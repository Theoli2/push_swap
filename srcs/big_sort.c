/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlivroze <tlivroze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:24:04 by tlivroze          #+#    #+#             */
/*   Updated: 2023/05/14 03:25:19 by tlivroze         ###   ########.fr       */
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
	// head = *b;
	pos = 0;
	// printf("index = %d\n", index);
	while (head != NULL && head->index != index)
	{
		pos++;
		head = head->next;
	}
	// printf("pos = %d\n", pos);
	if (pos < index / 2)
	{
		while (pos)
		{
			rb(b);
			pos--;
		}
	}
	else
	{
		pos = index - pos + 1;
		// printf("pos = %d\n", pos);
		while (pos)
		{
			// printf("pos = %d\n", pos);
			rrb(b);
			pos--;
		}
	}
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
		// printf("best_total = %d\n", best.total);
		curr = init(curr, 0, (*a)->index);
		// printf("curr %i\n", (*a)->index);
		// printf("curr index = %d\n", curr.index);
		curr = calc_moves_a(&head, curr);
		curr = calc_moves_b(b, curr);
		curr = optimize_moves(curr);
		// printf("curr index = %d\n", curr.index);

		curr.total = curr.ra + curr.rb + curr.rr \
		+ curr.rra + curr.rrb + curr.rrr;
		// printf("curr ra = %d\n", curr.ra);
		
		if (curr.total < best.total)
		{
			best = curr;
			// printf("index = %d\n", curr.index);
		}
		*a = (*a)->next;
	}
	// printf("best_total = %d\n", best.total);
	*a = head;
	return (best);
}

void	big_sort(t_pile **a, t_pile **b)
{
	t_moves	best;
	t_pile	*head;
	int		size;

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
	while (size)
	{
		best = calc_best_moves(a, b, best);
		// printf("best index = %d\n", best.index);
		// printf("best total = %d\n", best.total);
		push_elem_a_to_b(a, b, best);
		// print_all_pile(a, b);
		size--;
	}
	// print_all_pile(a, b);
	printf("%d\n", (*b)->value);
	final_rb(b);
	while (*b)
		pa(a, b);
	// print_all_pile(a, b);
	if (ft_issorted(*a))
		exit(0);
}
