/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlivroze <tlivroze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:41:31 by tlivroze          #+#    #+#             */
/*   Updated: 2023/05/03 05:53:54 by tlivroze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	t_data	data;
	t_pile	*a;
	t_pile	*b;

	if (verif(argv, argc, &data) == -1)
		return (0);
	a = NULL;
	b = NULL;
	printf("%i\n", data.size);
	while (data.size > 0)
	{
		ft_pileadd_front(&a, ft_pilenew(data.tab[data.size - 1]));
		data.size--;
	}
	ft_swap(&a);
	print_all_pile(&a, &b);
	return (1);
}
