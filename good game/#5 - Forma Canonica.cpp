#include <bits/stdc++.h>
using namespace std;

typedef pair<char, char> par;

vector<char> verify;

map<char, char> letras;


int buscar(char x){

	for(int i = 0; i < verify.size(); i++){
		if( verify[i] == x ) return 1;
	}

	return 0;
}

void forma(char *str, char *str2){

	char cont = 'a';
	int i = 0;

	while( str[i] != '\0' ){

		int existe = buscar(str[i]);

		if( existe ){
			//existe
			str2[i] = letras[str[i]];
		}
		else{
			//nao existe
			verify.push_back(str[i]);
			letras[str[i]] = cont;
			cont++;
			str2[i] = letras[str[i]];

		}

		i++;

	}

	str2[i] = '\0';

}

int main(){

	int t;
	scanf("%d\n", &t);

	while(t--){
		char str[501], str2[501];
		gets(str);

		letras.clear();
		verify.clear();

		forma(str, str2);

		printf("%s\n", str2);
	}


}
