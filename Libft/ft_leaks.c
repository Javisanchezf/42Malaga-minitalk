/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_leaks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:24:06 by javiersa          #+#    #+#             */
/*   Updated: 2023/03/14 17:56:10 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Add atexit(ft_leaks); in main and # include <stdlib.h>

void	ft_leaks(void)
{
	system("leaks -q a.out");
}
