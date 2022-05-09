#include <stdio.h>
#include <string.h>

struct piloto {
    char nome[50];
    char nacionalidade[30];
    char corPele[30];
    char corOlhos[30];
    char corCabelo[30];
    long int altura;
    int peso;
    int idade;
    int qtdCampeonatosGanhos;
    int polePosition;				// Posição de iniciação na corrida.
    int qtdVoltasRap;				// Quantidade de voltas mais rápidas.
}

// Getting and Setting for Nome:
    void setNome() {
        printf("Insira o nome completo:");
        fgets(piloto.nome, 50, stdin);
    }

    char getNome() {
        char *pointer;

        pointer = &piloto.nome[0];

        return pointer;
    }

// Getting and Setting for Nacionalidade:
    void setPilotoNacionalidade() {
        printf("Insira a nacionalidade do piloto: ");
        fgets(piloto.nacionalidade, 30, stdin);
    }

    char getPilotoNacionalidade() {
        char *pointer;

        pointer = &piloto.nacionalidade[0];

        return pointer;
    }
