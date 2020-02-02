/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wigth.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsance <jsance@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 18:01:59 by jsance            #+#    #+#             */
/*   Updated: 2019/10/29 19:15:24 by jsance           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*set_plus(char *str, const char *src)
{
	char	*copy;
	char	*tmp;

	copy = ft_strnew(ft_strlen(str) + 1);
	copy[0] = '+';
	if ((tmp = ft_strchr((const char *)src, '.')) && *str == '0')
	{
		if (ft_atoi(tmp + 1) != 0)
			ft_strcpy(copy + 1, str);
	}
	else
		ft_strcpy(copy + 1, str);
	return (copy);
}

char	*set_space(char *str)
{
	char	*copy;

	copy = ft_strnew(ft_strlen(str) + 1);
	copy[0] = ' ';
	ft_strcpy(copy + 1, str);
	return (copy);
}

char	*set_zero(t_flags *flags)
{
	char	*copy;

	if (flags->found_space)
	{
		copy = ft_strnew(2);
		ft_strcpy(copy, " 0");
	}
	else
	{
		copy = ft_strnew(1);
		ft_strcpy(copy, "0");
	}
	return (copy);
}

void	print_char(size_t width, t_flags *flags)
{
	size_t	i;

	i = 1;
	if (flags->found_minus)
	{
		ft_putchar('\0');
		while (i++ < width)
			ft_putchar(' ');
	}
	else
	{
		while (i++ < width)
			ft_putchar(' ');
		ft_putchar('\0');
	}
}

char	*check_width(const char *src, char *str, t_flags *fl)
{
	char		*copy;
	size_t		len_str;

	len_str = ft_strlen(str);
	copy = NULL;
	if (fl->type == 'c' && !(*str))
		print_char(fl->nr_width, fl);
	else if (fl->nr_width > len_str)
		copy = filling(len_str, fl, str);
	else if (fl->nr_width <= len_str && fl->found_plus == 1
		&& fl->found_octotorp == 0 && *str != '-' && fl->undefind == 0
		&& *str != '%' && fl->type != 'p')
		copy = set_plus(str, src);
	else if (*str == '0' && len_str == 1 && !fl->found_dot && fl->type != 'p')
		copy = set_zero(fl);
	else if ((fl->nr_width <= len_str && fl->found_octotorp == 1)
				|| fl->type == 'p')
		copy = alternate(fl, str);
	else if (fl->found_space && fl->nr_width <= len_str && *str != '-'
				&& fl->undefind == 0 && *str != '%')
		copy = set_space(str);
	else
		return (str);
	free(str);
	return (copy);
}
