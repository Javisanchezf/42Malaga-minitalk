/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:43:18 by javiersa          #+#    #+#             */
/*   Updated: 2023/02/02 20:29:27 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*strmapi;
	int		i;

	strmapi = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!strmapi)
		return (0);
	i = 0;
	while (s[i])
	{
		strmapi[i] = f(i, s[i]);
		i++;
	}
	strmapi[i] = 0;
	return (strmapi);
}
