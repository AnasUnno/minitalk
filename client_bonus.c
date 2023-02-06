/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araji-af <araji-af@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 20:07:09 by araji-af          #+#    #+#             */
/*   Updated: 2023/01/22 02:09:09 by araji-af         ###   ########.fr       */
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
		usleep(900);
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
	send_signals(pid, '\0');
}

int	protect_pid(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 48 || str[i] > 57)
			return (0);
		i++;
	}
	return (1);
}

void	my_hundler(int signal)
{
	if (signal == SIGUSR1)
		ft_putstr_fd("message has been sent");
}

int	main(int ac, char **av)
{
	signal(SIGUSR1, my_hundler);
	if (ac != 3 || ft_atoi(av[1]) < 0)
	{
		ft_putstr_fd("Error encountred");
		exit(0);
	}
	else if (!protect_pid(av[1]))
		ft_putstr_fd("invalid pid");
	else
		send_message(ft_atoi(av[1]), av[2]);
	return (0);
}
