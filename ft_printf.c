/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nriker <nriker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 13:50:33 by nriker            #+#    #+#             */
/*   Updated: 2019/10/29 21:06:51 by nriker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	check(const char *s, va_list args, int *count, t_flags *fl)
{
	fill_struct(&s[1], &fl, args);
	flags(fl, args);
	if (fl->len_rev_s < 0 && fl->type != 0)
		return ;
	ft_putstr(fl->tmp);
	if (fl->type == 'c' && fl->nr_width && !fl->tmp)
		(*count) += fl->nr_width;
	else if (!((int)ft_strlen(fl->tmp)) && fl->type == 'c')
		(*count)++;
	else
		*count += (int)ft_strlen(fl->tmp);
}

static void	ft_printf_else(t_flags *fl, const char *s, int *i)
{
	if (s[*i] != '{')
	{
		ft_putchar(s[*i]);
		fl->count++;
	}
	else
	{
		if (colors((char*)&s[*i]))
		{
			while (s[++(*i)] != '}')
				;
		}
		else
		{
			ft_putchar(s[*i]);
			fl->count++;
		}
	}
}

int			ft_printf(const char *s, ...)
{
	int		i;
	va_list	args;
	t_flags	*struct_flags;

	i = -1;
	va_start(args, s);
	create_flags(&struct_flags);
	while (s[++i] != '\0')
		if (s[i] == '%')
		{
			check(s + i, args, &struct_flags->count, struct_flags);
			if (struct_flags->len_rev_s < 0)
				return (-1);
			i += struct_flags->len_rev_s;
			if (struct_flags->type == 'm' && !free_struct(struct_flags))
				break ;
			free_struct(struct_flags);
		}
		else
			ft_printf_else(struct_flags, s, &i);
	free(struct_flags);
	va_end(args);
	return (struct_flags->count);
}
