/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_lstadd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-p <dramos-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 18:05:44 by dramos-p          #+#    #+#             */
/*   Updated: 2022/04/04 17:58:29 by dramos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../push_swap.h>

t_listc	*ft_lstintnew(int num)
{
	t_listc	*elem;

	elem = (t_listc *)malloc(sizeof(t_listc));
	if (!elem)
		return (NULL);
	elem->num = num;
	elem->next = NULL;
	return (elem);
}

void	ft_lstintadd_back(t_listc **lst, t_listc *n)
{
	t_listc	*p;

	if (*lst != NULL)
	{
		p = ft_lstintlast(*lst);
		p->next = n;
	}
	else
		*lst = n;
}

t_listc	*ft_lstintlast(t_listc *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ft_lstintadd_front(t_listc **lst, t_listc *n)
{
	if (n == NULL)
		return ;
	if (*lst != NULL && n != NULL)
		n->next = *lst;
	*lst = n;
}
