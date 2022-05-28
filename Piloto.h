#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define TAM 20

/* Carregando funcoes:
==========================================================================================================*/
	void abrir();
	void abrir_modoLeitura();
	void criar();
	void fechar();
	void cadastrar_piloto();
	void editar_piloto();
	void excluir_piloto();
	void imprimir_piloto();
	void ehCraque();

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
			filePointer = fopen(nome, "a+");
			
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

/* Struct:
==========================================================================================================*/
	/* Estrutura:
	======================================================================================================*/
		struct piloto {
			int  grupo;
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

/* Funcionalidades:
==============================================================================================================*/	
	/* Funcao de Cadastramento:
	==========================================================================================================*/
		void cadastrar_piloto() {
			/* Variaveis:
			======================================================================================================*/
				int n; // Para uso no loop FOR.
				int answer; // Controle do DO WHILE.
				int length;
				int sizeFile;
				
				int group_counting;
				
			/* Lidando com o arquivo de piloto.txt:
			======================================================================================================*/
				// Abrindo:
					abrir("arquivo_pilotos.txt");
					
				// Setando o ponteiro ao final da ultima informacao:
					fseek(filePointer, 0, SEEK_END);
					
				// Atualizando o numero de grupos:
					group_counting = n;
				/*	
				 Reescrever o arquivo pegando o group_couting:
					sizeFile = ftell(filePointer);
					
					if (sizeFile != 0) {
						length = 0;
						
						while (!feof(filePointer)) {
					    	/* Grupo:
					    	==============================================================================================
								fscanf(filePointer, "%i\n", &p[length].grupo);
						    
						    /* Limpando Buffer:
						    ==============================================================================================
						   		fflush(stdin);
					    	
							/* Nome:
							==============================================================================================		    	
					    		fgets(p[length].nome, 50, filePointer);
					    	
					    	/* Nacionalidade:
							==============================================================================================
					    		fgets(p[length].nacionalidade, 30, filePointer);
					    	
					    	/* Cor de Pele:
							==============================================================================================
					    		fgets(p[length].corPele, 30, filePointer);
					    	
					    	/* Cor dos Olhos:
							==============================================================================================
					    		fgets(p[length].corOlhos, 30, filePointer);
					    	
					    	/* Cor dos Cabelos:
							==============================================================================================
					    		fgets(p[length].corCabelo, 30, filePointer);
					    	
					    	/* Limpando Buffer:
						    ==============================================================================================
						   		fflush(stdin);
					    	
					    	/* Altura:
							==============================================================================================
					    		fscanf(filePointer, "%i\n", &p[length].altura);
					    	                                
					    	/* Peso:
							==============================================================================================
					    		fscanf(filePointer, "%i\n", &p[length].peso);
					    	                                
					    	/* Idade:
							==============================================================================================
					    		fscanf(filePointer, "%i\n", &p[length].idade);
					    	
							/* Qtd Campeonatos Ganhos:
							==============================================================================================
					    		fscanf(filePointer, "%i\n", &p[length].qtdCampeonatosGanhos);
					    	
					    	/* Pole Position:
							==============================================================================================
					    		fscanf(filePointer, "%i\n", &p[length].polePosition);
					    	
					    	/* Qtd de Voltas Rapidas:
							==============================================================================================
					    		fscanf(filePointer, "%i\n", &p[length].qtdVoltasRap);	
					    	
					    	/* Atualizando o valor de length:
					    	==============================================================================================
					    		length++;
						}
						
						//printf("%i", length);
						
						// Fechando o modo leitura:
							fechar();
						
						// Criando um arquivo novo:
							recriar("arquivo_pilotos.txt");
						
							int a;
							a = 0;
							
							for (a=0; a<length; a++) {
								p[a].grupo = a;
								
								fprintf(filePointer, "%i\n", p[a].grupo);
								fprintf(filePointer, "%s", p[a].nome);
								fprintf(filePointer, "%s", p[a].nacionalidade);
								fprintf(filePointer, "%s", p[a].corPele);
								fprintf(filePointer, "%s", p[a].corOlhos);
								fprintf(filePointer, "%s", p[a].corCabelo);
								fprintf(filePointer, "%i\n", p[a].altura);
								fprintf(filePointer, "%i\n", p[a].peso);
								fprintf(filePointer, "%i\n", p[a].idade);
								fprintf(filePointer, "%i\n", p[a].qtdCampeonatosGanhos);
								fprintf(filePointer, "%i\n", p[a].polePosition);
								fprintf(filePointer, "%i\r\n", p[a].qtdVoltasRap);
							}
						
						// Fechando o arquivo do modo criar:
							fechar();
						
						/* Abrindo o arquivo no modo escrita e leitura:
						======================================================================================================
							abrir("arquivo_pilotos.txt");
						
						/* Setando o ponteiro na ultima linha:
						======================================================================================================
							fseek(filePointer, 0, SEEK_END);
							
							group_counting = a;
					
					} else {
						group_counting = 0;
					}
					*/
					
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
								p[n].grupo = group_counting;
								
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
									group_counting++;
									
								} else {
									printf("\n\t\t Cadastramento finalizado!");
								}
					} while (answer == 1);
					
					fechar();
		}

	/* Funcao de Edicao:
	==============================================================================================================*/	
		void editar_piloto() {
			//if (filePointer != NULL) {
				int size;
				
				/* Lidando com o arquivo de piloto.txt:
				==========================================================================================================*/
					/* Abrindo no modo de leitura:
					======================================================================================================*/
						abrir_modoLeitura("arquivo_pilotos.txt");
				
					/* Setando o ponteiro na ultima linha:
					======================================================================================================*/
						fseek(filePointer, 0, SEEK_END);
					
					/* Pegando o tamanho do arquivo:
					======================================================================================================*/	
						size = ftell(filePointer);
				
						if (size == 0) {
							printf("\n\t\t Arquivo vazio! Insira dados antes de tentar editar!\n"); 
							
							int final_answer;
							
							printf("\t\t Retornar ao menu anterior? (0 = NAO || 1 = SIM): ");
							scanf("%i", &final_answer);
							
							if (final_answer == 1) {
								system("cls"); // Corrigir para funcionamento com linux tbm!!!!
							}
							
							/* Fechando o arquivo:
							======================================================================================================*/
								fechar();
								
						} else {
							/* Variaveis:
							======================================================================================================*/
								/* Funcionamento Geral:
								==================================================================================================*/
									int m = 0; 
									int answer; // Controle do DO WHILE.
								
							/* Lidando com o arquivo de piloto.txt:
							======================================================================================================*/
								// Abrindo:
									abrir_modoLeitura("arquivo_pilotos.txt");
									
							/* Impressao da Tarefa:
							======================================================================================================*/
								printf("\n\t\t ============= EDICAO DE PILOTO =============\n");
								
							/* Buscando Dados no Arquivo:
							======================================================================================================*/
								//PRA QUANDO FOR INT ou FLOAT ou CHAR
					    		//fscanf(file, "%s", equipes[i].nomeE);
					
							    //PRA QUANDO FOR STRING
							    //fgets(equipes[i].nomeE, 50, file);
							     
							    while (!feof(filePointer)) {
							    	/* Grupo:
							    	==============================================================================================*/
										fscanf(filePointer, "%i\n", &p[m].grupo);
										printf("\t\t Grupo %i:\n\n", p[m].grupo);
								    
								    /* Limpando Buffer:
								    ==============================================================================================*/
								   		fflush(stdin);
							    	
									/* Nome:
									==============================================================================================*/		    	
							    		fgets(p[m].nome, 50, filePointer);
							    		printf("\t\t %s", p[m].nome);
							    	
							    	/* Nacionalidade:
									==============================================================================================*/
							    		fgets(p[m].nacionalidade, 30, filePointer);
							    		printf("\t\t %s", p[m].nacionalidade);
							    	
							    	/* Cor de Pele:
									==============================================================================================*/
							    		fgets(p[m].corPele, 30, filePointer);
							    		printf("\t\t %s", p[m].corPele);
							    	
							    	/* Cor dos Olhos:
									==============================================================================================*/
							    		fgets(p[m].corOlhos, 30, filePointer);
							    		printf("\t\t %s", p[m].corOlhos);
							    	
							    	/* Cor dos Cabelos:
									==============================================================================================*/
							    		fgets(p[m].corCabelo, 30, filePointer);
							    		printf("\t\t %s", p[m].corCabelo);
							    	
							    	/* Limpando Buffer:
								    ==============================================================================================*/
								   		fflush(stdin);
							    	
							    	/* Altura:
									==============================================================================================*/
							    		fscanf(filePointer, "%i\n", &p[m].altura);
							    		printf("\t\t %i\n", p[m].altura);
							    	                                
							    	/* Peso:
									==============================================================================================*/
							    		fscanf(filePointer, "%i\n", &p[m].peso);
							    		printf("\t\t %i\n", p[m].peso);
							    	                                
							    	/* Idade:
									==============================================================================================*/
							    		fscanf(filePointer, "%i\n", &p[m].idade);
							    		printf("\t\t %i\n", p[m].idade);
							    	
									/* Qtd Campeonatos Ganhos:
									==============================================================================================*/
							    		fscanf(filePointer, "%i\n", &p[m].qtdCampeonatosGanhos);
							    		printf("\t\t %i\n", p[m].qtdCampeonatosGanhos);
							    	
							    	/* Pole Position:
									==============================================================================================*/
							    		fscanf(filePointer, "%i\n", &p[m].polePosition);
							    		printf("\t\t %i\n", p[m].polePosition);
							    	
							    	/* Qtd de Voltas Rapidas:
									==============================================================================================*/
							    		fscanf(filePointer, "%i\n", &p[m].qtdVoltasRap);
							    		printf("\t\t %i\n\n", p[m].qtdVoltasRap);	
							    	
							    	/* Atualizando o valor de m:
							    	==============================================================================================*/
							    		m++;
								}
								
								/* Fechando o arquivo depois do uso:
								==================================================================================================*/
									fechar();
								
								/* Selecionando o Grupo de Edicao:
								==================================================================================================*/    
							    	int group;
							    	int editionOption;
							    	
							    	printf("\t\t Qual grupo deseja editar: ");
							    	scanf("%i", &group);    	
							    	
							    	for (int y=0; y<m; y++) {
							    		if(y == group) {
							    			/* Mostrando o Grupo Selecionado:
							    			====================================================================================*/
								    			printf("\n\t\t ======================================\n\t\t");
												printf("\n\t\t O grupo selecionado foi:\n");
												
												printf("\n\t\t 1. Nome: %s", p[y].nome);
												printf("\t\t 2. Nacionalidade: %s", p[y].nacionalidade);
												printf("\t\t 3. Cor de Pele: %s", p[y].corPele);
												printf("\t\t 4. Cor dos Olhos: %s", p[y].corOlhos);
												printf("\t\t 5. Cor do Cabelo: %s", p[y].corCabelo);
												printf("\t\t 6. Altura: %i\n", p[y].altura);
												printf("\t\t 7. Peso: %i\n", p[y].peso);
												printf("\t\t 8. Idade: %i\n", p[y].idade);
												printf("\t\t 9. Qtd de Campeonatos Ganhos: %i\n", p[y].qtdCampeonatosGanhos);
												printf("\t\t 10. Pole Position: %i\n", p[y].polePosition);
												printf("\t\t 11. Qtd de Voltas Rapidas: %i\r\n", p[y].qtdVoltasRap);
												
											/* Selecionado a opcao para edicao:
											====================================================================================*/
												printf("\n\t\t Selecione um numero para editar uma informacao: ");
												scanf("%i", &editionOption);
												
											/* Limpando o buffer do teclado:
											====================================================================================*/
												fflush(stdin);
										}
									}
									
									/* Editando:
									============================================================================================*/					
										int cont;
										
										switch (editionOption) {
											case 1:							
												do {
													char aux[50];
													cont = 0;
														
													printf("\n\t\t Insira o nome do piloto: ");
													fgets(aux, 50, stdin);
													
													if (strlen(aux) == 1) {
														printf("\n\t\t Insira algum dado do tipo texto!\n");
														cont = 1;
													} else {
														for(int x=0; x<strlen(p[group].nome); x++) {
															p[group].nome[x] = aux[x];
														}
														cont = 2;
													}
													
													/* Limpando o buffer do teclado:
													==============================================================================*/
														fflush(stdin);
												} while (cont < 2);
												
												break;
											case 2:
												do {
													char aux[30];
													cont = 0;
																			
													printf("\t\t Insira a nacionalidade do piloto: ");
													fgets(aux, 30, stdin);
													
													if (strlen(aux) == 1) {
														printf("\n\t\t Insira algum dado do tipo texto!\n\n");
														cont = 1;
														
													}else {
														for(int x=0; x<strlen(p[group].nacionalidade); x++) {
															p[group].nacionalidade[x] = aux[x];
														}
														cont = 2;	
													}
													
													/* Limpando o buffer do teclado:
													==============================================================================*/
														fflush(stdin);
												} while (cont < 2);
												
												break;
											case 3:
												do {
													char aux[30];
													cont = 0;
													
													printf("\t\t Insira a cor de pele do piloto: ");
													fgets(aux, 30, stdin);
													
													if (strlen(aux) == 1) {
														printf("\n\t\t Insira algum dado do tipo texto!\n\n");
														cont = 1;
														
													} else {
														for(int x=0; x<strlen(p[group].corPele); x++) {
															p[group].corPele[x] = aux[x];
														}
														cont = 2;
													}
													
													/* Limpando o buffer do teclado:
													==============================================================================*/
														fflush(stdin);
												} while (cont < 2);
												
												break;
											case 4:
												do {
													char aux[30];
													cont = 0;
													
													printf("\t\t Insira a cor dos olhos do piloto: ");
													fgets(aux, 30, stdin);
													
													if (strlen(aux) == 1) {
														printf("\n\t\t Insira algum dado do tipo texto!\n\n");
														cont = 1;
														
													} else {
														for(int x=0; x<strlen(p[group].corOlhos); x++) {
															p[group].corOlhos[x] = aux[x];
														}
														cont = 2;
													}								
												} while (cont < 2);
												
												/* Limpando o buffer do teclado:
												==============================================================================*/
													fflush(stdin);
												
												break;
											case 5:
												do {	
													char aux[30];
													cont = 0;
													
													printf("\t\t Insira a cor do cabelo do piloto: ");
													fgets(aux, 30, stdin);
													
													if (strlen(aux) == 1) {
														printf("\n\t\t Insira algum dado do tipo texto!\n\n");
														cont = 0;
														
													} else {
														for(int x=0; x<strlen(p[group].corCabelo); x++) {
															p[group].corCabelo[x] = aux[x];
														}
														cont = 2;
													}
													
													/* Limpando o buffer do teclado:
													==============================================================================*/
														fflush(stdin);
												} while (cont < 2);
												
												break;
											case 6:
												do {
													char aux[4];
													int entrada;
													cont = 0;
													
													printf("\t\t Insira a altura do piloto (cm): ");
													fgets(aux, 4, stdin);
													
													if (isdigit(aux[1])) {
														entrada = atoi(aux);
														p[group].altura = entrada;
														cont = 2;
													} else {
														printf("\n\t\t Insira apenas numeros. E obedeca o formado em centimetros!\n\n");
														cont = 1;
													}
													
													/* Limpando o buffer do teclado:
													==============================================================================*/
														fflush(stdin);
													
												} while (cont < 2);
												
												break;
											case 7:
												do {
													char aux[4];
													int entrada;
													cont = 0;
													
													printf("\t\t Insira o peso do piloto: ");
													fgets(aux, 4, stdin);
													
													if (isdigit(aux[1])) {
														entrada = atoi(aux);
														p[group].peso = entrada;
														cont = 2;
													} else {
														printf("\n\t\t Insira apenas numeros!\n\n");
														cont = 1;
													}
													
													/* Limpando o buffer do teclado:
													======================================================================================*/
														fflush(stdin);
														
												} while (cont < 2);
												
												break;
											case 8:
												do {	
													char aux[4];
													int entrada;
													cont = 0;
													
													printf("\t\t Insira a idade do piloto: ");
													fgets(aux, 4, stdin);
													
													if (isdigit(aux[1])) {
														entrada = atoi(aux);
														p[group].idade = entrada;
														cont = 2;
													} else {
														printf("\n\t\t Insira apenas numeros com dois decimais!\n\t\t Nao insira numeros quebrados\n\n");
														cont = 1;
													}
													
													/* Limpando o buffer do teclado:
													======================================================================================*/
														fflush(stdin);
														
												} while (cont < 2);
												
												break;
											case 9:
												do {
													char aux[4];
													int entrada;
													cont = 0;
													
													printf("\t\t Insira a quantidade de campeonatos ganhos pelo piloto: ");
													fgets(aux, 4, stdin);
													
													if (isdigit(aux[0])) {
														entrada = atoi(aux);
														p[group].qtdCampeonatosGanhos = entrada;
														cont = 2;
													} else {
														printf("\n\t\t Insira apenas numeros!\n\n");
														cont = 1;
													}
													
													/* Limpando o buffer do teclado:
													======================================================================================*/
														fflush(stdin);
														
												} while (cont < 2);
												
												break;
											case 10:
												do {
													char aux[4];
													int entrada;
													cont = 0;
													
													printf("\t\t Insira a posicao de largada do piloto: ");
													fgets(aux, 4, stdin);
													
													if (isdigit(aux[0])) {
														entrada = atoi(aux);
														p[group].polePosition = entrada;
														cont = 2;
													} else {
														printf("\n\t\t Insira apenas numeros!\n\n");
														cont = 1;
													}
													
													/* Limpando o buffer do teclado:
													======================================================================================*/
														fflush(stdin);
												
												} while (cont < 2);
												
												break;
											case 11:
												do {
													char aux[4];
													int entrada;
													cont = 0;
													
													printf("\t\t Insira a quantidade de voltas mais rapidas feitas pelo piloto: ");
													fgets(aux, 4, stdin);
													
													if (isdigit(aux[0])) {
														entrada = atoi(aux);
														p[group].qtdVoltasRap = entrada;
														cont = 2;
													} else {
														printf("\n\t\t Insira apenas numeros!\n\n");
														cont = 1;
													}
													
													/* Limpando o buffer do teclado:
													======================================================================================*/
														fflush(stdin);
														
												} while (cont < 2);
												
												break;					
										}
									
									/* Limpando o buffer do teclado:
									======================================================================================================*/
										fflush(stdin);
									
									/* Informando que os dados foram salvos na memoria temporaria:
									======================================================================================================*/
										printf("\n\n\t\t Novos dados registrados!");
										
								/* Gravando no arquivo txt:
								==========================================================================================================*/
									/* Recriando o arquivo:
									======================================================================================================*/
										criar("arquivo_pilotos.txt");
											
									/* Inserindo os dados:
									======================================================================================================*/	
										int z = 0;
										
										while (z < m) {
											p[z].grupo = z;
											
											fprintf(filePointer, "%i\n", p[z].grupo);
											fprintf(filePointer, "%s", p[z].nome);
											fprintf(filePointer, "%s", p[z].nacionalidade);
											fprintf(filePointer, "%s", p[z].corPele);
											fprintf(filePointer, "%s", p[z].corOlhos);
											fprintf(filePointer, "%s", p[z].corCabelo);
											fprintf(filePointer, "%i\n", p[z].altura);
											fprintf(filePointer, "%i\n", p[z].peso);
											fprintf(filePointer, "%i\n", p[z].idade);
											fprintf(filePointer, "%i\n", p[z].qtdCampeonatosGanhos);
											fprintf(filePointer, "%i\n", p[z].polePosition);
											fprintf(filePointer, "%i\r\n", p[z].qtdVoltasRap);
											
											z++;
										}
										
									/* Fechando o arquivo txt:
									======================================================================================================*/
										fechar();
										
									/* Informando que os dados foram salvos no arquivo com sucesso:
									======================================================================================================*/			  
										printf("\n\n\t\t Os novos dados foram salvos no arquivo com sucesso!\n\t\t Edicao finalizada!");
						}
			//}
		}
		
	/* Funcao de Edicao:
	======================================================================================================================*/
		void excluir_piloto() {
			//if (filePointer != NULL) {
				int size;
				
				/* Lidando com o arquivo de piloto.txt:
				==========================================================================================================*/
					/* Abrindo no modo de leitura:
					======================================================================================================*/
						abrir_modoLeitura("arquivo_pilotos.txt");
				
					/* Setando o ponteiro na ultima linha:
					======================================================================================================*/
						fseek(filePointer, 0, SEEK_END);
					
					/* Pegando o tamanho do arquivo:
					======================================================================================================*/	
						size = ftell(filePointer);
				
						if (size == 0) {
							printf("\n\t\t Arquivo vazio! Insira dados antes de tentar excluir!\n");
							
							int final_answer;
							
							printf("\t\t Retornar ao menu anterior? (0 = NAO || 1 = SIM): ");
							scanf("%i", &final_answer);
							
							if (final_answer == 1) {
								system("cls"); // Corrigir para funcionamento com linux tbm!!!!
							}  
							
							/* Fechando o arquivo:
							======================================================================================================*/
								fechar();
					} else {
						/* Limpando o buffer do teclado:
						==============================================================================================================*/
							fflush(stdin);
							
						/* Variaveis:
						======================================================================================================*/
							/* Funcionamento Geral:
							==================================================================================================*/
								int m = 0; 
								//int answer; // Controle do DO WHILE.
							
						/* Lidando com o arquivo de piloto.txt:
						======================================================================================================*/
							// Abrindo:
								abrir_modoLeitura("arquivo_pilotos.txt");
								
						/* Impressao da Tarefa:
						======================================================================================================*/
							printf("\n\t\t =========== EXCLUSAO DE PILOTO =============\n");
													   
						/* Buscando Dados no Arquivo:
						======================================================================================================*/
							//PRA QUANDO FOR INT ou FLOAT ou CHAR
				    		//fscanf(file, "%s", equipes[i].nomeE);
				
						    //PRA QUANDO FOR STRING
						    //fgets(equipes[i].nomeE, 50, file);
						     
						    while (!feof(filePointer)) {
						    	/* Grupo:
						    	==============================================================================================*/
									fscanf(filePointer, "%i\n", &p[m].grupo);
									printf("\t\t Grupo %i:\n\n", p[m].grupo);
							    
							    /* Limpando Buffer:
							    ==============================================================================================*/
							   		fflush(stdin);
						    	
								/* Nome:
								==============================================================================================*/		    	
						    		fgets(p[m].nome, 50, filePointer);
						    		printf("\t\t %s", p[m].nome);
						    	
						    	/* Nacionalidade:
								==============================================================================================*/
						    		fgets(p[m].nacionalidade, 30, filePointer);
						    		printf("\t\t %s", p[m].nacionalidade);
						    	
						    	/* Cor de Pele:
								==============================================================================================*/
						    		fgets(p[m].corPele, 30, filePointer);
						    		printf("\t\t %s", p[m].corPele);
						    	
						    	/* Cor dos Olhos:
								==============================================================================================*/
						    		fgets(p[m].corOlhos, 30, filePointer);
						    		printf("\t\t %s", p[m].corOlhos);
						    	
						    	/* Cor dos Cabelos:
								==============================================================================================*/
						    		fgets(p[m].corCabelo, 30, filePointer);
						    		printf("\t\t %s", p[m].corCabelo);
						    	
						    	/* Limpando Buffer:
							    ==============================================================================================*/
							   		fflush(stdin);
						    	
						    	/* Altura:
								==============================================================================================*/
						    		fscanf(filePointer, "%i\n", &p[m].altura);
						    		printf("\t\t %i\n", p[m].altura);
						    	                                
						    	/* Peso:
								==============================================================================================*/
						    		fscanf(filePointer, "%i\n", &p[m].peso);
						    		printf("\t\t %i\n", p[m].peso);
						    	                                
						    	/* Idade:
								==============================================================================================*/
						    		fscanf(filePointer, "%i\n", &p[m].idade);
						    		printf("\t\t %i\n", p[m].idade);
						    	
								/* Qtd Campeonatos Ganhos:
								==============================================================================================*/
						    		fscanf(filePointer, "%i\n", &p[m].qtdCampeonatosGanhos);
						    		printf("\t\t %i\n", p[m].qtdCampeonatosGanhos);
						    	
						    	/* Pole Position:
								==============================================================================================*/
						    		fscanf(filePointer, "%i\n", &p[m].polePosition);
						    		printf("\t\t %i\n", p[m].polePosition);
						    	
						    	/* Qtd de Voltas Rapidas:
								==============================================================================================*/
						    		fscanf(filePointer, "%i\n", &p[m].qtdVoltasRap);
						    		printf("\t\t %i\n\n", p[m].qtdVoltasRap);	
						    	
						    	/* Atualizando o valor de m:
						    	==============================================================================================*/
						    		m++;
							}
							
							/* Fechando o arquivo depois do uso:
							==================================================================================================*/
								fechar();
							
							/* Selecionando o Grupo Para Exclusao:
							==================================================================================================*/    
						    	int group;
						    	int exclusionOption;
						    	
						    	printf("\t\t Qual grupo deseja excluir: ");
						    	scanf("%i", &group);
								
								for (int y=0; y<m; y++) {
						    		if(y == group) {
						    			/* Mostrando o Grupo Selecionado:
						    			======================================================================================*/
							    			printf("\n\t\t ======================================\n\t\t");
											printf("\n\t\t O grupo selecionado foi:\n");
											
											printf("\n\t\t Nome: %s", p[y].nome);
											printf("\t\t Nacionalidade: %s", p[y].nacionalidade);
											printf("\t\t Cor de Pele: %s", p[y].corPele);
											printf("\t\t Cor dos Olhos: %s", p[y].corOlhos);
											printf("\t\t Cor do Cabelo: %s", p[y].corCabelo);
											printf("\t\t Altura: %i\n", p[y].altura);
											printf("\t\t Peso: %i\n", p[y].peso);
											printf("\t\t Idade: %i\n", p[y].idade);
											printf("\t\t Qtd de Campeonatos Ganhos: %i\n", p[y].qtdCampeonatosGanhos);
											printf("\t\t Pole Position: %i\n", p[y].polePosition);
											printf("\t\t Qtd de Voltas Rapidas: %i\r\n", p[y].qtdVoltasRap);
									}
								}
								
								/* Limpando o buffer do teclado:
								==============================================================================================*/
									fflush(stdin);
									
							/* Gravando no arquivo txt:
							==========================================================================================================*/
								/* Criando novamente o arquivo:
								======================================================================================================*/
									criar("arquivo_pilotos.txt");
										
								/* Inserindo os dados:
								======================================================================================================*/	
									int z = 0;
									int count_groups;
									
									while (z < m) {							
										if (z == group) {
											z++;
											count_groups = z;
											count_groups--;
										} else if (z < group) {
											count_groups = z;
										} else {
											count_groups = (z-1);
										}
										
										p[z].grupo = count_groups;
										
										fprintf(filePointer, "%i\n", p[z].grupo);
										fprintf(filePointer, "%s", p[z].nome);
										fprintf(filePointer, "%s", p[z].nacionalidade);
										fprintf(filePointer, "%s", p[z].corPele);
										fprintf(filePointer, "%s", p[z].corOlhos);
										fprintf(filePointer, "%s", p[z].corCabelo);
										fprintf(filePointer, "%i\n", p[z].altura);
										fprintf(filePointer, "%i\n", p[z].peso);
										fprintf(filePointer, "%i\n", p[z].idade);
										fprintf(filePointer, "%i\n", p[z].qtdCampeonatosGanhos);
										fprintf(filePointer, "%i\n", p[z].polePosition);
										fprintf(filePointer, "%i\r\n", p[z].qtdVoltasRap);
										
										z++;
										count_groups++;
									}
								
								/* Fechando o arquivo txt:
								======================================================================================================*/	
									fechar();
								
								/* Caso Delete o Ultimo Grupo de Informacao:
								======================================================================================================*/		
									if (z == (m+1)) {
										/* Criando um novo arquivo vazio:
										==============================================================================================*/
											criar("arquivo_pilotos.txt");
										
										/* Fechando o arquivo txt:
										==============================================================================================*/
											fechar();
									}
									
								/* Informando que os dados foram salvos no arquivo com sucesso:
								======================================================================================================*/			  
									printf("\n\n\t\t Os novos dados foram salvos no arquivo com sucesso!\n\t\t Exclusao finalizada!");	
					}
			//}
			
		}
	
	/* Funcao de Impressao:
	======================================================================================================================*/
		void imprimir_piloto() {
			//if (filePointer != NULL) {
				int size;
				
				/* Lidando com o arquivo de piloto.txt:
				==========================================================================================================*/
					/* Abrindo no modo de leitura:
					======================================================================================================*/
						abrir_modoLeitura("arquivo_pilotos.txt");
				
					/* Setando o ponteiro na ultima linha:
					======================================================================================================*/
						fseek(filePointer, 0, SEEK_END);
					
					/* Pegando o tamanho do arquivo:
					======================================================================================================*/	
						size = ftell(filePointer);
				
						if (size == 0) {
							printf("\n\t\t Arquivo vazio! Insira dados antes de tentar imprimir!\n");
							
							int final_answer;
							
							printf("\t\t Retornar ao menu anterior? (0 = NAO || 1 = SIM): ");
							scanf("%i", &final_answer);
							
							if (final_answer == 1) {
								system("cls"); // Corrigir para funcionamento com linux tbm!!!!
							} 
							
							/* Fechando o arquivo:
							======================================================================================================*/
								fechar();
							
						} else {
							/* Limpando o buffer do teclado:
							======================================================================================================*/
								fflush(stdin);
								
							/* Variaveis:
							======================================================================================================*/
								/* Funcionamento Geral:
								==================================================================================================*/
									int m = 0; 
									int answer; // Controle
								
							/* Lidando com o arquivo de piloto.txt:
							======================================================================================================*/
								// Abrindo:
									abrir_modoLeitura("arquivo_pilotos.txt");
									
							/* Impressao da Tarefa:
							======================================================================================================*/
								printf("\n\t\t =========== IMPRESSAO DE PILOTO =============\n\n");
														   
							/* Buscando Dados no Arquivo:
							======================================================================================================*/
								//PRA QUANDO FOR INT ou FLOAT ou CHAR
					    		//fscanf(file, "%s", equipes[i].nomeE);
					
							    //PRA QUANDO FOR STRING
							    //fgets(equipes[i].nomeE, 50, file);
							     
							    while (!feof(filePointer)) {
							    	/* Grupo:
							    	==============================================================================================*/
										fscanf(filePointer, "%i\n", &p[m].grupo);
										printf("\t\t Grupo %i:\n\n", p[m].grupo);
								    
								    /* Limpando Buffer:
								    ==============================================================================================*/
								   		fflush(stdin);
							    	
									/* Nome:
									==============================================================================================*/		    	
							    		fgets(p[m].nome, 50, filePointer);
							    		printf("\t\t %s", p[m].nome);
							    	
							    	/* Nacionalidade:
									==============================================================================================*/
							    		fgets(p[m].nacionalidade, 30, filePointer);
							    		printf("\t\t %s", p[m].nacionalidade);
							    	
							    	/* Cor de Pele:
									==============================================================================================*/
							    		fgets(p[m].corPele, 30, filePointer);
							    		printf("\t\t %s", p[m].corPele);
							    	
							    	/* Cor dos Olhos:
									==============================================================================================*/
							    		fgets(p[m].corOlhos, 30, filePointer);
							    		printf("\t\t %s", p[m].corOlhos);
							    	
							    	/* Cor dos Cabelos:
									==============================================================================================*/
							    		fgets(p[m].corCabelo, 30, filePointer);
							    		printf("\t\t %s", p[m].corCabelo);
							    	
							    	/* Limpando Buffer:
								    ==============================================================================================*/
								   		fflush(stdin);
							    	
							    	/* Altura:
									==============================================================================================*/
							    		fscanf(filePointer, "%i\n", &p[m].altura);
							    		printf("\t\t %i\n", p[m].altura);
							    	                                
							    	/* Peso:
									==============================================================================================*/
							    		fscanf(filePointer, "%i\n", &p[m].peso);
							    		printf("\t\t %i\n", p[m].peso);
							    	                                
							    	/* Idade:
									==============================================================================================*/
							    		fscanf(filePointer, "%i\n", &p[m].idade);
							    		printf("\t\t %i\n", p[m].idade);
							    	
									/* Qtd Campeonatos Ganhos:
									==============================================================================================*/
							    		fscanf(filePointer, "%i\n", &p[m].qtdCampeonatosGanhos);
							    		printf("\t\t %i\n", p[m].qtdCampeonatosGanhos);
							    	
							    	/* Pole Position:
									==============================================================================================*/
							    		fscanf(filePointer, "%i\n", &p[m].polePosition);
							    		printf("\t\t %i\n", p[m].polePosition);
							    	
							    	/* Qtd de Voltas Rapidas:
									==============================================================================================*/
							    		fscanf(filePointer, "%i\n", &p[m].qtdVoltasRap);
							    		printf("\t\t %i\n\n", p[m].qtdVoltasRap);	
							    	
							    	/* Atualizando o valor de m:
							    	==============================================================================================*/
							    		m++;
								}
								
								printf("\t\t Retornar ao menu anterior? (0 = NAO || 1 = SIM): ");
								scanf("%i", &answer);
								
								if (answer == 1) {
									system("cls"); // Corrigir para funcionamento com linux tbm!!!!
								}
								
								/* Fechando o arquivo depois do uso:
								==================================================================================================*/
									fechar();
						}
			//}
		}
		
	/* Funcao Eh Craque:
	==============================================================================================================*/
		void ehCraque() { 

	        float calculo[20];
	        int controle[20];
	        float podio[3];
	        int b;
	        int qtdPilotos;
	        float maior;
	        int n;
	        int pilotoSelecionado[3];
	        
	        abrir("arquivo_pilotos.txt");
	        //qtdPilotos = reescrever();
			
			for(b = 0; b <= qtdPilotos; b++){
	            calculo[b] = p[b].qtdCampeonatosGanhos/p[b].idade;
	            controle[b] = 1; 
            }
			
			n = 0;
			
			while (n < 3 ) {
				maior = -9999999;
				
				for (b=0; b<qtdPilotos; b++) {
					if (maior < calculo[b] && controle[b] == 1) {
						maior = calculo[b];
						controle[b] = 0;
					}
				}
				
				podio[n] = calculo[b];
				pilotoSelecionado[n] = b;
				
				n++; 
			}
			
			for (b=0; b<n; b++) {
				printf("\n\t\t Podio de Pilotos:\n");
				printf("\n\t\t Piloto: %s", p[pilotoSelecionado[b]].nome);
				printf("\n\t\t Posicao do Podio: %i", (b+1));
				printf("\n\t\t Valor do Calculo: %f", podio[b]);
			}
        }
		 