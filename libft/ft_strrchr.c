/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nriker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 10:20:43 by nriker            #+#    #+#             */
/*   Updated: 2019/09/11 12:16:50 by nriker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *str;

	str = 0;
	while (*s)
	{
		if (*s == (char)c)
			str = (char*)s;
		++s;
	}
	if (*s == (char)c)
		str = (char*)s;
	return (str);
}
