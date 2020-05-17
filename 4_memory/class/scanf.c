#include <stdio.h>

int main(void)
{
	int x;
	printf("x: \n");
	scanf("%i",&x); //o motivo de ter que passar o endereco é porque somente assim uma funcão consegue alterar variaveis que não sejam globais.
	printf("%i\n",x);
}

