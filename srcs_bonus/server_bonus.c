/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubenior <rubenior@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 00:21:05 by rubenior          #+#    #+#             */
/*   Updated: 2025/11/30 20:46:55 by rubenior         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/minitalk_bonus.h"

void	handle_sigusr(int signum, siginfo_t *info, void *ucontent)
{
	static int				bit_itr = 7;
	static unsigned char	c;

	(void)ucontent;
	if (signum == SIGUSR1)
		c |= (1 << bit_itr);
	bit_itr--;
	if (bit_itr < 0)
	{
		ft_putchar_fd(c, STDOUT_FILENO);
		c = 0;
		bit_itr = 7;
		kill(info->si_pid, SIGUSR2);
	}
}

void	config_signals(void)
{
	struct sigaction	sa_newsig;

	sa_newsig.sa_sigaction = &handle_sigusr;
	sa_newsig.sa_flags = SA_SIGINFO;
	sigemptyset(&sa_newsig.sa_mask);
	if (sigaction(SIGUSR1, &sa_newsig, NULL) == -1)
		ft_printf("Failed to change SIGUSR1's behavior");
	if (sigaction(SIGUSR2, &sa_newsig, NULL) == -1)
		ft_printf("Failed to change SIGUSR2's behavior");
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("SERVER PID = %d\n\n", pid);
	config_signals();
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
