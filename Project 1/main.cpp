#include <iostream>
#include <string>
#include <fstream>
#include "Student.h"
#include "Roster.h"
#include "Date.h"

int rostersearch (Roster * r, int rcapacity, string cd);

 
int main () 
{
  
int capacity = 10;
  
int numofrosters = 0;
  
 
Roster * r = new Roster[capacity];
  
 
std::ifstream rosters;
  

  
std::string in,sid,cc,cn,usernamepass;

  double gpa;
int cred,scred, numofstudents = 0;
int m, d, y, m2, d2, y2;
string ln, fn, standing;
  
Date bd, md;

string rcheck;
char filler ;
int rostersearchindex = 0;
 string ignore;
 
Student s1;

std::ifstream myfile;
  
while (!rosters.eof ())
    
    {
getline(rosters,cn,'|');
getline(rosters,cc,'|');      
rosters>>cred;
rosters>>filler;
getline(rosters,in,'|');
rosters >> numofstudents;
rosters>>filler;
if (numofrosters == capacity)
	
	{
	  
capacity *= 2;
	  
Roster * newList = new Roster[capacity];
	  
for (int i = 0; i < numofrosters; i++)
	    
	    {
	      
newList[i] = r[i];
	    
} 
 
delete[]r;
	  
r = new Roster[capacity];
	  
r = newList;
	
}
      
 
Roster r2 (cn, cc, in, cred);
      
r[numofrosters] = r2;
      
 
for (int i = 0; i < numofstudents; i++)
	
	{
getline(rosters,fn,'|');
getline(rosters,ln,'|');  
getline(rosters,sid,'|');
getline(rosters,standing,'|');
rosters >> scred;
rosters>>filler;
rosters >> gpa;
rosters>>filler;
rosters >> m;
rosters>>filler;
rosters >> d;
rosters>>filler;
rosters >> y;
rosters>>filler;
rosters >> m2;
rosters>>filler;
rosters >> d2;
rosters>>filler;
rosters >> y2;
rosters>>filler;
rosters>>ignore;
Date bd (m, d, y);
Date md (m2, d2, y2);
Student s1 (ln, fn,sid,scred,gpa, bd, md);
	  
r[numofrosters].addstudentname (s1);
	
} 

      
numofrosters++;
    
} 
 
rosters.close ();


myfile.open ("DataBase.txt");
if (myfile.fail ())
    {
cout << "File did not open" << endl;
}
cout <<"Welcome to the Roster Managament Program"<< std::endl;
cout << endl;
char answer;
cout << "Please choose (A)Superviser Mode, (B)User Mode or (C)Exit: ";
cin >> answer;
string check;
myfile >> check;
myfile.close ();
while (answer < 'A' || answer > 'C')
    
    {
cout << "TRY AGAIN: ";
cin >> answer;
    
}
do
    {
if (answer == 'A')
	
	{
cout << "Please enter the username and password for the superviser mode access(Format:username/password): ";
cin >> usernamepass;
if (usernamepass == check)
	    
{
cout << endl;
cout << "Access Granted. Entering Superviser Mode....." <<endl;
cout << endl;
	    
}
else
	    {
cout <<endl;
cout <<"wrong username and password for Superviser. Access denied."<< endl;
while (usernamepass != check)
		{
cout << "TRY AGAIN: ";
cin >> usernamepass;
        }
cout << "Entering Superviser mode...." << endl;
cout << endl;
}
if (usernamepass == check)
    {   
cout << " Superviser Mode Options:" <<endl;
cout <<"1)Create a new Roster "<< endl;
cout << "2)Drop a Roster " <<endl;
cout <<"3)Display Roster information " <<endl;
cout << "4)Disply all Rosters " <<endl;
cout << "5)Additional options" <<endl;
cout << endl;
int option;
cout <<"Enter a number of Superviser Mode option to operate: ";      
std::cin >> option;
while (option < 1 || option > 5)
		
        {
cout << "TRY AGAIN: ";
cin >> option;
        }	
if (option == 1)
		{
Roster r1;
cout << "Enter the Course Name: ";
cin>>cn;
r1.setcourse_name(cn);
cout << "Enter the Course Code: ";
cin>>cc;
r1.setcourse_code(cc);
cout << "Enter the Instructor's Name: ";
cin>> in;
r1.setinstructor_name(in);
cout << "Enter the Amount of Credits: ";
cin >> cred;
r1.setcredits(cred);
cout << "Enter the Amount of Students in class: ";
cin >> numofstudents;
r1.setroster_index(numofstudents);
cout << endl;
if (numofrosters == capacity)
		    {
capacity *= 2;
Roster * newList = new Roster[capacity];
for (int i = 0; i < numofrosters; i++)
	{
newList[i] = r[i];
    } 
delete[]r;
r = new Roster[capacity];
r = newList;
            }
r[numofrosters] = Roster(cn,cc,in,cred);
Student s1;
		  
for (int i = 0; i < numofstudents; i++)

		    {
cout << "Enter Student No." << i+1  << "'s Information: " << std::endl;
		      
cin >> s1;
r[numofrosters].addstudentname (s1);
cout << endl;
} 
numofrosters++;
cout << "Roster successfully added" <<endl;
        }
else if (option == 2)
	    {
cout <<"Please Enter a Course Code of a Roster that you want to drop: ";
cin >> rcheck;
rostersearchindex = rostersearch (r, numofrosters, rcheck);
if (rostersearchindex != -1)
		    {
numofrosters--;
r[rostersearchindex] = Roster ();
for (int i = rostersearchindex; i < numofrosters; i++)
	{
r[i] = r[i + 1];
    } 
            }
cout << "Roster Dropped" << endl;
        }
else if (option == 3)
		{
cout <<"Enter the Course Code of the Roster you want to display: ";
cin >> rcheck;
cout << endl;
rostersearchindex = rostersearch (r, numofrosters, rcheck);
if (rostersearchindex != -1)
    {
cout << r[rostersearchindex];
cout << endl;
    }
        }
else if (option == 4)
		{
cout << endl;
for (int i = 1; i < numofrosters; i++)
	{
cout << "Roster No." << i + 1 << endl;
cout << r[i] << endl;
    } 
        }       
	      else if (option == 5)
		{
char c1;
cout << endl;
cout << "a)Insert new Student to a Roster" <<endl;
cout << "b)Remove a Student from a Roster" <<endl;
cout << "c)Update a Student from a Roster" << endl;
cout <<"d)List Students in a Roster" <<endl;
cout <<"Choose one of the Student operation from above: ";
cin >> c1;
cout <<"Enter the Course Code for the Roster that you want view/edit "<<endl;
cin >> rcheck;
cout << endl;
int rostersearchindex = rostersearch (r, numofrosters, rcheck);
while (c1 < 'a' || c1 > 'd')
	{
cout << "TRY AGAIN: ";
cin >> c1;
    }
if (c1 == 'a')
		    {
if (rostersearchindex != -1)
			
		{
cout << "Enter the Student's Information..." <<endl;
cin >> s1;
r[rostersearchindex].addstudentname (s1);
cout << "Student Added to the Roster" << endl;
        }
            }
else if (c1 == 'b')
            {
if (rostersearchindex != -1)
	{
cout << "Enter the Student's First name: ";
cin >> fn;
cout << "Enter the Student's Last name: ";
cin >> ln;
int stucheckfordel = r[rostersearchindex].searchstudentname (fn, ln);
r[rostersearchindex].deletestudentname (stucheckfordel);
cout << "Student Deleted from the Roster" << endl;
    }
            }
else if (c1 == 'c')
		    {
if (rostersearchindex != -1)
			{
cout <<"Enter a Student of the student you want to Update"<< endl;
cout << "Enter the Student's First name: ";
cin >> fn;
cout << "Enter the Student's Last name: ";
cin >> ln;
int stucheckforup = r[rostersearchindex].searchstudentname (fn, ln);
cout << endl;
cout << "Now enter the updated student info" <<endl;
cin >> s1;
r[rostersearchindex].updatestudent (s1, stucheckforup);
			    cout << "Student Successfully Updated" << endl;
            }
}
else if (c1 == 'd')
	    {
if (rostersearchindex != -1)
{
cout << endl;
r[rostersearchindex].liststudents ();
}
        }
}
    }
}
 else	                        {
cout << "Entering User mode....." << endl;
cout << "User Mode MENU:" << endl;
cout << "a)Add a new Student to a Roster" << endl;
cout << "b)Remove a Student from a Roster" << endl;
cout << "c)Update a Student in a Roster" << endl;
cout << endl;
cout << "Choose one of the option from above: ";
char menuchoice;
cin >> menuchoice;
cout <<"Enter the Course Code of the Roster that you want to perform these operations on: ";
cin >> rcheck;
cout << endl;
int rostersearchindex = rostersearch (r, numofrosters, rcheck);
while (menuchoice < 'a' || menuchoice > 'd')
{
cout << "TRY AGAIN: ";
	      
cin >> menuchoice;
}
if (menuchoice == 'a')
	            {       
if (rostersearchindex != -1)
		{
cout<< "Enter the Information for the student of you want to enter..." << endl;
cin >> s1;
r[rostersearchindex].addstudentname (s1);
cout << "Student Added to the Roster" << endl;
        }
                }           
	  else if (menuchoice == 'b')
	    {
if (rostersearchindex != -1)
		    {
cout << "Enter the Student's First name: ";
cin >> fn;
cout << "Enter the Student's Last name: ";
cin >> ln;
int stucheckfordel = r[rostersearchindex].searchstudentname (fn, ln);
r[rostersearchindex].deletestudentname (stucheckfordel);
cout << "Student removed from the Roster" <<endl;
            }
	    
        }
else if (menuchoice == 'c')
	        {
if (rostersearchindex != -1)
		{
cout <<"Enter the following information of the student you want to update" <<endl;
cout << "Enter the Student's First name: ";
cin >> fn;
cout << "Enter the Student's Last name: ";
cin >> ln;
int stucheckforup = r[rostersearchindex].searchstudentname (fn, ln);
cout << endl;
cout << "Now enter the updated student info" << endl;
cin >> s1;
r[rostersearchindex].updatestudent (s1, stucheckforup);
cout << "Student Successfully Updated" << endl;
        }
            }

                            }
cout << endl;
cout << "Please choose (A)Superviser Mode, (B)User Mode or (C)Exit: ";
cin >> answer;
while (answer < 'A' || answer > 'C')
	{
cout << "Error:Try Again:";
cin >> answer;
}
}
  while (answer != 'C');
  
 
std::ofstream output;
  
output.open ("rosters.txt");
if (output.good ())
    
    {
      
for (int i = 0; i < numofrosters; i++)
	{
output << r[i].getcourse_name () << "|" 
<< r[i].getcourse_code () << "|" 
<< r[i].getcredits () << "|" 
<< r[i].getinstructor_name () <<"|" 
<< r[i].getroster_index () << endl;
	  
 
for (int j = 0; j < r[i].getroster_index (); j++)
{
output << r[i].getstudent (j).getFirstname () << "|" 
<<r[i].getstudent (j).getLastname () << "|" 
<<r[i].getstudent (j).getStudentid () << "|" 
<<r[i].getstudent (j).getStanding () << "|" 
<<r[i].getstudent (j).getcredits () << "|" 
<<r[i].getstudent (j).gpa () << "|" 
<<r[i].getstudent (j).getBirth ().getMonthNum () << "/" 
<<r[i].getstudent (j).getBirth ().getDay () << "/" 
<<r[i].getstudent (j).getBirth ().getYear () << "|" 
<<r[i].getstudent (j).getMatriculation ().getMonthNum () << "/" 
<<r[i].getstudent (j).getMatriculation ().getDay () << "/" 
<<r[i].getstudent (j).getMatriculation ().getYear () ;
} 
output<< "end_roster|";
if (i < numofrosters - 1)
{
output<<endl;
}
}
}
else
    {
cout << "Roster file did not open no changes were made." << endl;
    }
output.close ();
cout << endl;
 cout <<"File Saved and exiting from the program" <<endl;
delete[]r;
return 0;
}
int rostersearch (Roster * r, int capacity, string cd) 
{
for (int i = 0; i < capacity; i++)
    {
      
if (r[i].getcourse_code () == cd)
{
return i;
}
    }
cout << "Roster can't be found" << endl;
return -1;
}
