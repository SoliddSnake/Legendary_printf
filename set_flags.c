/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nriker <nriker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 20:27:58 by nriker            #+#    #+#             */
/*   Updated: 2019/10/30 10:47:26 by nriker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_flags(t_flags *flags, char *copy)
{
	int		i;

	i = 0;
	while (copy[i] != flags->type && copy[i] != '\0')
	{
		if (copy[i] == '0')
			flags->found_zero = 1;
		if (copy[i] > '0' && copy[i] <= '9')
			break ;
		i++;
	}
	if (ft_strchr(copy, '#'))
		flags->found_octotorp = 1;
	if (ft_strchr(copy, ' '))
		flags->found_space = 1;
	if (ft_strchr(copy, '+'))
		flags->found_plus = 1;
	if (ft_strchr(copy, '-'))
		flags->found_minus = 1;
	if (ft_strchr(copy, 'L'))
		flags->found_lll = 1;
}
