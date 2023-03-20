/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 13:44:59 by javiersa          #+#    #+#             */
/*   Updated: 2023/02/02 20:16:27 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_size_int_to_char(long n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n = n * -1;
		i++;
	}
	while (n >= 1)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char			*itoa;
	unsigned long	size;
	long			number;

	if (n == 0)
		return (ft_strdup("0"));
	number = (long)n;
	size = ft_size_int_to_char(number);
	itoa = ft_calloc((size + 1), sizeof(char));
	if (!itoa)
		return (0);
	if (number < 0)
	{
		number = number * -1;
		itoa[0] = '-';
	}
	while (number >= 1)
	{
		itoa[--size] = (number % 10) + '0';
		number = number / 10;
	}
	return (itoa);
}
