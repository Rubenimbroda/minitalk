/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnuno-im <rnuno-im@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 13:20:54 by rnuno-im          #+#    #+#             */
/*   Updated: 2025/09/30 16:41:08 by rnuno-im         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
		{
			return ((char *)&str[i]);
		}
		i++;
	}
	if ((char)c == '\0')
	{
		return ((char *)&str[i]);
	}
	return (NULL);
}

/* int main()
{
	char str[] = "me llamo ruben";
	char c = 'y';
	char *ptachar;

	ptachar = ft_strchr(str, c);

	if (ptachar != NULL)
	{
		printf("caracter encontrado");
	}
	else
	{
		printf("caracter no encontrado");
	}
} */
