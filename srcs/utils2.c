/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlivroze <tlivroze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 09:04:03 by tlivroze          #+#    #+#             */
/*   Updated: 2023/05/09 14:23:01 by tlivroze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

bool	ft_issorted(t_pile	*a)
{
	t_pile	*tmp;

	tmp = a;
	while (a->next)
	{
		if (a->value < a->next->value)
			a = a->next;
		else
			return (false);
	}
	a = tmp;
	return (true);
}

int	ft_pilesize(t_pile *lst)
{
	int	i;

	i = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

int	get_minimum(t_pile *a)
{
	long	i;
	t_pile	*tmp;

	i = INT_MAX;
	tmp = a;
	while (a->next)
	{
		if (a->value < i)
			i = a->value;
		a = a->next;
	}
	if (a->value < i)
		i = a->value;
	a = tmp;
	return (i);
}

int	get_position(t_pile *a, int value)
{
	int		i;
	t_pile	*tmp;

	tmp = a;
	i = 0;
	while (a->next)
	{
		if (a->value == value)
			return (a = tmp, i);
		a = a->next;
		i++;
	}
	return (a = tmp, i);
}
