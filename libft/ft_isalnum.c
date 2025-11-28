/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnuno-im <rnuno-im@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:03:18 by rnuno-im          #+#    #+#             */
/*   Updated: 2025/10/07 14:54:41 by rnuno-im         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (1 == ft_isdigit(c) || 1 == ft_isalpha(c))
	{
		return (1);
	}
	return (0);
}

/*  int main () {
	char c = 'F';
	
	if (ft_isalnum(c) != 0){
		printf ("es numero o letra");
	}
	else {
		printf ("no es numero o letra");
	}
}  */