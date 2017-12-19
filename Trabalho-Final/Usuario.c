//#include "Viagem.h"
#include "Usuario.h"
#include <string.h>
#include <stdlib.h>

struct viagem{
	int id, dia, mes, ano, periodo;
	char cidade[61], pais[31];
	Viagem *direita, *esquerda, *pai, *raiz; 
};

struct usuario{
	int id;
	char nome[81];
	Usuario **amigos; //Vetor de Usuarios
	int tamanho; //tamanho do vetor amigos
	Viagem *viagens; //Lista de agendamento de viagens
};

Usuario** GlobalUser = NULL; //vetor que contém todos os usuários
int tamanho_global = 0;

int comparar_data(Viagem *viagem1, Viagem *viagem2){
	int *dia1, *mes1, *ano1, *periodo1;
	acessa_v_data(viagem1, dia1, mes1, ano1, periodo1);
	int *dia2, *mes2, *ano2, *periodo2;
	acessa_v_data(viagem2, dia2, mes2, ano2, periodo2);
	int total1 = *dia1+*mes1*30+*ano1*365;//1 - viagem que já está na árvore
	int total2 = *dia2+*mes2*30+*ano2*365;//2 - viagem que eu quero verificar se a data "bate" com as outras

	if(total1<total2){
		if(total1+*periodo1 < total2){
			return 1;
		}else{
			return 0;
		}                                                                                                                                                                                    
	}else{
		if(total2+*periodo2 < total1){
			return 1;
		}else{
			return 0;
		}
	}

	return 0;
}

int PercursoEmOrdem(Viagem *viagem1, Viagem *viagem2, int id2){//1 - viagem que já está na árvore
	if(viagem1 != NULL){
		Viagem *esquerda = acessa_esquerda_v(viagem1);
		PercursoEmOrdem(esquerda, viagem2, id2);
		if (!comparar_data(viagem1, viagem2) || viagem1->id == id2){
			return 0;
		}
		Viagem *direita = acessa_direita_v(viagem1);
		PercursoEmOrdem(direita, viagem2, id2);	
	}
	
	return 1;
}


int verificar_nome(char *nome){
	if(strlen(nome) <=80){
		return 1;
	}
	return 0;
}
int verificar_id(int id){ //somente para criar ou atribuir usuario
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

void removerGlobaluser(Usuario *usuario){
	if(usuario != NULL && GlobalUser != NULL){
		int id_teste;
		char *nome_teste;
		int tam = sizeof(GlobalUser)/sizeof(GlobalUser[0]);
		for (int i = 0; i < tam; i++){
			acessa_u(GlobalUser[i], &id_teste, nome_teste);
			if(id_teste == usuario->id){
				Usuario *vazio;
				if(tam == 1){
					GlobalUser[0] = vazio;
				}else{
					for (int j = i; j <= tam-1; j++){
						GlobalUser[j] = GlobalUser[j+1];
						GlobalUser[j+1] = vazio;
					}	
				}
			}
		}
	}
}

Usuario *novo_u(int id, char *nome){
	if(verificar_nome(nome) && verificar_id(id)){
		Usuario *user = (Usuario*)malloc(tamanho_u());
		if (user == NULL){
			return NULL;
		}
		Usuario **amigos = (Usuario**)malloc(tamanho_u());
		if(amigos == NULL){
			return NULL;
		}
		user->id = id;
		strcpy(user->nome, nome);
		user->amigos = amigos;
		user->tamanho = 0;
		user->viagens = NULL;
		//adiciona o GlobalUser
		if (GlobalUser == NULL){
			tamanho_global++;
			GlobalUser = (Usuario**)malloc(sizeof(tamanho_global*tamanho_u()));
			GlobalUser[0] = user;
		}else{
			tamanho_global++;
			GlobalUser = (Usuario**)realloc(GlobalUser,sizeof(tamanho_global*tamanho_u()));
			GlobalUser[tamanho_global-1] = user;
		}
		return user;
	}
}

void libera_u(Usuario *usuario){
	removerGlobaluser(usuario);
	int i = 0;
	while(usuario->amigos[i] != NULL){
		remove_amigo(usuario->amigos[i], (usuario->amigos[i])->id);
		i++;
	}
	libera_v(usuario->viagens);
	Usuario *new_user;
	usuario = new_user;
	free(usuario);
	usuario = NULL;
}
void acessa_u(Usuario *usuario, int *id, char *nome){
	*id = usuario->id;
	strcpy(nome, usuario->nome);
}
void atribui_u(Usuario *usuario, int id, char *nome){
	if (usuario != NULL && verificar_id(id) && verificar_nome(nome)){
		usuario->id = id;
		strcpy(usuario->nome, nome);
	}
}
void adiciona_amigo_u(Usuario *usuario, Usuario *amigo){
	if(usuario!= NULL && amigo!= NULL){
		Usuario *u_teste = busca_amigo_u(usuario,amigo->id);
		if (u_teste == NULL){
			usuario->tamanho++;
			usuario->amigos = (Usuario**)realloc(usuario->amigos, usuario->tamanho*tamanho_u());
			usuario->amigos[usuario->tamanho] = amigo;
			adiciona_amigo_u(amigo,usuario);
		}
	}
}
void remove_amigo(Usuario *usuario, int id){
	if (usuario!=NULL && id > 0){
		Usuario *amigo_r = busca_amigo_u(usuario,id);
		if (amigo_r != NULL){
			int tam = sizeof(usuario->amigos)/sizeof(usuario->amigos[0]);

			for (int i = 0; i < tam; i++){
				if (usuario->amigos[i] == amigo_r){
					Usuario *vazio;
					if(tam == 1){
						usuario->amigos[0] = vazio;
					}else{	
						for (int j = i; j < tam-1; i++){
							usuario->amigos[j] = usuario->amigos[j+1];
							usuario->amigos[j+1] = vazio;
	 					}
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
		if(usuario->amigos[0] != NULL){
			int tam = sizeof(usuario->amigos)/sizeof(usuario->amigos[0]);
			for(int i = 0; i < tam; i++){
				acessa_u(usuario->amigos[i],&id_teste,nome_teste);
				if(id_teste == id){
					return usuario->amigos[i];
				}
			}			
		}

	}
	return NULL;
}

Usuario *lista_amigos_u(Usuario *usuario){
	if (usuario != NULL){
		Usuario *amigos_copia[usuario->tamanho];
		if(usuario->amigos[0] != NULL){
			int tam = sizeof(usuario->amigos)/sizeof(usuario->amigos[0]);
			for (int i = 0; i < tam; i++){
				amigos_copia[i] = usuario->amigos[i];
			}
		}
		return *amigos_copia;
	}
}
void adiciona_viagem_u(Usuario *usuario, Viagem *viagem){
	if(usuario != NULL && viagem != NULL){
		int *dia1, *mes1, *ano1, *id1, *periodo1, *dia2, *mes2, *ano2, *periodo2;
		char *cidade1, *pais1;
		acessa_v(viagem, id1, dia1, mes1, ano1, cidade1, pais1, periodo1);
		if (usuario->viagens = NULL){
			usuario->viagens = viagem;
			atribui_raiz(viagem, viagem);
		}else if(PercursoEmOrdem(usuario->viagens, viagem, viagem->id)){ //testa se a viagem pode ser inserida  
			//adiciona viagem aqui
			Viagem *p = NULL; //ponteiro para o pai
			Viagem *i = (usuario->viagens)->raiz; // iterador
	
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
				viagem->raiz = viagem;
				viagem->esquerda = NULL;
				viagem->direita = NULL;
				viagem->pai = NULL;
				usuario->viagens = viagem;

			}else if(total1 < total2){
				p->esquerda = viagem;
			}else{
				p->direita = viagem;
			}
		}
	}
}


void remover_viagem_u(Usuario *usuario, int id){
	if(usuario != NULL && id > 0){
		Viagem *viagem_r = buscar_viagem_por_id_u(usuario, id);
		if(viagem_r != NULL){
			//remover viagem aqui
			if(viagem_r->esquerda == NULL){
				transplantar(viagem_r, viagem_r->direita);
			}else if(viagem_r->direita == NULL){
				transplantar(viagem_r, viagem_r->esquerda);
			}else{
				Viagem *min = minR(viagem_r->direita);
				if(min->pai != viagem_r){
					transplantar(min, min->direita);
					min->direita = viagem_r->direita;
					(viagem_r->direita)->pai = min;
				}
				transplantar(viagem_r, min);
				min->esquerda = viagem_r->esquerda;
				(viagem_r->esquerda)->pai = min;
			}
		}
	}
}
Viagem *listar_viagens_u(Usuario *usuario){
	return usuario->viagens;
}
Viagem *buscar_viagem_por_id_u(Usuario *usuario, int id){
	Viagem *x = usuario->viagens;
	while(x != NULL && x->id != id){
		if(id < x->id){
			x = x->esquerda;
		}else{
			x = x->direita;
		}
	}
	return x;
}
Viagem *buscar_viagem_por_data_u(Usuario *usuario, int dia, int mes, int ano){
	if (usuario != NULL && dia >= 1 && mes >= 1 && ano >= 1 ){
		Viagem *i = usuario->viagens;
		int total1 = dia + mes*30 + ano*365;
		while(i != NULL){
			if(i->ano == ano && i->mes == mes && i->dia == dia){
				return i;
			}else{
				int *dia2, *mes2, *ano2, *periodo2;
				acessa_v_data(i, dia2, mes2, ano2, periodo2);
				int total2 = *dia2 + *mes2*30 +*ano2*365;
				if (total1 < total2){
					i = i->esquerda;
				}else{
					i = i->direita;
				}
			}
		}
	}
	return NULL;
}
Viagem *buscar_viagem_por_destino_u(Usuario *usuario, char *cidade, char *pais){
	if (usuario != NULL && verificar_destino(cidade, pais)){
		Viagem *i = minR(usuario->viagens);
		while(i != NULL){
			if(i->cidade == cidade && i->pais == pais){
				return i;
			}
			i = sucessor(i);
		}
	}
	return NULL;
}
Viagem *filtrar_viagens_amigos_por_data_u(Usuario *usuario, int dia, int mes, int ano){
	int quantidadeViagens = 0;
	int tam = sizeof(usuario->amigos)/sizeof(usuario->amigos[0]); //tamanho do vetor amigos
	if (usuario !=NULL && verificar_data(dia, mes, ano)){	
		for (int i = 0; i < tam; i++){
			if (buscar_viagem_por_data_u(usuario->amigos[i], dia, mes, ano) != NULL){
				quantidadeViagens++;
			}
		}
	}
	if(quantidadeViagens != 0){
		Viagem *lista[quantidadeViagens];
		for (int i = 0; i < tam; i++){
			lista[i] = buscar_viagem_por_data_u(usuario->amigos[i], dia, mes, ano);
		}
		return lista;
	}
	return NULL;
	

}
Viagem *filtrar_viagens_amigos_por_destino_u(Usuario *usuario, char *cidade, char *pais){
	int quantidadeViagens = 0;
	int tam = sizeof(usuario->amigos)/sizeof(usuario->amigos[0]); //tamanho do vetor  amigos
	if (usuario !=NULL && verificar_destino(cidade, pais)){	
		for (int i = 0; i < tam; i++){
			if (buscar_viagem_por_destino_u(usuario->amigos[i], cidade, pais) != NULL){
				quantidadeViagens++;
			}
		}
	}
	if(quantidadeViagens != 0){
		Viagem *lista[quantidadeViagens];
		for (int i = 0; i < tam; i++){
			lista[i] = buscar_viagem_por_destino_u(usuario->amigos[i], cidade, pais);
		}
		return lista;
	}
	return NULL;
}
Usuario *filtrar_amigos_por_data_viagem_u(Usuario *usuario, int dia, int mes, int ano){
	int quantidadeAmigos = 0;
	int tam = sizeof(usuario->amigos)/sizeof(usuario->amigos[0]);
	Usuario *vetorDeAmigos[quantidadeAmigos];
	if(usuario != NULL && verificar_data(dia, mes, ano)){
		int total1 = dia + mes*30 + ano*365;
		for (int i = 0; i < tam; i++){
			Viagem *j = (usuario->amigos[i])->viagens;
			while(j != NULL){
				int total2 = j->dia + j->mes*30 + j->ano*365;
				if(total1 == total2){
					quantidadeAmigos++;
					j == NULL;
				}else if(total1 < total2){
					j = j->esquerda;
				}else{
					j = j->direita;
				}
			}
		}
		
		for (int i = 0; i < tam; i++){
			Viagem *j = (usuario->amigos[i])->viagens;
			while(j != NULL){
				int total2 = j->dia + j->mes*30 + j->ano*365;
				if(total1 == total2){
					vetorDeAmigos[i] = usuario->amigos[i];
					j == NULL;
				}else if(total1 < total2){
					j = j->esquerda;
				}else{
					j = j->direita;
				}
			}
		}
		return vetorDeAmigos;
	}
}
Usuario *filtrar_amigos_por_destino_viagem_u(Usuario *usuario, char *cidade, char *pais){

}
int tamanho_u(){
	return sizeof(Usuario);
}