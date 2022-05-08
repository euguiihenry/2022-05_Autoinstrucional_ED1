#include <stdio.h>
#include <string.h>

struct piloto {
    char nacionalidade[30];
    char corPele[30];
    char corOlhos[30];
    char corCabelo[30];
    long int altura;
    int idade;
    int qtdCampeonatosGanhos;
    int polePosition;				// Posição de iniciação na corrida.
    int qtdVoltasRap;				// Quantidade de voltas mais rápidas.
}

void setPilotoNacionalidade {
    printf("Insira a nacionalidade do piloto: ");
    fgets(piloto.nacionalidade, 30, stdin);
}

char getPilotoNacionalidade {
    //return printf(piloto.nacionalidade[30]); How to do this???
}