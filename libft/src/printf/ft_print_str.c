/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubenior <rubenior@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 13:15:57 by rubenior          #+#    #+#             */
/*   Updated: 2025/11/27 14:12:25 by rubenior         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"
#include "printf.h"

int	ft_print_str(char *s)
{
	int	len;

	if (!s)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	len = 0;
	while (s[len])
		len++;
	ft_putstr_fd(s, 1);
	return (len);
}
