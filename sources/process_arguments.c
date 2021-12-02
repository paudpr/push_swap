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
/*recoge los argumentos y hace una copia del primer argumento
en str y empieza a iterar por cada nuevo argumento asigna memoria
a un auxiliar que contenga  la string que tenemos hasta entonces,
la longitud del nuevo  argumento que estamos leyendo + 2 -> uno para 
un espacio y otro para 0 comprueba la asignación de memoria copia str
a aux, y luego concatena el argumento que estamos leyendo y un espacio
al final terminarlo con un 0asginar memoria para el nuevo str, igualar
a aux y liberar aux para la siguiente vuelta.*/
char	*join_argv(int argc, char **argv)
{
	char	*str;
	char	*aux;
	int		i;

	i = 1;
	aux = ft_strdup(argv[1]);
	str = malloc(sizeof(char) * ft_strlen(aux));
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

//checks if there's that's not a number
/*introduce los argumentos como un array de números y comprueba 
que sean números válidossolo con dígitos o signos. Devuelve 1 
si es correcto o 0 si no lo es. 
Todavia son strings. Transformar al pasar por itoa.*/
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
/*recoge el array doble, cuenta el número de items que tiene
y aplica atoi a cada uno de los items para transformarlo en valor numérico.
Si sobrepasa MIN_INT o MAX_INT sale de la función.
Si hay signos repetidos devuelve error y sale de la función.*/
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
			exit(0);
		nums[j] = ft_atoi_long(split[j]);
		j++;
	}
	return (nums);
}

//checks there are no duplicated numbers
/*sin pasarse de la longitud de la cadena (cantidad de 
números que tenemos) vamos comparando con todos los números 
que vienen detrás en la cadena
y devuelve un booleano*/
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

//just a function to try things out and see how it's going
/*
void	ft_print(int *nums)
{
	size_t	i;

	i = -1;
	while (++i < 5)
		printf("num[%zu] : %d\n", i, nums[i]);
}
*/


/*se queda en standby porsiaca luego hace falta pero en principio
no lo necesito por que ya son números y eso es ordenable en si mismo
int do_mapping(int *nums)
{
	int i;	//guarda índice de más pequeño
	int j;	//sigue avanzando
	int map;	//indice en map
	int *map;

	i = 0;
	while (nums[i])
	{
		j = 0;
		map = 0;
		if (nums[i] < nums[j])
			j++;
		else (nums[i] > nums[j])
		{
			i = j;
			j++;
		}
		map[i] = k;
		k++;
		i++;
	}
}
*/
