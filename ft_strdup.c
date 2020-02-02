/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nriker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 21:56:50 by nriker            #+#    #+#             */
/*   Updated: 2019/10/07 18:24:02 by nriker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strdup(const char *src)
{
	char	*str;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(src);
	str = malloc(sizeof(char) * len + 1);
	if (str)
	{
		while (i < len)
		{
			str[i] = src[i];
			++i;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
