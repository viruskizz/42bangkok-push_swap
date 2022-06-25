/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 22:07:08 by tsomsa            #+#    #+#             */
/*   Updated: 2022/06/25 22:07:10 by tsomsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_lst(t_list **src, t_list **dest);

/**
 * @brief push top of stack from source to destination
 * A: 7 5 9 2 3
 * B:
 * == push b
 * A: 7 5 9 2
 * B: 3
 * @param mode 
 */
void	push(int mode)
{
	if (mode == MODE_A)
	{
		if (!g_lst2)
			return ;
		push_lst(&g_lst2, &g_lst1);
		ft_printf("pa\n");
	}
	else if (mode == MODE_B)
	{
		if (!g_lst1)
			return ;
		push_lst(&g_lst1, &g_lst2);
		ft_printf("pb\n");
	}
}

static void	push_lst(t_list **src, t_list **dest)
{
	t_list	*tmp;

	tmp = *src;
	while (tmp->next)
		tmp = tmp->next;
	if (tmp->prev)
		tmp->prev->next = NULL;
	else
		*src = NULL;
	ft_lstadd_back(dest, tmp);
}
