/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlivroze <tlivroze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:41:31 by tlivroze          #+#    #+#             */
/*   Updated: 2023/05/14 03:03:30 by tlivroze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	print_index(t_pile *a)
{
	t_pile *b;

	b = a;
	while(a)
	{
		printf("%i\n", a->index);
		a = a->next;
	}
	a = b;
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
	if (ft_issorted(a) == true)
		return (0);
	// if (data.size == 2 && a->value > a->next->value)
	// 	sa(a);
	// else if (data.size == 3)
	// 	small_sort(&a);
	// else if (data.size < 100)
	// 	five_sort(&a, &b);
	// else if (data.size >= 100)
	big_sort(&a, &b);
	// print_index(a);
	// print_all_pile(&a, &b);
	return (0);
}
