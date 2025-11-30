/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubenior <rubenior@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 21:33:48 by rubenior          #+#    #+#             */
/*   Updated: 2025/11/30 20:58:07 by rubenior         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

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
		if (!ft_isdigit(argv[1][i++]))
		{
			ft_printf("ERROR\nInvalid PID\n");
			return (1);
		}
	if (*argv[2] == 0)
	{
		ft_printf("ERROR\nInvalid message (empty)\n");
		return (1);
	}
	return (0);
}

void	send_msg(pid_t sv_pid, char *msg)
{
	unsigned char	c;
	int				bits;

	while (*msg)
	{
		c = *msg;
		bits = 8;
		while (bits--)
		{
			if (c & 0b10000000)
				kill(sv_pid, SIGUSR1);
			else
				kill(sv_pid, SIGUSR2);
			c <<= 1;
			usleep(50);
		}
		msg++;
	}
}

int	main(int argc, char **argv)
{
	pid_t	sv_pid;

	if (args_check(argc, argv) == 1)
		return (EXIT_FAILURE);
	sv_pid = ft_atoi(argv[1]);
	if (sv_pid <= 0 || kill(sv_pid, 0) == -1)
	{
    	ft_printf("ERROR\nBad PID\n");
    	return (EXIT_FAILURE);
	}
	send_msg(sv_pid, argv[2]);
	return (EXIT_SUCCESS);
}
