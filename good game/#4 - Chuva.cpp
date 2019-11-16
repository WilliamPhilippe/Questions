#include <bits/stdc++.h>
using namespace std;

typedef int ll;
typedef vector<ll> vll;

int main()
{

  int n;
  cin >> n;

  bool flagFinal = true, equal = true, alwaysMin = true, alwaysMax = true;
  int qtdFinalandInitial = 0;

  vll V;

  for (int x, i = 0; i < n; i++)
  {
    cin >> x;
    V.push_back(x);

    if (i)
    {

      if (x != V[0])
        equal = false;

      if (x > V[0] && i < n - 1)
      {
        flagFinal = false;
      }
      if (i == n - 1 && x < V[0])
        flagFinal = false;
      if (x < V[0])
        qtdFinalandInitial++;

      if (x > V[i - 1])
        alwaysMin = false;
      if (x < V[i - 1])
        alwaysMax = false;
    }
  }

  // if (equal || alwaysMax || alwaysMin)
  // {
  //   cout << 0;
  //   return 0;
  // }
  // // // if (flagFinal)
  // // // {
  // // //   cout << n - 2;
  // // //   return 0;
  // // // }
  // if (V[0] == V[n - 1])
  // {
  //   cout << qtdFinalandInitial;
  //   return 0;
  // }

  if (V[0] <= V[n - 1])
  {
    int left = 0, right = n - 1, qtd = 0;

    while (true)
    {

      int tempLeft = left, tempRight = right;
      int qtdEqualtoTheBorder = 0;

      while (true)
      {
        tempLeft++;
        if (tempLeft == right)
        {
          qtd = qtd - qtdEqualtoTheBorder;
          left = tempLeft;
          break;
        }

        if (V[tempLeft] == V[right])
        {
          qtdEqualtoTheBorder++;
        }

        if (V[tempLeft] < V[left])
          qtd++;

        cout << tempLeft << "-" << qtd << endl;

        if (V[tempLeft] >= V[left])
        {

          qtdEqualtoTheBorder = 0;
          left = tempLeft;

        inicio1:
          if (V[tempLeft + 1] >= V[tempLeft])
          {
            tempLeft++;
          }
          if (tempLeft == right)
          {
            left = tempLeft;
            goto fim1;
          }
          goto inicio1;
        fim1:
          break;
        }
      }

      cout << "---" << endl;

      if (left == right)
        break;

      while (true)
      {
        tempRight--;
        if (tempRight == left)
        {
          qtd = qtd - qtdEqualtoTheBorder;
          right = tempRight;
          break;
        }

        if (V[tempRight] == V[left])
        {
          qtdEqualtoTheBorder++;
        }

        if (V[tempRight] < V[right])
          qtd++;

        cout << tempRight << "-" << qtd << endl;

        if (V[tempRight] >= V[right])
        {
          qtdEqualtoTheBorder = 0;
          right = tempRight;

        inicio2:
          if (V[tempRight - 1] >= V[tempRight])
          {
            tempRight--;
          }
          if (tempRight == left)
          {
            right = tempRight;
            goto fim2;
          }
          goto inicio2;
        fim2:
          break;
        }
      }

      cout << "---" << endl;

      if (left == right)
        break;
    }
    cout << qtd;
    return 0;
  }
  else
  {
    int left = 0, right = n - 1, qtd = 0;

    while (true)
    {

      int tempLeft = left, tempRight = right;
      int qtdEqualtoTheBorder = 0;

      while (true)
      {
        tempRight--;
        if (tempRight == left)
        {
          qtd = qtd - qtdEqualtoTheBorder;
          right = tempRight;
          break;
        }

        if (V[tempRight] == V[left])
        {
          qtdEqualtoTheBorder++;
        }

        if (V[tempRight] < V[right])
          qtd++;

        cout << tempRight << "-" << qtd << endl;

        if (V[tempRight] >= V[right])
        {
          qtdEqualtoTheBorder = 0;
          right = tempRight;

        inicio4:
          if (V[tempRight - 1] >= V[tempRight])
          {
            tempRight--;
          }
          if (tempRight == left)
          {
            right = tempRight;
            goto fim4;
          }
          goto inicio4;
        fim4:
          break;
        }
      }

      // cout << "----" << endl;

      if (left == right)
        break;

      while (true)
      {
        tempLeft++;
        if (tempLeft == right)
        {
          qtd = qtd - qtdEqualtoTheBorder;
          left = tempLeft;
          break;
        }

        if (V[tempLeft] == V[right])
        {
          qtdEqualtoTheBorder++;
        }

        if (V[tempLeft] < V[left])
          qtd++;

        cout << tempLeft << "-" << qtd << endl;

        if (V[tempLeft] >= V[left])
        {

          qtdEqualtoTheBorder = 0;
          left = tempLeft;

        inicio3:
          if (V[tempLeft + 1] >= V[tempLeft])
          {
            tempLeft++;
          }
          if (tempLeft == right)
          {
            left = tempLeft;
            goto fim3;
          }
          goto inicio3;
        fim3:
          break;
        }
      }

      // cout << "----" << endl;

      if (left == right)
        break;
    }

    cout << qtd;
    return 0;
  }

  return 0;
}