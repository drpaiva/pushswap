/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-p <dramos-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 00:24:09 by dramos-p          #+#    #+#             */
/*   Updated: 2022/04/04 17:22:16 by dramos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../push_swap.h>

static void	init_sort(t_sort **s, t_stack **x)
{
	(*s)->size = (*x)->size_a;
	(*s)->max_num = (*s)->size - 1;
	(*s)->i = 0;
	(*s)->max_bits = 0;
	while (((*s)->max_num >> (*s)->max_bits) != 0)
		++(*s)->max_bits;
}

void	ft_radix_sort(t_stack *x)
{
	t_sort	*s;
	int		num;

	s = (t_sort *)malloc(sizeof(t_sort));
	init_sort(&s, &x);
	while (s->i < s->max_bits)
	{
		s->j = 0;
		while (s->j < s->size)
		{
			num = x->a->num;
			if (((num >> s->i) & 1) == 1)
				ft_ra(&x);
			else
				ft_pb(&x);
			s->j++;
		}
		while (x->size_b)
			ft_pa(&x);
		s->i++;
	}
	free(s);
}
