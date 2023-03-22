#include"hw.h"
#include <iostream>
using namespace std;

int
main () 
{
  int flick;
  
Roster Roster1;
  
cout << "this is the default constructor" << endl;
  
cout << "Course Name: : " << Roster1.getcourse_name () << endl;
  
cout << "Course Code : " << Roster1.getcourse_code () << endl;
  
cout << "Instructor name : " << Roster1.getinstructor_name () << endl;
  
cout << "This class is worth " << Roster1.
    getcredits () << " credits" << endl;
  
cout << "would you like to see the setters(enter a positive number)" <<
    endl;
  
cin >> flick;
  
if (flick > 0)
    {
      
Roster1.setcourse_name ("Midnights");
      
Roster1.setcourse_code ("TS22");
      
Roster1.setinstructor_name ("Taylor Swift");
      
Roster1.setcredits (3);
      
cout << "Course Name: : " << Roster1.getcourse_name () << endl;
      
cout << "Course Code : " << Roster1.getcourse_code () << endl;
      
cout << "Instructor name : " << Roster1.getinstructor_name () << endl;
      
cout << "This class is worth " << Roster1.
	getcredits () << " credits" << endl;
    
}
  
cout <<
    "would you like to see the add roster function (enter a postive number)"
    << endl;
  
cin >> flick;
  
if (flick > 0)
    {
      
Roster1.addstudentname ("johnny");
      
Roster1.addstudentname ("Terra");
      
Roster1.addstudentname ("lima tall");
      
Roster1.addstudentname ("liz truss");
      
Roster1.addstudentname ("Ethan");
      
Roster1.addstudentname ("lisa");
      
Roster1.addstudentname ("oreo");
      
Roster1.addstudentname ("truffles");
      
Roster1.addstudentname ("sprinkles");
      
Roster1.liststudents ();
    
}
  
cout <<
    "would you like to see the search funciton (enter a postive number)" <<
    endl;
  
cin >> flick;
  
if (flick > 0)
    {
      
cout <<
	"here is a result from a search for steven which is not in the list"
	<< endl;
      
Roster1.searchstudentname ("steven");
      
    
 
}
  
cout <<
    "would you like to see the delete funciton (enter a postive number)" <<
    endl;
  
cin >> flick;
  
if (flick > 0)
    {
      
Roster1.deletestudentname ("johnny");
      
Roster1.deletestudentname ("sprinkles");
      
Roster1.deletestudentname ("lisa");
      
Roster1.deletestudentname ("oreo");
      
Roster1.liststudents ();
    
}

 
}
