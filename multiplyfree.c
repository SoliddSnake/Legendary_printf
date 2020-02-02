/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiplyfree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nriker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 16:02:02 by nriker            #+#    #+#             */
/*   Updated: 2019/10/22 17:28:46 by nriker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	free_s(t_multiply *m)
{
	if (*(m->res))
		free(m->res);
	free(m);
}

static char	*finaly(t_multiply *m)
{
	char	*r;

	if (m->carry > 0)
	{
		r = ft_strrev(ft_strsub(m->res, 0, m->i_s1 + m->i_s2));
		free_s(m);
		return (r);
	}
	else
	{
		r = ft_strrev(ft_strsub(m->res, 0, m->i_s1 + m->i_s2 - 1));
		free_s(m);
		return (r);
	}
}

static void	cre(t_multiply **m)
{
	if (!(*m = (t_multiply*)malloc(sizeof(t_multiply))))
		ft_error();
}

static void	middle(t_multiply *m, const char *s1, const char *s2)
{
	while (m->i >= 0)
	{
		m->num1 = s1[m->i] - '0';
		m->carry = 0;
		m->j = ft_strlen(s2) - 1;
		m->i_s2 = 0;
		while (m->j >= 0)
		{
			m->num2 = s2[m->j] - '0';
			m->sum = m->num1 * m->num2
				+ m->res[m->i_s1 + m->i_s2] - '0' + m->carry;
			m->carry = m->sum / 10;
			m->res[m->i_s1 + m->i_s2] = m->sum % 10 + '0';
			(m->i_s2)++;
			(m->j)--;
		}
		if (m->carry > 0)
			m->res[m->i_s1 + m->i_s2] += m->carry;
		(m->i_s1)++;
		(m->i)--;
	}
}

char		*multiplyfree(const char *s1, const char *s2)
{
	t_multiply	*m;

	cre(&m);
	m->res = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	m->i = ft_strlen(s1) + ft_strlen(s2);
	while (--(m->i) >= 0)
		m->res[m->i] = '0';
	m->i = ft_strlen(s1) - 1;
	m->i_s1 = 0;
	middle(m, s1, s2);
	if (*s1)
		free((char*)s1);
	return (finaly(m));
}
