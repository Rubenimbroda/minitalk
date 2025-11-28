/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnuno-im <rnuno-im@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:08:22 by rnuno-im          #+#    #+#             */
/*   Updated: 2025/10/08 15:27:38 by rnuno-im         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if ((s[i] != c) && (i == 0 || s[i - 1] == c))
			j++;
		i++;
	}
	return (j);
}

static char	*getword(char const *s, char c)
{
	size_t	i;
	char	*str;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s, i + 1);
	return (str);
}

void	free_array(char **arr)
{
	size_t	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	words;
	size_t	j;
	char	**res;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	res = malloc(sizeof(char *) * (words + 1));
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] && j < words)
	{
		while (s[i] == c && s[i])
			i++;
		res[j] = getword(s + i, c);
		if (!res[j])
			return (free_array(res), NULL);
		i += ft_strlen(res[j]);
		j++;
	}
	res[j] = NULL;
	return (res);
}
/*  void	print_split(char **split)
{
	int i;
	i = 0;
	while (split[i])
	{
		printf("%s\n", split[i]);
		i++;
	}
}

int main()
{
	char *str = "hola\tmundo";
	char **res = ft_split(str, '	');
	
	if (!res)
		return (1);
	print_split(res);
	free_array(res);
}  */