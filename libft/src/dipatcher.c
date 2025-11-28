/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dipatcher.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubenior <rubenior@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 13:03:34 by rubenior          #+#    #+#             */
/*   Updated: 2025/11/27 14:11:55 by rubenior         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "printf.h"

int	ft_format_dispatcher(char specifier, va_list args)
{
	if (specifier == 'c')
		return (ft_print_char(va_arg(args, int)));
	else if (specifier == 's')
		return (ft_print_str(va_arg(args, char *)));
	else if (specifier == 'p')
		return (ft_print_ptr(va_arg(args, void *)));
	else if (specifier == 'd' || specifier == 'i')
		return (ft_print_nbr(va_arg(args, int)));
	else if (specifier == 'u')
		return (ft_print_unsigned(va_arg(args, unsigned int)));
	else if (specifier == 'x')
		return (ft_print_hex(va_arg(args, unsigned int), 0));
	else if (specifier == 'X')
		return (ft_print_hex(va_arg(args, unsigned int), 1));
	else if (specifier == '%')
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	return (0);
}
