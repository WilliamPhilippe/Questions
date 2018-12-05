	#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

struct letras
{
	char l1;
	char l2;
	int cont;
};

int espacos(char *string){
	int i = 0, esp = 0;

	while(string[i] != '\0') if(string[i++] == ' ') esp++;
	return esp;
}

int letras_a(char *string){
	int i = 0, a = 0;

	while(string[i] != '\0'){
		if(string[i] == 'a' || string[i] == 'A') a++;
		i++;
	}
	return a;
}

void contar_pares(char *string, int n, struct letras *pares, int *tem_par, int *pos){

	int i, j, st = 0, value, maior = 0;

	for(i = 0; i < n; i++) string[i] = tolower(string[i]);

	for(i = 1, st = 0; i < strlen(string); i++){

		if( (string[i] >= 65 && string[i] <= 90) || (string[i] >= 97 && string[i] <= 122) && (string[i - 1] >= 65 && string[i - 1] <= 90) || (string[i - 1] >= 97 && string[i - 1] <= 122) && string[i] != ' ' && string[i - 1] != ' ' ){

			value = 1;
			for(j = 0; j < i - 1 && value; j++){
				if(string[i - 1] == (pares + j)->l1 && string[i] == (pares + j)->l2 ){
					((pares + j)->cont) ++;
					value = 0;
				}
			}

			if(value){
				(pares + st)->l2 = string[i];
				(pares + st)->l1 = string[i - 1];
				(pares + st)->cont = 1;
				st++;
			}

		}
	}

	for(i = 0; i < st; i++){
		if( (pares + i)->cont > maior ){
			(* pos) = i;
			maior = (pares + i)->cont;
		}
	}

}

int verificar_pares(char *string, int n){
	int i;
	for(i = 0; i < n - 1; i++){
		if( (string[i] >= 65 && string[i] <= 90) || (string[i] >= 97 && string[i] <= 122) ){
			if( (string[i + 1] >= 65 && string[i + 1] <= 90) || (string[i + 1] >= 97 && string[i + 1] <= 122) ) return 1;
		}
	}

	return 0;
}

void main(){

	char string[100];
	int tem_par, n, pos, i;

	while(1){
		gets(string);

		if(strcmp(string, "NAO QUERO MAIS") == 0) return;

		n = strlen(string);
		struct letras pares[n];
		for(i = 0; i < n; i++) (pares + i)->cont = 0;

		printf("%d\n", espacos(string));
		printf("%d\n", letras_a(string));

		tem_par = 0; pos = 0;
		contar_pares(string, n, pares, &tem_par, &pos);

		if(verificar_pares(string, n)) printf("%d\n%c%c\n", (pares + pos)->cont, (pares + pos)->l1, (pares + pos)->l2);
		else printf("NENHUM PAR\n");
		//printf(" %c\n", (pares + pos)->l1);
	}

}
