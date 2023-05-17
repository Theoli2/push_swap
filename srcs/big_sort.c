/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlivroze <tlivroze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:24:04 by tlivroze          #+#    #+#             */
/*   Updated: 2023/05/16 12:39:17 by tlivroze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	final_rb(t_pile **b)
{
	t_pile	*head;
	int		index;
	int		pos;

	head = *b;
	index = find_biggest(head);
	pos = 0;
	while (head != NULL && head->index != index)
	{
		pos++;
		head = head->next;
	}
	do_final_rb(b, pos, index);
}

void	push_elem_a_to_b(t_pile **a, t_pile **b, t_moves best)
{
	rotate_all(a, b, best);
	rotate_a(a, best);
	rotate_b(b, best);
	pb(a, b);
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

t_moves	calc_best_moves(t_pile **a, t_pile **b, t_moves best)
{
	t_pile	*head;
	t_moves	curr;

	head = *a;
	best = init(best, INT_MAX, -1);
	while (*a)
	{
		curr = init(curr, 0, (*a)->index);
		curr = calc_moves_a(&head, curr);
		curr = calc_moves_b(b, curr);
		curr = optimize_moves(curr);
		curr.total = curr.ra + curr.rb + curr.rr \
		+ curr.rra + curr.rrb + curr.rrr;
		if (curr.total < best.total)
			best = curr;
		*a = (*a)->next;
	}
	*a = head;
	return (best);
}

void	big_sort(t_pile **a, t_pile **b)
{
	t_moves	best;
	t_pile	*head;
	int		size;
	int		i;

	size = 0;
	pb(a, b);
	pb(a, b);
	head = *a;
	while (*a)
	{
		size++;
		*a = (*a)->next;
	}
	*a = head;
	i = 0;
	while (i < size / 2)
	{
		best = calc_best_moves(a, b, best);
		push_elem_a_to_b(a, b, best);
		i++;
	}
	final_rb(b);
	while (*b)
		pa(a, b);
	i = 2;
	rra(a);
	pb(a, b);
	rra(a);
	pb(a, b);
	while (i < size / 2)
	{
		best = calc_best_moves(a, b, best);
		push_elem_a_to_b(a, b, best);
		i++;
	}
	i = 0;
	while (i < size / 2)
	{
		best = calc_best_moves_rev(a, b, best);
		push_elem_b_to_a(a, b, best);
		i++;
	}
	// if (ft_issorted(*a))
	// 	exit(0);
}
