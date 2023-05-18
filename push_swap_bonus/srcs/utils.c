/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlivroze <tlivroze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 18:28:25 by tlivroze          #+#    #+#             */
/*   Updated: 2023/05/18 07:58:14 by tlivroze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	ft_pileadd_front(t_pile **lst, t_pile *new)
{
	if (!lst || !new)
		return ((void)0);
	new->next = *lst;
	*lst = new;
}

t_pile	*ft_pilenew(int value, int index)
{
	t_pile	*element;

	element = malloc(sizeof(t_pile));
	if (!element)
		return (NULL);
	element->value = value;
	element->index = index;
	element->next = NULL;
	return (element);
}

t_pile	*ft_pilelast(t_pile *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
