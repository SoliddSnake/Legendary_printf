/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nriker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 12:37:41 by nriker            #+#    #+#             */
/*   Updated: 2019/09/11 16:15:32 by nriker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	size_t j;
	size_t i;

	i = 0;
	j = 0;
	if (!to_find[j])
		return ((char*)str);
	while (str[i])
	{
		j = 0;
		while ((str[i + j] == to_find[j]) && to_find[j] != 0)
			++j;
		if (!to_find[j])
			return ((char*)&str[i]);
		++i;
	}
	return (0);
}
