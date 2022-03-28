#include <push_swap.h>

//swap the first two elements at the top of a stack
void	ft_swap(t_list **list, int type)
{
	t_list				*copy;
	t_list				*aux;
	unsigned int		items;

	if (!list)
		return ;
	items = ft_lstsize(*list);
	if (items < 1)
		return ;
	copy = *list;
	aux = malloc(sizeof(t_list));
	if (aux == NULL)
		return ;
	aux->data = copy->next->data;
	copy->next->data = copy->data;
	copy->data = aux->data;
	aux->index = copy->next->index;
	copy->next->index = copy->index;
	copy->index = aux->index;
	if (type == 0)
		write(1, "sa\n", 3);
	if (type == 1)
		write(1, "sb\n", 3);
	free(aux);
}

void	do_swap(t_list **stack_a, t_list **stack_b, int type)
{
	if (!stack_a || !stack_b)
		return ;
	if (type == 2)
	{
		ft_swap(stack_a, 2);
		ft_swap(stack_b, 2);
		write(1, "ss\n", 3);
	}
}
