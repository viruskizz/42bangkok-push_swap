/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 22:15:08 by tsomsa            #+#    #+#             */
/*   Updated: 2022/06/25 22:15:08 by tsomsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	valid_int(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str++))
			return (0);
	}
	return (1);
}

int	valid_lst(t_list *lst)
{
	t_list	*tmp;
	t_list	*ptr;

	ptr = lst;
	while (ptr->next)
	{
		tmp = ptr->next;
		while (tmp)
		{
			if (cint(ptr) == cint(tmp))
				return (0);
			tmp = tmp->next;
		}
		ptr = ptr->next;
	}
	return (1);
}

int	sorted_lst(t_list *lst)
{
	t_list	*tmp;
	t_list	*ptr;

	ptr = lst;
	while (ptr->next)
	{
		tmp = ptr->next;
		while (tmp)
		{
			if (cint(ptr) >= cint(tmp))
				return (0);
			tmp = tmp->next;
		}
		ptr = ptr->next;
	}
	return (1);
}
