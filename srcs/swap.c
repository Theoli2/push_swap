/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlivroze <tlivroze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 03:32:40 by tlivroze          #+#    #+#             */
/*   Updated: 2023/05/03 06:14:46 by tlivroze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_swap(t_pile *pile)
{
	int	temp;

	if (pile && pile->next)
	{
		temp = pile->value;
		pile->value = pile->next->value;
		pile->next->value = temp;		
	}
}

void	ft_swaps(t_pile *a, t_pile *b)
{
	ft_swap(a);
	ft_swap(b);
}
