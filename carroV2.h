#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void cadastramento_carro();
	void edicao_carro();
	void imprimir_carro();
	void excluir_carro();
	void abrir();
	void criar();
	void fechar();
	
	//declaracao de variaveis

// estrutura
	struct carro {
   		char nome[51];
    	float comprimento;
    	float largura;
    	float altura;
    	float peso;
    	char marcaMotor[31];
    	char tipoMotor[31];
    	float aceleracao;
    	float capacidadeCombustivel;
    	int caixaCambio;
    	int aroRoda;
    	float qtdEtanol;
		};
		
		FILE *filePointer;
		struct carro *carroPointer;
		int length;
	
           //funcoes
			void abrir() {
			filePointer = fopen("arquivo_carros.txt", "r+");
			
			if(filePointer == NULL) {
				criar();
				fechar();
				abrir();          
			}
		}
		
		void criar() {
			filePointer = fopen("arquivo_carros.txt", "w");

			if(filePointer == NULL) {
				printf("Erro ao criar o arquivo!");   
				exit(1);             
			}
		}

		void fechar() {
			fclose(filePointer);
		}
	
	    //cadastramento do carro
        void cadastroCarro(){
		
		    //declaranco um apelido
				struct carro c;
				
			//metodo para abrir o arquivo txt	
				abrir();
				
			// limpando a memoria
				fflush(stdin);
				
				// impressao de qual item sera chamado
				printf("\n\t\t =============== CADASTRAMENTO DO CARRO =================\n");
				
				
				// nome
					printf("Nome do carro:");		
					fgets(c.nome, 51, stdin);
					
					
                // comprimento do carro
					printf("\nComprimento do carro:");
					scanf("%f", &c.comprimento);
    
    
               // largura do carro
					printf("\nLargura do carro:");
					scanf("%f", &c.largura);
    
    
                // altura do carro
					printf("\nAltura do carro:");
					scanf("%f", &c.altura);
					
					
                //peso do carro
					printf("\nPeso do carro:");
					scanf("%f", &c.peso);
    
    
                //marca do carro
					printf("Marca do motor:");
					fgets(c.marcaMotor, 31, stdin );
    
    
               //Tipo de motor
					printf("Tipo de motor:");
					fgets(c.tipoMotor, 31, stdin );
   
   
               //Aceleracao 
					printf("\nAceleração (0 a 100 km/h):");
					scanf("%f", &c.aceleracao);
    
    
                //capacidade do tanque
					printf("\nCapacidade do tanque de combustivel:");
					scanf("%f", &c.capacidadeCombustivel);
    
    
               // caixa de cambio
					printf("\nCaixa de cambio:");
					scanf("%i", &c.caixaCambio);
    
    
               //aro da roda
					printf("\nAro da roda:");
					scanf("%i", &c.aroRoda);
    
    
    	       //quantidade de etanol 
					printf("\nQuantidade de etanol no combustivel:");
					scanf("%f", &c.qtdEtanol);
					
				//integrando od dados do arquvo
					fprintf(filePointer, "%s", c.nome);
					
				//fechando o arquivo TXT
					fechar();
}
							
					
//exclusao do carro:
void excluirCarro(){
			fflush(stdin);
				
			// Criando/Abrindo o Arquivo TXT:
				abrir();
				
			// Setando o ponteiro ao final do arquivo:
				fseek(filePointer, 0, SEEK_END);
			
			// Impressao de qual tarefa sera realizada:
				printf("\n\t\t ============= EXCLUSAO DE CARRO =============\n"); 
					
			// Chacando se a variavel possui dados:
				if(carroPointer != NULL) {
					// Impressão do array:
						int n;
						
						for(n=0; n<length; n++) {
							printf("\n\t\t Grupo %i:\r\n", n);
							
							printf("\t\t Nome: %s", (carroPointer+n)->nome);
							printf("\t\t Comprimento: %f", (carroPointer+n)->comprimento);
							printf("\t\t Largura: %f", (carroPointer+n)->largura);
							printf("\t\t Altura: %f", (carroPointer+n)->altura);
							printf("\t\t Marca do motor: %s", (carroPointer+n)->marcaMotor);
							printf("\t\t Tipo de motor: %s", (carroPointer+n)->tipoMotor);
							printf("\t\t Aceleracao: %f", (carroPointer+n)->aceleracao);
							printf("\t\t Capacidade de combustivel: %f\n", (carroPointer+n)->capacidadeCombustivel);
							printf("\t\t Caixa de Cambio: %i\n", (carroPointer+n)->caixaCambio);
							printf("\t\t Aro da roda: %i\n", (carroPointer+n)->aroRoda);
							printf("\t\t Qtd de etanol: %f\r\n", (carroPointer+n)->qtdEtanol);
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
						
						printf("\t\t Nome: %s", (carroPointer+exclusion_group)->nome);
						printf("\t\t Comprimento: %f", (carroPointer+exclusion_group)->comprimento);
						printf("\t\t Largura: %f", (carroPointer+exclusion_group)->largura);
						printf("\t\t Altura: %f", (carroPointer+exclusion_group)->altura);
						printf("\t\t Marca do motor: %s", (carroPointer+exclusion_group)->marcaMotor);
						printf("\t\t Tipo de motor: %s", (carroPointer+exclusion_group)->tipoMotor);
						printf("\t\t Aceleracao: %f", (carroPointer+exclusion_group)->aceleracao);
						printf("\t\t Capacidade de combustivel: %f\n", (carroPointer+exclusion_group)->capacidadeCombustivel);
						printf("\t\t Caixa de Cambio: %i\n", (carroPointer+exclusion_group)->caixaCambio);
						printf("\t\t Aro da roda: %i\n", (carroPointer+exclusion_group)->aroRoda);
						printf("\t\t Qtd de etanol: %f\r\n", (carroPointer+exclusion_group)->qtdEtanol);
						
						
						printf("\n\t\t O grupo selecionado será removido no momento de gravação no arquivo!");
						
					// Excluindo:
						// Gravando no arquivo txt:
							for (n=0; n<length; n++) {
								if (length == exclusion_group) {
									n++;
								}
								
								fprintf(filePointer, "%s\n", "INSERCAO DE DADOS FEITA ATRAVES DA EXCLUSAO DE PILOTO:");							
								fprintf(filePointer, "%s", ((carroPointer+n)->nome));
								fprintf(filePointer, "%f", ((carroPointer+n)->comprimento));
								fprintf(filePointer, "%f", ((carroPointer+n)->largura));
								fprintf(filePointer, "%f", ((carroPointer+n)->altura));
								fprintf(filePointer, "%s", ((carroPointer+n)->marcaMotor));
								fprintf(filePointer, "%s\n", ((carroPointer+n)->tipoMotor));
								fprintf(filePointer, "%f\n", ((carroPointer+n)->aceleracao));
								fprintf(filePointer, "%f\n", ((carroPointer+n)->capacidadeCombustivel));
								fprintf(filePointer, "%i\n", ((carroPointer+n)->caixaCambio));
								fprintf(filePointer, "%i\n", ((carroPointer+n)->aroRoda));
								fprintf(filePointer, "%f\n", ((carroPointer+n)->qtdEtanol));
							}
					
					// Fechando o arquivo txt:
						fechar();
						
				} else {
					printf("\n\t\t Primeiramente, faca um cadastramento de\n\t\t carro para que consiga realizar uma exclusao!");
				}
}


// Impressao do carro:
		
					

