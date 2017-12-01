#include "Usuario.h"
#include <string.h>
#include <stdlib.h>

struct Usuario{
	int id;
	char nome[81];
	Usuario **amigos; //Vetor de Usuarios
	int tamanho;
	Viagem *viagens; //Lista de agendamento de viagens
}


/*int comparar_data(int dia1, int mes1, int ano1, int periodo1, int dia2, int mes2, int ano2, int periodo2){
	
	return ;
}*/
int verificar_nome(char *nome){
	if(strlen(nome) <=80){
		return 1;
	}
	return 0;
}
int verificar_id(int id){
	if(id>=0){
		return 1;
	}
	return 0;
}

int tamanho_vetor_amigos(Usuario *vetor,Usuario primeiro]){
	return (sizeof(vetor)/sizeof(primeiro));
}

Usuario *novo_u(int id, char *nome){
	if(verificar_nome(nome) && verificar_id(id)){ //falta os outros testes
		Usuario *user = (Usuario*)malloc(tamanho_u());
		if (user == NULL){
			return NULL;
		}
		user->id = id;
		user->nome = nome;
		user->amigos = (*Usuario)malloc(tamanho_u());
		user->tamanho = 0;
		user->viagens = NULL;
	}
}

void libera_u(Usuario *usuario){//terminar
	libera_v(usuario->viagem)
	Usuario *new_user;
	usuario = new_user;
	free(usuario);
	usuario = NULL;
}
void acessa_u(Usuario *usuario, int *id, char *nome){
	*id = usuario->id;
	*nome = usuario->nome;
}
void atribui_u(Usuario *usuario, int id, char *nome){
	if (usuario != NULL && verificar_id(id) && verificar_nome(nome)){
		usuario->id = id;
		usuario->nome = nome;	
	}
}
void adiciona_amigo_u(Usuario *usuario, Usuario *amigo){
	if(usuario!= NULL && amigo!= NULL){
		Usuario u_teste = busca_amigo_u(usuario,amigo->id);
		if (u_teste == NULL){
			usuario->tamanho++;
			usuario->amigos = (*Usuario)realloc(usuario->tamanho*tamanho_u())
			usuario->amigos[usuario->tamanho] = amigo;
			adiciona_amigo_u(amigo,usuario);
		}
	}
}
void remove_amigo(Usuario *usuario, int id){
	if (usuario!=NULL && verificar_id(id)){
		Usuario *amigo_r = busca_amigo_u(usuario,id);
		if (amigo_r != NULL){
		for (int i = 0; i < len(usuario->amigos); i++){
			if (usuario->amigos[i] == amigo_r){
				for (int j = i; j < len(usuario->amigos)-1; i++){
					usuario->amigos[j] = usuario->amigos[j+1];
 				}
 				remove_amigo(amigo_r,usuario->id);
			}
		}	
		}
	}
}
Usuario *busca_amigo_u(Usuario *usuario, int id){
	if (usuario != NULL && verificar_id(id)){
		int id_teste;
		char *nome_teste;
		
		for(int i = 0;i < len(usuario); i++){
			acessa_u(usuario->amigos[i],&id_teste,nome_teste);
			if(id_teste == id){
				return usuario->amigos[i];
			}
		}
	}
	return NULL;
}
Usuario *lista_amigos_u(Usuario *usuario){
	if (usuario != NULL){
		return usuario->amigos;
	}
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