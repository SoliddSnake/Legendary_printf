/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nriker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 20:45:35 by nriker            #+#    #+#             */
/*   Updated: 2019/09/11 16:15:49 by nriker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	sized(char const *s, char c)
{
	size_t all;

	all = 0;
	while (*s)
	{
		while (*s == c)
			++s;
		if (*s)
		{
			all++;
			while (*s && *s != c)
				s++;
		}
	}
	return (all);
}

static char		*getword(char *word, char c)
{
	char *start;

	start = word;
	while (*word && *word != c)
		word++;
	*word = '\0';
	return (ft_strdup(start));
}

static char		**to_free(char **str, size_t i)
{
	while (i--)
		ft_strdel(&(str[i]));
	free(*str);
	str = NULL;
	return (NULL);
}

static char		**getline(char *s, char c, size_t all)
{
	size_t	i;
	char	**str;
	char	*str2;

	i = 0;
	if ((str = (char **)ft_memalloc(sizeof(char*) * (all + 1))))
	{
		while (i < all)
		{
			while (*s == c)
				++s;
			if (*s)
			{
				if (!(str2 = getword(s, c)))
				{
					return (to_free(str, i));
				}
				str[i++] = str2;
				s += (ft_strlen(str2) + 1);
			}
		}
		str[i] = NULL;
	}
	return (str);
}

char			**ft_strsplit(char const *s, char c)
{
	char **str;
	char *str2;

	if (!s || !(str2 = ft_strdup((char*)s)))
		return (NULL);
	str = getline(str2, c, sized(str2, c));
	free(str2);
	return (str);
}
