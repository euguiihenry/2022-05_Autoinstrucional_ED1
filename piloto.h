typedef struct piloto;

struct piloto {
    char nome[50];
    char nacionalidade[30];
    char corPele[30];
    char corOlhos[30];
    char corCabelo[30];
    long altura;
    int peso;
    int idade;
    int qtdCampeonatosGanhos;
    int polePosition;				// Posição de iniciação na corrida.
    int qtdVoltasRap;      			// Quantidade de voltas mais rápidas
    
}
    
printf("----------------------------------PILOTO-----------------------------------------");
	    
printf("\nInsira seu nome: ");
fgets(nome, 50, stdin);
    
printf("\nInsira sua nacionalidade: ");
fgets(nacionalidade, 30, stdin);
    
printf("\nInsira a cor da pele: ");
fgets(corPele, 30, stdin);
    
printf("\nInsira a cor dos olhos: ");
fgets(corOlhos, 30, stdin);
    
printf("\nInsira a cor do cabelo: ");
fgets(corCabelo, 30, stdin);
    
printf("\nInsira sua altura: ");
scanf("%d", &altura);
    
printf("\nInsira seu peso: ");
scanf("%d", &peso);
    
printf("\nInsira sua idade: ");
scanf("%d", &idade);
    
printf("\nInsira a quantidade de capeonatos ganhos: ");
scanf("%d", &qtdCampeonartosGanhos);
    
printf("\nInsira o pole position: ");
scanf("%d", &polePosition);
    
printf("\nInsira a quantidade de voltas mais rapidas: ");
scanf("%d", &qtdVoltasRap);

/*

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
    
    */
