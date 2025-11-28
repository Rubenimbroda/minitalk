/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnuno-im <rnuno-im@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 11:16:33 by rnuno-im          #+#    #+#             */
/*   Updated: 2025/09/30 16:41:20 by rnuno-im         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/* int main()
{
	int c = 129;
	
	if (ft_isascii(c) != 0)
	{
		printf("es ascii");
	}
	else
	{
		printf("no es ascii");
	}
} */