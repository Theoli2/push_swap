/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlivroze <tlivroze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 13:33:04 by tlivroze          #+#    #+#             */
/*   Updated: 2023/05/23 10:35:48 by tlivroze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

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

bool	ft_issorted(t_pile	*a)
{
	t_pile	*tmp;

	tmp = a;
	while (a->next)
	{
		if (a->value < a->next->value)
			a = a->next;
		else
			return (false);
	}
	a = tmp;
	return (true);
}

int	main2(t_pile *a, t_pile *b, t_data data, char *line)
{
	if (line == NULL)
	{
		free_list(&b);
		free_list(&a);
		free(data.tab);
		return (1);
	}
	if (ft_strncmp(line, "empty\n", 6))
		execute_instructions(line, &a, &b);
	if (b == NULL && ft_issorted(a) == true)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	if (ft_strncmp(line, "empty\n", 6))
		free(line);
	free_list(&a);
	free_list(&b);
	free(data.tab);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_pile	*a;
	t_pile	*b;
	char	*line;
	int		temp;

	if (argc == 1)
		return (1);
	if (verif_pile(argv, argc, &data) == -1)
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
	line = read_instructions();
	get_next_line_close();
	main2(a, b, data, line);
	return (0);
}
