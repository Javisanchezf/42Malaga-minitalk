/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 19:44:54 by javiersa          #+#    #+#             */
/*   Updated: 2023/02/03 21:41:14 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_size_split(char const *s, char c)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	if (s[0] != c && s[0])
		n++;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1])
			n++;
		i++;
	}
	return (n);
}

static char	**ft_splitfree(char **split, int n)
{
	while (n-- > 0)
		free(split[n]);
	free(split);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		i;
	int		j;
	int		n;

	i = 0;
	n = 0;
	split = (char **)ft_calloc((ft_size_split(s, c) + 1), sizeof(char *));
	if (!split || !s)
		return (0);
	while (s[i] && n < ft_size_split(s, c))
	{
		while (s[i] == c && s[i])
			i++;
		j = 1;
		while (s[i + j] != c && s[i + j])
			j++;
		split[n] = ft_substr(s, i, j);
		if (!split[n])
			return (ft_splitfree(split, n));
		n++;
		i += j;
	}
	return (split);
}
