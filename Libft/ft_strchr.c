/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 20:19:49 by javiersa          #+#    #+#             */
/*   Updated: 2022/12/12 16:37:29 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	unsigned char	character;

	character = (unsigned char)c;
	c = 0;
	while (s[c])
	{
		if (s[c] == character)
			return (&((char *)s)[c]);
		c++;
	}
	if (character == 0)
		return (&((char *)s)[c]);
	return (0);
}
