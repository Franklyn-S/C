/* TAD: Aluno (matricula, nome, curso) */ 
typedef struct aluno Aluno;

/* Aloca e retorna um aluno com os dados passados por parâmetro */ 
Aluno *novo_a(int matricula, char *nome, char *curso);

/* Libera a memória de um aluno previamente criado */ 
void libera_a(Aluno *aluno);

/* Copia os valores de um aluno para as referências informadas */ 
void acessa_a(Aluno *aluno, int *matricula, char *nome, char *curso);

/* Atribui novos valores aos campos de um aluno */
void atribui_a(Aluno *aluno, int matricula, char *nome, char *curso);

/* Retorna o tamanho em bytes do TAD aluno */ 
int tamanho_a();