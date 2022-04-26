/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-p <dramos-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 18:05:44 by dramos-p          #+#    #+#             */
/*   Updated: 2022/04/04 17:10:55 by dramos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../push_swap.h>

int	ft_swap_s(t_listc **x)
{
	t_listc	*tmp;
	t_listc	*third;

	if (!*x || !(*x)->next)
		return (0);
	third = (*x)->next->next;
	tmp = *x;
	*x = (*x)->next;
	(*x)->next = tmp;
	tmp->next = third;
	return (1);
}

void	ft_sa(t_stack **x)
{
	int	status;

	status = ft_swap_s(&((*x)->a));
	if (status)
		ft_putstr_fd("sa\n", 1);
}

void	ft_sb(t_stack **x)
{
	int	status;

	status = ft_swap_s(&((*x)->b));
	if (status)
		ft_putstr_fd("sb\n", 1);
}

void	ft_sa_sb(t_stack *x)
{
	if (!x->a || !x->a->next || !x->b || !x->b->next)
		return ;
	ft_swap_s(&(x->a));
	ft_swap_s(&(x->b));
	ft_putstr_fd("ss\n", 1);
}
