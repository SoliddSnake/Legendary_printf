/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_less.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsance <jsance@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 18:57:19 by jsance            #+#    #+#             */
/*   Updated: 2019/10/29 19:02:29 by jsance           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		nine_round(char *copy, t_flags *fl, size_t len, size_t precision)
{
	size_t	i;
	int		flag;

	i = 1;
	flag = 0;
	while (copy[precision + 1 + i] != '\0')
	{
		if (copy[precision + 1 + i] >= '1'
			&& copy[precision + 1 + i] <= '9')
		{
			flag = 1;
			break ;
		}
		i++;
	}
	return (flag);
}

void	check_five(char *copy, t_flags *fl, size_t len, size_t precision)
{
	int		flag;

	if (copy[precision + 1] > '5')
		more_five(copy, fl, len, precision);
	else
	{
		flag = nine_round(copy, fl, len, precision);
		if (flag)
			copy[precision] += 1;
		else
		{
			if ((copy[precision] - '0') % 2 != 0)
				copy[precision] += 1;
		}
	}
}

char	*create_fresh(char *copy, t_flags *fl, size_t precision)
{
	char	*copy2;

	if (fl->found_dot && fl->fprecision == 0)
	{
		copy2 = ft_strsub(copy, 1, precision - 1);
		free(copy);
		return (copy2);
	}
	else
	{
		copy2 = ft_strsub(copy, 1, precision);
		free(copy);
		return (copy2);
	}
}

char	*len_less(const char *str, t_flags *fl, size_t len)
{
	char	*copy;
	char	*copy2;
	int		precision;

	precision = fl->fprecision + (len - (ft_strlen(ft_strchr(str, '.') + 1)));
	copy = ft_strjoinfreefree(ft_strdup("0"), (char*)str);
	if (copy[precision + 1] >= '5')
		check_five(copy, fl, len, precision);
	if (copy[0] != '0')
	{
		copy2 = ft_strsub(copy, 0, precision);
		free(copy);
		return (copy2);
	}
	else
		return (create_fresh(copy, fl, precision));
}
