#include <stdio.h>
#include <string.h>

char matriz[201][201], lixo;

int verificar(int l, int lf, int c, int cf){
	int i, j; 
	char ant;
	ant = matriz[l][c];

	for(i = l; i <= lf; i++){
		for(j = c; j <= cf; j++){
			if(matriz[i][j] != ant) return -1;
		}
	}

	 if(ant == '0') return 0;
	 return 1;
}


void bitmap(int *contador, int l, int lf, int c, int cf){
	
	int x;
	x = verificar(l, lf, c, cf);

	float centroLinha, centroColuna;

	centroLinha = (lf - l)/2.0 + l;
	centroColuna = (cf - c)/2.0 + c;



	if(x == 1){
		printf("1");
		if(*contador == 49){
		    printf("\n");
		    *contador = 0;
		}
		else (*contador) ++;
		//return;
	}
	else if(x == 0){
		printf("0");
		if(*contador == 49){
		    printf("\n");
		    *contador = 0;
		}
		else
		(*contador) ++;
		//return;
	}
	else if(x == -1){
		printf("D");
		if(*contador == 49){
		    printf("\n");
		    *contador = 0;
		}
		else (*contador) ++;
		
		if(c == cf && l != lf){
			bitmap(contador, l, (int) centroLinha, c, c);
			bitmap(contador, (int) centroLinha + 1.0, lf, c, c);
		}
		else if(l == lf && c != cf){
			bitmap(contador, l, l, c, (int) centroColuna);
			bitmap(contador, l, l, (int) centroColuna + 1.0, cf);
		}
		else{

			bitmap(contador, l, (int) centroLinha, c, (int) centroColuna);
			bitmap(contador, l, (int) centroLinha, (int) centroColuna + 1.0, cf);
			bitmap(contador, (int) centroLinha + 1.0, lf, c, (int) centroColuna);
			bitmap(contador, (int) centroLinha + 1.0, lf, (int) centroColuna + 1.0, cf);

		}

	}
}

void main(){
	int test, l, c, i, j, contador;
	scanf("%d\n", &test);

	while(test--){
		scanf("%d %d\n", &l, &c);
		
		for(i = 0; i < l; i++){
			for(j = 0; j < c; j++){
				scanf("%c", &matriz[i][j]);
			}
			scanf("%c", &lixo);
		}

        contador = 0;
		bitmap(&contador, 0, l - 1, 0, c - 1);
		printf("\n");
	}

}
