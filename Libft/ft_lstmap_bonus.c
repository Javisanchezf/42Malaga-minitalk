/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 18:30:34 by javiersa          #+#    #+#             */
/*   Updated: 2023/02/02 20:15:53 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first_element;
	t_list	*aux;

	if (!lst)
		return (0);
	first_element = 0;
	while (lst)
	{
		aux = malloc (sizeof(t_list));
		if (!aux)
		{
			ft_lstclear(&first_element, del);
			return (0);
		}
		aux -> content = f(lst->content);
		aux -> next = 0;
		ft_lstadd_back(&first_element, aux);
		lst = lst->next;
	}
	return (first_element);
}
