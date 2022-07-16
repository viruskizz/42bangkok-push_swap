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
	int		fidx;
	int		bidx;
	int		ridx;
	t_list	*fptr;
	t_list	*bptr;

	if (g_tmp.n > 499)
		ridx = g_tmp.n / 11;
	else if (g_tmp.n > 49)
		ridx = g_tmp.n / 5;
	else
		ridx = 3;

	if (ft_lstsize(g_lst1) < 6)
		midx = 3;
	else if (ft_lstsize(g_lst1) <= ridx)
		midx = 3;
	else if (g_tmp.n > 499)
		midx = ft_lstsize(g_lst1) - ridx;
	else if (g_tmp.n > 49)
		midx = ft_lstsize(g_lst1) - ridx;
	else
		midx = ft_lstsize(g_lst1) / 2;
	// ft_printf("%d/%d\n", ridx, ft_lstsize(g_lst1));
	// ft_printf("[%d]: %d\n", midx, g_tmp.ar[midx]);
	if (midx >= ft_lstsize(g_lst1))
		return;
	mid = g_tmp.ar[midx];
	while (ft_lstsize(g_lst1) > midx)
	{
		fidx = 0;
		bidx = ft_lstsize(g_lst1) - 1;
		while (bidx != fidx)
		{
			fptr = lst_ptr(g_lst1, fidx);
			bptr = lst_ptr(g_lst1, bidx);
			if (cint(fptr) <= mid)
			{
				// lst_print();
				move_top(cint(fptr), g_lst1, MODE_A);
				push(MODE_B);
				break;
			}
			else if (cint(bptr) <= mid)
			{
				// lst_print();
				move_top(cint(bptr), g_lst1, MODE_A);
				push(MODE_B);
				break;
			}
			fidx++;
			bidx--;
		}
	}
	// lst_print();
	if (ft_lstsize(g_lst1) > 3)
		pre_sort();
}

// void	pre_sort(void)
// {
// 	int		mid;
// 	int		midx;
// 	t_list	*fptr;
// 	t_list	*bptr;

// 	fptr = g_lst1;
// 	if (ft_lstsize(g_lst1) > 6)
// 		midx = ft_lstsize(g_lst1) / 2;
// 	else
// 		midx = 3;
// 	mid = g_tmp.ar[midx];
// 	while (ft_lstsize(g_lst1) > midx)
// 	{
// 		fptr = g_lst1;
// 		while (fptr)
// 		{
// 			if (cint(fptr) <= mid)
// 			{
// 				move_top(cint(fptr), g_lst1, MODE_A);
// 				push(MODE_B);
// 			}
// 			fptr = fptr->next;
// 		}
// 	}
// 	if (ft_lstsize(g_lst1) > 3)
// 		pre_sort();
// }

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

static int	sim_top(int nb, t_list	*lst, int stack)
{
	int		size;
	int		lidx;
	int		times;

	lidx = lst_idx(lst, nb);
	if (lidx == size - 2)
		times = 1;
	else if (lidx < size / 2)
		times = lidx + 1;
	else
		times = size - lidx - 1;
	return (times);
}

// static void	move_range_top(int min, int max, t_list	*lst, int stack)
// {
// 	int		size;
// 	int		lidx;
// 	int		times;

// 	size = ft_lstsize(lst);
// 	lidx = lst_idx(lst, nb);
// 	if (lidx == size - 2)
// 		swap(stack);
// 	else if (lidx < size / 2)
// 	{
// 		times = lidx + 1;
// 		while (times-- > 0)
// 			reverse(stack);
// 	}
// 	else
// 	{
// 		times = size - lidx - 1;
// 		while (times-- > 0)
// 			rotate(stack);
// 	}
// }
