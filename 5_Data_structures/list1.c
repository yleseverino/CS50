#include <stdio.h>
#include <stdlib.h>

// Represents a note
typedef struct node
{
	int number;
	struct node *next;
}node;


void free_memory (node *list);

void print_list (node *list);


int main (void)
{
	// List if size 0
	node *list = NULL;

	// Add number to list
	node *n = malloc(sizeof(node));
	if (n== NULL)
	{
		return 1;
	}
	n->number = 1;
	n->next = NULL;
	
	// Apontando a lista para a memoria alocada
	list = n;

	// Add another number to list
	n = malloc(sizeof(node));
	if (n == NULL)
	{
		return 1;
	}

	n->number = 2;
	n->next = NULL;

	// Apontando os ponteiros
	
	list->next = n;

	// Add another number to list
	n = malloc(sizeof(node));
	if (n == NULL)
	{
		return 1;
	}

	n->number = 3;
	n->next = NULL;

	list->next->next = n;

	print_list(list);
	free_memory(list);

}

// Print List
void print_list (node *list)
{
	for (node *tmp = list; tmp != NULL; tmp = tmp->next)
	{
		printf("%i\n", tmp->number);
	}
}

// Free memory
void free_memory (node *list)
{
	while (list != NULL)
	{
		node *tmp = list->next;
		free(list);
		list = tmp;
	}
}

