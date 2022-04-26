/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-p <dramos-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 18:56:05 by dramos-p          #+#    #+#             */
/*   Updated: 2022/04/04 17:16:18 by dramos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../push_swap.h>

static void	end_pw(t_stack *x)
{
	ft_lstintclear(&x->a, free);
	ft_lstintclear(&x->b, free);
	free(x);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_stack	*x;

	if (argc < 3)
		return (0);
	ft_isduplicate(argc, argv);
	x = (t_stack *)malloc(sizeof(t_stack));
	x->a = NULL;
	x->b = NULL;
	x->size_a = 0;
	x->size_b = 0;
	ajust_stack(x, argc, argv);
	ft_isordened(x);
	if (small_sort(&x, argc))
		end_pw(x);
	ft_radix_sort(x);
	ft_lstintclear(&x->a, free);
	ft_lstintclear(&x->b, free);
	free(x);
	return (0);
}
