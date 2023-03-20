/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 19:39:39 by javiersa          #+#    #+#             */
/*   Updated: 2023/02/02 20:29:17 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dest_size;
	size_t	src_size;
	size_t	i;

	i = 0;
	dest_size = ft_strlen(dst);
	src_size = ft_strlen(src);
	if (dstsize <= dest_size)
		return (src_size + dstsize);
	while (src[i] && dest_size + 1 < dstsize)
	{
		dst[dest_size] = src[i];
		dest_size++;
		i++;
	}
	dst[dest_size] = 0;
	return (dest_size + src_size - i);
}
