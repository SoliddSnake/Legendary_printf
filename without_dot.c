/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   without_dot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsance <jsance@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 14:16:00 by jsance            #+#    #+#             */
/*   Updated: 2019/10/27 15:29:12 by jsance           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*without_dot_oct_o(t_flags *flags, size_t len, char *str)
{
	char	*copy;
	size_t	i;

	i = 0;
	copy = ft_strnew(flags->nr_width);
	while (i < len)
		copy[i++] = (flags->found_zero == 1) ? '0' : ' ';
	if (flags->found_zero == 0 && flags->zero == 0 && *str != '0')
		ft_strncpy(copy + i - 1, "0", 1);
	ft_strcpy(copy + i, str);
	return (copy);
}

char	*without_dot_oct_x(t_flags *flags, size_t len, char *str)
{
	char	*copy;
	size_t	i;
	int		flag;

	i = 0;
	flag = check_digit(str);
	copy = (flags->nr_width - ft_strlen(str) == 1)
		? ft_strnew(flags->nr_width + 1) : ft_strnew(flags->nr_width);
	while (i < len)
		copy[i++] = (flags->found_zero == 1) ? '0' : ' ';
	if (flags->nr_width - ft_strlen(str) == 1 && flag)
		i++;
	if (flags->type == 'x' && flags->found_zero && flags->zero == 0 && flag)
		ft_strncpy(copy, "0x", 2);
	else if (flags->type == 'X' && flags->found_zero == 1
		&& flags->zero == 0 && flag)
		ft_strncpy(copy, "0X", 2);
	else if (flags->type == 'x' && flags->found_zero == 0
		&& flags->zero == 0 && flag)
		ft_strncpy(copy + i - 2, "0x", 2);
	else if (flags->type == 'X' && flags->found_zero == 0
		&& flags->zero == 0 && flag)
		ft_strncpy(copy + i - 2, "0X", 2);
	ft_strcpy(copy + i, str);
	return (copy);
}

char	*without_octotorp(t_flags *flags, size_t len, char *str)
{
	char	*copy;
	size_t	i;

	i = 0;
	copy = ft_strnew(flags->nr_width);
	while (i < len)
		copy[i++] = (flags->found_zero == 1) ? '0' : ' ';
	if (flags->found_plus && flags->found_zero == 0)
		copy[i - 1] = '+';
	else if (flags->found_plus && flags->found_zero)
		copy[0] = '+';
	else if (flags->found_space)
		ft_strncpy(copy, " ", 1);
	else if (flags->found_plus && flags->found_zero == 1)
		copy[0] = '+';
	ft_strcpy(copy + i, str);
	return (copy);
}

char	*without_dot(size_t len, t_flags *flags, char *str)
{
	char	*copy;

	if (flags->found_octotorp == 0)
		copy = without_octotorp(flags, len, str);
	else if (flags->found_octotorp)
	{
		if (flags->type == 'x' || flags->type == 'X')
			copy = without_dot_oct_x(flags, len, str);
		else if (flags->type == 'o')
			copy = without_dot_oct_o(flags, len, str);
	}
	return (copy);
}
