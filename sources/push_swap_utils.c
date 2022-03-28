/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauladelpinoramirez <pauladelpinoramire    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:23:04 by pauladelpin       #+#    #+#             */
/*   Updated: 2022/03/28 14:23:05 by pauladelpin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	print_error(void)
{
	write(1, "Error\n", 6);
	exit(0);
}

void	ft_free_double(char **tab, int n)
{
	if (tab[n - 1])
	{
		while (n >= 0)
			free(tab[n--]);
		free(tab);
	}
}

void	ft_free(t_list **list, t_values main, int index)
{
	if (index == 0)
		free(main.aux_nums);
	if (index == 1)
		ft_lstclear(list, free);
	if (index == 2)
	{
		ft_lstclear(list, free);
		free(main.aux_nums);
	}
}

int	check_sort(t_list **list, t_values *main)
{
	unsigned int	i;

	i = 0;
	while (i < main->size_g && list[0]->next != NULL)
	{
		if (list[0]->index > list[0]->next->index)
			return (0);
		list = &list[0]->next;
		i++;
	}
	return (1);
}

/*
void	show_list(t_list *lst, int num)
{
	int	i;

	if (lst == NULL)
	{
		write(1, "Lista vacía \n\n", 15);
		printf("\n ...................... \n\n");
		return ;
	}
	i = 0;
	printf("cabeza lista -> %p\n\n", lst);
	while (i < num && lst != NULL)
	{
		// printf("%p\n", &lst->data);
		//printf("%d\n",  *lst->data);
		// printf("%p\n", lst->next);
		printf("DIRECTION: %p\nData: %d\nNext node: %p\nIndex: 
			%d\n\n", &lst->data, *lst->data, lst->next, lst->index);
		lst = lst->next;
		i++;
	}
	printf("\n ...................... \n\n");
}
*/
