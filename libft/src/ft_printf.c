/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubenior <rubenior@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 13:04:09 by rubenior          #+#    #+#             */
/*   Updated: 2025/11/27 14:07:23 by rubenior         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		printed;

	if (!format)
		return (-1);
	va_start(args, format);
	i = 0;
	printed = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			printed += ft_format_dispatcher(format[i + 1], args);
			i++;
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			printed++;
		}
		i++;
	}
	va_end(args);
	return (printed);
}