/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnuno-im <rnuno-im@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 21:33:48 by rubenior          #+#    #+#             */
/*   Updated: 2025/11/28 14:38:42 by rnuno-im         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

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

	args_check(argc, argv);
	sv_pid = ft_atoi(argv[1]);
	send_msg(sv_pid, argv[2]);
	return (0);
}
