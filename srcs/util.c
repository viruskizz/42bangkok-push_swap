#include "push_swap.h"

int	find_mid(t_list *lst, int len)
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

int	is_sorted(t_list *lst, int len, int cmp)
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
