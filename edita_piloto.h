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
				printf("\t\t Erro! Arquivo nao encontrado!");
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
			/* Funcionamento Geral:
			==================================================================================================*/
				int m = 0; 
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
		     
		    while (!feof(filePointer)) {
		    	/* Grupo:
		    	==============================================================================================*/
					fscanf(filePointer, "%i\n", &p[m].grupo);
					printf("\t\t\t\t Grupo %i:\n\n", p[m].grupo);
			    
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
		    	
		    	printf("Qual grupo deseja editar: ");
		    	scanf("%i", &group);    	
		    	
		    	for (int y=0; y<m; y++) {
		    		if(y == group) {
		    			/* Mostrando o Grupo Selecionado: (precisa editar o nome da variavel!!!!!)
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
						
						/* Editando:
						====================================================================================*/					
							switch (editionOption) {
								case 1:							
									printf("Insira o novo nome: ");
									fgets(p[y].nome, 50 ,stdin);
										
									break;
								case 2:
									printf("Insira a nova nacionalidade: ");
									fgets(p[y].nacionalidade, 30, stdin);
									
									break;
								case 3:
									printf("Insira a nova cor de pele: ");
									scanf("%s\n", &p[y].corPele, stdin);
									
									break;
								case 4:
									printf("Insira a nova cor dos olhos: ");
									scanf("%s\n", &p[y].corOlhos, stdin);
									
									break;
								case 5:
									printf("Insira a nova cor de cabelo: ");
									scanf("%s\n", &p[y].corCabelo, stdin);
									
									break;
								case 6:
									printf("Insira a nova altura: ");
									scanf("%i", &p[y].altura);
									
									break;
								case 7:
									printf("Insira o novo peso: ");
									scanf("%i", &p[y].peso);
									
									break;
								case 8:
									printf("Insira a nova idade: ");
									scanf("%i", &p[y].idade);
									
									break;
								case 9:
									printf("Insira a nova quantidade de campeonatos ganhos: ");
									scanf("%i", &p[y].qtdCampeonatosGanhos);
									
									break;
								case 10:
									printf("Insira a nova pole position: ");
									scanf("%i", &p[y].polePosition);
									
									break;
								case 11:
									printf("Insira a nova quantidade de voltas rapidas: ");
									scanf("%i", &p[y].qtdVoltasRap);
									
									break;					
							}
					}
				}
			/* Gravando no arquivo txt:
			==================================================================================================*/
				/* Recriando o arquivo:
				==============================================================================================*/
					criar();
				
				/* Inserindo os dados:
				==============================================================================================*/	
					for (int z=0; z<m; z++) {
						fprintf(filePointer, "%s", p[z].grupo);
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
					}
					
				/* Fechando o arquivo txt:
				==============================================================================================*/
					fechar();			  
	}