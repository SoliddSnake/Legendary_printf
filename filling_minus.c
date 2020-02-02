/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filling_minus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsance <jsance@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 14:00:14 by jsance            #+#    #+#             */
/*   Updated: 2019/10/27 15:06:36 by jsance           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*minus(t_flags *flags, char *str)
{
	char		*copy;
	size_t		i;
	int			flag;

	i = 0;
	flag = check_digit(str);
	copy = ft_strnew(flags->nr_width);
	if (flags->found_plus && *str != '-')
		copy[i++] = '+';
	if (flags->found_octotorp && flags->type == 'x' && flags->zero == 0 && flag)
		ft_strncpy(copy, "0x", i += 2);
	else if (flags->found_octotorp && flags->type == 'X' && flags->zero == 0
			&& flag)
		ft_strncpy(copy, "0X", i += 2);
	else if (flags->found_octotorp && flags->type == 'o' && str[0] != '0')
		ft_strncpy(copy, "0", i += 1);
	if (flags->found_space && flags->found_plus == 0
		&& flags->found_octotorp == 0 && *str != '-')
		copy[i++] = ' ';
	ft_strcpy(copy + i, str);
	i = ft_strlen(copy);
	while (i < flags->nr_width)
		copy[i++] = ' ';
	return (copy);
}

char	*minus_pointer(size_t len, t_flags *flags, char *str)
{
	char		*copy;
	size_t		i;

	i = 0;
	if (flags->nr_width - ft_strlen(str) == 1)
		copy = ft_strnew(flags->nr_width + 1);
	else
		copy = ft_strnew(flags->nr_width);
	if (flags->zero)
	{
		ft_strncpy(copy, "0x", i += 2);
		ft_strcpy(copy + i, str);
	}
	else
	{
		ft_strncpy(copy, "0x", i += 2);
		ft_strcpy(copy + i, str);
	}
	i = ft_strlen(copy);
	while (i < flags->nr_width)
		copy[i++] = ' ';
	return (copy);
}

char	*minus_float(t_flags *flags, char *str)
{
	char		*copy;
	size_t		i;

	i = 0;
	copy = ft_strnew(flags->nr_width);
	if (flags->found_plus && *str != '-')
		copy[i++] = '+';
	else if (flags->found_space && *str != '-')
		copy[i++] = ' ';
	if (flags->found_dot && flags->fprecision == 0 && flags->found_octotorp)
		ft_strcpy(copy + i, ft_strjoin(str, "."));
	else
		ft_strcpy(copy + i, str);
	i = ft_strlen(copy);
	while (i < flags->nr_width)
		copy[i++] = ' ';
	return (copy);
}

char	*filling(size_t len, t_flags *flags, char *str)
{
	char		*copy;

	if (flags->found_minus)
		if (flags->type == 'p')
			copy = minus_pointer(flags->nr_width - len, flags, str);
		else if (flags->type == 'f')
			copy = minus_float(flags, str);
		else
			copy = minus(flags, str);
	else
	{
		if (*str == '-')
			copy = negative_dig(flags, str, flags->nr_width - len + 1);
		else if (flags->type == 'f')
			copy = float_without_minus(flags->nr_width - len, flags, str);
		else if (flags->type == 'p')
			copy = pointer(flags->nr_width - len, flags, str);
		else if (flags->found_dot == 0)
			copy = without_dot(flags->nr_width - len, flags, str);
		else
			copy = with_dot(flags->nr_width - len, flags, str);
	}
	return (copy);
}
