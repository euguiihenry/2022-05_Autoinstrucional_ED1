#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void cadastramento_equipe() {   //FUNCAO DE CADASTRAMENTO
      int i;
      char nome[51];
      char nacionalidade[21];
      int qtddMembros; 
      int qtddTitulosConstrutores; 
      int qtddTitulosCondutores; 
      int poliPositions; 
      int qtddVoltasMaisRap; 
      float valorMercado;
      float taxaIncricaoTemp; 
      char coresEquipe[31]; 
      char chefeEquipe[21]; 
      char diretorComercial[21]; 
      char diretorTecnico[21]; 
      char aeroDinamicChefe[21];
      char projetistaChefe[21]; 
      char ChefePesqEhDev[21]; 
      char ChefeMecanico[21]; 
      char tecnicoPneus[21];
      char tecnicoComponentes[21]; 
      char tecnicoTransmissao[21]; 
      char tecnicoCombustivel[21];
      char mecanicosPitStop[21][21]; 
	
      for(i=0; i<3; i++){
            printf("\n\n");   
            printf("\t\t ~~~~~~~~~~~~~~~~  CADASTRAMENTO  ~~~~~~~~~~~~~~~~\n\n");
            printf("\t\t ~~~~~~~~~~~~~~~~~~  DE  DADOS  ~~~~~~~~~~~~~~~~~~\n\n");
            printf("\n\n");
            printf("\n\n");
            
            printf("Por favor, preencha os campos abaixo. \n\n");                          

            fflush(stdin);      //Limpar Buffer do Teclado
            printf("Nome: ");
            gets(nome);
						
            printf("Nacionalidade: ");
            gets(nacionalidade);
            
            printf("Quantidade de membros: ");
            scanf("%i", &qtddTitulosConstrutores);
            
            printf("Quantidade de titulos contrutores: ");
            scanf("%i", &qtddTitulosCondutores);
            
            printf("Poli positions: ");
            scanf("%i", &poliPositions);
            
            printf("Quantidade de voltas mais rapidas: ");
            scanf("%i", &qtddVoltasMaisRap);
            
            printf("Valor do mercado: ");
            scanf("%f", &valorMercado);
            
            printf("Valor da taxa de inscri��o: ");
            scanf("%f", &taxaIncricaoTemp);
            
            printf("Cores de equipe : ");
            gets(coresEquipe);
            
            printf("Chefe de equipe: ");
            gets(chefeEquipe);
            
            printf("Diretor Comercial: ");
            gets(diretorComercial);
            
            printf("Diretor Tecnico: ");
            gets(diretorTecnico);
            
            printf("Chefe dinamico: ");
            gets(aeroDinamicChefe);
            
            printf("Projetista Chefe: ");
            gets(projetistaChefe);
            
            printf("Chefe de Pesquisa e Desenvolvimento: ");
            gets(ChefePesqEhDev);
            
            printf("Chefe Mecanico: ");
            gets(ChefeMecanico);
            
            printf("Tecnico de Pneus: ");
            gets(tecnicoPneus);
            
            printf("Tecnicos de Componentes: ");
            gets(tecnicoComponentes);
            
            printf("Tecnico de Transmissao: ");
            gets(tecnicoTransmissao);
            
            printf("Tecnico de Combustiveis: ");
            gets(tecnicoCombustivel);
						
            for(int i = 0; i<21; i++){
                  printf("Mecanico Pit Stop: ");
                  gets(mecanicosPitStop[i]);

                  printf("\n\n");
                  printf("    Cadastro concluido com sucesso!   ",3745); 
                  printf("\n\n");
			printf("\n\n");
                  system("PAUSE");

                  printf("\n\n");
                  
                  break;
            }
      }
}

void sair() {
	printf("\n\t\t Bye-bye :)");
	//system("exit");
	exit(0);
}


/*
if(cont < TAM){
              system("cls");
              printf("\t\tDeseja continuar?   \n\n");
              printf(" 1 - Sim   \n\n 2 - n�o\n\n");
              scanf("%d",&continuar);
              while(continuar!=1 && continuar!=2)
                {
                system("cls");
                printf("\t\tDeseja continuar?   \n\n");
                printf(" 1 - Sim   \n\n 2 - n�o\n\n");
                scanf("%d",&continuar);                   
                }
             
             if(continuar==1)
                            {
                            CADASTRAMENTO();
                            }

               }


if(cont == TAM)
              {
               printf("\n\n No momento, a agenda esta cheia! \n\n");
               system("pause");
              } 
       
}



//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void PESQUISA() // FUN��O  PESQUISA
     {
     int i;
     char nome_busca[50];
     int nao_tem=999;
     system("cls");
     fflush(stdin); //Limpar Buffer do Teclado
     printf(" Informe o <Nome Completo> %c   ",26);
     gets(nome_busca);
           
     for(i=0; i<TAM; i++)
     {
             if(agenda[i].tel!=7777777)
             {
                         if(strcmp(agenda[i].nome,nome_busca)==0) // So vai listar as Fichas com os Nomes iguais aos digitados.
                         {

                          printf(" ------------------------------------------------------------------\n");                        
                          printf(" Nome Completo:  %s",agenda[i].nome);
                          printf("\n\n");
                          printf(" Data de Nascimento:  %d / %d / %d",agenda[i].data.dia,agenda[i].data.mes,agenda[i].data.ano);
                          printf("\n\n");
                          printf(" DDD:  %c%c",agenda[i].ddd[0],agenda[i].ddd[1]);
                          printf("\n\n");
                          printf(" Telefone: %d",agenda[i].tel); 
                          printf("\n\n"); 
                          printf(" Endereco: %s",agenda[i].endereco);
                          printf("\n\n"); 
                          printf(" E_mail:  %s",agenda[i].e_mail);
                          printf("\n\n");
                          printf(" Website:  %s",agenda[i].site);
                          printf("\n\n");
                          printf(" Observacoes:  %s",agenda[i].obs);
                          printf("\n\n");
                          printf(" ------------------------------------------------------------------\n");  
                     
                          nao_tem=0;
                          }
             }
     }
            
    
     if(nao_tem==999){
                      system("cls");
                      printf("\n  n�o foi encontrado nenhum dado correspondente. \n\n");
                      printf("  Certifique-se de que todas as palavras estejam escritas corretamente.\n\n\n\n\n\n");
                      }
                      
     system("PAUSE");                
     system("cls");
     printf("\t\tDeseja continuar?   \n\n");
     printf(" 1 - Sim   \n\n 2 - n�o\n\n");
     scanf("%d",&continuar);
     
     while(continuar!=1 && continuar!=2)
                                       {
                                       system("cls");
                                       printf("\t\tDeseja continuar?   \n\n");
                                       printf(" 1 - Sim   \n\n 2 - n�o\n\n");
                                       scanf("%d",&continuar);                   
                                       }
             
      if(continuar==1)
      {
      PESQUISA();
      } 
                             

      system("cls");
      }

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void AJUDA(void) // FUN��O  AJUDA
{
    int b;

    
    do{
       system("cls");
       printf("\n\n");   
       printf("\t\t ~~~~~~~~~~~~~~~~  AJUDA  ~~~~~~~~~~~~~~~~\n\n");
       printf("\n\n");
       printf("\n\n");
       printf("\t\t      ONDE VOCE DESEJA OBTER AJUDA?  \n\n\n");    
       printf("1 ~ CADASTRAMENTO DE DADOS\n2 ~ EDITAR\n3 ~ EXCLUIR\n4 ~ LISTAR\n5 ~ PESQUISA\n\n\n\t6 - SAIR DA AJUDA\n\n %c",26);
       scanf("%d",&b);
       }
       while((b<1) || (b>6));
    

       switch(b){
        case 1:
             system("cls");
             printf("\n\n");
             printf("\tCADASTRAMENTO DE DADOS \n\n");
             printf("   Nesta opcao voce vai informar os valores de \n   <Nome Completo> ,<Data de Nascimento>, <DDD> , <Telefone> , <Endereco> \n   <E-mail> , <Website>  e  <Observacoes> para serem armazenados em \n   alguma ficha/agenda vazia.\n   Os valores podem ser acessados, editados ou excluidos \n   atraves das opcoes do MENU PRINCIPAL.\n");
             printf("\n\n");
             printf("\n\n");
              break;
        case 2:
             system("cls");
             printf("\n\n");
             printf("\tEDITAR \n\n");
             printf("   Informando o <Nome Completo> voce vai substituir todos os dados\n   armazenados na sua Agenda por novos valores.\n");
             printf("\n\n");
             printf("\n\n");
             break;
        case 3:
             system("cls");
             printf("\n\n");
             printf("\tEXCLUIR \n\n");
             printf("   Informando o <Nome Completo> voce vai apagar todos \n   os valores da respectiva ficha. Se ela existir.\n");
             printf("\n\n");
             printf("\n\n");
              break;
        case 4:
             system("cls");
             printf("\n\n");
             printf("\tLISTAR \n\n");
             printf("   Nesta opcao o programa ira listar todas as fichas cadastradas no programa.\n");
             printf("\n\n");
             printf("\n\n");
               break;
        case 5:
             system("cls");
             printf("\n\n");
             printf("\tPESQUISA \n\n");
             printf("   Informando o <Nome Completo> este comando ira pesquisar \n   e imprimir todas as informacoes da ficha relacionadas ao nome inserido.\n");
             printf("\n\n");
             printf("\n\n");
             break;
        case 6:
              printf("SAIR");
              system("cls");
              break;
              }
              
    system("PAUSE");
    system("cls");
    
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void EDITAR(void) // FUN��O  EDITAR
{
     
     fflush(stdin); //Limpar Buffer do Teclado
     int i,a;
     char nome_busca[50];
     int nao_tem=999;
     
     system("cls");
     printf("\n\n");   
     printf("\t\t ~~~~~~~~~~~~~~~~  EDITAR  ~~~~~~~~~~~~~~~~\n\n");
     printf("\n\n");
     printf("\n\n");
     fflush(stdin); //Limpar Buffer do Teclado
     printf(" Informe o <Nome Completo> %c   ",26);
     
     gets(nome_busca);


     for(i=0; i<TAM; i++)
     {
      if(agenda[i].tel!=7777777)
                 {
                 if(strcmp(agenda[i].nome,nome_busca)==0) 
                           {
                                    
                           do{
                                    
                              system("cls");
  
                              printf("\t\t ~~~~~~~~~~~~~~~~  EDITAR  ~~~~~~~~~~~~~~~~\n\n");
                              printf("\n\n");
                              printf("\n\n");
                              printf("1 ~ Nome\n2 ~ Data de Nascimento\n3 ~ DDD\n4 ~ Telefone\n5 ~ E_mail\n6 ~ Website\n7 ~ Endereco\n8 ~ Observacoes\n9 ~ Sair.\n\n");
                              printf("\n\n");
                              scanf("%d",&a);
                              printf("\n\n");
                              printf("\n\n");
                 
                               switch(a){
                                case 1:

                                      fflush(stdin); //Limpar Buffer do Teclado
                                      printf(" Informe o novo <Nome completo> :  ");
                                      gets(agenda[i].nome);
                                      break;
                                case 2:
                                      printf(" Informe a nova <Data de Nascimento>:   \n");
                                    
                                      printf(" DIA: ");
                                      scanf("%d",&agenda[i].data.dia);
                                   
                                      printf(" MES: ");
                                      scanf("%d",&agenda[i].data.mes);
                                    
                                      printf(" ANO: ");
                                      scanf("%d",&agenda[i].data.ano);
                                      break;
                                case 3:
                                      printf(" Informe o novo <DDD> : ");
                                      scanf("%s",&agenda[i].ddd);
                                      break;
                                case 4:
                                      printf(" Informe o novo <Telefone>:  ");
                                           do{
                                              scanf("%d",&agenda[i].tel);
                                              }while(agenda[i].tel==7777777);
                                      break;
                                case 5:
                                      printf(" Informe o novo <E_mail> :  ");
                                      scanf("%s",agenda[i].e_mail);
                                      break;
                                case 6: 
                                      printf(" Informe o novo <Site> :  ");
                                      scanf("%s",agenda[i].site);
                                      break;
                                case 7:
                                      fflush(stdin); //Limpar Buffer do Teclado
                                      printf(" Informe o novo  <Endereco>:  ");
                                      gets(agenda[i].endereco);
                                      break;
                                case 8:
                                      printf("Obs:  ");  
                                      gets(agenda[i].obs);
                                      break;
                                case 9:
                                      break;
                                      }                                   
    
                              }while((a<1) || (a>9));
                                     nao_tem=0;
                                     
                           }
                 }
                     
     }
     
     if(nao_tem==999)
     {
     system("cls");
     printf("\n  n�o foi encontrado nenhum dado correspondente. \n\n");
     printf("  Certifique-se de que todas as palavras estejam escritas corretamente.\n\n\n\n\n\n");
     }
               
               
     system("PAUSE");                
     system("cls");
     printf("\t\tDeseja continuar?   \n\n");
     printf(" 1 - Sim   \n\n 2 - n�o\n\n");
     scanf("%d",&continuar);
     while(continuar!=1 && continuar!=2)
             {
             system("cls");
             printf("\t\tDeseja continuar?   \n\n");
             printf(" 1 - Sim   \n\n 2 - n�o\n\n");
             scanf("%d",&continuar);                   
             }
             
     if(continuar==1){
                     EDITAR();
                     } 
  
     system("cls");
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void EXCLUIR(void) // FUN��O  EXCLUIR
{
                   
     int i,a;
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


            for(i=0; i<TAM; i++)
            {
                     if(!strcmp(agenda[i].nome,nome_busca)) 
                      {
                       agenda[i].tel=7777777; 
                       nao_tem=0;
                       system("cls");
                       printf("\n\n   Exclus%co conclu%cda com sucesso! \n\n\n",3782,3745);
                      
                       printf("\n\n");
                       printf("\n\n");
                      
                       cont--;
                       }

            }
            
     if(nao_tem==999)
     {
     system("cls");
     printf("\n  n�o foi encontrado nenhum dado correspondente. \n\n");
     printf("  Certifique-se de que todas as palavras estejam escritas corretamente.\n\n\n\n\n\n");
     }
                             
     system("PAUSE");                
     system("cls");
     printf("\t\tDeseja continuar?   \n\n");
     printf(" 1 - Sim   \n\n 2 - n�o\n\n");
     scanf("%d",&continuar);
     while(continuar!=1 && continuar!=2)
             {
             system("cls");
             printf("\t\tDeseja continuar?   \n\n");
             printf(" 1 - Sim   \n\n 2 - n�o\n\n");
             scanf("%d",&continuar);                   
             }

     if(continuar==1){
                      EXCLUIR();
                      }                     
                             
                             
     system("CLS");                            
}
*/
