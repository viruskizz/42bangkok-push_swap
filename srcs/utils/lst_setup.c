/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araiva <tsomsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 01:20:26 by araiva            #+#    #+#             */
/*   Updated: 2022/07/17 01:20:27 by araiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_lst_nb(t_list **lst, char *str);
static void	is_number(char *str);
static void	free_arr2d(char	**arr);

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
		{
			free_arr2d(arr);
			return (NULL);
		}
	}
	lst = NULL;
	tmp = arr;
	while (*tmp)
		set_lst_nb(&lst, *tmp++);
	free_arr2d(arr);
	return (lst);
}

t_list	*set_var_nbs(int argc, char *argv[])
{
	t_list	*lst;
	int		i;

	i = 1;
	lst = NULL;
	while (i < argc)
		if (!is_valid_int(argv[i++]))
			return (NULL);
	i = 1;
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

static void	free_arr2d(char	**arr)
{
	char	**tmp;

	tmp = arr;
	while (*tmp)
		free(*tmp++);
	free(arr);
}
