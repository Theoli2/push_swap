/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_pile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlivroze <tlivroze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 13:46:32 by tlivroze          #+#    #+#             */
/*   Updated: 2023/05/14 13:58:39 by tlivroze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

int	verif_pile(char **argv, int argc, t_data *data)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	data->size = argc - 1;
	data->tab = malloc(sizeof(int) * data->size);
	if (!(data->tab))
		return (-1);
	while (i < argc)
	{
		if (ft_atol(argv[i]) > INT_MAX || ft_atol(argv[i]) < INT_MIN)
			return (-1);
		data->tab[j] = ft_atoi(argv[i]);
		i++;
		j++;
	}
	if (verif_double(data->tab, data->size) == -1)
		return (-1);
	return (0);
}
