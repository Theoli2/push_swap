/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlivroze <tlivroze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:04:42 by tlivroze          #+#    #+#             */
/*   Updated: 2023/05/14 03:44:04 by tlivroze         ###   ########.fr       */
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

/*
t_lst	*prev;

while (head)
{
	prev = head;
	head = head->next;
	free(prev);
}
*/

int	find_biggest_smaller(t_pile *b, int index)
{
	t_pile	*head;

	index = index - 1;
	head = b;
	// printf("index = %d; data size : %d\n", index, data.size);
	while (index >= 0)
	{
		// printf("test\n");
		while (head)
		{
			// printf("head index = %d\n", head->index);
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
	// printf("pos = %d\n", pos);
	if (pos <= size / 2)
	{
		curr.ra = pos;
		// printf("curr ra = %d\n", curr.ra);
	}
	else
	{
		curr.rra = size - pos;
		// printf("curr rra = %d\n", curr.rra);
	}
	return (curr);
}

t_moves	calc_moves_b(t_pile **b, t_moves curr)
{
	t_pile	*head;
	int		pos;
	int		size;
	int		index;

	size = 0;
	pos = 0;
	head = *b;
	// printf("curr index = %d\n", curr.index);
	while (head)
	{
		size++;
		head = head->next;
	}
	// printf("size = %d\n", size);
	head = *b;
	index = find_biggest_smaller(*b, curr.index);
	// printf("index returned = %d\n", index);
	if (index == -1)
		index = find_biggest(*b);
	while (head && index != head->index)
	{
		pos++;
		head = head->next;
	}
	head = *b;
	//printf("pos = %d\n", pos);
	if (pos < size / 2)
	{
		curr.rb = pos;
	//	printf("curr rb = %d\n", curr.rb);
	}
	else
	{
		curr.rrb = size - pos;
	//	printf("curr rrb = %d\n", curr.rrb);
	}
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
