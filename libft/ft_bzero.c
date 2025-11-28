/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnuno-im <rnuno-im@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 14:17:33 by rnuno-im          #+#    #+#             */
/*   Updated: 2025/10/01 14:39:02 by rnuno-im         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

/* int main()
{
	unsigned char	str[] = "holahola";
	size_t len = sizeof(str);
	size_t j = 0;
	
	ft_bzero(str, 2);
	while (j < len)
	{
		printf("%d\n", str[j]);
		j++;
	}
} */