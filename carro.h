#include <stdio.h>

struct carro {
    float comprimento;
    float largura;
    float altura;
    float peso;
    struct motor {
        char marca[30];
        char tipo[30];
    }
    float aceleracao;
    float capacidadeCombustivel;
    int caixaCambio;
    int aroRoda;
    float qtdEtanol;
}