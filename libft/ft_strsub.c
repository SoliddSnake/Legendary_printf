/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nriker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 12:15:39 by nriker            #+#    #+#             */
/*   Updated: 2019/10/21 11:50:08 by nriker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*s1;
	size_t	max;

	max = -1;
	if (!s || len == max || !(s1 = (char*)ft_memalloc(len + 1)))
		return (NULL);
	s1 = ft_strncpy(s1, (char*)s + start, len);
	return (s1);
}
