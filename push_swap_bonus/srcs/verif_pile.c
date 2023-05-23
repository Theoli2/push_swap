/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_pile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlivroze <tlivroze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 13:46:32 by tlivroze          #+#    #+#             */
/*   Updated: 2023/05/23 06:07:06 by tlivroze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

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

int	verif_overflow(char *argv)
{
	char	*str;

	if (argv[0] == '+')
	{
		str = ft_itoa(ft_atoi(&argv[1]));
		if (ft_strncmp(&argv[1], str, ft_strlen(str)))
			return (free(str), -1);
		free(str);
	}
	str = ft_itoa(ft_atoi(argv));
	if (ft_strncmp(argv, str, ft_strlen(str)))
		return (free(str), -1);
	free(str);
	return (1);
}

int	verif_pile(char **argv, int argc, t_data *data)
{
	int	i;

	i = 1;
	data->size = argc - 1;
	data->tab = malloc(sizeof(int) * data->size);
	if (!(data->tab))
		return (-1);
	while (i < argc)
	{
		if (argv[i][0] == '\0')
			return (ft_putstr_fd("Error\n", 2), -1);
		if (verif_only_numbers(argv[i]) == -1)
			return (ft_putstr_fd("Error\n", 2), -1);
		if (verif_only_plus_minus(argv[i]) == -1)
			return (ft_putstr_fd("Error\n", 2), -1);
		if (verif_overflow(argv[i]) == -1)
			return (ft_putstr_fd("Error\n", 2), -1);
		data->tab[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	if (verif_double(data->tab, data) == -1)
		return (-1);
	return (0);
}
