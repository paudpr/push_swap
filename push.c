void ft_push(t_list **stack_a, t_list **stack_b, int nbr, int type)
{
	t_list *copy;
	t_list *aux;
	int aux;

	if (stack_b == NULL)
		return(0);
	copy = *stack_b;
	if(stack_a == NULL)
	{
		*stack_a = copy;
		aux = *stack_a;
		*stack_b = copy->next;
		copy->next = NULL;
	}
	else
	{
		aux = *stack_a;
		*stack_a = copy;
		*stack_b = copy->next;
		copy->next = aux;
	}






}