/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsance <jsance@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 10:55:40 by nriker            #+#    #+#             */
/*   Updated: 2019/10/22 18:01:34 by nriker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*str_d_i(char *s, va_list args, t_flags *fl)
{
	if (fl->lsize >= 1)
	{
		if (fl->lsize >= 2)
			return (ft_itoa_base(fl->ll_param, 10, 0));
		return (ft_itoa_base((long)fl->ll_param, 10, 0));
	}
	if (fl->hsize >= 1)
	{
		if (fl->lsize >= 1)
			return (ft_itoa_base((long)fl->ll_param, 10, 0));
		if (fl->hsize >= 2)
			return (ft_itoa_base((char)fl->ll_param, 10, 0));
		return (ft_itoa_base((short)fl->ll_param, 10, 0));
	}
	return (0);
}

static char	*str_o_x_u(char *s, va_list args, t_flags *fl)
{
	int type;

	if (fl->type == 'o')
		type = 8;
	else if (fl->type == 'x')
		type = 16;
	else if (fl->type == 'u')
		type = 10;
	if (fl->lsize >= 1)
	{
		if (fl->lsize >= 2)
			return (ft_itoa_baseu(fl->ull_param, type, 0));
		return (ft_itoa_baseu(fl->ull_param, type, 0));
	}
	if (fl->hsize >= 1)
	{
		if (fl->hsize >= 2)
			return (ft_itoa_base((unsigned char)fl->ull_param, type, 0));
		return (ft_itoa_base((unsigned short)fl->ull_param, type, 0));
	}
	return (0);
}

static char	*str__xx(char *s, va_list args, t_flags *fl)
{
	if (fl->lsize >= 1)
	{
		if (fl->lsize >= 2)
			return (ft_itoa_baseu(fl->ull_param, 16, 1));
		return (ft_itoa_baseu(fl->ull_param, 16, 1));
	}
	if (fl->hsize >= 1)
	{
		if (fl->hsize >= 2)
			return (ft_itoa_base((unsigned char)fl->ull_param, 16, 1));
		return (ft_itoa_base((unsigned short)fl->ull_param, 16, 1));
	}
	return (0);
}

static char	*str_c(char *s, va_list args, t_flags *fl)
{
	char	*str;
	int		x;

	if (fl->lsize >= 1)
	{
		if (fl->hsize >= 2)
			return (flags_zero(args, fl));
		if (fl->type == 'c')
		{
			x = fl->ll_param;
			if (x >= 0 && x <= 255)
			{
				if (!(str = ft_strnew(1)))
					ft_error();
				*str = x;
				return (str);
			}
			fl->len_rev_s = -1;
			return (0);
		}
		return (flags_zero(args, fl));
	}
	if (fl->hsize >= 1)
		return (flags_zero(args, fl));
	return (0);
}

char		*flags_size(char *s, va_list args, t_flags *fl)
{
	char	*x;

	if (fl->type == 'U')
		return (ft_itoa_baseu(fl->ull_param, 10, 0));
	else if (fl->type == 'p')
	{
		x = ft_itoa_baseu(fl->ull_param, 16, 0);
		if (fl->len_rev_s == 1)
			return (ft_strjoinfreefree(ft_strdup("0x"), x));
		return (ft_itoa_baseu(fl->ull_param, 16, 0));
	}
	else if (fl->type == 'b')
		return (flags_zero(args, fl));
	else if (fl->type == 'd' || fl->type == 'i')
		return (str_d_i(s, args, fl));
	else if (fl->type == 'o' || fl->type == 'x'
			|| fl->type == 'u' || fl->type == 'p')
		return (str_o_x_u(s, args, fl));
	else if (fl->type == 'X')
		return (str__xx(s, args, fl));
	else if (fl->type == 'c' || fl->type == 's')
		return (str_c(s, args, fl));
	return (0);
}
