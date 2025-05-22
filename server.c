/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <hlichten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:30:52 by hlichten          #+#    #+#             */
/*   Updated: 2025/04/02 16:57:58 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	reception_signal(int signal)
{
	static unsigned char	bit = '\0';
	static int				count = 0;
	static char				str[700000] = {0};
	static int				len = 0;

	bit <<= 1;
	if (signal == SIGUSR1)
		bit |= 1;
	count++;
	if (count == 8)
	{
		str[len] = (char)bit;
		if (!str[len++])
		{
			ft_printf("%s\n", str);
			len = 0;
		}
		count = 0;
		bit = 0;
	}
}

int	main(int ac, char **av)
{
	pid_t	pid;

	(void)av;
	pid = getpid();
	if (ac != 1)
		ft_printf("No arguments needed but here is the \n");
	ft_printf("PID: %d\n", pid);
	ft_printf("Waiting for a message...\n");
	signal(SIGUSR1, reception_signal);
	signal(SIGUSR2, reception_signal);
	while (1)
		;
	return (0);
}
