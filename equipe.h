typedef struct equipe;

struct equipe {
	char nome[51];
	char nacionalidade[21]; // Quantidade de membros
	int qtddMembros; 
	int qtddTitulosConstrutores; // Tï¿½tulos dos construtores
	int qtddTitulosCondutores; //Tï¿½tulos dos condutores
	int poliPositions; //Pole positions
	int qtddVoltasMaisRap; //Voltas mais rï¿½pidas
	float valorMercado; //Valor de mercado
	float taxaIncricaoTemp; // Taxa de inscriï¿½ï¿½o da temporada
	char coresEquipe[31]; // Cores da equipe
	char chefeEquipe[21]; // Chefe de equipe
	char diretorComercial[21]; // Diretor comercial
	char diretorTecnico[21]; // Diretor tï¿½cnico
	char aeroDinamicChefe[21]; //Aerodinamicista-chefe
	char projetistaChefe[21]; //Projetista-chefe
	char ChefePesqEhDev[21]; //Chefe de Pesquisa e Desenvolvimento (R&D)
	char ChefeMecanico[21]; //Chefe dos mecï¿½nicos
	char tecnicoPneus[21]; //Tï¿½cnico de pneus
	char tecnicoComponentes[21]; // Tï¿½cnico de componentes
	char tecnicoTransmissao[21]; // Tï¿½cnico de transmissï¿½o
	char tecnicoCombustivel[21]; // Tï¿½cnico de combustï¿½vel
	char mecanicosPitStop[21][21]; //Mecï¿½nicos do pitstop (atï¿½ 21 profissionais)
	
}

printf("Nome: ");
gets(nome);

printf("Nacionalidade: ");
gets(nacionalidade);

printf("Quantidade de membros: ");
scanf("%i", &qtddTitulosConstrutores);

printf("Quantidade de titulos contrutores: ");
scanf("%i", &Dados.qtddTitulosCondutores);

printf("Poli positions: ");
scanf("%i", &poliPositions);

printf("Quantidade de voltas mais rapidas: ");
scanf("%i", &qtddVoltasMaisRap);

printf("Valor do mercado: ");
scanf("%f", &valorMercado);

printf("Valor da taxa de inscrição: ");
scanf("%f", &taxaIncricaoTemp);

printf("Cores de equipe : ");
gets(coresEquipe);

printf("Chefe de equipe: ");
gets(chefeEquipe);

printf("Diretor Comercial: ");
gets(diretorComercial);

printf("Diretor Tecnico: ");
gets(diretorTecnico);

printf("Chefe dinamico: ");
gets(aeroDinamicChefe);

printf("Projetista Chefe: ");
gets(projetistaChefe);

printf("Chefe de Pesquisa e Desenvolvimento: ");
gets(ChefePesqEhDev);

printf("Chefe Mecanico: ");
gets(ChefeMecanico);

printf("Tecnico de Pneus: ");
gets(tecnicoPneus);

printf("Tecnicos de Componentes: ");
gets(tecnicoComponentes);

printf("Tecnico de Transmissao: ");
gets(tecnicoTransmissao);

printf("Tecnico de Combustiveis: ");
gets(tecnicoCombustivel);

for(int i = 0; i<21; i++){
printf("Mecanico Pit Stop: ");
gets(mecanicosPitStop[i]);
}
