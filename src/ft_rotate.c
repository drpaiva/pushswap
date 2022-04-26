/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-p <dramos-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 18:05:44 by dramos-p          #+#    #+#             */
/*   Updated: 2022/04/04 17:10:32 by dramos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../push_swap.h>

int	ft_rotate_down(t_listc **x)
{
	t_listc	*top;
	t_listc	*tmp;

	if (!*x || !(*x)->next)
		return (0);
	top = *x;
	*x = (*x)->next;
	tmp = *x;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = top;
	top->next = NULL;
	return (1);
}

void	ft_ra(t_stack **x)
{
	int	res;

	res = ft_rotate_down(&((*x)->a));
	if (res)
		ft_putstr_fd("ra\n", 1);
}

void	ft_rb(t_stack **x)
{
	int	res;

	res = ft_rotate_down(&((*x)->b));
	if (res)
		ft_putstr_fd("rb\n", 1);
}

void	ft_rr(t_stack **x)
{
	int	res_ra;
	int	res_rb;

	res_ra = ft_rotate_down(&((*x)->b));
	res_rb = ft_rotate_down(&((*x)->a));
	if (res_ra && res_rb)
		ft_putstr_fd("rr\n", 1);
}
