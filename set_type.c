/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nriker <nriker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 20:25:28 by nriker            #+#    #+#             */
/*   Updated: 2019/10/29 21:08:57 by nriker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	set_type2(t_flags *flags, char *s)
{
	if (ft_strchr(s, 'b'))
		flags->type = *ft_strchr(s, 'b');
	else if (ft_strchr(s, 'r'))
		flags->type = *ft_strchr(s, 'r');
	else if (ft_strchr(s, 'f'))
		flags->type = *ft_strchr(s, 'f');
	else if (ft_strchr(s, 'e'))
		flags->type = *ft_strchr(s, 'e');
	else if (ft_strchr(s, 'm'))
		flags->type = *ft_strchr(s, 'm');
}

void		set_type(t_flags *flags, char *s)
{
	if (ft_strchr(s, 'd'))
		flags->type = *ft_strchr(s, 'd');
	else if (ft_strchr(s, 'i'))
		flags->type = *ft_strchr(s, 'i');
	else if (ft_strchr(s, 'u'))
		flags->type = *ft_strchr(s, 'u');
	else if (ft_strchr(s, 'o'))
		flags->type = *ft_strchr(s, 'o');
	else if (ft_strchr(s, 's'))
		flags->type = *ft_strchr(s, 's');
	else if (ft_strchr(s, 'c'))
		flags->type = *ft_strchr(s, 'c');
	else if (ft_strchr(s, 'x'))
		flags->type = *ft_strchr(s, 'x');
	else if (ft_strchr(s, 'X'))
		flags->type = *ft_strchr(s, 'X');
	else if (ft_strchr(s, '%'))
		flags->type = *ft_strchr(s, '%');
	else if (ft_strchr(s, 'U'))
		flags->type = *ft_strchr(s, 'U');
	else if (ft_strchr(s, 'p'))
		flags->type = *ft_strchr(s, 'p');
	set_type2(flags, s);
}
