#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define TAM 20

/* Carregando funcoes:
==========================================================================================================*/
	void cadastrar_carros();
	void abrir_arqCarro();
	void criar_arqCarro();
	void fechar_arqCarro();
	void editar_carro();
	void contCadastroscar();
	void excluir_carro();
	void imprimir_carro();
/* Struct:
==========================================================================================================*/
	/* Estrutura:
	======================================================================================================*/
		struct carro {
			int grupo;
			char nome[51];
    		int comprimento;
    		int largura;
    		int altura;
    		int peso;
    		char marcaMotor[51];
    		char tipoMotor[51];
    		int aceleracao;
    		int capacidadeCombustivel;
    		int caixaCambio;
    		int aroRoda;
    		int qtdEtanol;
			
		};
		
		/* Variavel Global 1:
	======================================================================================================*/
		struct carro c[TAM];
	
/* Lidando com arquivos:
==========================================================================================================*/	
	/* Variavel Global 2:
	======================================================================================================*/
		FILE *filePointerCar;
		
	/* Funcoes:
	======================================================================================================*/
		void abrir_arqCarro() {
			filePointerCar = fopen("arquivo_carros.txt", "r+");
			
			if(filePointerCar == NULL) {
				criar_arqCarro();
				fechar_arqCarro();
				filePointerCar = fopen("arquivo_carros.txt", "r+");     
			}
		}
		
		void criar_arqCarro() {
			filePointerCar = fopen("arquivo_carros.txt", "w");

			if(filePointerCar == NULL) {
				printf("Erro ao criar o arquivo!");   
				exit(1);             
			}
		}

		void fechar_arqCarro() {
			fclose(filePointerCar);
		}
/* Funcoes de Funcionalidades:
==========================================================================================================*/	
	void cadastrar_carro() {
		/* Variaveis:
		======================================================================================================*/
			int n; // Para uso no loop FOR.
			int answer; // Controle do DO WHILE.
			int group_counting;	
		/* Lidando com o arquivo de piloto.txt:
		======================================================================================================*/
			// Abrindo:
			abrir_arqCarro();	
			// Setando o ponteiro ao final da ultima informacao:
			fseek(filePointerCar, 0, SEEK_END);

			group_counting = n;
							
		/* Impressao da Tarefa:
		======================================================================================================*/
			printf("\n\t\t ========== CADASTRAMENTO DE CARRO ==========\n");
			
		/* Insercoes:
		======================================================================================================*/
			/* Coleta de Dados:
			==================================================================================================*/
			do{

			/* Variavel de controle e auxiliares:
			==========================================================================================*/
				int cont = 0;
				int entrada;
				int x;
			/* Limpando o buffer do teclado:
			==========================================================================================*/
				fflush(stdin);
					/* Variavel do Grupo:
				
							======================================================================================*/
				c[n].grupo = group_counting;
			
				do {
								
								cont = 0;
								char aux[51];
								printf("\n\t\t Insira o nome do carro: ");
								fgets(aux, 51, stdin);
								
								if (strlen(aux) == 1) {
									printf("\n\t\t Insira algum dado do tipo texto!\n");
									cont = 1;
								} else {
									for(x=0; x<strlen(aux); x++) {
										c[n].nome[x] = aux[x];
									}
									cont = 2;
								}
								
							} while (cont < 2);
				do {
					cont = 0;
					char aux[4];			
					printf("\t\t Insira o comprimento aproximado do carro (cm): ");
					fgets(aux, 4, stdin);
								
					if (isdigit(aux[1])) {
						entrada = atoi(aux);
						c[n].comprimento = entrada;
						cont = 2;
					} else {
						printf("\n\t\t Insira apenas numeros. E obedeca o formato em centimetros!\n\n");
						cont = 1;
					}
								
					fflush(stdin);
								
				} while (cont < 2);
				
				do {
					cont = 0;
					char aux[4];	
					printf("\t\t Insira a largura aproximada do carro (cm): ");
					fgets(aux, 4, stdin);
								
					if (isdigit(aux[1])) {
						entrada = atoi(aux);
						c[n].largura = entrada;
						cont = 2;
					} else {
						printf("\n\t\t Insira apenas numeros. E obedeca o formato em centimetros!\n\n");
						cont = 1;
					}
			
					fflush(stdin);
								
				} while (cont < 2);
				
				do {
					cont = 0;
					char aux[4];			
					printf("\t\t Insira a altura aproximada do carro (cm): ");
					fgets(aux, 4, stdin);
								
					if (isdigit(aux[1])) {
						entrada = atoi(aux);
						c[n].altura = entrada;
						cont = 2;
					} else {
						printf("\n\t\t Insira apenas numeros. E obedeca o formato em centimetros!\n\n");
						cont = 1;
					}
								
					fflush(stdin);
								
				} while (cont < 2);
				
				do {
					cont = 0;
					char aux[4];			
					printf("\t\t Insira o peso aproximado do carro (em kg): ");
					fgets(aux, 4, stdin);
								
					if (isdigit(aux[1])) {
						entrada = atoi(aux);
						c[n].peso = entrada;
						cont = 2;
					} else {
						printf("\n\t\t Insira apenas numeros. E desconsidere casas decimais!\n\n");
						cont = 1;
					}
					fflush(stdin);
								
				} while (cont < 2);
				
				do{
					cont = 0;	
					char aux[51];		
					printf("\t\t Insira a marca do motor do carro: ");
					fgets(aux, 51, stdin);
								
					if (strlen(aux) == 1) {
						printf("\n\t\t Insira algum dado do tipo texto!\n");
						cont = 1;
					} else {
						for(x=0; x<strlen(aux); x++) {
							c[n].marcaMotor[x] = aux[x];
						}
							cont = 2;
					}
					
				} while (cont < 2);
				
				do{
					cont = 0;
					char aux[51];			
					printf("\t\t Insira o tipo do motor do carro: ");
					fgets(aux, 51, stdin);
								
					if (strlen(aux) == 1) {
						printf("\n\t\t Insira algum dado do tipo texto!\n");
						cont = 1;
					} else {
						for(x=0; x<strlen(aux); x++) {
							c[n].tipoMotor[x]= aux[x];
						}
							cont = 2;
					}
					
				} while (cont < 2);
				
				do {
					cont = 0;
					char aux[4];
								
					printf("\t\t Insira o valor da aceleracao do carro (apenas o valor de km): ");
					fgets(aux, 4, stdin);
								
					if (isdigit(aux[1])) {
						entrada = atoi(aux);
						c[n].aceleracao = entrada;
						cont = 2;
					} else {
						printf("\n\t\t Insira apenas numeros inteiros!\n");
						cont = 1;
					}
					fflush(stdin);
								
				} while (cont < 2);
				
				do {
					cont = 0;
					char aux[4];			
					printf("\t\t Insira o capacidade do tanque de combustivel do carro (valor do volume em litros): ");
					fgets(aux, 5, stdin);
								
					if (isdigit(aux[1])) {
						entrada = atoi(aux);
						c[n].capacidadeCombustivel = entrada;
						cont = 2;
					} else {
						printf("\n\t\t Insira apenas numeros!E Desconsidere casas decimais\n");
						cont = 1;
					}
					fflush(stdin);
								
				} while (cont < 2);
				
				do {
								char aux[2];
								cont = 0;
								
								printf("\t\t Insira a quantidade de marchas da caixa de cambio do carro: ");
								fgets(aux, 2, stdin);
								if (isdigit(aux[0])) {
									entrada = atoi(aux);
									c[n].caixaCambio = entrada;
									cont = 2;
								} else {
									printf("\n\t\t Insira apenas numeros!\n\n");
									cont = 1;
								}
								fflush(stdin);
									
							} while (cont < 2);
				
				do {
					cont = 0;
					char aux[4];			
					printf("\t\t Insira o valor do aro da roda do carro (em polegadas): ");
					fgets(aux, 4, stdin);
								
					if (isdigit(aux[0])) {
						entrada = atoi(aux);
						c[n].aroRoda = entrada;
						cont = 2;
					} else {
						printf("\n\t\t Insira apenas numeros!E Desconsidere casas decimais\n");
						cont = 1;
					}
					fflush(stdin);
								
				} while (cont < 2);
				
				do {
					cont = 0;
					char aux[4];			
					printf("\t\t Insira o valor do percentual de etanol do combustivel (de 0 a 100): ");
					fgets(aux, 4, stdin);
								
					if (isdigit(aux[1])) {
						entrada = atoi(aux);
						c[n].qtdEtanol = entrada;
						cont = 2;
					} else {
						printf("\n\t\t Insira apenas numeros!E Desconsidere casas decimais\n");
						cont = 1;
					}
					fflush(stdin);
								
				} while (cont < 2);	
				
				printf("\n");
				/* Inserindo dados no arquivo:
				==================================================================================================*/
				c[n].grupo = n;
				fprintf(filePointerCar,"%i\n", c[n].grupo);
				fprintf(filePointerCar,"%s", c[n].nome);
				fprintf(filePointerCar,"%i\n", c[n].comprimento);
				fprintf(filePointerCar,"%i\n", c[n].largura);
				fprintf(filePointerCar,"%i\n", c[n].altura);
				fprintf(filePointerCar,"%i\n", c[n].peso);
				fprintf(filePointerCar,"%s", c[n].marcaMotor);
				fprintf(filePointerCar,"%s", c[n].tipoMotor);
				fprintf(filePointerCar,"%i\n", c[n].aceleracao);
				fprintf(filePointerCar,"%i\n", c[n].capacidadeCombustivel);
				fprintf(filePointerCar,"%i\n", c[n].caixaCambio);
				fprintf(filePointerCar,"%i\n", c[n].aroRoda);
				fprintf(filePointerCar,"%i\r\n", c[n].qtdEtanol);		
				/* Atualizando n:
				======================================================================================*/
				printf("\n\t\t Deseja cadastrar mais um carro\n\t\t (Digite '1' para sim OU '2' para nao): ");
				scanf("%i", &answer);
							
				if (answer == 1) {
					n++;
					group_counting++;			
				} else {
					printf("\n\t\t Cadastramento finalizado!");
				}
							
					
				
			} while (answer == 1);
			
			fechar_arqCarro();
	}
	
	void editar_carro(){
		int size;
		filePointerCar = fopen("arquivo_carros.txt", "r");
		fseek(filePointerCar, 0, SEEK_END);
		size = ftell(filePointerCar);
		
		if(size==0){
			printf("\n\t\t Arquivo vazio! Insira dados antes de tentar editar!\n"); 
							
			int final_answer;
							
			printf("\t\t Retornar ao menu anterior? (0 = NAO || 1 = SIM): ");
			scanf("%i", &final_answer);
			
			if (final_answer == 1) {
				system("cls"); // Corrigir para funcionamento com linux tbm!!!!
			}
			
			fechar_arqCarro();
		}else{
			fflush(stdin);
		
			int m=0; //size
			int answer; // Controle do DO WHILE.
			
			filePointerCar = fopen("arquivo_carros.txt", "r");
			
			printf("\n\t\t ============= EDICAO DE CARRO =============\n\n");
			
			while (!feof(filePointerCar)) {
				
				fscanf(filePointerCar, "%i\n", &c[m].grupo);
				printf("\t\t Grupo %i:\n\n", c[m].grupo);
				
				fflush(stdin);
				
				fgets(c[m].nome, 51, filePointerCar);
				printf("\t\t %s", c[m].nome);
				fflush(stdin);
				
				fscanf(filePointerCar, "%i\n",&c[m].comprimento );
				printf("\t\t %i\n", c[m].comprimento);
				
				fscanf(filePointerCar, "%i\n",&c[m].largura );
				printf("\t\t %i\n", c[m].largura);
				
				fscanf(filePointerCar, "%i\n",&c[m].altura );
				printf("\t\t %i\n", c[m].altura);
				
				fscanf(filePointerCar, "%i\n",&c[m].peso );
				printf("\t\t %i\n", c[m].peso);
				
				fgets(c[m].marcaMotor, 51, filePointerCar);
				printf("\t\t %s", c[m].marcaMotor);
				
				fgets(c[m].tipoMotor, 51, filePointerCar);
				printf("\t\t %s", c[m].tipoMotor);
				fflush(stdin);
				
				fscanf(filePointerCar, "%i\n",&c[m].aceleracao );
				printf("\t\t %i\n", c[m].aceleracao);
				
				fscanf(filePointerCar, "%i\n",&c[m].capacidadeCombustivel );
				printf("\t\t %i\n", c[m].capacidadeCombustivel);
				
				fscanf(filePointerCar, "%i\n",&c[m].caixaCambio );
				printf("\t\t %i\n", c[m].caixaCambio);
				
				fscanf(filePointerCar, "%i\n",&c[m].aroRoda );
				printf("\t\t %i\n", c[m].aroRoda);
				
				fscanf(filePointerCar, "%i\n",&c[m].qtdEtanol );
				printf("\t\t %i\n\n", c[m].qtdEtanol);
				
				m++;
				
			}
			
			fechar_arqCarro();
			
			int group;
			int editionOption;
			int y;
				    	
			printf("\t\t Qual grupo deseja editar: ");
			scanf("%i", &group); 
			
			for (y=0; y<m; y++) {
				if(y == group) {
					
					printf("\n\t\t ======================================\n\t\t");
					printf("\n\t\t O grupo selecionado foi:\n");
										
					printf("\n\t\t 1. Nome do carro: %s", c[y].nome);
					printf("\t\t 2. Comprimento: %i cm\n", c[y].comprimento);
					printf("\t\t 3. Largura: %i cm\n", c[y].largura);
					printf("\t\t 4. Altura: %i cm\n", c[y].altura);
					printf("\t\t 5. Peso: %i kg\n", c[y].peso);
					printf("\t\t 6. Marca do motor: %s", c[y].marcaMotor);
					printf("\t\t 7. Tipo do motor: %s", c[y].tipoMotor);
					printf("\t\t 8. Aceleração: %i km/h\n", c[y].aceleracao);
					printf("\t\t 9. Capacidade do tanque de combustivel: %i litros\n", c[y].capacidadeCombustivel);
					printf("\t\t 10. Quantidade de marchas: %i\n", c[y].caixaCambio);
					printf("\t\t 11. Aro da roda: %i\n", c[y].aroRoda);
					printf("\t\t 12. Quantidade de etanol na gasolina: %i %%\r\n", c[y].qtdEtanol);
										
					printf("\n\t\t Selecione um numero para editar uma informacao: ");
					scanf("%i", &editionOption);
										
					fflush(stdin);
	
				}
			}
	
			int cont;
			int x;
			//int n = group;
			int entrada;
							
			switch (editionOption){
				case 1: 
					do{
						cont = 0;
						char aux[51];
						printf("\n\t\t Insira o nome do carro: ");
						fgets(aux, 51, stdin);
										
						if (strlen(aux) == 1) {
							printf("\n\t\t Insira algum dado do tipo texto!\n");
							cont = 1;
						} else {
							for(x=0; x<=(strlen(c[group].nome)); x++) {
								c[group].nome[x] = aux[x];
							}
							cont = 2;
						}
						fflush(stdin);
					}while (cont < 2);
					break;
				
				case 2:
					do {
						cont = 0;
						char aux[4];			
						printf("\t\t Insira o comprimento aproximado do carro (cm): ");
						fgets(aux, 4, stdin);
									
						if (isdigit(aux[1])) {
							entrada = atoi(aux);
							c[group].comprimento = entrada;
							cont = 2;
						} else {
							printf("\n\t\t Insira apenas numeros. E obedeca o formato em centimetros!\n\n");
							cont = 1;
						}
						fflush(stdin);
					} while (cont < 2);	
					break;
					
				case 3:
					do {
						cont = 0;
						char aux[4];	
						printf("\t\t Insira a largura aproximada do carro (cm): ");
						fgets(aux, 4, stdin);
									
						if (isdigit(aux[1])) {
							entrada = atoi(aux);
							c[group].largura = entrada;
							cont = 2;
						} else {
							printf("\n\t\t Insira apenas numeros. E obedeca o formato em centimetros!\n\n");
							cont = 1;
						}
						
						fflush(stdin);
					} while (cont < 2);
					break;
				
				case 4:
					do {
						cont = 0;
						char aux[4];			
						printf("\t\t Insira a altura aproximada do carro (cm): ");
						fgets(aux, 4, stdin);
									
						if (isdigit(aux[1])) {
							entrada = atoi(aux);
							c[group].altura = entrada;
							cont = 2;
						} else {
							printf("\n\t\t Insira apenas numeros. E obedeca o formato em centimetros!\n\n");
							cont = 1;
						}
									
						fflush(stdin);		
					} while (cont < 2);
					break;
				
				case 5:	
					do {
						cont = 0;
						char aux[4];			
						printf("\t\t Insira o peso aproximado do carro (cm): ");
						fgets(aux, 4, stdin);
									
						if (isdigit(aux[1])) {
							entrada = atoi(aux);
							c[group].peso = entrada;
							cont = 2;
						} else {
							printf("\n\t\t Insira apenas numeros. E obedeca o formato em centimetros!\n\n");
							cont = 1;
						}
	
						fflush(stdin);
					} while (cont < 2);
					break;
				
				case 6:
					do{
						cont = 0;	
						char aux[51];		
						printf("\t\t Insira a marca do motor do carro: ");
						fgets(aux, 31, stdin);
									
						if (strlen(aux) == 1) {
							printf("\n\t\t Insira algum dado do tipo texto!\n");
							cont = 1;
						} else {
							for(x=0; x<=(strlen(c[group].marcaMotor)); x++) {
								c[group].marcaMotor[x] = aux[x];
							}
								cont = 2;
						}
						
						fflush(stdin);
					} while (cont < 2);
					break;
					
				case 7:
					do{
						cont = 0;
						char aux[51];			
						printf("\t\t Insira o tipo do motor do carro: ");
						fgets(aux, 51, stdin);
									
						if (strlen(aux) == 1) {
							printf("\n\t\t Insira algum dado do tipo texto!\n");
							cont = 1;
						} else {
							for(x=0; x<=strlen(c[group].tipoMotor); x++) {
								c[group].tipoMotor[x]= aux[x];
							}
								cont = 2;
						}
						
						fflush(stdin);
					} while (cont < 2);
					
					break;
					
				case 8:
					do {
						cont = 0;
						char aux[4];
									
						printf("\t\t Insira o valor da aceleracao do carro (apenas o valor de km): ");
						fgets(aux, 4, stdin);
									
						if (isdigit(aux[1])) {
							entrada = atoi(aux);
							c[group].aceleracao = entrada;
							cont = 2;
						} else {
							printf("\n\t\t Insira apenas numeros inteiros!\n");
							cont = 1;
						}
	
						fflush(stdin);		
					} while (cont < 2);
					break;
					
				case 9:
					do {
						cont = 0;
						char aux[4];			
						printf("\t\t Insira o capacidade do tanque de combustivel do carro (valor do volume em litros): ");
						fgets(aux, 4, stdin);
									
						if (isdigit(aux[1])) {
							entrada = atoi(aux);
							c[group].capacidadeCombustivel = entrada;
							cont = 2;
						} else {
							printf("\n\t\t Insira apenas numeros!E Desconsidere casas decimais\n");
							cont = 1;
						}
	
						fflush(stdin);		
					} while (cont < 2);
					break;
				
				case 10:	
					do {
						cont = 0;
						char aux[3];			
						printf("\t\t Insira a quantidade de marchas na caixa de cambio do carro: ");
						fgets(aux, 3, stdin);
									
						if (isdigit(aux[1])) {
							entrada = atoi(aux);
							c[group].qtdEtanol = entrada;
							cont = 2;
						} else {
							printf("\n\t\t Insira apenas numeros!\n\n");
							cont = 1;
						}
	
						fflush(stdin);			
					} while (cont < 2);
					break;
				
				case 11:	
					do {
						cont = 0;
						char aux[3];			
						printf("\t\t Insira o valor do aro da roda do carro (em polegadas): ");
						fgets(aux, 3, stdin);
									
						if (isdigit(aux[1])) {
							entrada = atoi(aux);
							c[group].aroRoda = entrada;
							cont = 2;
						} else {
							printf("\n\t\t Insira apenas numeros!E Desconsidere casas decimais\n");
							cont = 1;
						}
									
						/* Limpando o buffer do teclado:
						==============================================================================*/
						fflush(stdin);		
					} while (cont < 2);
					break;
				
				case 12:	
					do {
						cont = 0;
						char aux[4];			
						printf("\t\t Insira o valor do percentual de etanol do combustível (de 0 a 100): ");
						fgets(aux, 4, stdin);
									
						if (isdigit(aux[1])) {
							entrada = atoi(aux);
							c[group].qtdEtanol = entrada;
							cont = 2;
						} else {
							printf("\n\t\t Insira apenas numeros!E Desconsidere casas decimais\n");
							cont = 1;
						}
									
						/* Limpando o buffer do teclado:
						==============================================================================*/
						fflush(stdin);		
					} while (cont < 2);
					break;	
										
			}
			
			fflush(stdin);
						
			printf("\n\n\t\t Novos dados registrados!");
			
			criar_arqCarro();
			
			int z = 0;
			while (z < m) {
				c[z].grupo = z;
				fprintf(filePointerCar,"%i\n", c[z].grupo);
				fprintf(filePointerCar,"%s", c[z].nome);
				fprintf(filePointerCar,"%i\n", c[z].comprimento);
				fprintf(filePointerCar,"%i\n", c[z].largura);
				fprintf(filePointerCar,"%i\n", c[z].altura);
				fprintf(filePointerCar,"%i\n", c[z].peso);
				fprintf(filePointerCar,"%s", c[z].marcaMotor);
				fprintf(filePointerCar,"%s", c[z].tipoMotor);
				fprintf(filePointerCar,"%i\n", c[z].aceleracao);
				fprintf(filePointerCar,"%i\n", c[z].capacidadeCombustivel);
				fprintf(filePointerCar,"%i\n", c[z].caixaCambio);
				fprintf(filePointerCar,"%i\n", c[z].aroRoda);
				fprintf(filePointerCar,"%i\r\n", c[z].qtdEtanol);
				z++;
			}
			
			fechar_arqCarro();
			
			printf("\n\n\t\t Os novos dados foram salvos no arquivo com sucesso!\n\t\t Edicao finalizada!");
		}
	}
	
	void excluir_carro(){
		int size;
		filePointerCar = fopen("arquivo_carros.txt", "r");
		
		fseek(filePointerCar, 0, SEEK_END);
		size = ftell(filePointerCar);
		
		if (size == 0) {
			printf("\n\t\t Arquivo vazio! Insira dados antes de tentar excluir!\n");
							
			int final_answer;
							
			printf("\t\t Retornar ao menu anterior? (0 = NAO || 1 = SIM): ");
			scanf("%i", &final_answer);
							
			if (final_answer == 1) {
				system("cls"); // Corrigir para funcionamento com linux tbm!!!!
			}  	
						
			fechar_arqCarro();
			
			} else {
				fflush(stdin);
				int m = 0;
				filePointerCar = fopen("arquivo_carros.txt", "r");
				
				printf("\n\t\t =========== EXCLUSAO DE CARRO =============\n");
				while (!feof(filePointerCar)) {
			
					fscanf(filePointerCar, "%i\n", &c[m].grupo);
					printf("\t\t Grupo %i:\n\n", c[m].grupo);
					
					fflush(stdin);
					
					fgets(c[m].nome, 51, filePointerCar);
					printf("\t\t %s", c[m].nome);
					fflush(stdin);
					
					fscanf(filePointerCar, "%i\n",&c[m].comprimento );
					printf("\t\t %i\n", c[m].comprimento);
					
					fscanf(filePointerCar, "%i\n",&c[m].largura );
					printf("\t\t %i\n", c[m].largura);
					
					fscanf(filePointerCar, "%i\n",&c[m].altura );
					printf("\t\t %i\n", c[m].altura);
					
					fscanf(filePointerCar, "%i\n",&c[m].peso );
					printf("\t\t %i\n", c[m].peso);
					
					fgets(c[m].marcaMotor, 51, filePointerCar);
					printf("\t\t %s", c[m].marcaMotor);
					
					fgets(c[m].tipoMotor, 51, filePointerCar);
					printf("\t\t %s", c[m].tipoMotor);
					fflush(stdin);
					
					fscanf(filePointerCar, "%i\n",&c[m].aceleracao );
					printf("\t\t %i\n", c[m].aceleracao);
					
					fscanf(filePointerCar, "%i\n",&c[m].capacidadeCombustivel );
					printf("\t\t %i\n", c[m].capacidadeCombustivel);
					
					fscanf(filePointerCar, "%i\n",&c[m].caixaCambio );
					printf("\t\t %i\n", c[m].caixaCambio);
					
					fscanf(filePointerCar, "%i\n",&c[m].aroRoda );
					printf("\t\t %i\n", c[m].aroRoda);
					
					fscanf(filePointerCar, "%i\n",&c[m].qtdEtanol );
					printf("\t\t %i\n\n", c[m].qtdEtanol);
					
					m++;
					
				}
		
				fechar_arqCarro();
				int group;
				int exclusionOption;
				int y;
						    	
				printf("\t\t Qual grupo deseja excluir: ");
				scanf("%i", &group);
								
				for(y=0; y<m; y++){
					if(y == group) {
				
					printf("\n\t\t ======================================\n\t\t");
					printf("\n\t\t O grupo selecionado foi:\n");
										
					printf("\n\t\t 1. Nome do carro: %s", c[y].nome);
					printf("\t\t 2. Comprimento: %i cm\n", c[y].comprimento);
					printf("\t\t 3. Largura: %i cm\n", c[y].largura);
					printf("\t\t 4. Altura: %i cm\n", c[y].altura);
					printf("\t\t 5. Peso: %i kg\n", c[y].peso);
					printf("\t\t 6. Marca do motor: %s", c[y].marcaMotor);
					printf("\t\t 7. Tipo do motor: %s", c[y].tipoMotor);
					printf("\t\t 8. Aceleração: %i km/h\n", c[y].aceleracao);
					printf("\t\t 9. Capacidade do tanque de combustivel: %i litros\n", c[y].capacidadeCombustivel);
					printf("\t\t 10. Quantidade de marchas: %i\n", c[y].caixaCambio);
					printf("\t\t 11. Aro da roda: %i\n", c[y].aroRoda);
					printf("\t\t 12. Quantidade de etanol na gasolina: %i %%\r\n", c[y].qtdEtanol);
	
					}

				}
			
				fflush(stdin);
				criar_arqCarro();
				
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
											
					c[z].grupo = count_groups;
					
					fprintf(filePointerCar,"%i\n", c[z].grupo);
					fprintf(filePointerCar,"%s", c[z].nome);
					fprintf(filePointerCar,"%i\n", c[z].comprimento);
					fprintf(filePointerCar,"%i\n", c[z].largura);
					fprintf(filePointerCar,"%i\n", c[z].altura);
					fprintf(filePointerCar,"%i\n", c[z].peso);
					fprintf(filePointerCar,"%s", c[z].marcaMotor);
					fprintf(filePointerCar,"%s", c[z].tipoMotor);
					fprintf(filePointerCar,"%i\n", c[z].aceleracao);
					fprintf(filePointerCar,"%i\n", c[z].capacidadeCombustivel);
					fprintf(filePointerCar,"%i\n", c[z].caixaCambio);
					fprintf(filePointerCar,"%i\n", c[z].aroRoda);
					fprintf(filePointerCar,"%i\r\n", c[z].qtdEtanol);
					z++;
					count_groups++;
				}
			
				fechar_arqCarro();
				
				if(z == (m+1)){
					criar_arqCarro();
					fechar_arqCarro();
				}
				
				printf("\n\n\t\t Os novos dados foram salvos no arquivo com sucesso!\n\t\t Exclusao finalizada!");	
				
		}
			
	}
	
	
	
	void imprimir_carro(){
		int size;
		filePointerCar = fopen("arquivo_carros.txt", "r");
		fseek(filePointerCar, 0, SEEK_END);
		size = ftell(filePointerCar);
		
		if(size==0){
			printf("\n\t\t Arquivo vazio! Insira dados antes de tentar editar!\n"); 
							
			int final_answer;
							
			printf("\t\t Retornar ao menu anterior? (0 = NAO || 1 = SIM): ");
			scanf("%i", &final_answer);
			
			if (final_answer == 1) {
				system("cls"); // Corrigir para funcionamento com linux tbm!!!!
			}
			
			fechar_arqCarro();
		}else{
			fflush(stdin);
		
			int m=0; //size
			int answer; // Controle do DO WHILE.
			
			filePointerCar = fopen("arquivo_carros.txt", "r");
			
			printf("\n\t\t ============= LISTAGEM DE CARRO =============\n\n");
			
			while (!feof(filePointerCar)) {
				
				fscanf(filePointerCar, "%i\n", &c[m].grupo);
				printf("\t\t Grupo %i:\n\n", c[m].grupo);
				
				fflush(stdin);
				
				fgets(c[m].nome, 51, filePointerCar);
				printf("\t\t %s", c[m].nome);
				fflush(stdin);
				
				fscanf(filePointerCar, "%i\n",&c[m].comprimento );
				printf("\t\t %i\n", c[m].comprimento);
				
				fscanf(filePointerCar, "%i\n",&c[m].largura );
				printf("\t\t %i\n", c[m].largura);
				
				fscanf(filePointerCar, "%i\n",&c[m].altura );
				printf("\t\t %i\n", c[m].altura);
				
				fscanf(filePointerCar, "%i\n",&c[m].peso );
				printf("\t\t %i\n", c[m].peso);
				
				fgets(c[m].marcaMotor, 51, filePointerCar);
				printf("\t\t %s", c[m].marcaMotor);
				
				fgets(c[m].tipoMotor, 51, filePointerCar);
				printf("\t\t %s", c[m].tipoMotor);
				fflush(stdin);
				
				fscanf(filePointerCar, "%i\n",&c[m].aceleracao );
				printf("\t\t %i\n", c[m].aceleracao);
				
				fscanf(filePointerCar, "%i\n",&c[m].capacidadeCombustivel );
				printf("\t\t %i\n", c[m].capacidadeCombustivel);
				
				fscanf(filePointerCar, "%i\n",&c[m].caixaCambio );
				printf("\t\t %i\n", c[m].caixaCambio);
				
				fscanf(filePointerCar, "%i\n",&c[m].aroRoda );
				printf("\t\t %i\n", c[m].aroRoda);
				
				fscanf(filePointerCar, "%i\n",&c[m].qtdEtanol );
				printf("\t\t %i\n\n", c[m].qtdEtanol);
				
				m++;
				
			}
			
			printf("\t\t Retornar ao menu anterior? (0 = NAO || 1 = SIM): ");
			scanf("%i", &answer);
								
			if (answer == 1) {
				system("cls"); // Corrigir para funcionamento com linux tbm!!!!
			}
			
			fechar_arqCarro();
			
		}
		
		
		
	}
	
