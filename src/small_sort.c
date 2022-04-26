/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-p <dramos-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 00:24:09 by dramos-p          #+#    #+#             */
/*   Updated: 2022/04/04 17:24:55 by dramos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../push_swap.h>

static void	ft_tree_arg(t_stack ***x)
{
	int	arr[3];

	arr[0] = (**x)->a->num;
	arr[1] = (**x)->a->next->num;
	arr[2] = (**x)->a->next->next->num;
	if ((**x)->size_a != 3)
		return ;
	if (arr[0] > arr[1])
	{
		if (arr[0] > arr[2] && arr[1] < arr[2])
			ft_rra((**x));
		else
			ft_sa(&(**x));
	}
	if (arr[0] > arr[2])
		ft_rra((**x));
	if (arr[0] < arr[2] && arr[1] > arr[2])
	{
		ft_sa(&(**x));
		ft_ra(&(**x));
	}
}

static void	ajust_schedule(t_stack ***x)
{
	if ((**x)->a->num == 5 || (**x)->a->num == 1)
		ft_pb(&(**x));
	else
		ft_ra(&(**x));
}

static void	ft_four_arg(t_stack ***x)
{
	int		i;

	i = 0;
	while (i < 5)
	{
		ajust_schedule(&(*x));
		i++;
	}
	if (ft_isordened_r((**x)))
		ft_tree_arg(&(*x));
	if ((**x)->b->num > (**x)->b->next->num)
		ft_pa(&(**x));
	else
	{
		ft_rb(&(**x));
		ft_pa(&(**x));
	}		
	if ((**x)->a->num > (**x)->a->next->num)
		ft_ra(&(**x));
	ft_pa(&(**x));
	if ((**x)->a->num > (**x)->a->next->num)
		ft_ra(&(**x));
}

void	ft_isordened(t_stack *x)
{
	t_listc	*tmp;
	int		res;

	tmp = x->a;
	res = 0;
	while (x->a->next != NULL && res == 0)
	{
		if (x->a->next->num < x->a->num)
			res = 1;
		x->a = x->a->next;
	}
	if (!res)
	{
		ft_lstintclear(&tmp, free);
		free(x);
		exit(0);
	}
	x->a = tmp;
}

int	small_sort(t_stack **x, int argc)
{
	if (argc == 3)
		ft_putstr_fd("sa\n", 1);
	if (argc == 4)
		ft_tree_arg(&x);
	if (argc == 6)
		ft_four_arg(&x);
	if (argc > 6)
		return (0);
	return (argc);
}
