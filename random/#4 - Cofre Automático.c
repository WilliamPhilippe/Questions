#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int n, i, x, fat, count, h = 0;
    char c;
    scanf("%d\n", &n);
    fat = n*100000;
    int roleta[n];
    for(i = 0; i < n; i++) scanf("%d\n", &roleta[i]);
    
    while(1){
        count = 1;
        scanf("%c %d\n", &c, &x);
        if(c == 'S') break;
        if(c == 'D'){
            fat -= x;
        }
        else if(c == 'E'){
            fat += x;
        }
        
        if(h++) printf("\n");
        for(i = fat%n; count <= n; i++, count++){
           if(i == fat%7) printf("%d ", roleta[i%n]);
           else printf("%d ", roleta[i%n]);
        }
       // printf("\n");
    }
    
    
    
	return 0;
}
