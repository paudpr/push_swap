

#include <push_swap.h>

//contar número elementos en array y pasarlos todos a una lista enlazada
int init_list(int *nums, int len)
{
	t_list *list;
	t_list *aux;
	int i;

	// list = malloc(sizeof(t_list));
	// if (list == NULL)
	// 	return(list);
	// i = 0;
	// list->data = nums[i];

	list = ft_lstnew(&nums[0]);
	i = 1;
	while (i < len)
	{
		aux = ft_lstnew(&nums[i]);
		ft_lstadd_front(&list, aux);
		//free(aux);
		i++;
	}
	return(0);
}
