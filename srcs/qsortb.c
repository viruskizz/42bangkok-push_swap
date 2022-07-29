/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qsortb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomsa <tsomsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 17:48:28 by tsomsa            #+#    #+#             */
/*   Updated: 2022/07/28 17:48:30 by tsomsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort3b(int len);
static void	sort3b_opt(int top, int prev, int pprev, int len);
static void	bottom_sortb(void);

void	qsortb(int len)
{
	int	mid;
	int	n;
	int	p;

	if (len <= 3)
	{
		sort3b(len);
		while (len--)
			push(STACK_A, PRINT);
		return ;
	}
	mid = find_mid(g_lst2, len);
	n = len;
	p = 0;
	while (n != len / 2)
	{
		if (cint(ft_lstlast(g_lst2)) >= mid && n--)
			push(STACK_A, PRINT);
		else if (++p)
			rotate(STACK_B, PRINT);
	}
	while (len / 2 != ft_lstsize(g_lst2) && p-- > 0)
		reverse(STACK_B, PRINT);
	qsorta(len / 2 + len % 2);
	qsortb(len / 2);
}

static void	sort3b(int len)
{
	int		size;
	t_list	*top;
	t_list	*prev;
	t_list	*pprev;

	size = ft_lstsize(g_lst2);
	if (size <= 3)
		return (bottom_sortb());
	top = lst_ptr(g_lst2, size - 1);
	prev = lst_ptr(g_lst2, size - 2);
	pprev = lst_ptr(g_lst2, size - 3);
	if (len == 2 && cint(top) < cint(prev))
		swap(STACK_B, PRINT);
	else if (len == 3)
		sort3b_opt(cint(top), cint(prev), cint(pprev), len);
}

/**
 * @brief sort Stack B Top is greatest
 	1		3		1		2		3
	3		1		2		1		2
	2	sa	2	ra	x	sa	x	rra	1
	x		x		x		x		x
	x		x		3		3		x

	1		2		1		3		2		3
	2	sa	1	ra	3	sa	1	rra	3	sa	2
	3		3		x		x		1		1
	x		x		x		x		x		x
	x		x		2		2		x		x
 */
static void	sort3b_opt(int top, int prev, int pprev, int len)
{
	if (top < prev && top < pprev)
	{
		swap(STACK_B, PRINT);
		sort3b(len);
	}
	if (prev < top && prev < pprev)
	{
		rotate(STACK_B, PRINT);
		swap(STACK_B, PRINT);
		reverse(STACK_B, PRINT);
		sort3b(len);
	}
	if (pprev < prev && pprev < top && top < prev)
		swap(STACK_B, PRINT);
}

/**
 * @brief Sort only last 3 elements in Stack B
 * @param lst
 */
/*
Operation description
Focus on Max and Min value only

	1		3
	3	ra	2
	2		1

	1		2		3
	2	ra	3	sa	2
	3		1		1

	2		3
	1	rra	2
	3		1

	3		2		3
	1	rra	3	sa	2
	2		1		1

*/
static void	bottom_sortb(void)
{
	int		min;
	int		mid;
	int		max;
	int		size;

	size = ft_lstsize(g_lst2);
	if (is_sorted(g_lst2, size, 1))
		return ;
	else if (size == 2 && g_tmp.ar[0] == cint(g_lst2))
		swap(STACK_B, PRINT);
	else if (size == 3)
	{
		min = g_tmp.ar[g_tmp.n - 1];
		mid = g_tmp.ar[g_tmp.n - 2];
		max = g_tmp.ar[g_tmp.n - 3];
		if (lst_idx(g_lst2, min) == 2
			&& (lst_idx(g_lst2, max) == 0 || lst_idx(g_lst2, max) == 1))
			rotate(STACK_B, PRINT);
		if (lst_idx(g_lst2, min) == 1
			&& (lst_idx(g_lst2, mid) == 0 || lst_idx(g_lst2, mid) == 2))
			reverse(STACK_B, PRINT);
		if (lst_idx(g_lst2, min) == 0 && lst_idx(g_lst2, max) == 1)
			swap(STACK_B, PRINT);
	}
}
