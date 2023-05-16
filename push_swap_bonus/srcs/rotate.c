/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlivroze <tlivroze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 03:33:17 by tlivroze          #+#    #+#             */
/*   Updated: 2023/05/16 03:44:55 by tlivroze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

bool	ft_rotate(t_pile **a)
{
	t_pile	*tmp;

	if (*a && (*a)->next)
	{
		tmp = (*a);
		*a = (*a)->next;
		tmp->next = NULL;
		ft_pileadd_back(a, ft_pilenew(tmp->value, tmp->index));
		ft_piledelone(tmp);
		return (true);
	}
	return (false);
}

void	ra(t_pile **a)
{
	if (ft_rotate(a) == true)
		write(1, "ra\n", 3);
}

void	rb(t_pile **b)
{
	if (ft_rotate(b) == true)
		write(1, "rb\n", 3);
}

void	rr(t_pile **a, t_pile **b)
{
	if (*a && (*a)->next && *b && (*b)->next)
	{
		ft_rotate(a);
		ft_rotate(b);
		write(1, "rr\n", 3);
	}
}
