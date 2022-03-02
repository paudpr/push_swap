#include <push_swap.h>

//swap the first two elements at the top of a stack
/*
comprobaciones: que exista la lista, que haya suficientes argumentos, 
que no haya más elementos que argumentos en total
creamos una copia de la lista y asignamos memoria para un nodo auxiliar
intercambiar los data de los dos elementos contando con el aux
*/
void	ft_swap(t_list **list, int type, t_values *main)
{
	t_list	*copy;
	t_list	*aux;
	unsigned int		items;
	
	if (!list)
		return ;
	items = ft_lstsize(*list);
	if (items > main->size_g)
		print_error();
	if (items < 1)
		return ;
	copy = *list;
	aux = malloc(sizeof(t_list));
	if (aux == NULL)
		return ;
	aux->data = copy->next->data;
	copy->next->data = copy->data;
	copy->data = aux->data;
	if (type == 0)
		write(1, "sa\n", 3);
	if (type == 1)
		write(1, "sb\n", 3);
	//ft_lstclear(&aux, free);
	free(aux);
}


void	do_swap_ss(t_list **stack_a, t_list **stack_b, int type, t_values *main)
{
	if (!stack_a || !stack_b)
		return ;
	if (type == 2)
	{
		ft_swap(stack_a, 2, main);
		ft_swap(stack_b, 2, main);
		write(1, "ss\n", 3);
	}
}
