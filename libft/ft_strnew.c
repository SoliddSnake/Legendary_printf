/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nriker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 09:50:10 by nriker            #+#    #+#             */
/*   Updated: 2019/09/17 12:48:49 by nriker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	max;

	max = -1;
	if (size + 1 >= max || size >= max)
		return (NULL);
	if ((str = (char*)malloc(sizeof(char) * (size + 1))))
	{
		ft_bzero(str, size + 1);
		return (str);
	}
	return (NULL);
}
