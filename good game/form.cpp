#include <bits/stdc++.h>

using namespace std;

int main(){

	char num[1000];

	vector<char> vetor;
	char x; int i = 0;
	char b, c;
	b == '0'; c == '0';

	while(cin >> x){
		if(x == '.') break;
		vetor.push_back(x);
	}
	cin >> b >> c;

	if( b < 48 || b > 57) b = '0';
	if( c < 48 || c > 57) c = '0';

	int t;

	cout << "R$ ";
	for(i = 0, t = vetor.size(); i < vetor.size(); i++, t--){
		if(t != vetor.size() && t%3 == 0){
			cout << '.';
		}
		cout << vetor[i];
	}
	cout << '.' << b << c;

	return 0;
}