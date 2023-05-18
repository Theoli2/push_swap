/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlivroze <tlivroze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 03:32:49 by tlivroze          #+#    #+#             */
/*   Updated: 2023/05/18 09:42:40 by tlivroze         ###   ########.fr       */
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
	ft_push(a, b);
}

void	pb(t_pile **a, t_pile **b)
{
	ft_push(b, a);
}
