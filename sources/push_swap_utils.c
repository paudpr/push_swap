#include <push_swap.h>

static int	ft_atoi_long_spaces(const char *str, int *r)
{
	int	i;

	i = 0;
	while (str[i] == 32 || (str[i] > 8 && str[i] < 14))
		i++;
	if (str[i] == 45)
		*r = -1;
	while (str[i] == 45 || str[i] == 43)
		i++;
	return (i);
}

long	ft_atoi_long(const char *str)
{
	int		i;
	int		r;
	long	sol;

	r = 1;
	sol = 0;
	i = ft_atoi_long_spaces(str, &r);
	if (i >= 2)
	{
		print_error();
	}
	while (str[i] > 47 && str[i] < 58)
	{
		if (sol > 2147483647 && r == 1)
			return ((long)MAX_INT + 1);
		if (sol > 2147483648 && r == -1)
			return ((long)MIN_INT - 1);
		else
			sol = (sol * 10) + (str[i] - 48);
		i++;
	}
	return (sol * r);
}

void print_error(void)
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

void ft_free(t_list **list, t_values main, int index)
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


int check_sort(t_list **list, t_values *main)
{
	unsigned int i;

	i = 0;
	// printf("%d\n", i);
	// printf("%d\n", main->size_g);
	// printf("%d\n", *list[0]->data);
	while(i < main->size_g && list[0]->next != NULL)
	{
		if(*list[0]->data > *list[0]->next->data)
			return(0);
		//printf("*list[0]->data -> %d\n", *list[0]->data);
		list = &list[0]->next;
		i++;
	}
	return(1);
}





void	show_list(t_list *lst, int num)
{
	int	i;

	i = 0;
	if (lst == NULL)
	{
		write(1, "Lista vacía \n\n", 15);
		printf("\n ...................... \n\n");
		return ;
	}
	while (i < num && lst != NULL)
	{
		printf("DIRECTION: %p\nData: %d\nNext node: %p\n\n", &lst->data, *lst->data, lst->next);
		lst = lst->next;
		i++;
	}
	printf("\n ...................... \n\n");
}