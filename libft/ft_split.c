/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngpar <youngseo321@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 19:07:11 by youngpar          #+#    #+#             */
/*   Updated: 2021/05/10 19:18:38 by youngpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_issep(char c1, char c2)
{
	if (c1 == c2 || c1 == '\0')
		return (1);
	return (0);
}

static void		ft_catcat(char *dst, char *src, char c)
{
	size_t		idx;

	idx = 0;
	while (!ft_issep(src[idx], c) && src[idx])
	{
		dst[idx] = src[idx];
		idx++;
	}
	dst[idx] = 0;
}

static size_t	ft_cntsep(char *s, char c)
{
	size_t		cnt;
	size_t		idx;

	idx = 0;
	cnt = 0;
	while (s[idx])
	{
		if (!ft_issep(s[idx], c) && ft_issep(s[idx + 1], c))
			cnt++;
		idx++;
	}
	return (cnt);
}

static void		ft_sep(char **ret, char *s, char c)
{
	size_t		size;
	size_t		idx;
	size_t		curr;

	idx = 0;
	curr = 0;
	while (s[idx])
	{
		if (ft_issep(s[idx], c))
			idx++;
		else
		{
			size = 0;
			while (!ft_issep(s[idx + size], c) && s[idx + size])
				size++;
			if (!(ret[curr] = (char *)malloc(sizeof(char) * size + 1)))
			{
				while (curr >= 0)
					free(ret[curr--]);
				return ;
			}
			ft_catcat(ret[curr++], &s[idx], c);
			idx += size;
		}
	}
}

char			**ft_split(char const *s, char c)
{
	char		**split;
	size_t		size;

	if (!s)
		return ((void *)0);
	size = ft_cntsep((char *)s, c);
	if (!(split = (char **)malloc(sizeof(char *) * (size + 1))))
	{
		free(split);
		return (0);
	}
	ft_sep(split, (char *)s, c);
	if (!split)
		return ((void *)0);
	split[size] = 0;
	return (split);
}