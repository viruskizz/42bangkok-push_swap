/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_opt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araiva <tsomsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 01:20:35 by araiva            #+#    #+#             */
/*   Updated: 2022/07/17 01:20:35 by araiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	del_content(void *content)
{
	free(content);
}

int	lst_idx(t_list *lst, int nb)
{
	t_list	*ptr;
	int		i;

	i = 0;
	if (!lst)
		return (-1);
	ptr = lst;
	while (ptr)
	{
		if (cint(ptr) == nb)
			return (i);
		ptr = ptr->next;
		i++;
	}
	return (-1);
}

t_list	*lst_ptr(t_list *lst, int idx)
{
	int		size;
	int		i;

	size = ft_lstsize(lst);
	i = 0;
	if (idx >= size)
		return (NULL);
	while (i++ < idx)
		lst = lst->next;
	return (lst);
}

int	cint(t_list *lst)
{
	if (!lst)
		return (0);
	return (*((int *)lst->content));
}

// Using for debuging
void	lst_print(void)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = g_lst1;
	tmp2 = g_lst2;
	ft_printf("A: ");
	while (tmp1)
	{
		ft_printf("%d ", cint(tmp1));
		tmp1 = tmp1->next;
	}
	ft_printf("\n");
	ft_printf("B: ");
	while (tmp2)
	{
		ft_printf("%d ", cint(tmp2));
		tmp2 = tmp2->next;
	}
	ft_printf("\n");
}
