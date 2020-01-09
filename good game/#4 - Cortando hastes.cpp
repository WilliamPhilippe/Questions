#include <bits/stdc++.h>
using namespace std;

int values[1001];
int progMemo[1001] = {-1};

int dp(int n)
{
  int best;
  progMemo[0] = 0;

  for (int j = 1; j <= n; ++j)
  {
    best = INT_MIN;
    for (int i = 0; i < j; ++i)
    {
      best = max(best, values[i] + progMemo[j - i - 1]);
    }
    progMemo[j] = best;
  }
  return progMemo[n];
}

int main()
{
  int n;
  cin >> n;
  while (n)
  {
    for (int i = 0; i < n; ++i)
    {
      cin >> values[i];
    }
    cout << dp(n) << endl;
    memset(progMemo, -1, sizeof progMemo);
    cin >> n;
  }
  return 0;
}