#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct dados
{	
	char palavra[11];
};

void busca(struct dados *vetor, int ls, int li, char *sort, int cont){

	int p = (li + ls)/2;
	int i;

	//1 2 3 5 6 7 8 9 10
	//44  21 10 4 2 3 4

	//printf("%s %d %d %d\n", vetor[p].palavra, p, ls, li);

	if( ls > li ){
		printf("NAO %d\n", cont);
				return;
	}

	for(i = 0; ; i++){

		if( vetor[p].palavra[i] == '\0' && sort[i] == '\0' ){
			
			
			printf("SIM %d\n", cont);
			return;
		}
		else if( vetor[p].palavra[i] != sort[i] ){
			//if( ls > li ) printf("%d %d\n", p, i);

			if(ls >= li){
				if( vetor[p].palavra[i] != '\0' && sort[i] != '\0' )	cont++;
				printf("NAO %d\n", cont);
				return;
			}
			else{
				if( vetor[p].palavra[i] > sort[i] ){
					if( vetor[p].palavra[i] != '\0' && sort[i] != '\0' ) cont++;

					
					busca(vetor ,ls, p - 1, sort, cont);
					return;
				}
				else{
					if( vetor[p].palavra[i] != '\0' && sort[i] != '\0' )	cont++;
					
					busca(vetor, p + 1, li, sort, cont);
					return;
				}
			}
		}
		else
			cont++;
	}
}

void main(){

	int n, m, i;

	scanf("%d %d\n", &n, &m);
	char sort[11];
	struct dados vetor[n];

	for(i = 0; i < n; i++){
		gets(vetor[i].palavra);
	}

	for(i = 0; i < m; i++){
		gets(sort);
		busca(vetor, 0, n - 1, sort, 0);
	}
}
