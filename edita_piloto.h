#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define TAM 20

/* Carregando funcoes:
==========================================================================================================*/
	void editar_piloto();
	void abrir();
	void criar();
	void fechar();

/* Struct:
==========================================================================================================*/
	/* Estrutura:
	======================================================================================================*/
		struct piloto {
			int  ativo;
			char nome[50];
		    char nacionalidade[30];
		    char corPele[30];
		    char corOlhos[30];
		    char corCabelo[30];
		    int  altura;
		    int  peso;
		    int  idade;
		    int  qtdCampeonatosGanhos;
		    int  polePosition;				
			int  qtdVoltasRap;      			
		};
	
	/* Variavel Global 1:
	======================================================================================================*/
		struct piloto p[TAM];
	
/* Lidando com arquivos:
==========================================================================================================*/	
	/* Variavel Global 2:
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
/* Funcoes de Funcionalidades:
==========================================================================================================*/
	void editar_piloto() {
		
	}