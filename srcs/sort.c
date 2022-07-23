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
static int	top_swap(void);
static int	move_top_times(int nb, t_list *lst);
static void	top_sort(void);

static int	top_push_back(int nb)
{
	t_list	*ptr;
	int		size;

	size = ft_lstsize(g_lst2);
	ptr = lst_ptr(g_lst2, size - 1);
	if (ptr && cint(ptr) == nb)
	{
		push(STACK_A, PRINT);
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
				rotate(STACK_B, PRINT);
				if (top_push_back(nb - 1))
					times--;
			}
		}
		else
		{
			while (times++ < 0)
			{
				reverse(STACK_B, PRINT);
				top_push_back(nb - 1);
			}
		}
		push(STACK_A, PRINT);
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
	{
		// lst_print();
		// ft_printf("swap: %d<->%d\n", cint(top), cint(prev));
		swap(STACK_A, PRINT);
		// lst_print();
	}
	else
		return (0);
	return (1);
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
static void	top_sort(void)
{
	int	size;
	t_list	*top;
	t_list	*prev;
	t_list	*pprev;

	size = ft_lstsize(g_lst1);
	if (size <= 3)
		bottom_sort();

	top = lst_ptr(g_lst1, size - 1);
	prev = lst_ptr(g_lst1, size - 2);
	pprev = lst_ptr(g_lst1, size - 3);
	// ft_printf("top sort: %d %d %d\n", cint(pprev), cint(prev), cint(top));
	// lst_print();
	if (cint(top) > cint(prev) && cint(top) > cint(pprev))
	{
		swap(STACK_A, PRINT);
		top_sort();
	}
	if (cint(prev) > cint(top) && cint(prev) > cint(pprev))
	{
		rotate(STACK_A, PRINT);
		swap(STACK_A, PRINT);
		reverse(STACK_A, PRINT);
		top_sort();
	}
	if (cint(pprev) > cint(prev) && cint(pprev) > cint(top) && cint(top) > cint(prev))
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

static int move_top_times(int nb, t_list *lst)
{
	int	times;
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

static void	move_top(int nb, t_list	*lst, int stack)
{
	int times;
	
	times = move_top_times(nb, lst);
	if (times > 0)
	{
		while (times-- > 0)
			rotate(stack, PRINT);
	}
	else
	{
		while (times++ < 0)
			reverse(stack, PRINT);
	}
}
