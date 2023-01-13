/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araji-af <araji-af@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 20:08:14 by araji-af          #+#    #+#             */
/*   Updated: 2023/01/08 00:23:21 by araji-af         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int		ft_atoi(const char *str);
void	ft_putchar_fd(char c);
void	ft_putnbr_fd(int n);
void	ft_putstr_fd(char *s);
char	*ft_strjoin(char const *s1, char const *s2);

#endif