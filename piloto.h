#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Functions Loading:
	void cadastramento_piloto();
	void excluir_piloto();
	void abrir();
	void criar();
	void fechar();

// Estrutura:
	struct piloto {
	    char nome[50];
	    char nacionalidade[30];
	    char corPele[30];
	    char corOlhos[30];
	    char corCabelo[30];
	    int altura;
	    int peso;
	    int idade;
	    int qtdCampeonatosGanhos;
	    int polePosition;				// Posicao de iniciacao na corrida.
	    int qtdVoltasRap;      			// Quantidade de voltas mais rapidas

	};

// Variables:
	FILE *filePointer;
	struct piloto *pilotoPointer;
	int length;


// Funcoes:
	/* Handling with Files: 
	==========================================================================================================*/
		void abrir() {
			filePointer = fopen("pilotos.txt", "r+");
			
			if(filePointer == NULL) {
				criar();
				fechar();
				abrir();          
			}
		}
		
		void criar() {
			filePointer = fopen("pilotos.txt", "w");

			if(filePointer == NULL) {
				printf("Erro ao criar o arquivo!");   
				exit(1);             
			}
		}

		void fechar() {
			fclose(filePointer);
		}

	/* Cadastramento do Piloto:
	==========================================================================================================*/
		void cadastramento_piloto() {
			int n; // Para uso no loop do FOR.
			
			// Pegando o numero de inserções:
				printf("\n\t\t Insira o numero de pilotos deseja cadastrar: ");
				scanf("%i", &length);
			
			// Definindo a estrutura a ser utilizada e seu apelido:
				struct piloto p[length];
				
			// Definindo um ponteiro para p[]:
				pilotoPointer = &p[0];
			
			// Criando/Abrindo o Arquivo TXT:
				abrir();
				
			// Setando o ponteiro ao final do arquivo:
				fseek(filePointer, 0, SEEK_END);
				
			// Impressao de qual tarefa sera realizada:
				printf("\n\t\t ================= CADASTRAMENTO DE PILOTO =================\n");
			
			// Insercoes:
				// Coleta de dados:
					for (n=0; n<length; n++) {
						// Limpando o buffer do teclado:
							fflush(stdin);
							
						// Nome:
							printf("\t\t Insira o nome do piloto: ");
							fgets(p[n].nome, 50, stdin);
							
						// Nacionalidade:
							printf("\t\t Insira a nacionalidade do piloto: ");
							fgets(p[n].nacionalidade, 30, stdin);
							
						// Cor de Pele:
							printf("\t\t Insira a cor de pele do piloto: ");
							fgets(p[n].corPele, 30, stdin);
							
						// Cor dos Olhos:
							printf("\t\t Insira a cor dos olhos do piloto: ");
							fgets(p[n].corOlhos, 30, stdin);
							
						// Cor do Cabelo:
							printf("\t\t Insira a cor do cabelo do piloto: ");
							fgets(p[n].corCabelo, 30, stdin);
							
						// Altura:
							printf("\t\t Insira a altura do piloto: ");
							scanf("%i", &p[n].altura);
							
						// Peso:
							printf("\t\t Insira o peso do piloto: ");
							scanf("%i", &p[n].peso);
							
						// Idade:
							printf("\t\t Insira a idade do piloto: ");
							scanf("%i", &p[n].idade);
							
						// Qtd de Campeonatos Ganhos:
							printf("\t\t Insira a quantidade de campeonatos ganhos pelo piloto: ");
							scanf("%i", &p[n].qtdCampeonatosGanhos);
							
						// Pole Position:
							printf("\t\t Insira a posicao de largada do piloto: ");
							scanf("%i", &p[n].polePosition);
							
						// Qtd de Voltas Mais Rapidas:
							printf("\t\t Insira a quantidade de voltas mais rapidas feitas pelo piloto: ");
							scanf("%i", &p[n].qtdVoltasRap);
							
						// Pulando uma linha:
							printf("\n");
					}
					
				// Adicao ao arquivo txt:
					for (n=0; n<length; n++) {
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
					}
					
				//Fechando o arquivo TXT:
					fechar();		
		}
	
	// Edicao do Piloto:
		void edicao_piloto() {			
			// Impressão do array:
				int n;
				
				for(n=0; n<length; n++) {
					printf("%s\n%s\n%s\n%s\n%s\n%i\n%i\n%i\n%i\n%i\n%i\r\n", *(pilotoPointer+n).nome, *((pilotoPointer+n).nacionalidade), *((pilotoPointer+n).corPele), p.corOlhos, p.corCabelo, p.altura, p.peso, p.idade, p.qtdCampeonatosGanhos, p.polePosition, p.qtdVoltasRap );
				}
		}
	
	// Exclusao do Piloto:
/*void excluir_piloto(void){
	
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
		
	}*/
		
