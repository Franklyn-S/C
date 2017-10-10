#include <stdio.h>
#define n 8
int main(void){

	int seq1[n]={8,2,4,3,4,2,5,1};
	int seq2[n]={3,3,7,5,2,3,3,7};
	int seq3[n+1]={0,0,0,0,0,0,0,0,0};

	int i;
	for (i = n-1; i >= 0; i--){
		int soma = seq1[i] + seq2[i];
		int flag = 0;
		if (soma > 10){
			seq3[i+1] = seq3[i+1] + soma-10;
			flag = 1;
			seq3[i] = flag;
		}else{
			seq3[i+1] = seq3[i+1] + soma;
			flag = 0;
		}
	}
	for (i = 0; i < n+1; i++){
		printf("%d", seq3[i]);
	}
	printf("\n");
	return 0;
}