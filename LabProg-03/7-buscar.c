#include <stdio.h>
#include <stdlib.h>
void captura(int n, int* v);
int buscar(int n, int *v);

int main(void){
	int n;
	int n_buscar;
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
	printf("Digite um número para buscar na sequência:\n");
	scanf("%d", n_buscar);
	int pos = buscar(n_buscar,v);
	if (pos == -1){
		printf("O número não se encontra na sequência!\n");
	}else{
		printf("Sua posição na sequência é %d\n", pos);
	}
	return 0;
}

void captura(int n, int* v){
	int i;
	for (i=0;i<n;i++){
		printf("Digite o valor %d:\n", i+1);
		scanf("%d", v[i]);
	}
}

int buscar(int n, int* v){
	int tam = (sizeof(v)/sizeof(int));
	for(int i=0; i<tam; i++){
		if(v[i] == n){
			return i;
		}
	}
	return -1;
}




