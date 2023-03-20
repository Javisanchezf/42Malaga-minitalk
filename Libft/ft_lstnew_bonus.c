/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 19:37:00 by javiersa          #+#    #+#             */
/*   Updated: 2023/02/02 20:15:49 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*lstnew;

	lstnew = malloc (sizeof(t_list));
	if (!lstnew)
		return (0);
	lstnew -> content = content;
	lstnew -> next = 0;
	return (lstnew);
}
