
#include <iostream>
#include <cmath>
using namespace std;


bool ok(int q[], int c) {
   for (int i = 0; i < c; ++i)
      if (q[i] == q[c] or abs(q[i] - q[c]) == c - i)
         return false;
   return true;
}

void print(int q[]){//when called the array called will be printed out
   static int numSolutions = 1;
cout << "Solution #" << numSolutions++ << ":\n";
   for (int j = 0; j <= 7; j++) {
cout<<q[j] ;}
cout<<endl;
   for (int j = 0; j <= 7; j++) {
        for (int k = 0; k <= 7; k++) {
            if(q[j] == k)
                cout << "x";
            else {
                cout <<".";
            }
        }
cout <<endl;
       
   }
};

int main(){

    
int q[8],c=0;
   q[0]=0;
   while (c >= 0) { // End the loop if you backtrack from the first column
      if (c == 7) { // If you are in the last column, print and backtrack
         print(q);
         c--;
      }
      else                  // Otherwise, move to one before the first row of the next column
         q[++c] = -1;
        while (c >= 0) {
            ++q[c];            // Move to the next row
         if (q[c] == 8)     // If you have passed the end of the column, backtrack
            c--;
         else if (ok(q, c)) // Otherwise, if the queen is ok, break (go back to the beginning of the outer loop)
            break;
      }
   }
   return 0;
}
