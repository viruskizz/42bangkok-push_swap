/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   template.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araiva <tsomsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 01:11:30 by araiva            #+#    #+#             */
/*   Updated: 2022/07/17 01:11:31 by araiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_sort_arr(void)
{
	t_list	*ptr;
	t_list	*chk;
	int		idx;

	g_tmp.n = ft_lstsize(g_lst1);
	g_tmp.ar = malloc(sizeof(int) * g_tmp.n);
	ptr = g_lst1;
	while (ptr)
	{
		chk = g_lst1;
		idx = 0;
		while (chk)
		{
			if (cint(ptr) < cint(chk))
				idx++;
			chk = chk->next;
		}
		g_tmp.ar[idx] = cint(ptr);
		ptr = ptr->next;
	}
}

void	set_arr_range(void)
{
	if (g_tmp.n > 499)
		g_tmp.range = g_tmp.n / 11;
	else if (g_tmp.n > 49)
		g_tmp.range = g_tmp.n / 5;
	else
		g_tmp.range = g_tmp.n / 2;
}

int	sorted_idx(int nb)
{
	int		i;

	i = 0;
	while (i < g_tmp.n)
	{
		if (g_tmp.ar[i] == nb)
			return (i);
		i++;
	}
	return (-1);
}
