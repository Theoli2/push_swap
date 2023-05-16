/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlivroze <tlivroze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 23:04:01 by tlivroze          #+#    #+#             */
/*   Updated: 2023/05/16 03:40:52 by tlivroze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	const size_t	len_src = ft_strlen(src);
	char *const		dest = (char *const)malloc((len_src + 1) * sizeof(char));

	if (dest != NULL)
		ft_strlcpy(dest, src, len_src + 1);
	free(src);
	return (dest);
}
