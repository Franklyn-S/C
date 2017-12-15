#include "Usuario.h"
#include <string.h>
#include <stdlib.h>

struct Usuario{
	int id;
	char nome[81];
	Usuario **amigos; //Vetor de Usuarios
	int tamanho; //tamanho do vetor amigos
	Viagem *viagens; //Lista de agendamento de viagens
}
Usuario **GlobalUser = NULL; //vetor que contém todos os usuários
int tamanho_global = 0;

int PercursoEmOrdem(Viagem *viagem1, Viagem *viagem2){//1 - viagem que já está na árvore
	if(viagem1 != NULL){
		Viagem *esquerda = acessa_esquerda_v(viagem1);
		PercursoEmOrdem(esquerda, viagem2);
		if (!comparar_data(viagem1, viagem2)){
			return 0;
		}
		Viagem *direita = acessa_direita_v(viagem1);
		PercursoEmOrdem(direita, viagem2);	
	}
	
	return 1;
}

int comparar_data(Viagem *viagem1, Viagem *viagem2){
	int *dia1, *mes1, *ano1, periodo1;
	acessa_v_data(viagem1, dia1, mes1, ano1, periodo1);
	int *dia2, *mes2, *ano2, periodo2;
	acessa_v_data(viagem2, dia2, mes2, ano2, periodo2);
	int total1 = *dia1+*mes1*30+*ano1*365;//1 - viagem que já está na árvore
	int total2 = *dia2+*mes2*30+*ano2*365;//2 - viagem que eu quero verificar se a data "bate" com as outras

	if(total1<total2){
		if(total1+periodo1 < total2){
			return 1;
		}else{
			return 0;
		}                                                                                                                                                                                    
	}else{
		if(total2+periodo2 < total1){
			return 1;
		}else{
			return 0;
		}
	}

	return 0;
}
int verificar_nome(char *nome){
	if(strlen(nome) <=80){
		return 1;
	}
	return 0;
}
int verificar_id(int id){
	if (GlobalUser != NULL){
		for (int i = 0; i < tamanho_global; i++){
			Usuario *user_teste = GlobalUser[i];
			if (user_teste->id == id){
				return 0;
			}
		}
	}
	if(id>=0){
		return 1;
	}
	return 0;
}

/*
int tamanho_vetor_amigos(Usuario *vetor,Usuario primeiro]){
	return (sizeof(vetor)/sizeof(primeiro));
}
*/

Usuario *novo_u(int id, char *nome){
	if(verificar_nome(nome) && verificar_id(id)){
		Usuario *user = (Usuario*)malloc(tamanho_u());
		if (user == NULL){
			return NULL;
		}
		user->id = id;
		user->nome = nome;
		user->amigos = (*Usuario)malloc(tamanho_u());
		user->tamanho = 0;
		user->viagens = NULL;
		if (GlobalUser == NULL){
			tamanho_global++;
			GlobalUser = (Usuario**)malloc(sizeof(tamanho_global*tamanho_u()));
			GlobalUser[0] = user;
		}else{
			tamanho_global++;
			GlobalUser = (Usuario**)realloc(GlobalUser,sizeof(tamanho_global*tamanho_u()));
			GlobalUser[tamanho_global-1] = user;
		}
	}
}

void libera_u(Usuario *usuario){//terminar
	int i = 0;
	while(i < tamanho_global && usuario != GlobalUser){
		i++;
	}
	for (int j = i; j < tamanho_global-1; j++){
		GlobalUser[j] = GlobalUser[j+1];
	}

	libera_v(usuario->viagens);	
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
		Usuario *u_teste = busca_amigo_u(usuario,amigo->id);
		if (u_teste == NULL){
			usuario->tamanho++;
			usuario->amigos = (*Usuario)realloc(usuario->tamanho*tamanho_u())
			usuario->amigos[usuario->tamanho] = amigo;
			adiciona_amigo_u(amigo,usuario);
		}
	}
}
void remove_amigo(Usuario *usuario, int id){
	if (usuario!=NULL && id > 0){
		Usuario *amigo_r = busca_amigo_u(usuario,id);
		if (amigo_r != NULL){
			for (int i = 0; i < len(usuario->amigos); i++){
				if (usuario->amigos[i] == amigo_r){
					for (int j = i; j < len(usuario->amigos)-1; i++){
						usuario->amigos[j] = usuario->amigos[j+1];
	 				}
	 				usuario->tamanho--;
	 				remove_amigo(amigo_r,usuario->id);
				}
			}
		}
	}
}

Usuario *busca_amigo_u(Usuario *usuario, int id){
	if (usuario != NULL && id > 0){
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
		Usuario *amigos_copia[usuario->tamanho];
		for (int i = 0; i < len(usuario); i++){
			amigos_copia[i] = usuario->amigos[i];
		}
		return *amigos_copia;
	}
}
void adiciona_viagem_u(Usuario *usuario, Viagem *viagem){
	if(usuario != NULL && viagem != NULL){
		int *dia1, *mes1, *ano1, *id1, periodo1, *dia2, *mes2, *ano2, periodo2;
		char *cidade1, *pais1;
		acessa_v(viagem, id1, dia1, mes1, ano1, cidade1, pais1, periodo1);
		if (usuario->viagens = NULL){
			usuario->viagens = viagem;
			viagem->raiz = viagem;
			atribui_raiz(viagem, viagem);
		}else if(PercursoEmOrdem(usuario->viagens, viagem) && viagem->id != id1){ //testa se a viagem pode ser inserida  
			//adicionar Usuario aqui
			Viagem *p = NULL;
			Viagem *i = (usuario->viagens)->raiz;
	
			int total1 = *dia1 + *mes1*30 + *ano1*365;
			while(i != NULL){
				p = i;
				
				int total2 = *dia2 + *mes2*30 + *ano2*365;
				if(total1 < total2){
					i = i->esquerda;
				}else{
					i = i->direita;
				}
			}
			viagem->pai = p;
			acessa_v_data(p, dia2, mes2, ano2, periodo2);
			int total2 = *dia2 + *mes2*30 + *ano2*365;
			if(p = NULL){ //Árvore vazia
				usuario->viagens = viagem;
				(usuario->viagens)->raiz = viagem;
			}else if(total1 < total2){
				p->esquerda = viagem;
			}else{
				p->direita = viagem;
			}
		}
	}
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