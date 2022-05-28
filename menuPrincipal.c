#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Piloto.h"
#include "Carro.h"
//#include "Equipe.h"

// Menu Principal:
	int main() {
		// Variável:
			int count;
		
		// Processamento:
			do{
				printf("\n\n\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",3017,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3003);
				printf("\t\t\t%c     Formula 1      %c\n",3002,3002);
				printf("\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",3016,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3004);
				
				printf("\n\n\t\t  1  %c   CADASTRAR\n\n\t\t  2  %c   EDITAR\n\n\t\t  3  %c   EXCLUIR\n\n\t\t  4  %c   LISTAR\n\n\t\t  5  %c   PODIO\n\n\t\t  6  %c   SAIR DO PROGRAMA\n\n",16,16,16,16,16,16,16,136,16);
				printf("\t\t ____________________________________________   \n\n\t\t  %c     ",26);
		
				scanf("\n%d",&count);
				
				switch(count){
					case 1:
						do{
							printf("\n\t\t ____________________________________________");
							printf("\n\n\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",3017,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3003);
							printf("\t\t\t%c   CADASTRAMENTO    %c\n",3002,3002);
							printf("\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",3016,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3004);
				
							printf("\n\n\t\t ESCOLHA A OPCAO DESEJADA:  \n\n");
							printf("\t\t  1  %c   CADASTRAR EQUIPE\n\n\t\t  2  %c   CADASTRAR CARRO\n\n\t\t  3  %c   CADASTRAR PILOTO\n\n\t\t  4  %c   VOLTAR AO MENU PRINCIPAL\n\n",16,16,16,16,16,16,16,136,16);
							printf("\t\t ____________________________________________   \n\n\t\t  %c     ",26);
							scanf("\n%d",&count);
				
							
								switch(count){
									case 1:
										//cadastrar_equipe();
										break;
									case 2:
										cadastrar_carro();
										break;
									case 3:
										cadastrar_piloto();
										break;
									case 4:
										break;
									default:
										printf("\n\t\t  Insira uma opcao valida!");
										break;
								}
							
						}while(count != 4);
					break;	
					
					case 2: 
						do{
							printf("\n\t\t ____________________________________________");
							printf("\n\n\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",3017,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3003);
							printf("\t\t\t%c       EDICAO       %c\n",3002,3002);
							printf("\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",3016,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3004);
							printf("\n\n\t\t ESCOLHA A OPCAO DESEJADA:  \n\n");
							printf("\t\t  1  %c   EDITAR EQUIPE\n\n\t\t  2  %c   EDITAR CARRO\n\n\t\t  3  %c   EDITAR PILOTO\n\n\t\t  4  %c   VOLTAR AO MENU PRINCIPAL\n\n",16,16,16,16,16,16,16,136,16);
							printf("\t\t ____________________________________________   \n\n\t\t  %c     ",26);
							scanf("\n%d",&count);
							
							
								switch(count){
									case 1:
										//editarEquipe();
										break;
									case 2:
										//editarCarro();
										break;
									case 3:
										editar_piloto();
										break;
									case 4:
										break;
										
									default:
										printf("\n\t\t  Insira uma opcao valida!");
										break;
								}
							
						}while(count != 4);
						break;
					case 3:
						do{
							printf("\n\t\t ____________________________________________");
							printf("\n\n\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",3017,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3003);
							printf("\t\t\t%c       EXCLUSAO     %c\n",3002,3002);
							printf("\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",3016,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3004);
							printf("\n\n\t\t ESCOLHA A OPCAO DESEJADA:  \n\n");
							printf("\t\t  1  %c   EXCLUIR EQUIPE\n\n\t\t  2  %c   EXCLUIR CARRO\n\n\t\t  3  %c   EXCLUIR PILOTO\n\n\t\t  4  %c   VOLTAR AO MENU PRINCIPAL\n\n",16,16,16,16,16,16,16,136,16);
							printf("\t\t ____________________________________________   \n\n\t\t  %c     ",26);
							scanf("\n%d",&count);
							
							
								switch(count){
									case 1:
										//excluir_equipe();
										break;
									case 2:
										//excluir_carro();
										break;
									case 3:
										excluir_piloto();
										break;
									case 4:
										break;
									default:
										printf("\n\t\t  Insira uma opcao valida!");
										break;
								}
								
						}while(count != 4);
						break;
					
					case 4:
						do{
							printf("\n\t\t ____________________________________________");
							printf("\n\n\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",3017,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3003);
							printf("\t\t\t%c       LISTAR       %c\n",3002,3002);
							printf("\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",3016,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3004);
							printf("\n\n\t\t ESCOLHA A OPCAO DESEJADA:  \n\n");
							printf("\t\t  1  %c   LISTAR EQUIPE\n\n\t\t  2  %c   LISTAR CARRO\n\n\t\t  3  %c   LISTAR PILOTO\n\n\t\t  4  %c   LISTAR TUDO\n\n\t\t  5  %c   VOLTAR AO MENU PRINCIPAL\n\n",16,16,16,16,16,16,16,136,16);
							printf("\t\t ____________________________________________   \n\n\t\t  %c     ",26);
							scanf("\n%d",&count);
							
							
								switch(count){
									case 1:
										//listar_equipe();
										break;
									case 2:
										//listar_carro();
										break;
									case 3:
										imprimir_piloto();
										break;
									case 4:
										//listarEquipe();
										//printf("\t\t ____________________________________________   \n\n\t\t  %c     ",26);
										//listarCarro();
										//printf("\t\t ____________________________________________   \n\n\t\t  %c     ",26);
										//listarPiloto();
										break;
									case 5:
										break;
									default:
										printf("\n\t\t  Insira uma opcao valida!\n");
										break;
								}
						}while(count != 5);
						break;
					
					case 5:
							printf("\n\t\t ____________________________________________");
							printf("\n\n\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",3017,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3003);
							printf("\t\t\t%c        PODIO       %c\n",3002,3002);
							printf("\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",3016,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3004);
							
						ehCraque();
						break;
		
					case 6:
						printf("\t\t ____________________________________________\n\n");
						printf("\t\t Desenvolvido por:\n\n");
						printf("\t\t Arthur Gomes   \n");
						printf("\t\t Guilherme Henrique   \n");
						printf("\t\t Karen Moreira   \n");
						printf("\t\t Matheus de Oliveira   \n");
						printf("\n\n\t\t CIENCIA DA COMPUTACAO - 02/2022");
						
						break;
		
					default:
						printf("\n\t\t  Insira uma opcao valida!\n");
						printf("\n\t\t ____________________________________________   \n\n");
						break;
					}
						
				}while(count != 6);
			
		return 0;
	}
