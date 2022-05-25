#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Functions Loading:
	void cadastramento_piloto();
	void edicao_piloto();
	void imprimir_piloto();
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

	/* Cadastramento do Piloto:
	==========================================================================================================*/
		void cadastramento_piloto() {
			int n; // Para uso no loop do FOR.
			
			// Pegando o numero de inserções:
				printf("\n\t\t Insira o numero de pilotos deseja cadastrar: ");
				scanf("%i", &length);
			
			// Definindo a estrutura a ser utilizada e seu apelido:
				//struct piloto p[length];
				
				struct piloto* p = malloc (length * sizeof * p);
							
			// Definindo um ponteiro para p[]:
				pilotoPointer = p;
			
			// Criando/Abrindo o Arquivo TXT:
				abrir();
				
			// Setando o ponteiro ao final do arquivo:
				fseek(filePointer, 0, SEEK_END);
				
			// Impressao de qual tarefa sera realizada:
				printf("\n\t\t ========== CADASTRAMENTO DE PILOTO ==========\n");
			
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
						fprintf(filePointer, "%s\n", "INSERCAO DE DADOS FEITA NO CADASTRAMENTO DE PILOTO:");
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
					
				// Limpando o buffer do teclado:
					fflush(stdin);
					
				// Limpando tela:
					system("cls");	
		}
	
	// Edicao do Piloto:
		void edicao_piloto() {
			// Limpando o buffer do teclado:
				fflush(stdin);
				
			// Criando/Abrindo o Arquivo TXT:
				abrir();
				
			// Setando o ponteiro ao final do arquivo:
				fseek(filePointer, 0, SEEK_END);
			
			// Impressao de qual tarefa sera realizada:
				printf("\n\t\t ============= EDICAO DE PILOTO =============\n"); 
					
			// Chacando se a variavel possui dados:
				if(pilotoPointer != NULL) {
					// Impressão do array:
						int n;
						
						for(n=0; n<length; n++) {
							printf("\n\t\t Grupo %i:\r\n", n);
							
							printf("\t\t Nome: %s", (pilotoPointer+n)->nome);
							printf("\t\t Nacionalidade: %s", (pilotoPointer+n)->nacionalidade);
							printf("\t\t Cor de Pele: %s", (pilotoPointer+n)->corPele);
							printf("\t\t Cor dos Olhos: %s", (pilotoPointer+n)->corOlhos);
							printf("\t\t Cor do Cabelo: %s", (pilotoPointer+n)->corCabelo);
							printf("\t\t Altura: %i\n", (pilotoPointer+n)->altura);
							printf("\t\t Peso: %i\n", (pilotoPointer+n)->peso);
							printf("\t\t Idade: %i\n", (pilotoPointer+n)->idade);
							printf("\t\t Qtd de Campeonatos Ganhos: %i\n", (pilotoPointer+n)->qtdCampeonatosGanhos);
							printf("\t\t Pole Position: %i\n", (pilotoPointer+n)->polePosition);
							printf("\t\t Qtd de Voltas Rapidas: %i\r\n", (pilotoPointer+n)->qtdVoltasRap);
						}
						
					// Limpando o buffer do teclado:
						fflush(stdin);
						
					// Definição da posição do grupo:
						int edition_group;
						
						printf("\n\t\t Insira em qual dos grupos deseja realizar a alteracao: ");
						scanf("%i", &edition_group);
											
					// Limpando o buffer do teclado:
						fflush(stdin);	
						
					// Selecionando o grupo e a parte de edicao:
						int edition_choice;
						
						printf("\n\t\t ======================================\n\t\t");
						printf("\n\t\t O grupo selecionado foi:\n");
						
						printf("\n\t\t 1. Nome: %s", (pilotoPointer+edition_group)->nome);
						printf("\t\t 2. Nacionalidade: %s", (pilotoPointer+edition_group)->nacionalidade);
						printf("\t\t 3. Cor de Pele: %s", (pilotoPointer+edition_group)->corPele);
						printf("\t\t 4. Cor dos Olhos: %s", (pilotoPointer+edition_group)->corOlhos);
						printf("\t\t 5. Cor do Cabelo: %s", (pilotoPointer+edition_group)->corCabelo);
						printf("\t\t 6. Altura: %i\n", (pilotoPointer+edition_group)->altura);
						printf("\t\t 7. Peso: %i\n", (pilotoPointer+edition_group)->peso);
						printf("\t\t 8. Idade: %i\n", (pilotoPointer+edition_group)->idade);
						printf("\t\t 9. Qtd de Campeonatos Ganhos: %i\n", (pilotoPointer+edition_group)->qtdCampeonatosGanhos);
						printf("\t\t 10. Pole Position: %i\n", (pilotoPointer+edition_group)->polePosition);
						printf("\t\t 11. Qtd de Voltas Rapidas: %i\r\n", (pilotoPointer+edition_group)->qtdVoltasRap);
						
						printf("\n\t\t Selecione um numero para editar uma informacao: ");
						scanf("%i", &edition_choice);
						
						// Limpando o buffer do teclado:
							fflush(stdin);
						
					// Editando:					
						switch (edition_choice) {
							case 1:							
								printf("Insira o novo nome: ");
								scanf("%s\n", ((pilotoPointer+edition_group)->nome), stdin);
									
								break;
							case 2:
								printf("Insira a nova nacionalidade: ");
								scanf("%s\n", ((pilotoPointer+edition_group)->nacionalidade), stdin);
								
								break;
							case 3:
								printf("Insira a nova cor de pele: ");
								scanf("%s\n", ((pilotoPointer+edition_group)->corPele), stdin);
								
								break;
							case 4:
								printf("Insira a nova cor dos olhos: ");
								scanf("%s\n", ((pilotoPointer+edition_group)->corOlhos), stdin);
								
								break;
							case 5:
								printf("Insira a nova cor de cabelo: ");
								scanf("%s\n", ((pilotoPointer+edition_group)->corCabelo), stdin);
								
								break;
							case 6:
								printf("Insira a nova altura: ");
								scanf("%i", ((pilotoPointer+edition_group)->altura));
								
								break;
							case 7:
								printf("Insira o novo peso: ");
								scanf("%i", ((pilotoPointer+edition_group)->peso));
								
								break;
							case 8:
								printf("Insira a nova idade: ");
								scanf("%i", ((pilotoPointer+edition_group)->idade));
								
								break;
							case 9:
								printf("Insira a nova quantidade de campeonatos ganhos: ");
								scanf("%i", ((pilotoPointer+edition_group)->qtdCampeonatosGanhos));
								
								break;
							case 10:
								printf("Insira a nova pole position: ");
								scanf("%i", ((pilotoPointer+edition_group)->polePosition));
								
								break;
							case 11:
								printf("Insira a nova quantidade de voltas rapidas: ");
								scanf("%i", ((pilotoPointer+edition_group)->qtdVoltasRap));
								
								break;					
						}
						
						// Gravando no arquivo txt:
							for (n=0; n<length; n++) {
								fprintf(filePointer, "%s\n", "INSERCAO DE DADOS FEITA NA EDICAO DE PILOTO:");
								fprintf(filePointer, "%s", ((pilotoPointer+n)->nome));
								fprintf(filePointer, "%s", ((pilotoPointer+n)->nacionalidade));
								fprintf(filePointer, "%s", ((pilotoPointer+n)->corPele));
								fprintf(filePointer, "%s", ((pilotoPointer+n)->corOlhos));
								fprintf(filePointer, "%s", ((pilotoPointer+n)->corCabelo));
								fprintf(filePointer, "%i\n", ((pilotoPointer+n)->altura));
								fprintf(filePointer, "%i\n", ((pilotoPointer+n)->peso));
								fprintf(filePointer, "%i\n", ((pilotoPointer+n)->idade));
								fprintf(filePointer, "%i\n", ((pilotoPointer+n)->qtdCampeonatosGanhos));
								fprintf(filePointer, "%i\n", ((pilotoPointer+n)->polePosition));
								fprintf(filePointer, "%i\n", ((pilotoPointer+n)->qtdVoltasRap));
							}
					
					// Fechando o arquivo txt:
						fechar();
						
				} else {
					printf("\n\t\t Primeiramente, faca um cadastramento de\n\t\t piloto para que consiga realizar uma edicao!");
				}
		}
	
	// Exclusao do Piloto:
		void excluir_piloto() {
			// Limpando o buffer do teclado:
				fflush(stdin);
				
			// Criando/Abrindo o Arquivo TXT:
				abrir();
				
			// Setando o ponteiro ao final do arquivo:
				fseek(filePointer, 0, SEEK_END);
			
			// Impressao de qual tarefa sera realizada:
				printf("\n\t\t ============= EXCLUSAO DE PILOTO =============\n"); 
					
			// Chacando se a variavel possui dados:
				if(pilotoPointer != NULL) {
					// Impressão do array:
						int n;
						
						for(n=0; n<length; n++) {
							printf("\n\t\t Grupo %i:\r\n", n);
							
							printf("\t\t Nome: %s", (pilotoPointer+n)->nome);
							printf("\t\t Nacionalidade: %s", (pilotoPointer+n)->nacionalidade);
							printf("\t\t Cor de Pele: %s", (pilotoPointer+n)->corPele);
							printf("\t\t Cor dos Olhos: %s", (pilotoPointer+n)->corOlhos);
							printf("\t\t Cor do Cabelo: %s", (pilotoPointer+n)->corCabelo);
							printf("\t\t Altura: %i\n", (pilotoPointer+n)->altura);
							printf("\t\t Peso: %i\n", (pilotoPointer+n)->peso);
							printf("\t\t Idade: %i\n", (pilotoPointer+n)->idade);
							printf("\t\t Qtd de Campeonatos Ganhos: %i\n", (pilotoPointer+n)->qtdCampeonatosGanhos);
							printf("\t\t Pole Position: %i\n", (pilotoPointer+n)->polePosition);
							printf("\t\t Qtd de Voltas Rapidas: %i\r\n", (pilotoPointer+n)->qtdVoltasRap);
						}
						
					// Limpando o buffer do teclado:
						fflush(stdin);
						
					// Definição da posição do grupo:
						int exclusion_group;
						
						printf("\n\t\t Escolha qual grupo deseja deletar: ");
						scanf("%i", &exclusion_group);
											
					// Limpando o buffer do teclado:
						fflush(stdin);	
						
					// Grupo selecionado para exclusao:
						printf("\n\t\t ======================================\n\t\t");
						printf("\n\t\t O grupo selecionado foi:\n");
						
						printf("\n\t\t Nome: %s", (pilotoPointer+exclusion_group)->nome);
						printf("\t\t Nacionalidade: %s", (pilotoPointer+exclusion_group)->nacionalidade);
						printf("\t\t Cor de Pele: %s", (pilotoPointer+exclusion_group)->corPele);
						printf("\t\t Cor dos Olhos: %s", (pilotoPointer+exclusion_group)->corOlhos);
						printf("\t\t Cor do Cabelo: %s", (pilotoPointer+exclusion_group)->corCabelo);
						printf("\t\t Altura: %i\n", (pilotoPointer+exclusion_group)->altura);
						printf("\t\t Peso: %i\n", (pilotoPointer+exclusion_group)->peso);
						printf("\t\t Idade: %i\n", (pilotoPointer+exclusion_group)->idade);
						printf("\t\t Qtd de Campeonatos Ganhos: %i\n", (pilotoPointer+exclusion_group)->qtdCampeonatosGanhos);
						printf("\t\t Pole Position: %i\n", (pilotoPointer+exclusion_group)->polePosition);
						printf("\t\t Qtd de Voltas Rapidas: %i\r\n", (pilotoPointer+exclusion_group)->qtdVoltasRap);
						
						printf("\n\t\t O grupo selecionado será removido no momento de gravação no arquivo!");
						
					// Excluindo:
						// Gravando no arquivo txt:
							for (n=0; n<length; n++) {
								if (length == exclusion_group) {
									n++;
								}
								
								fprintf(filePointer, "%s\n", "INSERCAO DE DADOS FEITA ATRAVES DA EXCLUSAO DE PILOTO:");
								fprintf(filePointer, "%s", ((pilotoPointer+n)->nome));
								fprintf(filePointer, "%s", ((pilotoPointer+n)->nacionalidade));
								fprintf(filePointer, "%s", ((pilotoPointer+n)->corPele));
								fprintf(filePointer, "%s", ((pilotoPointer+n)->corOlhos));
								fprintf(filePointer, "%s", ((pilotoPointer+n)->corCabelo));
								fprintf(filePointer, "%i\n", ((pilotoPointer+n)->altura));
								fprintf(filePointer, "%i\n", ((pilotoPointer+n)->peso));
								fprintf(filePointer, "%i\n", ((pilotoPointer+n)->idade));
								fprintf(filePointer, "%i\n", ((pilotoPointer+n)->qtdCampeonatosGanhos));
								fprintf(filePointer, "%i\n", ((pilotoPointer+n)->polePosition));
								fprintf(filePointer, "%i\n", ((pilotoPointer+n)->qtdVoltasRap));
							}
					
					// Fechando o arquivo txt:
						fechar();
						
				} else {
					printf("\n\t\t Primeiramente, faca um cadastramento de\n\t\t piloto para que consiga realizar uma exclusao!");
				}
		}
		
	// Leitura de Arquivo:
		void imprimir_piloto() {
			system("cls");
			printf("========== IMPRESSAO DADOS DO ARQUIVO PILOTO ==========\n\n");
			system(" type arquivo_pilotos.txt");
			printf("\n\n============================== FIM ==============================\n\t\t");
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
		
