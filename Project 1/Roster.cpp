#include <string>
#include "Roster.h"
#include "iostream"
using namespace std;

void
Roster::sort ()
{
  int i, k, min;

  for (i = 0; i < roster_index - 1; i++)
    {
      min = i;
      for (int k = i + 1; k < roster_index; ++k)
	{
	  if (studentname[k] < studentname[min])
	    {
	      min = k;
	    }
	}
      Student *m = studentname[min];
      studentname[min] = studentname[i];
      studentname[i] = m;
      m = nullptr;
    }
}

Roster::Roster ()
{

  course_name = "Sculptures of Anything Goes";

  course_code = "AM22";

  instructor_name = "Alex Turner";

  credits = 4;

 this->studentname=new Student *[this->defaultcap]; 


}

Roster::Roster (string cse_name, string cse_code, string inst_name, int cred
		)
{

  course_name = cse_name;

  course_code = cse_code;

  instructor_name = inst_name;

  credits = cred;

this->studentname = new Student * [this->defaultcap];
      
}

void
Roster::setcourse_name (string cse_name)
{
  course_name = cse_name;

}
Roster::Roster(const Roster& other)
{
        this->course_name = other.course_name;
        this->course_code = other.course_code;
        this->instructor_name = other.instructor_name;
        this->credits = other.credits;
        this->roster_index = other.roster_index;
        this->defaultcap = other.defaultcap;
        this->studentname = new Student * [this->defaultcap];
        Student* newstu;
        for (int i = 0; i < this->roster_index; i++)
        {
                newstu = new Student(*other.studentname[i]);
                studentname[i] = newstu;
                newstu = nullptr;
        }
}

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
Roster::setroster_index (int r_in)
{
  roster_index = r_in;

}

void
Roster::setcredits (int cred)
{
  credits = cred;

}

string
Roster::getcourse_name ()
{
  return course_name;
}

string
Roster::getcourse_code ()
{
  return course_code;
}

string
Roster::getinstructor_name ()
{
  return instructor_name;
}

int
Roster::getcredits ()
{
  return credits;
}
Student 
Roster::getstudent(int check)
{
        if (check < 0 || check >(defaultcap- 1))
        {
        cout << "Error invalid number used" << endl;
                exit(0);
        }
        else if (check > this->roster_index)
        {
        cout << "Error: There is no student at index " << check << endl;
                exit(0);
        }
        else
        {
                return *this->studentname[check];
        }
}
int
Roster::getroster_index ()
{
    return this->roster_index;
}
void
Roster::addstudentname (Student targetstudentname)
{
  if (this->roster_index >=this->defaultcap)
    {
      grow ();

    }
  else
    {
     Student * newstu= new Student(targetstudentname);
      this->studentname[roster_index] = newstu;
      newstu=nullptr;
      roster_index++;
     
    }

}

int
Roster::searchstudentname (string Firstname, string Lastname)
{
  int check = -1;
  for (int i = 0; i < this->roster_index; i++)
    {


      if (((*this->studentname[i]).getFirstname () == Firstname)
	  && ((*this->studentname[i]).getLastname () == Lastname))
	{
	  check = i;
	  break;
	}
    }
  return check;

}

void
Roster::updatestudent(Student s,int r_i)
{
Student* newstu = new Student(s);
this->studentname[r_i]=newstu;
newstu=nullptr;
}

void
Roster::deletestudentname (int i)
{

  if (i < 0 || i > (defaultcap - 1))
    {
      cout << "There is no student with this first and last name ignore the statement bellow" << endl;
     return;
    
    }
  else if (i > this->roster_index)
    {
      cout << "There is no student at this index number" << endl;
      return;
    }
  else
    {
      roster_index--;
      delete this->studentname[i];
      for (int k = i; i < this->roster_index; i++)
	{
	  *this->studentname[i] = *this->studentname[i + 1];

	}
    }
}

void
Roster::liststudents ()
{
  this->sort ();

  for (int i = 0; i < roster_index; i++)

    {

      cout << (i + 1) << ":";
      (*studentname[i]).outputstudent ();
      cout << endl;
    }
  if (roster_index == 0)
    cout << "the Roster is empty" << endl;
}


ostream & operator<< (ostream & out, Roster & other)
{
  out << "Course Name: " << other.course_name << std::endl
    << "Course Code: " << other.course_code << std::endl
    << "Instructor Name: " << other.instructor_name << std::endl
    << "Credits: " << other.credits << std::endl
    << "Number of students: " << other.roster_index << std::endl;
for (int i=0; i<other.roster_index;i++)
{
    out <<"Student"<<(i+1)<<std::endl;
    out<<other.studentname[i]<<std::endl;
}

  return out;
}

istream & operator>> (istream & in, Roster & other)
{
  cout << "Enter a Course Name: ";
  in >> other.course_name;
  cout << "Enter a Course Code: ";
  in >> other.course_code;
  cout << "Enter a Instructor Name: ";
  in >> other.instructor_name;
  cout << "Enter the credits for the class: ";
  in >> other.credits;
  cout << "Enter the Number of Students: ";
  in >> other.roster_index;


  return in;
}

const Student &
Roster::operator[] (int in)
{
  if (in < 0 || in > (roster_index - 1))
    {
      cout << "The index is out of bounds" << endl;
      exit (0);
    }
  return *studentname[in];
}

void
Roster::grow ()
{
  this->defaultcap *=2;
  Student **newindex = new Student *[this->defaultcap];
  for (int i = 0; i < this->roster_index; i++)
    {
      newindex[i] = studentname[i];
    }
  delete[]studentname;
  studentname = newindex;
}

Roster & Roster::operator= (const Roster & r)
{
  if (this != &r)
    {
      this->course_name = r.course_name;
      this->course_code = r.course_code;
      this->instructor_name = r.instructor_name;
      this->credits = r.credits;
      for (int i = 0; this->roster_index; i++)
	delete this->studentname[i];
      delete[]studentname;
      this->roster_index = r.roster_index;
      this->defaultcap = r.defaultcap;
      Student **
	newindex = new Student *[this->defaultcap];
      Student *
	newstu;
      for (int i = 0; i < this->roster_index; i++)
	{
	  newstu = new Student (*r.studentname[i]);
	  newindex[i] = newstu;
	  newstu = nullptr;
	}
      studentname = newindex;
    }
  return *this;
}
Roster::~Roster()
{
        for (int i = 0; i < this->roster_index; i++)
        {
                delete studentname[i];
        }
        delete[] studentname;
}
