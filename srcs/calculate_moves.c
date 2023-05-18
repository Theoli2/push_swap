/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlivroze <tlivroze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:04:42 by tlivroze          #+#    #+#             */
/*   Updated: 2023/05/18 07:52:15 by tlivroze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

t_moves	optimize_moves(t_moves curr)
{
	while (curr.ra > 0 && curr.rb > 0)
	{
		curr.ra--;
		curr.rb--;
		curr.rr++;
	}
	while (curr.rra > 0 && curr.rrb > 0)
	{
		curr.rra--;
		curr.rrb--;
		curr.rrr++;
	}
	return (curr);
}
