/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 20:27:12 by javiersa          #+#    #+#             */
/*   Updated: 2023/03/22 20:01:35 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

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

void	ft_ack(int signal)
{
	if (signal == SIGUSR1)
		ft_printf("\n ✅ Message sent successfully!\n");
	exit(0);
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	signal(SIGUSR1, ft_ack);
	signal(SIGUSR2, ft_ack);
	if (argc != 3 || !argv[1][0] || !argv[2][0])
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	ft_sent_signal(pid, argv[2]);
	ft_sent_signal(pid, "\n\0");
	i = -1;
	while (++i < 8)
	{
		kill(pid, SIGUSR1);
		usleep(42);
	}
	sleep(8);
	ft_printf("❌ Time out, try other PID or ");
	return (0);
}
