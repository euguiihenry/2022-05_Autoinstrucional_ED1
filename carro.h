#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void cadastroCarro();
void abrir();
void fechar();
	
	//declaracao de variaveis
    FILE *filePointer;

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
		}
	
           //funcoes
			void abrir(){
				
				filePointer = fopen("./TextFiles/carro.txt", "w");
				
				if(filePointer == NULL){
					printf("ERROR!");
					exit(1);
				}
			}
		
			void fechar(){
				
		 	    fclose(filePoiter);
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
					fgets(c.nome, 51, stin);
					
					
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
							
					
//exclusao do carro:
void excluirCarro(){
	char carro;
	void strlen (nome);
		
	for(int x = 0; x < strlen; x++){
			if(nome[x] < '0' || nome[x] > '9'){
			flag = 1;
			break;
		}
	}
}


// Impressao do carro:
		
					
}