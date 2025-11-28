/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnuno-im <rnuno-im@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 11:00:31 by rnuno-im          #+#    #+#             */
/*   Updated: 2025/10/07 12:38:12 by rnuno-im         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_total;
	size_t	s1_len;
	char	*str;
	size_t	i;

	s1_len = ft_strlen(s1);
	len_total = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * (len_total + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len_total && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (i < len_total && s2[i - s1_len])
	{
		str[i] = s2[i - s1_len];
		i++;
	}
	str[i] = '\0';
	return (str);
}

/* int main()
{
	char const	s1[] = "\0";
	char const	s2[] = "hola";
	char *str = ft_strjoin(s1, s2);

	printf("%s\n", str);
	free(str);
	return (0);
} */