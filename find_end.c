/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nriker <nriker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 20:58:13 by nriker            #+#    #+#             */
/*   Updated: 2019/10/29 21:07:04 by nriker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		find_end(const char *str)
{
	int i;

	i = 0;
	while (str[i] != 'd' && str[i] != 'i' && str[i] != 'u'
			&& str[i] != 'o' && str[i] != 's' && str[i] != 'c'
			&& str[i] != 'x' && str[i] != 'X' && str[i] != '%'
			&& str[i] != 'U' && str[i] != '\0' && str[i] != 'p'
			&& str[i] != 'r' && str[i] != 'b' && str[i] != 'f'
			&& str[i] != 'e' && str[i] != 'm'
			&& (str[i] == 'l' || str[i] == 'h' || str[i] == 'j'
			|| str[i] == 'z' || (str[i] >= '0' && str[i] <= '9')
				|| str[i] == '.' || str[i] == '-' || str[i] == '+'
				|| str[i] == '#' || str[i] == ' ' || str[i] == '*'
				|| str[i] == 'L'))
		i++;
	if (str[i] == 'd' || str[i] == 'i' || str[i] == 'u' || str[i] == 'o'
			|| str[i] == 's' || str[i] == 'c' || str[i] == 'x' || str[i] == 'X'
			|| str[i] == '%' || str[i] == 'U' || str[i] == 'p' || str[i] == 'r'
			|| str[i] == 'f' || str[i] == 'b' || str[i] == 'e' || str[i] == 'm')
		return (i + 1);
	return (i);
}
