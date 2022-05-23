#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void cadastramento_piloto();

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
	    int polePosition;				// Posição de iniciação na corrida.
	    int qtdVoltasRap;      			// Quantidade de voltas mais rápidas
	    
	};

// Funções:
	/* Cadastramento do Piloto: */
		void cadastramento_piloto() {
			// Definindo a estrutura a ser utilizada e seu apelido:
				struct piloto p;
				
			// Limpando o buffer do teclado:
			 	fflush(stdin);
				
			// Impressão de qual tarefa será realizada:
				printf("\n\t\t ======================== CADASTRAMENTO DE PILOTO ========================\n");
			
			// Inserções:
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
					printf("\t\t Insira a posição de largada do piloto: ");
					scanf("%i", &p.polePosition);
					
				// Qtd de Voltas Mais Rapidas:
					printf("\t\t Insira a quantidade de voltas mais rápidas feitas pelo piloto: ");
					scanf("%i", &p.qtdVoltasRap);
						
		}
	
	// Edição do Piloto:
		
	
	// Exclusão do Piloto:
		
	
	// Impressão do Piloto:
	
	// Functions:
		void write() {
			
		}
		
