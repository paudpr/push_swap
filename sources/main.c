#include <push_swap.h>

void print_error(void);


int *main_check(int argc, char **argv, t_pepe *general)
{
	int		i;
	char	**split;
	char	*str;
	int		*nums;

	check_valid_args(argv);
	str = join_argv(argc, argv);
	split = ft_split(str, ' ');
	if (split == NULL)
		return (0);
	free(str);
	if (check_valid_chars(split) != 1)
		print_error();
		//return (write(1, "Error no son dígitos\n", 21));
	nums = transform_to_nums(split);
	i = 0;
	while (split[i])
		i++;
	general->size_g = i;
	if (check_duplicates(nums, i) != 1)
		print_error();
		//return (write(1, "Error están duplicados\n", 23));
	return (nums);
}

// int elements_in_array(int *nums)
// {
// 	int i;

// 	i = (sizeof(nums) / sizeof(int));
// 	return(i);
// }

void print_error(void)
{
	write(1, "Error\n", 6);
	exit(0);
}

int	main(int argc, char **argv)
{
	//int *nums;
	//int len;
	t_pepe	general;

	if (argc < 2)
		return (0);
	general.aux_nums = main_check(argc, argv, &general);
	//printf("sizeg : %d\n", general.size_g);
	//ft_print(general.aux_nums);
	//len = elements_in_array(nums);
	//elements_in_array(&general);
	
	return(0);
}
