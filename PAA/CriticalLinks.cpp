#include <bits/stdc++.h>
using namespace std;

#define MAX 150

int counter = 0;
int dfsnumber[MAX];
int dfslow[MAX];
int parent[MAX];
int n, a, b, c;

typedef pair<int, int> pii;

vector<vector<int>> network;
vector<pii> out;

bool compare(pii &a, pii &b);

void resolve(int u);
void clear();

int main()
{
  for (int i = 0; i < 1000; i++)
  {
    vector<int> temp;
    network.push_back(temp);
  }

  while (cin >> n)
  {
    clear();
    for (int i = 0; i < n; i++)
    {
      scanf("%d (%d)", &a, &b);
      for (int j = 0; j < b; j++)
      {
        scanf("%d", &c);
        network[a].push_back(c);
      }
    }

    for (int i = 0; i < n; i++)
    {
      if (dfsnumber[i] == -1)
      {
        resolve(i);
      }
    }

    cout << out.size() << " critical links" << endl;
    sort(out.begin(), out.end(), compare);
    for (int i = 0; i < out.size(); i++)
    {
      cout << out[i].first << " - " << out[i].second << endl;
    }
    cout << endl;
  }

  return 0;
}

void clear()
{
  counter = 0;
  out.clear();
  for (int i = 0; i < (n + 2); i++)
  {
    network[i].clear();
    dfsnumber[i] = -1;
    dfslow[i] = 0;
    parent[i] = 0;
  }
}

void resolve(int u)
{
  dfsnumber[u] = dfslow[u] = counter++;
  vector<int> x = network[u];
  for (int i = 0; i < (int)x.size(); i++)
  {
    if (dfsnumber[x[i]] == -1)
    {
      parent[x[i]] = u;
      resolve(x[i]);
      if (dfslow[x[i]] > dfsnumber[u])
      {
        out.push_back(make_pair(min(u, x[i]), max(u, x[i])));
      }
      dfslow[u] = min(dfslow[u], dfslow[x[i]]);
    }
    else if (x[i] != parent[u])
    {
      dfslow[u] = min(dfslow[u], dfsnumber[x[i]]);
    }
  }
}

bool compare(pii &a, pii &b)
{
  if (b.first > a.first)
  {
    return true;
  }
  if (a.first == b.first && a.second < b.second)
  {
    return true;
  }
  return false;
}
