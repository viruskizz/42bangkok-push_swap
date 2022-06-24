#include "push_swap.h"

void	runner(t_list *lst);

int	main(int argc, char *argv[])
{
	t_list	*lst;

	if (argc == 1)
		ft_printf("Error\n");
	else if (argc == 2)
		lst = set_var_str(argv[1]);
	else
		lst = set_var_nbs(argc, argv);
	if (!lst)
		ft_printf("Error\n");
	else
	{
		runner(lst);
		ft_lstclear(&lst, &del_content);
	}
	return (0);
}

void	runner(t_list *lst1)
{
	t_list *lst2;

	lst2 = NULL;
	swap(lst1, lst2, MODE_A);
	lst_print(lst1, lst2);
	swap(lst1, lst2, MODE_B);
	swap(lst1, lst2, MODE_S);
}
