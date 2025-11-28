/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubenior <rubenior@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 00:20:35 by rubenior          #+#    #+#             */
/*   Updated: 2025/11/28 00:50:30 by rubenior         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/minitalk_bonus.h"

void	args_check(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 3)
		ft_printf("Invalid number of arguments");
	while (argv[1][i])
		if (!ft_isdigit(argv[1][i++]))
			ft_printf("Invalid PID");
	if (*argv[2] == 0)
		ft_printf("Invalid message (empty)");
}

void	send_msg(pid_t sv_pid, char *msg)
{
	unsigned char	c;
	int				nbr_bits;

	while (*msg)
	{
		c = *msg;
		nbr_bits = 8;
		while (nbr_bits--)
		{
			if (c & 0b10000000)
				kill(sv_pid, SIGUSR1);
			else
				kill(sv_pid, SIGUSR2);
			usleep(50);
			c <<= 1;
		}
		msg++;
	}
}

void	sig_handler(int signum)
{
	if (signum == SIGUSR2)
		write(1, "Character has been sucessfully receieved!\n", 42);
}

void	config_signals(void)
{
	struct sigaction	sa_newsig;

	sa_newsig.sa_handler = &sig_handler;
	sa_newsig.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa_newsig, NULL) == -1)
		ft_printf("Failed to change SIGUSR1's behavior");
	if (sigaction(SIGUSR2, &sa_newsig, NULL) == -1)
		ft_printf("Failed to change SIGUSR2's behavior");
}

int	main(int argc, char **argv)
{
	pid_t		sv_pid;

	args_check(argc, argv);
	sv_pid = ft_atoi(argv[1]);
	config_signals();
	send_msg(sv_pid, argv[2]);
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
