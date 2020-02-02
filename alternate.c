/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alternate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsance <jsance@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 13:51:45 by jsance            #+#    #+#             */
/*   Updated: 2019/10/27 15:26:56 by jsance           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*create_octal(t_flags *flags, char *str)
{
	char	*copy;

	if (*str != '0')
	{
		copy = ft_strnew(ft_strlen(str) + 1);
		ft_strncpy(copy, "0", 1);
		ft_strcpy(copy + 1, str);
	}
	else
	{
		copy = ft_strnew(ft_strlen(str));
		ft_strcpy(copy, str);
	}
	return (copy);
}

char	*create_small_hex(t_flags *flags, char *str)
{
	char	*copy;

	if (flags->zero && flags->type != 'p')
	{
		copy = ft_strnew(ft_strlen(str));
		ft_strcpy(copy, str);
	}
	else
	{
		if (check_digit(str) == 0 && flags->zero == 0)
		{
			copy = ft_strnew(ft_strlen(str));
			ft_strcpy(copy, str);
		}
		else if (flags->type == 'p' && flags->zero && flags->fprecision == 0
		&& flags->found_minus == 0)
		{
			copy = ft_strnew(2);
			ft_strncpy(copy, "0x", 2);
		}
		else
			copy = ft_strjoin("0x", str);
	}
	return (copy);
}

char	*create_big_hex(t_flags *flags, char *str)
{
	char	*copy;

	if (flags->zero && flags->type != 'p')
	{
		copy = ft_strnew(ft_strlen(str));
		ft_strcpy(copy, str);
	}
	else
	{
		if (check_digit(str) == 0 && flags->zero == 0)
		{
			copy = ft_strnew(ft_strlen(str));
			ft_strcpy(copy, str);
		}
		else if (flags->type == 'p' && flags->zero && flags->fprecision == 0)
		{
			copy = ft_strnew(2);
			ft_strncpy(copy, "0X", 2);
		}
		else
			copy = ft_strjoin("0X", str);
	}
	return (copy);
}

char	*create_float(t_flags *flags, char *str)
{
	char	*copy;
	size_t	i;

	i = 0;
	copy = ft_strnew(ft_strlen(str) + 1);
	if (flags->found_plus && *str != '-')
		copy[i++] = '+';
	else if (flags->found_space && *str != '-')
		copy[i++] = ' ';
	if (flags->found_dot && flags->fprecision == 0 && flags->found_octotorp)
		ft_strcpy(copy + i, ft_strjoin(str, "."));
	else
		ft_strcpy(copy + i, str);
	return (copy);
}

char	*alternate(t_flags *flags, char *str)
{
	char	*copy;

	copy = NULL;
	if (*str != '\0' || flags->type == 'o')
	{
		if (flags->type == 'x' || flags->type == 'p')
			copy = create_small_hex(flags, str);
		else if (flags->type == 'f')
			copy = create_float(flags, str);
		else if (flags->type == 'X')
			copy = create_big_hex(flags, str);
		else if (flags->type == 'o')
			copy = create_octal(flags, str);
	}
	return (copy);
}
