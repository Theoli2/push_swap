/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlivroze <tlivroze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:47:11 by tlivroze          #+#    #+#             */
/*   Updated: 2023/05/03 14:24:37 by tlivroze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <stdbool.h>
# include "libft/libft.h"

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
void		ft_pileadd_front(t_pile **lst, t_pile *new);
void		ft_pileadd_back(t_pile **lst, t_pile *new);
void		print_pile(t_pile **pile);
void		print_all_pile(t_pile **a, t_pile **b);
void		sa(t_pile *pile);
void		sb(t_pile *pile);
void		ss(t_pile *a, t_pile *b);
void		pa(t_pile **a, t_pile **b);
void		pb(t_pile **a, t_pile **b);
void		ra(t_pile **a);
void		rb(t_pile **a);
void		rs(t_pile **a, t_pile **b);
void		rra(t_pile **a);
void		rrb(t_pile **b);
void		rrs(t_pile **a, t_pile **b);
void		ft_piledelone(t_pile *lst);
t_pile		*ft_pilelast(t_pile *lst);
t_pile		*ft_pilenew(int value, int index);

#endif