#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define MAX_INT 2147483647
# define MIN_INT -2147483648

# include <stdlib.h>
# include <libft.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>

typedef struct s_pepe
{
	int	size_g;
	int	size_a;
	int	size_b;
	int	*aux_nums;
}	t_pepe;

int		check_valid_args(char **argv);
char	*join_argv(int argc, char **argv);
int		check_valid_chars(char **nums);
int		*transform_to_nums(char **split);
int		check_duplicates(int *nums, int len);
long	ft_atoi_long(const char *str);
void	print_error(void);

#endif

