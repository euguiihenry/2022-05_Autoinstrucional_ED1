#include <stdio.h>
#include <string.h>

struct equipe {
	char nome{}
	char nacionalidade[21]; // Quantidade de membros
	int qtddMembros; 
	int qtddTitulosConstrutores; // T�tulos dos construtores
	int qtddTitulosCondutores; //T�tulos dos condutores
	int poliPositions; //Pole positions
	int qtddVoltasMaisRap; //Voltas mais r�pidas
	float valorMercado; //Valor de mercado
	float taxaIncricaoTemp; // Taxa de inscri��o da temporada
	char coresEquipe[31]; // Cores da equipe
	char chefeEquipe[21]; // Chefe de equipe
	char diretorComercial[21]; // Diretor comercial
	char diretorTecnico[21]; // Diretor t�cnico
	char aeroDinamicChefe[21]; //Aerodinamicista-chefe
	char projetistaChefe[21]; //Projetista-chefe
	char ChefePesqEhDev[21]; //Chefe de Pesquisa e Desenvolvimento (R&D)
	char ChefeMecanico[21]; //Chefe dos mec�nicos
	char tecnicoPneus[21]; //T�cnico de pneus
	char tecnicoComponentes[21]; // T�cnico de componentes
	char tecnicoTransmissao[21]; // T�cnico de transmiss�o
	char tecnicoCombustivel[21]; // T�cnico de combust�vel
	char mecanicosPitStop[21][21]; //Mec�nicos do pitstop (at� 21 profissionais)
	
};
