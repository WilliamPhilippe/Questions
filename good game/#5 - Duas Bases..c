#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int nx, ny, by, bx, i, j, num;
    long long int x = 0, y = 0;
    scanf("%d %d\n", &nx, &bx);
    int xx[nx];
    
    for(i = 0; i < nx; i++){
        scanf("%d", &num);
        x += num*pow(bx, nx - 1 - i);
    }
    
    scanf("%d %d\n", &ny, &by);
    int yy[ny];
    
    for(i = 0; i < ny; i++){
        scanf("%d", &num);
        y += num*pow(by, ny - 1 - i);
    }
    
    if(x > y) printf(">\n");
    else if(x == y) printf("=\n");
    else printf("<\n");
    
    
	return 0;
}