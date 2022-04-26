/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_lstdel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-p <dramos-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 18:05:44 by dramos-p          #+#    #+#             */
/*   Updated: 2022/02/20 15:39:19 by dramos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../push_swap.h>

void	ft_lstintclear(t_listc **lst, void (*del)(void*))
{
	t_listc	*nlst;
	t_listc	*next;

	nlst = *lst;
	while (nlst)
	{
		next = nlst->next;
		ft_lstintdelone(nlst, del);
		nlst = next;
	}
	*lst = NULL;
}

void	ft_lstintdelone(t_listc *lst, void (*del)(void*))
{
	if (lst != NULL || del != NULL)
	{
		del(lst);
	}
}
