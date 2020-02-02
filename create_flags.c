/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nriker <nriker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 14:51:22 by jsance            #+#    #+#             */
/*   Updated: 2019/10/30 10:46:08 by nriker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	create_union(t_union **un)
{
	if (!(*un = (t_union*)malloc(sizeof(t_union))))
		ft_error();
}

void	create_struct_float(t_float **sfl)
{
	if (!(*sfl = (t_float*)malloc(sizeof(t_float))))
		ft_error();
	(*sfl)->man = 0;
	(*sfl)->str_exp = 0;
	(*sfl)->exp = 0;
	(*sfl)->inf_nan = 0;
	(*sfl)->del = 0;
}

void	create_flags2(t_flags **flags)
{
	(*flags)->found_minus = 0;
	(*flags)->ull_param = -1;
	(*flags)->ll_param = -1;
	(*flags)->s_param = 0;
	(*flags)->ld_param = -1;
	(*flags)->d_param = -1;
	(*flags)->found_lll = 0;
	(*flags)->pzero = 0;
}

void	create_flags(t_flags **flags)
{
	if (!(*flags = (t_flags*)malloc(sizeof(t_flags))))
		return ;
	(*flags)->found_plus = 0;
	(*flags)->found_space = 0;
	(*flags)->found_zero = 0;
	(*flags)->found_octotorp = 0;
	(*flags)->found_dot = 0;
	(*flags)->found_point = 0;
	(*flags)->nr_width = 0;
	(*flags)->undefind = 0;
	(*flags)->fprecision = 0;
	(*flags)->lsize = 0;
	(*flags)->hsize = 0;
	(*flags)->zero = 0;
	(*flags)->len_rev_s = 0;
	(*flags)->count = 0;
	(*flags)->rev_s = 0;
	(*flags)->right_s = 0;
	(*flags)->main_str = 0;
	(*flags)->tmp = 0;
	(*flags)->type = 0;
	create_flags2(flags);
}
