/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_bis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlivroze <tlivroze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 08:34:30 by tlivroze          #+#    #+#             */
/*   Updated: 2023/05/18 09:30:37 by tlivroze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

t_moves	calc_best_moves_rev(t_pile **a, t_pile **b, t_moves best)
{
	t_pile	*head;
	t_moves	curr;

	head = *b;
	best = init(best, INT_MAX, -1);
	while (*b)
	{
		curr = init(curr, 0, (*b)->index);
		curr = calc_moves_b_rev(&head, curr);
		curr = calc_moves_a_rev(a, curr);
		curr = optimize_moves(curr);
		curr.total = curr.ra + curr.rb + curr.rr \
		+ curr.rra + curr.rrb + curr.rrr;
		if (curr.total < best.total)
			best = curr;
		*b = (*b)->next;
	}
	*b = head;
	return (best);
}

void	push_elem_b_to_a(t_pile **a, t_pile **b, t_moves best)
{
	rotate_all(a, b, best);
	rotate_a(a, best);
	rotate_b(b, best);
	pa(a, b);
}

t_moves	calc_a_rev_bis(t_pile	*head, t_moves curr, int index, int size)
{
	int	pos;

	pos = 0;
	while (head && index != head->index)
	{
		pos++;
		head = head->next;
	}
	if (pos < size / 2)
		curr.ra = pos;
	else
		curr.rra = size - pos;
	return (curr);
}

void	final_ra_bis(t_pile **a, int pos)
{
	if (pos <= get_size(a) / 2)
	{
		while (pos > 0)
		{
			ra(a);
			pos--;
		}
	}
	else
	{
		while (pos < get_size(a))
		{
			rra(a);
			pos++;
		}
	}
}

void	final_ra(t_pile **a)
{
	t_pile	*head;
	int		index;
	int		pos;

	head = *a;
	index = 0;
	pos = 0;
	while (head != NULL && head->index != index)
	{
		pos++;
		head = head->next;
	}
	final_ra_bis(a, pos);
}
