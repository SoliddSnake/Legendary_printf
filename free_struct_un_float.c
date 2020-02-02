/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct_un_float.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nriker <nriker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 19:49:01 by nriker            #+#    #+#             */
/*   Updated: 2019/10/29 19:51:16 by nriker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	free_struct_un_float(t_union *un, t_float *sfl)
{
	free(un);
	if (sfl->man)
		free(sfl->man);
	if (sfl->str_exp)
		free(sfl->str_exp);
	if (*(sfl->del))
		free(sfl->del);
	free(sfl);
}
