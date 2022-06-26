#include "push_swap.h"

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
		g_sarr[idx] = cint(ptr);
		ptr = ptr->next;
	}
	return ;
}

int		get_sorted_idx(int nb)
{
	int		i;

	i = 0;
	while (i < g_sorted.size)
		ft_printf("%d, ", g_sarr[i++]);
}