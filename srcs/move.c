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
