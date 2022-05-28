#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/* Carregando funcoes:
==========================================================================================================*/
	void abrir();
	void abrir_modoLeitura();
	void criar();
	void fechar();

/* Lidando com arquivos:
==========================================================================================================*/	
	/* Variaveis Globais:
	======================================================================================================*/
		FILE *filePointer;
		int total_linhas = 0;
		int last_group;
		
	/* Funcoes:
	======================================================================================================*/
		void abrir(char const *nome) {
			filePointer = fopen(nome, "r+");
			
			char const *inserted_name;
			
			if(filePointer == NULL) {
				filePointer = fopen(nome, "w");
				
				fechar();
				
				filePointer = fopen(nome, "r+");
				
				if(filePointer == NULL) {
					printf("Erro ao criar o arquivo!");   
					exit(1);             
				}            
			}
		}
		
		void criar(char const *nome) {
			filePointer = fopen(nome, "w");

			if(filePointer == NULL) {
				printf("Erro ao criar o arquivo!");   
				exit(1);             
			}
		}
		
		void recriar(char const *nome) {
			filePointer = fopen(nome, "a");
			
			if(filePointer == NULL) {
				printf("Erro ao recriar o arquivo!");   
				exit(1);  
			}
		}
		
		void abrir_modoLeitura(char const *nome) {
			filePointer = fopen(nome, "r");
			
			if(filePointer == NULL) {
				printf("\t\t Erro! Arquivo nao encontrado!");
				exit(1);       
			}
		}

		void fechar() {
			fclose(filePointer);
		}