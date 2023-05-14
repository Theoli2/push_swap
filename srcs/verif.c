/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlivroze <tlivroze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 18:12:45 by tlivroze          #+#    #+#             */
/*   Updated: 2023/05/09 14:22:56 by tlivroze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	arg_is_nb(char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (ft_isdigit(av[i][j]) == 0 && (j != 0 && (av[i][j] \
			!= '-' || av[i][j] != '+')))
			{
				printf("test\n");
				return (-1);
			}
			j++;
		}
		if (ft_atoi(av[i]) > INT_MAX || ft_atoi(av[i]) < INT_MIN)
		{
			return (-1);
		}
		i++;
	}
	return (1);
}

int	verif_double(int *tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = i + 1;
		while (tab[j])
		{
			if (tab[i] == tab[j])
			{
				free(tab);
				return (-1);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	verif(char **argv, int argc, t_data *data)
{
	int	i;

	if (argc < 2)
		return (-1);
	i = 1;
	if (arg_is_nb(argv) == -1)
		return (-1);
	data->tab = malloc(sizeof(int) * (argc - 1));
	if (data->tab == NULL)
		return (-1);
	while (argv[i])
	{
		data->tab[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	data->size = i - 1;
	if (verif_double(data->tab) == -1)
		return (-1);
	return (1);
}
