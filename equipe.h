
#include <stdio.h>
#include <string.h>

struct equipe {
	char nomeCompleto[31];
	char nacionalidade[21]; // Quantidade de membros
	int qtddMembros; 
	int qtddTitulosConstrutores; // Títulos dos construtores
	int qtddTitulosCondutores; //Títulos dos condutores
	int poliPositions; //Pole positions
	int qtddVoltasMaisRap; //Voltas mais rápidas
	float valorMercado; //Valor de mercado
	float taxaIncricaoTemp; // Taxa de inscrição da temporada
	char coresEquipe[31]; // Cores da equipe
	char chefeEquipe[21]; // Chefe de equipe
	char diretorComercial[21]; // Diretor comercial
	char diretorTecnico[21]; // Diretor técnico
	char aeroDinamicChefe[21]; //Aerodinamicista-chefe
	char projetistaChefe[21]; //Projetista-chefe
	char ChefePesqEhDev[21]; //Chefe de Pesquisa e Desenvolvimento (R&D)
	char ChefeMecanico[21]; //Chefe dos mecânicos
	char tecnicoPneus[21]; //Técnico de pneus
	char tecnicoComponentes[21]; // Técnico de componentes
	char tecnicoTransmissao[21]; // Técnico de transmissão
	char tecnicoCombustivel[21]; // Técnico de combustível
	char mecanicosPitStop[21][21]; //Mecânicos do pitstop (até 21 profissionais)
	
};


void setEquipeNacionalidade {
    printf("Insira a nacionalidade da equipe: ");
    fgets(equipe.nacionalidade, 30, stdin);
}

char getEquipeNacionalidade {
    char pNacionalidade;

    pNacionalidade = equipe.nacionalidade;

    return pNacionalidade;
}
