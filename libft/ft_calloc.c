/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnuno-im <rnuno-im@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 13:55:09 by rnuno-im          #+#    #+#             */
/*   Updated: 2025/10/06 12:44:41 by rnuno-im         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	total;

	if (size != 0 && nmemb > 2147483647 / size)
		return (NULL);
	if (nmemb == 0 || size == 0)
		return (malloc(0));
	total = nmemb * size;
	ptr = (unsigned char *)malloc(total);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, total);
	return (ptr);
}

/* int	main(void)
{
	int *arr;

	arr = (int *)ft_calloc(74568321, sizeof(int));
	if (!arr)
	{
		printf("ft_calloc devolvio NULL\n");
	}
	else
	{
		printf("ft_calloc reservo memoria\n");
	}
	int i = 0;
	while (i < 1000)
	{
		printf("%d", arr[i]);
		i++;
	}
	printf("\n");
	return (0);
} */