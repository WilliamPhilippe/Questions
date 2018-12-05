#include <bits/stdc++.h> 


using namespace std;

int main(){

    set<int> A;
    set<int> B;

    int i, x, y, anna, bia, count;

while(1){
    A.clear();
    B.clear();

	count = 0;
    cin >> anna >> bia;
    if(anna == 0 && bia == 0) return 0;

    for(i = 0; i < anna; i++){
    	cin >> x;
    	A.insert(x);
    }	
    for(i = 0; i < bia; i++){
    	cin >> x;
    	B.insert(x);
    }

    x = 0;
    y = 0;

    
    	for(auto i:A){
    		if(B.find(i) == B.end()) x++;
    	}
        for(auto i:B){
            if(A.find(i) == A.end()) y++;
        }

        if( x > y) cout << y << endl;
        else cout << x << endl;

    //cout << count << endl;

}

}