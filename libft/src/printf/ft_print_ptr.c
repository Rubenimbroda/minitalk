/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubenior <rubenior@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 13:15:44 by rubenior          #+#    #+#             */
/*   Updated: 2025/11/27 14:12:23 by rubenior         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"
#include "printf.h"

static int	ft_ptr_len(unsigned long long n)
{
	int	len;

	len = 1;
	while (n >= 16)
	{
		n /= 16;
		len++;
	}
	return (len);
}

static void	ft_put_ptr(unsigned long long n)
{
	char	*base;

	base = "0123456789abcdef";
	if (n >= 16)
		ft_put_ptr(n / 16);
	ft_putchar_fd(base[n % 16], 1);
}

int	ft_print_ptr(void *ptr)
{
	unsigned long long	addr;

	if (!ptr)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	addr = (unsigned long long)ptr;
	ft_putstr_fd("0x", 1);
	ft_put_ptr(addr);
	return (2 + ft_ptr_len(addr));
}
