/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mylist.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 22:15:26 by tsomsa            #+#    #+#             */
/*   Updated: 2022/06/25 22:15:27 by tsomsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_lst_nb(t_list **lst, char *str);

void	del_content(void *content)
{
	free(content);
}

t_list	*set_var_str(char *str)
{
	char	**arr;
	char	**tmp;
	t_list	*lst;

	arr = ft_split(str, ' ');
	tmp = arr;
	while (*tmp)
	{
		if (!is_valid_int(*tmp++))
			return (NULL);
	}
	lst = NULL;
	while (*arr)
		set_lst_nb(&lst, *arr++);
	return (lst);
}

t_list	*set_var_nbs(int argc, char *argv[])
{
	t_list	*lst;
	int		i;

	i = 1;
	lst = NULL;
	while (i < argc)
		set_lst_nb(&lst, argv[i++]);
	return (lst);
}

static void	set_lst_nb(t_list **lst, char *str)
{
	int		*nb;
	t_list	*var;

	nb = malloc(sizeof(int));
	*nb = ft_atoi(str);
	var = ft_lstnew(nb);
	ft_lstadd_front(lst, var);
}

// Using for debuging

int	cint(t_list *lst)
{
	if (!lst)
		return (0);
	return (*((int *)lst->content));
}

void	lst_print(t_list *lst1, t_list *lst2)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = lst1;
	tmp2 = lst2;
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
