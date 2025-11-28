/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnuno-im <rnuno-im@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 11:19:53 by rnuno-im          #+#    #+#             */
/*   Updated: 2025/10/01 13:16:43 by rnuno-im         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (little[j] == '\0')
		return ((char *)&big[i]);
	while (i < len && big[i])
	{
		j = 0;
		if (big[i] == little[j])
		{
			while ((i + j) < len && little[j] && big[i + j] == little[j])
			{
				j++;
			}
			if (little[j] == '\0')
				return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}

/* int main()
{
	const char *big = "hola me llamo ruben";

	printf("%s\n", ft_strnstr(big, "", 20));
}   */