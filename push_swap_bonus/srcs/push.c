/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlivroze <tlivroze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 03:32:49 by tlivroze          #+#    #+#             */
/*   Updated: 2023/05/16 06:46:47 by tlivroze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

bool	ft_push(t_pile **a, t_pile **b)
{
	t_pile	*tmp;

	if ((*b))
	{
		tmp = (*b)->next;
		(*b)->next = (*a);
		(*a) = (*b);
		(*b) = tmp;
		return (true);
	}
	return (false);
}

void	pa(t_pile **a, t_pile **b)
{
	if (ft_push(a, b) == true)
		write(1, "pa\n", 3);
}

void	pb(t_pile **a, t_pile **b)
{
	if (ft_push(b, a) == true)
		write(1, "pb\n", 3);
}
