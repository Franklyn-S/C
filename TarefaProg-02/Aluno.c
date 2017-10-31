#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Aluno.h"

struct aluno{
	int matricula;
	char nome[50];
	char curso[30];
	Aluno *prox;
};

Aluno* novo_a(int matricula, char *nome, char *curso){
	if (nome == NULL || curso == NULL){
		return NULL;
	}
	if (matricula < 0){
		return NULL;
	}
	Aluno* a = (Aluno*)malloc(sizeof(struct aluno));
	if (a == NULL){
		return NULL;
	}
	a->matricula = matricula;
	strcpy(a->nome,nome);
	strcpy(a->curso, curso);
	a->prox = NULL;
	a->ant = NULL;
	return a;
}

void libera_a(Aluno *aluno){
	if (aluno != NULL){
		Aluno alunoNulo;
		*aluno = alunoNulo;
		free(aluno);
		aluno = NULL;
	}
}

void acessa_a(Aluno *aluno, int *matricula, char *nome, char *curso){
	if (nome == NULL || curso == NULL){
		return;
	}
	*matricula = aluno->matricula;
	strcpy(nome, aluno->nome);
	strcpy(curso, aluno->curso);
	
}

void atribui_a(Aluno *aluno, int matricula, char *nome, char *curso){
	if (nome == NULL || curso == NULL){
		return;
	}
	if (strlen(nome) < 51 && strlen(curso) < 31){
		aluno->matricula = matricula;
		strcpy(aluno->nome,nome);
		strcpy(aluno->curso, curso);
	}
	
}

int tamanho_a(){
	return sizeof(struct aluno);
}
//setProximo
void atribui_proximo_a(Aluno *aluno, Aluno *proximo){
	if (aluno == NULL || proximo == NULL) {
		return;
	}
	aluno->prox = proximo;
}
//getProximo
Aluno *acessa_proximo_a(Aluno *aluno){
	return aluno->prox;
}