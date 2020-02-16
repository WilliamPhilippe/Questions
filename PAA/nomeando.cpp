#include <bits/stdc++.h>
using namespace std;

int gera[100][100], geratot[100];
int matriz1[100], matriz2[100], n1[100];

int dfs(int x);

int main()
{
  int test;
  scanf("%d", &test);
  int n, K[30], i, j, k, cases = 0;
  char name[30][30][100];

  while (test--)
  {
    scanf("%d", &n);
    memset(geratot, 0, sizeof(geratot));
    memset(matriz1, 0, sizeof(matriz1));
    memset(matriz2, 0, sizeof(matriz2));

    for (i = 1; i <= n; i++)
    {
      scanf("%d", &K[i]);
      for (j = 0; j < K[i]; j++)
      {
        scanf("%s", &name[i][j]);
        int x = i, y = 30 + (name[i][j][0] >= 'a' ? name[i][j][0] - 'a' : name[i][j][0] - 'A');
        gera[y][geratot[y]++] = x;
      }
    }

    int ans = 0;
    for (i = 30; i < 30 + n; i++)
    {
      if (!matriz1[i])
      {
        memset(n1, 0, sizeof(n1));
        if (dfs(i))
          ans++;
      }
    }

    printf("Case #%d:\n", ++cases);
    for (i = 30; i < 30 + n; i++)
    {
      for (j = 0; j < K[matriz1[i]]; j++)
      {
        if (tolower(name[matriz1[i]][j][0]) == i - 30 + 'a')
        {
          printf("%c", toupper(name[matriz1[i]][j][0]));
          for (k = 1; name[matriz1[i]][j][k]; k++)
          {
            printf("%c", tolower(name[matriz1[i]][j][k]));
          }
          printf("\n");
          break;
        }
      }
    }
  }
  return 0;
}

int dfs(int x)
{
  int i, y;
  for (i = 0; i < geratot[x]; i++)
  {
    y = gera[x][i];
    if (!n1[y])
    {
      n1[y] = 1;
      if (matriz2[y] == 0 || dfs(matriz2[y]))
      {
        matriz1[x] = y, matriz2[y] = x;
        return 1;
      }
    }
  }
  return 0;
}