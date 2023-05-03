/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlivroze <tlivroze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 03:33:14 by tlivroze          #+#    #+#             */
/*   Updated: 2023/05/03 14:24:55 by tlivroze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

bool	reverse_rotate(t_pile **a)
{
	t_pile	*tmp;
	t_pile	*head;

	if (*a && (*a)->next)
	{
		head = *a;
		tmp = ft_pilelast(*a);
		while ((*a)->next->next)
			*a = (*a)->next;
		(*a)->next = NULL;
		*a = head;
		ft_pileadd_front(a, ft_pilenew(tmp->value, tmp->index));
		return (true);
	}
	return (false);
}

void	rra(t_pile **a)
{
	if (reverse_rotate(a) == true)
		write(1, "rra\n", 4);
}

void	rrb(t_pile **b)
{
	if (reverse_rotate(b) == true)
		write(1, "rrb\n", 4);
}

void	rrs(t_pile **a, t_pile **b)
{
	if (*a && (*a)->next && *b && (*b)->next)
	{
		reverse_rotate(a);
		reverse_rotate(b);
		write(1, "rrs\n", 4);
	}
}