#include <stdio.h>

char matriz[256][256];

void focar(int l, int c, int li, int lf, int ci, int cf){
	float centrolinha, centrocoluna;
	if(li == lf && ci == cf){
		printf("0");
		return;
	}
	else{
		centrolinha = (lf - li)/2.0 + li;
		centrocoluna = (cf - ci)/2.0 + ci;
		if(l < centrolinha && c < centrocoluna){
			//2 quadrante
			printf("2");
			focar(l, c, li, (int) centrolinha, ci, (int) centrocoluna);
		}
		else if(l < centrolinha && c > centrocoluna){
			// 1 quadrante
			printf("1");
			focar(l, c, li, (int) centrolinha, (int) centrocoluna + 1.0, cf);
		}
		else if(l > centrolinha && c < centrocoluna){
			// 3 quadrante
			printf("3");
			focar(l, c, (int) centrolinha + 1.0, lf, ci, (int) centrocoluna);
		}
		else if(l > centrolinha && c > centrocoluna){
			// 4 quadrante
			printf("4");
			focar(l, c, (int) centrolinha + 1.0, lf, (int) centrocoluna + 1.0, cf);
		}
		
	}
}

void main(){
	int i, t, j, l, c;
	scanf("%d\n", &t);
	char lixo;
	
	for(i = 0; i < t; i++){
		for(j = 0; j < t; j++){
			scanf("%c", &matriz[i][j]);
			if(matriz[i][j] == '*'){
				l = i; c = j;
			}
		}
		scanf("%c", &lixo);
	}

	focar(l, c, 0, t - 1, 0, t - 1);

}