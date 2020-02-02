/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nriker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 10:21:07 by nriker            #+#    #+#             */
/*   Updated: 2019/10/03 15:38:29 by nriker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		size(int n)
{
	int i;

	i = 0;
	if (!n)
		return (1);
	if (n < 0)
		n *= -1;
	while (n)
	{
		n /= 10;
		++i;
	}
	return (i);
}

static void		check(int *n, int *f)
{
	if (*n < 0)
	{
		*n *= -1;
		*f = 1;
	}
}

char			*ft_itoa(int n)
{
	char	*str;
	char	*str2;
	int		f;

	f = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (!(str = (char*)malloc(sizeof(char) *
					(size(n) + 1 + (n < 0 ? 1 : 0)))))
		return (0);
	check(&n, &f);
	str2 = str;
	if (!n)
		return (ft_strdup("0"));
	while (n)
	{
		*(str2++) = '0' + n % 10;
		n /= 10;
	}
	if (f == 1)
		*(str2++) = '-';
	*str2 = '\0';
	return (ft_strrev(str));
}
