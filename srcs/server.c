/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubenior <rubenior@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 21:33:51 by rubenior          #+#    #+#             */
/*   Updated: 2025/11/28 01:18:31 by rubenior         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	handle_sigusr(int signum, siginfo_t *info, void *ucontent)
{
	static int				bit_itr = 7;
	static unsigned char	c = 0;

	(void)info;
	(void)ucontent;

	if (signum == SIGUSR1)
		c |= (1 << bit_itr);

	bit_itr--;

	if (bit_itr < 0)
	{
		if (c >= 32 && c <= 126)
			ft_putchar_fd(c, 1);
		c = 0;
		bit_itr = 7;
	}
}

void	config_signals(void)
{
	struct sigaction sa;

	sa.sa_sigaction = &handle_sigusr;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
}

int main(void)
{
	ft_printf("SERVER PID = %d\n", getpid());
	config_signals();
	while (1)
		pause();
}
