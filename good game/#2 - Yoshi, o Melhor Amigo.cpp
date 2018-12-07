#include <bits/stdc++.h>
using namespace std;

int main(){

	int m;
	cin >> m;

	double c_verde, c_verme, c_ama, c_azul, maior = -100000.0;
	int c = 0;
	int p, v, mv;
	string nome;

	cin >> p >> v;
	c_verde = v/((double) p);
	mv = p;
	if(c_verde > maior && p <= m) maior = c_verde, nome = "Verde";
	if(p <= m) c = 1;

	cin >> p >> v;
	c_verme = v/((double) p);
	if(c_verme > maior && p <= m) maior = c_verme, nome = "Vermelho";
	if(p <= m) c = 1;

	cin >> p >> v;
	c_azul = v/((double) p);
	if(c_azul > maior && p <= m) maior = c_azul, nome = "Azul";
	if(p <= m) c = 1;

	cin >> p >> v;
	c_ama = v/((double) p);
	if(c_ama > maior && p <= m) maior = c_ama, nome = "Amarelo";
	if(p <= m) c = 1;

	if(!c){
		cout << "Acho que vou a pe :(" << endl;
		return 0;
	}

	if( maior - c_verde <= 1.0 && mv <= m){
		cout << "Verde" << endl;
	}
	else cout << nome << endl;


	return 0;
}