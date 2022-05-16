#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Methods.h"

int main(void) // FUNÇÃO  MENU
{
  int count;
  
  do{
    
     printf("\n\n");    

     printf("\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",3017,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3003);
     printf("\t\t\t%c    Formula 1       %c\n",3002,3002);
     printf("\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",3016,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3004);
     
     printf("\t\t  1  %c   CADASTRAR\n\n\t\t  2  %c   EDITAR\n\n\t\t  3  %c   EXCLUIR\n\n\t\t  4  %c   LISTAR\n\n\t\t  5  %c   PODIO\n\n\t\t  6  %c   SAIR\n\n",16,16,16,16,16,16,16,136,16);
     printf("\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~   \n\t\t  %c     ",26);
          
    
     scanf("\n%d",&count);
     
     switch(count){
			case 1:
			CADASTRAMENTO_EQUIPE();
        	break;
        	
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
				//sair();
				break;
		}
			
   
     }while((count<1) || (count>8));
    
 return 0;

}
