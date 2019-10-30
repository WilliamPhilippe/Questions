//segment tree

#include <bits/stdc++.h>
using namespace std;

void buildSegTree(vector<int> &segTree, int idx, int left, int right, vector<int> &dinheiros)
{

  if (right - left < 2)
  {
    segTree[idx] = dinheiros[left];
    return;
  }

  int mid = (left + right) / 2;
  buildSegTree(segTree, idx * 2, left, mid, dinheiros);
  buildSegTree(segTree, idx * 2 + 1, mid, right, dinheiros);
  segTree[idx] = segTree[idx * 2] + segTree[idx * 2 + 1];
}

int main()
{

  int nDeDinheiros, var, requests;
  char type, value1, value2;
  cin >> nDeDinheiros;

  vector<int> dinheiros;

  for (int i = 0; i < nDeDinheiros; i++)
  {
    cin >> var;
    dinheiros.push_back(var);
  }

  int maxSegTreeSize = nDeDinheiros * nDeDinheiros > 100000 ? 100001 : nDeDinheiros * nDeDinheiros;

  vector<int> segTree;
  segTree.resize(maxSegTreeSize);
  segTree[0] = -1;

  buildSegTree(segTree, 1, 1, dinheiros.size(), dinheiros);

  for (int i = 0; i <= nDeDinheiros; i++)
  {
    cout << segTree[i] << " ";
  }

  cin >> requests;
  getchar();

  while (requests--)
  {
    scanf("%c %d %d\n", &type, &value1, &value2);
  }

  return 0;
}