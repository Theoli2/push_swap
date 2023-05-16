/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlivroze <tlivroze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 04:06:54 by tlivroze          #+#    #+#             */
/*   Updated: 2023/05/16 04:28:20 by tlivroze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	do_instructions(char *line, t_pile **a, t_pile **b)
{
	if (ft_strncmp(line, "sa\n", ft_strlen(line)) == 0)
		sa(*a);
	else if (ft_strncmp(line, "sb\n", ft_strlen(line)) == 0)
		sb(*b);
	else if (ft_strncmp(line, "ss\n", ft_strlen(line)) == 0)
		ss(*a, *b);
	else if (ft_strncmp(line, "pa\n", ft_strlen(line)) == 0)
		pa(a, b);
	else if (ft_strncmp(line, "pb\n", ft_strlen(line)) == 0)
		pb(a, b);
	else if (ft_strncmp(line, "ra\n", ft_strlen(line)) == 0)
		ra(a);
	else if (ft_strncmp(line, "rb\n", ft_strlen(line)) == 0)
		rb(b);
	else if (ft_strncmp(line, "rr\n", ft_strlen(line)) == 0)
		rr(a, b);
	else if (ft_strncmp(line, "rra\n", ft_strlen(line)) == 0)
		rra(a);
	else if (ft_strncmp(line, "rrb\n", ft_strlen(line)) == 0)
		rrb(b);
	else if (ft_strncmp(line, "rrr\n", ft_strlen(line)) == 0)
		rrr(a, b);
}

void	execute_instructions(char *line, t_pile **a, t_pile **b)
{
	char	**tab;
	int		i;

	tab = ft_split(line, '\n');
	i = 0;
	while (tab[i])
	{
		do_instructions(tab[i], a, b);
		i++;
	}
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
