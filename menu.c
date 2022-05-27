#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "cadastra_piloto.h"
//#include "codigos_comuns.h"

int main() {
	int choice;
	printf("Escolha:\n");
	printf("1. Cadastrar.\n");
	printf("2. Editar.\n");
	printf("3. Excluir.\n");
	printf("4. Imprimir.\n");
	scanf("%i", &choice);
	
	switch(choice) {
		case 1:
			cadastrar_piloto();
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
	}
	
	return 0;
}