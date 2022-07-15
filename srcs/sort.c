#include "push_swap.h"
void	move_top(t_list *lst, int nb, int stack);
int		get_mid_lst(t_list *lst);
void	presort();
void	lastsort();

void	sort()
{
	if (ft_lstsize > 3)
		presort();
	lastsort();
}

void	lastsort()
{
	int		min_idx;
	int		mid_idx;
	int		max_idx;

	max_idx = g_sorted.arr[0];
	mid_idx = g_sorted.arr[1];
	min_idx = g_sorted.arr[2];
	ft_printf("mid = %d\n", mid);
}

void	presort()
{
	int		mid;
	int		midx;
	t_list	*ptr;

	ptr = g_lst1;
	midx = ft_lstsize(g_lst1) / 2;
	mid = g_sorted.arr[midx];
	ft_printf("mid = %d\n", mid);
	while (ft_lstsize(g_lst1) > midx)
	{
		ptr = g_lst1;
		while (ptr)
		{
			if (cint(ptr) <= mid)
			{
				move_top(g_lst1, cint(ptr), MODE_A);
				push(MODE_B);
			}
			ptr = ptr->next;
		}
	}
	lst_print();
	if (ft_lstsize(g_lst1) > 3)
		presort();
}

void	move_top(t_list *lst, int nb, int stack)
{
	int		size;
	int		lidx;
	int		times;

	size = ft_lstsize(lst);
	lidx = get_lst_idx(lst, nb);
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

int		get_sorted_idx(int nb)
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
