#include <bits/stdc++.h>
using namespace std;



typedef struct c
{
	int gold[11];
	int level;
} str;

int func(str i, str j){

	for(int k = 10; k >= 1; k--){

		if( i.gold[k] > j.gold[k] ) return 1;
		else if( i.gold[k] < j.gold[k] ) return 0;

	}

	return (i.level < j.level);

}

void troca(struct c *i, struct c *j){
	str aux = *i;
	*i = *j;
	*j = aux;
}

void ordenar(struct c *dados, int ini, int fim){

	for(int i = 1; i < fim; i++){
		for(int j = i + 1; j < fim; j++){
			if( func( dados[j], dados[i]) ){
				troca( &dados[j], &dados[i]);
			}
		}
	}

}



int main(){
	
	int n;
	cin >> n;
	str dados[n + 1];

	for(int i = 1; i <= n; i++){
		dados[i].level = i;
		int a; cin >> a;
		for(int j = 1; j <= 10; j++){
			cin >> dados[i].gold[j];
		}

		for(int j = a + 1; j <= 10; j++){
			dados[i].gold[j] = 0;
		}
	}

	ordenar(dados, 1, n + 1);	

	for(int i = 1; i <= n; i++){
		cout << dados[i].level << endl;
	}


	return 0;
}