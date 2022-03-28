/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_arguments.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauladelpinoramirez <pauladelpinoramire    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:23:01 by pauladelpin       #+#    #+#             */
/*   Updated: 2022/03/28 17:11:57 by pauladelpin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

//checks argument is not NULL
int	check_valid_args(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (argv[i][0] == 0)
			print_error();
		i++;
	}
	return (1);
}

//joins arguments into a single string
char	*join_argv(int argc, char **argv)
{
	char	*str;
	char	*aux;
	int		i;

	i = 1;
	aux = ft_strdup(argv[1]);
	str = malloc(sizeof(char) * ft_strlen(aux));
	free(aux);
	aux = NULL;
	if (str == NULL)
		print_error();
	while (i < argc)
	{
		aux = ft_strjoin(str, " ");
		free(str);
		str = ft_strjoin(aux, argv[i]);
		free(aux);
		i++;
	}
	return (str);
}

//checks if there's argvs that are not numbers
int	check_valid_chars(char **nums)
{
	int	i;
	int	j;

	i = 0;
	while (nums[i])
	{
		j = 0;
		while (nums[i][j] == '-' || nums[i][j] == '+')
			j++;
		while (nums[i][j])
		{
			if (ft_isdigit(nums[i][j]) != 1)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

//gets **split and returns *nums with every value transformed into number value
int	*transform_to_nums(char **split)
{
	int	i;
	int	j;
	int	*nums;

	i = 0;
	while (split[i])
		i++;
	nums = malloc(sizeof(int) * i + 1);
	if (nums == NULL)
		return (nums);
	j = 0;
	while (j < i)
	{
		if (ft_atoi_long(split[j]) < MIN_INT
			|| ft_atoi_long(split[j]) > MAX_INT)
			print_error();
		nums[j] = ft_atoi_long(split[j]);
		j++;
	}
	return (nums);
}

//checks there are no duplicated numbers
int	check_duplicates(int *nums, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			if (j != i && nums[i] == nums[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
