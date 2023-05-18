/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlivroze <tlivroze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:41:31 by tlivroze          #+#    #+#             */
/*   Updated: 2023/05/18 07:37:37 by tlivroze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	print_index(t_pile *a)
{
	t_pile	*b;

	b = a;
	while (a)
	{
		printf("%i\n", a->index);
		a = a->next;
	}
	a = b;
}

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
		return ;
	if (data.size == 2 && a->value > a->next->value)
		sa(a);
	else if (data.size == 3)
		small_sort(&a);
	else if (data.size > 3)
		big_sort_alt(&a, &b);
	// print_all_pile(&a, &b);
	free_list(&a);
	free_list(&b);
	free(data.tab);
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_pile	*a;
	t_pile	*b;
	int		temp;

	if (verif(argv, argc, &data) == -1)
		return (1);
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
