#include <stdio.h>
#include <stdlib.h>
#include "Aluno.h"
#include "Fila.h"

struct fila{
	Aluno *aluno;
	int tamanho;
	int head;
	int tail;
}

Fila *novo_f(int tamanho){
	Fila* f = (Fila*)malloc(tamanho*sizeof(Fila));
	f->tamanho = tamanho;
	if (a == NULL){
		printf("Memória insuficiente!\n");
		exit(1);
	}
	f->head = f->tail = 1;
	return f;
}
int vazia_f(Fila *fila){
	if (fila->head = fila->tail){
		return 1;
	}
	return 0;
}

int cheia_f(Fila *fila){
	if (fila->tail = fila->tamanho && fila->head = 1){
		return 1;
	} 
	if(fila->head = fila->tail+1){
		return 1;
	}
	return 0;
}

void destroi_f(Fila *fila){
	free(fila);
}

int adiciona_f(Fila *fila, Aluno *aluno){
	if (cheia_f(fila) == 1){
		printf("Piha cheia!Não foi possível a inserção.\n");
		return 0;
	}
	fila->aluno = aluno
}

int retira_f(Fila *fila){
	if (fila->tamanho = 0){
		printf("Fila vazia!\n");
		return NULL;
	}
	Aluno aluno = fila->aluno[0];
	fila->tamanho -= 1;
	return aluno; 


}

Aluno *busca_f(Fila *fila, int matricula){

}

