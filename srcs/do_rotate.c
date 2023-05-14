/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlivroze <tlivroze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:20:15 by tlivroze          #+#    #+#             */
/*   Updated: 2023/05/11 18:52:03 by tlivroze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	rotate_all(t_pile **a, t_pile **b, t_moves best)
{
	int	i;

	i = 0;
	while (i < best.rr)
	{
		rr(a, b);
		i++;
	}
	i = 0;
	while (i < best.rrr)
	{
		rrr(a, b);
		i++;
	}
}

void	rotate_a(t_pile **a, t_moves best)
{
	int	i;

	i = 0;
	while (i < best.ra)
	{
		ra(a);
		i++;
	}
	i = 0;
	while (i < best.rra)
	{
		rra(a);
		i++;
	}
}

void	rotate_b(t_pile **b, t_moves best)
{
	int	i;

	i = 0;
	while (i < best.rb)
	{
		rb(b);
		i++;
	}
	i = 0;
	while (i < best.rrb)
	{
		rrb(b);
		i++;
	}
}
