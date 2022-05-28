#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define TAM 20

/* Carregando funcoes:
==========================================================================================================*/
	void cadastrar_carros();
	void abrir_arqCarro();
	void criar_arqCarro();
	void fechar_arqCarro();
	
/* Struct:
==========================================================================================================*/
	/* Estrutura:
	======================================================================================================*/
		struct carro {
			int grupo;
			char nome[51];
    		int comprimento;
    		int largura;
    		int altura;
    		int peso;
    		char marcaMotor[31];
    		char tipoMotor[31];
    		int aceleracao;
    		int capacidadeCombustivel;
    		int caixaCambio;
    		int aroRoda;
    		int qtdEtanol;
			
		};
		
		/* Variavel Global 1:
	======================================================================================================*/
		struct carro c[TAM];
	
/* Lidando com arquivos:
==========================================================================================================*/	
	/* Variavel Global 2:
	======================================================================================================*/
		FILE *filePointerCar;
		
	/* Funcoes:
	======================================================================================================*/
		void abrir_arqCarro() {
			filePointerCar = fopen("arquivo_carros.txt", "r+");
			
			if(filePointerCar == NULL) {
				criar_arqCarro();
				fechar_arqCarro();
				abrir_arqCarro();          
			}
		}
		
		void criar_arqCarro() {
			filePointerCar = fopen("arquivo_carros.txt", "w");

			if(filePointerCar == NULL) {
				printf("Erro ao criar o arquivo!");   
				exit(1);             
			}
		}

		void fechar_arqCarro() {
			fclose(filePointerCar);
		}
/* Funcoes de Funcionalidades:
==========================================================================================================*/	
	void cadastrar_carro() {
		/* Variaveis:
		======================================================================================================*/
			int n=0; // Para uso no loop FOR.
			int answer; // Controle do DO WHILE.
			
		/* Lidando com o arquivo de piloto.txt:
		======================================================================================================*/
			// Abrindo:
				abrir_arqCarro();
				
			// Setando o ponteiro ao final da ultima informacao:
				fseek(filePointerCar, 0, SEEK_END);
				
		/* Impressao da Tarefa:
		======================================================================================================*/
			printf("\n\t\t ========== CADASTRAMENTO DE PILOTO ==========\n");
			
		/* Insercoes:
		======================================================================================================*/
			/* Coleta de Dados:
			==================================================================================================*/
			do{
				
			/* Variavel de controle e auxiliares:
			==========================================================================================*/
				int cont = 0;
				int entrada;
				int x;			
						
			/* Limpando o buffer do teclado:
			==========================================================================================*/
				fflush(stdin);

				
				do {
								
								cont = 0;
								char aux[51];
								printf("\n\t\t Insira o nome do carro: ");
								fgets(aux, 51, stdin);
								
								if (strlen(aux) == 1) {
									printf("\n\t\t Insira algum dado do tipo texto!\n");
									cont = 1;
								} else {
									for(x=0; x<strlen(aux); x++) {
										c[n].nome[x] = aux[x];
									}
									cont = 2;
								}
								
							} while (cont < 2);
				
				
				do {
					cont = 0;
					char aux[4];			
					printf("\t\t Insira o comprimento aproximado do carro (cm): ");
					fgets(aux, 4, stdin);
								
					if (isdigit(aux[1])) {
						entrada = atoi(aux);
						c[n].comprimento = entrada;
						cont = 2;
					} else {
						printf("\n\t\t Insira apenas numeros. E obedeca o formato em centimetros!\n\n");
						cont = 1;
					}
								
					/* Limpando o buffer do teclado:
					==============================================================================*/
					fflush(stdin);
								
				} while (cont < 2);
				
				do {
					cont = 0;
					char aux[4];	
					printf("\t\t Insira a largura aproximada do carro (cm): ");
					fgets(aux, 4, stdin);
								
					if (isdigit(aux[1])) {
						entrada = atoi(aux);
						c[n].largura = entrada;
						cont = 2;
					} else {
						printf("\n\t\t Insira apenas numeros. E obedeca o formato em centimetros!\n\n");
						cont = 1;
					}
								
					/* Limpando o buffer do teclado:
					==============================================================================*/
					fflush(stdin);
								
				} while (cont < 2);
				
				do {
					cont = 0;
					char aux[4];			
					printf("\t\t Insira a altura aproximada do carro (cm): ");
					fgets(aux, 4, stdin);
								
					if (isdigit(aux[1])) {
						entrada = atoi(aux);
						c[n].altura = entrada;
						cont = 2;
					} else {
						printf("\n\t\t Insira apenas numeros. E obedeca o formato em centimetros!\n\n");
						cont = 1;
					}
								
					/* Limpando o buffer do teclado:
					==============================================================================*/
					fflush(stdin);
								
				} while (cont < 2);
				
				do {
					cont = 0;
					char aux[4];			
					printf("\t\t Insira o peso aproximado do carro (em kg): ");
					fgets(aux, 4, stdin);
								
					if (isdigit(aux[1])) {
						entrada = atoi(aux);
						c[n].peso = entrada;
						cont = 2;
					} else {
						printf("\n\t\t Insira apenas numeros. E desconsidere casas decimais!\n\n");
						cont = 1;
					}
								
					/* Limpando o buffer do teclado:
					==============================================================================*/
					fflush(stdin);
								
				} while (cont < 2);
				
				do{
					cont = 0;	
					char aux[31];		
					printf("\t\t Insira a marca do motor do carro: ");
					fgets(aux, 31, stdin);
								
					if (strlen(aux) == 1) {
						printf("\n\t\t Insira algum dado do tipo texto!\n");
						cont = 1;
					} else {
						for(x=0; x<strlen(aux); x++) {
							c[n].marcaMotor[x] = aux[x];
						}
							cont = 2;
					}
					
				} while (cont < 2);
				
				do{
					cont = 0;
					char aux[31];			
					printf("\t\t Insira o tipo do motor do carro: ");
					fgets(aux, 31, stdin);
								
					if (strlen(aux) == 1) {
						printf("\n\t\t Insira algum dado do tipo texto!\n");
						cont = 1;
					} else {
						for(x=0; x<strlen(aux); x++) {
							c[n].tipoMotor[x]= aux[x];
						}
							cont = 2;
					}
					
				} while (cont < 2);
				
				do {
					cont = 0;
					char aux[4];
								
					printf("\t\t Insira o valor da aceleracao do carro (apenas o valor de km): ");
					fgets(aux, 4, stdin);
								
					if (isdigit(aux[1])) {
						entrada = atoi(aux);
						c[n].aceleracao = entrada;
						cont = 2;
					} else {
						printf("\n\t\t Insira apenas numeros inteiros!\n");
						cont = 1;
					}
								
					/* Limpando o buffer do teclado:
					==============================================================================*/
					fflush(stdin);
								
				} while (cont < 2);
				
				do {
					cont = 0;
					char aux[4];			
					printf("\t\t Insira o capacidade do tanque de combustivel do carro (valor do volume em litros): ");
					fgets(aux, 4, stdin);
								
					if (isdigit(aux[1])) {
						entrada = atoi(aux);
						c[n].capacidadeCombustivel = entrada;
						cont = 2;
					} else {
						printf("\n\t\t Insira apenas numeros!E Desconsidere casas decimais\n");
						cont = 1;
					}
								
					/* Limpando o buffer do teclado:
					==============================================================================*/
					fflush(stdin);
								
				} while (cont < 2);
				
				do {
								char aux[2];
								cont = 0;
								
								printf("\t\t Insira a quantidade de marchas da caixa de cambio do carro: ");
								fgets(aux, 2, stdin);
								if (isdigit(aux[0])) {
									entrada = atoi(aux);
									c[n].caixaCambio = entrada;
									cont = 2;
								} else {
									printf("\n\t\t Insira apenas numeros!\n\n");
									cont = 1;
								}
								
								/* Limpando o buffer do teclado:
								==============================================================================*/
									fflush(stdin);
									
							} while (cont < 2);
				
				do {
					cont = 0;
					char aux[4];			
					printf("\t\t Insira o valor do aro da roda do carro (em polegadas): ");
					fgets(aux, 4, stdin);
								
					if (isdigit(aux[0])) {
						entrada = atoi(aux);
						c[n].aroRoda = entrada;
						cont = 2;
					} else {
						printf("\n\t\t Insira apenas numeros!E Desconsidere casas decimais\n");
						cont = 1;
					}
								
					/* Limpando o buffer do teclado:
					==============================================================================*/
					fflush(stdin);
								
				} while (cont < 2);
				
				do {
					cont = 0;
					char aux[4];			
					printf("\t\t Insira o valor do percentual de etanol do combustivel (de 0 a 100): ");
					fgets(aux, 4, stdin);
								
					if (isdigit(aux[1])) {
						entrada = atoi(aux);
						c[n].qtdEtanol = entrada;
						cont = 2;
					} else {
						printf("\n\t\t Insira apenas numeros!E Desconsidere casas decimais\n");
						cont = 1;
					}
								
					/* Limpando o buffer do teclado:
					==============================================================================*/
					fflush(stdin);
								
				} while (cont < 2);	
				/* Inserindo dados no arquivo:
				==================================================================================================*/
				fprintf(filePointerCar,"%i\n", c[n].grupo);
				fprintf(filePointerCar,"%s", c[n].nome);
				fprintf(filePointerCar,"%i\n", c[n].comprimento);
				fprintf(filePointerCar,"%i\n", c[n].largura);
				fprintf(filePointerCar,"%i\n", c[n].altura);
				fprintf(filePointerCar,"%i\n", c[n].peso);
				fprintf(filePointerCar,"%s", c[n].marcaMotor);
				fprintf(filePointerCar,"%s", c[n].tipoMotor);
				fprintf(filePointerCar,"%i\n", c[n].aceleracao);
				fprintf(filePointerCar,"%i\n", c[n].capacidadeCombustivel);
				fprintf(filePointerCar,"%i\n", c[n].caixaCambio);
				fprintf(filePointerCar,"%i\n", c[n].aroRoda);
				fprintf(filePointerCar,"%i\r\n", c[n].qtdEtanol);		
				/* Atualizando n:
				======================================================================================*/
				printf("\n\t\t Deseja cadastrar mais um carro\n\t\t (Digite '1' para sim OU '2' para nao): ");
				scanf("%i", &answer);
							
				if (answer == 1) {
					n++;
								
				} else {
					printf("\n\t\t Cadastramento finalizado!");
				}
							
					
				
			} while (answer == 1);
			
			fechar_arqCarro();
	}
	
			
			
			
			
			
			
			
			
