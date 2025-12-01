/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnuno-im <rnuno-im@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 00:20:35 by rubenior          #+#    #+#             */
/*   Updated: 2025/12/01 17:40:08 by rnuno-im         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/minitalk_bonus.h"

static int	g_recived;

int	args_check(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 3)
	{
		ft_printf("ERROR\nInvalid number of arguments\n");
		return (1);
	}
	while (argv[1][i])
	{
		if (!ft_isdigit(argv[1][i++]))
		{
			ft_printf("ERROR\nInvalid PID\n");
			return (1);
		}
	}
	if (*argv[2] == 0)
	{
		ft_printf("ERROR\nInvalid message (empty)\n");
		return (1);
	}
	return (0);
}

static void	send_binary(char c, pid_t pid_server)
{
	int	num;

	num = 7;
	while (num >= 0)
	{
		g_recived = 0;
		if (((c >> num) & 1) == 1)
			kill(pid_server, SIGUSR2);
		else
			kill(pid_server, SIGUSR1);
		while (g_recived == 0)
			usleep(50);
		num--;
	}
}

static void	handler(int signal)
{
	if (signal == SIGUSR2)
		g_recived = 1;
}

int	main(int argc, char **argv)
{
	pid_t	pid_server;
	int		i;

	i = 0;
	if (args_check(argc, argv) == 1)
		return (EXIT_FAILURE);
	signal(SIGUSR2, handler);
	write(1, "Everything has been sucessfully receieved!\n", 43);
	if (argc == 3)
	{
		pid_server = ft_atoi(argv[1]);
		if (pid_server <= 0 || kill(pid_server, 0) == -1)
		{
			ft_printf("ERROR\nBad PID\n");
			return (EXIT_FAILURE);
		}
		while (argv[2][i] != 0)
		{
			send_binary(argv[2][i], pid_server);
			i++;
		}
		send_binary(0, pid_server);
	}
	return (0);
}
