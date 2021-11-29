#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include "push_swap.h"

char	*join_argv(int argc, char **argv);
int		check_valid_chars(char **nums);
int		ft_isdigit(int c);
int		check_duplicates(int *nums, int len);
int 	*transform_to_nums(char **split);

int	main (int argc, char **argv)
{
	int		i;
	char	**split;
	char	*str;
	int		*nums;
	
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
	free(str);
	if (check_valid_chars(split) != 1)
		return (write(1, "Error no son dígitos\n", 21));


	//por aqui hacer el atoi
	nums = transform_to_nums(split);
	///////////////////////////////////////////////////////////////////////////////////////
	//IMPRIME LO GUARRRRRRRRRDADO
	i = 0;
	while(nums[i])
	{
		printf("%d\n", nums[i]);
		i++;
	}


	if (check_duplicates(nums, i) != 1)
		return(write(1, "Error están duplicados\n", 23));
	write(1, "Sin errores\n", 12);
	return (0);

	//por aqui mapear
}

int *transform_to_nums(char **split)
{
	int i; 
	int j;
	int *nums;

	i = 0;
	while (split[i])
		i++;
	nums = malloc(sizeof(int) * i + 1);
	if (nums == NULL)
		return(nums);
	j = 0;
	while(j < i)
	{
		if (ft_atoi_long(split[j]) < MIN_INT || ft_atoi_long(split[j]) > MAX_INT)
			return (0);
		nums[j] = ft_atoi_long(split[j]);
		j++;
	}
	nums[j] = '\0';
	return(nums);
}

//joins arguments into a single string
/*recoge los argumentos
hace una copia del primer argumento en str y empieza a iterar
por cada nuevo argumento asigna memoria a un auxiliar que contenga la string que tenemos
hasta entonces, la longitud del nuevo argumento que estamos leyendo + 2 -> uno para un espacio y otro para 0
comprueba la asignación de memoria
copia str a aux, y luego concatena el argumento que estamos leyendo y un espacio al final
terminarlo con un 0
asginar memoria para el nuevo str, igualar a aux y liberar aux para la siguiente vuelta.*/
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
/*introduce los argumentos como un array de números y comprueba que sean números válidos
solo con dígitos o signos. Devuelve 1 si es correcto o 0 si no lo es. 
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

//checks there are no duplicated numbers
/*sin pasarse de la longitud de la cadena (cantidad de números que
tenemos) vamos comparando con todos los números que vienen detrás en la cadena
y devuelve un booleano*/
int check_duplicates(int *nums, int len)
{
	int i;
	int j;


	i = 0;
	while(i < len)
	{
		j = 0;
		while (j < len)
		{
			if (j != i && nums[i] == nums[j])
			{
				return(0);
			}
			j++;
		}
		i++;
	}
	return(1);
}
