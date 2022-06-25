#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define MODE_A 1
# define MODE_B 2
# define MODE_S 3

t_list* set_var_nbs(int argc, char *argv[]);
t_list*	set_var_str(char *str);
void	del_content(void *content);
int	    cint(t_list *lst);
void    lst_print(t_list *lst1, t_list *lst2);
void	swap(t_list *lst1, t_list *lst2, int mode);
void	push(t_list **lst1, t_list **lst2, int mode);
void	rotate(t_list *lst1, t_list *lst2, int mode);
void	reverse(t_list *lst1, t_list *lst2, int mode);
#endif