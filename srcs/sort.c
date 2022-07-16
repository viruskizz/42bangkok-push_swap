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
		move_top(g_tmp.ar[nidx], g_lst2, MODE_B);
		push(MODE_A);
		nidx++;
	}
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
		swap(MODE_A);
	else if (ft_lstsize(g_lst1) == 3)
	{
		max = g_tmp.ar[0];
		mid = g_tmp.ar[1];
		min = g_tmp.ar[2];
		if (lst_idx(g_lst1, max) == 2
			&& (lst_idx(g_lst1, mid) == 0 || lst_idx(g_lst1, mid) == 1))
			rotate(MODE_A);
		if (lst_idx(g_lst1, max) == 1
			&& (lst_idx(g_lst1, mid) == 0 || lst_idx(g_lst1, mid) == 2))
			reverse(MODE_A);
		if (lst_idx(g_lst1, max) == 0 && lst_idx(g_lst1, min) == 1)
			swap(MODE_A);
	}
}

void	pre_sort(void)
{
	int		mid;
	int		midx;
	t_list	*ptr;

	ptr = g_lst1;
	midx = ft_lstsize(g_lst1) / 2;
	mid = g_tmp.ar[midx];
	while (ft_lstsize(g_lst1) > midx)
	{
		ptr = g_lst1;
		while (ptr)
		{
			if (cint(ptr) <= mid)
			{
				move_top(cint(ptr), g_lst1, MODE_A);
				push(MODE_B);
			}
			ptr = ptr->next;
		}
	}
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
	if (lidx == size - 2)
		swap(stack);
	else if (lidx < size / 2)
	{
		times = lidx + 1;
		while (times-- > 0)
			reverse(stack);
	}
	else
	{
		times = size - lidx - 1;
		while (times-- > 0)
			rotate(stack);
	}
}
