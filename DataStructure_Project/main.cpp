#include <iostream>
#include "Project.h"

using namespace std;
int main()
{
  doctors_list l1;

  int d_No;
  cout << "Enter the number of doctors: ";
  cin >> d_No;

  for (int i = 1; i <= d_No; i++)
  {
    string d_Name;
    cout << "Enter D.Name NO : " << i << endl;
    cin >> d_Name;
    l1.insertFirst(d_Name);
  }
  l1.display();
  return 0;
}