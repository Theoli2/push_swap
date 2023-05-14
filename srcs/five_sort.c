/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlivroze <tlivroze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:28:19 by tlivroze          #+#    #+#             */
/*   Updated: 2023/05/09 14:22:21 by tlivroze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	five_sort(t_pile **a, t_pile **b)
{
	int	i;

	while (ft_pilesize(*a) > 3)
	{
		i = get_position(*a, get_minimum(*a));
		if (i < ft_pilesize(*a) / 2)
		{
			while ((*a)->value != get_minimum(*a))
				ra(a);
		}
		else
		{
			while ((*a)->value != get_minimum(*a))
				rra(a);
		}
		pb(a, b);
	}
	small_sort(a);
	while (*b)
		pa(a,b);
}
