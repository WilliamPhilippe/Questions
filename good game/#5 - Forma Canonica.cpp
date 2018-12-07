#include <bits/stdc++.h>
using namespace std;

typedef pair<char, char> par;
vector<char> verify;

map<char, char> letras;


void forma(char *str, char *str2){

	char cont = 'a';
	int i = 0;

	while( str[i] != '\0' ){

		if(  ){
			//existe
			str2[i] = letras[str[i]];
		}
		else{
			//nao existe
			letras[str[i]] = cont;
			verify.push_back(str[i]);
			cont++;
			str2[i] = letras[str[i]];

		}

		i++;

	}

	str2[i + 1] = '\0';

}

int main(){

	int t;
	scanf("%d\n", &t);

	while(t--){
		char str[501], str2[501];
		gets(str);

		forma(str, str2);
		printf("%s\n", str);
		printf("%s\n", str2);
	}


}