/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_zero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nriker <nriker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 17:59:51 by nriker            #+#    #+#             */
/*   Updated: 2019/10/27 18:38:23 by nriker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*get_r(int c, t_flags *fl)
{
	char	*str;

	if (ft_isprint(c))
	{
		str = ft_strnew(1);
		*str = c;
	}
	else
	{
		str = ft_strjoinfreefree(ft_strdup("\\"), ft_itoa_base(c, 10, 0));
	}
	return (str);
}

static char	*get_c_b(int c, t_flags *fl)
{
	char	*s;

	if (fl->type == 'r')
		return (get_r(c, fl));
	if (fl->type == 'b')
		return (ft_itoa_base(c, 2, 0));
	if (!(s = ft_strnew(1)))
		ft_error();
	if (!c)
	{
		if (fl->len_rev_s == 1)
			ft_putchar('\0');
		*s = '\0';
	}
	else
		*s = c;
	return (s);
}

static char	*check_u(va_list args, t_flags *fl)
{
	long long	y;

	y = fl->ull_param;
	if (y < 0 || y > 2147483647)
		fl->undefind = 1;
	return (ft_itoa_base((unsigned int)y, 10, 0));
}

char		*flags_zero(va_list args, t_flags *fl)
{
	if (fl->type == 'd' || fl->type == 'i')
		return (ft_itoa_base((int)fl->ll_param, 10, 0));
	else if (fl->type == 'p')
		return (flags_size(fl->rev_s, args, fl));
	else if (fl->type == '%' && !fl->tmp)
		return (ft_strdup("%"));
	else if (fl->type == 'U')
		return (ft_itoa_baseu((unsigned long)fl->ull_param, 10, 0));
	else if (fl->type == 'u')
		return (check_u(args, fl));
	else if (fl->type == 'c' || fl->type == 'b' || fl->type == 'r')
		return (get_c_b((int)fl->ll_param, fl));
	else if (fl->type == 's')
		return (str_s(fl->s_param, fl->rev_s, fl));
	else if (fl->type == 'X')
		return (ft_itoa_base((unsigned int)fl->ull_param, 16, 1));
	else if (fl->type == 'x')
		return (ft_itoa_base((unsigned int)fl->ull_param, 16, 0));
	else if (fl->type == 'o')
		return (ft_itoa_base((unsigned int)fl->ull_param, 8, 0));
	return (0);
}
