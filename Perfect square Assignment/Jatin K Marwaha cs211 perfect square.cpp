/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
using namespace std;

int main()
{
 int k=1;
 int check = k*k; 
 for (int j=0; j<=65537;j++){

        if((check%2==1)&&((check/10)%2==1)) 
        // checks if it is a perfect square with the last two digits being 7 or 3 
        {
            j=k;
        // if it is it assigns the value of b to a and shuts down the loop 
        }
         else if (j==65537)
        { cout<<" there is no perfect square"<<endl;
        // i know this is a trick quesiton 65537 is just the last int you can check with the short int format
        }
            else  
            {
            k++;
        // if it is not the perfect square im looking for it increments 
            }
       
 }

    return 0;
}



