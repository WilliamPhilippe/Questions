#include <bits/stdc++.h>

using namespace std;

int main(){
    
    vector<int> v;

	int n;
	cin >> n;
	while(n > 0){
		v.push_back(n%10);
		n /= 10;
	}
	
	for(int i = v.size() - 1; i >= 0; i--){
	    cout << v[i] << " ";
	}
}