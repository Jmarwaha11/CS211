#include <iostream>
#include <string>
#include "Student.h"
using namespace std;
Student::Student()
{

    Lastname = "Doe";
    Firstname = "John";
    Standing = "Upper Senior";
    credits = 9000;
    gradepointaverage = 3.91;
    birthday =Date(1,1,1970);
    Matriculation = Date(1,1,1972);
    Studentid="2662494";

};
Student::Student(string LN,string FN,string stuid,int cred,double gpa,Date Birth,Date Mat)
{Lastname=LN;
Firstname=FN;
Studentid=stuid;
credits=cred;
gradepointaverage=gpa;
Matriculation=Mat;
birthday=Birth;
if (credits >= 0 && credits < 15)
      {
	Standing = "Lower Freshman";
      }
    else if (credits >= 15 && credits < 30)
      {
	Standing = "Upper Freshman";
      }
    else if (credits >= 30 && credits < 45)
      {
	Standing = "Lower Sophomore";
      }
    else if (credits >= 45 && credits < 60)
      {
	Standing = "Upper Sophomore";
      }
    else if (credits >= 60 && credits < 75)
      {
	Standing = "Lower Junior";
      }
    else if (credits >= 75 && credits < 90)
      {
	Standing = "Upper Junior";
      }
    else if (credits >= 90 && credits < 105)
      {
	Standing = "Lower Senior";
      }
    else if (credits >= 105)
      {
	Standing = "Upper Senior";
      }
    else if (credits < 0)
      {
	Standing = "invalid credits entered";
      }
      
}
std::string Student::getFirstname()
{
    return Firstname;
};
std::string Student::getLastname()

{ return Lastname;
}

std::string Student::getStanding()
{
    return Standing;
}
int Student::getcredits()
{
    return credits;
}
string Student::getStudentid()
{
    return Studentid;
}
double Student::gpa()
{
    return gradepointaverage;
}

Date Student::getBirth(){
    return birthday;
}
Date Student::getMatriculation(){
    return Matriculation;
}
void Student::setLastname(string LN){
       Lastname=LN;
}
void Student::setFirstname(string FN){
    Firstname=FN;
}
void Student::setcredits(int cred){
    credits=cred;
}
void Student::setstudentid(string studid){
    Studentid=studid;
}
void Student::setgradepointaverage(double gpa){
    gradepointaverage=gpa;
}
void Student::setbirthday(Date Birth){
    birthday=Birth;
}
void Student::setMatriculation(Date Mat){
    Matriculation=Mat;
}
void Student::inputstudent()
  {
    cout << endl << "Please input the following information for a student" <<
      endl;
    cout << "First Name ";
    cin >> Firstname;
    cout << endl << "Last Name ";
    cin >> Lastname;
    cout << endl << "Credits ";
    cin >> credits;
    cout << endl << "GPA ";
    cin >> gradepointaverage;
    cout << endl << "Birth Date ";
    birthday.input();
    cout << endl << "Matriculation ";
    Matriculation.input();
    if (credits >= 0 && credits < 15)
      {
	Standing = "Lower Freshman";
      }
    else if (credits >= 15 && credits < 30)
      {
	Standing = "Upper Freshman";
      }
    else if (credits >= 30 && credits < 45)
      {
	Standing = "Lower Sophomore";
      }
    else if (credits >= 45 && credits < 60)
      {
	Standing = "Upper Sophomore";
      }
    else if (credits >= 60 && credits < 75)
      {
	Standing = "Lower Junior";
      }
    else if (credits >= 75 && credits < 90)
      {
	Standing = "Upper Junior";
      }
    else if (credits >= 90 && credits < 105)
      {
	Standing = "Lower Senior";
      }
    else if (credits >= 105)
      {
	Standing = "Upper Senior";
      }
    else if (credits < 0)
      {
	Standing = "invalid credits entered";
      }
  }
void Student::outputstudent()
      {
    cout << endl << "the students information is the following";
    cout << endl << "First Name " << Firstname;
    cout << endl << "Last Name " << Lastname;
    cout << endl << "Credits " << credits;
    cout << endl << "Standing " << Standing;
    cout << endl << "GPA " << gradepointaverage;
    birthday.output();
    Matriculation.output();
  }

bool Student:: operator==(Student &other)
    {
return((Lastname == other.Lastname) && (Firstname == other.Firstname) && (Studentid == other.Studentid));
}
bool Student:: operator!=(Student &other)
{
return((Lastname != other.Lastname) || (Firstname != other.Firstname) || (Studentid != other.Studentid));
}
bool Student:: operator>(Student &other)
{
if (Lastname > other.Lastname)
return true;
else if (Lastname < other.Lastname)
return false;
else
{
if (Firstname > other.Firstname)
return true;
else if (Firstname < other.Firstname)
return false;
else
return(Studentid > other.Studentid);
}
}
bool Student:: operator<(Student &other)
{
if (Lastname < other.Lastname)
return true;
else if (Lastname > other.Lastname)
return false;
else
{
if (Firstname < other.Firstname)
return true;
else if (Firstname > other.Firstname)
return false;
else
return(Studentid < other.Studentid);
}
}
bool Student:: operator>=(Student &other)
{
if (Lastname >= other.Lastname)
return true;
else
return false;
}
bool Student:: operator<=(Student &other)
{
if (Lastname <= other.Lastname)
return true;
else
return false;
}

std::ostream& operator<<(std::ostream& out, Student &other)
{
out <<std::endl<< "ID: " << other.Studentid << std::endl
<< "First Name: " << other.Firstname << std::endl
<< "Last Name: " << other.Lastname << std::endl
<< "Date of Birth: " << std::endl<<other.birthday << std::endl
<< "Date of Matriculation: "<<std::endl << other.Matriculation << std::endl
<< "Credits: " << other.credits << std::endl
<< "Standing: " << other.Standing << std::endl
<< "GPA: " << other.gradepointaverage << std::endl;
return out;
}
std::istream& operator>>(std::istream& in, Student &other)
{cout<<"Enter StudentID: ";
in >> other.Studentid;
cout<< std::endl<<"Enter Student First name:" ;
in>> other.Firstname;
cout<< std::endl<<"Enter Student Last name:" ;
in>> other.Lastname ;
cout<< std::endl<<"Enter Student Date of Birth:" ;
in>> other.birthday;
cout<< std::endl<<"Enter Student Matriculation: " ;
in >> other.Matriculation ;
cout<< std::endl<<"Enter credits:" ;
in>> other.credits ;
cout<< std::endl<<"Enter Grade Point Average:" ;
in>> other.gradepointaverage;
return in;
}