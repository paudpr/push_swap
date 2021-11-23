#include "push_swap.h"

void ft_swap(int *list, int len, int type)
{
	int aux;
	int i;

	if (!list)
		return(NULL);
	if (len < 2)
		return(0);
	if (type == 0)
		i = 0;
	if (type == 1)
		i = len * -1;
	aux = list[i];					//no funciona por que tiene índice negativo
	list[i] = list[i + 1];
	list[i + 1] = aux;
	if (type == 0)
		write(1, "sa\n", 3);
	if (type == 1)
		write(1, "sb\n", 3);
}

void ft_swap_ss(int *list, int len, int type)
{
	if (type == 2)
	{
		ft_swap(list, len, 0);
		ft_swap(list, len, 1);
		write(1, "ss\n", 3);
	}
}
