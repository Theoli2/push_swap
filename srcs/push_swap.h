/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlivroze <tlivroze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:47:11 by tlivroze          #+#    #+#             */
/*   Updated: 2023/05/18 09:37:47 by tlivroze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include "../libft/libft.h"

typedef struct s_moves
{
	int	index;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	total;
}				t_moves;

typedef struct s_data
{
	int	*tab;
	int	size;
}				t_data;

typedef struct s_pile
{
	int				value;
	int				index;
	struct s_pile	*next;
}				t_pile;

int			verif(char **argv, int argc, t_data *data);
int			get_size(t_pile **a);
int			find_biggest(t_pile *b);
void		ft_pileadd_front(t_pile **lst, t_pile *new);
void		sa(t_pile *pile);
void		sb(t_pile *pile);
void		ss(t_pile *a, t_pile *b);
void		pa(t_pile **a, t_pile **b);
void		pb(t_pile **a, t_pile **b);
void		ra(t_pile **a);
void		rb(t_pile **a);
void		rr(t_pile **a, t_pile **b);
void		rra(t_pile **a);
void		rrb(t_pile **b);
void		rrr(t_pile **a, t_pile **b);
void		rotate_all(t_pile **a, t_pile **b, t_moves best);
void		rotate_a(t_pile **a, t_moves best);
void		rotate_b(t_pile **b, t_moves best);
void		final_ra(t_pile **a);
void		small_sort(t_pile **a);
void		put_index(t_pile **a, t_data data);
void		big_sort(t_pile **a, t_pile **b);
void		push_elem_b_to_a(t_pile **a, t_pile **b, t_moves best);
bool		ft_issorted(t_pile	*a);
t_pile		*ft_pilelast(t_pile *lst);
t_pile		*ft_pilenew(int value, int index);
t_moves		optimize_moves(t_moves curr);
t_moves		calc_best_moves_rev(t_pile **a, t_pile **b, t_moves best);
t_moves		init(t_moves moves, int init, int index);
t_moves		calc_a_rev_bis(t_pile	*head, t_moves curr, int index, int size);
t_moves		calc_moves_a_rev(t_pile **a, t_moves curr);
t_moves		calc_moves_b_rev(t_pile **b, t_moves curr);

#endif