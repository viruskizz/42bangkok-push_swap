/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qsorta.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomsa <tsomsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 17:21:38 by tsomsa            #+#    #+#             */
/*   Updated: 2022/07/28 17:21:39 by tsomsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort3a(int len);
static void	sort3a_opt(int top, int prev, int pprev, int len);
static void	bottom_sorta(void);

void	qsorta(int len)
{
	int	mid;
	int	n;
	int	p;

	if (is_sorted(g_lst1, len, 1))
		return ;
	if (len <= 3)
		sort3a(len);
	if (ft_lstsize(g_lst1) <= 3)
		return ;
	mid = find_mid(g_lst1, len);
	n = len;
	p = 0;
	while (n != len / 2 + len % 2)
	{
		if (cint(ft_lstlast(g_lst1)) < mid && n--)
			push(STACK_B, PRINT);
		else if (++p)
			rotate(STACK_A, PRINT);
	}
	while (len / 2 + len % 2 != ft_lstsize(g_lst1) && p-- > 0)
		reverse(STACK_A, PRINT);
	qsorta(len / 2 + len % 2);
	qsortb(len / 2);
}

static void	sort3a(int len)
{
	int		size;
	t_list	*top;
	t_list	*prev;
	t_list	*pprev;

	size = ft_lstsize(g_lst1);
	if (size <= 3)
		return (bottom_sorta());
	top = lst_ptr(g_lst1, size - 1);
	prev = lst_ptr(g_lst1, size - 2);
	pprev = lst_ptr(g_lst1, size - 3);
	if (len == 2 && cint(top) > cint(prev))
		swap(STACK_A, PRINT);
	else if (len == 3)
		sort3a_opt(cint(top), cint(prev), cint(pprev), len);
}

/**
 * @brief
 	3		1		3		2		1
	1		3		2		3		2
	2	sa	2	ra	x	sa	x	rra	3
	x		x		x		x		x
	x		x		1		1		x

	3		2		3		1		2		1
	2	sa	3	ra	1	sa	3	rra	1	sa	2
	1		1		x		x		3		3
	x		x		x		x		x		x
	x		x		2		2		x		x
 */
static void	sort3a_opt(int top, int prev, int pprev, int len)
{
	if (top > prev && top > pprev)
	{
		swap(STACK_A, PRINT);
		sort3a(len);
	}
	else if (prev > top && prev > pprev)
	{
		rotate(STACK_A, PRINT);
		swap(STACK_A, PRINT);
		reverse(STACK_A, PRINT);
		sort3a(len);
	}
	else if (pprev > prev && pprev > top && top > prev)
		swap(STACK_A, PRINT);
}

/**
 * @brief Sort only last 3 elements in list
 * @param lst
 */
/*
Operation description
Focus on Max and Min value only
	3		1
	1	ra	2
	2		3

	3		2		1
	2	ra	1	sa	2
	1		3		3

	2		1
	3	rra	2
	1		3

	1		2		1
	3	rra	1	sa	2
	2		3		3
	2		1
	1	sa	2
	3		3
*/
static void	bottom_sorta(void)
{
	int		min;
	int		mid;
	int		max;

	if (ft_lstsize(g_lst1) == 2 && g_tmp.ar[0] != cint(g_lst1))
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
