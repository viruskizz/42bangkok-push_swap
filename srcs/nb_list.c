#include "push_swap.h"

void	del_content(void *content)
{
	free(content);
}

t_list*	set_var_str(char *str)
{
	char	**arr;
	int		*nb;
	t_list	*lst;
	t_list	*var;

	arr = ft_split(str, ' ');
	lst = NULL;
	while (*arr)
	{
		nb = malloc(sizeof(int));
		*nb = ft_atoi(*arr++);
		var = ft_lstnew(nb);
		ft_lstadd_back(&lst, var);
	}
	return (lst);
}

t_list* set_var_nbs(int argc, char *argv[])
{
	int	i;
	int	*nb;
	t_list	*lst;
	t_list	*var;

	i = 1;
	lst = NULL;
	while (i < argc)
	{
		nb = malloc(sizeof(int));
		*nb = ft_atoi(argv[i]);
		var = ft_lstnew(nb);
		ft_lstadd_back(&lst, var);
		i++;
	}
	return (lst);
}

int	cint(t_list *lst)
{
	return *((int *)lst->content);
}