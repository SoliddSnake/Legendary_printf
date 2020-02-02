/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nriker <nriker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 13:49:59 by nriker            #+#    #+#             */
/*   Updated: 2019/10/28 20:55:52 by nriker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		check_alone(t_flags *fl, va_list args)
{
	if (fl->type == 'm')
	{
		check_fd(fl);
		return (1);
	}
	if (fl->type == 'f')
	{
		check_float(fl, args);
		return (1);
	}
	if (fl->len_rev_s == 1 || fl->type == 0)
	{
		if (!(fl->tmp = flags_zero(args, fl)))
			return (1);
		return (1);
	}
	return (0);
}

int				flags(t_flags *fl, va_list args)
{
	if (check_alone(fl, args))
		return (0);
	if (fl->type == '%')
		fl->tmp = ft_strdup("%");
	else if ((!fl->lsize && !fl->hsize && fl->type != 'p') || fl->type == 'r')
	{
		if (!(fl->tmp = flags_zero(args, fl)))
			return (0);
	}
	else if (!(fl->tmp = flags_size(fl->rev_s, args, fl)))
		return (-1);
	if (fl->found_dot && fl->type != '%' && fl->fprecision >= 0)
		if (!(fl->tmp = flags_precision(fl)))
			return (0);
	fl->tmp = check_width(fl->right_s, fl->tmp, fl);
	return (fl->len_rev_s);
}
