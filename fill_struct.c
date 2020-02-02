/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nriker <nriker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 21:00:57 by nriker            #+#    #+#             */
/*   Updated: 2019/10/29 21:02:33 by nriker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fill_struct(const char *str, t_flags **struct_flags, va_list args)
{
	(*struct_flags)->main_str = (char*)str;
	(*struct_flags)->rev_s = ft_strrev(ft_strsub(str, 0, find_end(str)));
	(*struct_flags)->len_rev_s = ft_strlen((*struct_flags)->rev_s);
	(*struct_flags)->right_s = ft_strsub(str, 0, find_end(str));
	create_struct(struct_flags, (*struct_flags)->rev_s, args);
	read_param(*struct_flags, args);
}
