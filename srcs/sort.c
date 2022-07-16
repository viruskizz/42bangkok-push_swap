#include "push_swap.h"
void	move_top(int nb, int stack);
int		get_mid_lst(t_list *lst);
void	pre_sort();
void	bottom_sort();
void	complete_sort();

void	sort()
{
	if (ft_lstsize(g_lst1) > 3)
		pre_sort();
	bottom_sort();
	complete_sort();
}

void	complete_sort()
{
	int	nidx;
	int	lidx;

	nidx = ft_lstsize(g_lst1);
	while (nidx < g_sorted.size)
	{
		move_top(g_sorted.arr[nidx], MODE_B);
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
void	bottom_sort()
{
	int		min;
	int		mid;
	int		max;
	int		mid_lidx;

	if (is_sorted_lst(g_lst1))
		return ;
	else if (ft_lstsize(g_lst1) == 2)
		swap(MODE_A);
	else if (ft_lstsize(g_lst1) == 3)
	{
		max = g_sorted.arr[0];
		mid = g_sorted.arr[1];
		min = g_sorted.arr[2];
		if (lst_idx(g_lst1, max) == 2 && (lst_idx(g_lst1, mid) == 0 || lst_idx(g_lst1, mid) == 1))
			rotate(MODE_A);
		if (lst_idx(g_lst1, max) == 1 && (lst_idx(g_lst1, mid) == 0 || lst_idx(g_lst1, mid) == 2))
			reverse(MODE_A);
		if (lst_idx(g_lst1, max) == 0 && lst_idx(g_lst1, min) == 1)
			swap(MODE_A);
	}
}

void	pre_sort()
{
	int		mid;
	int		midx;
	t_list	*ptr;

	ptr = g_lst1;
	midx = ft_lstsize(g_lst1) / 2;
	mid = g_sorted.arr[midx];
	while (ft_lstsize(g_lst1) > midx)
	{
		ptr = g_lst1;
		while (ptr)
		{
			if (cint(ptr) <= mid)
			{
				move_top(cint(ptr), MODE_A);
				push(MODE_B);
			}
			ptr = ptr->next;
		}
	}
	if (ft_lstsize(g_lst1) > 3)
		pre_sort();
}

void	move_top(int nb, int stack)
{
	t_list	*lst;
	int		size;
	int		lidx;
	int		times;

	if (stack == MODE_A)
		lst = g_lst1;
	else if (stack == MODE_B)
		lst = g_lst2;
	else
		return ;
	size = ft_lstsize(lst);
	lidx = lst_idx(lst, nb);
	if (lidx == size - 2)
		swap(stack);
	else if (lidx < size / 2)
	{
		times = lidx + 1;
		while (times-- > 0)
			reverse(stack);
	} else {
		times = size - lidx - 1;
		while (times-- > 0)
			rotate(stack);	
	}
}

void	set_sort_arr()
{
	t_list	*ptr;
	t_list	*chk;
	int		idx;

	g_sorted.size = ft_lstsize(g_lst1);
	g_sorted.arr = malloc(sizeof(int) * g_sorted.size);
	ptr = g_lst1;
	while (ptr)
	{
		chk = g_lst1;
		idx = 0;
		while (chk)
		{
			if (cint(ptr) < cint(chk))
				idx++;
			chk = chk->next;
		}
		g_sorted.arr[idx] = cint(ptr);
		ptr = ptr->next;
	}
}

int		sorted_idx(int nb)
{
	int		i;

	i = 0;
	while (i < g_sorted.size)
	{
		if (g_sorted.arr[i] == nb)
			return (i);
		i++;
	}
	return (-1);
}
