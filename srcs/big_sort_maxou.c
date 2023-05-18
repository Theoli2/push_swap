/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_maxou.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlivroze <tlivroze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 03:17:46 by tlivroze          #+#    #+#             */
/*   Updated: 2023/05/18 07:33:22 by tlivroze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	get_size(t_pile **a)
{
	t_pile	*head;
	int		size;

	head = *a;
	size = 0;
	while (head != NULL)
	{
		size++;
		head = head->next;
	}
	return (size);
}

void	do_pop_a(t_pile **a, t_pile **b, int pos, int size)
{
	int		num_rra;

	if (pos <= size / 2)
	{
		while (pos > 0)
		{
			ra(a);
			pos--;
		}
	}
	else
	{
		num_rra = size - pos;
		while (num_rra > 0)
		{
			rra(a);
			num_rra--;
		}
	}
	pb(a, b);
}

void	moves_pop_a(t_pile **a, t_pile **b, int median)
{
	t_pile	*head;
	int		pos;
	int		size;

	size = 0;
	pos = 0;
	head = *a;
	while (head)
	{
		size++;
		head = head->next;
	}
	head = *a;
	while (head && head->index < median)
	{
		pos++;
		head = head->next;
	}
	head = *a;
	do_pop_a(a, b, pos, size);
}

void	push_top_half(t_pile **a, t_pile **b, int median)
{
	int		i;

	i = 0;
	while (i < median)
	{
		moves_pop_a(a, b, median);
		i++;
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

void	big_sort_alt(t_pile **a, t_pile **b)
{
	t_moves	best;
	int		i;
	int		size;

	while (get_size(a) > 3)
		push_top_half(a, b, get_size(a) / 2);
	if (!ft_issorted(*a) && get_size(a) == 3)
		small_sort(a);
	size = get_size(b);
	i = 0;
	while (i < size)
	{
		best = calc_best_moves_rev(a, b, best);
		push_elem_b_to_a(a, b, best);
		i++;
	}
	final_ra(a);
}
