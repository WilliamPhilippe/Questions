#include <bits/stdc++.h>

using namespace std;

void print(int array[])
{
  for (int i = 0; i < 10; i++)
  {
    cout << array[i] << " ";
  }
  cout << endl;
}

int main()
{

  int array[] = {4, 3, 1, 5, 6, 7, 2, 3, 5, 6};

  for (int i = 0; i < 10; i++)
  {
    for (int j = 0; j < 10; j++)
    {
      if (array[j] > array[i])
      {
        int x = array[j];
        array[j] = array[i];
        array[i] = x;
      }
    }

    print(array);
  }

  return 0;
}