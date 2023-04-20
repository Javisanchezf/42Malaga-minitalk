/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 18:17:42 by javiersa          #+#    #+#             */
/*   Updated: 2023/04/20 18:55:41 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_sent_signal(int pid, char *str)
{
	int	bit;

	while (*str)
	{
		bit = -1;
		while (++bit < 8)
		{
			if (*str >> bit & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(42);
		}
		str++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3 || !argv[1][0] || !argv[2][0])
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	ft_sent_signal(pid, argv[2]);
	ft_sent_signal(pid, "\n\0");
	return (0);
}
