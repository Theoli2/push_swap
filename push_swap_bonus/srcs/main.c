/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlivroze <tlivroze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 13:33:04 by tlivroze          #+#    #+#             */
/*   Updated: 2023/05/14 13:45:45 by tlivroze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

int	main(int argc, char **argv)
{
	t_data	data;
	t_pile	*a;
	t_pile	*b;

	if (argc == 1)
		return (1);
	if (verif_pile(argv, argc, &data) == -1)
		return (write(2, "Error\n", 6), 1);
}
