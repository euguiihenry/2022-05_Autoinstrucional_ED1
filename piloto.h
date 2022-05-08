#include <stdio.h>

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