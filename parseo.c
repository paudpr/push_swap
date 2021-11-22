#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include "push_swap.h"

char	*join_argv(int argc, char **argv);
char	*ft_strjoin(char const *s1, char const *s2);
int		check_valid_nums(char **nums);
int		ft_isdigit(int c);

int	main (int argc, char **argv)
{
	int		i;
	char	**split;
	char	*str;

	if (argc < 2)
		return (write(1, "Error número de argumentos\n", 27));		//devolver 0 por que tecnicamente es una lista
	i = 1;
	while (argv[i])
	{
		if (argv[i][0] == 0)
			return (write(1, "Error argumento NULL\n", 21));
		i++;
	}
	str = join_argv(argc, argv);
	split = ft_split(str, ' ');
	if (check_valid_nums(split) != 1)
		return (write(1, "Error no son dígitos\n", 21));


	write(1, "Sin errores\n", 12);
	return (0);
}

//joins arguments into a single string
/*
recoge los argumentos
hace una copia del primer argumento en str y empieza a iterar
por cada nuevo argumento asigna memoria a un auxiliar que contenga la string que tenemos
hasta entonces, la longitud del nuevo argumento que estamos leyendo + 2 -> uno para un espacio y otro para 0
comprueba la asignación de memoria
copia str a aux, y luego concatena el argumento que estamos leyendo y un espacio al final
terminarlo con un 0
asginar memoria para el nuevo str, igualar a aux y liberar aux para la siguiente vuelta. 
*/
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
	printf("%s\n", str);
	return (str);
}

int	ft_isdigit(int c)
{
	if (c > 47 && c < 58)
		return (1);
	return (0);
}

//returns 0 or 1 as a boolean
/*introduce los argumentos como un array de números y comprueba que sean números válidos
solo con dígitos. Devuelve 1 si es correcto o 0 si no lo es. 
Todavia son strings. Transformar al pasar por itoa*/
int	check_valid_nums(char **nums)
{
	int	i;
	int	j;

	i = 0;
	while (nums[i])
	{
		j = 0;
		if (nums[i][j] == '-' || nums[i][j] == '+')
			j++;
		while (nums[i][j])
		{
			if (ft_isdigit(nums[i][j] != 1))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
