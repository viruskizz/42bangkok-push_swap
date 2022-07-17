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

# define STACK_A	1
# define STACK_B	2
# define STACK_S	3
# define TESTING	0
# define RUNNING	1
# define PRINT		1
# define NOPRINT	0
# define SORT_5		5
# define SORT_100	100
# define SORT_500	500

t_list		*g_lst1;
t_list		*g_lst2;
typedef struct  s_template
{
	int *ar;
	int n;
}	t_template;

t_template	g_tmp;

int		is_valid_int(char *str);
int		is_dup_var(t_list *lst);
int		is_sorted_lst(t_list *lst);

void	pre_sort(void);
void	bottom_sort(void);
void	complete_sort(void);

int		short_move(int midx, t_list **lst, int stack1, int stack2);

// template
void	set_sort_arr();
int		sorted_idx(int nb);

// list function
t_list	*set_var_nbs(int argc, char *argv[]);
t_list	*set_var_str(char *str);
void	del_content(void *content);
int		cint(t_list *lst);
void	lst_print();
int		lst_idx(t_list *lst, int nb);
t_list	*lst_ptr(t_list *lst, int idx);

// operation
void	swap(int stack, int is_print);
void	push(int stack, int is_print);
void	rotate(int stack, int is_print);
void	reverse(int stack, int is_print);
#endif
