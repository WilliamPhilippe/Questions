#include <bits/stdc++.h>
using namespace std;

int n;
int dinheiros[1001];
int segTree[5 * 1001];

void build(int idx = 1, int start = 1, int end = n)
{
  if (start == end)
    segTree[idx] = dinheiros[start];
  else
  {
    int mid = (start + end) / 2;
    build(2 * idx, start, mid);
    build((2 * idx) + 1, mid + 1, end);
    segTree[idx] = segTree[idx * 2] + segTree[(2 * idx) + 1];
  }
}

int main()
{
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> dinheiros[i];
  build();

  for (int i = 0; i <= 50; i++)
  {
    cout << segTree[i] << " ";
  }
  return 0;
}