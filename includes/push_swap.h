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
# define STACK_X	4
# define STACK_Y	5
# define STACK_Z	6
# define TESTING	0
# define RUNNING	1
# define PRINT		1
# define NOPRINT	0
# define EDGE_MOV	50
# define TOP_MOV	99
# define BOT_MOV	0
# define TOC_MOV	55

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

void	partition_sort(void);
void	bottom_sort(void);
void	complete_sort(void);
void	partition_ab(int midx);

int 	move_top_times(int nb, t_list *lst);
void	move_top(int nb, t_list	*lst, int stack);

// template
void	set_sort_arr();
int		sorted_idx(int nb);

// list function
t_list	*set_var_nbs(int argc, char *argv[]);
t_list	*set_var_str(char *str);
void	del_content(void *content);
int		cint(t_list *lst);
void	lst_print();
void	lst_debug(char *str, t_list *lst);
int		lst_idx(t_list *lst, int nb);
t_list	*lst_ptr(t_list *lst, int idx);

// operation
void	swap(int stack);
void	push(int stack);
void	rotate(int stack);
void	reverse(int stack);

int	qsorta(int len);
int	qsortb(int len);

#endif
