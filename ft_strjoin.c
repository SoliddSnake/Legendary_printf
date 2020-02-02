/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nriker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 14:54:58 by nriker            #+#    #+#             */
/*   Updated: 2019/10/26 20:22:48 by nriker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;

	if (!s1 && !s2)
		return (0);
	if (!(str = (char*)ft_memalloc((size_t)(ft_strlen(s1)
						+ ft_strlen(s2) + 1))))
		return (0);
	if (!s1)
		return (ft_strcpy(str, s2));
	if (!s2)
		return (ft_strcpy(str, s1));
	ft_strcpy(str, s1);
	ft_strcat(str, s2);
	return (str);
}
