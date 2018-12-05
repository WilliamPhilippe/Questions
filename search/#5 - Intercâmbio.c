#include <stdio.h>

struct dados
{
	int origem;
	int destino;
	int visitados;
};

int verificar(struct dados *pas, int ini, int n){
	int i;

	for(i = ini; i < n; i++){
		if( (pas + i)->visitados == 0 ){
			if( (pas + i)->origem == (pas + ini)->destino && (pas + i)->destino == (pas + ini)->origem  ){
				(pas + i)->visitados = 1;
				return 1;
			}
		}
	}
	return 0;
}

void main(){

	int n, i, value;
	

	while(1){
		scanf("%d\n", &n);
		if(n == 0) break;
		struct dados pas[n];

		for(i = 0; i < n; i++){
			scanf("%d %d\n", &pas[i].origem, &pas[i].destino);
			pas[i].visitados = 0;
		}
		value = 1;

if(n < 500)
		for(i = 0, value = 1; i < n; i++){
			if( pas[i].visitados == 0 ){
				pas[i].visitados = 1;
				value = verificar(pas, i, n);
			}

			if(value == 0) break;
		};

		if(value) puts("YES");
		else puts("NO");

	}

}