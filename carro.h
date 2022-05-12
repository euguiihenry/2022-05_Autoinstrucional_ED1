typedef struct carro;

struct carro {
    char nome[51];
    float comprimento;
    float largura;
    float altura;
    float peso;
    char marcaMotor[31];
    char tipoMotor[31];
    float aceleracao;
    float capacidadeCombustivel;
    int caixaCambio;
    int aroRoda;
    float qtdEtanol;
}
	
    
printf("Nome do carro:");
fgets(nome, 51, stin);
    
printf("\nComprimento do carro:");
scanf("%f",comprimento);
    
printf("\nLargura do carro:");
scanf("%f",largura);
    
printf("\nAltura do carro:");
scanf("%f",alturao);
    
printf("\nPeso do carro:");
scanf("%f",peso);
    
printf("Marca do motor:");
fgets(marcaMotor, 31, stdin );
    
printf("Tipo de motor:");
fgets(tipoMotor, 31, stdin );
    
printf("\nAceleração (0 a 100 km/h):");
scanf("%f",aceleracao);
    
printf("\nCapacidade do tanque de combustivel:");
scanf("%f",capacidadeCombustivel);
    
printf("\nCaixa de cambio:");
scanf("%i",caixaCambio);
    
printf("\nAro da roda:");
scanf("%i",aroRoda);
    
printf("\nQuantidade de etanol no combustivel:");
scanf("%f",qtdEtanol);
    
