#include <push_swap.h>

void sort_3(t_list **stack, t_values *main)
{
	int i;

	if(!stack)
		return ;
	i = ft_lstsize(*stack);
	if(i < 3)
	{
		if(check_sort(stack, main) == 0)
			ft_swap(stack, 0, main);
		return ;
	}
	while(check_sort(stack, main) == 0)
	{
		if(*stack[0]->data > *stack[0]->next->data &&
			*stack[0]->data > *stack[0]->next->next->data &&
			*stack[0]->next->data < *stack[0]->next->next->data)
			ft_rotate(stack);
		else if (*stack[0]->data > *stack[0]->next->data ||
			*stack[0]->data < *stack[0]->next->next->data)
			ft_swap(stack, 0, main);
		else if(*stack[0]->data < *stack[0]->next->data &&
			*stack[0]->data > *stack[0]->next->next->data)
			ft_rev_rotate(stack);
	}
}

void sort_4_5(t_list **stack_a, t_list **stack_b, t_values *main)
{
	int i;

	if(!stack_a)
		return ;
	i = ft_lstsize(*stack_a);
	if(i == 5)
		ft_push(stack_a, stack_b);
	ft_push(stack_a, stack_b);
	sort_3(stack_a, main);
	printf("size_b -> %d\n", main->size_b);

	//poner bien la cuenta de movimientos o esto no sale :(   )
	while(main->size_b != 0)
	{
		if(stack_a[0]->data < stack_b[0]->data)
		{
			printf("%d\n", *stack_a[0]->data);
			printf("%d\n", *stack_b[0]->data);
			printf("entro\n");
			ft_rev_rotate(stack_a);
		}
		ft_push(stack_b, stack_a);
		main->size_b--;
	}
	show_list(*stack_a, 6);



}