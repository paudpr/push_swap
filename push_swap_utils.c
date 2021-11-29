#include "push_swap.h"

long	ft_atoi_long(const char *str)
{
	int		i;
	int		r;
	long	sol;

	i = 0;
	r = 1;
	sol = 0;
	while (str[i] == 32 || (str[i] > 8 && str[i] < 14))
		i++;
	while (str[i] == 45 || str[i] == 43)
	{
		if (str[i] == 45)
		{
			r = -1;
			if (i >= 2)
			{
				write(1, "Error de cantidad de signos\n", 28);
				exit (0);
			}
			i++;
		}
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
