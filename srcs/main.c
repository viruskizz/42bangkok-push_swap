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

static void	sort(void);

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
		else if (!is_sorted_lst())
			sort();
		ft_lstclear(&g_lst1, &del_content);
		ft_lstclear(&g_lst2, &del_content);
	}
	return (0);
}

static void	sort(void)
{
	int		i;

	i = 0;
	set_sort_arr();
	set_arr_range();
	if (ft_lstsize(g_lst1) < 200)
		partition_sort();
	else
		qsorta(ft_lstsize(g_lst1));
}
