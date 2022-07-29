/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomsa <tsomsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 16:16:15 by tsomsa            #+#    #+#             */
/*   Updated: 2022/07/29 16:16:16 by tsomsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*read_input(t_list **lst);
void	run_opts(t_list *lst);
void	run_checker(void);

int	main(int argc, char *argv[])
{
	g_lst1 = NULL;
	g_lst2 = NULL;
	if (argc == 1)
	{
		ft_printf("Error\n");
		return (0);
	}
	else if (argc == 2)
		g_lst1 = set_var_str(argv[1]);
	else
		g_lst1 = set_var_nbs(argc, argv);
	if (!g_lst1)
		ft_printf("Error: invalid argument\n");
	else
	{
		if (!is_dup_var(g_lst1))
			ft_printf("Error: duplicated argument\n");
		else if (is_sorted_lst())
			ft_printf("Error: already sorted argument\n");
		else
			run_checker();
		ft_lstclear(&g_lst1, &del_content);
		ft_lstclear(&g_lst2, &del_content);
	}
	return (0);
}

void	run_checker(void)
{
	t_list	*lst;

	lst = NULL;
	if (!read_input(&lst))
	{
		ft_printf("Error not operation argument\n");
		return ;
	}
	run_opts(lst);
	ft_lstclear(&lst, &del_content);
}

t_list	*read_input(t_list **lst)
{
	char	*buf;
	char	*opt;
	t_list	*new;

	buf = calloc(sizeof(char), BUF_SIZE + 1);
	while (read(0, buf, BUF_SIZE))
	{
		if (!is_opt(buf))
		{
			if (lst)
				ft_lstclear(lst, &del_content);
			free(buf);
			return (NULL);
		}
		opt = calloc(sizeof(char), ft_strlen(buf));
		ft_strlcpy(opt, buf, ft_strlen(buf));
		new = ft_lstnew(opt);
		if (*lst == NULL)
			*lst = new;
		else
			ft_lstadd_back(lst, new);
	}
	free(buf);
	return (*lst);
}

void	run_opts(t_list *lst)
{
	while (lst)
	{
		run_opt((char *) lst->content, NOPRINT);
		lst = lst->next;
	}
	if (is_sorted_lst())
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}
