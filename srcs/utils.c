/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlivroze <tlivroze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 18:28:25 by tlivroze          #+#    #+#             */
/*   Updated: 2023/05/18 08:00:47 by tlivroze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

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

bool	ft_issorted(t_pile	*a)
{
	t_pile	*tmp;

	tmp = a;
	while (a->next)
	{
		if (a->value < a->next->value)
			a = a->next;
		else
			return (false);
	}
	a = tmp;
	return (true);
}

t_moves	init(t_moves moves, int init, int index)
{
	moves.index = index;
	moves.ra = init;
	moves.rb = init;
	moves.rr = init;
	moves.rra = init;
	moves.rrb = init;
	moves.rrr = init;
	moves.total = init;
	return (moves);
}
