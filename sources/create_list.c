

#include <push_swap.h>

//contar número elementos en array y pasarlos todos a una lista enlazada
t_list *init_list(int *nums, int len)
{
	t_list *stack_a;
	int i;

	stack_a = ft_lstnew(&nums[0]);
	i = 1;
	while (i < len)
	{
		ft_lstadd_front(&stack_a, ft_lstnew(&nums[i]));
		i++;
	}
	return(stack_a);
}

void	show_list(t_list *lst, int num)
{
	int	i;

	i = 0;
	if (lst == NULL)
	{
		write(1, "Lista vacía \n\n", 15);
		return ;
	}
	while (i < num && lst != NULL)
	{
		printf("DIRECTION: %p\nData: %d\nNext node: %p\n\n", &lst->data, *lst->data, lst->next);
		lst = lst->next;
		i++;
	}
}