/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nriker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 21:52:03 by nriker            #+#    #+#             */
/*   Updated: 2019/09/19 14:05:42 by nriker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *tp;

	if ((tp = (t_list*)malloc(sizeof(t_list))))
	{
		if (!content)
		{
			tp->content = (void*)content;
			tp->content_size = 0;
		}
		else
		{
			if (!(tp->content = malloc(sizeof(void) * content_size)))
				return (NULL);
			ft_memcpy(tp->content, content, content_size);
			tp->content_size = content_size;
		}
		tp->next = NULL;
		return (tp);
	}
	return (NULL);
}
