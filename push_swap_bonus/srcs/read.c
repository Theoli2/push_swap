/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlivroze <tlivroze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 02:55:33 by tlivroze          #+#    #+#             */
/*   Updated: 2023/05/23 10:32:27 by tlivroze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

int	check_instructions(char *line)
{
	if (ft_strncmp(line, "sa\n", 3) == 0)
		return (1);
	if (ft_strncmp(line, "sb\n", 3) == 0)
		return (1);
	if (ft_strncmp(line, "ss\n", 3) == 0)
		return (1);
	if (ft_strncmp(line, "pa\n", 3) == 0)
		return (1);
	if (ft_strncmp(line, "pb\n", 3) == 0)
		return (1);
	if (ft_strncmp(line, "ra\n", 3) == 0)
		return (1);
	if (ft_strncmp(line, "rb\n", 3) == 0)
		return (1);
	if (ft_strncmp(line, "rr\n", 3) == 0)
		return (1);
	if (ft_strncmp(line, "rra\n", 4) == 0)
		return (1);
	if (ft_strncmp(line, "rrb\n", 4) == 0)
		return (1);
	if (ft_strncmp(line, "rrr\n", 4) == 0)
		return (1);
	return (-1);
}

char	*read_instructions(void)
{
	char	*buffer;
	char	*line;

	line = NULL;
	buffer = NULL;
	buffer = get_next_line(STDIN_FILENO);
	if (buffer == NULL)
		return (free(buffer), "empty\n");
	while (buffer != NULL)
	{
		if (check_instructions(buffer) == -1)
			return (ft_putstr_fd("Error\n", 2), free(buffer), free(line), NULL);
		if (line == NULL)
			line = ft_strdup(buffer);
		else
			line = ft_strjoin(line, buffer);
		buffer = get_next_line(STDIN_FILENO);
	}
	return (free(buffer), line);
}
