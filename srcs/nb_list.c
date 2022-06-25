#include "push_swap.h"

void	set_lst_nb(t_list **lst, char *str);

int		valid_int(char *str)
{
	while(*str)
	{
		if (!ft_isdigit(*str++))
			return (0);
	}
	return (1);
}

void	del_content(void *content)
{
	free(content);
}

t_list	*set_var_str(char *str)
{
	char	**arr;
	char	**tmp;
	t_list	*lst;

	arr = ft_split(str, ' ');
	tmp = arr;
	while (*tmp)
	{
		if (!valid_int(*tmp++))
			return (NULL);
	}
	lst = NULL;
	while (*arr)
		set_lst_nb(&lst, *arr++);
	return (lst);
}

void	set_lst_nb(t_list **lst, char *str)
{
	int		*nb;
	t_list	*var;

	nb = malloc(sizeof(int));
	*nb = ft_atoi(str);
	var = ft_lstnew(nb);
	ft_lstadd_back(lst, var);	
}

int	cint(t_list *lst)
{
	if (!lst)
		return (0);
	return *((int *)lst->content);
}

t_list	*set_var_nbs(int argc, char *argv[])
{
	int	i;
	t_list	*lst;

	i = 1;
	lst = NULL;
	while (i < argc)
		set_lst_nb(&lst, argv[i++]);
	return (lst);
}

void	lst_print(t_list *lst1, t_list *lst2)
{
	t_list *tmp1;
	t_list *tmp2;

	tmp1 = lst1;
	tmp2 = lst2;
	ft_printf("A: ");
	while (tmp1)
	{
		ft_printf("%d ", cint(tmp1));
		tmp1 = tmp1->next;
	}
	ft_printf("\n");
	ft_printf("B: ");
	while (tmp2)
	{
		ft_printf("%d ", cint(tmp2));
		tmp2 = tmp2->next;
	}
	ft_printf("\n");
}
