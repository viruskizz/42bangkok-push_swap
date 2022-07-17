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
static void print_opt(char *str, int is_print);

void	reverse(int stack, int is_print)
{
	if (stack == STACK_A && g_lst1 && ft_lstsize(g_lst1) > 1)
	{
		reverse_lst(&g_lst1);
		print_opt("rra", is_print);

	}
	else if (stack == STACK_B && g_lst2 && ft_lstsize(g_lst2) > 1)
	{
		reverse_lst(&g_lst2);
		print_opt("rrb", is_print);

	}
	else if (g_lst1 && g_lst2
		&& ft_lstsize(g_lst1) > 2 && ft_lstsize(g_lst2) > 1)
	{
		reverse_lst(&g_lst1);
		reverse_lst(&g_lst2);
		print_opt("rrr", is_print);

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

static void print_opt(char *str, int is_print)
{
	if (is_print)
		ft_printf("%s\n", str);
}