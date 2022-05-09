#include <stdio.h>
#include <string.h>

struct carro {
    char nome[50];
    float comprimento;
    float largura;
    float altura;
    float peso;
    float aceleracao;
    float capacidadeCombustivel;
    int caixaCambio;
    int aroRoda;
    float qtdEtanol;

    struct carroMotor {
        char marca[30];
        char tipo[30];
    }
}