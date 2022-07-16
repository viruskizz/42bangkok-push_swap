/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 22:07:25 by tsomsa            #+#    #+#             */
/*   Updated: 2022/06/25 22:07:26 by tsomsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_lst(t_list **lst);

void	rotate(int mode)
{
	if (mode == MODE_A && g_lst1 && ft_lstsize(g_lst1) > 2)
	{
		rotate_lst(&g_lst1);
		ft_printf("ra\n");
	}
	else if (mode == MODE_B && g_lst2 && ft_lstsize(g_lst2) > 2)
	{
		rotate_lst(&g_lst2);
		ft_printf("rb\n");
	}
	else if (g_lst1 && g_lst2
		&& ft_lstsize(g_lst1) > 2 && ft_lstsize(g_lst2) > 2)
	{
		rotate_lst(&g_lst1);
		rotate_lst(&g_lst2);
		ft_printf("rr\n");
	}
}

static void	rotate_lst(t_list **lst)
{
	t_list	*tmp;
	t_list	*lt;
	t_list	*ft;

	ft = *lst;
	tmp = *lst;
	lt = ft_lstlast(tmp);
	tmp = lt->prev;
	tmp->next = NULL;
	*lst = lt;
	(*lst)->prev = NULL;
	(*lst)->next = ft;
	ft->prev = *lst;
}
