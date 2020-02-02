/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nriker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 11:08:41 by nriker            #+#    #+#             */
/*   Updated: 2019/09/11 16:14:03 by nriker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	char			*str1;
	unsigned int	i;

	if (!s || !f)
		return (0);
	i = 0;
	if (!(str = (char*)ft_memalloc((size_t)(ft_strlen(s) + 1))))
		return (0);
	str1 = str;
	while (*s)
	{
		*(str1++) = (*f)(i, *(s++));
		++i;
	}
	return (str);
}
