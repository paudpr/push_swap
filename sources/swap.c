#include <push_swap.h>

//swap the first two elements at the top of a stack
/*
comprobaciones: que exista la lista, que haya suficientes argumentos, 
que no haya más elementos que argumentos en total
creamos una copia de la lista y asignamos memoria para un nodo auxiliar
intercambiar los data de los dos elementos contando con el aux
*/
int	*ft_swap(t_list **list, int type, t_values main)
{
	t_list	*copy;
	t_list	*aux;
	int		items;

	if (!list)
		return (NULL);
	items = ft_lstsize(*list);
	if (items > main.size_g)
		print_error();
	if (items < 1)
		return (0);
	copy = *list;
	aux = malloc(sizeof(t_list));
	if (aux == NULL)
		return (NULL);
	aux->data = copy->next->data;
	copy->next->data = copy->data;
	copy->data = aux->data;
	if (type == 0)
		write(1, "sa\n", 3);
	if (type == 1)
		write(1, "sb\n", 3);
	ft_lstclear(&aux, free);
	return (0);
}

int	*ft_swap_ss(t_list **stack_a, t_list **stack_b, int type, t_values main)
{
	if (!stack_a || !stack_b)
		return (NULL);
	if (type == 2)
	{
		ft_swap(stack_a, 0, main);
		ft_swap(stack_b, 1, main);
		write(1, "ss\n", 3);
	}
	return (0);
}
