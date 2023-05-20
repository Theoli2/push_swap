/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlivroze <tlivroze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 13:33:58 by tlivroze          #+#    #+#             */
/*   Updated: 2023/05/20 04:07:40 by tlivroze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include "../libft/libft.h"

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

int		verif_pile(char **argv, int argc, t_data *data);
int		verif_line(char *line);
char	*read_instructions(void);
void	ft_pileadd_front(t_pile **lst, t_pile *new);
void	ft_pileadd_back(t_pile **lst, t_pile *new);
void	ft_piledelone(t_pile *lst);
void	pa(t_pile **a, t_pile **b);
void	pb(t_pile **a, t_pile **b);
void	sa(t_pile *a);
void	sb(t_pile *b);
void	ss(t_pile *a, t_pile *b);
void	ra(t_pile **a);
void	rb(t_pile **b);
void	rr(t_pile **a, t_pile **b);
void	rra(t_pile **a);
void	rrb(t_pile **b);
void	rrr(t_pile **a, t_pile **b);
void	execute_instructions(char *line, t_pile **a, t_pile **b);
t_pile	*ft_pilenew(int value, int index);
t_pile	*ft_pilelast(t_pile *lst);

#endif