#include <bits/stdc++.h>

using namespace std;

vector<int> my_vector[1001];
int sized[1001];
pair<bool, bool> visited[1001];
bool flag = false;

int main()
{
  int testes, n, m;
  int T1, T2, T3;

  cin >> testes;

  while (testes--)
  {
    for (int i = 0; i < 1001; i++)
    {
      my_vector[i].clear();
      sized[i] = 0;
      flag = false;
      visited[i] = make_pair(false, false);
    }

    cin >> n >> m;
  }

  return 0;
}