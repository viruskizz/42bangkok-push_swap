#include "push_swap.h"

static int	sort3b(void);
static void	top_sortb(int len);
static void	bottom_sortb(void);
static int	find_mid(t_list *lst, int len);
static int	is_sorted(t_list *lst, int len, int cmp);

int	qsortb(int len)
{
	int	mid;
	int	n;
	int	p;

	if (len <= 0)
		return (1);
	if (len <= 3)
		sort3b();
		// top_sortb(len);
	if (is_sorted(g_lst2, len, -1))
	{
		while (len--)
			push(STACK_A, PRINT);
		return (1);
	}
	// lst_print();
	if (len == 2)
	{
		swap(STACK_B, PRINT);
		while (len--)
			push(STACK_A, PRINT);
		return (1);
	}
	mid = find_mid(g_lst2, len);
	n = len;
	p = 0;
	// ft_printf("B mid:len = %d:%d\n", mid, len);
	while (n != len / 2)
	{
		if (cint(ft_lstlast(g_lst2)) >= mid)
		{
			push(STACK_A, PRINT);
			n--;
		}
		else
		{
			rotate(STACK_B, PRINT);
			p++;
		}
	}
	while (len / 2 != ft_lstsize(g_lst2) && p-- > 0)
		reverse(STACK_B, PRINT);
	// lst_print();
	// ft_printf("START qsorta in B\n");
	qsorta(len / 2 + len % 2);
	// ft_printf("START qsortb in B\n");
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
	3		2		3
	1	ra	3	sa	2
	2		1		1

	1		2		3
	2	sa 	1	rra	2
	3		3		1
*/
static int	sort3b(void)
{
	int		min;
	int		mid;
	int		max;

	if (is_sorted(g_lst2, ft_lstsize(g_lst2), -1))
		return (1);
	else if (ft_lstsize(g_lst2) == 2)
		swap(STACK_B, PRINT);
	else if (ft_lstsize(g_lst2) == 3)
	{
		max = g_tmp.ar[0];
		mid = g_tmp.ar[1];
		min = g_tmp.ar[2];
		if (lst_idx(g_lst2, max) == 2 && (lst_idx(g_lst2, min) == 1))
			rotate(STACK_B, PRINT);
		if ((lst_idx(g_lst2, max) == 1 && lst_idx(g_lst2, min) == 0) ||
			(lst_idx(g_lst2, max) == 0 && lst_idx(g_lst2, min) == 2))
			swap(STACK_B, PRINT);
		if (lst_idx(g_lst2, max) == 0 && lst_idx(g_lst2, min) == 1)
			reverse(STACK_B, PRINT);
	}
	return (1);
}


/**
 * @brief sort Stack B Top is greatest
 	1		3		1		2		3
	3		1		2		1		2
	2	sa	2	ra	x	sa	x	rra	1
	x		x		x		x		x
	x		x		3		3		x

	1		2		1		3		2		3
	2	sa	1	ra	3	sa	1	rra	3	sa	2
	3		3		x		x		1		1
	x		x		x		x		x		x
	x		x		2		2		x		x
 */
static void	top_sortb(int len)
{
	int	size;
	t_list	*top;
	t_list	*prev;
	t_list	*pprev;

	size = ft_lstsize(g_lst2);
	if (size <= 3)
	{
		bottom_sortb();
		return ;
	}
	top = lst_ptr(g_lst2, size - 1);
	prev = lst_ptr(g_lst2, size - 2);
	pprev = lst_ptr(g_lst2, size - 3);
	if (len == 2 && cint(top) < cint(prev))
		swap(STACK_B, PRINT);
	if (len != 3)
		return ;
	if (cint(top) < cint(prev) && cint(top) < cint(pprev))
	{
		swap(STACK_B, PRINT);
		top_sortb(len);
	}
	if (cint(prev) < cint(top) && cint(prev) < cint(pprev))
	{
		rotate(STACK_B, PRINT);
		swap(STACK_B, PRINT);
		reverse(STACK_B, PRINT);
		top_sortb(len);
	}
	if (cint(pprev) < cint(prev) && cint(pprev) < cint(top) && cint(top) < cint(prev))
		swap(STACK_B, PRINT);
}

/**
 * @brief Sort only last 3 elements in Stack B
 * @param lst
 */
/*
Operation description
Focus on Max and Min value only

	1		3
	3	ra	2
	2		1

	1		2		3
	2	ra	3	sa	2
	3		1		1

	2		3
	1	rra	2
	3		1

	3		2		3
	1	rra	3	sa	2
	2		1		1

*/
static void	bottom_sortb(void)
{
	int		min;
	int		mid;
	int		max;

	if (is_sorted(g_lst2, ft_lstsize(g_lst2), 1))
		return ;
	else if (ft_lstsize(g_lst2) == 2 && g_tmp.ar[0]== cint(g_lst2))
		swap(STACK_B, PRINT);
	else if (ft_lstsize(g_lst2) == 3)
	{
		max = g_tmp.ar[0];
		mid = g_tmp.ar[1];
		min = g_tmp.ar[2];
		if (lst_idx(g_lst2, min) == 2
			&& (lst_idx(g_lst2, max) == 0 || lst_idx(g_lst2, max) == 1))
			rotate(STACK_B, PRINT);
		if (lst_idx(g_lst2, min) == 1
			&& (lst_idx(g_lst2, mid) == 0 || lst_idx(g_lst2, mid) == 2))
			reverse(STACK_B, PRINT);
		if (lst_idx(g_lst2, min) == 0 && lst_idx(g_lst2, max) == 1)
			swap(STACK_B, PRINT);
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
