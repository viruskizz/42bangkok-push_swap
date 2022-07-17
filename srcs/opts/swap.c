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
static void	swap_two(t_list **lst);
static void	sim_swap(int stack);
static void	opt_swap(int stack);

/**
 * @brief swap top and prev-top
 * 9 7 8 5 -> 9 7 5 8
 * @param stack STACK_A or STACK_B or STACK_S select stact to swap a or b or same
 */
void	swap(int stack, int is_print)
{
	if (stack == STACK_X || stack == STACK_Y || stack == STACK_Z)
		sim_swap(stack);
	else
		opt_swap(stack);
}

static void	opt_swap(int stack)
{
	if (stack == STACK_A && g_lst1 && ft_lstsize(g_lst1) > 1)
	{
		swap_lst(&g_lst1);
		ft_printf("sa\n");
	}
	else if (stack == STACK_B && g_lst2 && ft_lstsize(g_lst2) > 1)
	{
		swap_lst(&g_lst2);
		ft_printf("sb\n");
	}
	else if (g_lst1 && g_lst2
		&& ft_lstsize(g_lst1) > 1 && ft_lstsize(g_lst2) > 1)
	{
		swap_lst(&g_lst1);
		swap_lst(&g_lst2);
		ft_printf("ss\n");
	}
}

static void	sim_swap(int stack)
{
	if (stack == STACK_X && g_lstx && ft_lstsize(g_lstx) > 1)
	{
		swap_lst(&g_lstx);
	}
	else if (stack == STACK_Y && g_lst2 && ft_lstsize(g_lsty) > 1)
	{
		swap_lst(&g_lsty);
	}
	else if (g_lstx && g_lsty
		&& ft_lstsize(g_lstx) > 1 && ft_lstsize(g_lsty) > 1)
	{
		swap_lst(&g_lstx);
		swap_lst(&g_lsty);
	}
}

static void	swap_lst(t_list **lst)
{
	t_list	*tmp;
	t_list	*lt;
	t_list	*ft;

	if (ft_lstsize(*lst) == 2)
		return (swap_two(lst));
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

static void	swap_two(t_list **lst)
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
