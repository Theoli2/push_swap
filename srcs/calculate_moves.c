/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlivroze <tlivroze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:04:42 by tlivroze          #+#    #+#             */
/*   Updated: 2023/05/14 12:09:29 by tlivroze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	find_biggest(t_pile *b)
{
	t_pile	*head;
	int		biggest;

	head = b;
	biggest = head->index;
	while (head)
	{
		if (head->index > biggest)
			biggest = head->index;
		head = head->next;
	}
	return (biggest);
}

int	find_biggest_smaller(t_pile *b, int index)
{
	t_pile	*head;

	index = index - 1;
	head = b;
	while (index >= 0)
	{
		while (head)
		{
			if (head->index == index)
				return (head->index);
			head = head->next;
		}
		index--;
		head = b;
	}
	return (-1);
}

t_moves	calc_moves_a(t_pile **a, t_moves curr)
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
	while (head && head->index != curr.index)
	{
		pos++;
		head = head->next;
	}
	head = *a;
	if (pos <= size / 2)
		curr.ra = pos;
	else
		curr.rra = size - pos;
	return (curr);
}

t_moves	calc_moves_b(t_pile **b, t_moves curr)
{
	t_pile	*head;
	int		size;
	int		index;

	size = 0;
	head = *b;
	while (head)
	{
		size++;
		head = head->next;
	}
	head = *b;
	index = find_biggest_smaller(*b, curr.index);
	if (index == -1)
		index = find_biggest(*b);
	curr = calc_moves_b_bis(head, curr, index, size);
	return (curr);
}

t_moves	optimize_moves(t_moves curr)
{
	while (curr.ra > 0 && curr.rb > 0)
	{
		curr.ra--;
		curr.rb--;
		curr.rr++;
	}
	while (curr.rra > 0 && curr.rrb > 0)
	{
		curr.rra--;
		curr.rrb--;
		curr.rrr++;
	}
	return (curr);
}
