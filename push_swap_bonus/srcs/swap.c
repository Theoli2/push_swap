/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlivroze <tlivroze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 03:32:40 by tlivroze          #+#    #+#             */
/*   Updated: 2023/05/18 09:44:08 by tlivroze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

bool	ft_swap(t_pile *pile)
{
	int	temp;

	if (pile && pile->next)
	{
		temp = pile->value;
		pile->value = pile->next->value;
		pile->next->value = temp;
		temp = pile->index;
		pile->index = pile->next->index;
		pile->next->index = temp;
		return (true);
	}
	return (false);
}

void	sa(t_pile *a)
{
	ft_swap(a);
}

void	sb(t_pile *b)
{
	ft_swap(b);
}

void	ss(t_pile *a, t_pile *b)
{
	if ((a && a->next) && (b && b->next))
	{
		ft_swap(a);
		ft_swap(b);
	}
}
