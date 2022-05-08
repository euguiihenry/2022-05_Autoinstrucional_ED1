#include <stdio.h>

int main() {
	int cont;

	do{
		printf("\n\MENU\n");
        printf("1. Atribuir\n");
        printf("2. Editar\n");
        printf("3. Exluir\n");
        printf("4. Imprimir\n");
        printf("5. EhCraque\n");
        printf("6. Sair\n");

        scanf("%d", &cont);
        
        switch(cont){
			case 1:
				atribuir();
        		break;
        	
			case 2: 
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
				break;
			
			default:
			  	printf("\n Digite uma opcao valida: \n");    
			    
		}
	}while(cont);

	return 0;
}
