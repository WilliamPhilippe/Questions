#include <bits/stdc++.h>

using namespace std;

struct duplo
{
  int lo, hi;
};

void findLoHi(vector<int> &dinheiros, int mid, int x, int &lo, int &hi)
{

  for (int i = mid; i >= 0; i--)
  {
    if (dinheiros[i] == x)
      lo = i;
  }

  for (int i = mid; i < dinheiros.size(); i++)
  {
    if (dinheiros[i] == x)
      hi = i;
  }
}

void binarySearch(vector<int> &dinheiros, int x, int &lo, int &hi, int init, int end)
{

  int mid = (init + end) / 2; //4 + 5 = 9 / 2 = 4

  if (dinheiros[mid] == x)
  {
    findLoHi(dinheiros, mid, x, lo, hi);
    return;
  }

  if (init >= end)
  {
    int finalArray = dinheiros.size() - 1;

    if (dinheiros[end] > x)
    {
      lo = end;
      hi = end - 1;
    }
    else
    {
      lo = end + 1;
      hi = end;
    }

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

  map<int, duplo> answers;

  while (qtdRequests--)
  {
    int x;
    cin >> x;
    int lo, hi;

    if (answers.size())
    {
      map<int, duplo>::iterator it;

      it = answers.find(x);
      if (it != answers.end())
      {
        cout << it->second.lo << " " << it->second.hi << endl;
      }
      else
      {
        binarySearch(dinheiros, x, lo, hi, 0, dinheiros.size() - 1);
        cout << lo << " " << hi << endl;
        answers[x] = {lo, hi};
      }
    }
    else
    {
      binarySearch(dinheiros, x, lo, hi, 0, dinheiros.size() - 1);
      cout << lo << " " << hi << endl;
      answers[x] = {lo, hi};
    }
  }

  return 0;
}
