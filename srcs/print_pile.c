/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlivroze <tlivroze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 11:44:09 by tlivroze          #+#    #+#             */
/*   Updated: 2023/05/14 11:45:30 by tlivroze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	print_pile(t_pile **pile)
{
	int		i;
	t_pile	*tmp;

	if (*pile == NULL)
	{
		ft_printf("[ Empty ]\n");
		return;
	}
	i = 0;
	tmp = (*pile);
	while ((*pile)->next)
	{
		ft_printf("[ %i ]  ",(*pile)->value);
		ft_printf("[ %i ]\n",(*pile)->index);
        (*pile) = (*pile)->next;
        i++;
    }
    ft_printf("[ %i ]  ",(*pile)->value);
    ft_printf("[ %i ]\n\n",(*pile)->index);
    (*pile) = tmp;
}

void print_all_pile(t_pile **a, t_pile **b)
{
    t_pile *tmp_a;
    t_pile *tmp_b;

    tmp_a = (*a);
    tmp_b = (*b);

    ft_printf("\t[ A ]\t|   [ B ]\n");
    ft_printf("       --------------------\n");
    while (tmp_a || tmp_b)
    {
        if (tmp_a && tmp_b)
        {

            ft_printf("\t[ %i ]\t|",tmp_a->value);
            ft_printf("   [ %i ]\n",tmp_b->value);
            tmp_a = tmp_a->next;
            tmp_b = tmp_b->next;
        }
        else if (tmp_a && !tmp_b)
        {
            ft_printf("\t[ %i ]\t|\t\n",tmp_a->value);
            tmp_a = tmp_a->next;
        }
        else if (!tmp_a && tmp_b)
        {
            ft_printf("\t\t|   [ %i ]\n",tmp_b->value);
            tmp_b = tmp_b->next;
        }
        else
            ft_printf("[ Empty ]\t|\t[ Empty ]\n");
    }
    ft_printf("       --------------------\n\n");
}