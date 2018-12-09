#include <bits/stdc++.h>
using namespace std;

vector<string> matriz;

void bt(int i, int j, char contorno, char mark){
	if(i < 0 || i >= matriz.size() || j < 0 || j >= matriz[i].size() || matriz[i][j] != ' ') return;
	matriz[i][j] = mark;

	bt(i - 1, j, contorno, mark);
	bt(i, j - 1, contorno, mark);
	bt(i + 1, j, contorno, mark);
	bt(i, j + 1, contorno, mark);

}

void process(char contorno){

	for(int i = 0; i < matriz.size(); i++){
		for(int j = 0; matriz[i][j] != '\0'; j++){
			if( matriz[i][j] != ' ' && matriz[i][j] != contorno && matriz[i][j] != '_'){
				bt(i - 1, j, contorno, matriz[i][j]);
				bt(i, j - 1, contorno, matriz[i][j]);
				bt(i + 1, j, contorno, matriz[i][j]);
				bt(i, j + 1, contorno, matriz[i][j]);
			}
		}
	}

}

int main(){
	int i = 0, aa = 0;
	char x[100], contorno, linha[100];
	int tt, cont = 0;
	while(1){

		if(!gets(x)) break;
		if(x[0] == '\0') {aa = 1; tt = cont; continue;}
		cont++;
		if(matriz.size() == 0){
			while(1){
				if(x[i] != ' '){ contorno = x[i]; i = 0; break;}
				i++;
			}
		}

		if(x[0] == '_'){
			
			aa = 0;
			process(contorno);
				for(int t = 0; t < matriz.size(); t++){
					if(t == tt){
						cout << endl;
						tt = INT_MAX;
					}
					cout << matriz[t] << endl;
			}
			printf("%s\n", x);
				
			matriz.clear();
			cont = 0; 
		}
		else
			matriz.push_back(x);
	}

}
