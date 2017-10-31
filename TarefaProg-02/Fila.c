#include <stdio.h>
#include <stdlib.h>
#include "Aluno.h"
#include "Fila.h"

struct fila{
	int tamanho;
	Aluno *cabeca;
	Aluno *rabo;
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
	f->cabeca = NULL;
	f->rabo = f->cabeca;
	return f;
}

void destroi_f(Fila *fila){
	if (fila != NULL){
		Fila f;
		*fila = f;
		fila->cabeca = NULL;
		fila->rabo = NULL;
		free(fila->cabeca);
		free(fila->rabo);
		free(fila);	
		fila = NULL;
	}
	
}

int adiciona_f(Fila *fila, Aluno *aluno){
	if (fila == NULL || aluno == NULL){
		return 0;
	}
	if (cheia_f(fila)){
		return 0;
	}
	if (fila->cabeca = NULL){
		fila->cabeca = aluno;
		fila->rabo = aluno;
	}else{
		atribui_proximo_a(fila->rabo, aluno);
		
	}
	fila->rabo = aluno;
	return 1;

}

int retira_f(Fila *fila){
	if (fila == NULL){
		return 0;
	}
	if (fila->cabeca == NULL){
		return 0;
	}
	Aluno *prox = acessa_proximo_a(fila->cabeca);
	fila->cabeca = prox;
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
	Aluno *x = fila->cabeca;
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
	int cont = quantidade(fila);
	if (cont >= fila->tamanho){
		return 1;
	} 
	return 0;
}
int quantidade(Fila *fila){
	if (fila == NULL){
		return 0;
	}
	int cont = 0;
	Aluno *x = fila->cabeca;
	while(x != NULL){
		cont++;
		x = acessa_proximo_a(x);
	}
	return cont;
}