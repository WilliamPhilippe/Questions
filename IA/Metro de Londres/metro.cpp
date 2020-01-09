#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef map<int, pii> mipii;

#define mp make_pair

int n, u, v, d;
int distances[100][100];
mipii crossing;

void lerTabelaDeDistancias()
{
  //esta função lê a tabela de distâncias
  //que separei em um arquivo .txt.

  while (cin >> u >> v >> d)
  {
    distances[u][v] = d;
    distances[v][u] = d;
  }
}

void associoarCruzamentos()
{
  /**
   * Esta função armazena os cruzamentos de linhas.
  */

  /** 
   * Se em uma estação E passam duas linhas L1, L2
   * então existe o map <E, (L1, L2)>
  */

  /**
   * LINHA AZUL - 1
   * LINHA AMARELA - 2
   * LINHA VERMELHA - 3
   * LINHA VERDE - 4
  */
  crossing[2] = mp(1, 2);
  crossing[3] = mp(1, 3);
  crossing[4] = mp(1, 4);
  crossing[5] = mp(1, 2);
  crossing[9] = mp(2, 3);
  crossing[13] = mp(3, 4);
  crossing[8] = mp(2, 4);
}

int main()
{
  cin >> n;

  lerTabelaDeDistancias();
  associoarCruzamentos();

  return 0;
}