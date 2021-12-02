
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include <push_swap.h>


int	main (int argc, char **argv)
{
	int		i;
	char	**split;
	char	*str;
	int		*nums;
	int		len;
	
	if (argc < 2)
		return (write(1, "Error número de argumentos\n", 27));		//devolver 0 por que tecnicamente es una lista ordenada
	i = 1;
	while (argv[i])
	{
		if (argv[i][0] == 0)
			return (write(1, "Error argumento NULL\n", 21));
		i++;
	}
	str = join_argv(argc, argv);
	split = ft_split(str, ' ');
	if (split == NULL)
		return(0);
	len = 0;
	while(split[len])
		len++;
	free(str);
	if (check_valid_chars(split) != 1)
		return (write(1, "Error no son dígitos\n", 21));
	nums = transform_to_nums(split);
	if (check_duplicates(nums, len) != 1)
		return(write(1, "Error están duplicados\n", 23));
	write(1, "Sin errores\n", 12);
	return (0);
}