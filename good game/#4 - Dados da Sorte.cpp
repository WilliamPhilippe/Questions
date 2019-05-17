#include <bits/stdc++.h>
using namespace std;

int vetor[10] = {0};
int jogadas, distancia;
int vezes = 0;


int verificar(){
	int soma = 0;
	for(int i = 0; i < 10; i++){
		soma += vetor[i];
	}

	return soma >= distancia ? 1 : 0;
}

void next(int vez){
	if (vez > jogadas) return;

	for(int i = 1; i <= 6; i++){
		vetor[vez - 1] = i;

		if(vez == jogadas) vezes += verificar();
		else next(vez + 1);
	}

}

int jogar(int vez){
	int vezes = 0;

	for(int i = 1; i <= 6; i++){
		vetor[0] = i;

		if(vez == jogadas) vezes += verificar();
		else next(vez + 1);
	}
}

int main()
{
	cin >> jogadas >> distancia;

	jogar(1);

	cout << vezes;

	return 0;
}