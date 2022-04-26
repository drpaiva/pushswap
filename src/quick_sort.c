/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-p <dramos-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 00:24:09 by dramos-p          #+#    #+#             */
/*   Updated: 2022/04/04 17:17:16 by dramos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../push_swap.h>

static void	ft_swap(int *a, int *b)
{
	int	t;

	t = *a;
	*a = *b;
	*b = t;
}

static int	ft_partition(int *v, int start, int end)
{
	int	left;
	int	right;
	int	pivot;

	left = start;
	right = end;
	pivot = v[start];
	while (left < right)
	{
		while (left <= end && v[left] <= pivot)
			left++;
		while (right >= 0 && v[right] > pivot)
			right--;
		if (left < right)
			ft_swap(&v[right], &v[left]);
	}
	ft_swap(&v[start], &v[right]);
	return (right);
}

void	ft_quick_sort(int *v, int start, int end)
{
	int	pivot;

	if (end > start)
	{
		pivot = ft_partition(v, start, end);
		ft_quick_sort(v, start, pivot - 1);
		ft_quick_sort(v, pivot + 1, end);
	}
}
