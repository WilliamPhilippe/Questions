#include <bits/stdc++.h>

using namespace std;

int n, m;
int x, y;

void remove(int i, queue<int> &list)
{
  int init = list.front();

  if (init == i)
  {
    list.pop();
    return;
  }

  while (true)
  {
    int nu = list.front();
    list.pop();
    if (nu != i)
    {
      list.push(nu);
    }

    if (list.front() == init)
      return;
  }
}

void getZero(queue<int> *graph, queue<int> *invert, queue<int> &result, int *removed)
{
  priority_queue<int, vector<int>, greater<int>> pq;

  while (true)
  {

    for (int i = 1; i <= n; i++)
    {
      if (graph[i].empty() && !removed[i])
      {

        removed[i] = 1;
        pq.push(i);

        while (!invert[i].empty())
        {
          int node = invert[i].front();
          invert[i].pop();

          remove(i, graph[node]);
        }

        break;
      }
    }

    if (pq.empty())
      return;

    while (!pq.empty())
    {
      result.push(pq.top());
      // while (!invert[pq.top()].empty())
      // {
      //   int node = invert[pq.top()].front();
      //   invert[pq.top()].pop();

      //   remove(pq.top(), graph[node]);
      // }
      pq.pop();
    }
  }
}

int main()
{

  cin >> n >> m;

  // priority_queue<int, vector<int>, greater<int>> graph[n + 1];
  queue<int> graph[n + 1];
  queue<int> invert[n + 1];
  queue<int> result;
  int removed[n + 1] = {0};

  for (int i = 0; i < m; i++)
  {
    cin >> x >> y;
    graph[x].push(y);
    invert[y].push(x);
  }

  getZero(graph, invert, result, removed);

  if (result.size() != n)
  {
    cout << "Impossible";
    return 0;
  }

  while (!result.empty())
  {
    cout << result.front() << " ";
    result.pop();
  }

  return 0;
}