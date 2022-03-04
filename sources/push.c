#include <push_swap.h>

//take the first element of one stack to the top of the other stack
void ft_push(t_list **stack_orig, t_list **stack_dest)
{
	t_list *copy;

	if (stack_orig == NULL)
		return ;
	copy = *stack_orig;

	if(*stack_dest == NULL)
	{
		*stack_dest = ft_lstnew(stack_orig[0]->data);
		*stack_orig = copy->next;
	}
	else
	{
		ft_lstadd_front(stack_dest, ft_lstnew(stack_orig[0]->data));
		*stack_orig = copy->next;
		//show_list(*stack_dest, 10);
		//printf("\n\n");
		//show_list(*stack_orig, 10);
		//printf("\n\n");
	}
	free(copy);
	//printf("\nFIN PUSH\n");
}
