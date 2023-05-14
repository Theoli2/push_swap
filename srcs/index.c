/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlivroze <tlivroze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:24:25 by tlivroze          #+#    #+#             */
/*   Updated: 2023/05/11 18:59:30 by tlivroze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	*sort_tab(int *tab, t_data data)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	j = 0;
	while (i < data.size - 1)
	{
		while (j < data.size)
		{
			if (tab[i] > tab[j])
			{
				temp = tab[i];
				tab[i] = tab[j];
				tab[j] = temp;
			}
			j++;
		}
		i++;
		j = i + 1;
	}
	return (tab);
}

int	*init_index(t_pile **a, int *tab)
{
	t_pile	*head;
	int		i;

	head = *a;
	i = 0;
	while ((*a))
	{
		(*a)->index = -1;
		tab[i] = (*a)->value;
		(*a) = (*a)->next;
		i++;
	}
	(*a) = head;
	return (tab);
}

void	put_index(t_pile **a, t_data data)
{
	t_pile	*head;
	int		*tab;
	int		index;

	head = *a;
	index = 0;
	tab = malloc(sizeof(int) * data.size);
	if (tab == NULL)
	{
		exit (EXIT_FAILURE);
	}
	tab = init_index(a, tab);
	tab = sort_tab(tab, data);
	while (index < data.size)
	{
		while ((*a))
		{
			if ((*a)->value == tab[index])
			{
				(*a)->index = index;
			}
			(*a) = (*a)->next;
		}
		(*a) = head;
		index++;
	}
	free(tab);
}
