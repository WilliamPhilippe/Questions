#include <bits/stdc++.h>
using namespace std;

long long int n, k, d;

long long int solved[101];
long long int unSolved[101];

long long int dp(long long int sobra, bool jaRes)
{

  if (sobra < 0)
    return 0;

  if (jaRes)
  {
    if (solved[sobra] == -1)
    {
      long long int temp = 0;
      for (int i = 1; i <= k; i++)
      {
        temp += dp(sobra - i, jaRes);
      }

      solved[sobra] = temp;
      return solved[sobra];
    }
    else
    {
      return solved[sobra];
    }
  }
  else
  {
    if (unSolved[sobra] == -1)
    {
      long long int temp = 0;
      for (int i = 1; i <= k; i++)
      {
        temp += dp(sobra - i, i >= d);
      }

      unSolved[sobra] = temp;
      return unSolved[sobra];
    }
    else
    {
      return unSolved[sobra];
    }
  }
}

int main()
{
  cin >> n >> k >> d;

  memset(solved, -1, sizeof solved);
  memset(unSolved, -1, sizeof unSolved);

  for (int i = 0; i < d; i++)
  {
    unSolved[i] = 0;
  }
  solved[0] = 1;
  unSolved[d] = 1;

  // for (int i = 0; i < 101; i++)
  //   cout << solved[i] << endl;

  dp(n, false);

  cout << unSolved[n] % 1000000007;

  return 0;
}