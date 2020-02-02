/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nriker <nriker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 20:21:26 by nriker            #+#    #+#             */
/*   Updated: 2019/10/29 21:08:05 by nriker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	create_struct(t_flags **flags, char *s, va_list args)
{
	if (ft_strchr(s, 'j'))
		*ft_strchr(s, 'j') = 'l';
	if (ft_strchr(s, 'z'))
		*ft_strchr(s, 'z') = 'l';
	if (find_lh(flags, s) && !find_stars(*flags, args))
		find_width(flags, s, -1);
	set_type(*flags, s);
	set_flags(*flags, (*flags)->right_s);
}
