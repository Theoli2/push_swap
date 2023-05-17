/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlivroze <tlivroze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 03:33:17 by tlivroze          #+#    #+#             */
/*   Updated: 2023/05/16 07:01:26 by tlivroze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

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
