#include <iostream>
using namespace std;

int main() {
   int b[8][8] = {0}, r, c = 0;
   b[0][0]=1;
nc:c++;
   if (c == 8)
      goto print;
   r = -1;
   
nr: r++;
   if (r == 8)
      goto backtrack;
   
//row test
   for (int i = 0; i < c; i++)                    
      if (b[r][i] == 1)
         goto nr;
// up diagonal        
   for (int i = 1; r - i >= 0 and c - i >= 0; i++)
      if (b[r-i][c-i] == 1)
         goto nr;
// down diagonal 
   for (int i = 1; r + i < 8 && c - i >= 0; i++)  
      if (b[r+i][c-i] == 1)
         goto nr;
   b[r][c] = 1;
   goto nc;
 
//backtrack 
backtrack: c--;
if (c==-1)
{return 0;}
   r=0;
   while (b[r][c]!=1)
  r++;
  b[r][c]=0;
  goto nr;

//print
print:
   static int numSolutions = 1;
   cout << "Solution #" << numSolutions++ << ":\n";
   for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++)
         cout << b[i][j];
      cout << "\n";
   }
   goto backtrack;
}


