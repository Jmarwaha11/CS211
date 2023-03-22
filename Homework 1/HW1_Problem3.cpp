#include <iostream>
using namespace std;
bool leap(int y){
if(y%4==0){
if(y%100==0){
if(y%400==0)
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
int main()
{
int s,e,range;
cout<<"Enter a range of years from lowest to highest ";
cin>>s>>e;
range=e-s;
int ray[5][5] ;
cout<<"Leap years are:"<<endl;
for(int i=s;i<=e;i++){

if(leap(i)&&i!=800)

cout<<i<<" ";}
return 0;
}

