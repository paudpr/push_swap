static void	ft_2sort(t_list **stack, int num)
{
	t_list	*temp;

	temp = *stack;
	if (temp->content > temp->next->content)
		ft_swap(&temp, num, 0);
	else
		exit(0);
}

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
}

static void	ft_45sort(t_list **stack_a, t_list **stack_b, int num)
{
	t_list	*temp;

	if (is_sorted(stack_a, num) == 0)
		exit(0);
	while (ft_lstsize(*stack_b) < 2)
	{
		temp = *stack_a;
		if (temp->content == 1 || temp->content == 2)
			ft_push(stack_a, stack_b, num, 1);
		else
			ft_rotate_up(stack_a, num, 0);
	}
	if (is_sorted(stack_b, num) == 0)
		ft_swap(stack_b, num, 1);
	if (ft_lstsize(*stack_a) == 3 && is_sorted(stack_a, num) != 0)
		ft_3sort(stack_a, num);
	else if (ft_lstsize(*stack_a) == 2 && is_sorted(stack_a, num) != 0)
		ft_2sort(stack_a, num);
	ft_push(stack_b, stack_a, num, 0);
	ft_push(stack_b, stack_a, num, 0);
}
