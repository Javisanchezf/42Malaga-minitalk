/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freeandjoin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 19:00:01 by javiersa          #+#    #+#             */
/*   Updated: 2023/02/22 18:18:38 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_freeandjoin(char *buffer, char *aux)
{
	char	*strjoin;

	strjoin = ft_strjoin(buffer, aux);
	ft_free_and_null((void **) &buffer);
	return (strjoin);
}
