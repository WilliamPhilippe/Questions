#include <bits/stdc++.h>
using namespace std;
long int inv_count = 0;
void merge(int arr[], int l, int m, int r)
{
  int ctr1 = 0, ctr2 = 0, lefthalf[(m - l) + 1], righthalf[(r - (m + 1)) + 1], k;
  int size1 = (m - l) + 1;
  int size2 = (r - (m + 1)) + 1;

  for (ctr1 = 0; ctr1 < size1; ++ctr1)
    lefthalf[ctr1] = arr[l + ctr1];

  for (ctr2 = 0; ctr2 < size2; ++ctr2)
    righthalf[ctr2] = arr[m + 1 + ctr2];
  ctr1 = 0;
  ctr2 = 0;
  k = l;

  while (ctr1 < size1 && ctr2 < size2)
  {
    if (lefthalf[ctr1] <= righthalf[ctr2])
      arr[k++] = lefthalf[ctr1++];
    else
    {
      arr[k++] = righthalf[ctr2++];

      inv_count = inv_count + (size1 - ctr1);
    }
  }
  while (ctr1 < size1)
    arr[k++] = lefthalf[ctr1++];

  while (ctr2 < size2)
    arr[k++] = righthalf[ctr2++];
}
void merge_sort(int arr[], int l, int r)
{
  int m;
  if (l < r)
  {
    m = (l + r - 1) / 2;
    merge_sort(arr, l, m);
    merge_sort(arr, m + 1, r);
    merge(arr, l, m, r);
  }
}
int main()
{

  int testes;
  cin >> testes;

  while (testes--)
  {
    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
      cin >> arr[i];
    }

    int size = sizeof(arr) / sizeof(arr[0]);
    merge_sort(arr, 0, size - 1);
    cout << inv_count << endl;
    inv_count = 0;
  }

  return 0;
}