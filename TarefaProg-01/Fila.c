#include <stdio.h>
#include <stdlib.h>
#include "Aluno.h"
#include "Fila.h"

struct fila{
	int tamanho;
	int tail;
	Aluno **alunos;
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
	f->tail = 0;
	return f;
}

void destroi_f(Fila *fila){
	if (fila != NULL){
		int i;
		for (i = 0; i < fila->tail; i++){
			libera_a(fila->alunos[i]);
		}
		free(fila);	
	}
	
}

int adiciona_f(Fila *fila, Aluno *aluno){
	if (fila == NULL || aluno == NULL){
		return 0;
	}
	if (cheia_f(fila)){
		return 0;
	}
	
	fila->alunos[fila->tail++] = aluno;
	/*int indice = (fila->head + fila->tail) % fila->tamanho;
	fila->aluno[fila->tail] = aluno;
	fila->tail++;
	*/
	return 1;

}

int retira_f(Fila *fila){
	if (fila == NULL){
		return 0;
	}
	if (fila->tail = 0){
		return 0;
	}
	int i;
	for (i = 0; i < fila->tail; i++){
		fila->alunos[i] = fila->alunos[i+1];
	}
	fila->tail--;
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
	for ( i = 0; i < fila->tail; i++){
		acessa_a(fila->alunos[i], &matriculaAux, nome, curso);
		if(matriculaAux == matricula){
			return fila->alunos[i];
		}
	}
	return NULL;
}

int cheia_f(Fila *fila){
	if (fila == NULL){
		return 0;
	}
	if (fila->tail >= fila->tamanho){
		return 1;
	} 
	return 0;
}