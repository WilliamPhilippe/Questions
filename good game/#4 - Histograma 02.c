#include <stdio.h>

void main(){

	int n, n0_1 = 0;
	int valores[10] = {0}, maior = 0;
	double num;
	int i, j;

	scanf("%d", &n);

	while(n--){
		scanf("%lf", &num);
		if(num <= 1.0) valores[0]++;
		else if(num <= 2.0) valores[1]++;
		else if(num <= 3.0) valores[2]++;
		else if(num <= 4.0) valores[3]++;
		else if(num <= 5.0) valores[4]++;
		else if(num <= 6.0) valores[5]++;
		else if(num <= 7.0) valores[6]++;
		else if(num <= 8.0) valores[7]++;
		else if(num <= 9.0) valores[8]++;
		else if(num <= 10.0) valores[9]++;
	}

	printf("^\n");

	for(j = 1; j <= 10; j++){
		printf("|");
		for(i = 0; i < valores[10 - j]; i++){
			printf("*");
			if(valores[10 - j] > maior) maior = valores[10 -j];
		}
		printf("\n");
	}
	if(maior){
		printf("+");
		for(i = 0; i < maior; i++) printf("-");
		printf(">\n");


	}


}
