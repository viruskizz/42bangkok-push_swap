#include "push_swap.h"

static void	swap_lst(t_list *lst);

void	swap(t_list *lst1, t_list *lst2, int mode)
{
	if (mode == MODE_A) {
		if (!lst1)
			return ;
		swap_lst(lst1);
		ft_printf("sa\n");
	} else if (mode == MODE_B) {
		if (!lst2)
			return ;
		swap_lst(lst2);
		ft_printf("sb\n");
	} else {
		if (lst1)
			swap_lst(lst1);
		if (lst2)
			swap_lst(lst2);
		if (lst1 || lst2)
			ft_printf("ss\n");
	}
}

static void	swap_lst(t_list *lst)
{
	t_list	*tmp;
	t_list	*lt;
	t_list	*ft;

	tmp = lst;
	while (tmp->next->next->next)
		tmp = tmp->next;
	ft = tmp->next;
	lt = tmp->next->next;
	ft->next = NULL;
	tmp->next = lt;
	lt->next = ft;
}

void	push(t_list **lst1, t_list **lst2, int mode)
{
	t_list	*tmp;
	t_list	*prev;

	if (mode == MODE_A) {
		if (!*lst2)
			return ;
		tmp = *lst2;
		while (tmp->next)
			tmp = tmp->next;
		if (tmp->prev)
			tmp->prev->next = NULL;
		else
			*lst2 = NULL;
		ft_lstadd_back(lst1, tmp);
		ft_printf("pa\n");
	} else if (mode == MODE_B) {
		if (!*lst1)
			return ;
		tmp = *lst1;
		while (tmp->next)
			tmp = tmp->next;
		if (tmp-prev)
			tmp->prev->next = NULL;
		else
			lst1 = NULL;
		ft_lstadd_back(lst2, tmp);
		ft_printf("pb\n");
	}
}

void	rotate(t_list *lst1, t_list *lst2, int mode)
{
	if (mode == MODE_A) {
		ft_printf("ra\n");
	} else if (mode == MODE_B) {
		ft_printf("rb\n");
	} else {
		ft_printf("rr\n");
	}
}

void	reverse(t_list *lst1, t_list *lst2, int mode)
{
	if (mode == MODE_A) {
		ft_printf("rra\n");
	} else if (mode == MODE_B) {
		ft_printf("rrb\n");
	} else {
		ft_printf("rrr\n");
	}
}

