#include "push_swap.h"

static int	sort3a(void);
static void	top_sorta(int len);
static void	bottom_sorta(void);
static int	find_mid(t_list *lst, int len);
static int	is_sorted(t_list *lst, int len, int cmp);

int	qsorta(int len)
{
	int	mid;
	int	n;
	int	p;

	// ft_printf("A len = %d\n", len);
	if (is_sorted(g_lst1, len, 1))
		return (0);
	if (len <= 0)
		return (1);
	if (len <= 3)
		top_sorta(len);
	if (ft_lstsize(g_lst1) <= 3)
		return (1);
	// if (is_sorted(g_lst1, len, 1))
	// {
	// 	while (len--)
	// 		push(STACK_A);
	// 	return (1);
	// }
	mid = find_mid(g_lst1, len);
	n = len;
	p = 0;
	// ft_printf("A mid:len = %d:%d\n", mid, len);
	while (n != len / 2 + len % 2)
	{
		if (cint(ft_lstlast(g_lst1)) < mid)
		{
			push(STACK_B);
			n--;
		}
		else
		{
			rotate(STACK_A);
			p++;
		}
	}
	// lst_print();
	// first condition to dont run at first time
	while (len / 2 + len % 2 != ft_lstsize(g_lst1) && p-- > 0)
		reverse(STACK_A);
	// ft_printf("START qsorta in A\n");
	qsorta(len / 2 + len % 2);
	// ft_printf("START qsortb in A\n");
	qsortb(len / 2);
	return (0);
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
static int	sort3a(void)
{
	int		min;
	int		mid;
	int		max;

	if (is_sorted(g_lst1, ft_lstsize(g_lst1), 1))
		return (1);
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
static void	top_sorta(int len)
{
	int	size;
	t_list	*top;
	t_list	*prev;
	t_list	*pprev;

	size = ft_lstsize(g_lst1);
	if (size <= 3)
	{
		bottom_sorta();
		return ;
	}
	top = lst_ptr(g_lst1, size - 1);
	prev = lst_ptr(g_lst1, size - 2);
	pprev = lst_ptr(g_lst1, size - 3);
	if (len == 2 && cint(top) > cint(prev))
		swap(STACK_A);
	if (len != 3)
		return ;
	if (cint(top) > cint(prev) && cint(top) > cint(pprev))
	{
		swap(STACK_A);
		top_sorta(len);
	}
	if (cint(prev) > cint(top) && cint(prev) > cint(pprev))
	{
		rotate(STACK_A);
		swap(STACK_A);
		reverse(STACK_A);
		top_sorta(len);
	}
	if (cint(pprev) > cint(prev) && cint(pprev) > cint(top) && cint(top) > cint(prev))
		swap(STACK_A);
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
static void	bottom_sorta(void)
{
	int		min;
	int		mid;
	int		max;

	// ft_printf("== Bottom sort==\n");
	if (ft_lstsize(g_lst1) == 2 && g_tmp.ar[0] != cint(g_lst1))
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

static int	is_sorted(t_list *lst, int len, int cmp)
{
	t_list	*tmp;
	t_list	*chk;
	t_list	*ptr;
	int		n;

	ptr = lst;
	n = ft_lstsize(lst) - len;
	while (n-- > 0)
		ptr = ptr->next;
	chk = ptr;
	while (chk->next)
	{
		tmp = ptr;
		while (tmp)
		{
			if (cint(chk) < cint(tmp) && cmp > 0)
				return (0);
			if (cint(chk) > cint(tmp) && cmp < 0)
				return (0);
			tmp = tmp->next;
		}
		chk = chk->next;
	}
	return (1);
}

static int	find_mid(t_list *lst, int len)
{
	t_list	*tmp;
	t_list	*ptr;
	t_list	*chk;
	int		n;
	int		idx;

	if (len <= 0)
		return (cint(lst));
	n = ft_lstsize(lst) - len;
	ptr = lst;
	while (n-- > 0)
		ptr = ptr->next;
	tmp = ptr;
	while (ptr)
	{
		chk = tmp;
		idx = 0;
		while (chk)
		{
			if (cint(ptr) > cint(chk))
				idx++;
			chk = chk->next;
		}
		if (idx == len / 2)
			return (cint(ptr));
		ptr = ptr->next;
	}
	return (cint(tmp));
}