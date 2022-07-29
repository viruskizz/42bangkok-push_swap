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
static void	print_opt(int is_print, char *opt);

void	push(int stack, int is_print)
{
	if (stack == STACK_A && g_lst2 && ft_lstsize(g_lst2) > 0)
	{
		push_lst(&g_lst2, &g_lst1);
		print_opt(is_print, "pa\n");
	}
	else if (stack == STACK_B && g_lst1 && ft_lstsize(g_lst1) > 0)
	{
		push_lst(&g_lst1, &g_lst2);
		print_opt(is_print, "pb\n");
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

static void	print_opt(int is_print, char *opt)
{
	if (is_print)
		ft_putstr_fd(opt, STDOUT_FILENO);
}
