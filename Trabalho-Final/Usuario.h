#include "Viagem.h"
typedef struct usuario Usuario;
//obrigatórias
Usuario *novo_u(int id, char *nome);
void libera_u(Usuario *usuario);
void acessa_u(Usuario *usuario, int *id, char *nome);
void atribui_u(Usuario *usuario, int id, char *nome);
void adiciona_amigo_u(Usuario *usuario, Usuario *amigo);
void remove_amigo(Usuario *usuario, int id);
Usuario *busca_amigo_u(Usuario *usuario, int id);
Usuario *lista_amigos_u(Usuario *usuario);
void adiciona_viagem_u(Usuario *usuario, Viagem *viagem);
void remover_viagem_u(Usuario *usuario, int id);
Viagem *listar_viagens_u(Usuario *usuario);
Viagem *buscar_viagem_por_data_u(Usuario *usuario, int dia, int mes, int ano);
Viagem *buscar_viagem_por_destino_u(Usuario *usuario, char *cidade, char *pais);
Viagem *filtrar_viagens_amigos_por_data_u(Usuario *usuario, int dia, int mes, int ano);
Viagem *filtrar_viagens_amigos_por_destino_u(Usuario *usuario, char *cidade, char *pais);
Usuario *filtrar_amigos_por_data_viagem_u(Usuario *usuario, int dia, int mes, int ano);
Usuario *filtrar_amigos_por_destino_viagem_u(Usuario *usuario, char *cidade, char *pais);
int tamanho_u();
//outras
Viagem *buscar_viagem_por_id_u(Usuario *usuario, int id);
int comparar_data(Viagem *viagem1,Viagem *viagem2);
int verificar_nome(char *nome);
int verificar_id(int id);
int PercursoEmOrdem(Viagem *viagem1, Viagem *viagem2, int id2);
void removerGlobaluser(Usuario *usuario);