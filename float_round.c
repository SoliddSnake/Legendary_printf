/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_round.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nriker <nriker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 19:11:46 by jsance            #+#    #+#             */
/*   Updated: 2019/10/29 19:46:57 by nriker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*fill_zero(const char *str, t_flags *fl, size_t len)
{
	char	*fresh;
	char	*zero;
	size_t	i;
	size_t	diff;

	diff = (len - ft_strlen(ft_strchr(str, '.') + 1));
	i = fl->fprecision - len + diff;
	fresh = ft_strnew(fl->fprecision);
	zero = ft_strnew(i);
	while (i--)
		zero[i] = '0';
	return (ft_strjoin(str, (const char *)zero));
}

char	*without_fract(const char *str, t_flags *fl, size_t len)
{
	char	*zero;
	size_t	i;

	if (fl->fprecision == 0)
		return ((char*)str);
	i = fl->fprecision;
	zero = ft_strnew(i);
	while (i--)
		zero[i] = '0';
	zero = ft_strjoin(".", zero);
	return (ft_strjoin(str, (const char *)zero));
}

char	*float_round(const char *str, t_flags *fl)
{
	size_t	len;
	char	*new;

	fl->fprecision = fl->found_dot == 0 ? 6 : fl->fprecision;
	if (ft_strchr(str, '.') == NULL)
		new = without_fract(str, fl, len);
	else
	{
		len = ft_strlen(str);
		if (fl->fprecision > len)
			new = fill_zero(str, fl, len);
		else if (fl->fprecision < len)
			new = len_less(str, fl, len);
	}
	return (new);
}
