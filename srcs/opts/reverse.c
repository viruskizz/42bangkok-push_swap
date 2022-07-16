/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 22:07:17 by tsomsa            #+#    #+#             */
/*   Updated: 2022/06/25 22:07:18 by tsomsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_lst(t_list **lst);

void	reverse(int mode)
{
	if (mode == MODE_A && g_lst1 && ft_lstsize(g_lst1) > 2)
	{
		reverse_lst(&g_lst1);
		ft_printf("rra\n");
	}
	else if (mode == MODE_B && g_lst2 && ft_lstsize(g_lst2) > 2)
	{
		reverse_lst(&g_lst2);
		ft_printf("rrb\n");
	}
	else if (g_lst1 && g_lst2
		&& ft_lstsize(g_lst1) > 2 && ft_lstsize(g_lst2) > 2)
	{
		reverse_lst(&g_lst1);
		reverse_lst(&g_lst2);
		ft_printf("rrr\n");
	}
}

static void	reverse_lst(t_list **lst)
{
	t_list	*tmp;
	t_list	*lt;
	t_list	*ft;

	tmp = *lst;
	ft = *lst;
	lt = ft_lstlast(tmp);
	ft->next->prev = NULL;
	*lst = ft->next;
	lt->next = ft;
	ft->prev = lt;
	ft->next = NULL;
}
