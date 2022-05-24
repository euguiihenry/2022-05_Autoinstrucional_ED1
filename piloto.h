#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void cadastramento_piloto();
void abrir();
void fechar();

// Variables:
	FILE *filePointer;

// Estrutura:
	struct piloto {
	    char nome[50];
	    char nacionalidade[30];
	    char corPele[30];
	    char corOlhos[30];
	    char corCabelo[30];
	    long altura;
	    int peso;
	    int idade;
	    int qtdCampeonatosGanhos;
	    int polePosition;				// PosiÃ§Ã£o de iniciaÃ§Ã£o na corrida.
	    int qtdVoltasRap;      			// Quantidade de voltas mais rÃ¡pidas

	};

// FunÃ§Ãµes:
	/* Handling with Files: 
	==========================================================================================================*/
		void abrir() {
			//fopen("fileopen","mode");
			filePointer = fopen("./TextFiles/pilotos.txt", "w");

			if(filePointer == NULL) {
				printf("Error!");   
				exit(1);             
			}
		}

		void fechar() {
			//fclose()
			fclose(filePointer);
		}

	/* Cadastramento do Piloto:
	==========================================================================================================*/
		void cadastramento_piloto() {
			// Definindo a estrutura a ser utilizada e seu apelido:
				struct piloto p;
			
			// Criando/Abrindo o Arquivo TXT:
				abrir();
			
			// Limpando o buffer do teclado:
				fflush(stdin);
				
			// ImpressÃ£o de qual tarefa serÃ¡ realizada:
				printf("\n\t\t ======================== CADASTRAMENTO DE PILOTO ========================\n");
			
			// InserÃ§Ãµes:
				// Nome:
					printf("\t\t Insira o nome do piloto: ");
					fgets(p.nome, 50, stdin);
					
				// Nacionalidade:
					printf("\t\t Insira a nacionalidade do piloto: ");
					fgets(p.nacionalidade, 30, stdin);
					
				// Cor de Pele:
					printf("\t\t Insira a cor de pele do piloto: ");
					fgets(p.corPele, 30, stdin);
					
				// Cor dos Olhos:
					printf("\t\t Insira a cor dos olhos do piloto: ");
					fgets(p.corOlhos, 30, stdin);
					
				// Cor do Cabelo:
					printf("\t\t Insira a cor do cabelo do piloto: ");
					fgets(p.corCabelo, 30, stdin);
					
				// Altura:
					printf("\t\t Insira a altura do piloto: ");
					scanf("%i", &p.altura);
					
				// Peso:
					printf("\t\t Insira o peso do piloto: ");
					scanf("%i", &p.peso);
					
				// Idade:
					printf("\t\t Insira a idade do piloto: ");
					scanf("%i", &p.idade);
					
				// Qtd de Campeonatos Ganhos:
					printf("\t\t Insira a quantidade de campeonatos ganhos pelo piloto: ");
					scanf("%i", &p.qtdCampeonatosGanhos);
					
				// Pole Position:
					printf("\t\t Insira a posiÃ§Ã£o de largada do piloto: ");
					scanf("%i", &p.polePosition);
					
				// Qtd de Voltas Mais Rapidas:
					printf("\t\t Insira a quantidade de voltas mais rÃ¡pidas feitas pelo piloto: ");
					scanf("%i", &p.qtdVoltasRap);
					
				// Integrando os dados ao arquivo:
					fprintf(filePointer, "%s", p.nome);
					
				//Fechando o arquivo TXT:
					fechar();
						
		}
	
	// Edicao do Piloto:
		
	
	// Exclusao do Piloto:
		
	
	// Impressao do Piloto:
		