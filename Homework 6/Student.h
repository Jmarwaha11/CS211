#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <string>
#include "Date.h"
using namespace std;

class Student
{
private:
string Lastname,Firstname,Standing;
int credits;
string Studentid;
double gradepointaverage;
Date birthday;
Date Matriculation;
public:
Student();
Student(string LN,string FN,string stuid,int cred,double gpa,Date Birth,Date Mat);
string getFirstname();
string getLastname();
string getStanding();
int getcredits();
string getStudentid();
double gpa();
Date getBirth();
Date getMatriculation();
void setLastname(string LN);
void setFirstname(string FN);
void setcredits(int cred);
void setstudentid(string studid);
void setgradepointaverage(double gpa);
void setbirthday(Date Birth);
void setMatriculation(Date Mat);
void inputstudent();
void outputstudent();
bool operator==(Student &other);
bool operator!=(Student &other);
bool operator>(Student &other);
bool operator<(Student &other);
bool operator>=(Student &other);
bool operator<=(Student &other);

friend std::ostream& operator<<(std::ostream& out, Student &other);
friend std::istream& operator>>(std::istream& in, Student &other);
};

#endif