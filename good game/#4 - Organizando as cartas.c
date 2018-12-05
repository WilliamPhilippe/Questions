#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct dados
{
	int dia, mes, ano;
	char nome_mes[50];
	char remetente[100], rem[100];
	char destinatario[100], dest[100];
};

void tl(char a[], char b[]){
	int i = 0;

	while(a[i] != '\0'){
		b[i] = tolower(a[i]);
		i++;
	}

	b[i] = '\0';
}

void transformar(struct dados *cartas, int n){
	int i;

	for(i = 0; i < n; i++){

		if( ( (cartas + i)->nome_mes[0] == 'j' ||  (cartas + i)->nome_mes[0] == 'J') && ( (cartas + i)->nome_mes[1] == 'A' || (cartas + i)->nome_mes[1] == 'a') ) (cartas + i)->mes = 1;
		else if( (cartas + i)->nome_mes[0] == 'F' || (cartas + i)->nome_mes[0] == 'f') (cartas + i)->mes = 2;
		else if( ( (cartas + i)->nome_mes[0] == 'M' || (cartas + i)->nome_mes[0] == 'm') && ((cartas + i)->nome_mes[2] == 'R' || (cartas + i)->nome_mes[2] == 'r') ) (cartas + i)->mes = 3;
		else if( ( (cartas + i)->nome_mes[0] == 'A' || (cartas + i)->nome_mes[0] == 'a') && ((cartas + i)->nome_mes[2] == 'R' || (cartas + i)->nome_mes[2] == 'r') ) (cartas + i)->mes = 4;
		else if( ( (cartas + i)->nome_mes[0] == 'M' || (cartas + i)->nome_mes[0] == 'm') && ((cartas + i)->nome_mes[2] == 'i' || (cartas + i)->nome_mes[2] == 'I') ) (cartas + i)->mes = 5;
		else if( ( (cartas + i)->nome_mes[0] == 'J' || (cartas + i)->nome_mes[0] == 'j') && ((cartas + i)->nome_mes[2] == 'n' || (cartas + i)->nome_mes[2] == 'N') ) (cartas + i)->mes = 6;
		else if( ( (cartas + i)->nome_mes[0] == 'J' || (cartas + i)->nome_mes[0] == 'j') && ((cartas + i)->nome_mes[2] == 'L' || (cartas + i)->nome_mes[2] == 'l') ) (cartas + i)->mes = 7;
		else if( ( (cartas + i)->nome_mes[0] == 'A' || (cartas + i)->nome_mes[0] == 'a') && ((cartas + i)->nome_mes[2] == 'O' || (cartas + i)->nome_mes[2] == 'o') ) (cartas + i)->mes = 8;
		else if( (cartas + i)->nome_mes[0] == 'S' || (cartas + i)->nome_mes[0] == 's') (cartas + i)->mes = 9;
		else if( (cartas + i)->nome_mes[0] == 'O' || (cartas + i)->nome_mes[0] == 'o') (cartas + i)->mes = 10;
		else if( (cartas + i)->nome_mes[0] == 'N' || (cartas + i)->nome_mes[0] == 'n') (cartas + i)->mes = 11;
		else if( (cartas + i)->nome_mes[0] == 'D' || (cartas + i)->nome_mes[0] == 'd') (cartas + i)->mes = 12;

	}
}

int melhor(struct dados i, struct dados j){
	if( i.ano > j.ano ) return 1;
	if( i.ano < j.ano ) return 0;

	if( i.mes > j.mes ) return 1;
	if( i.mes < j.mes ) return 0;

	if( i.dia > j.dia ) return 1;
	if( i.dia < j.dia ) return 0;

	if( strcmp(i.rem, j.rem) > 0 ) return 1;
	if( strcmp(i.rem, j.rem) < 0 ) return 0;

	if( strcmp(i.dest, j.dest) > 0 ) return 1;
	if( strcmp(i.dest, j.dest) < 0 ) return 0;

	return 0;

}

void trocar(struct dados *i, struct dados *j){
	struct dados aux;
	aux = *j;
	*j = *i;
	*i = aux;
}

void ordenar(struct dados *cartas, int n){
	int i, j;

	for(i = 0; i < n; i++){
		for(j = i; j < n; j++){
			if( melhor( cartas[i], cartas[j] ) ){
				trocar( &cartas[j], &cartas[i] );
			}
		}
	}

}

void main(){

	int n, i;
	char lixo[5];
	scanf("%d\n", &n);

	struct dados cartas[n];

	for(i = 0; i < n; i++){
		scanf("%d de ", &cartas[i].dia);
		scanf("%s", cartas[i].nome_mes);
		scanf("%s", lixo);
		scanf(" %d\n", &cartas[i].ano);
		gets(cartas[i].remetente);
		gets(cartas[i].destinatario);

		tl(cartas[i].remetente, cartas[i].rem);
		tl(cartas[i].destinatario, cartas[i].dest);
	}

	transformar(cartas, n);
	ordenar(cartas, n);

	for(i = 0; i < n; i++){
		printf("%d de %s de %d\n", cartas[i].dia, cartas[i].nome_mes, cartas[i].ano);
		printf("%s\n", cartas[i].remetente);
		printf("%s\n", cartas[i].destinatario);
	}

}