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
		
		void abrir_modoLeitura() {
			filePointer = fopen("arquivo_pilotos.txt", "r");
			
			if(filePointer == NULL) {
				printf("Erro! Arquivo não encontrado!");
				exit(1);       
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
		
		/* Variaveis:
		======================================================================================================*/
			/* Armazenamento:
			==================================================================================================*/
				char scriptWritten[25];
				
			/* Funcionamento Geral:
			==================================================================================================*/
				int n; 
				int answer; // Controle do DO WHILE.
			
		/* Lidando com o arquivo de piloto.txt:
		======================================================================================================*/
			// Abrindo:
				abrir_modoLeitura();
				
		/* Impressao da Tarefa:
		======================================================================================================*/
			printf("\n\t\t ============= EDICAO DE PILOTO =============\n");
			
		/* Buscando Dados no Arquivo:
		======================================================================================================*/
			//PRA QUANDO FOR INT ou FLOAT ou CHAR
    		//fscanf(file, "%s", equipes[i].nomeE);

		    //PRA QUANDO FOR STRING
		    //fgets(equipes[i].nomeE, 50, file);
		    
		    fgets(scriptWritten, 50, filePointer);
		    fgets()
		    
		    
		
		/* Insercoes:
		======================================================================================================*/
			/* Coleta de Dados:
			==================================================================================================*/
				//do {
					/* Variavel de controle:
					==========================================================================================*/
				//		int cont = 0;
						
					/* Limpando o buffer do teclado:
					==========================================================================================*/
				//		fflush(stdin);
					
					/* Coleta:
					==========================================================================================*/
						/* Variavel de Controle (Se 0 = desativado, Se 1 = ativado)
						======================================================================================*/
				//			p[n].ativo = 1;				  
	}