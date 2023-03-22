#include "Roster.h"
#include <string>
#include <iostream>
using namespace std;
int
main ()
{
  Roster r1;
  Student t[12];
  int i, k;
  for (i = 0; i < 12; i++)
    {
      t[i].inputstudent ();
    }
  for (k = 0; k < 12; k++)
    {
      r1.addstudentname (t[k]);
    }

  r1.liststudents ();
  return 0;
}
