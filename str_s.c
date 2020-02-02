/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsance <jsance@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 18:49:31 by nriker            #+#    #+#             */
/*   Updated: 2019/10/23 12:10:04 by nriker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*find_dot(char *s, char *line, t_flags *fl)
{
	int x;
	int i;

	i = 0;
	x = fl->fprecision;
	if (x < ft_strlen(s))
	{
		free(line);
		line = ft_strnew(x);
		while (x--)
			line[i++] = *(s++);
		return (line);
	}
	free(line);
	return (ft_strdup(s));
}

char			*str_s(char *getparam_s, char *str_rev, t_flags *fl)
{
	char	*copy;
	char	*line;

	if (!getparam_s)
	{
		copy = ft_strnew(6);
		ft_strcpy(copy, "(null)");
		line = ft_strcpy(ft_strnew(ft_strlen(str_rev)), str_rev);
		ft_strrev(line);
		if (fl->found_dot)
			return (find_dot(copy, line, fl));
		fl->tmp = copy;
		free(line);
		return (fl->tmp);
	}
	line = ft_strcpy(ft_strnew(fl->len_rev_s), str_rev);
	ft_strrev(line);
	if (fl->found_dot)
		return (find_dot(getparam_s, line, fl));
	free(line);
	return (ft_strdup(getparam_s));
}
