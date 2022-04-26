/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-p <dramos-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 03:13:42 by dramos-p          #+#    #+#             */
/*   Updated: 2021/06/03 19:36:25 by dramos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strchr_md(const char *s, char const *c, int p)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s);
	while (i < len)
	{
		if (s[i] == c[p])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		f;

	if (!s1 || set == 0)
		return (0);
	while (s1[0] != '\0' && ft_strchr(set, s1[0]))
		s1++;
	f = ft_strlen(s1);
	if (f <= 0)
	{
		res = ft_calloc(1, sizeof(char));
		if (!res)
			return (NULL);
		return (res);
	}
	f--;
	while (ft_strchr_md(set, s1, f) && f > 0)
		f--;
	res = ft_substr(s1, 0, (f + 1));
	if (!res)
		return (NULL);
	return (res);
}
