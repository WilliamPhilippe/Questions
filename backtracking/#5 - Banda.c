#include <stdio.h>
#include <ctype.h>
#include <string.h>

struct musico
{
	int cantou[101];
	int entro[101];
	int cc;
};

void backtracking(struct musico *musicos, int n_musc, int m_atual,
				  int *sol_atual, int *sol_final, int *e_max, int e, int col){

	if(col == 2){
		int i, j;

		for(i = 0; i < 3; i++){
			for(j = 0; j < 3; j++){
				if(i != j){

					e += (musicos + sol_atual[i])->entro[sol_atual[j]];

				}
			}
		}

	}

	int s, soma; soma = sol_atual[0] + sol_atual[1] + sol_atual[2];
		s = sol_final[0] + sol_final[1] + sol_final[2]; 

	if(e > (*e_max)){
		(*e_max) = e;

	    sol_final[0] = sol_atual[0], sol_final[1] = sol_atual[1]; sol_final[2] = sol_atual[2];
	}

	if(e == (*e_max) && s >= soma && sol_atual[0] != sol_atual[1] && sol_atual[1] != sol_atual[2]
			&& sol_atual[0] != sol_atual[2]){
		(*e_max) = e;

	    sol_final[0] = sol_atual[0], sol_final[1] = sol_atual[1]; sol_final[2] = sol_atual[2];
	}


	if(col == 2) return;

	int i, j, value;

	for( i = 1; i <= n_musc; i++){

		value = 1;
		for(j = 0; j <= col; j++) if(sol_atual[j] == i) value = 0;

		if(value){
			sol_atual[col + 1] = i;
			backtracking(musicos, n_musc, i, sol_atual, sol_final, e_max, 0, col + 1);
		}

	}

}

void main(){

while(1){
	int n_musc, par, i, j, a, b, e;
	if(scanf("%d %d\n", &n_musc, &par) == EOF) return;

	if(n_musc == 0 && par == 0) return;

	struct musico musicos[n_musc + 1];

	for(i = 1; i <= n_musc; i++){
		memset(musicos[i].cantou, 0, sizeof(musicos[i].cantou));
		memset(musicos[i].entro, 0, sizeof(musicos[i].entro));
		musicos[i].cc = 0;
	}

	for(i = 1; i <= par; i++){
		if(scanf("%d %d %d\n", &a, &b, &e) == EOF) return;

		musicos[a].cc = 1;
		musicos[a].cantou[b] = 1;
		musicos[a].entro[b] = e;
	}

	int sol_atual[3] = {1, 2, 3};
	int sol_final[3] = {1, 2, 3};
	int e_max = 0;

	for(i = 1; i <= n_musc; i++){
		if(musicos[i].cc){
			sol_atual[0] = i;
			backtracking(musicos, n_musc, i, sol_atual, sol_final, &e_max, 0, 0);
		}
	}

	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			if(sol_final[j] > sol_final[i]){
				e = sol_final[j];
				sol_final[j] = sol_final[i];
				sol_final[i] = e;
			}
		}
	}

	printf("%d %d %d\n", sol_final[0], sol_final[1], sol_final[2]);

}

}
