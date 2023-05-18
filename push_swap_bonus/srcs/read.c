/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlivroze <tlivroze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 02:55:33 by tlivroze          #+#    #+#             */
/*   Updated: 2023/05/19 01:08:01 by tlivroze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

int	check_instructions(char *line)
{
	if (ft_strncmp(line, "sa\n", ft_strlen(line)) == 0)
		return (1);
	if (ft_strncmp(line, "sb\n", ft_strlen(line)) == 0)
		return (1);
	if (ft_strncmp(line, "ss\n", ft_strlen(line)) == 0)
		return (1);
	if (ft_strncmp(line, "pa\n", ft_strlen(line)) == 0)
		return (1);
	if (ft_strncmp(line, "pb\n", ft_strlen(line)) == 0)
		return (1);
	if (ft_strncmp(line, "ra\n", ft_strlen(line)) == 0)
		return (1);
	if (ft_strncmp(line, "rb\n", ft_strlen(line)) == 0)
		return (1);
	if (ft_strncmp(line, "rr\n", ft_strlen(line)) == 0)
		return (1);
	if (ft_strncmp(line, "rra\n", ft_strlen(line)) == 0)
		return (1);
	if (ft_strncmp(line, "rrb\n", ft_strlen(line)) == 0)
		return (1);
	if (ft_strncmp(line, "rrr\n", ft_strlen(line)) == 0)
		return (1);
	return (-1);
}

char	*read_instructions(void)
{
	char	*buffer;
	char	*line;

	line = NULL;
	buffer = NULL;
	while (1)
	{
		buffer = get_next_line(STDIN_FILENO);
		if (check_instructions(buffer) == -1)
		{
			printf("line= %s\n", line);
			return (write(2, "Error\n", 6), free(buffer), free(line), NULL);
		}
		if (buffer == NULL)
			return (free(buffer), line);
		if (line == NULL)
			line = ft_strdup(buffer);
		else
			line = ft_strjoin(line, buffer);
		buffer = NULL;
	}
	return (line);
}
