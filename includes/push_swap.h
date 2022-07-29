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
# include <unistd.h>

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
# define BUF_SIZE	10

t_list		*g_lst1;
t_list		*g_lst2;
typedef struct s_template
{
	int	*ar;
	int	n;
	int	range;
}	t_template;

t_template	g_tmp;

// operation
void	swap(int stack, int is_print);
void	push(int stack, int is_print);
void	rotate(int stack, int is_print);
void	reverse(int stack, int is_print);

// sort
void	partition_sort(void);
void	qsorta(int len);
void	qsortb(int len);

// validate
int		is_valid_int(char *str);
int		is_dup_var(t_list *lst);
int		is_sorted_lst(void);
int		is_opt(char *str);

// template
void	set_sort_arr(void);
void	set_arr_range(void);
int		sorted_idx(int nb);

// list function
t_list	*set_var_nbs(int argc, char *argv[]);
t_list	*set_var_str(char *str);
void	del_content(void *content);
int		cint(t_list *lst);
void	lst_print(void);
int		lst_idx(t_list *lst, int nb);
t_list	*lst_ptr(t_list *lst, int idx);

// util
int		find_mid(t_list *lst, int len);
int		is_sorted(t_list *lst, int len, int cmp);
int		move_top_times(int nb, t_list *lst);
void	move_top(int nb, t_list	*lst, int stack, int is_print);
void	run_opt(char *str, int is_print);

#endif
