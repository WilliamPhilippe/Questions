#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    char risada[50];
    int i, n, count = 0, marc = 0;
    scanf("%s\n", risada);
    
    n = strlen(risada);
    char l1[n], l2[n];
    
    for(i = 0; i < n; i++){
        switch(risada[i]){
            case 'a':
                l1[count] = 'a';
                count++;
                break;
            case 'e':
                l1[count] = 'e';
                count++;
                break;
            case 'i':
                l1[count] = 'i';
                count++;
                break;
            case 'o':
                l1[count] = 'o';
                count++;
                break;
            case 'u':
                l1[count] = 'u';
                count++;
                break;
        }
    }
    char k1[count], k2[count];
    count = 0;
    for(i = (n-1); i >= 0; i--){
        switch(risada[i]){
            case 'a':
                l2[count] = 'a';
                count++;
                break;
            case 'e':
                l2[count] = 'e';
                count++;
                break;
            case 'i':
                l2[count] = 'i';
                count++;
                break;
            case 'o':
                l2[count] = 'o';
                count++;
                break;
            case 'u':
                l2[count] = 'u';
                count++;
                break;
        }
    }
    
    for(i = 0; i < count; i++){
        if(l1[i] == l2[i]) marc++;
    }
    
    if(marc == count) printf("S\n");
    else printf("N\n");
    
	return 0;
}