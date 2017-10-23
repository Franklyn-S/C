#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Aluno.h"


struct aluno{
	int matricula;
	char nome[51];
	char curso[31];
};

Aluno* novo_a(int matricula, char *nome, char *curso){
	if (nome == NULL || curso == NULL){
		return NULL;
	}
	if (matricula < 0){
		return NULL;
	}
	Aluno* a = (Aluno*)malloc(sizeof(Aluno));
	if (a == NULL){
		printf("Memória insuficiente!\n");
		exit(1);
	}
	a->matricula = matricula;
	strcpy(a->nome,nome);
	strcpy(a->curso, curso);
	return a;
}

void libera_a(Aluno *aluno){
	if (aluno == NULL){
		return NULL;
	}
	free(aluno);
	aluno = NULL;
}

void acessa_a(Aluno *aluno, int *matricula, char *nome, char *curso){
	*matricula = aluno->matricula;
	strcpy(nome, aluno->nome);
	strcpy(curso, aluno->curso);
}

void atribui_a(Aluno *aluno, int matricula, char *nome, char *curso){
	if (nome == NULL || curso == NULL){
		//printf("Dados inválidos!\n");
		return;
	}
	if (strlen(nome) > 51 && strlen(curso) > 31){
		aluno->matricula = matricula;
		strcpy(aluno->nome,nome);
		strcpy(aluno->curso, curso);
	}
	
}

int tamanho_a(){
	return (int) sizeof(Aluno);
}
