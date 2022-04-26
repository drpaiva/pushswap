/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-p <dramos-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 20:50:51 by dramos-p          #+#    #+#             */
/*   Updated: 2022/04/04 17:58:11 by dramos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdio.h>

typedef struct s_listc
{
	size_t			num;
	struct s_listc	*next;
}	t_listc;

typedef struct s_sort
{
	int	size;
	int	max_num;
	int	max_bits;
	int	i;
	int	j;
}	t_sort;

typedef struct s_stack
{
	t_listc			*a;
	t_listc			*b;
	int				size_a;
	int				size_b;
}	t_stack;

t_listc	*ft_lstintnew(int num);
void	ft_lstintclear(t_listc **lst, void (*del)(void*));
void	ft_lstintdelone(t_listc *lst, void (*del)(void*));
void	ft_lstintadd_back(t_listc **lst, t_listc *n);
t_listc	*ft_lstintlast(t_listc *lst);
void	ft_lstintadd_front(t_listc **lst, t_listc *n);
int		ft_swap_s(t_listc **lst);
void	ft_quick_sort(int *v, int start, int end);
void	ft_sa(t_stack **lst);
void	ft_sb(t_stack **lst);
void	ft_sa_sb(t_stack *lst);
int		ft_push_xony(t_listc **x, t_listc **y);
void	ft_pb(t_stack **x);
void	ft_pa(t_stack **x);
int		ft_rotate_down(t_listc **x);
void	ft_ra(t_stack **x);
void	ft_rb(t_stack **x);
void	ft_rr(t_stack **x);
void	ft_rra(t_stack *x);
void	ft_rrb(t_stack *x);
int		ft_rotate_top(t_listc **x);
void	ajust_stack(t_stack	*x, int argc, char **argv);
int		ft_arr_search(int *arr, int arr_size, int data);
int		ft_isdigit_oper(int c);
int		ft_check_value(char *str);
void	ft_isduplicate(int argc, char **argv);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_check_int(char *str, t_stack	*x, int *stack_a, int *tmp);
void	msg_error(void);
void	ft_radix_sort(t_stack *x);
void	ft_isordened(t_stack *x);
int		small_sort(t_stack **x, int argc);
int		ft_isordened_r(t_stack *x);

#endif