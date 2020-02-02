/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nriker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 20:13:32 by nriker            #+#    #+#             */
/*   Updated: 2019/09/21 19:13:41 by nriker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;
	size_t			i;

	i = -1;
	if (dst == src)
		return (dst);
	s1 = (unsigned char*)dst;
	s2 = (unsigned char*)src;
	while (++i < n)
		s1[i] = s2[i];
	return (dst);
}
