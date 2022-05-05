#include <stdio.h>

int main(){
	int cont = 1
	do{
		printf("\n\MENU\n");
        printf("1. Atribuir\n");
        printf("2. Editar\n");
        printf("3. Exluir\n");
        printf("4. Imprimir\n");
        printf("5. EhCraque\n");
        printf("0. Sair\n");

        scanf("%d", &cont);
        
        switch(cont){
        	case 1:
        		Atribui();
        		break;
        	
			case 2: 
			    Edita();
			    break;
			    
			case 3: 
			    Exclui();
				break;
				
			case 4:
			    Imprime();
			    break;
			    
			case 5:
			    EhCreaque();
				break;      
			
			default:
			  	printf("\n Digite uma opcao valida: \n");    
			    
		}
	}while(cont);
}
