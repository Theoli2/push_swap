/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_bis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlivroze <tlivroze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 08:34:30 by tlivroze          #+#    #+#             */
/*   Updated: 2023/05/16 09:10:09 by tlivroze         ###   ########.fr       */
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
