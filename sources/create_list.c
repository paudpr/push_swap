

#include <push_swap.h>

//contar número elementos en array y pasarlos todos a una lista enlazada
t_list *init_list(int *nums, int len)
{
	t_list *list;
	//t_list *node;
	int i;

	//list = malloc(sizeof(t_list));
	list = ft_lstnew(&nums[0]);
	printf("IMPRIMIENDO &nums[i]   ->    %p\n", &nums[0]);
	i = 1;
	while (i < len)
	{
		printf("nums[%d] : %d\n", i, nums[i]);
		//node = ft_lstnew(&nums[i]);
		//printf("IMPRIMIENDO node   ->    %p\n", node);
		//ft_lstadd_front(&list, node);
		ft_lstadd_front(&list, ft_lstnew(&nums[i]));
		//free(node);
		i++;
	}
	return(list);
}

void	show_list(t_list *lst, int num)
{
	int	i;

	i = 0;
	if (lst == NULL)
		return ;
	while (i < num && lst != NULL)
	{
		printf("DIRECTION: %p\nData: %d\nNext node: %p\n\n", &lst->data, *lst->data, lst->next);
		lst = lst->next;
		i++;
	}
}