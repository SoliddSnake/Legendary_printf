/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nriker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 15:25:55 by nriker            #+#    #+#             */
/*   Updated: 2019/10/02 17:39:11 by nriker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static const char	*check(char const *s, int *i)
{
	while (*s == ' ' || *s == '\n' || *s == '\t')
	{
		++s;
		*i += 1;
	}
	return (s);
}

char				*ft_strtrim(char const *s)
{
	int		i;
	char	*str;
	char	*str2;
	size_t	size;

	i = 0;
	if (!s)
		return (0);
	s = check(s, &i);
	if (!ft_strlen((char*)s))
		return (ft_strdup(""));
	i = (int)ft_strlen((char*)s);
	while (s[i - 1] == ' ' || s[i - 1] == '\n'
			|| s[i - 1] == '\t')
		i--;
	size = (int)i;
	if (!(str = (char*)ft_memalloc(size + 1)))
		return (0);
	str2 = str;
	while (size-- > 0)
		*(str2++) = *(s++);
	return (str);
}
