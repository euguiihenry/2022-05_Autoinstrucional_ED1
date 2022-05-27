#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "cadastra_piloto.h"

int main() {
	int choice;
	printf("\t\t Escolha uma opcao:\n");
	printf("\t\t =========================================\n");
	printf("\t\t 1. Cadastrar.\n");
	printf("\t\t 2. Editar.\n");
	printf("\t\t 3. Excluir.\n");
	printf("\t\t 4. Imprimir.\n");
	printf("\n\t\t Opcao escolhida: ");
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