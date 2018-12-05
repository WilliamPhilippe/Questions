#include <stdio.h>

void main(){
	int i, j, y, n, m;
	int inseticida = 0, colhidos = 0;
	scanf("%d %d\n", &n, &m);
	int matriz[100][100];
	for(i = 0; i < n; i++){
		for(j = 0; j < m; j++){
			scanf("%d", &matriz[i][j]);
		}
	}

	char string[10], trash, lixo;
	scanf("\n%c", trash); 
	while(scanf("%s\n", string) != EOF){
			if(string[0] == 'P'){
				while(1){
					if(scanf("%d%c", &y, &lixo) == EOF) break;
					for(i = 0; i < m; i++){
						if(matriz[y][0] == 3) break;
						if(matriz[y][i] == 0){
							matriz[y][i]++;
							inseticida += 2;
						}
					}
					if(lixo == '\n') break;
				}
			}
			else if(string[0] == 'T'){
				for(i = 0; i < n; i++){
					for(j = 0; j < m; j++){			
						if(matriz[i][j] == 1){
							matriz[i][j] = 2;
							inseticida += 2;
						}
						else if(matriz[i][j] == 2){
							matriz[i][j] = 3;
						}
					}
				}
			}
			else if(string[0] == 'C'){
				for(i = 0; i < n; i++){
					for(j = 0; j < m; j++){
						if(matriz[i][j] == 3){
							matriz[i][j] = 0;
							colhidos++;
						}
						else if(matriz[i][j] == -1) matriz[i][j] = 0;
					}
				}
			}
			else{
				scanf("%d %d\n", &i, &j);
				matriz[i][j] = -1;
			}	
	}

	for(i = 0; i < n; i++){
		printf("%d", matriz[i][0]);
		for(j = 1; j < m; j++){
				printf(" %d", matriz[i][j]);
		}
		printf("\n");
	}

	printf("\nForam colhidos %d morangos.\nForam utilizados %dml de inseticida.\n", colhidos, inseticida);

}