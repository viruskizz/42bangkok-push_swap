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
#include "get_next_line.h"

t_list	*read_input(t_list **lst);
void	run_opts(t_list *lst);
void	run_checker(void);

int	main(int argc, char *argv[])
{
	g_lst1 = NULL;
	g_lst2 = NULL;
	if (argc == 1 || (argc == 2 && ft_strlen(argv[1]) == 0))
		return (0);
	else if (argc == 2)
		g_lst1 = set_var_str(argv[1]);
	else
		g_lst1 = set_var_nbs(argc, argv);
	if (!g_lst1)
		ft_putstr_fd("Error\n", STDERR_FILENO);
	else
	{
		if (is_dup_var(g_lst1))
			ft_putstr_fd("Error\n", STDERR_FILENO);
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
	read_input(&lst);
	run_opts(lst);
	if (lst)
		ft_lstclear(&lst, &del_content);
}

t_list	*read_input(t_list **lst)
{
	char	*line;
	t_list	*new;

	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		if (!is_opt(line))
		{
			ft_putstr_fd("Error\n", STDERR_FILENO);
			if (lst)
				ft_lstclear(lst, &del_content);
			free(line);
			exit(EXIT_FAILURE);
		}
		new = ft_lstnew(line);
		if (*lst == NULL)
			*lst = new;
		else
			ft_lstadd_back(lst, new);
		line = get_next_line(0);
	}
	return (*lst);
}

void	run_opts(t_list *lst)
{
	int		t;

	t = 0;
	while (lst)
	{
		run_opt((char *) lst->content, NOPRINT);
		lst = lst->next;
	}
	if (is_sorted_lst())
		ft_putstr_fd("OK\n", STDOUT_FILENO);
	else
		ft_putstr_fd("KO\n", STDOUT_FILENO);
}
