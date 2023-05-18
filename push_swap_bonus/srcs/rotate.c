/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlivroze <tlivroze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 03:33:17 by tlivroze          #+#    #+#             */
/*   Updated: 2023/05/18 09:43:42 by tlivroze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

bool	ft_rotate(t_pile **a)
{
	t_pile	*tmp;
	t_pile	*head;

	if (*a)
	{
		head = (*a);
		tmp = (*a);
		while (head->next)
			head = head->next;
		head->next = tmp;
		*a = tmp->next;
		tmp->next = NULL;
		return (true);
	}
	return (false);
}

void	ra(t_pile **a)
{
	ft_rotate(a);
}

void	rb(t_pile **b)
{
	ft_rotate(b);
}

void	rr(t_pile **a, t_pile **b)
{
	if (*a && (*a)->next && *b && (*b)->next)
	{
		ft_rotate(a);
		ft_rotate(b);
	}
}
