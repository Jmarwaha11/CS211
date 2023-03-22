#include<iostream>
using namespace std;

int reverseInt(int n)
{
int reversedNo = 0;
while(n!=0) 
{
int rem = n % 10;
reversedNo = reversedNo * 10 + rem;
n /= 10;
}
return reversedNo; 
}



int main()
{
int n;
while(1)
{
cout<<"Enter a positive integer\n";
cin>>n;
if(n<0) 
{
cout<<"You entered Negative integer\n";
break;
}
else 
cout<<reverseInt(n)<<endl;
}
return 0;
}
