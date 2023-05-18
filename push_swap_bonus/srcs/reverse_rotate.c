/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlivroze <tlivroze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 03:33:14 by tlivroze          #+#    #+#             */
/*   Updated: 2023/05/18 09:43:12 by tlivroze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

bool	reverse_rotate(t_pile **a)
{
	t_pile	*tmp;
	t_pile	*head;

	if (*a)
	{
		head = *a;
		tmp = ft_pilelast(*a);
		while (head->next->next)
			head = head->next;
		head->next = NULL;
		ft_pileadd_front(a, ft_pilenew(tmp->value, tmp->index));
		free(tmp);
		return (true);
	}
	return (false);
}

void	rra(t_pile **a)
{
	reverse_rotate(a);
}

void	rrb(t_pile **b)
{
	reverse_rotate(b);
}

void	rrr(t_pile **a, t_pile **b)
{
	if (*a && (*a)->next && *b && (*b)->next)
	{
		reverse_rotate(a);
		reverse_rotate(b);
	}
}
