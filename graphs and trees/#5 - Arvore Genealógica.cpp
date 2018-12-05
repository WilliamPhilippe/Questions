#include <bits/stdc++.h>

#define pb push_back

using namespace std;
typedef long long ll;

set<string> people;
map<string, string> parent;
map<string, ll> order;

ll kin(string A, string B) {
    if(A == B)
        return 0;
    if(!people.count(A) || !people.count(B))
        return INT_MAX;
    return 1 + min(kin(parent[A], B), kin(A, parent[B]));
}

int main() {
    ll N; string v1, v2;
    cin >> N;
    for(ll n=0;n<N;n++) {
        cin >> v1 >> v2;
        parent[v2] = v1;
        if(!order.count(v1))
            order[v1] = n;
        if(!order.count(v2))
            order[v2] = n;
        people.insert(v1), people.insert(v2);
    }
    ll opt = INT_MIN;
    for(auto i = people.begin(); i!=people.end(); i++) {
        for(auto j = next(i); j!=people.end(); j++) {
            ll deg = kin(*i, *j);
            if(deg>opt) {
                opt = deg;
                v1 = min(*i,*j), v2 = max(*i,*j);
            } else if(deg == opt) {
                if(min(*i, *j) == v1 && max(order[*i], order[*j])<order[v2])
                    v1 = min(*i,*j), v2 = max(*i,*j);
            }
        }
    }
    cout << v1 << " " << v2 << " " << opt << endl;
}
