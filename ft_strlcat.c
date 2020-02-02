/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nriker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 18:56:31 by nriker            #+#    #+#             */
/*   Updated: 2019/10/20 19:59:08 by nriker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t i;
	size_t j;
	size_t len;
	size_t lendest;

	i = 0;
	j = 0;
	lendest = ft_strlen(dest);
	len = ft_strlen(src);
	if (size <= lendest)
		return (ft_strlen(src) + size);
	while (dest[i] && i < size - 1)
		++i;
	while (j < len && (i + j < size - 1))
	{
		dest[i + j] = src[j];
		++j;
	}
	dest[i + j] = '\0';
	return (ft_strlen(src) + lendest);
}
