/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filling_without_minus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsance <jsance@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 14:06:00 by jsance            #+#    #+#             */
/*   Updated: 2019/10/27 15:16:02 by jsance           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*float_without_minus(size_t len, t_flags *flags, char *str)
{
	char		*copy;
	size_t		i;

	i = 0;
	copy = ft_strnew(flags->nr_width);
	if (flags->found_space && flags->found_zero)
		copy[i++] = ' ';
	else if (flags->found_plus && flags->found_zero)
		copy[i++] = '+';
	while (i < len)
		copy[i++] = (flags->found_zero == 1) ? '0' : ' ';
	ft_strcpy(copy + i, str);
	if (flags->found_space && flags->found_zero == 0)
		copy[i - 1] = ' ';
	else if (flags->found_plus && flags->found_zero == 0)
		copy[i - 1] = '+';
	return (copy);
}

char	*pointer(size_t len, t_flags *flags, char *str)
{
	char		*copy;
	size_t		i;

	i = 0;
	if (flags->nr_width - ft_strlen(str) == 1)
		copy = ft_strnew(flags->nr_width + 1);
	else
		copy = ft_strnew(flags->nr_width);
	while (i < len)
		copy[i++] = (flags->found_zero == 1) ? '0' : ' ';
	if (flags->nr_width - ft_strlen(str) == 1)
		i++;
	if (flags->found_zero == 1)
		ft_strncpy(copy, "0x", 2);
	else if (flags->found_zero == 0)
		ft_strncpy(copy + i - 2, "0x", 2);
	ft_strcpy(copy + i, str);
	return (copy);
}

char	*with_dot(size_t len, t_flags *flags, char *str)
{
	char		*copy;
	size_t		i;
	int			flag;

	i = 0;
	flag = check_digit(str);
	copy = (flags->nr_width - ft_strlen(str) == 1)
			? ft_strnew(flags->nr_width + 1) : ft_strnew(flags->nr_width);
	while (i < len)
		copy[i++] = flags->fprecision < 0 ? '0' : ' ';
	if (flags->nr_width - ft_strlen(str) == 1 && flag
			&& flags->found_octotorp && flags->type != 'o')
		i++;
	if (flags->found_plus)
		copy[i - 1] = '+';
	if (flags->found_octotorp && flags->type == 'x' && flags->zero == 0 && flag)
		ft_strncpy(copy + i - 2, "0x", 2);
	else if (flags->found_octotorp && flags->type == 'X'
			&& flags->zero == 0 && flag)
		ft_strncpy(copy + i - 2, "0X", 2);
	else if (flags->found_octotorp && flags->type == 'o' && str[0] != '0')
		ft_strncpy(copy + i - 1, "0", 1);
	ft_strcpy(copy + i, str);
	return (copy);
}
