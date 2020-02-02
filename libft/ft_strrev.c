/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nriker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 10:22:37 by nriker            #+#    #+#             */
/*   Updated: 2019/09/10 13:51:34 by nriker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *s)
{
	char	*str;
	char	*str2;
	char	t;

	if (!s)
		return (0);
	if (!*s)
		return (s);
	str = s;
	str2 = s;
	while (*(++str2))
		;
	while (str < (--str2))
	{
		t = *str;
		*(str++) = *str2;
		*(str2) = t;
	}
	return (s);
}
