/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nriker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 15:25:10 by nriker            #+#    #+#             */
/*   Updated: 2019/10/15 15:58:20 by nriker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinfree(char *s1, char *s2)
{
	char	*str;

	if (!s1 && !s2)
		return (0);
	if (!(str = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (0);
	if (!s1)
		return (ft_strcpy(str, s2));
	if (!s2)
		return (ft_strcpy(str, s1));
	ft_strcpy(str, s1);
	ft_strcat(str, s2);
	if (s1)
		free(&(s1[0]));
	return (str);
}
