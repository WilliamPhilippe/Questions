#include <bits/stdc++.h>
using namespace std;

int d, p, r, b;
int var1, var2;
int dMember[101] = {-1}, pMember[101] = {-1};
int dVisited[101] = {0}, pVisited[101] = {0};
bool rivals[101][101];

int dpMatrix[201][10000];

class Triple
{
public:
  int dCount, pCount, cost;

public:
  void add(int a, int b, int c)
  {
    dCount += a;
    pCount += b;
    cost += c;
  }

public:
  Triple(int a, int b, int c)
  {
    dCount = a;
    pCount = b;
    cost = c;
  }
};

void detectConecction(int node, bool isD, Triple &tp)
{
  if (isD)
  {
    if (dVisited[node])
      return;
    dVisited[node] = 1;

    tp.add(1, 0, dMember[node]);

    for (int i = 1; i <= p; i++)
    {
      if (rivals[node][i])
      {
        detectConecction(i, false, tp);
      }
    }
  }
  else
  {
    if (pVisited[node])
      return;
    pVisited[node] = 1;

    tp.add(0, 1, pMember[node]);

    for (int i = 1; i <= d; i++)
    {
      if (rivals[i][node])
      {
        detectConecction(i, true, tp);
      }
    }
  }
}

vector<Triple> tpVector;

int dp(int idx, int money, bool isD)
{

  if (dpMatrix[idx][money] != -1)
    return dpMatrix[idx][money];

  if (tpVector.size() == idx)
  {
    dpMatrix[idx][money] = 0;
    return 0;
  }

  if (money < 1)
  {

    if (money == 0)
      dpMatrix[idx][money] = (isD ? tpVector[idx].dCount : tpVector[idx].pCount);
    return (isD ? tpVector[idx].dCount : tpVector[idx].pCount);
  }

  if (tpVector[idx].cost > money)
  {
    dpMatrix[idx][money] = (isD ? tpVector[idx].dCount : tpVector[idx].pCount) + dp(idx + 1, money, isD);

    return (isD ? tpVector[idx].dCount : tpVector[idx].pCount) + dp(idx + 1, money, isD);
  }

  dpMatrix[idx][money] = max(
      (isD ? tpVector[idx].pCount : tpVector[idx].dCount) + dp(idx + 1, money - tpVector[idx].cost, isD),
      (!isD ? tpVector[idx].pCount : tpVector[idx].dCount) + dp(idx + 1, money, isD));

  return max(
      (isD ? tpVector[idx].pCount : tpVector[idx].dCount) + dp(idx + 1, money - tpVector[idx].cost, isD),
      (!isD ? tpVector[idx].pCount : tpVector[idx].dCount) + dp(idx + 1, money, isD));
}

int main()
{

  cin >> d >> p >> r >> b;

    for (int i = 0; i < 101; i++)
    memset(rivals[i], false, sizeof rivals[i]);

  for (int i = 1; i <= d; i++)
    cin >> dMember[i];
  for (int i = 1; i <= p; i++)
    cin >> pMember[i];

  for (int i = 0; i < r; i++)
  {
    cin >> var1 >> var2;
    rivals[var1][var2] = true;
  }

  int connection = 0;

  for (int i = 1; i <= d; i++)
  {
    Triple tp(0, 0, 0);
    if (dVisited[i])
      continue;
    connection++;
    detectConecction(i, true, tp);

    tpVector.push_back(tp);
  }

  for (int i = 1; i <= p; i++)
  {
    Triple tp(0, 0, 0);
    if (pVisited[i])
      continue;

    connection++;
    detectConecction(i, false, tp);
    tpVector.push_back(tp);
  }

  for (int i = 0; i < connection + 3; i++)
  {
    memset(dpMatrix[i], -1, sizeof dpMatrix[i]);
  }
  cout << dp(0, b, true) << " ";
  for (int i = 0; i < connection + 3; i++)
  {
    memset(dpMatrix[i], -1, sizeof dpMatrix[i]);
  }
  cout << dp(0, b, false) << endl;

  return 0;
}