
#include "push_swap.h"

static int	move_top(int nb, t_list	*lst, int stack, int is_print);
static int	move_push(int nb, t_list **lst, int stack1, int stack2);

void	short_move(int midx, t_list **lst, int stack1, int stack2)
{
	int		et;
	int		tt;
	int		bt;

	et = sim_move(EDGE_MOV, midx, STACK_A, STACK_B);
	tt = sim_move(TOP_MOV, midx, STACK_A, STACK_B);
	bt = sim_move(BOT_MOV, midx, STACK_A, STACK_B);
	if (et < tt && et < bt)
		from_edge_move(midx, &g_lst1, STACK_A, STACK_B);
	else if (bt < tt)
		from_bot_move(midx, &g_lst1, STACK_A, STACK_B);
	else
		from_top_move(midx, &g_lst1, STACK_A, STACK_B);
}

int	sim_move(int move, int midx, int stack1, int stack2)
{
	int		times;

	g_lstx = lst_clone(g_lst1);
	g_lsty = lst_clone(g_lst2);
	times = 0;
	if (move == EDGE_MOV)
		times = from_edge_move(midx, &g_lstx, STACK_X, STACK_Y);
	if (move == TOP_MOV)
		times = from_top_move(midx, &g_lstx, STACK_X, STACK_Y);
	if (move == BOT_MOV)
		times = from_bot_move(midx, &g_lstx, STACK_X, STACK_Y);
	ft_lstclear(&g_lstx, &del_content);
	ft_lstclear(&g_lsty, &del_content);
	return (times);
}

int	from_edge_move(int midx, t_list **lst, int stack1, int stack2)
{
	int		times;
	int		idx;
	int		r;
	t_list	*ptr;

	times = 0;
	r = -1;
	idx = 0;
	while (ft_lstsize(*lst) > midx && idx < midx)
	{
		if (r < 0)
			ptr = lst_ptr(*lst, ft_lstsize(*lst) - 1 - idx);
		else
			ptr = lst_ptr(*lst, idx);
		if (ptr && cint(ptr) <= g_tmp.ar[midx])
		{
			times += move_push(cint(ptr), lst, stack1, stack2);
			idx = 0;
		}
		else
		{
			r = r * -1;
			if (r < 0)
				idx++;
		}
	}
	return (times);
}

/*
from top to bottom
*/
int	from_top_move(int midx, t_list **lst, int stack1, int stack2)
{
	int		times;
	int		idx;
	t_list	*ptr;

	times = 0;
	while (ft_lstsize(*lst) > midx)
	{

		idx = ft_lstsize(*lst) - 1;
		while (idx >= 0)
		{
			ptr = lst_ptr(*lst, idx);
			if (ptr && cint(ptr) <= g_tmp.ar[midx])
			{
				times += move_push(cint(ptr), lst, stack1, stack2);
				break;
			}
			idx--;
		}
	}
	return (times);
}

/*
from bottom to top
*/
int	from_bot_move(int midx, t_list **lst, int stack1, int stack2)
{
	int		times;
	int		idx;
	t_list	*ptr;

	times = 0;
	while (ft_lstsize(*lst) > midx)
	{

		idx = 0;
		while (idx < ft_lstsize(*lst)>0)
		{
			ptr = lst_ptr(*lst, idx);
			if (ptr && cint(ptr) <= g_tmp.ar[midx])
			{
				times += move_push(cint(ptr), lst, stack1, stack2);
				break;
			}
			idx++;
		}
	}
	return (times);
}

static int	move_push(int nb, t_list **lst, int stack1, int stack2)
{
	int times;
	int t;
	int	is_print;

	times = 0;
	t = 0;
	if (stack1 == STACK_X || stack1 == STACK_Y || stack2 == STACK_X || stack2 == STACK_Y)
		is_print = NOPRINT;
	else
		is_print = PRINT;
	t = move_top(nb, *lst, stack1, is_print);
	times += t;
	push(stack2, is_print);
	return (++times);
}

static int	move_top(int nb, t_list	*lst, int stack, int is_print)
{
	int		size;
	int		lidx;
	int		times;
	int		t;

	size = ft_lstsize(lst);
	lidx = lst_idx(lst, nb);
	t = 0;
	if (lidx == size - 1)
		return (t);
	else if (lidx < size / 2)
	{
		times = lidx + 1;
		t = times;
		while (times-- > 0)
		{
			reverse(stack, is_print);
		}
	}
	else
	{
		times = size - lidx - 1;
		t = times;
		while (times-- > 0)
		{
			rotate(stack, is_print);
		}
	}
	return (t);
}
