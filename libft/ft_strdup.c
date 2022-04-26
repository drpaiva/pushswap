/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-p <dramos-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 16:14:01 by dramos-p          #+#    #+#             */
/*   Updated: 2022/01/22 20:41:45 by dramos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*news1;
	int		len;
	int		sizes1;
	void	*res;

	len = ft_strlen(s1);
	sizes1 = sizeof(char) * len + 1;
	news1 = (char *)malloc(sizes1);
	if (!news1)
		return (0);
	ft_bzero(news1, sizes1);
	res = ft_memcpy(news1, s1, sizes1);
	free(news1);
	return ((char *)res);
}
