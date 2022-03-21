#include <push_swap.h>

/* shift all elements of stack by one. first element becomes last */
void ft_rotate(t_list **list, int type)
{
	t_list *copy;
	unsigned int items;

	if (!list)
		return ;
	items = ft_lstsize(*list);
	if (items <= 1)
		return ;
	copy = *list;
	ft_lstadd_back(list, copy);
	*list = copy->next;
	copy->next = NULL;
	return ;	
	if (type == 0)
		write(1, "ra\n", 3);
	else if (type == 1)
		write(1, "rb\n", 3);
}

void ft_rev_rotate(t_list **list, int type)
{
	t_list *copy;
	t_list *aux;
	unsigned int i;
	unsigned int items;

	if(list == NULL)
		return ;
	items = ft_lstsize(*list);
	if (items <= 1)
		return ;
	aux = *list;
	i = 0;
	while (i < items - 1)
	{
		copy = aux;
		aux = aux->next;
		i++;
	}
	ft_lstadd_front(list, aux);
	copy->next = NULL;
	return ;
	if (type == 0)
		write(1, "rra\n", 4);
	else if (type == 1)
		write(1, "rrb\n", 4);
}

void do_rotate(t_list **stack_a, t_list **stack_b, int type)
{
	if(!stack_a || !stack_b)
		return ;
	if (type == 2)
	{
		ft_rotate(stack_a, 2);
		ft_rotate(stack_b, 2);
		write(1, "rr\n", 3);
	}
	if (type == 3)
	{
		ft_rev_rotate(stack_a, 3);
		ft_rev_rotate(stack_b, 3);
		write(1, "rrr\n", 4);
	}
	return ;
}