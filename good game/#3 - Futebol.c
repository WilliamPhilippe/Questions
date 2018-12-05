#include <stdio.h>

void ordenar(int placares[][3], int jogos){
	int i, j;
	int aux1, aux2, aux3;

	for(i = 0; i < jogos; i++){
		for(j = 0; j < jogos; j++){
			if( placares[i][2] > placares[j][2] ){

				aux1 = placares[i][2];
				placares[i][2] = placares[j][2];
				placares[j][2] = aux1;

				aux1 = placares[i][0];
				placares[i][0] = placares[j][0];
				placares[j][0] = aux1;

				aux1 = placares[i][1];
				placares[i][1] = placares[j][1];
				placares[j][1] = aux1;

			}
		}
	}
}

int golas(int placares[][3], int jogos, int gols){
	int i, pts = 0;

	for(i = 0; i < jogos && gols > 0; i++){
		if( placares[i][2] == 0 ){
			if(gols > 0){
				placares[i][0]++; placares[i][2]++;
				gols--;
			}
		}	
		else if( placares[i][2] < 0 ){

			while( gols > 0 && placares[i][2] < 1 ){
				placares[i][0]++; placares[i][2]++;
				gols--;
			}

		}
	}

	for(i = 0; i < jogos; i++){
		if(placares[i][2] == 0) pts++;
		if(placares[i][2] > 0) pts += 3;
	}

	return pts;

}

void main(){

	int jogos, gols, i;
	scanf("%d %d\n", &jogos, &gols);
	int placares[jogos][3];

	for(i = 0; i < jogos; i++){

		scanf("%d %d\n", &placares[i][0], &placares[i][1]);
		placares[i][2] = placares[i][0] - placares[i][1];
	}

	ordenar(placares, jogos);

	printf("%d\n", golas(placares, jogos, gols) );


}
