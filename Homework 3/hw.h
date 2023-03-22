#ifndef hw_h
#define hw_h
#define MAX_CAPACITY 10
#include <string>
using namespace std;

class Roster 
{

private:
string course_name, course_code, instructor_name;
  
string studentname[MAX_CAPACITY];
  
int credits, roster_index;

public:
Roster ();
  
Roster (string cse_name, string cse_code, string inst_name, int cred,
	   int r_in);
  
void setcourse_name (string);
  
void setcourse_code (string);
  
void setinstructor_name (string);
  
void setcredits (int);
  
string getcourse_name ();
  
string getcourse_code ();
  
string getinstructor_name ();
  
int getcredits ();
  
void addstudentname (string studentname);
  
int searchstudentname (string targetstudentname);
  
void deletestudentname (string studentname);
  
void liststudents ();

};


#endif	/* 
 */
  
