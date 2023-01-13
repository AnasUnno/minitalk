/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araji-af <araji-af@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 20:07:09 by araji-af          #+#    #+#             */
/*   Updated: 2023/01/13 00:12:42 by araji-af         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signals(int pid, char caractere)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((caractere >> i) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		i--;
		usleep(700);
	}
}

void	send_message(int pid, char *message)
{
	int	i;

	i = 0;
	while (message[i])
	{
		send_signals(pid, message[i]);
		i++;
	}
}

void	my_hundler(int signal)
{
	if (signal == SIGUSR2)
		ft_putstr_fd("message has been sent");
}

int	main(int ac, char **av)
{
	signal(SIGUSR2, my_hundler);
	if (ac != 3 || ft_atoi(av[1]) < 0)
	{
		printf("Error encountred");
		exit(0);
	}
	else
		send_message(ft_atoi(av[1]), av[2]);
	return (0);
}
