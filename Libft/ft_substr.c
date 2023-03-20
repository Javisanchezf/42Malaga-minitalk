/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:37:02 by javiersa          #+#    #+#             */
/*   Updated: 2023/02/02 20:29:49 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s_cast;
	char	*substr;

	if ((unsigned int)ft_strlen(s) <= start || !s || len == 0)
		return (ft_calloc(1, sizeof(char)));
	if (((size_t)ft_strlen(s) - start) < len)
		len = (size_t)ft_strlen(s) - start;
	s_cast = &((char *)s)[start];
	substr = malloc((len + 1) * sizeof(char));
	if (!substr)
		return (0);
	ft_strlcpy(substr, s_cast, len + 1);
	return (substr);
}
