/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 20:27:09 by javiersa          #+#    #+#             */
/*   Updated: 2023/03/22 19:55:01 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	action(int signal, siginfo_t *info, void *context)
{
	static int				bit = 0;
	static unsigned char	c = 0;
	static pid_t			sender_pid = 0;

	(void)context;
	if (!sender_pid)
		sender_pid = info->si_pid;
	if (signal == SIGUSR2)
		c = c + (1 << bit);
	bit++;
	if (bit == 8)
	{
		if (c == 0)
		{
			kill(sender_pid, SIGUSR1);
			sender_pid = 0;
		}
		else
			write(1, &c, 1);
		bit = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	s_sigaction;

	if (write(1, "", 0) == -1)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	ft_printf("PID: %d\n", getpid());
	s_sigaction.sa_sigaction = action;
	s_sigaction.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_sigaction, 0);
	sigaction(SIGUSR2, &s_sigaction, 0);
	while (1)
		pause();
	return (0);
}
