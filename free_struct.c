/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nriker <nriker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 19:41:27 by nriker            #+#    #+#             */
/*   Updated: 2019/10/30 10:46:30 by nriker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	free_struct_str(t_flags *fl)
{
	fl->type = 0;
	fl->len_rev_s = 0;
	free(fl->rev_s);
	fl->rev_s = 0;
	free(fl->right_s);
	fl->right_s = 0;
	free(fl->tmp);
	fl->tmp = 0;
}

int			free_struct(t_flags *fl)
{
	fl->ll_param = -1;
	fl->ull_param = -1;
	fl->ld_param = -1;
	fl->d_param = -1;
	fl->zero = 0;
	fl->pzero = 0;
	fl->found_lll = 0;
	fl->found_minus = 0;
	fl->found_plus = 0;
	fl->found_space = 0;
	fl->found_zero = 0;
	fl->found_octotorp = 0;
	fl->found_dot = 0;
	fl->found_point = 0;
	fl->nr_width = 0;
	fl->undefind = 0;
	fl->fprecision = 0;
	fl->lsize = 0;
	fl->hsize = 0;
	free_struct_str(fl);
	return (0);
}
