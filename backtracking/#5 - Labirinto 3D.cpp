#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int p,l,c;
int solved = 0;
char *sol;


void bt(char lab[l][c][p], int pi, int pj, int pk, int id){

	if(lab[pi][pj][pk] == '#') return;
	if(solved) return;

	if(pi + 1 == l && pj + 1 == c && pk + 1 == p){
		int x;
		printf("%d\n", id);
		for(x = 0; x < id; x++){
			if(x == 0) printf("%c", sol[x]);
			else{
				printf(" -> %c", sol[x]);
			}
		}
		
		solved = 1;
		return;
	}
	
	lab[pi][pj][pk] = '#';

	if( pi - 1 >= 0 && lab[pi - 1][pj][pk] == '.' ){
		sol[id] = 'U';
		bt(lab, pi - 1, pj, pk, id + 1);
		lab[pi - 1][pj][pk] = '.';
	}
	if( pi + 1 < l && lab[pi + 1][pj][pk] == '.' ){
		sol[id] = 'D';
		bt(lab, pi + 1, pj, pk, id + 1);
		lab[pi + 1][pj][pk] = '.';
	}
	if( pj - 1 >= 0 && lab[pi][pj - 1][pk] == '.' ){
		sol[id] = 'L';
		bt(lab, pi, pj - 1, pk, id + 1);
		lab[pi][pj - 1][pk] = '.';
	}
	if( pj + 1 < c && lab[pi][pj + 1][pk] == '.' ){
		sol[id] = 'R';
		bt(lab, pi, pj + 1, pk, id + 1);
		lab[pi][pj + 1][pk] = '.';
	}
	if( pk + 1 < p && lab[pi][pj][pk + 1] == '.' ){
		sol[id] = 'F';
		bt(lab, pi, pj, pk + 1, id + 1);
		lab[pi][pj][pk + 1] = '.';
	}
	if( pk - 1 >= 0 && lab[pi][pj][pk - 1] == '.' ){
		sol[id] = 'B';
		bt(lab, pi, pj, pk - 1, id + 1);
		lab[pi][pj][pk - 1] = '.';
	}

}

void main(){

	
	scanf("%d %d %d\n", &p, &l, &c);
	char lab[l][c][p];
	char lixo;
	int i, j, k;

	sol = malloc(i * j * k * sizeof(char));

	for(k = 0; k < p; k++){
		for(i = 0; i < l; i++){
			for(j = 0; j < c; j++){
				scanf("%c", &lab[i][j][k]);
			}
			scanf("%c", &lixo);
		}
		scanf("%c", &lixo);
	}

	bt(lab, 0, 0, 0, 0);

}