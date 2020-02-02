/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsance <jsance@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 18:11:38 by nriker            #+#    #+#             */
/*   Updated: 2019/10/22 17:55:16 by nriker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_fun(char *tmp)
{
	if (!*tmp || !ft_strcmp(tmp, "(null)"))
	{
		if (!ft_strcmp(tmp, "(null)"))
			return (1);
		free(tmp);
		tmp = ft_strnew(1);
		*tmp = '\0';
		return (1);
	}
	return (0);
}

static char	*check_d(t_flags *fl)
{
	if ((fl->type == 'd' || fl->type == 'i' || fl->type == 'o'
				|| fl->type == 'x' || fl->type == 'X' || fl->type == 'u')
			&& *fl->tmp == '0')
		*fl->tmp = '\0';
	return (fl->tmp);
}

char		*flags_precision(t_flags *fl)
{
	char	*str;

	if (check_fun(fl->tmp))
		return (fl->tmp);
	if (fl->fprecision > 0 && ((fl->fprecision - (int)ft_strlen(fl->tmp) >= 0))
			&& fl->type != 'c' && fl->type != 's')
	{
		if (*fl->tmp == '-')
		{
			if (!(str = ft_strnew(fl->fprecision - ft_strlen(fl->tmp) + 1)))
				ft_error();
			str[0] = '-';
			*fl->tmp = '0';
			ft_memset(str + 1, '0', fl->fprecision - ft_strlen(fl->tmp));
		}
		else
		{
			if (!(str = ft_strnew(fl->fprecision - ft_strlen(fl->tmp))))
				ft_error();
			ft_memset(str, '0', fl->fprecision - ft_strlen(fl->tmp));
		}
		if (fl->type != 'f')
			return (ft_strjoinfreefree(str, fl->tmp));
	}
	return (check_d(fl));
}
