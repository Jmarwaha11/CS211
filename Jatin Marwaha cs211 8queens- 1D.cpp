/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
   int q[8],c=0;
   q[0]=0;
   nc:c++;
   if(c==8)
   goto print;
   q[c]=-1;
   nr: q[c]++;
   if(q[c]==8)
   goto backtrack;
   //combined tests - a short circuit evaluation 
   for(int i =0;i<c;i++)
   {
   if ((q[i]==q[c])or (abs(q[c]-q[i])==(c-i)))
   goto nr;
   }
   goto nc;
   backtrack:c--;
   if(c==-1)
   return 0 ;
   goto nr;
   static int numSolutions = 1;
   print: cout << "Solution #" << numSolutions++ << ":\n";
   for (int j = 0; j <= 7; j++) {
        for (int k = 0; k <= 7; k++) {
            if(q[j] == k)
                cout << "1";
            else {
                cout <<"0";
            }
        }
   cout<<endl;}
 
   goto backtrack;
   
    return 0;
}

