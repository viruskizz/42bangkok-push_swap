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

static void	runner(void);

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
		ft_printf("Error\n");
	else
	{
		if (!is_valid_lst(g_lst1) || is_sorted_lst(g_lst1))
			ft_printf("Error\n");
		else
			runner();
		ft_lstclear(&g_lst1, &del_content);
		ft_lstclear(&g_lst2, &del_content);
	}
	return (0);
}

static void	runner(void)
{
	int		i;
	int		size;

	i = 0;
	size = ft_lstsize(g_lst1);
	set_sort_arr();
	while (i < size)
		ft_printf("%d, ", g_sarr[i++]);
	// swap(MODE_A);
}
