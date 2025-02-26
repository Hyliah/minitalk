/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:30:52 by hlichten          #+#    #+#             */
/*   Updated: 2025/02/16 16:19:31 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitak.h"

void	reception_signal(int signal)
{
	int	bit;
	int	count;

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
}

int main (int ac, char **av)
{
	(void)av;
	
    pid_t	pid; 

	pid = getpid();
	if (ac != 1)
	{
		ft_printf("Ceci est un message d'erreur merci de faire les choses correctement");
	}
	ft_printf("Hello, vla le PID : %d\n", pid);
	ft_printf("Maintenant j'attends un message vraiment stylé \n");
	signal(SIGUSR1, reception_signal);
	signal(SIGUSR2, reception_signal);
	while (1)
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