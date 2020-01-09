#include <iostream>
#include <iomanip>
using std::cout;

int rightM = 3, ic = 3, i, fm = 0, fc = 0, status = 0, flag = 0, select = 0;

void display(char bpass1, char bpass2);
int notFinished();
void working();



int main()
{
  display(' ', ' ');
  working();
  display(' ', ' ');
  return 0;
}

void display(char bpass1, char bpass2)
{
  cout << "\n\n\n";
  for (int i = 0; i < fm; i++)
    cout << "M";
  for (int i = 0; i < fc; i++)
    cout << "C";

  if (flag == 0)
    cout << "   |  no barco: " << bpass1 << "," << bpass2 << "  |   ";
  else
    cout << "   |  no barco: " << bpass1 << "," << bpass2 << "  |   ";
  for (int i = 0; i < rightM; i++)
    cout << "M";
  for (int i = 0; i < ic; i++)
    cout << "C";
}

int notFinished()
{
  return !(fc == 3 && fm == 3);
}

void working()
{
  while (notFinished())
  {
    if (!flag)
    {
      switch (select)
      {
      case 1:
        display('C', ' ');
        ic++;
        break;
      case 2:
        display('C', 'M');
        ic++;
        rightM++;
        break;
      }

      if (((rightM - 2) >= ic && (fm + 2) >= fc) || (rightM - 2) == 0)
      {
        rightM = rightM - 2;
        select = 1;
        display('M', 'M');
        flag = 1;
      }
      else if ((ic - 2) < rightM && (fm == 0 || (fc + 2) <= fm) || rightM == 0)
      {
        ic = ic - 2;
        select = 2;
        display('C', 'C');
        flag = 1;
      }

      else if ((ic--) <= (rightM--) && (fm++) >= (fc++))
      {
        ic = ic - 1;
        rightM = rightM - 1;
        select = 3;
        display('M', 'C');
        flag = 1;
      }
    }

    else
    {
      switch (select)
      {
      case 1:
        display('M', 'M');
        fm = fm + 2;
        break;

      case 2:
        display('C', 'C');
        fc = fc + 2;
        break;

      case 3:
        display('M', 'C');
        fc = fc + 1;
        fm = fm + 1;
        break;
      }

      if (notFinished())
      {
        if (((fc > 1 && fm == 0) || rightM == 0))
        {
          fc--;
          select = 1;
          display('C', ' ');
          flag = 0;
        }

        else if ((ic + 2) > rightM)
        {
          fc--;
          fm--;
          select = 2;
          display('C', 'M');
          flag = 0;
        }
      }
    }
  }
}