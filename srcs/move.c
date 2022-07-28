/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomsa <tsomsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:03:26 by tsomsa            #+#    #+#             */
/*   Updated: 2022/07/28 15:03:27 by tsomsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
from top to bottom
*/
void	partition_ab(int mid)
{
	int		p;
	int		idx;
	int		len;
	t_list	*ptr;

	p = g_tmp.range;
	while (ft_lstsize(g_lst1) > 3 && p-- > 0)
	{
		idx = ft_lstsize(g_lst1) - 1;
		while (idx >= 0)
		{
			ptr = lst_ptr(g_lst1, idx--);
			if (ptr && cint(ptr) <= mid)
			{
				move_top(cint(ptr), g_lst1, STACK_A);
				push(STACK_B);
				break ;
			}
		}
	}
	len = ft_lstsize(g_lst1);
	if (len > 3 && len > g_tmp.range)
		partition_ab(g_tmp.ar[len - g_tmp.range]);
	else if (len > 3)
		partition_ab(g_tmp.ar[3]);
}

int	move_top_times(int nb, t_list *lst)
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
	int	times;

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
