#include "push_swap.h"

void	ft_swap(t_list **list, int nbr, int type)
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
}

void	ft_swap_ss(t_list **list, int nbr, int type)
{
	if (type == 2)
	{
		ft_swap(list, nbr, 0);
		ft_swap(list, nbr, 1);
		write(1, "ss\n", 3);
	}
}
