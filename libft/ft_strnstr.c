/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nriker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 14:37:21 by nriker            #+#    #+#             */
/*   Updated: 2019/09/05 15:11:15 by nriker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (!to_find[j])
		return ((char*)str);
	while (str[i] && i < len)
	{
		j = 0;
		while ((i + j < len) && (str[i + j] == to_find[j]) && to_find[j] != 0)
			++j;
		if (!to_find[j])
			return ((char*)&str[i]);
		++i;
	}
	return (0);
}
