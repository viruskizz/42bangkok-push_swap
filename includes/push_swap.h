#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>

t_list* set_var_nbs(int argc, char *argv[]);
t_list*	set_var_str(char *str);
void	del_content(void *content);
int	    cint(t_list *lst);