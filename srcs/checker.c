/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 22:15:14 by tsomsa            #+#    #+#             */
/*   Updated: 2022/06/25 22:15:18 by tsomsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	read_input(void);

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
		else if (is_sorted_lst(g_lst1))
			ft_printf("Error: already sorted argument\n");
		else
			read_input();
		ft_lstclear(&g_lst1, &del_content);
		ft_lstclear(&g_lst2, &del_content);
	}
	return (0);
}
#include <string.h>
void	read_input(void)
{
	char	*buf;
	char	*opt;
	t_list	*lst;
	t_list	*new;
	t_list	*ptr;

	buf = calloc(sizeof(char), BUF_SIZE + 1);
	lst = NULL;
	while(read(0, buf, BUF_SIZE))
	{
		if (!is_opt(buf))
		{
			ft_printf("Error not operation argument\n", buf);
			break;
		}
		opt = calloc(sizeof(char), ft_strlen(buf));
		ft_strlcpy(opt, buf, ft_strlen(buf));
		new = ft_lstnew(opt);
		if (!lst)
			lst = new;
		else
			ft_lstadd_back(&lst, new);
	}
	ft_printf("finish %p\n", lst);
	if (lst)
		ft_lstclear(&lst, &del_content);
	free(buf);
}
