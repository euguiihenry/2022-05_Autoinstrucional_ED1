#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include "codigos_comuns.h"
#define TAM 20

// Carregando a funcao:
	void cadastrar_piloto();

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
	
	/* Variavel:
	======================================================================================================*/
		struct piloto p[TAM];

void cadastrar_piloto() {
	/* Variaveis:
	======================================================================================================*/
		int n; // Para uso no loop FOR.
		int answer; // Controle do DO WHILE.
		
	/* Lidando com o arquivo de piloto.txt:
	======================================================================================================*/
		// Abrindo:
			//abrir();
			
		// Setando o ponteiro ao final da ultima informacao:
			//fseek(filePointer, 0, SEEK_END);
			
	/* Impressao da Tarefa:
	======================================================================================================*/
		printf("\n\t\t ========== CADASTRAMENTO DE PILOTO ==========\n");
		
	/* Insercoes:
	======================================================================================================*/
		/* Coleta de Dados:
		==================================================================================================*/
			int cont;
			
			do {				
				/* Limpando o buffer do teclado:
				==========================================================================================*/
					fflush(stdin);
				
				/* Coleta:
				==========================================================================================*/
					/* Variavel de Controle (Se 0 = desativado, Se 1 = ativado)
					======================================================================================*/
						p[n].ativo = 1;
						
					/* Nome:
					======================================================================================*/
						do {
							printf("\t\t Insira o nome do piloto: ");
							fgets(p[n].nome, 50, stdin);
							
							if (p[n].nome == NULL) {
								cont = 0;
								printf("\nInsira algum dado do tipo texto!\n");
								
							} else {
								cont = 1;
							}
						} while (cont == 0);
						
					/* Nacionalidade:
					======================================================================================*/
						do {						
							printf("\t\t Insira a nacionalidade do piloto: ");
							fgets(p[n].nacionalidade, 30, stdin);
							
							if (p[n].nacionalidade[0] == NULL) {
								printf("\nInsira algum dado do tipo texto!\n");
								cont = 0;
								
							} else {
								cont = 1;
							}
						} while (cont == 0);
						
					/* Cor de Pele:
					======================================================================================*/
						do {
							printf("\t\t Insira a cor de pele do piloto: ");
							fgets(p[n].corPele, 30, stdin);
							
							if (p[n].corPele[0] == NULL) {
								printf("\nInsira algum dado do tipo texto!\n");
								cont = 0;
								
							} else {
								cont = 1;
							}
						} while (cont == 0);
						
					/* Cor dos Olhos:
					======================================================================================*/
						do {
							printf("\t\t Insira a cor dos olhos do piloto: ");
							fgets(p[n].corOlhos, 30, stdin);
							
							if (p[n].corOlhos[0] == NULL) {
								printf("\nInsira algum dado do tipo texto!\n");
								cont = 0;
								
							} else {
								cont = 1;
							}
						} while (cont == 0);
						
					/* Cor do Cabelo:
					======================================================================================*/
						do {
							printf("\t\t Insira a cor do cabelo do piloto: ");
							fgets(p[n].corCabelo, 30, stdin);
							
							if (p[n].corCabelo[0] == NULL) {
								printf("\nInsira algum dado do tipo texto!\n");
								cont = 0;
								
							} else {
								cont = 1;
							}
						} while (cont == 0);
						
					/* Altura:
					======================================================================================*/
						do {
							char aux[4];
							
							printf("\t\t Insira a altura do piloto: (cm) ");
							fgets(aux, 4, stdin);
							
							int x;
													
							for (x=0; x<4; x++) {
								if ((aux[x] >= 65 || aux[x] <= 90) || aux[x] == 44) {
									printf("\nInsira apenas numeros. E obedeca o formado em centimetros!\n");
									cont = 0;
									break;
								} 
							}
							
							if (aux[0] == NULL) {
								printf("\nInsira algum dado do tipo numerico!\n");
								cont = 0;
								
							} else {
								p[n].altura = aux;
								cont = 1;
							}
							
							/* Limpando o buffer do teclado:
							==============================================================================*/
								fflush(stdin);
							
						} while (cont == 0);
						
					/* Peso:
					======================================================================================*/
						do {
							char aux[4];
							
							printf("\t\t Insira o peso do piloto: ");
							fgets(aux, 4, stdin);
							
							int x;
													
							for (x=0; x<4; x++) {
								if ((aux[x] >= 65 || aux[x] <= 90) || aux[x] == 44) {
									printf("\nInsira apenas numeros.\n");
									cont = 0;
									break;
								} 
							}
							
							if (aux[0] == NULL) {
								printf("\nInsira algum dado do tipo numerico!\n");
								cont = 0;
								
							} else {
								p[n].peso = aux;
								cont = 1;
							}
							
							/* Limpando o buffer do teclado:
							==============================================================================*/
								fflush(stdin);
								
						} while (cont == 0);
						
					/* Idade:
					======================================================================================*/
						do {
							char aux[4];
							
							printf("\t\t Insira a idade do piloto: ");
							fgets(aux, 4, stdin);
							
							int x;
													
							for (x=0; x<4; x++) {
								if ((aux[x] >= 65 || aux[x] <= 90) || aux[x] == 44) {
									printf("\nInsira apenas numeros. E obedeca o formado em centimetros!\n");
									cont = 0;
									break;
								} 
							}
							
							if (aux[0] == NULL) {
								printf("\nInsira algum dado do tipo numerico!\n");
								cont = 0;
								
							} else {
								p[n].idade = aux;
								cont = 1;
							}
							
							/* Limpando o buffer do teclado:
							==============================================================================*/
								fflush(stdin);
								
						} while (cont == 0);
						
					/* Qtd de Campeonatos Ganhos:
					======================================================================================*/
						do {
							char aux[4];
							
							printf("\t\t Insira a quantidade de campeonatos ganhos pelo piloto: ");
							fgets(aux, 4, stdin);
							
							int x;
													
							for (x=0; x<4; x++) {
								if ((aux[x] >= 65 || aux[x] <= 90) || aux[x] == 44) {
									printf("\nInsira apenas numeros. E obedeca o formado em centimetros!\n");
									cont = 0;
									break;
								} 
							}
							
							if (aux == NULL) {
								printf("\nInsira algum dado do tipo numerico!\n");
								cont = 0;
								
							} else {
								p[n].qtdCampeonatosGanhos = aux;
								cont = 1;
							}
							
							/* Limpando o buffer do teclado:
							==============================================================================*/
								fflush(stdin);
								
						} while (cont == 0);
						
					/* Pole Position:
					======================================================================================*/
						do {
							char aux[4];
							
							printf("\t\t Insira a posicao de largada do piloto: ");
							fgets(aux, 4, stdin);
							
							int x;
													
							for (x=0; x<4; x++) {
								if ((aux[x] >= 65 || aux[x] <= 90) || aux[x] == 44) {
									printf("\nInsira apenas numeros. E obedeca o formado em centimetros!\n");
									cont = 0;
									break;
								} 
							}
							
							if (aux == NULL) {
								printf("\nInsira algum dado do tipo numerico!\n");
								cont = 0;
								
							} else {
								p[n].polePosition = aux;
								cont = 1;
							}
							
							/* Limpando o buffer do teclado:
							==============================================================================*/
								fflush(stdin);
								
						} while (cont == 0);
						
					/* Qtd de Voltas Mais Rapidas:
					======================================================================================*/
						do {
							char aux[4];
							
							printf("\t\t Insira a quantidade de voltas mais rapidas feitas pelo piloto: ");
							fgets(aux, 4, stdin);
							
							int x;
													
							for (x=0; x<4; x++) {
								if ((aux[x] >= 65 || aux[x] <= 90) || aux[x] == 44) {
									printf("\nInsira apenas numeros. E obedeca o formado em centimetros!\n");
									cont = 0;
									break;
								} 
							}
							
							if (aux == NULL) {
								printf("\nInsira algum dado do tipo numerico!\n");
								cont = 0;
								
							} else {
								p[n].qtdVoltasRap = aux;
								cont = 1;
							}
							
							/* Limpando o buffer do teclado:
							==============================================================================*/
								fflush(stdin);
								
						} while (cont == 0);
						
					/* Pulando uma linha:
					======================================================================================*/
						printf("\n");	
				
					/* Atualizando n:
					======================================================================================*/
						printf("Deseja cadastrar mais um piloto: (Digite '1' para sim OU '2' para nao)");
						scanf("%i", &answer);
						
						if (answer == 1) {
							n++;
							
						} else {
							printf("\nCadastramento finalizado!");
						}
			} while (answer == 1);
}