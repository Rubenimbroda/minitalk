/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnuno-im <rnuno-im@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 21:33:51 by rubenior          #+#    #+#             */
/*   Updated: 2025/12/01 17:27:54 by rnuno-im         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static void	btoa(int signal, siginfo_t *info, void *context)
{
	static char	c;
	static int	num;

	if (!num)
		num = 8;
	if (!c)
		c = 0;
	num--;
	if (signal == SIGUSR1)
		c += 0 << num;
	if (signal == SIGUSR2)
		c += 1 << num;
	if (num == 0)
	{
		write(1, &c, 1);
		num = 8;
		c = 0;
	}
	if (context == NULL)
		write(1, "", 0);
	kill(info->si_pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("Server PID = %d\n", getpid());
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = btoa;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		usleep(50);
	return (0);
}
