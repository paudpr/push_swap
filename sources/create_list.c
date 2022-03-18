

#include <push_swap.h>

//contar número elementos en array y pasarlos todos a una lista enlazada
t_list *init_list(int *nums, int len)
{
	t_list *stack_a;
	int i;

	stack_a = ft_lstnew_pw(&nums[0], 0);
	i = 1;
	while (i < len)
	{
		ft_lstadd_back(&stack_a, ft_lstnew_pw(&nums[i], 0));
		i++;
	}
	return(stack_a);
}
