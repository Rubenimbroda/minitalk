/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnuno-im <rnuno-im@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 10:50:51 by rnuno-im          #+#    #+#             */
/*   Updated: 2025/10/07 12:21:39 by rnuno-im         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (!f || !s)
		return ;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/* void to_asterisk(unsigned int i, char *c)
{
	(void)i;
	*c = '*';
}
int main()
{
	char str[] = "hola me llamo ruben";
	ft_striteri(str, to_asterisk);
	printf("%s\n", str);
} */