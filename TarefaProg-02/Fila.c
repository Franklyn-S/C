#include <stdio.h>
#include <stdlib.h>
#include "Aluno.h"
#include "Fila.h"

struct fila{
	int tamanho;
	Aluno **alunos;
	Aluno *cabeça;
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
	f->alunos = malloc(tamanho*sizeof(Aluno*));
	f->tamanho = tamanho;
	f->cabeça = NULL;
	return f;
}

void destroi_f(Fila *fila){
	if (fila != NULL){
		int i;
		for (i = 0; i < tamanho(fila); i++){
			libera_a(fila->alunos[i]);
		}
		Fila f;
		*fila = f;
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
	if (fila->cabeça = NULL){
		fila->cabeça = aluno;
		fila->rabo = aluno;
	}else{
		atribui_proximo_a(fila->rabo, aluno)
		
	}
	fila->rabo = aluno;
	return 1;

}

int retira_f(Fila *fila){
	if (fila == NULL){
		return 0;
	}
	if (fila->cabeça == NULL){
		return 0;
	}
	Aluno prox = acessa_proximo_a(fila->cabeça);
	fila->cabeça = prox;
	return 1;
}

Aluno *busca_f(Fila *fila, int matricula){
	if(fila == NULL || matricula < 0){
		return NULL;
	}
	int matriculaAux;
	char nome[50];
	char curso[30];
	int i;
	Aluno x = fila->cabeça;
	while (x != NULL && x->matricula != matricula){
		x = acessa_proximo_a(x);
	}
	return x;
}

int cheia_f(Fila *fila){
	if (fila == NULL){
		return 0;
	}
	cont = tamanho(fila);
	if (cont >= fila->tamanho){
		return 1;
	} 
	return 0;
}
int tamanho(Fila *fila){
	int cont = 0;
	Aluno x = fila->cabeça;
	while(x != NULL){
		cont++;
		x = acessa_proximo_a(x);
	}
	return cont;
}