#include "push_swap.h"

//swap the first two elements at the top of a stack
/*
comprobaciones: que exista la lista, que haya suficientes argumentos
creamos una copia de la lista y asignamos memoria para un nodo auxiliar
intercambiar los data de los dos elementos contando con el aux
*/
int	*ft_swap(t_list **list, int type)
{
	t_list	*copy;
	t_list	*aux;
	int		items;

	if (!list)
		return (NULL);
	items = ft_lstsize(*list);
	if (items < 1)
		return (0);
	copy = *list;
	aux = malloc(sizeof(t_list));
	if (aux == NULL)
		return (aux);
	aux->next = NULL;
	aux->data = copy->next->data;
	copy->next->data = copy->data;
	copy->data = aux->data;
	if (type == 0)
		write(1, "sa\n", 3);
	if (type == 1)
		write(1, "sb\n", 3);
	ft_lstclear(&aux, free);
	return(0);
}

void	ft_swap_ss(t_list **list, int type)
{
	if (type == 2)
	{
		ft_swap(list, 0);
		ft_swap(list, 1);
		write(1, "ss\n", 3);
	}
}
