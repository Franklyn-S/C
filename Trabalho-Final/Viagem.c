#include "Viagem.h"
#include <string.h>
#include <stdlib.h>

struct viagem{
	int id, dia, mes, ano, periodo;
	char cidade[61], pais[31];
	Viagem *direita, *esquerda, *pai, *raiz; 
};

int id_viagem = 0;

int verificar_data(int dia, int mes, int ano){
	if ((dia >= 1 && dia <= 31) && (mes >= 1 && mes <= 12) && (ano >= 1900 && ano <= 2100)){ //verifica se os numeros sao validos
            if ((dia == 29 && mes == 2) && ((ano % 4) == 0)){ //verifica se o ano e bissexto
                return 1;
            }
            if (dia <= 28 && mes == 2){ //verifica o mes de feveireiro
                return 1;
            }
            if ((dia <= 30) && (mes == 4 || mes == 6 || mes == 9 || mes == 11)){ //verifica os meses de 30 dias
                return 1;
            }
            if ((dia <=31) && (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes ==8 || mes == 10 || mes == 12)){ //verifica os meses de 31 dias
                return 1;
            }
            else{
                return 0;
            }
      }
       else{
            return 0;
           }
     }

int verificar_destino(char *cidade, char *pais){
    if (strlen(cidade) <= 60 && strlen(pais) <= 30){
        return 1;
    }
    return 0;
}

int verificar_periodo(int periodo){
    if (periodo >= 1){
        return 1;
    }
    return 0;
}


Viagem *minR(Viagem *x){ //retorna um ponteiro para o nó mínimo na subárvore enraizada em x
	if(x->esquerda == NULL){
		return x;
	}
	return minR(x->esquerda);
}

Viagem *sucessor(Viagem *x){
	if(x->direita != NULL){
		return minR(x->direita);
	}
	Viagem *p = x->pai;
	while(p != NULL && x = p->direita){
		x = p;
		p = x->pai;
	}
	return p;
}

void transplantar(Viagem *viagem, Viagem *filho){ //onde filho pode ser esquerdo ou direito
    if (viagem != NULL){
        if(viagem->pai = NULL){
            viagem->raiz = filho;
        }else if(viagem = (viagem->pai)->esquerda){
            (viagem->pai)->esquerda = filho;
        }else{
            (viagem->pai)->direita = filho;
        }
        if(viagem->filho != NULL){
            filho->pai = viagem->pai;
        }
    }
}

Viagem *nova_v(int dia, int mes, int ano, char *cidade, char *pais, int periodo){
    if(verificar_data(dia, mes, ano) && verificar_periodo(periodo) && verificar_destino(cidade, pais)){
        Viagem *v = (Viagem*)malloc(sizeof(Viagem));
        if (v == NULL){
            return NULL;
        }
        v->id = id_viagem++;
        v->dia = dia;
        v->mes = mes;
        v->ano = ano;
        strcpy(v->cidade, cidade);
        strcpy(v->pais, pais);
        v->periodo = periodo;
        v->esquerda = NULL;
        v->direita = NULL;
        v->pai = NULL;
        v->raiz = v;
        return v;      
    }else{
        return NULL;
    }
}


void libera_v(Viagem *viagem){
    if(viagem != NULL){
        Viagem *nova_viagem;
        viagem = nova_viagem;
        free(viagem);
        viagem = NULL;   
    }   
}
void acessa_v(Viagem *viagem, int *id, int *dia, int *mes, int *ano, char *cidade, char *pais, int *periodo){
    if (viagem != NULL){
        *id = viagem->id;
        *dia = viagem->dia;
        *mes = viagem->mes;
        *ano = viagem->ano;
        strcpy(cidade, viagem->cidade);
        strcpy(pais, viagem->pais);
        periodo = viagem->periodo;   
    }
}
//nova
acessa_v_data(Viagem *viagem, int *dia, int *mes, int *ano, int *periodo){
    *dia = viagem->dia;
    *mes = viagem->mes;
    *ano = viagem->ano;
    *periodo = viagem->periodo;
}
//
void atribui_v(Viagem *viagem, int *dia, int *mes, int *ano, char *cidade, char *pais, int periodo){
    if(verificar_data(*dia, *mes, *ano) && verificar_periodo(periodo) && verificar_destino(cidade, pais)){
        viagem->dia = *dia;
        viagem->mes = *mes;
        viagem->ano = *ano;
        strcpy(viagem->cidade, cidade);
        strcpy(viagem->pais, pais);
        viagem->periodo = periodo;       
    }    
}

void atribui_direita_v(Viagem *viagem, Viagem *direita){
    if (viagem != NULL && direita != NULL){
        viagem->direita = direita;
        direita->pai = viagem;
    }
}

Viagem *acessa_direita_v(Viagem *viagem){
    return viagem->direita;
}

void atribui_esquerda_v(Viagem *viagem, Viagem *esquerda){
    if (viagem != NULL && esquerda != NULL){
        viagem->esquerda = esquerda;
        esquerda->pai = esquerda;
    }
}

Viagem *acessa_esquerda_v(Viagem *viagem){
    return viagem->esquerda;
}

Viagem *acessa_pai_v(Viagem *viagem){
    return viagem->pai;
}

Viagem *acessa_raiz_v(Viagem *viagem){
    return viagem->raiz;
}

void atribui_raiz(Viagem *viagem, Viagem *raiz){
        if (viagem != NULL && raiz != NULL){
        viagem->raiz = raiz;
    }
}

int tamanho_v(){
    return sizeof(Viagem);
}
