/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlivroze <tlivroze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:41:31 by tlivroze          #+#    #+#             */
/*   Updated: 2023/05/23 05:16:24 by tlivroze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	free_list(t_pile **list)
{
	t_pile	*tmp;

	while (*list)
	{
		tmp = (*list)->next;
		free(*list);
		*list = tmp;
	}
}

void	main2(t_pile *a, t_pile *b, t_data data)
{
	if (ft_issorted(a) == true)
		return (free_list(&a), free_list(&b), free(data.tab));
	if (data.size == 2 && a->value > a->next->value)
		sa(a);
	else if (data.size == 3)
		small_sort(&a);
	else if (data.size > 3)
		big_sort(&a, &b);
	(free_list(&a), free_list(&b), free(data.tab));
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_pile	*a;
	t_pile	*b;
	int		temp;

	if (verif(argv, argc, &data) == -1)
		return (free(data.tab), 1);
	a = NULL;
	b = NULL;
	(void)b;
	temp = data.size;
	while (temp > 0)
	{
		ft_pileadd_front(&a, ft_pilenew(data.tab[temp - 1], -1));
		temp--;
	}
	put_index(&a, data);
	main2(a, b, data);
	return (0);
}
