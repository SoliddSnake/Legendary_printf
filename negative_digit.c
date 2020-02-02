/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   negative_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsance <jsance@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 14:48:25 by jsance            #+#    #+#             */
/*   Updated: 2019/10/27 15:08:17 by jsance           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*negative_float(t_flags *flags, char *str, size_t len)
{
	char		*copy;
	size_t		i;

	i = 0;
	copy = ft_strnew(flags->nr_width);
	if (flags->found_zero)
		copy[i++] = '-';
	while (i < len)
		copy[i++] = (flags->found_zero == 1) ? '0' : ' ';
	if (flags->found_zero == 0)
		copy[i - 1] = '-';
	ft_strcpy(copy + i, str + 1);
	return (copy);
}

char	*negative_dig(t_flags *flags, char *str, size_t len)
{
	char		*copy;
	size_t		i;

	if (flags->type == 'f')
		copy = negative_float(flags, str, len);
	else
	{
		i = 0;
		copy = ft_strnew(flags->nr_width);
		if (flags->found_zero && flags->found_dot == 0)
			copy[i++] = '-';
		if (flags->found_dot == 0)
			while (i < len)
				copy[i++] = (flags->found_zero == 1) ? '0' : ' ';
		else
			while (i < len)
				copy[i++] = ' ';
		if (flags->found_zero == 0 || flags->found_dot)
			copy[i - 1] = '-';
		ft_strcpy(copy + i, str + 1);
	}
	return (copy);
}
