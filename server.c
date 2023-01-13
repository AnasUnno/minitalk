/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araji-af <araji-af@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 21:25:47 by araji-af          #+#    #+#             */
/*   Updated: 2023/01/13 01:20:53 by araji-af         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static pid_t	g_client_pid;

void	from_bin_ascii(char *binary_str)
{
	char	ascii_num;
	int		i;

	ascii_num = 0;
	i = 0;
	while (binary_str[i])
	{
		ascii_num = (ascii_num << 1) | (binary_str[i] - '0');
		i++;
	}
	write(1, &ascii_num, 1);
}

void	check_str(char *str, int counter)
{
	if (!str[counter])
	{
		kill(g_client_pid, SIGUSR2);
		return ;
	}
}

void	fill_str(int signal, siginfo_t *info, void *context)
{
	static int			count;
	static char			*to_fill;

	(void)context;
	if (g_client_pid != info->si_pid)
	{
		g_client_pid = info->si_pid;
		count = 0;
	}
	if (!to_fill)
		to_fill = malloc(8 * sizeof(char) + 1);
	if (!to_fill)
		return ;
	if (signal == SIGUSR2)
		to_fill[count++] = '1';
	else if (signal == SIGUSR1)
		to_fill[count++] = '0';
	if (count == 8)
	{
		from_bin_ascii(to_fill);
		free(to_fill);
		count = 0;
		to_fill = NULL;
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_putstr_fd("PID => ");
	ft_putnbr_fd(getpid());
	ft_putchar_fd('\n');
	sa.sa_sigaction = fill_str;
	sa.sa_flags = SA_SIGINFO;
	while (1)
	{
		sigaction(SIGUSR2, &sa, NULL);
		sigaction(SIGUSR1, &sa, NULL);
		pause();
	}
	return (0);
}
