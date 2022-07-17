/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araiva <tsomsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 01:11:14 by araiva            #+#    #+#             */
/*   Updated: 2022/07/17 01:11:15 by araiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	move_top(int nb, t_list	*lst, int stack);

void	complete_sort(void)
{
	int	nidx;

	nidx = ft_lstsize(g_lst1);
	while (nidx < g_tmp.n)
	{
		// ft_printf("move: %d\n", g_tmp.ar[nidx]);
		move_top(g_tmp.ar[nidx], g_lst2, STACK_B);
		push(STACK_A, PRINT);
		nidx++;
	}
}

void	bottom_sort(void)
{
	int		min;
	int		mid;
	int		max;

	if (is_sorted_lst(g_lst1))
		return ;
	else if (ft_lstsize(g_lst1) == 2)
		swap(STACK_A, PRINT);
	else if (ft_lstsize(g_lst1) == 3)
	{
		max = g_tmp.ar[0];
		mid = g_tmp.ar[1];
		min = g_tmp.ar[2];
		if (lst_idx(g_lst1, max) == 2
			&& (lst_idx(g_lst1, mid) == 0 || lst_idx(g_lst1, mid) == 1))
			rotate(STACK_A, PRINT);
		if (lst_idx(g_lst1, max) == 1
			&& (lst_idx(g_lst1, mid) == 0 || lst_idx(g_lst1, mid) == 2))
			reverse(STACK_A, PRINT);
		if (lst_idx(g_lst1, max) == 0 && lst_idx(g_lst1, min) == 1)
			swap(STACK_A, PRINT);
	}
}

void	pre_sort(void)
{
	int		mid;
	int		midx;
	int		ridx;

	if (is_sorted_lst(g_lst1))
		return ;
	if (g_tmp.n > 499)
		ridx = g_tmp.n / 11;
	else if (g_tmp.n > 49)
		ridx = g_tmp.n / 5;
	else
		ridx = g_tmp.n / 2;
	if (ft_lstsize(g_lst1) > ridx)
		midx = ft_lstsize(g_lst1) - ridx;
	else
		midx = 3;
	short_move(midx, &g_lst1, STACK_A, STACK_B);
	// lst_print();
	if (ft_lstsize(g_lst1) > 3)
		pre_sort();
}

static void	move_top(int nb, t_list	*lst, int stack)
{
	int		size;
	int		lidx;
	int		times;

	size = ft_lstsize(lst);
	lidx = lst_idx(lst, nb);
	if (lidx == size - 1)
		return ;
	if (lidx < size / 2)
	{
		times = lidx + 1;
		while (times-- > 0)
			reverse(stack, PRINT);
	}
	else
	{
		times = size - lidx - 1;
		while (times-- > 0)
			rotate(stack, PRINT);
	}
}
