/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlivroze <tlivroze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:47:11 by tlivroze          #+#    #+#             */
/*   Updated: 2023/05/02 00:17:59 by tlivroze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <math.h>
# include <stdlib.h>
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
t_pile		*ft_pilelast(t_pile *lst);
t_pile		*ft_pilenew(int value);
void		ft_pileadd_front(t_pile **lst, t_pile *new);
void		ft_pileadd_back(t_pile **lst, t_pile *new);
void		print_pile(t_pile **pile);
void		print_all_pile(t_pile **a, t_pile **b);

#endif