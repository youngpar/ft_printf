/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngpar <youngseo321@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 00:24:22 by youngpar          #+#    #+#             */
/*   Updated: 2021/05/10 21:41:12 by youngpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ret;
	size_t	size;
	size_t	idx;

	size = ft_strlen(s1);
	idx = 0;
	if (!s1)
		return ((void *)0);
	if (!(ret = (char *)malloc(sizeof(char) * (size + 1))))
		return ((void *)0);
	while (s1[idx])
	{
		ret[idx] = s1[idx];
		idx++;
	}
	ret[idx] = '\0';
	return (ret);
}
