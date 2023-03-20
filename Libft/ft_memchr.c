/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:01:18 by javiersa          #+#    #+#             */
/*   Updated: 2023/02/02 20:15:40 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s1;
	unsigned char	c1;
	size_t			i;

	s1 = (unsigned char *)s;
	c1 = (unsigned char )c;
	i = 0;
	while (i < n)
	{
		if (s1[i] == c1)
			return ((void *)(s1 + i));
		i++;
	}
	return (0);
}
