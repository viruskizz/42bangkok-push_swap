/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomsa <tsomsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 18:06:51 by tsomsa            #+#    #+#             */
/*   Updated: 2022/07/28 18:06:52 by tsomsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_mid(t_list *lst, int len)
{
	t_list	*tmp;
	t_list	*ptr;
	t_list	*chk;
	int		idx;

	ptr = lst_ptr(lst, ft_lstsize(lst) - len);
	tmp = ptr;
	while (ptr)
	{
		chk = tmp;
		idx = 0;
		while (chk)
		{
			if (cint(ptr) > cint(chk))
				idx++;
			chk = chk->next;
		}
		if (idx == len / 2)
			return (cint(ptr));
		ptr = ptr->next;
	}
	return (cint(tmp));
}

int	is_sorted(t_list *lst, int len, int cmp)
{
	t_list	*tmp;
	t_list	*chk;
	t_list	*ptr;
	int		n;

	ptr = lst;
	n = ft_lstsize(lst) - len;
	while (n-- > 0)
		ptr = ptr->next;
	chk = ptr;
	while (chk->next)
	{
		tmp = ptr;
		while (tmp)
		{
			if (cint(chk) < cint(tmp) && cmp > 0)
				return (0);
			if (cint(chk) > cint(tmp) && cmp < 0)
				return (0);
			tmp = tmp->next;
		}
		chk = chk->next;
	}
	return (1);
}

int	move_top_times(int nb, t_list *lst)
{
	int	size;
	int	lidx;

	size = ft_lstsize(lst);
	lidx = lst_idx(lst, nb);
	if (size < 2 || lidx == size - 1)
		return (0);
	if (lidx < size / 2)
		return (lidx * -1 - 1);
	else
		return (size - lidx - 1);
}

void	move_top(int nb, t_list	*lst, int stack, int is_print)
{
	int	times;

	times = move_top_times(nb, lst);
	if (times > 0)
	{
		while (times-- > 0)
			rotate(stack, is_print);
	}
	else
	{
		while (times++ < 0)
			reverse(stack, is_print);
	}
}

void	run_opt(char *str, int is_print)
{
	if (!ft_strncmp(str, "rra", 3))
		reverse(STACK_A, is_print);
	else if (!ft_strncmp(str, "rrb", 3))
		reverse(STACK_B, is_print);
	else if (!ft_strncmp(str, "rrr", 3))
		reverse(STACK_S, is_print);
	else if (!ft_strncmp(str, "ra", 2))
		rotate(STACK_A, is_print);
	else if (!ft_strncmp(str, "rb", 2))
		rotate(STACK_B, is_print);
	else if (!ft_strncmp(str, "rr", 2))
		rotate(STACK_S, is_print);
	else if (!ft_strncmp(str, "sa", 2))
		swap(STACK_A, is_print);
	else if (!ft_strncmp(str, "sb", 2))
		swap(STACK_B, is_print);
	else if (!ft_strncmp(str, "ss", 2))
		swap(STACK_S, is_print);
	else if (!ft_strncmp(str, "pa", 2))
		push(STACK_A, is_print);
	else if (!ft_strncmp(str, "pb", 2))
		push(STACK_B, is_print);
}
