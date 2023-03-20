/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 11:48:56 by javiersa          #+#    #+#             */
/*   Updated: 2023/02/02 20:29:43 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;

	start = 0;
	end = ft_strlen(s1);
	while (ft_strchr(set, s1[start]) != 0 && s1[start])
		start++;
	while (ft_strchr(set, s1[end]) != 0 && end > start)
		end--;
	return (ft_substr(s1, start, (end - start + 1)));
}
