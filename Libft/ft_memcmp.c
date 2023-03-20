/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 19:40:09 by javiersa          #+#    #+#             */
/*   Updated: 2023/02/02 20:15:35 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1cast;
	unsigned char	*s2cast;

	i = 0;
	s1cast = (unsigned char *)s1;
	s2cast = (unsigned char *)s2;
	while (i < n)
	{
		if (s1cast[i] != s2cast[i])
			return (s1cast[i] - s2cast[i]);
		i++;
	}
	return (0);
}
