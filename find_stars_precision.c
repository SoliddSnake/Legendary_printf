/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_stars_precision.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nriker <nriker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 21:13:46 by nriker            #+#    #+#             */
/*   Updated: 2019/10/29 21:15:27 by nriker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		find_stars_precision(t_flags *fl, va_list args, int *i)
{
	fl->found_dot = 1;
	fl->fprecision = va_arg(args, int);
	while (fl->right_s[*i] == '*')
		(*i)++;
	return (1);
}
