/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-p <dramos-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 18:05:44 by dramos-p          #+#    #+#             */
/*   Updated: 2022/04/04 17:09:56 by dramos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../push_swap.h>

int	ft_rotate_top(t_listc **x)
{
	t_listc	*tmp;
	t_listc	*aux;

	if (!*x || !(*x)->next)
		return (0);
	tmp = *x;
	while (tmp->next)
	{
		aux = tmp;
		tmp = tmp->next;
	}
	tmp->next = (*x);
	*x = tmp;
	aux->next = NULL;
	return (1);
}

void	ft_rra(t_stack *x)
{
	int	res;

	res = ft_rotate_top(&(x->a));
	if (res)
		ft_putstr_fd("rra\n", 1);
}

void	ft_rrb(t_stack *x)
{
	int	res;

	res = ft_rotate_top(&(x->b));
	if (res)
		ft_putstr_fd("rrb\n", 1);
}

void	ft_rrr(t_stack *x)
{
	int	res_a;
	int	res_b;

	res_a = ft_rotate_top(&(x->b));
	res_b = ft_rotate_top(&(x->a));
	if (res_a && res_b)
		ft_putstr_fd("rrr\n", 1);
}
