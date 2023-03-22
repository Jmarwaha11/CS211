#ifndef hw_h
#define hw_h
#define MAX_CAPACITY 10
#include <string>
#include "Student.h"
using namespace std;

class Roster 
{

private:
string course_name, course_code, instructor_name;
  
Student** studentname;
  
int credits, roster_index=0,defaultcap=10;


void grow();
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
  
void addstudentname (Student);
  
int searchstudentname (string ,string );
  
void deletestudentname (int);
 void sort(); 
void liststudents ();
friend ostream& operator<<(ostream &out, Roster &other);

friend istream& operator>>(istream &in, Roster &other);
const Student& operator[](int);
Roster& operator=(const Roster&);
};




#endif	/* 
 */
  
