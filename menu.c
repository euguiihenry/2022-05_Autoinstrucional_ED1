#include <stdio.h>

typedef struct equipe teste;


int main() {
	int cont;

	do{
		printf("\nMENU\n");
        printf("1. Atribuir\n");
        printf("2. Editar\n");
        printf("3. Exluir\n");
        printf("4. Imprimir\n");
        printf("5. EhCraque\n");
        printf("6. Sair\n");

        scanf("%d", &cont);
         
        teste tes[2];
               
        switch(cont){
			case 1:
				//scanf(equipe.nacionalidade, 21, stdin);
        		break;
        	
			/*case 2: 
			    editar();
			    break;
			    
			case 3: 
			    excluir();
				break;
				
			case 4:
			    imprimir();
			    break;
			    
			case 5:
			    ehCreaque();
				break;

			case 6:
				sair();
				break;*/
			
			default:
			  	printf("\n Digite uma opcao valida: \n");    
			    break;
		}
	}while(cont);

	return 0;
}
