#include "Usuario.h"

struct Usuario{
	int id;
	char nome[81];
	Usuario **amigos; //Vetor de amigos
	Viagem *viagens; //Lista de agendamento de viagens
}