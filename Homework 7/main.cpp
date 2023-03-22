#include<iostream>
#include "Safearray.h"
#include "Safematrix.h"
#define SIZE 200

using namespace std;


int main()

{

SafeMatrix<int> smi(5,3);

smi[0][1]=15;

cout<<"sm.length() -> "<<smi.length()<<endl;
cout<<"sm[0].length() --> "<<smi[0].length()<<endl;

cout<<"Value of sm[0][1] -> "<<smi[0][1]<<endl;
SafeMatrix<const char*> smc(10,12);

smc[2][3]="a";

cout<<"sm.length() -> "<<smc.length()<<endl;
cout<<"sm[0].length() --> "<<smc[1].length()<<endl;

cout<<"Value of sm[0][1] -> "<<smc[2][3]<<endl;
SafeMatrix<string> sms(31,42);
sms[7][7]="Overwatch 2 is a broken game and blizzard should be ashammed at themselves";

cout<<"sm.length() -> "<<sms.length()<<endl;
cout<<"sm[0].length() --> "<<sms[10].length()<<endl;

cout<<"Value of sm[0][1] -> "<<sms[7][7]<<endl;
SafeMatrix<double> smd(21,22);
smd[8][8]=3.14;

cout<<"sm.length() -> "<<smd.length()<<endl;
cout<<"sm[0].length() --> "<<smd[14].length()<<endl;

cout<<"Value of sm[0][1] -> "<<smd[8][8]<<endl;
SafeMatrix<bool> smb(60,60);
smb[9][9]=true;

cout<<"sm.length() -> "<<smb.length()<<endl;
cout<<"sm[0].length() --> "<<smb[50].length()<<endl;

cout<<"Value of sm[0][1] -> "<<smb[9][9]<<endl;

return 0;

};