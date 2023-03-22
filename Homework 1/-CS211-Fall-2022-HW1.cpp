#include <iostream>
using namespace std;

bool
print_primes (int numforprime)
{
  bool primebool = true;
  int internalvariableforprime;
  if (numforprime >= 1)
    {
      for (internalvariableforprime = 2;
	   internalvariableforprime <= numforprime / 2;
	   ++internalvariableforprime)
	{
	  if (numforprime % internalvariableforprime == 0)
	    {
	      primebool = false;
	      break;
	    }
	}
    }
  else
    {
      primebool = false;
    }
  return primebool;
}

int
print_perfect_nums (int numforperfect)
{
  int counterforperfect, sumforperfect = 0;
  for (counterforperfect = 1; counterforperfect < numforperfect;
       counterforperfect++)
    {
      if (numforperfect % counterforperfect == 0)
	sumforperfect = sumforperfect + counterforperfect;
    }
  if (numforperfect == sumforperfect)
    return 1;
  else
    return 0;
}

bool
print_leap_years (int leapyearcounter)
{
  if (leapyearcounter % 4 == 0)
    {
      if (leapyearcounter % 100 == 0)
	{
	  if (leapyearcounter % 400 == 0)
	    return true;
	  else
	    return false;
	}
      else
	return true;
    }
  else
    return false;

}

int
print_reverse (int numforreverse)
{
  int numberafterreverse = 0;
  while (numforreverse != 0)
    {
      int numleftover = numforreverse % 10;
      numberafterreverse = numberafterreverse * 10 + numleftover;
      numforreverse /= 10;
    }
  return numberafterreverse;
}

int
main ()
{
  int numforprime, numforperfect, startyearforleap, endyearforleap,
    linecounterforleap = 1, numforreverse;
  cout << "enter a number to see all the prime numbers from 1 to that number";
  cin >> numforprime;
  cout << "below are the prime numbers from 1 to the number you entered" <<
    endl;
  for (int counterforprime = 1; counterforprime <= numforprime;
       counterforprime++)
    {
      if (print_primes (counterforprime))
	{
	  cout << counterforprime << " ";
	}
    }
  cout << endl;
  cout <<
    " now enter a number to see all the perfect numbers for 1 to that number ";
  cin >> numforperfect;
  for (int mainprogramcounterforperfect = 1;
       mainprogramcounterforperfect <= numforperfect;
       mainprogramcounterforperfect++)
    {
      if (print_perfect_nums (mainprogramcounterforperfect))
	{
	  cout << mainprogramcounterforperfect << " ";
	}
    }
  cout << endl;
  cout <<
    " now enter a start and end year to see the leap years between them ";
  cin >> startyearforleap >> endyearforleap;
  cout << "the leap years between" << startyearforleap << " " <<
    endyearforleap << "are" << endl;
  for (int counterforleapyear = startyearforleap;
       counterforleapyear <= endyearforleap; counterforleapyear++)
    {
      linecounterforleap = linecounterforleap + 1;
      if (linecounterforleap % 20 == 0)
	cout << endl;
      if (print_leap_years (counterforleapyear) && counterforleapyear != 800)
	cout << counterforleapyear << " ";
    }
  cout << endl;

  while (1)
    {
      cout << "please enter a positive integer you would like to be reversed" << endl;
      cin >> numforreverse;

      if (numforreverse < 0)
	{
	  cout << "you have entered a negative interger" << endl;
	  break;
	}
      else
	cout << print_reverse (numforreverse) << endl;
    }
  return 0;
}
