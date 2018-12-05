#include <stdio.h>
#include <math.h>

int main() {
    int i = 1;
    long int n, x, ori;
    long int count = 0;
    scanf("%ld\n", &n);

    ori = n;
   while(1){
      if(n < pow(10, i)){ count += n*i; break;}
      if(i == 1) x = 9;
      else x = 9*pow(10, i - 1);
      count += x*i;
      n = n - x;
      i++;
   }
    //printf("%d\n", i);
    if(ori == pow(10, i)) count++;
    else if(ori == pow(10, i) + 1) count += 2;
    printf("%lld\n", count);
    
	return 0;
}