/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlivroze <tlivroze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:24:04 by tlivroze          #+#    #+#             */
/*   Updated: 2023/05/18 07:41:57 by tlivroze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

t_moves	init(t_moves moves, int init, int index)
{
	moves.index = index;
	moves.ra = init;
	moves.rb = init;
	moves.rr = init;
	moves.rra = init;
	moves.rrb = init;
	moves.rrr = init;
	moves.total = init;
	return (moves);
}
