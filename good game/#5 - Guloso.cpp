#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef vector<pii> vpii;

bool sorting(pii a, pii b)
{

  return (a.second < b.second);
}

int counting(vpii &A)
{
  int qtd = 0, final;

  final = A[0].second;

  for (auto x : A)
  {
    if (x.first >= final)
    {
      final = x.second;
      qtd++;
    }
  }

  return qtd;
}

int main()
{
  int n, v1, v2;
  cin >> n;

  vpii A;

  for (int i = 0; i < n; i++)
  {
    cin >> v1 >> v2;
    A.push_back(make_pair(v1, v2));
  }

  sort(A.begin(), A.end(), sorting);

  cout << counting(A) + 1;

  return 0;
}