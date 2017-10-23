#include <stdio.h>
#include <stdlib.h>
#include "Aluno.h"
#include "Fila.h"

struct fila{
	Aluno **aluno;
	int tamanho;
	int head;
	int tail;
};

Fila *nova_f(int tamanho){
	if (tamanho < 1){
		return NULL;
	}
	Fila* f = (Fila*)malloc(sizeof(Fila));
	f->aluno* = (Aluno*)malloc(tamanho*sizeof(Aluno*));
	f->tamanho = tamanho;
	if (f == NULL){
		printf("Memória insuficiente!\n");
		exit(1);
	}
	f->head = f->tail = 0;
	return f;
}

int cheia_f(Fila *fila){
	if (fila->tail == fila->tamanho && fila->head == 0){
		return 1;
	} 
	if(fila->head = fila->tail+1){
		return 1;
	}
	return 0;
}

void destroi_f(Fila *fila){
	free(fila);
	fila = NULL;
}

int adiciona_f(Fila *fila, Aluno *aluno){
	if (cheia_f(fila)){
		printf("Piha cheia!Não foi possível a inserção.\n");
		return 0;
	}
	/*
	fila->aluno[fila->tail++] = aluno;
	if (fila->tail == fila->tamanho+1){
		fila->tail = 0;
	}*/
	int indice = (fila->head + fila->tail) % fila->tamanho;
	fila->aluno[indice] = aluno;
	fila->tail++;
	
	return 1;

}

int retira_f(Fila *fila){
	if (fila->tail = 0){
		printf("Fila vazia!\n");
		return 0;
	}
	if (fila == NULL){
		return 0;
	}
	/*
	fila->aluno[fila->head++];
	if (fila->head == fila->tamanho){
		p = 0;
	}*/
	Aluno* aluno = fila->aluno[fila->head];
	fila->head = (fila->head+1) % fila->tamanho;
	fila->tail--;
	
	return 1;
}

Aluno *busca_f(Fila *fila, int matricula){
	if(fila == NULL || matricula < 0){
		return NULL;
	}
	for (int i = fila->head; i < fila->tail; i++){
		if(fila->*(aluno[i])->matricula == matricula){
			return fila->aluno[i];
		}
	}
	return NULL;
}

