#include <push_swap.h>

void sort_3(t_list **stack, t_values *main)
{
	int i;

	(void)main;
	if(!stack)
		return ;
	i = ft_lstsize(*stack);
	if (i != 3)
		return ;
	if(*stack[0]->data > *stack[0]->next->data && 
		*stack[0]->next->data < *stack[0]->next->next->data &&
		*stack[0]->data > *stack[0]->next->next->data)
			ft_rotate(stack);
	if(*stack[0]->next->data < *stack[0]->data &&
		*stack[0]->next->data > *stack[0]->next->next->data)
			ft_rev_rotate(stack);
	if(*stack[0]->next->data > *stack[0]->data &&
		*stack[0]->next->data < *stack[0]->next->next->data)
			ft_rev_rotate(stack);
	if(*stack[0]->data > *stack[0]->next->data &&
		*stack[0]->data < *stack[0]->next->next->data &&
		*stack[0]->next->data < *stack[0]->next->next->data)
			ft_swap(stack, 0, main);
	
	
}



/*
static void	ft_3sort(t_list **stack, int num)
{
	t_list	*temp;

	temp = *stack;
	if (is_sorted(stack, num) == 0)
		exit(0);
	if (temp->content > temp->next->content)
		ft_swap(stack, num, 0);
	if (temp->content > temp->next->next->content)
		ft_rrotate_down(stack, num, 0);
	if (is_sorted(stack, num) != 0)
	{
		ft_rrotate_down(stack, num, 0);
		if (is_sorted(stack, num) != 0)
			ft_swap(stack, num, 0);
	}
}*/