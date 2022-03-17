#include <push_swap.h>

void	sort_2_3(t_list **stack, t_values *main)
{
	int	i;

	if (!stack)
		return ;
	i = ft_lstsize(*stack);
	if (i < 3)
	{
		if (check_sort(stack, main) == 0)
			ft_swap(stack, 0, main);
		return ;
	}
	while (check_sort(stack, main) == 0)
	{
		if (*stack[0]->data > *stack[0]->next->data
			&& *stack[0]->data > *stack[0]->next->next->data
			&& *stack[0]->next->data < *stack[0]->next->next->data)
			ft_rotate(stack);
		if (*stack[0]->data > *stack[0]->next->data
			|| *stack[0]->data < *stack[0]->next->next->data)
			ft_swap(stack, 0, main);
		if (*stack[0]->data < *stack[0]->next->data
			&& *stack[0]->data > *stack[0]->next->next->data)
			ft_rev_rotate(stack);
	}
}

int	*find_smallest(t_list **stack)
{
	int		*nums;
	int		i;
	t_list	*copy;

	copy = *stack;
	nums = malloc(sizeof(int) * 2);
	i = ft_lstsize(*stack);
	nums[0] = 2147483647;
	while (i > 0)
	{
		if (nums[0] > *copy->data)
			nums[0] = *copy->data;
		copy = copy->next;
		i--;
	}
	copy = *stack;
	nums[1] = 2147483647;
	while (i < ft_lstsize(*stack))
	{
		if (nums[1] > *copy->data && nums[0] != *copy->data)
			nums[1] = *copy->data;
		copy = copy->next;
		i++;
	}
	return (nums);
}

void	sort_4_5(t_list **stack_a, t_list **stack_b, t_values *main)
{
	int	i;
	int	*nums;

	if (!stack_a)
		return ;
	i = 2;
	nums = find_smallest(stack_a);
	while (i > 0)
	{
		if (*stack_a[0]->data == nums[0] || *stack_a[0]->data == nums[1])
		{
			ft_push(stack_a, stack_b);
			i--;
		}
		else
			ft_rev_rotate(stack_a);
	}
	free(nums);
	sort_2_3(stack_a, main);
	i = 2;
	while (i > 0)
	{
		ft_push(stack_b, stack_a);
		i--;
	}
	if (*stack_a[0]->data > *stack_a[0]->next->data)
		ft_swap(stack_a, 0, main);
}
/*
void	sort_10(t_list **stack_a, t_list **stack_b, t_values *main)
{
	int	i;
	int	*nums;

	if (!stack_a)
		return ;
	i = 2;
	nums = find_smallest(stack_a);
	while (i > 0)
	{
		if (*stack_a[0]->data == nums[0] || *stack_a[0]->data == nums[1])
		{
			ft_push(stack_a, stack_b);
			i--;
		}
		else
			ft_rev_rotate(stack_a);
	}
	free(nums);
}
*/