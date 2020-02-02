/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_nriker.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nriker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 10:50:48 by nriker            #+#    #+#             */
/*   Updated: 2019/10/15 19:36:07 by nriker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*get_tab(int content)
{
	char	*tab;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (!(tab = ft_strnew(16)))
		return (0);
	while (++i < 10)
		tab[i] = i + '0';
	if (content > 0)
	{
		while (i < 16)
			tab[i++] = 'A' + j++;
		return (tab);
	}
	else
	{
		while (i < 16)
			tab[i++] = 'a' + j++;
		return (tab);
	}
	return (0);
}

static int	get_size(int flag, long long tmp, int base)
{
	int size;

	size = 0;
	while (tmp /= base)
		size++;
	size += flag + 1;
	return (size);
}

char		*ft_itoa_base(long long value, int base, int content)
{
	char	*str;
	int		size;
	char	*tab;
	int		flag;

	flag = 0;
	if (base < 2 || base > 16)
		return (0);
	if (value < 0 && base == 10)
		flag = 1;
	tab = get_tab(content);
	size = get_size(flag, value, base);
	str = ft_strnew(size);
	if (flag == 1)
		str[0] = '-';
	while (size > flag)
	{
		str[size - 1] = tab[(int)ft_abs(value % base)];
		size--;
		value /= base;
	}
	free(tab);
	return (str);
}
