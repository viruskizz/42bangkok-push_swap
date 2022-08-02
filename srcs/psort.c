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

static void	partition_ab(int mid);
static void	bottom_sort(void);
static void	complete_sort(void);
static int	top_push_back(int nb);

void	partition_sort(void)
{
	int		len;

	len = ft_lstsize(g_lst1);
	if (len > 6)
		partition_ab(g_tmp.ar[len - g_tmp.range]);
	else if (len > 3)
		partition_ab(g_tmp.ar[3]);
	bottom_sort();
	complete_sort();
}

/*
partition range from a to b
*/
static void	partition_ab(int mid)
{
	int		p;
	int		idx;
	int		len;
	t_list	*ptr;

	p = g_tmp.range;
	while (ft_lstsize(g_lst1) > 3 && p-- > 0)
	{
		idx = ft_lstsize(g_lst1) - 1;
		while (idx >= 0)
		{
			ptr = lst_ptr(g_lst1, idx--);
			if (ptr && cint(ptr) <= mid)
			{
				move_top(cint(ptr), g_lst1, STACK_A, PRINT);
				push(STACK_B, PRINT);
				break ;
			}
		}
	}
	len = ft_lstsize(g_lst1);
	if (len - g_tmp.range > 3)
		partition_ab(g_tmp.ar[len - g_tmp.range]);
	else if (len > 3)
		partition_ab(g_tmp.ar[3]);
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
static void	bottom_sort(void)
{
	int		min;
	int		mid;
	int		max;

	if (is_sorted_lst())
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

/**
 * @brief find max and almost max in B
 * swap on A if push 2 times from B
 */
static void	complete_sort(void)
{
	int	nidx;
	int	nb;
	int	p;

	nidx = ft_lstsize(g_lst1);
	while (nidx < g_tmp.n)
	{
		nb = g_tmp.ar[nidx];
		p = top_push_back(nb);
		if (p == 2)
			swap(STACK_A, PRINT);
		nidx += p;
	}
}

static int	top_push_back(int nb)
{
	int		times;
	int		t;
	int		p;

	t = move_top_times(nb, g_lst2);
	times = ft_abs(t);
	p = 1;
	while (times-- > 0)
	{
		if (t > 0)
			rotate(STACK_B, PRINT);
		else
			reverse(STACK_B, PRINT);
		if (cint(ft_lstlast(g_lst2)) == nb - 1)
		{
			push(STACK_A, PRINT);
			if (p++ && t > 0)
				times--;
		}
	}
	push(STACK_A, PRINT);
	return (p);
}
