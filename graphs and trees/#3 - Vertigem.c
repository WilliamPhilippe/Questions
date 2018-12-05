#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dado
{
	int l, c, pmap, pal;
	char nome[101];
	int **mov;
	int **pt;

};

long int pontos = 0;

void alocar(struct dado *m){
	m->mov = malloc(m->l * sizeof(int *));
	m->pt = malloc(m->l * sizeof(int *));

	int i;
	for(i = 0; i < m->l; i++){
		m->mov[i] = malloc(m->c * sizeof(int));
		m->pt[i] = malloc(m->c * sizeof(int));
	}
}

int eh_p(char *nome){
	int i, j;

	for(i = 0, j = strlen(nome) - 1; i != j && i < j; i++, j--){
		if(nome[j] != nome[i]) return 0;
	}

	return 1;
}

void uhul(struct dado *mapas, int map, int pi, int pj){

	if( mapas[map].mov[pi][pj] != 4 ){
		mapas[map].pmap += mapas[map].pt[pi][pj] * mapas[map].pal;
		pontos += mapas[map].pt[pi][pj] * mapas[map].pal;
	}

	if(mapas[map].l == pi + 1 && mapas[map].c == pj + 1) return;

	if( mapas[map].mov[pi][pj] == 0 ){
		pi = (pi - 1 + mapas[map].l)%mapas[map].l;
		uhul(mapas, map, pi, pj);
	}
	else if( mapas[map].mov[pi][pj] == 1 ){
		pi = (pi + 1 + mapas[map].l)%mapas[map].l;
		uhul(mapas, map, pi, pj);
	}
	else if( mapas[map].mov[pi][pj] == 2 ){
		pj = (pj - 1 + mapas[map].c)%mapas[map].c;
		uhul(mapas, map, pi, pj);
	}
	else if( mapas[map].mov[pi][pj] == 3 ){
		pj = (pj + 1 + mapas[map].c)%mapas[map].c;
		uhul(mapas, map, pi, pj);
	}
	else if( mapas[map].mov[pi][pj] == 4 ){
		int temp, next;
		next = mapas[map].pt[pi][pj];
		temp = pontos % (mapas[next].l * mapas[next].c);

		int x = 0, i, j;

		for(i = 0; i < mapas[next].l; i++){
			for(j = 0; j < mapas[next].c; j++, x++){
				if(x == temp){
				//	printf("%d %d %d %d %d\n", i, j, temp, x, pontos);
					uhul(mapas, next, i, j);
					return;
				}
			}
		}

		return;
	}
	

}

void main(){

	int n, i, ll, cc;
	scanf("%d\n", &n);

	struct dado mapas[n];

	for(i = 0; i < n; i++){

		scanf("%d %d\n", &mapas[i].l, &mapas[i].c);
		gets(mapas[i].nome);

		mapas[i].pmap = 0;
		mapas[i].pal = 1; 
		eh_p(mapas[i].nome) == 1 ? (mapas[i].pal) = 2 : (mapas[i].pal);
		
		alocar(&mapas[i]);

		int a, b;
		for(a = 0; a < mapas[i].l; a++){
			for(b = 0; b < mapas[i].c; b++){
				scanf("%d,%d", &mapas[i].mov[a][b], &mapas[i].pt[a][b]);
			}
		}

	}

	uhul(mapas, 0, 0, 0);

	printf("%d\n", pontos);

	for(i = 0; i < n; i++){
		printf("%s %d\n", mapas[i].nome, mapas[i].pmap);
	}


}
