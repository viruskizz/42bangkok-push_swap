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

static int	top_swap(void);

static int	top_push_back(int nb)
{
	t_list	*ptr;
	int		size;

	size = ft_lstsize(g_lst2);
	ptr = lst_ptr(g_lst2, size - 1);
	if (ptr && cint(ptr) == nb)
	{
		push(STACK_A);
		return (1);
	}
	return (0);
}

void	complete_sort(void)
{
	int	nidx;
	int	nb;
	int times;
	int	t;

	nidx = ft_lstsize(g_lst1);
	while (nidx < g_tmp.n)
	{
		nb = g_tmp.ar[nidx];
		times = move_top_times(nb, g_lst2);
		if (times > 0)
		{
			while (times-- > 0)
			{
				rotate(STACK_B);
				if (top_push_back(nb - 1))
					times--;
			}
		}
		else
		{
			while (times++ < 0)
			{
				reverse(STACK_B);
				top_push_back(nb - 1);
			}
		}
		push(STACK_A);
		if (top_swap())
			nidx++;
		nidx++;
	}
}

static int	top_swap(void)
{
	int		size;
	t_list	*top;
	t_list	*prev;

	size = ft_lstsize(g_lst1);
	if (size == 1 || is_sorted_lst(g_lst1))
		return (0);
	top = lst_ptr(g_lst1, size - 1);
	prev = lst_ptr(g_lst1, size - 2);
	if ((cint(top) > cint(prev) && cint(top) - cint(prev) == 1))
		swap(STACK_A);
	else
		return (0);
	return (1);
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
void	bottom_sort(void)
{
	int		min;
	int		mid;
	int		max;

	if (is_sorted_lst(g_lst1))
		return ;
	else if (ft_lstsize(g_lst1) == 2)
		swap(STACK_A);
	else if (ft_lstsize(g_lst1) == 3)
	{
		max = g_tmp.ar[0];
		mid = g_tmp.ar[1];
		min = g_tmp.ar[2];
		if (lst_idx(g_lst1, max) == 2
			&& (lst_idx(g_lst1, mid) == 0 || lst_idx(g_lst1, mid) == 1))
			rotate(STACK_A);
		if (lst_idx(g_lst1, max) == 1
			&& (lst_idx(g_lst1, mid) == 0 || lst_idx(g_lst1, mid) == 2))
			reverse(STACK_A);
		if (lst_idx(g_lst1, max) == 0 && lst_idx(g_lst1, min) == 1)
			swap(STACK_A);
	}
}

void	partition_sort(void)
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
	partition_ab(midx);
	if (ft_lstsize(g_lst1) > 3)
		partition_sort();
}
