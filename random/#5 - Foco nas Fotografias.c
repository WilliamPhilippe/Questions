
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


void ordenar(int *vini, int *vfim, int n){
	int i, j, aux;
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			if(vini[j] > vini[i]){
				aux = vini[j];
				vini[j] = vini[i];
				vini[i] = aux;
				aux = vfim[j];
				vfim[j] = vfim[i];
				vfim[i] = aux;
			}
			else if(vini[j] == vini[i] && vfim[j] > vfim[i]){
				aux = vini[j];
				vini[j] = vini[i];
				vini[i] = aux;
				aux = vfim[j];
				vfim[j] = vfim[i];
				vfim[i] = aux;
			}
		}
	}
}

int main() {
    int n, ini, fim, a, b, count, i;
    
    while(scanf("%d\n", &n) != EOF){
        count = 1;
        int vini[n], vfim[n];
        
        for(i = 0; i < n; i++) scanf("%d %d\n", &vini[i], &vfim[i]);
        ordenar(vini, vfim, n);
    	//for(i = 0; i < n; i++) printf("%d %d\n", vini[i], vfim[i]);

    	ini = vini[0]; fim = vfim[0];
    	
    	for(i = 1; i < n; i++){
    		if(vini[i] > fim){
    			count++;
    			fim = vfim[i];
    		}
    	}

    	printf("%d\n", count);
    }
    
    
    
	return 0;
}


