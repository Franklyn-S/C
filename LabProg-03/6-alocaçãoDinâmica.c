#include <stdio.h>
#include <stdlib.h>

void captura(int n, int* v);

int main(void){
	int tam_v;
	int n;
	printf("Diga o tamanho do vetor:\n");
	scanf("%d", &n);
	//alocando função dinâmicamente
	int *v = (int*)malloc(n*sizeof(int));
	//verificação de espaço na memória
	if(v == NULL){
		printf("Memória insuficiente.\n");
		exit(1);
	}
	captura(n, v);
	tam_v = n;
	int cont;
	printf("Digite 1 para inserir mais elementos e 0 para sair e printar os elementos:\n");
	scanf("%d", &cont);
	while (cont != 0){
		int m = 0;
		printf("Digite a quantidade de elementos que deseja adicionar:\n");
		scanf("%d", m);
		//realocando função dinâmicamente
		int *v = (int*)realloc(v, m*sizeof(int));
		if (v == NULL){
			printf("Memória insuficiente.\n");
			exit(1);
		}
		tam_v += m;
		printf("Digite 1 para inserir mais elementos e 0 para sair e printar os elementos:\n");
		scanf("%d", &cont);
	}
	
	//imprimindo vetor
	printf("VETOR:\n");
	for(int i=0; i<tam_v; i++){
		printf("%d\n", v[i]);
	}
	free(v);
	return 0;
}

void captura(int n, int* v){
	int i;
	for (i=0;i<n;i++){
		printf("Digite o valor %d:\n", i+1);
		scanf("%d", v[i]);
	}
}