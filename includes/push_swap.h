/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 23:17:08 by tsomsa            #+#    #+#             */
/*   Updated: 2022/06/25 23:17:10 by tsomsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"
# include "libft.h"
# include <stdlib.h>

# define MODE_A		1
# define MODE_B		2
# define MODE_S		3
# define TESTING	0
# define RUNNING	1
# define SORT_5		5
# define SORT_100	100
# define SORT_500	500

t_list		*g_lst1;
t_list		*g_lst2;
typedef struct  s_sorted
{
	int *arr;
	int size;
}	t_sorted;

t_sorted	g_sorted;

int		is_valid_int(char *str);
int		is_dup_var(t_list *lst);
int		is_sorted_lst(t_list *lst);
void	sort();
void	set_sort_arr();
int		sorted_idx(int nb);
t_list	*set_var_nbs(int argc, char *argv[]);
t_list	*set_var_str(char *str);
void	del_content(void *content);
int		cint(t_list *lst);
void	lst_print();
int		lst_idx(t_list *lst, int nb);
void	swap(int mode);
void	push(int mode);
void	rotate(int mode);
void	reverse(int mode);
#endif
