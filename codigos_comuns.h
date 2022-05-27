#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/* Carregamento das funcoes:
==========================================================================================================*/
void abrir();
void criar();
void fechar();
	
/* Lidando com arquivos:
==========================================================================================================*/	
	/* Variavel:
	======================================================================================================*/
		FILE *filePointer;
		
	/* Funcoes:
	======================================================================================================*/
		void abrir() {
			filePointer = fopen("arquivo_pilotos.txt", "r+");
			
			if(filePointer == NULL) {
				criar();
				fechar();
				abrir();          
			}
		}
		
		void criar() {
			filePointer = fopen("arquivo_pilotos.txt", "w");

			if(filePointer == NULL) {
				printf("Erro ao criar o arquivo!");   
				exit(1);             
			}
		}

		void fechar() {
			fclose(filePointer);
		}
		
