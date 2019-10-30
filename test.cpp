#include <bits/stdc++.h>
using namespace std;

int main()
{
  vector<int> myVector;
  myVector.push_back(1);
  myVector.push_back(2);
  myVector.push_back(3);
  myVector[6] = 6;

  for (int i = 0; i < myVector.size(); i++)
  {
    cout << myVector[i];
  }

  cout << myVector.size();
}