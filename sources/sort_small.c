#include <push_swap.h>

void	sort_3(t_list **stack, t_values *main)
{
	if (!stack)
		return ;
	if (check_sort(stack, main) == 0)
	{
		if (*stack[0]->next->next->data > *stack[0]->data)
			ft_swap(stack, 0);
		if (*stack[0]->data > *stack[0]->next->data
			&& *stack[0]->data > *stack[0]->next->next->data)
			ft_rotate(stack, 0);
		if (*stack[0]->data > *stack[0]->next->next->data
			&& *stack[0]->data < *stack[0]->next->data
			&& *stack[0]->next->data > *stack[0]->next->next->data)
			ft_rev_rotate(stack, 0);
		if (*stack[0]->data > *stack[0]->next->data
			&& *stack[0]->data < *stack[0]->next->next->data
			&& *stack[0]->next->data < *stack[0]->next->next->data)
			ft_swap(stack, 0);
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

void	small_push(t_list **stk_a, t_list **stk_b, int *nums, t_values *main)
{
	int	i;

	i = 2;
	if (ft_lstsize(*stk_a) == 4)
		i = 1;
	while (i > 0)
	{
		if (*stk_a[0]->data == nums[0] || *stk_a[0]->data == nums[1])
		{
			do_push(stk_a, stk_b, main, 0);
			i--;
		}
		else
			ft_rev_rotate(stk_a, 0);
	}
}

void	sort_4_5(t_list **stack_a, t_list **stack_b, t_values *main)
{
	int	i;
	int	*nums;

	if (!stack_a)
		return ;
	nums = find_smallest(stack_a);
	small_push(stack_a, stack_b, nums, main);
	free(nums);
	sort_3(stack_a, main);
	i = 2;
	while (i > 0)
	{
		do_push(stack_a, stack_b, main, 1);
		i--;
	}
	if (*stack_a[0]->data > *stack_a[0]->next->data)
		ft_swap(stack_a, 0);
}
