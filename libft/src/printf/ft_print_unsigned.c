/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubenior <rubenior@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 13:16:09 by rubenior          #+#    #+#             */
/*   Updated: 2025/11/27 14:12:26 by rubenior         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"
#include "printf.h"

static int	ft_unsigned_len(unsigned int n)
{
	int	len;

	len = 1;
	while (n >= 10)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	ft_put_unsigned(unsigned int n)
{
	if (n >= 10)
		ft_put_unsigned(n / 10);
	ft_putchar_fd((n % 10) + '0', 1);
}

int	ft_print_unsigned(unsigned int n)
{
	ft_put_unsigned(n);
	return (ft_unsigned_len(n));
}
