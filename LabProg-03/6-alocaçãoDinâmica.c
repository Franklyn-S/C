#include <stdio.h>
#include <stdlib.h>

int main(void){
	int n;
	printf("Diga o tamanho do vetor:\n");
	scanf("%d", &n);
	int *v = (int*)malloc(n*sizeof(int));
	if(v == NULL){
		printf("Memória insuficiente.\n");
		exit(1);
	}
	for (i=0;i<n;i++){
		printf("Digita o valor %d:\n", i+1);
		scanf("%d", v[i]);
	}
	int cont;
	printf("Digite 1 para inserir mais elementos e 0 para sair e printar os elementos:\n");
	scanf("%d", &cont)
	while

	return 0;
}