#include <push_swap.h>

int binary(int data,  int bit)
{
	if(!data)
		return(0);
	data >>= bit;
	if(data & 1)
		return(1);
	else
		return(0);
}

void radix(t_list **stack_a, t_list **stack_b, t_values *main)
{
	int i;
	int bit;

	i = ft_lstsize(stack_a);
	if (check_sort(stack_a, main) == 1)
		return ;
	bit = 0;
	while(check_sort(stack_a, main != 1))
	{
		sort_radix(stack_a, stack_b, main, &bit);
	}
}

void sort_radix(t_list **stack_a, t_list **stack_b, t_values *main, int bit)
{
	t_list *copy;

	copy = *stack_a;
	if (ft_binary(copy->data, bit) == 0)
	{
		copy = copy->next;
		ft_push(*stack_a, *stack_b);
	}
	else
		copy = copy->next;
		ft_rev_rotate(stack_a);
}