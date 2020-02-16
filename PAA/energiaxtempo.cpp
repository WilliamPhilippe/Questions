#include <bits/stdc++.h>
using namespace std;

int pd[5000][20];
int anexo[5000][20];

int dp(int i, int j, int k, int f, int acu);

int main()
{
  int f, p, e, a;

  cin >> f >> p >> e >> a;

  while (f && p && e && a)
  {
    int acumulado = e * a;
    int n1, n2;

    for (int i = 0; i < p; i++)
      for (int j = 0; j < f; j++)
      {
        cin >> n1 >> n2;
        anexo[i][j] = n1 * n2;
      }

    memset(pd, -1, sizeof(pd));

    cout << dp(0, p, 0, f, acumulado) << endl;
    cin >> f >> p >> e >> a;
  }

  return 0;
}

int dp(int i, int j, int k, int f, int acu)
{
  if (i == j)
  {
    return 0;
  }

  if (pd[i][k] == -1)
  {
    int res = dp(i + 1, j, k, f, acu) + anexo[i][k];

    for (int w = 0; w < f; w++)
    {
      if (w != k)
        res = min(res, dp(i + 1, j, w, f, acu) + anexo[i][w] + acu);
    }

    pd[i][k] = res;
  }

  return pd[i][k];
}