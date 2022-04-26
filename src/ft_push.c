/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-p <dramos-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 18:05:44 by dramos-p          #+#    #+#             */
/*   Updated: 2022/04/04 17:08:50 by dramos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../push_swap.h>

int	ft_push_xony(t_listc **x, t_listc **y)
{
	t_listc	*top;

	if (!*x)
		return (0);
	top = *x;
	*x = top->next;
	if (*y)
		top->next = (*y);
	else
		top->next = NULL;
	*y = top;
	return (1);
}

void	ft_pb(t_stack **x)
{
	if (ft_push_xony(&((*x)->a), &((*x)->b)))
	{
		(*x)->size_b++;
		(*x)->size_a--;
		ft_putstr_fd("pb\n", 1);
	}		
}

void	ft_pa(t_stack **x)
{
	if (ft_push_xony(&((*x)->b), &((*x)->a)))
	{
		(*x)->size_a++;
		(*x)->size_b--;
		ft_putstr_fd("pa\n", 1);
	}
}
