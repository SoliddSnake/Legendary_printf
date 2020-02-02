/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nriker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 10:57:17 by nriker            #+#    #+#             */
/*   Updated: 2019/09/19 13:28:24 by nriker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *tp;

	if (alst && del && *alst)
	{
		tp = *alst;
		while (*alst)
		{
			tp = *alst;
			*alst = (*alst)->next;
			del(tp->content, tp->content_size);
			free(tp);
		}
		*alst = NULL;
	}
}
