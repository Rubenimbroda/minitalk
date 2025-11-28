/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnuno-im <rnuno-im@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 12:13:24 by rnuno-im          #+#    #+#             */
/*   Updated: 2025/10/07 15:16:27 by rnuno-im         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*str;
	unsigned char		uc;

	uc = (unsigned char)c;
	str = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (str[i] == uc)
		{
			return ((void *)&str[i]);
		}
		i++;
	}
	return (NULL);
}

/* int main()
{
	unsigned char str[] = "hola me llamo ruben";
	char c = 'o';
	char *ptrachar;
	
	ptrachar = ft_memchr(str, c, 5);
	if (ptrachar != NULL)
		printf("%s\n", ptrachar);
	else
		printf("caracter no encontrado");
} */