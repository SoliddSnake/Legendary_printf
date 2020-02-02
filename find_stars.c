/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_stars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nriker <nriker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 20:46:42 by nriker            #+#    #+#             */
/*   Updated: 2019/10/29 21:27:40 by nriker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	cycle_find(t_flags *fl, int j)
{
	while (fl->right_s[j])
	{
		if (fl->right_s[j] >= '1' && fl->right_s[j] <= '9')
		{
			if (j == 0)
			{
				fl->nr_width = ft_atoi(&fl->right_s[j]);
				return (1);
			}
			else
			{
				if (fl->right_s[j - 1] == '.')
					while (fl->right_s[++j] >= '1' && fl->right_s[j] <= '9')
						;
				else
				{
					fl->nr_width = ft_atoi(&fl->right_s[j]);
					return (1);
				}
			}
		}
		j++;
	}
	return (0);
}

static int	find_stars_width2(t_flags *fl, va_list args, int *i)
{
	fl->nr_width = va_arg(args, int);
	if (fl->nr_width < 0)
	{
		fl->nr_width *= -1;
		fl->found_minus = 1;
	}
	while (fl->right_s[*i] == '*')
		(*i)++;
	cycle_find(fl, *i);
	return (1);
}

static int	find_stars_width(t_flags *fl, va_list args, int *i)
{
	fl->nr_width = va_arg(args, int);
	if (fl->nr_width < 0)
	{
		fl->nr_width *= -1;
		fl->found_minus = 1;
	}
	while (fl->right_s[*i] == '*')
		(*i)++;
	cycle_find(fl, *i);
	return (1);
}

int			find_stars(t_flags *fl, va_list args)
{
	int i;
	int k;
	int k2;

	i = -1;
	k = 0;
	k2 = 0;
	while (fl->right_s[++i])
		if (fl->right_s[i] == '*')
		{
			if (i == 0)
				k = find_stars_width(fl, args, &i);
			else if (fl->right_s[i - 1] == '.' && !k2)
				k2 = find_stars_precision(fl, args, &i);
			else if (!k)
				k = find_stars_width2(fl, args, &i);
		}
	if (ft_strchr(fl->right_s, '.') && !k2 && (fl->found_dot = 1))
		fl->fprecision = ft_atoi(ft_strchr(fl->right_s, '.') + 1);
	return (k);
}
