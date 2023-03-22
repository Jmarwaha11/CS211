#include <iostream>
#include <cmath>
using namespace std;


    int main( ) {
	
      int c = 0;
	  int q[8] = {0};
	  int a[8][5] = {
    	{-1},
    	{0,-1},
    	{0,1,-1},
    	{0,1,2,-1},
    	{1,2,3,-1},
    	{0,3,4,-1},
    	{3,4,5,-1},
    	{2,4,6,-1}
   		};
	
		
	nr: q[c]++;
	
	    if (q[c] == 9)
	    {
		goto backtrack;
		} 
		if (c == 8)
		{
			goto print;
		}
	for (int i = 0; i < c; i++)
	{
		if (q[i] == q[c])
		{
			goto nr;
		}
	}
	for(int i = 0; i <= 8; i ++)
	{
		while (a[c][i] != -1){
			if (abs((q[c] - q[a[c][i]])) == 1)
			{
				goto nr;
			}
			else
			{	i++;}
			
		}
		
		c++;
		goto nr;
	}

	backtrack:q[c] = 0;
    c--;
	goto nr;
	print: static int solution = 0;
   cout << "Solution #" << ++solution << "\n";
   cout << " "  << q[1] << q[4] << "\n";
   cout << q[0] << q[2] << q[5] << q[7] << "\n";
   cout << " "  << q[3] << q[6] << "\n\n";
   goto backtrack;
   return 0;
	}