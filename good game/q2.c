#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

int n_b, n_s, n_c;
int p_b, p_s, p_c;
int qtdB = 0, qtdS = 0, qtdC = 0;
long long int r, precoReceita = 0;
long long int quantidade = 0;
char receita[105];

void main(){

	gets(receita);
	scanf("%d %d %d\n%d %d %d\n%lld\n", &n_b, &n_s, &n_c, &p_b, &p_s, &p_c, &r);

	int i;
	for(i = 0; i < strlen(receita); i++){
		if(receita[i] == 'B'){
			precoReceita += p_b;
			qtdB++;
		}
		else if(receita[i] == 'S'){
			precoReceita += p_s;
			qtdS++;
		}
		else if(receita[i] == 'C'){
			precoReceita += p_c;
			qtdC++;
		}
	}

	if(qtdC == 0) n_c = 0;
	if(qtdB == 0) n_b = 0;
	if(qtdS == 0) n_s = 0;

	while( (n_b > 0 && n_s > 0) && n_c > 0 ){

		if( (n_b - qtdB < 0 || n_s - qtdS < 0) || n_c - qtdC < 0 ) break;
		else{
			n_b -= qtdB;
			n_s -= qtdS;
			n_c -= qtdC;
			quantidade ++;
		}

	}

	while( (n_c > 0 || n_s > 0) || n_b > 0 ){

		if(n_c < qtdC){
			r = r - (qtdC - n_c)*p_c;
			n_c = 0;
		}
		if(n_b < qtdB){
			r = r - (qtdB - n_b)*p_b;
			n_b = 0;
		}
		if(n_s < qtdS){
			r = r - (qtdS - n_s)*p_s;
			n_s = 0;
		}

		if(n_s >= qtdS) n_s -= qtdS;
		if(n_c >= qtdC) n_c -= qtdC;
		if(n_b >= qtdB) n_b -= qtdB;

		if(r >= 0) quantidade++;
		if(r <= 0) break;

	}

	if( (!n_c && !n_s) && !n_b ){
		quantidade += (long long int) r/precoReceita;
	}

	printf("%lld\n", quantidade);
	

}