/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <hlichten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:30:52 by hlichten          #+#    #+#             */
/*   Updated: 2025/02/26 18:19:41 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int sig_message = 0; // stock le caractere et l'index des bits

void	reception_signal1(int signal) //reconstruit et affiche le message. 
{
	char c;

	if (signal == SIGUSR1)
		sig_message |= (1<< ((sig_message >> 8) & 0xFF));

	sig_message += (1 << 8);

	if (((sig_message >> 8) & 0x0FF) == 8)
	{
		c = sig_message & 0xFF;
		if (c == '\0')
			ft_printf("\n");
		else 
			ft_printf("%c", c);
		sig_message = 0;	
	}




	int	bit;
	int	count; // permet de suivre la reception du des bits



	if (signal == SIGUSR1)
	{
		
		count++;
	}
	if (signal == SIGUSR2)
	{
		
		count++;
	}
	if (count > 7)
	{
		
	}

	// peut etre mettre le message dans un malloc avant de l'envoyer mais comment gerer la taille ?
}

int	main(int ac, char **av)
{
	(void)av;
	
    pid_t	pid;

	pid = getpid();// envoie le pid 
	if (ac != 1)
	{
		ft_printf("Ceci est un message d'erreur merci de faire les choses correctement");
	}
	ft_printf("Hello, vla le PID : %d\n", pid);
	ft_printf("Maintenant j'attends un message vraiment stylé \n");
	signal(SIGUSR1, reception_signal);
	signal(SIGUSR2, reception_signal);
	while (1) // reste en pause, alerte d une reception de message
	{
		pause();
	}
    return (0);
}

// Display its PID
// Create an endless loop so that the server can receive signals at any time
// Receive signals
// Decrypt signals
// For each signal received (SIGUSR1 & SIGUSR2) it should take a certain action