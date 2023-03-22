#include "hw.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <string.h>
using namespace std;

 
Roster::Roster ()
{
  
course_name = "Sculptures of Anything Goes";
  
course_code = "AM22";
  
instructor_name = "Alex Turner";
  
credits = 4;
  
roster_index = 0;

}


Roster::Roster (string cse_name, string cse_code, string inst_name, int cred,
		 int r_in) 
{
  
course_name = cse_name;
  
course_code = cse_code;
  
instructor_name = inst_name;
  
credits = cred;
  
roster_index = r_in;

};


void
Roster::setcourse_name (string cse_name) 
{
  course_name = cse_name;

};


void
Roster::setcourse_code (string cse_code) 
{
  course_code = cse_code;

} 
void

Roster::setinstructor_name (string inst_name) 
{
  instructor_name = inst_name;

} 
void

Roster::setcredits (int cred) 
{
  credits = cred;

} 
string Roster::getcourse_name () 
{
  return course_name;
}


string Roster::getcourse_code () 
{
  return course_code;
}


string Roster::getinstructor_name () 
{
  return instructor_name;
}


int
Roster::getcredits () 
{
  return credits;
}


void
Roster::addstudentname (string targetstudentname) 
{
  studentname[roster_index] = targetstudentname;
  
roster_index++;

 
} 
int

Roster::searchstudentname (string targetstudentname) 
{
  for (int i = 0; i <= roster_index; i++)
    {
      
 
if (studentname[i] == targetstudentname)
	{
	  
return i;
	}
    
 
}
  
cout << " there is no student with this name" << endl;
  
 
return -1;

}


void
Roster::deletestudentname (string targetstudentname) 
{
  
int numberonrost = Roster::searchstudentname (targetstudentname);
  
 
for (int k = numberonrost; k <= roster_index - 1; ++k)
    {
      
 
studentname[k] = studentname[k + 1];

 
}};


void
Roster::liststudents ()
{
  
for (int i = 0; i <= roster_index; i++)
    
    {
      
cout << i + 1 << ":" << studentname[i] << endl;

} 
} 
