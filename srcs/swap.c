/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlivroze <tlivroze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 03:32:40 by tlivroze          #+#    #+#             */
/*   Updated: 2023/05/09 14:22:45 by tlivroze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

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
	if (ft_swap(a) == true)
		write(1, "sa\n", 3);
}

void	sb(t_pile *b)
{
	if (ft_swap(b) == true)
		write(1, "sb\n", 3);
}

void	ss(t_pile *a, t_pile *b)
{
	if ((a && a->next) && (b && b->next))
	{
		ft_swap(a);
		ft_swap(b);
		write(1, "ss\n", 3);
	}
}
