/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nriker <nriker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 21:19:14 by nriker            #+#    #+#             */
/*   Updated: 2019/10/29 10:43:42 by nriker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		check_inf_null(t_flags *fl, t_union *un, t_float *sfl)
{
	if (un->parts.exponent == 32767
			&& un->parts.mantisa == 9223372036854775808.0)
	{
		if (un->parts.sign)
			fl->tmp = ft_strdup("-inf");
		else
			fl->tmp = ft_strdup("inf");
		sfl->inf_nan = 1;
		return (1);
	}
	else if (un->parts.exponent == 32767
			&& un->parts.mantisa != 9223372036854775808.0
			&& un->parts.mantisa)
	{
		fl->tmp = ft_strdup("nan");
		sfl->inf_nan = 1;
		return (1);
	}
	return (0);
}

static void		exp_minus(t_union *un, t_float *sfl)
{
	int		i;
	char	*copy;

	sfl->man = ft_strjoinfreefree(ft_strdup("0."), ft_strdup(""));
	if ((i = ft_strlen(sfl->del)) < 63 - sfl->exp)
	{
		while ((i++) < 63 - sfl->exp)
		{
			sfl->man = ft_strjoinfreefree(sfl->man, ft_strdup("0"));
		}
	}
	sfl->man = ft_strjoinfree(sfl->man, sfl->del);
}

static void		exp_plus(t_union *un, t_float *sfl)
{
	int		i;
	char	*copy;

	copy = 0;
	i = 63 - sfl->exp;
	sfl->man = ft_strnew(ft_strlen(sfl->del) - i);
	sfl->man = ft_memcpy(sfl->man, sfl->del, ft_strlen(sfl->del) - i);
	if (ft_strcmp(sfl->man, sfl->del))
	{
		sfl->man = ft_strjoinfreefree(sfl->man, ft_strdup("."));
		copy = ft_strjoinfree(copy, sfl->del + (ft_strlen(sfl->man) - 1));
		sfl->man = ft_strjoinfreefree(sfl->man, copy);
	}
}

static char		*create_double_str(t_flags *fl, t_union *un, t_float *sfl)
{
	int		i;

	sfl->exp = un->parts.exponent - 16383;
	sfl->del = ft_itoa_baseu(un->parts.mantisa, 10, 0);
	if ((i = ft_abs(63 - sfl->exp)) >= 16382)
	{
		i -= 16382;
		sfl->del = multiplyfree(sfl->del, g_fmin_16382);
		while (i--)
			sfl->del = multiplyfree(sfl->del, "5");
	}
	else if (63 - sfl->exp > 0)
		while (i--)
			sfl->del = multiplyfree(sfl->del, "5");
	else
		while (i--)
			sfl->del = multiplyfree(sfl->del, "2");
	if (sfl->exp < 0)
		exp_minus(un, sfl);
	else
		exp_plus(un, sfl);
	if (un->parts.sign)
		sfl->man = ft_strjoinfreefree(ft_strdup("-"), sfl->man);
	return (ft_strdup(sfl->man));
}

int				check_float(t_flags *fl, va_list args)
{
	t_union	*un;
	t_float	*sfl;

	create_union(&un);
	create_struct_float(&sfl);
	un->f = fl->ld_param;
	if (check_inf_null(fl, un, sfl))
		return (0);
	fl->tmp = create_double_str(fl, un, sfl);
	fl->tmp = float_round(fl->tmp, fl);
	fl->tmp = check_width(fl->right_s, fl->tmp, fl);
	free_struct_un_float(un, sfl);
	return (1);
}
