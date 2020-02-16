#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;

vector<int> dist;
int vertex, edges;

const int maxN = 1e3, inf = 1e8;

int n, m;
vvpii graph;
vector<int> prv;

bool graphDetect();

int main()
{
  int testes;
  cin >> testes;
  for (int i = 0; i < testes; i++)
  {
    cin >> vertex >> edges;
    graph.resize(vertex);
    dist.resize(vertex, INT_MAX);
    prv.resize(vertex);
    for (int j = 0; j < edges; j++)
    {
      int v1, v2, w;
      cin >> v1 >> v2 >> w;
      graph[v1].push_back(make_pair(v2, w));
    }

    graphDetect() ? cout << "possible\n" : cout << "not possible\n";

    graph.clear();
    prv.clear();
    dist.clear();
  }
  return (0);
}

bool graphDetect()
{
  dist[0] = 0;
  for (int i = 0; i < vertex - 1; i++)
  {
    for (int u = 0; u < vertex; u++)
    {
      for (auto &v : graph[u])
      {
        if (dist[u] + v.second < dist[v.first] and dist[u] != INT_MAX)
        {
          dist[v.first] = dist[u] + v.second, prv[v.first] = u;
        }
      }
    }
  }

  for (int u = 0; u < vertex; u++)
    for (auto &v : graph[u])
      if (dist[u] + v.second < dist[v.first] and dist[u] != INT_MAX)
        return (true);
  return (false);
}