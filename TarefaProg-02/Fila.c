#include <stdio.h>
#include <stdlib.h>
#include "Aluno.h"
#include "Fila.h"

struct fila{
	int tamanho;
	int quantidade;
	Aluno *primeiro;
};

Fila *nova_f(int tamanho){
	if (tamanho < 1){
		return NULL;
	}
	Fila* f = (Fila*)malloc(sizeof(Fila));
	if (f == NULL){
		return NULL;
	}
	f->tamanho = tamanho;
	f->quantidade = 0;
	f->primeiro = NULL;
	return f;
}

void destroi_f(Fila *fila){
	if (fila != NULL){
		Fila f;
		*fila = f;
		fila->primeiro = NULL;
		free(fila->primeiro);
		free(fila);	
		fila = NULL;
	}
	
}

int adiciona_f(Fila *fila, Aluno *aluno){
	if (fila != NULL && aluno != NULL && fila->quantidade < fila->tamanho){
		if(fila->primeiro != NULL){
			Aluno *aux = fila->primeiro;
			while(acessa_proximo_a(aux) != NULL){
				aux = acessa_proximo_a(aux);
			}
			atribui_proximo_a(aux, aluno);
		}else{
			fila->primeiro = aluno;
		}
		fila->quantidade++;
		return 1;
	}
	if (cheia_f(fila)){
		return 0;
	}
	return 0;

}

//lbera_a
int retira_f(Fila *fila){
	if (fila == NULL){
		return 0;
	}
	if (fila->primeiro == NULL){
		return 0;
	}
	Aluno *prox = acessa_proximo_a(fila->primeiro);
	libera_a(fila->primeiro);
	fila->primeiro = prox;
	fila->quantidade--;
	return 1;
}


Aluno *busca_f(Fila *fila, int matricula){
	if(fila == NULL || matricula < 0){
		return NULL;
	}
	int* matriculaAux;
	char nome[50];
	char curso[30];
	int i;
	Aluno *x = fila->primeiro;
	acessa_a(x, matriculaAux, nome, curso);
	while (x != NULL && *matriculaAux != matricula){
		x = acessa_proximo_a(x);
		acessa_a(x, matriculaAux, nome, curso);
	}
	return x;
}

int cheia_f(Fila *fila){
	if (fila == NULL){
		return 0;
	}
	int cont = fila->quantidade;
	if (cont >= fila->tamanho){
		return 1;
	} 
	return 0;
}