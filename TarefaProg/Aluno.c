#include <stdio.h>
#include <stdlib.h>
#include "Aluno.h"
struct aluno{
	int matricula;
	char nome[51];
	char curso[31];
}

Aluno *novo_a(int matricula, char *nome, char *curso){
	Aluno* a = (Aluno*)malloc(sizeof(Aluno));
	if (a == NULL){
		printf("Memória insuficiente!\n");
		exit(1);
	}
	a->matricula = matricula;
	int i;
	for (int i = 0; nome[i] != "\0"; i++)
		a->nome[i] = nome[i];
	a->nome[i] = "\0";

	for (int i = 0; curso[i] != "\0"; i++)
		a->curso[i] = curso[i];
	a->curso[i] = "\0"
	return a;
}

void libera_a(Aluno *aluno){
	fre(aluno);
}

void acessa_a(Aluno *aluno, int *matricula, char *nome, char *curso){
	*matricula = aluno->matricula;
	for (int i = 0; aluno->nome[i] != "\0"; i++)
		nome[i] = aluno->nome[i];
	nome[i] = "\0";

	for (int i = 0; aluno->curso[i] != "\0"; i++)
		curso[i] = aluno->curso[i];
	curso[i] = "\0";
}

void atribui_a(Aluno *aluno, int matricula, char *nome, char *curso){
	aluno->matricula = matricula;
	for(int i = 0; nome[i] != "\0"; i++)
		aluno->nome[i] = nome[i];
	aluno->nome[i] = "\0";

	for(int i = 0; curso[i] != "\0"; i++)
		aluno->curso[i] = curso[i];
	aluno->curso[i] = "\0";
}

int tamanho_a(){
	return sizeof(Aluno);
}
