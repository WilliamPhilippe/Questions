#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NMAX 1000
#define MAXCANDIDATOS 2

void solucionar(int a[], int k){
	int i;

	printf("{");
	for(i = 1; i <= k; i++){
		if(a[i]) printf(" %d", i);
	}
	printf(" }\n");
}

void backtracking(int a[], int k, int n){
	int c[MAXCANDIDATOS];
	int ncandidatos, i;

	if(k == n){
		solucionar(a, k);
	}
	else{

		k++;
		c[0] = 1; c[1] = 0;
		ncandidatos = 2;

		for(i = 0; i < ncandidatos; i++){
			a[k] = c[i];
			backtracking(a, k, n);
		}

	}
}

void main(){
	int n;
	scanf("%d\n", &n);

	int a[NMAX];
	backtracking(a, 0, n);
}

