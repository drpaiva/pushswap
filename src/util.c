/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-p <dramos-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 20:19:06 by dramos-p          #+#    #+#             */
/*   Updated: 2022/04/04 17:28:23 by dramos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../push_swap.h>

int	ft_arr_search(int *arr, int arr_size, int data)
{
	int	i;

	i = 0;
	while (i < arr_size)
	{
		if (arr[i] == data)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_isordened_r(t_stack *x)
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
	x->a = tmp;
	return (res);
}

void	ajust_stack(t_stack	*x, int argc, char **argv)
{
	int	num;
	int	*stack_a;
	int	*tmp;

	stack_a = (int *)malloc(sizeof(int) * argc - 1);
	tmp = (int *)malloc(sizeof(int) * argc - 1);
	x->size_a = 0;
	while (argv[x->size_a + 1])
	{
		stack_a[x->size_a] = ft_check_int(argv[x->size_a + 1], x, stack_a, tmp);
		tmp[x->size_a] = stack_a[x->size_a];
		x->size_a++;
	}
	ft_quick_sort(stack_a, 0, argc - 2);
	x->size_a = 0;
	while (argv[x->size_a + 1])
	{
		num = ft_arr_search(stack_a, argc -1, tmp[x->size_a]) + 1;
		ft_lstintadd_back(&(x->a), ft_lstintnew(num));
		x->size_a++;
	}
	free(tmp);
	free(stack_a);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	ft_check_int(char *str, t_stack	*x, int *stack_a, int *tmp)
{
	long int	num;

	num = ft_atoi(str);
	if (num >= -2147483648 && num <= 2147483647)
		return (num);
	ft_lstintclear(&x->a, free);
	ft_lstintclear(&x->b, free);
	free(tmp);
	free(stack_a);
	free(x);
	msg_error();
	return (num);
}
