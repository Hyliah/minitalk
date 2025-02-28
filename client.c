/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <hlichten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:30:40 by hlichten          #+#    #+#             */
/*   Updated: 2025/02/26 18:02:10 by hlichten         ###   ########.fr       */
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
	if (str[i] == 45 || str[i] == 43)
	{
		if (str[i] == '-')
			neg = -neg;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + (str[i] - 48);
		i++;
	}
	return (nb * neg);
}

void	send_msg(int pid, char *str)
{
	int	i;
	int	bit;

	i = 0;
	while (str[i])
	{
		bit = 0;
		while (bit < 8)
		{
			if ((str[i] >> bit) & 1)
				kill(pid, SIGUSR1); // kill envoie un signal a un processus donne (pid)
			else
				kill(pid, SIGUSR2);
			bit++;
			usleep(500); // evite les envois trop rapides des signaux
		}
		i++;
	}
	bit = 0;
	while (bit < 8) // envoi de 8 0 via SIGUSR2 pour marquer la fin de la communication
	{
		kill(pid, SIGUSR2);
		bit++;
		usleep(50);
	}
}

int	main (int ac, char **av) // verifie les arguments et extrait le pid du serveur
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
	
	send_msg(pid, str); // envoie un message au serveur avec send_msg
	return (0);
}

// av1 = PID en char a mettre en int via atoi 
// av2 = message en char 
// verifier que le programme ait 3 arguments sinon ?
// mettre en place un index qui va parcourir le texte [2][i]
// while() {exit}

// Client Checklist
// In the "client.c" file, you will...
// Write a program (main) in which the client takes two parameters/arguments
// The PID of the server to which it wants to send the message
// A message
// Encrypt the message (I did the encryption via bits)
// Send the message to the server (via its PID)
// Create a stop condition so that the server knows when it has finished receiving the message