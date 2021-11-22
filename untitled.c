#include <stdio.h>
#include <stdlib.h>

typedef struct s_numbers
{
		int number;
		struct s_numbers *next;
} t_numbers;

int main(void)
{
		t_numbers *list;
		t_numbers *num;

		//creacion del primer nodo
		list = malloc(sizeof(t_numbers));
		if (list == NULL)
				return(0);
		//(*num).number accede a la dirección encadenada aquí, y pon el número
		//se puede escribir también num->number
		(*list).number = 23;
		
		//creación del segundo nodo
		num = malloc(sizeof(t_numbers));
		if (num == NULL)
				return(0);
		list->next = num;
		num->number = 33;

		//creación del tercer nodo
		num = malloc(sizeof(t_numbers));
		if (num == NULL)
				return(0);
		list->next->next = num;
		num->number = 43;
		num->next = NULL;

		printf("DIRECTION: %p\nData: %d\nNext node: %p\n\n",&list, list->number, list->next);
		printf("DIRECTION: %p\nData: %d\nNext node: %p\n\n",&list->next->number, list->next->number, list->next->next);
		printf("DIRECTION: %p\nData: %d\nNext node: %p\n",&num->number, num->number, num->next);
		return(0);
}