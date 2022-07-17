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
	// ft_printf("\n= RUN =\n");
	// while (i < g_tmp.n)
	// {
	// 	ft_printf("[%d]: %d\n", i, g_tmp.ar[i]);
	// 	i++;
	// }
	// lst_print();
	if (ft_lstsize(g_lst1) > 3)
		pre_sort();
	bottom_sort();
	// lst_print();
	complete_sort();
	// lst_print();
	// if (is_sorted_lst(g_lst1))
	// 	ft_printf("\nSORTED\n");
	// lst_print();
	// ft_printf("= Finish =\n");

	// lst_print();
	// rotate(MODE_A);
	// lst_print();
	g_lstx = lst_clone(g_lst1);
	g_lsty = lst_clone(g_lst2);
	// swap(STACK_X, NOPRINT);
	// rotate(STACK_X, NOPRINT);
	// rotate(STACK_X, NOPRINT);
	// rotate(STACK_X, NOPRINT);
	// rotate(STACK_X, NOPRINT);
	// rotate(STACK_X, NOPRINT);
	// reverse(STACK_X, NOPRINT);
	// push(STACK_Y, NOPRINT);
	// push(STACK_X, NOPRINT);
	ft_lstclear(&g_lstx, &del_content);
	ft_lstclear(&g_lsty, &del_content);
	// t_list *tmp = lst_ptr(g_lst1, 0);
	// t_list *tmp1 = lst_ptr(g_lst1, 1);
	// t_list *tmp2 = lst_ptr(g_lst1, 2);
	// t_list *tmp3 = lst_ptr(g_lst1, 3);
	// ft_printf("%d <- %d -> %d\n", cint(tmp->prev), cint(tmp), cint(tmp->next));
	// ft_printf("%d <- %d -> %d\n", cint(tmp1->prev), cint(tmp1), cint(tmp1->next));
	// ft_printf("%d <- %d -> %d\n", cint(tmp2->prev), cint(tmp2), cint(tmp2->next));
	// ft_printf("%d <- %d -> %d\n", cint(tmp3->prev), cint(tmp3), cint(tmp3->next));
}
