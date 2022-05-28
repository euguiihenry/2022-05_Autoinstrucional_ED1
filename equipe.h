#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define TAM 20

/* Carregando funcoes:
==========================================================================================================*/
	void cadastrar_equipe();
	void editar_equipe();
	void excluir_equipe();
	void imprimir_equipe();
	void criar_arqEquip();
	void fechar_arqEquip();
	void abrir_arqEquip();  
	void recriar_arqEquip();    
	void abrir_arqEquip_modoLeitura();
	int reescrever_equip();


/* Lidando com arquivos:
==========================================================================================================*/	
	/* Variavel Global 2:
	======================================================================================================*/
		FILE *filePointerEquip;
		
	/* Funcoes:
	======================================================================================================*/
		void abrir_arqEquip(char const *nome) {
			filePointerEquip = fopen(nome, "r+");
			
			char const *inserted_name;
			
			if(filePointerEquip == NULL) {
				filePointerEquip = fopen(nome, "w");
				
				fechar_arqEquip();
				
				filePointerEquip = fopen(nome, "r+");
				
				if(filePointerEquip == NULL) {
					printf("Erro ao criar o arquivo!");   
					exit(1);             
				}            
			}
		}
		
		void criar_arqEquip(char const *nome) {
			filePointerEquip = fopen(nome, "w");

			if(filePointerEquip == NULL) {
				printf("Erro ao criar o arquivo!");   
				exit(1);             
			}
		}
		
		void recriar_arqEquip(char const *nome) {
			filePointerEquip = fopen(nome, "a");
			
			if(filePointerEquip == NULL) {
				printf("Erro ao recriar o arquivo!");   
				exit(1);  
			}
		}

		void fechar_arqEquip() {
			fclose(filePointerEquip);
		}	
		
		void abrir_arqEquip_modoLeitura(char const *nome) {
			filePointerEquip = fopen(nome, "r");
			
			if(filePointerEquip == NULL) {
				printf("\t\t Erro! Arquivo nao encontrado!");
				exit(1);       
			}
		}

/* Struct:
==========================================================================================================*/
	/* Estrutura:
	======================================================================================================*/
		struct equipe {
			int  grupo;
	        char nome[50];
			char nacionalidade[30]; 
			int qtddMembros; 
			int qtddTitulosConstrutores; 
			int qtddTitulosCondutores; 
			int poliPositions; 
			int qtddVoltasMaisRap; 
			int valorMercado;
			int taxaIncricaoTemp; 
			char coresEquipe[30];
			char chefeEquipe[30]; 
			char diretorComercial[30]; 
			char diretorTecnico[30];
			char aeroDinamicChefe[30];
			char projetistaChefe[30]; 
			char chefePesqEhDev[30]; 
			char chefeMecanico[30]; 
			char tecnicoPneus[30];
			char tecnicoComponentes[30];
			char tecnicoTransmissao[30];
			char tecnicoCombustivel[30]; 
     		char mecanicosPitStop[21][30]; 
		};
		
	/* Variavel Global 1:
	======================================================================================================*/
		struct equipe e[TAM];
		

/* Funcionalidades:
==============================================================================================================*/	
	/* Funcao de Cadastramento:
	==========================================================================================================*/
		void cadastrar_equipe() {
			/* Variaveis:
			======================================================================================================*/
				int n; // Para uso no loop FOR.
				int answer; // Controle do DO WHILE.
				int group_counting1;

				
			/* Lidando com o arquivo de piloto.txt:
			======================================================================================================*/
				// Abrindo:
					abrir_arqEquip("arquivo_equipe.txt");
					
				// Setando o ponteiro ao final da ultima informacao:
					fseek(filePointerEquip, 0, SEEK_END);
					
					group_counting1 = reescrever_equip();

					
			/* Impressao da Tarefa:
			======================================================================================================*/
				printf("\n\t\t ========== CADASTRAMENTO DE EQUIPE ==========\n");
				
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
								e[n].grupo = group_counting1;

								
							/* Nome:
							======================================================================================*/
								do {
									char aux[50];
									cont = 0;
										
									printf("\n\t\t Insira o nome do equipe: ");
									fgets(aux, 50, stdin);
									
									if (strlen(aux) == 1) {
										printf("\n\t\t Insira algum dado do tipo texto!\n");
										cont = 1;
									} else {
										for(int x=0; x<strlen(aux); x++) {
											e[n].nome[x] = aux[x];
										}
										cont = 2;
									}
									
								} while (cont < 2);
								
							/* Nacionalidade:
							======================================================================================*/
								do {
									char aux[30];
									cont = 0;
															
									printf("\t\t Insira a nacionalidade do equipe: ");
									fgets(aux, 30, stdin);
									
									if (strlen(aux) == 1) {
										printf("\n\t\t Insira algum dado do tipo texto!\n\n");
										cont = 1;
										
									}else {
										for(int x=0; x<strlen(aux); x++) {
											e[n].nacionalidade[x] = aux[x];
										}
										cont = 2;	
									}
								} while (cont < 2);
								
							/* Quantidade de membros
							======================================================================================*/
								do {
									char aux[4];
									int entrada;
									cont = 0;
									
									printf("\t\t Insira a quantidade de membros: ");
									fgets(aux, 4, stdin);
									
									if (isdigit(aux[1])) {
										entrada = atoi(aux);
										e[n].qtddMembros = entrada;
										cont = 2;
									} else {
										printf("\n\t\t Insira apenas numeros!\n\n");
										cont = 1;
									}
									
									/* Limpando o buffer do teclado:
									==============================================================================*/
										fflush(stdin);
									
								} while (cont < 2);
								
									
							/* Quantidade de titulos dos contrutores
							======================================================================================*/
								do {
									char aux[4];
									int entrada;
									cont = 0;
									
									printf("\t\t Insira a quantidade de titulos dos contrutores: ");
									fgets(aux, 4, stdin);
									
									if (isdigit(aux[1])) {
										entrada = atoi(aux);
										e[n].qtddTitulosConstrutores  = entrada;
										cont = 2;
									} else {
										printf("\n\t\t Insira apenas numeros!\n\n");
										cont = 1;
									}
									
									/* Limpando o buffer do teclado:
									==============================================================================*/
										fflush(stdin);
									
								} while (cont < 2);
								
								
									
							/* Quantidade de titulos dos condutores
							======================================================================================*/
								do {
									char aux[4];
									int entrada;
									cont = 0;
									
									printf("\t\t Insira a quantidade de titulos dos condutores: ");
									fgets(aux, 4, stdin);
									
									if (isdigit(aux[1])) {
										entrada = atoi(aux);
										e[n].qtddTitulosCondutores = entrada;
										cont = 2;
									} else {
										printf("\n\t\t Insira apenas numeros!\n\n");
										cont = 1;
									}
									
									/* Limpando o buffer do teclado:
									==============================================================================*/
										fflush(stdin);
									
								} while (cont < 2);
								
									
							/* poli positions
							======================================================================================*/
								do {
									char aux[4];
									int entrada;
									cont = 0;
									
									printf("\t\t Insira o poli positions : ");
									fgets(aux, 4, stdin);
									
									if (isdigit(aux[1])) {
										entrada = atoi(aux);
										e[n].poliPositions  = entrada;
										cont = 2;
									} else {
										printf("\n\t\t Insira apenas numeros!\n\n");
										cont = 1;
									}
									
									/* Limpando o buffer do teclado:
									==============================================================================*/
										fflush(stdin);
									
								} while (cont < 2);
								
								
									
							/* Quantidade de voltas mais rapidas
							======================================================================================*/
								do {
									char aux[8];
									int entrada;
									cont = 0;
									
									printf("\t\t Insira a quantidade de voltas mais rapidas: ");
									fgets(aux, 8, stdin);
									
									if (isdigit(aux[1])) {
										entrada = atoi(aux);
										e[n].qtddVoltasMaisRap  = entrada;
										cont = 2;
									} else {
										printf("\n\t\t Insira apenas numeros!\n\n");
										cont = 1;
									}
									
									/* Limpando o buffer do teclado:
									==============================================================================*/
										fflush(stdin);
									
								} while (cont < 2);
								
								
								
									
							/* Valor do mercado
							======================================================================================*/
								do {
									char aux[10];
									int entrada;
									cont = 0;
									
									printf("\t\t Insira o valor de mercado: ");
									fgets(aux, 10, stdin);
									
									if (isdigit(aux[1])) {
										entrada = atoi(aux);
										e[n].valorMercado = entrada;
										cont = 2;
									} else {
										printf("\n\t\t Insira apenas numeros!\n\n");
										cont = 1;
									}
									
									/* Limpando o buffer do teclado:
									==============================================================================*/
										fflush(stdin);
									
								} while (cont < 2);
								
								
									
							/* Taxa de inscrição das temporadas
							======================================================================================*/
								do {
									char aux[10];
									int entrada;
									cont = 0;
									
									printf("\t\t Insira o valor da taxa de inscricao: ");
									fgets(aux, 10, stdin);
									
									if (isdigit(aux[1])) {
										entrada = atoi(aux);
										e[n].taxaIncricaoTemp  = entrada;
										cont = 2;
									} else {
										printf("\n\t\t Insira apenas numeros!\n\n");
										cont = 1;
									}
									
									/* Limpando o buffer do teclado:
									==============================================================================*/
										fflush(stdin);
									
								} while (cont < 2);
								
							/* Cores da equipe
							======================================================================================*/
								do {
									char aux[30];
									cont = 0;
															
									printf("\t\t Insira as cores da equipe: ");
									fgets(aux, 30, stdin);
									
									if (strlen(aux) == 1) {
										printf("\n\t\t Insira algum dado do tipo texto!\n");
										cont = 1;
									} else {
										for(int x=0; x<strlen(aux); x++) {
											e[n].coresEquipe[x] = aux[x];
										}
										cont = 2;
									}
								} while (cont < 2);			
								
									
							/* Chefe da equipe:
							======================================================================================*/
								do {
									char aux[30];
									cont = 0;
															
									printf("\t\t Insira o nome do chefe de equipe: ");
									fgets(aux, 30, stdin);
									
									if (strlen(aux) == 1) {
										printf("\n\t\t Insira algum dado do tipo texto!\n\n");
										cont = 1;
										
									}else {
										for(int x=0; x<strlen(aux); x++) {
											e[n].chefeEquipe[x] = aux[x];
										}
										cont = 2;	
									}
								} while (cont < 2);			
								
									
							/* Diretor comercial:
							======================================================================================*/
								do {
									char aux[30];
									cont = 0;
															
									printf("\t\t Insira o nome do diretor comercial: ");
									fgets(aux, 30, stdin);
									
									if (strlen(aux) == 1) {
										printf("\n\t\t Insira algum dado do tipo texto!\n\n");
										cont = 1;
										
									}else {
										for(int x=0; x<strlen(aux); x++) {
											e[n].diretorComercial[x] = aux[x];
										}
										cont = 2;	
									}
								} while (cont < 2);			
								
									
							/* Diretor tecnico:
							======================================================================================*/
								do {
									char aux[30];
									cont = 0;
															
									printf("\t\t Insira o nome do diretor tecnico: ");
									fgets(aux, 30, stdin);
									
									if (strlen(aux) == 1) {
										printf("\n\t\t Insira algum dado do tipo texto!\n\n");
										cont = 1;
										
									}else {
										for(int x=0; x<strlen(aux); x++) {
											e[n].diretorTecnico[x] = aux[x];
										}
										cont = 2;	
									}
								} while (cont < 2);			
								
									
							/* Chefe da aerodinamica:
							======================================================================================*/
								do {
									char aux[30];
									cont = 0;
															
									printf("\t\t Insira o nome do chefe da aereodinamica: ");
									fgets(aux, 30, stdin);
									
									if (strlen(aux) == 1) {
										printf("\n\t\t Insira algum dado do tipo texto!\n\n");
										cont = 1;
										
									}else {
										for(int x=0; x<strlen(aux); x++) {
											e[n].aeroDinamicChefe[x] = aux[x];
										}
										cont = 2;	
									}
								} while (cont < 2);			
								
									
							/* Projetista chefe:
							======================================================================================*/
								do {
									char aux[30];
									cont = 0;
															
									printf("\t\t Insira o nome do projetista chefe: ");
									fgets(aux, 30, stdin);
									
									if (strlen(aux) == 1) {
										printf("\n\t\t Insira algum dado do tipo texto!\n\n");
										cont = 1;
										
									}else {
										for(int x=0; x<strlen(aux); x++) {
											e[n].projetistaChefe[x] = aux[x];
										}
										cont = 2;	
									}
								} while (cont < 2);			
								
									
							/* Chefe de pesquisa e desenvolvimento:
							======================================================================================*/
								do {
									char aux[30];
									cont = 0;
															
									printf("\t\t Insira o nome do chefe de pesquisa e desenvolvimento: ");
									fgets(aux, 30, stdin);
									
									if (strlen(aux) == 1) {
										printf("\n\t\t Insira algum dado do tipo texto!\n\n");
										cont = 1;
										
									}else {
										for(int x=0; x<strlen(aux); x++) {
											e[n].chefePesqEhDev[x] = aux[x];
										}
										cont = 2;	
									}
								} while (cont < 2);			
								
									
							/* Chefe mecanico:
							======================================================================================*/
								do {
									char aux[30];
									cont = 0;
															
									printf("\t\t Insira o nome do chefe mecanico: ");
									fgets(aux, 30, stdin);
									
									if (strlen(aux) == 1) {
										printf("\n\t\t Insira algum dado do tipo texto!\n\n");
										cont = 1;
										
									}else {
										for(int x=0; x<strlen(aux); x++) {
											e[n].chefeMecanico[x] = aux[x];
										}
										cont = 2;	
									}
								} while (cont < 2);			
								
									
							/* Tecnico de pneus:
							======================================================================================*/
								do {
									char aux[30];
									cont = 0;
															
									printf("\t\t Insira o nome do tecnico de pneus: ");
									fgets(aux, 30, stdin);
									
									if (strlen(aux) == 1) {
										printf("\n\t\t Insira algum dado do tipo texto!\n\n");
										cont = 1;
										
									}else {
										for(int x=0; x<strlen(aux); x++) {
											e[n].tecnicoPneus[x] = aux[x];
										}
										cont = 2;	
									}
								} while (cont < 2);			
								
									
							/* Tecnico de componentes:
							======================================================================================*/
								do {
									char aux[30];
									cont = 0;
															
									printf("\t\t Insira o nome dos tecnico de componentes: ");
									fgets(aux, 30, stdin);
									
									if (strlen(aux) == 1) {
										printf("\n\t\t Insira algum dado do tipo texto!\n\n");
										cont = 1;
										
									}else {
										for(int x=0; x<strlen(aux); x++) {
											e[n].tecnicoComponentes[x] = aux[x];
										}
										cont = 2;	
									}
								} while (cont < 2);			
								
									
							/* Tecnico de transmissão:
							======================================================================================*/
								do {
									char aux[30];
									cont = 0;
															
									printf("\t\t Insira o nome do tecnico de transmissao: ");
									fgets(aux, 30, stdin);
									
									if (strlen(aux) == 1) {
										printf("\n\t\t Insira algum dado do tipo texto!\n\n");
										cont = 1;
										
									}else {
										for(int x=0; x<strlen(aux); x++) {
											e[n].tecnicoTransmissao[x] = aux[x];
										}
										cont = 2;	
									}
								} while (cont < 2);			
								
									
							/* Tecnico de combustiveis:
							======================================================================================*/
								do {
									char aux[30];
									cont = 0;
															
									printf("\t\t Insira o nome do tecnico de combustiveis: ");
									fgets(aux, 30, stdin);
									
									if (strlen(aux) == 1) {
										printf("\n\t\t Insira algum dado do tipo texto!\n\n");
										cont = 1;
										
									}else {
										for(int x=0; x<strlen(aux); x++) {
											e[n].tecnicoCombustivel[x] = aux[x];
										}
										cont = 2;	
									}
								} while (cont < 2);			
								
									
//							/* Mecanicos de pitstop:
//							======================================================================================*/
				    	for(int l = 0; l < 21; l++){
								do {
									char aux[30];
									cont = 0;
															
									printf("\t\t Insira os nomes do mecanicos de pitstop: ");
									fgets(aux, 30, stdin);
									
									if (strlen(aux) == 1) {
										printf("\n\t\t Insira algum dado do tipo texto!\n\n");
										cont = 1;
										
									}else {
										for(int x=0; x<strlen(aux); x++) {
											e[n].mecanicosPitStop[l][x] = aux[x];
										}
										cont = 2;	
									}
								} while (cont < 2);	
								
						}
								
							/* Pulando uma linha:
							======================================================================================*/
								printf("\n");	
						
							/* Inserindo dados no arquivo:
							======================================================================================*/
															
								fprintf(filePointerEquip, "%i\n", e[n].grupo);
								fprintf(filePointerEquip, "%s", e[n].nome);
								fprintf(filePointerEquip, "%s", e[n].nacionalidade);
								fprintf(filePointerEquip, "%i\n", e[n].qtddMembros);
								fprintf(filePointerEquip, "%i\n", e[n].qtddTitulosConstrutores );
								fprintf(filePointerEquip, "%i\n", e[n].qtddTitulosCondutores);
								fprintf(filePointerEquip, "%i\n", e[n].poliPositions);
								fprintf(filePointerEquip, "%i\n", e[n].qtddVoltasMaisRap);
								fprintf(filePointerEquip, "%i\n", e[n].valorMercado);
								fprintf(filePointerEquip, "%i\n", e[n].taxaIncricaoTemp );
								fprintf(filePointerEquip, "%s", e[n].coresEquipe);
								fprintf(filePointerEquip, "%s", e[n].chefeEquipe);
								fprintf(filePointerEquip, "%s", e[n].diretorComercial);
								fprintf(filePointerEquip, "%s", e[n].diretorTecnico);
								fprintf(filePointerEquip, "%s", e[n].aeroDinamicChefe);
								fprintf(filePointerEquip, "%s", e[n].projetistaChefe);
								fprintf(filePointerEquip, "%s", e[n].chefePesqEhDev);
								fprintf(filePointerEquip, "%s", e[n].chefeMecanico);
								fprintf(filePointerEquip, "%s", e[n].tecnicoPneus);
								fprintf(filePointerEquip, "%s", e[n].tecnicoComponentes);
								fprintf(filePointerEquip, "%s", e[n].tecnicoTransmissao);
								fprintf(filePointerEquip, "%s", e[n].tecnicoCombustivel);
							
							for(int l = 0; l < 21; l++){
								fprintf(filePointerEquip, "%s", e[n].mecanicosPitStop[l]);
							
						}
							/* Atualizando n:
							======================================================================================*/
								printf("Deseja cadastrar mais um piloto ? \n\t\t (Digite '1' para sim OU '2' para nao): ");
								scanf("%i", &answer);
								
								if (answer == 1) {
									n++;
									
								} else {
									printf("\n\t\t Cadastramento finalizado!");
								}
					} while (answer == 1);
					
					fechar_arqEquip();
		}

	/* Funcao de Edicao:
	==============================================================================================================*/	
		void editar_equipe() {
			/* Variaveis:
			======================================================================================================*/
				/* Funcionamento Geral:
				==================================================================================================*/
					int m = 0; 
					int answer; // Controle do DO WHILE.
				
			/* Lidando com o arquivo de piloto.txt:
			======================================================================================================*/
				// Abrindo:
					abrir_arqEquip_modoLeitura("arquivo_equipe.txt");
					
			/* Impressao da Tarefa:
			======================================================================================================*/
				printf("\n\t\t ============= EDICAO DE EQUIPE =============\n");
				
			     
			    while (!feof(filePointerEquip)) {
			    	/* Grupo:
			    	==============================================================================================*/
						fscanf(filePointerEquip, "%i\n", &e[m].grupo);
						printf("\t\t Grupo %i:\n\n", e[m].grupo);
				    
				    /* Limpando Buffer:
				    ==============================================================================================*/
				   		fflush(stdin);
			    	
					 /* Nome:
									==============================================================================================*/		    	
							    		fgets(e[m].nome, 50, filePointerEquip);
							    		printf("\t\t %s", e[m].nome);
							    	
							    	/* Nacionalidade:
									==============================================================================================*/
							    		fgets(e[m].nacionalidade, 30, filePointerEquip);
							    		printf("\t\t %s", e[m].nacionalidade);
							    		
							    	/* Limpando Buffer:
								    ==============================================================================================*/
								   		fflush(stdin);
							    	
							    	/* Quantidade de membros:
									==============================================================================================*/
							    		fscanf(filePointerEquip, "%i\n", &e[m].qtddMembros);
							    		printf("\t\t %i\n", e[m].qtddMembros);
							    	
							    	/* Quantidade de titulos dos contrutores:
									==============================================================================================*/
							    		fscanf(filePointerEquip, "%i\n", &e[m].qtddTitulosConstrutores );
							    		printf("\t\t %i\n", e[m].qtddTitulosConstrutores );
							    	
							    	/* Quantidade de titulos dos condutores
									==============================================================================================*/
							    		fscanf(filePointerEquip, "%i\n", &e[m].qtddTitulosCondutores);
							    		printf("\t\t %i\n", e[m].qtddTitulosCondutores);
							    		
							    		fflush(stdin);
							    	
							    	/* Poli Positions:
									==============================================================================================*/
							    		fscanf(filePointerEquip, "%i\n", &e[m].poliPositions);
							    		printf("\t\t %i\n", e[m].poliPositions);
							    	                                
							    	/* Quantidades de voltas mais rapidas:
									==============================================================================================*/
							    		fscanf(filePointerEquip, "%i\n", &e[m].qtddVoltasMaisRap );
							    		printf("\t\t %i\n", e[m].qtddVoltasMaisRap );
							    	 
									 /* Limpando Buffer:
				                    ==============================================================================================*/
				   		               fflush(stdin);            
										                     
							    	/* Valor do mercado:
									==============================================================================================*/
							    		fscanf(filePointerEquip, "%i\n", &e[m].valorMercado);
							    		printf("\t\t %i\n", e[m].valorMercado);
							    	
									/* Taxa de inscrição na temporada
									==============================================================================================*/
							    		fscanf(filePointerEquip, "%i\n", &e[m].taxaIncricaoTemp );
							    		printf("\t\t %i\n", e[m].taxaIncricaoTemp );
							    	
							    	/* Limpando Buffer:
								    ==============================================================================================*/
								   		fflush(stdin);
								   		
							    	/* Cores da equipe:
									==============================================================================================*/		    	
							    		fgets(e[m].coresEquipe, 30, filePointerEquip);
							    		printf("\t\t %s", e[m].coresEquipe);
							    	
							    	/* Chefe da equipe:
									==============================================================================================*/
							    		fgets(e[m].chefeEquipe, 30, filePointerEquip);
							    		printf("\t\t %s", e[m].chefeEquipe);
							    	
							    	/* Diretor Comercial:
									==============================================================================================*/		    	
							    		fgets(e[m].diretorComercial, 30, filePointerEquip);
							    		printf("\t\t %s", e[m].diretorComercial);
							    	
							    	/* Diretor Tecnico:
									==============================================================================================*/
							    		fgets(e[m].diretorTecnico, 30, filePointerEquip);
							    		printf("\t\t %s", e[m].diretorTecnico);
							    	
							    	/* Chefe aereo dinamico:
									==============================================================================================*/		    	
							    		fgets(e[m].aeroDinamicChefe, 30, filePointerEquip);
							    		printf("\t\t %s", e[m].aeroDinamicChefe);
							    	
							    	/* Chefe projetista:
									==============================================================================================*/
							    		fgets(e[m].projetistaChefe, 30, filePointerEquip);
							    		printf("\t\t %s", e[m].projetistaChefe);
							    		
							    	/* Chefe de pesquisa e desenvolvimento:
									==============================================================================================*/		    	
							    		fgets(e[m].chefePesqEhDev, 30, filePointerEquip);
							    		printf("\t\t %s", e[m].chefePesqEhDev);
							    	
							    	/* Chefe Mecanico:
									==============================================================================================*/
							    		fgets(e[m].chefeMecanico, 30, filePointerEquip);
							    		printf("\t\t %s", e[m].chefeMecanico);
							    		
							    	/* Tecnico de pneus:
									==============================================================================================*/		    	
							    		fgets(e[m].tecnicoPneus, 30, filePointerEquip);
							    		printf("\t\t %s", e[m].tecnicoPneus);
							    	
							    	/* Tecnico de componentes:
									==============================================================================================*/
							    		fgets(e[m].tecnicoComponentes, 30, filePointerEquip);
							    		printf("\t\t %s", e[m].tecnicoComponentes);
							    		
							    	/* Tecnico de transmissão:
									==============================================================================================*/		    	
							    		fgets(e[m].tecnicoTransmissao, 30, filePointerEquip);
							    		printf("\t\t %s", e[m].tecnicoTransmissao);
							    	
							    	/* Tecnico de combustivel:
									==============================================================================================*/
							    		fgets(e[m].tecnicoCombustivel, 30, filePointerEquip);
							    		printf("\t\t %s", e[m].tecnicoCombustivel);
							    		
							    	/* Limpando Buffer:
				                    ==============================================================================================*/
				   		                fflush(stdin);
							    		
							    	/* Mecanico de pit stop:
									==============================================================================================*/		    
									for(int l = 0; l < 21; l++){	
							    		fgets(e[m].mecanicosPitStop[l], 30, filePointerEquip);
							    		printf("\t\t %s", e[m].mecanicosPitStop[l]);
							    		fflush(stdin);
								    }
			    	/* Atualizando o valor de m:
			    	==============================================================================================*/
			    		m++;
				}
				
				/* Fechando o arquivo depois do uso:
				==================================================================================================*/
					fechar_arqEquip();
				
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
								
									printf("\n\t\t1- Nome: %s", e[y].nome);
									printf("\t\t2- Nacionalidade: %s", e[y].nacionalidade);
									printf("\t\t3- Quantidade de membros: %i\n", e[y].qtddMembros);
									printf("\t\t4- Quantidade de titulos dos contrutores: %i\n", e[y].qtddTitulosConstrutores);
									printf("\t\t5- Quantidade de titulos dos condutores: %i\n", e[y].qtddTitulosCondutores);
									printf("\t\t6- Poli Positions: %i\n", e[y].poliPositions );
									printf("\t\t7- Quantidade de voltas mais rapidas: %i\n", e[y].qtddVoltasMaisRap );
									printf("\t\t8- Valor do mercado: %i\n", e[y].valorMercado);
									printf("\t\t9- Valor da taxa de inscrição: %i\n", e[y].taxaIncricaoTemp );										
									printf("\t\t10- Cores de equipe: %s", e[y].coresEquipe);
									printf("\t\t11- Chefe de equipe: %s", e[y].chefeEquipe);
									printf("\t\t12- Diretor comercial: %s", e[y].diretorComercial);
									printf("\t\t13- Diretor tecnico: %s", e[y].diretorTecnico);
									printf("\t\t14- Chefe da aereo dinamica: %s", e[y].aeroDinamicChefe);
									printf("\t\t15- Projetista chefe: %s", e[y].projetistaChefe);
									printf("\t\t16- Chefe de pesquisa e desenvolvimento: %s", e[y].chefePesqEhDev);
									printf("\t\t17- Chefe mecanico: %s", e[y].chefeMecanico);
									printf("\t\t18- Tecnico de pneus: %s", e[y].tecnicoPneus);							
									printf("\t\t19- Tecnico de de componentes: %s", e[y].tecnicoComponentes);
									printf("\t\t20- Tecnico de transmissão: %s", e[y].tecnicoTransmissao);
									printf("\t\t21- Tecnico de combustivel: %s", e[y].tecnicoCombustivel);	
								
								for(int l = 0; l < 21; l++){
										
								     printf("\t\t22- Mecanicos de PitStop: %s", e[y].mecanicosPitStop[l]);
								     
								 }
								
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
														for(int x=0; x<strlen(aux); x++) {
															e[group].nome[x] = aux[x];
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
														for(int x=0; x<strlen(aux); x++) {
															e[group].nacionalidade[x] = aux[x];
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
													char aux[4];
													int entrada;
													cont = 0;
													
													printf("\t\t Insira a quantidade de membros: ");
													fgets(aux, 4, stdin);
													
													if (isdigit(aux[0])) {
														entrada = atoi(aux);
														e[group].qtddMembros = entrada;
														cont = 2;
													} else {
														printf("\n\t\t Insira apenas numeros!\n\n");
														cont = 1;
													}
													
													/* Limpando o buffer do teclado:
													==============================================================================*/
														fflush(stdin);
													
												} while (cont < 1);
												
												break;
											case 4:
												do {
													char aux[4];
													int entrada;
													cont = 0;
													
													printf("\t\t Insira a quantidade de titulos dos construtores: ");
													fgets(aux, 4, stdin);
													
													if (isdigit(aux[0])) {
														entrada = atoi(aux);
														e[group].qtddTitulosConstrutores  = entrada;
														cont = 2;
													} else {
														printf("\n\t\t Insira apenas numeros!\n\n");
														cont = 1;
													}
													
													/* Limpando o buffer do teclado:
													==============================================================================*/
														fflush(stdin);
													
												} while (cont < 1);
												
												break;
											case 5:
													do {
													char aux[4];
													int entrada;
													cont = 0;
													
													printf("\t\t Insira a quantidade de titulos dos condutores: ");
													fgets(aux, 4, stdin);
													
													if (isdigit(aux[0])) {
														entrada = atoi(aux);
														e[group].qtddTitulosCondutores = entrada;
														cont = 2;
													} else {
														printf("\n\t\t Insira apenas numeros!\n\n");
														cont = 1;
													}
													
													/* Limpando o buffer do teclado:
													==============================================================================*/
														fflush(stdin);
													
												} while (cont < 1);
												
												break;
											case 6:
													do {
													char aux[4];
													int entrada;
													cont = 0;
													
													printf("\t\t Insira a poli positions: ");
													fgets(aux, 4, stdin);
													
													if (isdigit(aux[0])) {
														entrada = atoi(aux);
														e[group].poliPositions  = entrada;
														cont = 2;
													} else {
														printf("\n\t\t Insira apenas numeros!\n\n");
														cont = 1;
													}
													
													/* Limpando o buffer do teclado:
													==============================================================================*/
														fflush(stdin);
													
												} while (cont < 1);
												
												break;
											case 7:
													do {
													char aux[4];
													int entrada;
													cont = 0;
													
													printf("\t\t Insira a quantidade de voltas mais rapidas: ");
													fgets(aux, 4, stdin);
													
													if (isdigit(aux[0])) {
														entrada = atoi(aux);
														e[group].qtddVoltasMaisRap  = entrada;
														cont = 2;
													} else {
														printf("\n\t\t Insira apenas numeros!\n\n");
														cont = 1;
													}
													
													/* Limpando o buffer do teclado:
													==============================================================================*/
														fflush(stdin);
													
												} while (cont < 1);
												
												break;
											case 8:
												do {
													char aux[10];
													int entrada;
													cont = 0;
													
													printf("\t\t Insira o valor da equipe: ");
													fgets(aux, 10, stdin);
													
													if (isdigit(aux[0])) {
														entrada = atoi(aux);
														e[group].valorMercado = entrada;
														cont = 2;
													} else {
														printf("\n\t\t Insira apenas numeros. E descarte valores fracionarios, caso possua, arredonde por favor!\n\n");
														cont = 1;
													}
													
													/* Limpando o buffer do teclado:
													==============================================================================*/
														fflush(stdin);
													
												} while (cont < 1);
												
												break;
											case 9:
												do {
													char aux[10];
													int entrada;
													cont = 0;
													
													printf("\t\t Insira o valor da taxa de inscricao da temporada: ");
													fgets(aux, 10, stdin);
													
													if (isdigit(aux[0])) {
														entrada = atoi(aux);
														e[group].taxaIncricaoTemp  = entrada;
														cont = 2;
													} else {
														printf("\n\t\t Insira apenas numeros. E descarte valores fracionarios, caso possua, arredonde por favor!\n\n");
														cont = 1;
													}
													
													/* Limpando o buffer do teclado:
													==============================================================================*/
														fflush(stdin);
													
												} while (cont < 1);
												
												break;
											case 10:
												do {
													char aux[30];
													cont = 0;
																			
													printf("\t\t Insira as cores da equipe: ");
													fgets(aux, 30, stdin);
													
													if (strlen(aux) == 1) {
														printf("\n\t\t Insira algum dado do tipo texto!\n\n");
														cont = 1;
														
													}else {
														for(int x=0; x<strlen(aux); x++) {
															e[group].coresEquipe[x] = aux[x];
														}
														cont = 2;	
													}
													
													/* Limpando o buffer do teclado:
													==============================================================================*/
														fflush(stdin);
														
												} while (cont < 2);
												
												break;
											case 11:
												do {
													char aux[30];
													cont = 0;
																			
													printf("\t\t Insira o nome do chefe de equipe: ");
													fgets(aux, 30, stdin);
													
													if (strlen(aux) == 1) {
														printf("\n\t\t Insira algum dado do tipo texto!\n\n");
														cont = 1;
														
													}else {
														for(int x=0; x<strlen(aux); x++) {
															e[group].chefeEquipe[x] = aux[x];
														}
														cont = 2;	
													}
													
													/* Limpando o buffer do teclado:
													==============================================================================*/
														fflush(stdin);
														
												} while (cont < 2);
												
												break;
											case 12:
												do {
													char aux[30];
													cont = 0;
																			
													printf("\t\t Insira o nome do diretor comercial: ");
													fgets(aux, 30, stdin);
													
													if (strlen(aux) == 1) {
														printf("\n\t\t Insira algum dado do tipo texto!\n\n");
														cont = 1;
														
													}else {
														for(int x=0; x<strlen(aux); x++) {
															e[group].diretorComercial[x] = aux[x];
														}
														cont = 2;	
													}
													
													/* Limpando o buffer do teclado:
													==============================================================================*/
														fflush(stdin);
														
												} while (cont < 2);
												
												break;
											case 13:
												do {
													char aux[30];
													cont = 0;
																			
													printf("\t\t Insira o nome do diretor tecnico: ");
													fgets(aux, 30, stdin);
													
													if (strlen(aux) == 1) {
														printf("\n\t\t Insira algum dado do tipo texto!\n\n");
														cont = 1;
														
													}else {
														for(int x=0; x<strlen(aux); x++) {
															e[group].diretorTecnico[x] = aux[x];
														}
														cont = 2;	
													}
													
													/* Limpando o buffer do teclado:
													==============================================================================*/
														fflush(stdin);
												} while (cont < 2);
												
												break;
											case 14:
												do {
													char aux[30];
													cont = 0;
																			
													printf("\t\t Insira o nome do chefe aerodinamico: ");
													fgets(aux, 30, stdin);
													
													if (strlen(aux) == 1) {
														printf("\n\t\t Insira algum dado do tipo texto!\n\n");
														cont = 1;
														
													}else {
														for(int x=0; x<strlen(aux); x++) {
															e[group].aeroDinamicChefe[x] = aux[x];
														}
														cont = 2;	
													}
													
													/* Limpando o buffer do teclado:
													==============================================================================*/
														fflush(stdin);
												} while (cont < 2);
												
												break;
											case 15:
												do {
													char aux[30];
													cont = 0;
																			
													printf("\t\t Insira o nome do projetista chefe: ");
													fgets(aux, 30, stdin);
													
													if (strlen(aux) == 1) {
														printf("\n\t\t Insira algum dado do tipo texto!\n\n");
														cont = 1;
														
													}else {
														for(int x=0; x<strlen(aux); x++) {
															e[group].projetistaChefe[x] = aux[x];
														}
														cont = 2;	
													}
													
													/* Limpando o buffer do teclado:
													==============================================================================*/
														fflush(stdin);
												} while (cont < 2);
												
												break;
											case 16:
													do {
													char aux[30];
													cont = 0;
																			
													printf("\t\t Insira o nome do chefe de pesquisa e desenvolvimento: ");
													fgets(aux, 30, stdin);
													
													if (strlen(aux) == 1) {
														printf("\n\t\t Insira algum dado do tipo texto!\n\n");
														cont = 1;
														
													}else {
														for(int x=0; x<strlen(aux); x++) {
															e[group].chefePesqEhDev[x] = aux[x];
														}
														cont = 2;	
													}
													
													/* Limpando o buffer do teclado:
													==============================================================================*/
														fflush(stdin);
												} while (cont < 2);
												
												break;
											case 17:
													do {
													char aux[30];
													cont = 0;
																			
													printf("\t\t Insira o nome do chefe mecanico: ");
													fgets(aux, 30, stdin);
													
													if (strlen(aux) == 1) {
														printf("\n\t\t Insira algum dado do tipo texto!\n\n");
														cont = 1;
														
													}else {
														for(int x=0; x<strlen(aux); x++) {
															e[group].chefeMecanico[x] = aux[x];
														}
														cont = 2;	
													}
													
													/* Limpando o buffer do teclado:
													==============================================================================*/
														fflush(stdin);
												} while (cont < 2);
												
												break;
											case 18:
												do {
													char aux[30];
													cont = 0;
																			
													printf("\t\t Insira o nome do tecnico de pneus: ");
													fgets(aux, 30, stdin);
													
													if (strlen(aux) == 1) {
														printf("\n\t\t Insira algum dado do tipo texto!\n\n");
														cont = 1;
														
													}else {
														for(int x=0; x<strlen(aux); x++) {
															e[group].tecnicoPneus[x] = aux[x];
														}
														cont = 2;	
													}
													
													/* Limpando o buffer do teclado:
													==============================================================================*/
														fflush(stdin);
												} while (cont < 2);
												
												break;
											case 19:
												do {
													char aux[30];
													cont = 0;
																			
													printf("\t\t Insira o nome do tecnico de componentes: ");
													fgets(aux, 30, stdin);
													
													if (strlen(aux) == 1) {
														printf("\n\t\t Insira algum dado do tipo texto!\n\n");
														cont = 1;
														
													}else {
														for(int x=0; x<strlen(aux); x++) {
															e[group].tecnicoComponentes[x] = aux[x];
														}
														cont = 2;	
													}
													
													/* Limpando o buffer do teclado:
													==============================================================================*/
														fflush(stdin);
												} while (cont < 2);
												
												break;
											case 20:
												do {
													char aux[30];
													cont = 0;
																			
													printf("\t\t Insira nome do tecnico de componentes: ");
													fgets(aux, 30, stdin);
													
													if (strlen(aux) == 1) {
														printf("\n\t\t Insira algum dado do tipo texto!\n\n");
														cont = 1;
														
													}else {
														for(int x=0; x<strlen(aux); x++) {
															e[group].tecnicoTransmissao[x] = aux[x];
														}
														cont = 2;	
													}
													
													/* Limpando o buffer do teclado:
													==============================================================================*/
														fflush(stdin);
												} while (cont < 2);
												
												break;	
											case 21:
												do {
													char aux[30];
													cont = 0;
																			
													printf("\t\t Insira o nome do tecnico de combustiveis: ");
													fgets(aux, 30, stdin);
													
													if (strlen(aux) == 1) {
														printf("\n\t\t Insira algum dado do tipo texto!\n\n");
														cont = 1;
														
													}else {
														for(int x=0; x<strlen(aux); x++) {
															e[group].tecnicoCombustivel[x] = aux[x];
														}
														cont = 2;	
													}
													
													/* Limpando o buffer do teclado:
													==============================================================================*/
														fflush(stdin);
												} while (cont < 2);
												
												break;
											case 22:
									    	for(int l = 0; l < 21; l++){

												do {
													char aux[30];
													cont = 0;
																			
													printf("\t\t Insira os nomes do tecnicos de pitstop: ");
													fgets(aux, 30, stdin);
													
													if (strlen(aux) == 1) {
														printf("\n\t\t Insira algum dado do tipo texto!\n\n");
														cont = 1;
														
													}else {
														for(int x=0; x<strlen(aux); x++) {
															e[group].mecanicosPitStop[l][x] = aux[x];
															fflush(stdin);
														}
														
														cont = 2;	
													}
													
													/* Limpando o buffer do teclado:
													==============================================================================*/
														fflush(stdin);
														
												} while (cont < 2);
												
											}
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
						criar_arqEquip("arquivo_equipe.txt");
							
					/* Inserindo os dados:
					======================================================================================================*/	
						int s = 0;
						
						while (s < m) {
							e[s].grupo = s;
							
								fprintf(filePointerEquip, "%i\n", e[s].grupo);
								fprintf(filePointerEquip, "%s", e[s].nome);
								fprintf(filePointerEquip, "%s", e[s].nacionalidade);
								fprintf(filePointerEquip, "%i\n", e[s].qtddMembros);
								fprintf(filePointerEquip, "%i\n", e[s].qtddTitulosConstrutores );
								fprintf(filePointerEquip, "%i\n", e[s].qtddTitulosCondutores);
								fprintf(filePointerEquip, "%i\n", e[s].poliPositions);
								fprintf(filePointerEquip, "%i\n", e[s].qtddVoltasMaisRap);
								fprintf(filePointerEquip, "%i\n", e[s].valorMercado);
								fprintf(filePointerEquip, "%i\n", e[s].taxaIncricaoTemp );
								fprintf(filePointerEquip, "%s", e[s].coresEquipe);
								fprintf(filePointerEquip, "%s", e[s].chefeEquipe);
								fprintf(filePointerEquip, "%s", e[s].diretorComercial);
								fprintf(filePointerEquip, "%s", e[s].diretorTecnico);
								fprintf(filePointerEquip, "%s", e[s].aeroDinamicChefe);
								fprintf(filePointerEquip, "%s", e[s].projetistaChefe);
								fprintf(filePointerEquip, "%s", e[s].chefePesqEhDev);
								fprintf(filePointerEquip, "%s", e[s].chefeMecanico);
								fprintf(filePointerEquip, "%s", e[s].tecnicoPneus);
								fprintf(filePointerEquip, "%s", e[s].tecnicoComponentes);
								fprintf(filePointerEquip, "%s", e[s].tecnicoTransmissao);
								fprintf(filePointerEquip, "%s", e[s].tecnicoCombustivel);
								
							for(int l = 0; l < 21; l++){
		
            					fprintf(filePointerEquip, "%s", e[s].mecanicosPitStop[l]);
            					fflush(stdin);
							}
							
							s++;
						}
						
					/* Fechando o arquivo txt:
					======================================================================================================*/
						fechar_arqEquip();
						
					/* Informando que os dados foram salvos no arquivo com sucesso:
					======================================================================================================*/			  
						printf("\n\n\t\t Os novos dados foram salvos no arquivo com sucesso!\n\t\t Edicao finalizada!");
		}
	
	/* Funcao de Edicao:
	======================================================================================================================*/
		void excluir_equipe() {
			if (filePointerEquip != NULL) {
				int size;
				
				/* Lidando com o arquivo de piloto.txt:
				==========================================================================================================*/
					/* Abrindo no modo de leitura:
					======================================================================================================*/
						abrir_arqEquip_modoLeitura("arquivo_equipe.txt");
				
					/* Setando o ponteiro na ultima linha:
					======================================================================================================*/
						fseek(filePointerEquip, 0, SEEK_END);
					
					/* Pegando o tamanho do arquivo:
					======================================================================================================*/	
						size = ftell(filePointerEquip);
				
						if (size == 0) {
							printf("\n\t\t Arquivo vazio! Insira dados antes de tentar excluir!\n");
							
							int final_answer;
							
							printf("Retornar ao menu anterior? (0 = NAO || 1 = SIM): ");
							scanf("%i", &final_answer);
							
							if (final_answer == 1) {
								system("cls"); // Corrigir para funcionamento com linux tbm!!!!
							}  
							
							/* Fechando o arquivo:
							======================================================================================================*/
								fechar_arqEquip();
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
								abrir_arqEquip_modoLeitura("arquivo_equipe.txt");
								
						/* Impressao da Tarefa:
						======================================================================================================*/
							printf("\n\t\t =========== EXCLUSAO DE EQUIPE =============\n");
						     
						    while (!feof(filePointerEquip)) {
						    	/* Grupo:
						    	==============================================================================================*/
									fscanf(filePointerEquip, "%i\n", &e[m].grupo);
									printf("\t\t Grupo %i:\n\n", e[m].grupo);
							    
							    /* Limpando Buffer:
							    ==============================================================================================*/
							   		fflush(stdin);
						    	
							        /* Nome:
									==============================================================================================*/		    	
							    		fgets(e[m].nome, 50, filePointerEquip);
							    		printf("\t\t %s", e[m].nome);
							    	
							    	/* Nacionalidade:
									==============================================================================================*/
							    		fgets(e[m].nacionalidade, 30, filePointerEquip);
							    		printf("\t\t %s", e[m].nacionalidade);
							    		
							    	/* Limpando Buffer:
								    ==============================================================================================*/
								   		fflush(stdin);
							    	
							    	/* Quantidade de membros:
									==============================================================================================*/
							    		fscanf(filePointerEquip, "%i\n", &e[m].qtddMembros);
							    		printf("\t\t %i\n", e[m].qtddMembros);
							    	
							    	/* Quantidade de titulos dos contrutores:
									==============================================================================================*/
							    		fscanf(filePointerEquip, "%i\n", &e[m].qtddTitulosConstrutores );
							    		printf("\t\t %i\n", e[m].qtddTitulosConstrutores );
							    	
							    	/* Quantidade de titulos dos condutores
									==============================================================================================*/
							    		fscanf(filePointerEquip, "%i\n", &e[m].qtddTitulosCondutores);
							    		printf("\t\t %i\n", e[m].qtddTitulosCondutores);
							    	
							    	/* Poli Positions:
									==============================================================================================*/
							    		fscanf(filePointerEquip, "%i\n", &e[m].poliPositions);
							    		printf("\t\t %i\n", e[m].poliPositions);
							    		
							        /* Limpando Buffer:
							        ==============================================================================================*/
							   		fflush(stdin);
							    	                                
							    	/* Quantidades de voltas mais rapidas:
									==============================================================================================*/
							    		fscanf(filePointerEquip, "%i\n", &e[m].qtddVoltasMaisRap );
							    		printf("\t\t %i\n", e[m].qtddVoltasMaisRap );
							    	                                
							    	/* Valor do mercado:
									==============================================================================================*/
							    		fscanf(filePointerEquip, "%i\n", &e[m].valorMercado);
							    		printf("\t\t %i\n", e[m].valorMercado);
							    	
									/* Taxa de inscrição na temporada
									==============================================================================================*/
							    		fscanf(filePointerEquip, "%i\n", &e[m].taxaIncricaoTemp );
							    		printf("\t\t %i\n", e[m].taxaIncricaoTemp );
							    	
							    	/* Limpando Buffer:
								    ==============================================================================================*/
								   		fflush(stdin);
								   		
							    	/* Cores da equipe:
									==============================================================================================*/		    	
							    		fgets(e[m].coresEquipe, 30, filePointerEquip);
							    		printf("\t\t %s", e[m].coresEquipe);
							    	
							    	/* Chefe da equipe:
									==============================================================================================*/
							    		fgets(e[m].chefeEquipe, 30, filePointerEquip);
							    		printf("\t\t %s", e[m].chefeEquipe);
							    	
							    	/* Diretor Comercial:
									==============================================================================================*/		    	
							    		fgets(e[m].diretorComercial, 30, filePointerEquip);
							    		printf("\t\t %s", e[m].diretorComercial);
							    	
							    	/* Diretor Tecnico:
									==============================================================================================*/
							    		fgets(e[m].diretorTecnico, 30, filePointerEquip);
							    		printf("\t\t %s", e[m].diretorTecnico);
							    	
							    	/* Chefe aereo dinamico:
									==============================================================================================*/		    	
							    		fgets(e[m].aeroDinamicChefe, 30, filePointerEquip);
							    		printf("\t\t %s", e[m].aeroDinamicChefe);
							    	
							    	/* Chefe projetista:
									==============================================================================================*/
							    		fgets(e[m].projetistaChefe, 30, filePointerEquip);
							    		printf("\t\t %s", e[m].projetistaChefe);
							    		
							    	/* Chefe de pesquisa e desenvolvimento:
									==============================================================================================*/		    	
							    		fgets(e[m].chefePesqEhDev, 30, filePointerEquip);
							    		printf("\t\t %s", e[m].chefePesqEhDev);
							    		
							    	/* Limpando Buffer:
							        ==============================================================================================*/
							   		    fflush(stdin);
							    	
							    	/* Chefe Mecanico:
									==============================================================================================*/
							    		fgets(e[m].chefeMecanico, 30, filePointerEquip);
							    		printf("\t\t %s", e[m].chefeMecanico);
							    		
							    	/* Tecnico de pneus:
									==============================================================================================*/		    	
							    		fgets(e[m].tecnicoPneus, 30, filePointerEquip);
							    		printf("\t\t %s", e[m].tecnicoPneus);
							    	
							    	/* Tecnico de componentes:
									==============================================================================================*/
							    		fgets(e[m].tecnicoComponentes, 30, filePointerEquip);
							    		printf("\t\t %s", e[m].tecnicoComponentes);
							    		
							    	/* Tecnico de transmissão:
									==============================================================================================*/		    	
							    		fgets(e[m].tecnicoTransmissao, 30, filePointerEquip);
							    		printf("\t\t %s", e[m].tecnicoTransmissao);
							    	
							    	/* Tecnico de combustivel:
									==============================================================================================*/
							    		fgets(e[m].tecnicoCombustivel, 30, filePointerEquip);
							    		printf("\t\t %s", e[m].tecnicoCombustivel);
							    		
							    	/* Mecanico de pit stop:
									==============================================================================================*/
									for(int l = 0; l < 21; l++){		    	
							    		fgets(e[m].mecanicosPitStop[l], 30, filePointerEquip);
							    		printf("\t\t %s", e[m].mecanicosPitStop);
                                }
									/* Limpando Buffer:
							        ==============================================================================================*/
							   		fflush(stdin);
							    	
						    	/* Atualizando o valor de m:
						    	==============================================================================================*/
						    		m++;
							}
							
							/* Fechando o arquivo depois do uso:
							==================================================================================================*/
								fechar_arqEquip();
							
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
											
											printf("\n\t\t1-Nome: %s", e[y].nome);
											printf("\t\t2-Nacionalidade: %s", e[y].nacionalidade);
											printf("\t\t3-Quantidade de membros: %i\n", e[y].qtddMembros);
											printf("\t\t4-Quantidade de titulos dos contrutores: %i\n", e[y].qtddTitulosConstrutores);
											printf("\t\t5-Quantidade de titulos dos condutores: %i\n", e[y].qtddTitulosCondutores);
											printf("\t\t6-Poli Positions: %i\n", e[y].poliPositions );
											printf("\t\t7-Quantidade de voltas mais rapidas: %i\n", e[y].qtddVoltasMaisRap );
											printf("\t\t8-Valor do mercado: %i\n", e[y].valorMercado);
											printf("\t\t9-Valor da taxa de inscrição: %i\n", e[y].taxaIncricaoTemp );										
											printf("\t\t10-Cores de equipe: %s", e[y].coresEquipe);
											printf("\t\t11-Chefe de equipe: %s", e[y].chefeEquipe);
											printf("\t\t12-Diretor comercial: %s", e[y].diretorComercial);
											printf("\t\t13-Diretor tecnico: %s", e[y].diretorTecnico);
											printf("\t\t14-Chefe da aereo dinamica: %s", e[y].aeroDinamicChefe);
											printf("\t\t15-Projetista chefe: %s", e[y].projetistaChefe);
											printf("\t\t16-Chefe de pesquisa e desenvolvimento: %s", e[y].chefePesqEhDev);
											printf("\t\t17-Chefe mecanico: %s", e[y].chefeMecanico);
											printf("\t\t18-Tecnico de pneus: %s", e[y].tecnicoPneus);							
											printf("\t\t19-Tecnico de de componentes: %s", e[y].tecnicoComponentes);
											printf("\t\t20-Tecnico de transmissão: %s", e[y].tecnicoTransmissao);
											printf("\t\t21-Tecnico de combustivel: %s", e[y].tecnicoCombustivel);	
						             for(int l = 0; l < 21; l++){
										printf("\t\t22-Mecanicos de PitStop: %s", e[y].mecanicosPitStop[l]);
									}
									}
								}
								
								/* Limpando o buffer do teclado:
								==============================================================================================*/
									fflush(stdin);
									
							/* Gravando no arquivo txt:
							==========================================================================================================*/
								/* Criando novamente o arquivo:
								======================================================================================================*/
									criar_arqEquip("arquivo_equipe.txt");
										
								/* Inserindo os dados:
								======================================================================================================*/	
									int s = 0;
									int count_groups;
									
									while (s < m) {							
										if (s == group) {
											s++;
											count_groups = s;
											count_groups--;
										} else if (s < group) {
											count_groups = s;
										} else {
											count_groups = (s-1);
										}
										
										e[s].grupo = count_groups;
										
										fprintf(filePointerEquip, "%i\n", e[s].grupo);
										fprintf(filePointerEquip, "%s", e[s].nome);
										fprintf(filePointerEquip, "%s", e[s].nacionalidade);
										fprintf(filePointerEquip, "%i\n", e[s].qtddMembros);
										fprintf(filePointerEquip, "%i\n", e[s].qtddTitulosConstrutores );
										fprintf(filePointerEquip, "%i\n", e[s].qtddTitulosCondutores);
										fprintf(filePointerEquip, "%i\n", e[s].poliPositions);
										fprintf(filePointerEquip, "%i\n", e[s].qtddVoltasMaisRap);
										fprintf(filePointerEquip, "%i\n", e[s].valorMercado);
										fprintf(filePointerEquip, "%i\n", e[s].taxaIncricaoTemp );
										fprintf(filePointerEquip, "%s", e[s].coresEquipe);
										fprintf(filePointerEquip, "%s", e[s].chefeEquipe);
										fprintf(filePointerEquip, "%s", e[s].diretorComercial);
										fprintf(filePointerEquip, "%s", e[s].diretorTecnico);
										fprintf(filePointerEquip, "%s", e[s].aeroDinamicChefe);
										fprintf(filePointerEquip, "%s", e[s].projetistaChefe);
										fprintf(filePointerEquip, "%s", e[s].chefePesqEhDev);
										fprintf(filePointerEquip, "%s", e[s].chefeMecanico);
										fprintf(filePointerEquip, "%s", e[s].tecnicoPneus);
										fprintf(filePointerEquip, "%s", e[s].tecnicoComponentes);
										fprintf(filePointerEquip, "%s", e[s].tecnicoTransmissao);
										fprintf(filePointerEquip, "%s", e[s].tecnicoCombustivel);
									for(int l = 0; l < 21; l++){
   										fprintf(filePointerEquip, "%s", e[s].mecanicosPitStop[l]);
									}
										s++;
										count_groups++;
								}
								
								/* Fechando o arquivo txt:
								======================================================================================================*/	
									fechar_arqEquip();
								
								/* Caso Delete o Ultimo Grupo de Informacao:
								======================================================================================================*/		
									if (s == (m+1)) {
										/* Criando um novo arquivo vazio:
										==============================================================================================*/
											criar_arqEquip("arquivo_equipe.txt");
										
										/* Fechando o arquivo txt:
										==============================================================================================*/
											fechar_arqEquip();
									}
									
								/* Informando que os dados foram salvos no arquivo com sucesso:
								======================================================================================================*/			  
									printf("\n\n\t\t Os novos dados foram salvos no arquivo com sucesso!\n\t\t Exclusao finalizada!");	
					}
			}
			
		}
	

		
/* Funcao de Impressao:
	======================================================================================================================*/
		void imprimir_equipe() {
		//	if (filePointerEquip != NULL) {
				int size;
				
				/* Lidando com o arquivo de piloto.txt:
				==========================================================================================================*/
					/* Abrindo no modo de leitura:
					======================================================================================================*/
						abrir_arqEquip_modoLeitura("arquivo_equipe.txt");
				
					/* Setando o ponteiro na ultima linha:
					======================================================================================================*/
						fseek(filePointerEquip, 0, SEEK_END);
					
					/* Pegando o tamanho do arquivo:
					======================================================================================================*/	
						size = ftell(filePointerEquip);
				
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
								fechar_arqEquip();
							
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
									abrir_arqEquip_modoLeitura("arquivo_equipe.txt");
									
							/* Impressao da Tarefa:
							======================================================================================================*/
								printf("\n\t\t =========== IMPRESSAO DE EQUIPE =============\n\n");
														   
						
							     
							    while (!feof(filePointerEquip)) {
							    	/* Grupo:
							    	==============================================================================================*/
										fscanf(filePointerEquip, "%i\n\n", &e[m].grupo);
										printf("\t\t Grupo %i:\n\n", e[m].grupo);
								    
								    /* Limpando Buffer:
								    ==============================================================================================*/
								   		fflush(stdin);
							    	
			                        /* Nome:
									==============================================================================================*/		    	
							    		fgets(e[m].nome, 50, filePointerEquip);
							    		printf("\t\t %s", e[m].nome);
							    	
							    	/* Nacionalidade:
									==============================================================================================*/
							    		fgets(e[m].nacionalidade, 30, filePointerEquip);
							    		printf("\t\t %s", e[m].nacionalidade);
							    		
							    	/* Limpando Buffer:
								    ==============================================================================================*/
								   		fflush(stdin);
							    	
							    	/* Quantidade de membros:
									==============================================================================================*/
							    		fscanf(filePointerEquip, "%i\n", &e[m].qtddMembros);
							    		printf("\t\t %i\n", e[m].qtddMembros);
							    	
							    	/* Quantidade de titulos dos contrutores:
									==============================================================================================*/
							    		fscanf(filePointerEquip, "%i\n", &e[m].qtddTitulosConstrutores );
							    		printf("\t\t %i\n", e[m].qtddTitulosConstrutores );
							    	
							    	/* Quantidade de titulos dos condutores
									==============================================================================================*/
							    		fscanf(filePointerEquip, "%i\n", &e[m].qtddTitulosCondutores);
							    		printf("\t\t %i\n", e[m].qtddTitulosCondutores);
							    	
							    	/* Poli Positions:
									==============================================================================================*/
							    		fscanf(filePointerEquip, "%i\n", &e[m].poliPositions);
							    		printf("\t\t %i\n", e[m].poliPositions);
							    	                                
							    	/* Quantidades de voltas mais rapidas:
									==============================================================================================*/
							    		fscanf(filePointerEquip, "%i\n", &e[m].qtddVoltasMaisRap );
							    		printf("\t\t %i\n", e[m].qtddVoltasMaisRap );
							    	                                
							    	/* Valor do mercado:
									==============================================================================================*/
							    		fscanf(filePointerEquip, "%i\n", &e[m].valorMercado);
							    		printf("\t\t %i\n", e[m].valorMercado);
							    	
									/* Taxa de inscrição na temporada
									==============================================================================================*/
							    		fscanf(filePointerEquip, "%i\n", &e[m].taxaIncricaoTemp );
							    		printf("\t\t %i\n", e[m].taxaIncricaoTemp );
							    	
							    	/* Limpando Buffer:
								    ==============================================================================================*/
								   		fflush(stdin);
								   		
							    	/* Cores da equipe:
									==============================================================================================*/		    	
							    		fgets(e[m].coresEquipe, 30, filePointerEquip);
							    		printf("\t\t %s", e[m].coresEquipe);
							    	
							    	/* Chefe da equipe:
									==============================================================================================*/
							    		fgets(e[m].chefeEquipe, 30, filePointerEquip);
							    		printf("\t\t %s", e[m].chefeEquipe);
							    	
							    	/* Diretor Comercial:
									==============================================================================================*/		    	
							    		fgets(e[m].diretorComercial, 30, filePointerEquip);
							    		printf("\t\t %s", e[m].diretorComercial);
							    	
							    	/* Diretor Tecnico:
									==============================================================================================*/
							    		fgets(e[m].diretorTecnico, 30, filePointerEquip);
							    		printf("\t\t %s", e[m].diretorTecnico);
							    	
							    	/* Chefe aereo dinamico:
									==============================================================================================*/		    	
							    		fgets(e[m].aeroDinamicChefe, 30, filePointerEquip);
							    		printf("\t\t %s", e[m].aeroDinamicChefe);
							    	
							    	/* Chefe projetista:
									==============================================================================================*/
							    		fgets(e[m].projetistaChefe, 30, filePointerEquip);
							    		printf("\t\t %s", e[m].projetistaChefe);
							    		
							    	/* Chefe de pesquisa e desenvolvimento:
									==============================================================================================*/		    	
							    		fgets(e[m].chefePesqEhDev, 30, filePointerEquip);
							    		printf("\t\t %s", e[m].chefePesqEhDev);
							    	
							    	/* Chefe Mecanico:
									==============================================================================================*/
							    		fgets(e[m].chefeMecanico, 30, filePointerEquip);
							    		printf("\t\t %s", e[m].chefeMecanico);
							    		
							    	/* Tecnico de pneus:
									==============================================================================================*/		    	
							    		fgets(e[m].tecnicoPneus, 30, filePointerEquip);
							    		printf("\t\t %s", e[m].tecnicoPneus);
							    	
							    	/* Tecnico de componentes:
									==============================================================================================*/
							    		fgets(e[m].tecnicoComponentes, 30, filePointerEquip);
							    		printf("\t\t %s", e[m].tecnicoComponentes);
							    		
							    	/* Tecnico de transmissão:
									==============================================================================================*/		    	
							    		fgets(e[m].tecnicoTransmissao, 30, filePointerEquip);
							    		printf("\t\t %s", e[m].tecnicoTransmissao);
							    	
							    	/* Tecnico de combustivel:
									==============================================================================================*/
							    		fgets(e[m].tecnicoCombustivel, 30, filePointerEquip);
							    		printf("\t\t %s", e[m].tecnicoCombustivel);
							    		
							    	/* Mecanico de pit stop:
									==============================================================================================*/		
									for(int l = 0; l < 21; l++){    	
							    		fgets(e[m].mecanicosPitStop[l], 30, filePointerEquip);
							    		printf("\t\t %s", e[m].mecanicosPitStop[l]);
							    }
							    	/* Atualizando o valor de m:
							    	==============================================================================================*/
							    		m++;
								}
								
								printf("Retornar ao menu anterior? (0 = NAO || 1 = SIM): ");
								scanf("%i", &answer);
								
								if (answer == 1) {
									system("cls"); // Corrigir para funcionamento com linux tbm!!!!
								}
								
								/* Fechando o arquivo depois do uso:
								==================================================================================================*/
									fechar_arqEquip();
						}
			//}
		}
		
		
/* Funcao de reescrita:
	==============================================================================================================*/
		int reescrever_equip() {	
			int tam;
			int num1_last_group;
			int sizeFil;
			
			sizeFil = ftell(filePointerEquip);
			
			if (sizeFil != 0) {
				tam = 0;
				
				while (!feof(filePointerEquip)) {
			    	/* Grupo:
			    	==============================================================================================*/
						fscanf(filePointerEquip, "%i\n", &e[tam].grupo);
				    
				    /* Limpando Buffer:
				    ==============================================================================================*/
				   		fflush(stdin);
			    	
				    	fgets(e[tam].nome, 50, filePointerEquip);
				    	fgets(e[tam].nacionalidade, 30, filePointerEquip);
				    	fscanf(filePointerEquip, "%i\n", &e[tam].qtddMembros);
				    	fscanf(filePointerEquip, "%i\n", &e[tam].qtddTitulosConstrutores);
				    	fscanf(filePointerEquip, "%i\n", &e[tam].qtddTitulosCondutores);
				    	fscanf(filePointerEquip, "%i\n", &e[tam].poliPositions);
				    	fscanf(filePointerEquip, "%i\n", &e[tam].qtddVoltasMaisRap);
				    	fscanf(filePointerEquip, "%i\n", &e[tam].valorMercado);
				    	fscanf(filePointerEquip, "%i\n", &e[tam].taxaIncricaoTemp );
				    	fgets(e[tam].coresEquipe, 30, filePointerEquip);
				    	fgets(e[tam].chefeEquipe, 30, filePointerEquip);
				    	fgets(e[tam].diretorComercial, 30, filePointerEquip);
				    	fgets(e[tam].diretorTecnico, 30, filePointerEquip);
				    	fgets(e[tam].aeroDinamicChefe, 30, filePointerEquip);
				    	fgets(e[tam].projetistaChefe, 30, filePointerEquip);
				    	fgets(e[tam].chefePesqEhDev, 30, filePointerEquip);
				    	fgets(e[tam].chefeMecanico, 30, filePointerEquip);
				    	fgets(e[tam].tecnicoPneus, 30, filePointerEquip);
				    	fgets(e[tam].tecnicoComponentes, 30, filePointerEquip);
				    	fgets(e[tam].tecnicoTransmissao, 30, filePointerEquip);
				    	fgets(e[tam].tecnicoCombustivel, 30, filePointerEquip);
				    	
				    	for(int l = 0; l < 21; l++){
				    		fgets(e[tam].mecanicosPitStop[l], 30, filePointerEquip);
				    	
				    }
 					   	fflush(stdin);

			    	
			    	/* Atualizando o valor de length:
			    	==============================================================================================*/
			    		tam++;
				}
				
				printf("%i", tam);
				
				// Fechando o modo leitura:
					fechar_arqEquip();
				
				// Criando um arquivo novo:
					criar_arqEquip("arquivo_equipe.txt");
				
					int v;
					v = 0;
				
					while(v <= tam) {
						e[v].grupo = v;
					
						fprintf(filePointerEquip, "%i\n", e[v].grupo);
						fprintf(filePointerEquip, "%s", e[v].nome);
						fprintf(filePointerEquip, "%s", e[v].nacionalidade);
						fprintf(filePointerEquip, "%i\n", e[v].qtddMembros);
						fprintf(filePointerEquip, "%i\n", e[v].qtddTitulosConstrutores );
						fprintf(filePointerEquip, "%i\n", e[v].qtddTitulosCondutores);
						fprintf(filePointerEquip, "%i\n", e[v].poliPositions);
						fprintf(filePointerEquip, "%i\n", e[v].qtddVoltasMaisRap);
						fprintf(filePointerEquip, "%i\n", e[v].valorMercado);
						fprintf(filePointerEquip, "%i\n", e[v].taxaIncricaoTemp );
						fprintf(filePointerEquip, "%s", e[v].coresEquipe);
						fprintf(filePointerEquip, "%s", e[v].chefeEquipe);
						fprintf(filePointerEquip, "%s", e[v].diretorComercial);
						fprintf(filePointerEquip, "%s", e[v].diretorTecnico);
						fprintf(filePointerEquip, "%s", e[v].aeroDinamicChefe);
						fprintf(filePointerEquip, "%s", e[v].projetistaChefe);
						fprintf(filePointerEquip, "%s", e[v].chefePesqEhDev);
						fprintf(filePointerEquip, "%s", e[v].chefeMecanico);
						fprintf(filePointerEquip, "%s", e[v].tecnicoPneus);
						fprintf(filePointerEquip, "%s", e[v].tecnicoComponentes);
						fprintf(filePointerEquip, "%s", e[v].tecnicoTransmissao);
						fprintf(filePointerEquip, "%s", e[v].tecnicoCombustivel);
	
			    	for(int l = 0; l < 21; l++){
									
     					fprintf(filePointerEquip, "%s", e[v].mecanicosPitStop[l]);
                    }
						v++;
					}
				
				// Fechando o arquivo do modo criar:
					fechar_arqEquip();
				
				/* Abrindo o arquivo no modo escrita e leitura:
				======================================================================================================*/
					abrir_arqEquip("arquivo_equipe.txt");
				
				/* Setando o ponteiro na ultima linha:
				======================================================================================================*/
					fseek(filePointerEquip, 0, SEEK_END);
				
				return v;
				
			} else {
				num1_last_group = 0;
				
				return num1_last_group;
			}
		}
