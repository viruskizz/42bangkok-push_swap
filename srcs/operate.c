#include "push_swap.h"

void	swap(t_list *lst1, t_list *lst2, int mode)
{
	if (mode == MODE_A) {
		ft_printf("sa\n");
	} else if (mode == MODE_B) {
		ft_printf("sb\n");
	} else {
		ft_printf("ss\n");
	}
}

void	push(t_list *lst1, t_list *lst2, int mode)
{
	if (mode == MODE_A) {
		ft_printf("pa\n");
	} else if (mode == MODE_B) {
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

