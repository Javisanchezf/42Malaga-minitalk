/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 20:10:16 by javiersa          #+#    #+#             */
/*   Updated: 2023/02/02 20:29:34 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	o;

	i = 0;
	if (needle[0] == 0)
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		o = 0;
		while (haystack[i + o] == needle[o] && needle[o] && (i + o) < len)
		{
			o++;
		}
		if (needle[o] == 0)
			return ((char *)(haystack + i));
		i++;
	}
	return (0);
}
