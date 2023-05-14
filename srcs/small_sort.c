/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlivroze <tlivroze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:31:00 by tlivroze          #+#    #+#             */
/*   Updated: 2023/05/09 14:22:42 by tlivroze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	small_sort_bis(t_pile **a)
{
	if ((*a)->next->value > (*a)->next->next->value)
	{
		ra(a);
		sa(*a);
		return ;
	}
	if ((*a)->value > (*a)->next->next->value)
	{
		ra(a);
		return ;
	}
	else
		sa(*a);
}

void	small_sort(t_pile **a)
{
	int	x;
	int	y;
	int	z;

	x = (*a)->value;
	y = (*a)->next->value;
	z = (*a)->next->next->value;
	if (x < y && y > z && z > x)
	{
		rra(a);
		sa(*a);
	}
	else if (x > y && x < z)
		sa(*a);
	else if (x < y && x > z)
		rra(a);
	else if (x > y && y < z)
		ra(a);
	else
	{
		sa(*a);
		rra(a);
	}
}
