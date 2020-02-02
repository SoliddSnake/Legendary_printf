/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nriker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 10:23:50 by nriker            #+#    #+#             */
/*   Updated: 2019/09/11 16:12:44 by nriker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	char	*str1;

	if (!s || !f)
		return (0);
	if (!(str = (char *)ft_memalloc((size_t)ft_strlen(s) + 1)))
		return (0);
	str1 = str;
	while (*s)
		*(str1++) = (*f)(*(s++));
	return (str);
}
