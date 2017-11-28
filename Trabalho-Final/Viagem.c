#include "Viagem.h"
#include <string.h>
struct Viagem{
	int id, dia, mes, ano, periodo;
	char cidade[61], pais[31];
	Viagem *direita, *esquerda, *pai, *raiz; 
}
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
    if(verificar_data(dia, mes, ano) && (periodo >= 1) && verificar_destino(cidade, pais)){
        Viagem *v = (*viagem)malloc(sizeof(Viagem));
        if (v == NUll){
            return NULL;
        }
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


void libera_v(Viagem *viagem){ //falar com o Lincoln sobre à necessidade de verificar a direita e a esquerda
    if(viagem != NULL){
        Viagem *nova_viagem;
        viagem = nova_viagem;
        free(viagem);
        viagem = NULL;   
    }   
}
void acessa_v(Viagem *viagem, int *dia, int *mes, int *ano, char *cidade, char *pais, int *periodo){
    if (viagem != NULL){
        dia = viagem->dia;
        mes = viagem->mes;
        ano = vaigem->ano;
        strcpy(cidade, viagem->cidade);
        strcpy(pais, viagem->pais);
        periodo = viagem->periodo;   
    }
}
void atribui_v(Viagem *viagem, int dia, int mes, int ano, char *cidade, char *pais, int periodo){
    if(verificar_data(dia, mes, ano) && periodo >= 1 && verificar_destino(cidade, pais)){
        viagem->dia = dia;
        viagem->mes = mes;
        viagem->ano = ano;
        strcpy(v->cidade, cidade);
        strcpy(v->pais, pais);
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
    if (viagem != NULL){
        return viagem->direita;
    }
}

void atribui_esquerda_v(Viagem *viagem, Viagem *esquerda){
    if (viagem != NULL && esquerda != NULL){
        viagem->esquerda = esquerda;
        esquerda->pai = esquerda;
    }
}

Viagem *acessa_esquerda_v(Viagem *viagem){
    if (viagem != NULL){
        return viagem->esquerda;
    }
}

int tamanho_v(){
    return sizeof(Viagem);
}



