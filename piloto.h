#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void cadastramento_piloto();
void excluir_piloto();
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
void excluir_piloto(void){
	
	int i,TAM=100, continuar;
	char nome_busca[50];
	system("cls");
	printf("\n\n");   
	printf("\t\t ~~~~~~~~~~~~~~~~  EXCLUIR  ~~~~~~~~~~~~~~~~\n\n");
	printf("\n\n");
	printf("\n\n");
	fflush(stdin); //Limpar Buffer do Teclado
	
	printf(" Informe o <Nome Completo> %c   ",26);
	     
	int nao_tem=999;
	gets(nome_busca);
	for(i=0; i<TAM; i++){
	     	if(strcmp(piloto[i].nome,nome_busca) = 0){
			int y;
	     		for(y=i; i<TAM; y++){
	     	 		piloto[y].nome = piloto[y+1].nome;
	     	 		piloto[y].altura = piloto[y+1].altura;
	     	 		piloto[y].corCabelo = piloto[y+1].corCabelo;
	     	 		piloto[y].corOlhos = piloto[y+1].corOlhos;
	     	 		piloto[y].corPele = piloto[y+1].corPele;
	     	 		piloto[y].idade = piloto[y+1].idade;
	     	 		piloto[y].nacionalidade = piloto[y+1].nacionalidade;
	     	 		piloto[y].peso = piloto[y+1].peso;
	     	 		piloto[y].polePosition = piloto[y+1].polePosition;
	     	 		piloto[y].qtdCampeonatosGanhos = piloto[y+1].qtdCampeonatosGanhos;
	     	 		piloto[y].qtdVoltasRap = piloto[y+1].qtdVoltasRap;
	     	 		
	     	 		system("cls");
                    		printf("\n\n   Exclusco conclu%cda com sucesso! \n\n\n",3782,3745);
                      
                    		printf("\n\n");
                    		printf("\n\n");
                    
                    		count--;
            		}
                    
		}else{
			system("cls");
	     		printf("\n  n?o foi encontrado nenhum dado correspondente. \n\n");
	     		printf("  Certifique-se de que todas as palavras estejam escritas corretamente.\n\n\n\n\n\n");
				  	
		}
			
	}
				  
	system("PAUSE");                
	system("cls");
	printf("\t\tDeseja continuar?   \n\n");
	printf(" 1 - Sim   \n\n 2 - n?o\n\n");
	scanf("%d",&continuar);
			
	while(continuar!=1 && continuar!=2){
		system("cls");
		printf("\t\tDeseja continuar?   \n\n");
		printf(" 1 - Sim   \n\n 2 - n?o\n\n");
		scanf("%d",&continuar);                   
	}
			
	if(continuar==1){
		EXCLUIR();
	}
	system("CLS");   
	     	 	
			
	     	
}
		
	
	// Impressao do Piloto:

	//Eh Craque

void EhCraque(){

		fflush(stdin); //Limpar Buffer do Teclado
    	int i;
    	int maior1=0, maior2=0, maior3=0;
    	int TAM = 100;
	     
	    system("cls");
	    printf("\n\n");   
	    printf("\t\t ~~~~~~~~~~~~~~~~  EH CRAQUE  ~~~~~~~~~~~~~~~~\n\n");
	    printf("\n\n");
	    printf("\n\n");
	    fflush(stdin); //Limpar Buffer do Teclado
	    
	    for(i=0; i<TAM; i++){
	    	if(piloto[i].qtdCampeonatosGanhos>maior1){
	    		maior1 = piloto[i].qtdCampeonatosGanhos;
	    		piloto[0][].EhCraque = piloto[i].nome
			}
		}
		
		for(i=0; i<TAM; i++){
			if(piloto[i].qtdCampeonatosGanhos>maior2 && piloto[i].qtdCampeonatosGanhos<maior1 ){
	    		maior2 = piloto[i].qtdCampeonatosGanhos;
	    		piloto[1][].EhCraque = piloto[i].nome
			}
		}
		
		for(i=0; i<TAM; i++){
			if(piloto[i].qtdCampeonatosGanhos>maior3 && piloto[i].qtdCampeonatosGanhos<maior2 ){
	    		maior3 = piloto[i].qtdCampeonatosGanhos;
	    		piloto[2][].EhCraque = piloto[i].nome
			}
		}
		printf("\nPOSICAO --- NOME ");
		for(i=0; i<3; i++){
			
			printf("%i    %s\n", i ,piloto[i].EhCraque);
			
		}
		
	}
		
