
#include "push_swap.h"

static int	move_top(int nb, t_list	*lst, int stack);

int	short_move(int midx, t_list **lst, int stack1, int stack2)
{
	int	times;
	int fidx;
	int	bidx;
	t_list	*tmp;
	t_list	*fptr;
	t_list	*bptr;

	// ft_printf("%d/%d\n", midx, ft_lstsize(*lst));
	// ft_printf("[%d]: %d\n", midx, g_tmp.ar[midx]);
	times = 0;
	while (ft_lstsize(*lst) > midx)
	{
		tmp = *lst;
		bidx = ft_lstsize(tmp) - 1;
		fidx = 0;
		while (bidx != fidx)
		{
			fptr = lst_ptr(tmp, fidx);
			bptr = lst_ptr(tmp, bidx);
			if (bptr && cint(bptr) <= g_tmp.ar[midx])
			{
				times += move_top(cint(bptr), tmp, stack1);
				push(stack2, PRINT);
				times++;
				break;
			}
			else if (fptr && cint(fptr) <= g_tmp.ar[midx])
			{
				times += move_top(cint(fptr), tmp, stack1);
				push(stack2, PRINT);
				times++;
				break;
			}
			fidx++;
			bidx--;
		}
		// lst_print();
	}
	// ft_printf("times = %d\n", times);
	return (times);
}

/*
from top to bottom
*/
int	rotate_move(int midx, t_list **lst, int stack)
{
	int fidx;
	int	bidx;
	t_list	*fptr;
	t_list	*bptr;

	// ft_printf("%d/%d\n", midx, ft_lstsize(*lst));
	// ft_printf("[%d]: %d\n", midx, g_tmp.ar[midx]);
	while (ft_lstsize(g_lst1) > midx)
	{
		bidx = ft_lstsize(g_lst1) - 1;
		fidx = 0;
		while (bidx != fidx)
		{
			fptr = lst_ptr(g_lst1, fidx);
			bptr = lst_ptr(g_lst1, bidx);
			if (bptr && cint(bptr) <= g_tmp.ar[midx])
			{
				move_top(cint(bptr), g_lst1, stack);
				push(STACK_B, PRINT);
				break;
			}
			else if (fptr && cint(fptr) <= g_tmp.ar[midx])
			{
				move_top(cint(fptr), g_lst1, stack);
				push(STACK_B, PRINT);
				break;
			}
			fidx++;
			bidx--;
		}
		lst_print();
	}
}
static int	move_top(int nb, t_list	*lst, int stack)
{
	int		size;
	int		lidx;
	int		times;
	int		t;

	size = ft_lstsize(lst);
	lidx = lst_idx(lst, nb);
	t = 1;
	if (lidx == size - 2)
		swap(stack, PRINT);
	else if (lidx < size / 2)
	{
		times = lidx + 1;
		t = times;
		while (times-- > 0)
			reverse(stack, PRINT);
	}
	else
	{
		times = size - lidx - 1;
		t = times;
		while (times-- > 0)
			rotate(stack, PRINT);
	}
	return t;
}