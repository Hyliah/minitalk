/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <hlichten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:30:40 by hlichten          #+#    #+#             */
/*   Updated: 2025/03/04 15:49:44 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	nb;
	int	neg;

	i = 0;
	nb = 0;
	neg = 1;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = neg * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + (str[i] - 48);
		i++;
	}
	return (nb * neg);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	send_msg(int pid, char *str)
{
	int	i;
	int	bit;
	int	size;

	size = ft_strlen(str);
	i = 0;
	str[size] = '\0';
	while (1)
	{
		bit = 7;
		while (bit >= 0)
		{
			if ((str[i] >> bit) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			bit--;
			usleep(100);
		}
		if (!str[i++])
			break ;
	}
}

int	main(int ac, char **av)
{
	char	*str;
	int		pid;

	if (ac != 3)
	{
		ft_printf("Erreur : merci de rentrer un nombre d arguments valide");
		return (1);
	}
	str = av[2];
	pid = ft_atoi(av[1]);
	if (pid <= 0)
	{
		ft_printf("Erreur : merci de rentrer un PID valide");
		return (1);
	}
	send_msg(pid, str);
	return (0);
}
