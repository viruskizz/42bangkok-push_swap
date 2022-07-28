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
			ft_printf("SORTING");
		ft_lstclear(&g_lst1, &del_content);
		ft_lstclear(&g_lst2, &del_content);
	}
	return (0);
}
