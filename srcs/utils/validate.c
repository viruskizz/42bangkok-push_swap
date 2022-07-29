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

int	is_valid_int(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str++))
			return (0);
	}
	return (1);
}

int	is_dup_var(t_list *lst)
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

int	is_sorted_lst(t_list *lst)
{
	t_list	*tmp;
	t_list	*ptr;

	ptr = lst;
	while (ptr->next)
	{
		tmp = ptr->next;
		while (tmp)
		{
			if (cint(ptr) < cint(tmp))
				return (0);
			tmp = tmp->next;
		}
		ptr = ptr->next;
	}
	return (1);
}

int	is_opt(char *str)
{
	if (ft_strlen(str) == 3)
	{
		if (ft_strncmp(str, "sa", 2)
			&& ft_strncmp(str, "sb", 2)
			&& ft_strncmp(str, "ss", 2)
			&& ft_strncmp(str, "pa", 2)
			&& ft_strncmp(str, "pb", 2)
			&& ft_strncmp(str, "ra", 2)
			&& ft_strncmp(str, "rb", 2)
			&& ft_strncmp(str, "rr", 2))
			return (0);
		else
			return (1);
	}
	if (ft_strlen(str) == 4)
	{
		if (ft_strncmp(str, "rra", 3)
			&& ft_strncmp(str, "rrb", 3)
			&& ft_strncmp(str, "rrr", 3))
			return (0);
		else
			return (1);
	}
	return (0);
}
