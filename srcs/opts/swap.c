/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 22:07:35 by tsomsa            #+#    #+#             */
/*   Updated: 2022/06/25 22:07:36 by tsomsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_lst(t_list **lst);
static void swap_two(t_list **lst);

/**
 * @brief swap top and prev-top
 * 9 7 8 5 -> 9 7 5 8
 * @param mode MODE_A or MODE_B or MODE_S select stact to swap a or b or same
 */
void	swap(int mode)
{
	if (mode == MODE_A && g_lst1 && ft_lstsize(g_lst1) > 1)
	{
		if (ft_lstsize(g_lst1) == 2)
			swap_two(&g_lst1);
		else
			swap_lst(&g_lst1);
		ft_printf("sa\n");
	}
	else if (mode == MODE_B && g_lst2 && ft_lstsize(g_lst2) > 1)
	{
		if (ft_lstsize(g_lst2) == 2)
			swap_two(&g_lst2);
		else
			swap_lst(&g_lst2);
		ft_printf("sb\n");
	}
	else if (g_lst1 && g_lst2 && ft_lstsize(g_lst1) > 1 && ft_lstsize(g_lst2) > 1)
	{
		swap_lst(&g_lst1);
		swap_lst(&g_lst2);
		ft_printf("ss\n");
	}
}

static void	swap_lst(t_list **lst)
{
	t_list	*tmp;
	t_list	*lt;
	t_list	*ft;

	tmp = *lst;
	while (tmp->next->next->next)
		tmp = tmp->next;
	ft = tmp->next;
	lt = tmp->next->next;
	ft->next = NULL;
	ft->prev = lt;
	lt->next = ft;
	lt->prev = tmp;
	tmp->next = lt;
}

static void swap_two(t_list **lst)
{
	t_list	*lt;
	t_list	*ft;

	ft = *lst;
	lt = ft->next;
	*lst = ft->next;
	ft->next = NULL;
	ft->prev = lt;
	lt->next = ft;
	lt->prev = NULL;

}