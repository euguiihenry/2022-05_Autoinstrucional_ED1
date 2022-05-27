#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define TAM 20

/* Carregando funcoes:
==========================================================================================================*/
	void cadastrar_piloto();
	void abrir();
	void criar();
	void fechar();

/* Struct:
==========================================================================================================*/
	/* Estrutura:
	======================================================================================================*/
		struct piloto {
			int grupo;
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
	void cadastrar_piloto() {
		/* Variaveis:
		======================================================================================================*/
			int n; // Para uso no loop FOR.
			int answer; // Controle do DO WHILE.
			
		/* Lidando com o arquivo de piloto.txt:
		======================================================================================================*/
			// Abrindo:
				abrir();
				
			// Setando o ponteiro ao final da ultima informacao:
				fseek(filePointer, 0, SEEK_END);
				
		/* Impressao da Tarefa:
		======================================================================================================*/
			printf("\n\t\t ========== CADASTRAMENTO DE PILOTO ==========\n");
			
		/* Insercoes:
		======================================================================================================*/
			/* Coleta de Dados:
			==================================================================================================*/
				do {
					/* Variavel de controle:
					==========================================================================================*/
						int cont = 0;			
						
					/* Limpando o buffer do teclado:
					==========================================================================================*/
						fflush(stdin);
					
					/* Coleta:
					==========================================================================================*/
						/* Variavel do Grupo:
						======================================================================================*/
							p[n].grupo = n;
						
						/* Variavel de Controle (Se 0 = desativado, Se 1 = ativado)
						======================================================================================*/
							p[n].ativo = 1;
							
						/* Nome:
						======================================================================================*/
							do {
								char aux[50];
								cont = 0;
									
								printf("\n\t\t Insira o nome do piloto: ");
								fgets(aux, 50, stdin);
								
								if (strlen(aux) == 1) {
									printf("\n\t\t Insira algum dado do tipo texto!\n");
									cont = 1;
								} else {
									for(int x=0; x<strlen(aux); x++) {
										p[n].nome[x] = aux[x];
									}
									cont = 2;
								}
								
							} while (cont < 2);
							
						/* Nacionalidade:
						======================================================================================*/
							do {
								char aux[30];
								cont = 0;
														
								printf("\t\t Insira a nacionalidade do piloto: ");
								fgets(aux, 30, stdin);
								
								if (strlen(aux) == 1) {
									printf("\n\t\t Insira algum dado do tipo texto!\n\n");
									cont = 1;
									
								}else {
									for(int x=0; x<strlen(aux); x++) {
										p[n].nacionalidade[x] = aux[x];
									}
									cont = 2;	
								}
							} while (cont < 2);
							
						/* Cor de Pele:
						======================================================================================*/
							do {
							char aux[30];
								cont = 0;
								
								printf("\t\t Insira a cor de pele do piloto: ");
								fgets(aux, 30, stdin);
								
								if (strlen(aux) == 1) {
									printf("\n\t\t Insira algum dado do tipo texto!\n\n");
									cont = 1;
									
								} else {
									for(int x=0; x<strlen(aux); x++) {
										p[n].corPele[x] = aux[x];
									}
									cont = 2;
								}
							} while (cont < 2);
							
						/* Cor dos Olhos:
						======================================================================================*/
							do {
								char aux[30];
								cont = 0;
								
								printf("\t\t Insira a cor dos olhos do piloto: ");
								fgets(aux, 30, stdin);
								
								if (strlen(aux) == 1) {
									printf("\n\t\t Insira algum dado do tipo texto!\n\n");
									cont = 1;
									
								} else {
									for(int x=0; x<strlen(aux); x++) {
										p[n].corOlhos[x] = aux[x];
									}
									cont = 2;
								}								
							} while (cont < 2);
							
						/* Cor do Cabelo:
						======================================================================================*/
							do {	
								char aux[30];
								cont = 0;
								
								printf("\t\t Insira a cor do cabelo do piloto: ");
								fgets(aux, 30, stdin);
								
								if (strlen(aux) == 1) {
									printf("\n\t\t Insira algum dado do tipo texto!\n\n");
									cont = 0;
									
								} else {
									for(int x=0; x<strlen(aux); x++) {
										p[n].corCabelo[x] = aux[x];
									}
									cont = 2;
								}
							} while (cont < 2);
							
						/* Altura:
						======================================================================================*/
							do {
								char aux[4];
								int entrada;
								cont = 0;
								
								printf("\t\t Insira a altura do piloto (cm): ");
								fgets(aux, 4, stdin);
								
								if (isdigit(aux[1])) {
									entrada = atoi(aux);
									p[n].altura = entrada;
									cont = 2;
								} else {
									printf("\n\t\t Insira apenas numeros. E obedeca o formado em centimetros!\n\n");
									cont = 1;
								}
								
								/* Limpando o buffer do teclado:
								==============================================================================*/
									fflush(stdin);
								
							} while (cont < 2);
							
						/* Peso:
						======================================================================================*/
							do {
								char aux[4];
								int entrada;
								cont = 0;
								
								printf("\t\t Insira o peso do piloto: ");
								fgets(aux, 4, stdin);
								
								if (isdigit(aux[1])) {
									entrada = atoi(aux);
									p[n].peso = entrada;
									cont = 2;
								} else {
									printf("\n\t\t Insira apenas numeros!\n\n");
									cont = 1;
								}
								
								/* Limpando o buffer do teclado:
								==============================================================================*/
									fflush(stdin);
									
							} while (cont < 2);
							
						/* Idade:
						======================================================================================*/
							do {	
								char aux[4];
								int entrada;
								cont = 0;
								
								printf("\t\t Insira a idade do piloto: ");
								fgets(aux, 4, stdin);
								
								if (isdigit(aux[1])) {
									entrada = atoi(aux);
									p[n].idade = entrada;
									cont = 2;
								} else {
									printf("\n\t\t Insira apenas numeros com dois decimais!\n\t\t Nao insira numeros quebrados\n\n");
									cont = 1;
								}
								
								/* Limpando o buffer do teclado:
								==============================================================================*/
									fflush(stdin);
									
							} while (cont < 2);
							
						/* Qtd de Campeonatos Ganhos:
						======================================================================================*/
							do {
								char aux[4];
								int entrada;
								cont = 0;
								
								printf("\t\t Insira a quantidade de campeonatos ganhos pelo piloto: ");
								fgets(aux, 4, stdin);
								
								if (isdigit(aux[0])) {
									entrada = atoi(aux);
									p[n].qtdCampeonatosGanhos = entrada;
									cont = 2;
								} else {
									printf("\n\t\t Insira apenas numeros!\n\n");
									cont = 1;
								}
								
								/* Limpando o buffer do teclado:
								==============================================================================*/
									fflush(stdin);
									
							} while (cont < 2);
							
						/* Pole Position:
						======================================================================================*/
							do {
								char aux[4];
								int entrada;
								cont = 0;
								
								printf("\t\t Insira a posicao de largada do piloto: ");
								fgets(aux, 4, stdin);
								
								if (isdigit(aux[0])) {
									entrada = atoi(aux);
									p[n].polePosition = entrada;
									cont = 2;
								} else {
									printf("\n\t\t Insira apenas numeros!\n\n");
									cont = 1;
								}
								
								/* Limpando o buffer do teclado:
								==============================================================================*/
									fflush(stdin);
									
							} while (cont < 2);
							
						/* Qtd de Voltas Mais Rapidas:
						======================================================================================*/
							do {
								char aux[4];
								int entrada;
								cont = 0;
								
								printf("\t\t Insira a quantidade de voltas mais rapidas feitas pelo piloto: ");
								fgets(aux, 4, stdin);
								
								if (isdigit(aux[0])) {
									entrada = atoi(aux);
									p[n].qtdVoltasRap = entrada;
									cont = 2;
								} else {
									printf("\n\t\t Insira apenas numeros!\n\n");
									cont = 1;
								}
								
								/* Limpando o buffer do teclado:
								==============================================================================*/
									fflush(stdin);
									
							} while (cont < 2);
							
						/* Pulando uma linha:
						======================================================================================*/
							printf("\n");	
					
						/* Inserindo dados no arquivo:
						======================================================================================*/
							fprintf(filePointer, "%i\n", p[n].grupo);
							fprintf(filePointer, "%i\n", p[n].ativo);
							fprintf(filePointer, "%s", p[n].nome);
							fprintf(filePointer, "%s", p[n].nacionalidade);
							fprintf(filePointer, "%s", p[n].corPele);
							fprintf(filePointer, "%s", p[n].corOlhos);
							fprintf(filePointer, "%s", p[n].corCabelo);
							fprintf(filePointer, "%i\n", p[n].altura);
							fprintf(filePointer, "%i\n", p[n].peso);
							fprintf(filePointer, "%i\n", p[n].idade);
							fprintf(filePointer, "%i\n", p[n].qtdCampeonatosGanhos);
							fprintf(filePointer, "%i\n", p[n].polePosition);
							fprintf(filePointer, "%i\r\n", p[n].qtdVoltasRap);
						
						/* Atualizando n:
						======================================================================================*/
							printf("\t\t Deseja cadastrar mais um piloto\n\t\t (Digite '1' para sim OU '2' para nao): ");
							scanf("%i", &answer);
							
							if (answer == 1) {
								n++;
								
							} else {
								printf("\n\t\t Cadastramento finalizado!");
							}
				} while (answer == 1);
				
				fechar();
	}