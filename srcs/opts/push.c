/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 22:07:08 by tsomsa            #+#    #+#             */
/*   Updated: 2022/06/25 22:07:10 by tsomsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_lst(t_list **src, t_list **dest);
static void	opt_push(int stack);
static void	sim_push(int stack);

/**
 * @brief push top of stack from source to destination
 * A: 7 5 9 2 3
 * B:
 * == push b
 * A: 7 5 9 2
 * B: 3
 * @param stack 
 */
void	push(int stack, int is_print)
{
	if (stack == STACK_X || stack == STACK_Y || stack == STACK_Z)
		sim_push(stack);
	else
		opt_push(stack);
}

static void	opt_push(int stack)
{
	if (stack == STACK_A && g_lst2 && ft_lstsize(g_lst2) > 0)
	{
		push_lst(&g_lst2, &g_lst1);
		ft_printf("pa\n");
	}
	else if (stack == STACK_B && g_lst1 && ft_lstsize(g_lst1) > 0)
	{
		push_lst(&g_lst1, &g_lst2);
		ft_printf("pb\n");
	}
}

static void	sim_push(int stack)
{
	if (stack == STACK_X && g_lsty && ft_lstsize(g_lsty) > 0)
	{
		push_lst(&g_lsty, &g_lstx);
	}
	else if (stack == STACK_Y && g_lstx && ft_lstsize(g_lstx) > 0)
	{
		push_lst(&g_lstx, &g_lsty);
	}
}

static void	push_lst(t_list **src, t_list **dest)
{
	t_list	*tmp;

	tmp = *src;
	while (tmp->next)
		tmp = tmp->next;
	if (tmp->prev)
		tmp->prev->next = NULL;
	else
		*src = NULL;
	ft_lstadd_back(dest, tmp);
}
