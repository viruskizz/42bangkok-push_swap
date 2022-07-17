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

t_list	*lst_clone(t_list *lst)
{
	t_list	*new;
	t_list	*tmp;
	int		*nb;

	tmp = NULL;
	while(lst)
	{
		nb = malloc(sizeof(int));
		*nb = cint(lst);
		new = ft_lstnew(nb);
		if (tmp)
			ft_lstadd_back(&tmp, new);
		else
			tmp = new;
		lst = lst->next;
	}
	return (tmp);
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

void	lst_debug(char *str, t_list *lst)
{

	ft_printf("%s", str);
	while (lst)
	{
		ft_printf("%d ", cint(lst));
		lst = lst->next;
	}
	ft_printf("\n");
}
