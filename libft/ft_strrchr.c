/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnuno-im <rnuno-im@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 17:28:07 by rnuno-im          #+#    #+#             */
/*   Updated: 2025/10/07 14:39:20 by rnuno-im         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	if (c > 255)
		c = c % 256;
	while (i >= 0)
	{
		if (s[i] == c)
		{
			return ((char *)&s[i]);
		}
		i--;
	}
	return (NULL);
}
/* int main()
{
	const char str[] = "me y llamo ruben";
	char c = 'z';
	char *ptachar;

	ptachar = ft_strrchr(str, c);

	if (ptachar != NULL)
	{
		printf("caracter encontrado");
	}
	else
	{
		printf("caracter no encontrado");
	}
} */