#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	*lst;
	t_list	*tmp;

	if (argc == 1)
		ft_printf("Error\n");
	else if (argc == 2)
		lst = set_var_str(argv[1]);
	else
		lst = set_var_nbs(argc, argv);
	if (lst)
	{
		tmp = lst;
		while (tmp)
		{
			ft_printf("%d\n", cint(tmp));
			tmp = tmp->next;
		}
		if (lst)
			ft_lstclear(&lst, &del_content);
	}

	return (0);
}
