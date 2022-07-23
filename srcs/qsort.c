#include "push_swap.h"

static int	is_sorted(t_list *lst, int len, int cmp);
static int	sort3a(void);
static int	sort3b(void);
static int	find_mid(t_list *lst, int len);

int	qsorta(int len)
{
	int	mid;
	int	n;
	int	p;

	if (len <= 0)
		return (1);
	if (len <= 3)
		return (sort3a());
	mid = find_mid(g_lst1, len);
	n = len;
	p = 0;
	ft_printf("A mid:len = %d:%d\n", mid, len);
	while (n > 0)
	{
		if (cint(ft_lstlast(g_lst1)) < mid)
			push(STACK_B, PRINT);
		else
		{
			rotate(STACK_A, PRINT);
			p++;
		}
		n--;
	}
	lst_print();
	while (p-- > 0)
		reverse(STACK_A, PRINT);
	ft_printf("START qsorta in A\n");
	qsorta(len / 2);
	ft_printf("START qsortb in A\n");
	qsortb(len / 2);
	return (0);
}

int	qsortb(int len)
{
	int	mid;
	int	n;
	int	p;

	if (len <= 0)
		return (1);
	if (ft_lstsize(g_lst2) <= 3)
		sort3b();
	if (is_sorted(g_lst2, len, -1))
	{
		while (len--)
			push(STACK_A, PRINT);
	}
	lst_print();
	if (len == 2)
	{
		swap(STACK_B, PRINT);
		while (len--)
			push(STACK_A, PRINT);
		len = 0;
	}
	mid = find_mid(g_lst2, len);
	n = len;
	p = 0;
	ft_printf("B mid:len = %d:%d\n", mid, len);
	while (n > 0)
	{
		if (cint(ft_lstlast(g_lst2)) >= mid)
			push(STACK_A, PRINT);
		else
		{
			rotate(STACK_B, PRINT);
			p++;
		}
		n--;
	}
	while (p-- > 0)
		reverse(STACK_B, PRINT);
	lst_print();
	ft_printf("START qsorta in B\n");
	qsorta(len / 2);
	ft_printf("START qsortb in B\n");
	qsortb(len / 2);
	return (0);
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
			if (cint(ptr) < cint(chk))
				idx++;
			chk = chk->next;
		}
		if (idx == len / 2 - 1)
			return (cint(ptr));
		ptr = ptr->next;
	}
	return (cint(tmp));
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

	if (is_sorted_lst(g_lst1))
		return (1);
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
	return (1);
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

	if (is_sorted(g_lst2, 3, -1))
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

