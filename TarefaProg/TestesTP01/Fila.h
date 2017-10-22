#include "Aluno.h"

/* TAD: Fila (tamanho)*/ 
typedef struct fila Fila;

/* Aloca e retorna uma fila de tamanho informado */ 
Fila *nova_f(int tamanho);

/* Libera a memória de uma fila previamente criada */ 
void destroi_f(Fila *fila);

/* Adiciona um aluno na fila. Retorna 1 se der certo e 0 caso contrário */ 
int adiciona_f(Fila *fila, Aluno *aluno);

/* Remove um aluno na fila. Retorna 1 se der certo e 0 caso contrário */ 
int retira_f(Fila *fila);

/* Busca aluno pelo número de matricula. Retorna o aluno se der certo e NULL caso contrário */
Aluno *busca_f(Fila *fila, int matricula);

/* Retorna 1 se a fila estiver cheia e 0 caso contrário */ 
int cheia_f(Fila *fila);