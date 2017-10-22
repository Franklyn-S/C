#include <stdio.h>
#include <stdlib.h>
#include "Aluno.h"
#include "Fila.h"

struct fila{
	Aluno *aluno;
	int tamanho;
}

Fila *novo_f(int tamanho){
	Fila* f = (Fila*)malloc(tamanho*sizeof(Fila));
	f->tamanho = tamanho;
	if (a == NULL){
		printf("Memória insuficiente!\n");
		exit(1);
	}
	return f;
}

void destroi_f(Fila *fila){
	free(fila);
}

int adiciona_f(Fila *fila, Aluno *aluno){
	if (cheia_f == 1){
		printf("Piha cheia!Não foi possível a inserção.\n");
		return 0;
	}
	fila->aluno[] = aluno
}