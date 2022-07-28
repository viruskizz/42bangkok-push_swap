
#include "push_swap.h"

/*
from top to bottom
*/
void	partition_ab(int midx)
{
	int		idx;
	t_list	*ptr;

	while (ft_lstsize(g_lst1) > midx)
	{
		idx = ft_lstsize(g_lst1) - 1;
		while (idx >= 0)
		{
			ptr = lst_ptr(g_lst1, idx);
			if (ptr && cint(ptr) <= g_tmp.ar[midx])
			{
				move_top(cint(ptr), g_lst1, STACK_A);
				push(STACK_B);
				break;
			}
			idx--;
		}
	}
}

int move_top_times(int nb, t_list *lst)
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

void	move_top(int nb, t_list	*lst, int stack)
{
	int times;

	times = move_top_times(nb, lst);
	if (times > 0)
	{
		while (times-- > 0)
			rotate(stack);
	}
	else
	{
		while (times++ < 0)
			reverse(stack);
	}
}
