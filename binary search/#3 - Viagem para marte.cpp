#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef vector<ld> vld;
typedef vector<int> vi;

int main()
{

  int planetas, foguete, var;
  cin >> planetas;
  cin >> foguete;

  vi D, P;

  for (int i = 0; i < planetas; i++)
  {
    cin >> var;
    if (var <= 1)
    {
      cout << -1;
      return 0;
    }
    D.push_back(var);
  }

  for (int i = 0; i < planetas; i++)
  {
    cin >> var;
    if (var <= 1)
    {
      cout << -1;
      return 0;
    }
    P.push_back(var);
  }

  long double coust = ((long double)foguete) / (P[0] - 1);

  for (int i = planetas - 1; i >= 0; i--)
  {
    coust += ((long double)foguete + coust) / (D[i] - 1);

    if (i == 0)
      break;
    coust += ((long double)foguete + coust) / (P[i] - 1);
  }

  printf("%.2Lf", coust);

  return 0;
}