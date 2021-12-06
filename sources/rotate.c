#include <push_swap.h>

void ft_rotate(t_list **list, int type)
{
	t_list *copy;
	int items;

	if (!list)
		return ;
	items = ft_lstsize(*list);
	if (items < 0)
		return ;
	copy = *list;
	//show_list(copy, items);
	*list = copy->next;
	copy->next = NULL;
	// while(list->next)
	// 	copy = copy->next;
	ft_lstadd_back(list, copy);

	if (type == 0)
		write(1, "ra\n", 3);
	if (type == 1)
		write(1, "rb\n", 3);
	ft_lstclear(&copy, free);
	return ;	
}

void ft_rev_rotate(t_list **list, int type)
{
	t_list *copy;
	t_list *aux;
	unsigned int items;

	items = ft_lstsize(*list);
	if (items < 0)
		return ;
	copy = *list;
	while (items)
	{
		aux = copy;
		copy = copy->next;
		items--;
	}
	ft_lstadd_front(list, copy);
	aux->next = NULL;

	if (type == 0)
		write(1, "rra\n", 4);
	if (type == 1)
		write(1, "rrb\n", 4);
	ft_lstclear(&copy, free);
	return ;
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
