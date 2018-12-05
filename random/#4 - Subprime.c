#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int verificar(int renda[], int b){
    int i;
    for(i = 0; i < b; i++){
        if(renda[i] < 0) return 0;
    }
    
    return 1;
}

int main() {
    int b, n, i, d, c, v;
    
    while(1){
        scanf("%d %d\n", &b, &n);
        if(b == 0 && n == 0) break;
        
        int renda[b];
        for(i = 0; i < b; i++) scanf("%d", &renda[i]);
        while(n--){
            scanf("%d %d %d\n", &d, &c, &v);
            renda[d - 1] -= v;
            renda[c - 1] += v;
        }
        
        if(verificar(renda, b)) printf("S\n");
        else printf("N\n");
        
    }
	return 0;
}
