/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_moves_rev.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlivroze <tlivroze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 08:41:40 by tlivroze          #+#    #+#             */
/*   Updated: 2023/05/18 02:49:45 by tlivroze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

// int	find_smallest(t_pile *a)
// {
// 	t_pile	*head;
// 	int		smallest;

// 	head = a;
// 	smallest = head->index;
// 	while (head)
// 	{
// 		if (head->index < smallest)
// 			smallest = head->index;
// 		head = head->next;
// 	}
// 	return (smallest);
// }

int	find_smallest(t_pile *a)
{
	int	index_min;

	if (!a)
		return (-1);
	index_min = a->index;
	while (a)
	{
		if (a->index < index_min)
			index_min = a->index;
		a = a->next;
	}
	return (index_min);
}

// int	find_smallest_bigger(t_pile *a, int index, int size)
// {
// 	t_pile	*head;

// 	printf("index initial = %d\n", index);
// 	index = index + 1;
// 	head = a;
// 	// printf("size = %d\n", size);
// 	while (index < size)
// 	{
// 		while (head)
// 		{
// 			if (head->index == index)
// 			{
// 				// printf("index = %d\n", head->index);
// 				return (head->index);
// 			}
// 			head = head->next;
// 		}
// 		index++;
// 		head = a;
// 	}
// 	printf("je trouve cet index = %d\n", index - 1);
// 	return (-1);
// }

int	find_smallest_bigger_rev(t_pile *a, int index, int size)
{
	int	index_a;

	(void)size;
	index_a = find_biggest(a);
	while (a)
	{
		if (a->index > index && index_a > a->index)
			index_a = a->index;
		a = a->next;
	}
	if (index_a < index)
		return (find_smallest(a));
	return (index_a);
}

t_moves	calc_moves_b_rev(t_pile **b, t_moves curr)
{
	t_pile	*head;
	int		pos;
	int		size;

	size = 0;
	pos = 0;
	head = *b;
	while (head)
	{
		size++;
		head = head->next;
	}
	head = *b;
	while (head && head->index != curr.index)
	{
		pos++;
		head = head->next;
	}
	head = *b;
	if (pos <= size / 2)
		curr.rb = pos;
	else
		curr.rrb = size - pos;
	return (curr);
}

t_moves	calc_moves_a_rev(t_pile **a, t_moves curr)
{
	t_pile	*head;
	int		size;
	int		index;

	size = 0;
	head = *a;
	while (head)
	{
		size++;
		head = head->next;
	}
	head = *a;
	index = find_smallest_bigger_rev(*a, curr.index, size);
	if (index == -1)
		index = find_smallest(*a);
	curr = calc_a_rev_bis(head, curr, index, size);
	return (curr);
}
