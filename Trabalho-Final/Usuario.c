#include "Usuario.h"

struct Usuario{
	int id;
	char nome[81];
	Usuario **amigos; //Vetor de amigos
	Viagem *viagens; //Lista de agendamento de viagens
}
int comparar_data(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2){
	return (dia1+mes1*30+ano1*365)<=(dia2+mes2*30+ano2*365);
}
Usuario *novo_u(int id, char *nome){

}
void libera_u(Usuario *usuario){

}
void acessa_u(Usuario *usuario, int *id, char *nome){

}
void atribui_u(Usuario *usuario, int id, char *nome){

}
void adiciona_amigo_u(Usuario *usuario, Usuario *amigo){

}
void remove_amigo(Usuario *usuario, int id){

}
Usuario *busca_amigo_u(Usuario *usuario, int id){

}
Usuario *lista_amigos_u(Usuario *usuario){

}
void adiciona_viagem_u(Usuario *usuario, Viagem *viagem){

}
void remover_viagem_u(Usuario *usuario, int id){

}
Viagem *listar_viagens_u(Usuario *usuario){

}
Viagem *buscar_viagem_por_data_u(Usuario *usuario, int dia, int mes, int ano){

}
Viagem *buscar_viagem_por_destino_u(Usuario *usuario, char *cidade, char *pais){

}
Viagem *filtrar_viagens_amigos_por_data_u(Usuario *usuario, int dia, int mes, int ano){

}
Viagem *filtrar_viagens_amigos_por_destino_u(Usuario *usuario, char *cidade, char *pais){

}
Usuario *filtrar_amigos_por_data_viagem_u(Usuario *usuario, int dia, int mes, int ano){

}
Usuario *filtrar_amigos_por_destino_viagem_u(Usuario *usuario, char *cidade, char *pais){

}
int tamanho_u(){
	return sizeof(Usuario);
}