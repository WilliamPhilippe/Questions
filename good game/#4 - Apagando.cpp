#include <bits/stdc++.h>
using namespace std;

int main()
{

  int n, d;

  while (cin >> n >> d)
  {

    if (!n && !d)
    {
      break;
    }

    char number[n + 2], num;
    int init, apagados, i;

    apagados = 0;

    for (i = 0, init = -1; i < n; i++)
    {

      scanf(" %c", &num);

      while (init > -1 && apagados < d && num > number[init])
      {

        init--;

        apagados++;
      }

      if (init + 1 < n - d)
        number[++init] = num;
    }

    number[++init] = '\0';

    cout << number << endl;
  }

  return 0;
}