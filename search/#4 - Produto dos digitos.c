#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    long int dig1 = 1, dig2 = 1, dig3 = 1, dig4 = 1, dig5 = 1, dig6 = 1, c = 1, prod;
    int n;
    scanf("%d\n", &n);
    
while(1){
    
    c++;
    
    dig1 = c%10;
    dig2 = (c%100 - dig1)/10;
    if(c > 99){
        dig3 = ((c - c%100)/100)%10;
    }
    if(c > 999){
        dig4 = ((c - c%1000)/1000)%10;
    }
    if(c > 9999){
        dig5 = ((c - c%10000)/10000)%10;
    }
  
    prod = dig1*dig2*dig3*dig4*dig5;
    if(prod == n) break;
    
    if(n == 0){
     c = 0;
    }
    
    if(c > 100000){
        c = -1;
        break;
    }
}
    
    
    printf("%d\n", c);

    
	return 0;
}