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
	if (index == 1)
		ft_lstclear(list, free);
	if (index == 0)
		free(main.aux_nums);
	if (index == 2)
	{
		ft_lstclear(list, free);
		free(main.aux_nums);
	}
}

void check_sort(t_list **list, t_values main)
{
	int i;

	i = 0;
	while(i < main.size_g && list->next != NULL)
	{
		if(list->data > list->next->data)
			return(1);
		list = list->next;
		i++;
	}
	return(0);
}