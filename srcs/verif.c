/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlivroze <tlivroze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 18:12:45 by tlivroze          #+#    #+#             */
/*   Updated: 2023/05/18 09:29:22 by tlivroze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	verif_only_numbers(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_strchr("-+0123456789", str[i]))
			return (-1);
		i++;
	}
	return (0);
}

int	verif_only_plus_minus(char *str)
{
	int	i;

	i = 0;
	if (ft_strchr("-+", str[i]))
	{
		if (str[i + 1] == '\0')
			return (-1);
	}
	return (0);
}

int	verif_double(int *tab, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i + 1 < data->size)
	{
		j = i + 1;
		while (j < data->size)
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
	data->tab = malloc(sizeof(int) * (argc - 1));
	if (data->tab == NULL)
		return (-1);
	while (argv[i])
	{
		if (verif_only_numbers(argv[i]) == -1)
			return (-1);
		if (verif_only_plus_minus(argv[i]) == -1)
			return (-1);
		if (ft_atol(argv[i]) > INT_MAX || ft_atol(argv[i]) < INT_MIN)
			return (-1);
		data->tab[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	data->size = i - 1;
	if (verif_double(data->tab, data) == -1)
		return (-1);
	return (1);
}
