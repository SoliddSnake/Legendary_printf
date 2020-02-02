/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nriker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 12:17:24 by nriker            #+#    #+#             */
/*   Updated: 2019/09/10 10:14:33 by nriker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "unistd.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*s1;
	unsigned char	*s2;
	size_t			i;

	i = 0;
	if (len != 0 && dst == NULL && src == NULL)
		return (NULL);
	s1 = (unsigned char*)dst;
	s2 = (unsigned char*)src;
	if (s2 < s1)
	{
		while (++i <= len)
			s1[len - i] = s2[len - i];
	}
	else
	{
		while (len-- > 0)
		{
			s1[i] = s2[i];
			++i;
		}
	}
	return (dst);
}
