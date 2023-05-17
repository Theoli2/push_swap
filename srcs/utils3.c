/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlivroze <tlivroze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 11:48:06 by tlivroze          #+#    #+#             */
/*   Updated: 2023/05/16 09:29:25 by tlivroze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

t_moves	calc_moves_b_bis(t_pile	*head, t_moves curr, int index, int size)
{
	int	pos;

	pos = 0;
	while (head && index != head->index)
	{
		pos++;
		head = head->next;
	}
	if (pos < size / 2)
		curr.rb = pos;
	else
		curr.rrb = size - pos;
	return (curr);
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