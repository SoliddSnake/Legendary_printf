/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nriker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 11:52:52 by nriker            #+#    #+#             */
/*   Updated: 2019/09/12 09:48:05 by nriker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *tp;
	t_list *new;

	if (lst && f)
	{
		tp = f(lst);
		new = tp;
		while (lst->next)
		{
			lst = lst->next;
			if (!(tp->next = f(lst)))
			{
				free(tp->next);
				return (NULL);
			}
			tp = tp->next;
		}
		return (new);
	}
	return (NULL);
}
