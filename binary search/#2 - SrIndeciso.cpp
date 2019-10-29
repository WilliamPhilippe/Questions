#include <bits/stdc++.h>

using namespace std;

void binarySearch(vector<int> &dinheiros, int x, int &lo, int &hi, int init, int end)
{
  cout << "  -   " << init << "  " << end << endl;
  if (init > end)
  {
    cout << "'first if'";
    cout << endl;
    return;
  }

  if (init == end)
  {
    if (dinheiros[end] == x)
    {
      cout << "'second.1 if'";
      cout << endl;

      return;
    }
    else
    {
      cout << "'second.2 if'";
      cout << endl;

      return;
    }
  }

  int mid = (init + end) / 2;

  if (dinheiros[mid] == x)
  {
    cout << "'thith if'";
    cout << endl;

    cout << mid;
    return;
  }

  if (dinheiros[mid] < x)
  {
    binarySearch(dinheiros, x, lo, hi, mid + 1, end);
  }
  else
  {
    binarySearch(dinheiros, x, lo, hi, init, mid);
  }
}

int main()
{

  int var;
  int nDeDinheiros, qtdRequests, request;

  cin >> nDeDinheiros;
  vector<int> dinheiros;
  for (int i = 0; i < nDeDinheiros; i++)
  {
    cin >> var;
    dinheiros.push_back(var);
  }

  cin >> qtdRequests;

  // while (qtdRequests--)
  {
    int x;
    cin >> x;
    cin >> x;
    cin >> x;
    cin >> x;
    int lo, hi;

    binarySearch(dinheiros, x, lo, hi, 0, dinheiros.size() - 1);
  }

  return 0;
}
