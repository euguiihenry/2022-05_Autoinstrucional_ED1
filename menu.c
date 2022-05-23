#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Methods.h"
#include "piloto.h"

// Menu Principal:
	int main() {
		// Variável:
			int count;
		
		// Processamento:
			do{
				printf("\n\n");    
		
				printf("\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",3017,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3003);
				printf("\t\t\t%c     Formula 1      %c\n",3002,3002);
				printf("\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",3016,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3004);
				
				printf("\n\n\t\t  1  %c   CADASTRAR\n\n\t\t  2  %c   EDITAR\n\n\t\t  3  %c   EXCLUIR\n\n\t\t  4  %c   LISTAR\n\n\t\t  5  %c   PODIO\n\n\t\t  6  %c   SAIR\n\n",16,16,16,16,16,16,16,136,16);
				printf("\t\t ____________________________________________   \n\n\t\t  %c     ",26);
					
		
				scanf("\n%d",&count);
				
				switch(count){
					case 1:
						//cadastramento_equipe();
						cadastramento_piloto();
					case 2: 
						//editar();
						break;
					
					case 3: 
						//excluir();
						break;
					
					case 4:
						//imprimir();
						break;
					
					case 5:
						//ehCreaque();
						break;
		
					case 6:
						sair();
						break;
		
					default:
						printf("Insira uma opção válida!");
						break;
					}
						
				}while(count != 6);
			
		return 0;
	}
