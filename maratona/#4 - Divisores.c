#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int d, nd, m, nm, n = 0, i=0;
    scanf("%d %d %d %d\n", &d, &nd, &m, &nm);
    
    while(!((n != 0) && (n%d == 0) && (n % nd !=0) && (m % n == 0) && (nm % n != 0))){
       
       n = n + d;
       if(n > 100000000) break;
    }
    if(n < 100000000) printf("%d\n", n);
    else printf("-1\n");
    
    
	return 0;
}