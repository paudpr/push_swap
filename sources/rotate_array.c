#include "push_swap.h"

void ft_rotate(int *list, int len, int type)
{
	int aux;
	int i;

	if (type == 0)
		i = 0;
	if (type == 1)
		i = len * -1;
	aux = list[i];					//no funciona por que tiene índice negativo
	while(i < len - 1)
	{
		list[i] = list[i + 1];
		i++;
	}
	list[len] = aux;




}







