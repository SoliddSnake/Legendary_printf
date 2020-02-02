/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nriker <nriker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 20:50:25 by nriker            #+#    #+#             */
/*   Updated: 2019/10/30 10:47:15 by nriker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	read_param(t_flags *fl, va_list args)
{
	if (fl->type == 'd' || fl->type == 'i' || fl->type == 'c'
		|| fl->type == 'b' || fl->type == 'r' || fl->type == 'm')
		fl->ll_param = va_arg(args, long long);
	else if (fl->type == 'o' || fl->type == 'x' || fl->type == 'u'
			|| fl->type == 'X' || fl->type == 'U' || fl->type == 'p')
		fl->ull_param = va_arg(args, unsigned long long);
	else if (fl->type == 's')
	{
		fl->s_param = va_arg(args, char *);
		if (!fl->s_param)
			fl->zero = 1;
	}
	else if (fl->type == 'f' || fl->type == 'e' || fl->type == 'g')
	{
		if (fl->found_lll)
			fl->ld_param = va_arg(args, long double);
		else
			fl->ld_param = (long double)va_arg(args, double);
	}
	if (!fl->ll_param || !fl->ull_param || !fl->ld_param || !fl->ld_param)
		fl->zero = 1;
}
