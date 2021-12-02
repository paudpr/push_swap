#include "push_swap.h"

void ft_rotate(t_list **list, int nbr, int type)
{
	t_list *copy;
	t_list *aux;
	int items;

	if (!list)
		return (NULL);
	items = ft_lstsize(*list);
	if (items < 1)
		return (0);
	copy = *list;
	aux = malloc(sizeof(t_list));
	if (aux == NULL)
		return(aux);
	aux = copy;
	while (lst->next)
		copy = copy->next;
	ft_lstadd_back(list, aux);
	if (type == 0)
		write(1, "ra\n", 3);
	if (type == 1)
		write(1, "rb\n", 3);
	ft_lstclear(&aux, free);
}

void ft_rotate_rr(t_list **list, int nbr, int type)
{
	if(type == 3)
	{
		ft_rotate(list, nbr, 0);
		ft_rotate(list, nbr, 1);
		write(1, "ss\n", 3);
	}
}
