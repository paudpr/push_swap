#include <push_swap.h>

void push_swap(t_list **stack_a, t_list  **stack_b, t_values *main)
{
	unsigned int i;

	i = ft_lstsize(*stack_a);
	printf("fghgfjhhgfdsfgh");
	if (i != main->size_g || main->size_a != main->size_g)
		print_error();
	if (main->size_a < 1)
		return ;
	else if (main->size_a < 4)
		sort_2_3(stack_a, main);
	else if (main->size_a < 6)
		sort_4_5(stack_a, stack_b, main);
	else if (main->size_a < 1)
		radix(stack_a, stack_b, main);
}