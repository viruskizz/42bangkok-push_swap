#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define MODE_A 1
# define MODE_B 2
# define MODE_S 3

t_list  *g_lst1;
t_list  *g_lst2;

int		valid_int(char *str);
int		valid_lst(t_list *lst);
int		sorted_lst(t_list *lst);
t_list*	set_var_nbs(int argc, char *argv[]);
t_list*	set_var_str(char *str);
void	del_content(void *content);
int		cint(t_list *lst);
void	lst_print(t_list *lst1, t_list *lst2);
void	swap(int mode);
void	push(int mode);
void	rotate(int mode);
void	reverse(int mode);
#endif