/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nriker <nriker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 15:11:48 by nriker            #+#    #+#             */
/*   Updated: 2019/10/29 10:39:33 by nriker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		colors(char *s)
{
	if (!ft_strncmp(s, "{black}", 7))
		write(1, BLACK, 8);
	else if (!ft_strncmp(s, "{red}", 5))
		write(1, RED, 5);
	else if (!ft_strncmp(s, "{green}", 7))
		write(1, GREEN, 5);
	else if (!ft_strncmp(s, "{yellow}", 8))
		write(1, YELLOW, 8);
	else if (!ft_strncmp(s, "{blue}", 6))
		write(1, BLUE, 5);
	else if (!ft_strncmp(s, "{violet}", 8))
		write(1, VIOLET, 8);
	else if (!ft_strncmp(s, "{eoc}", 5))
		write(1, EOC, 7);
	if (!ft_strncmp(s, "{black}", 7) || !ft_strncmp(s, "{red}", 5)
		|| !ft_strncmp(s, "{green}", 7) || !ft_strncmp(s, "{yellow}", 8)
		|| !ft_strncmp(s, "{blue}", 6) || !ft_strncmp(s, "{violet}", 8)
		|| !ft_strncmp(s, "{eoc}", 5))
		return (1);
	return (0);
}
