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
static void	opt_reverse(int stack);
static void	sim_reverse(int stack);

void	reverse(int stack, int is_print)
{
	if (stack == STACK_X || stack == STACK_Y || stack == STACK_Z)
		sim_reverse(stack);
	else
		opt_reverse(stack);
}

static void	opt_reverse(int stack)
{
	if (stack == STACK_A && g_lst1 && ft_lstsize(g_lst1) > 1)
	{
		reverse_lst(&g_lst1);
		ft_printf("rra\n");
	}
	else if (stack == STACK_B && g_lst2 && ft_lstsize(g_lst2) > 1)
	{
		reverse_lst(&g_lst2);
		ft_printf("rrb\n");
	}
	else if (g_lst1 && g_lst2
		&& ft_lstsize(g_lst1) > 2 && ft_lstsize(g_lst2) > 1)
	{
		reverse_lst(&g_lst1);
		reverse_lst(&g_lst2);
		ft_printf("rrr\n");
	}
}

static void	sim_reverse(int stack)
{
	if (stack == STACK_X && g_lstx && ft_lstsize(g_lstx) > 1)
	{
		reverse_lst(&g_lstx);
	}
	else if (stack == STACK_Y && g_lsty && ft_lstsize(g_lsty) > 1)
	{
		reverse_lst(&g_lsty);
	}
	else if (g_lstx && g_lsty
		&& ft_lstsize(g_lstx) > 2 && ft_lstsize(g_lsty) > 1)
	{
		reverse_lst(&g_lstx);
		reverse_lst(&g_lsty);
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
