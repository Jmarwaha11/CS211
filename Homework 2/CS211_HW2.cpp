#include <iostream>
#include<string>
using namespace std;

class Student
{
private:
  string lastname;
  string firstname;
  string standing;
  int credits;
  double gpa;
  string birth;
  string matriculation;
public:
    Student ()
  {
    lastname = "Doe";
    firstname = "John";
    standing = "Upper Senior";
    credits = 9000;
    gpa = 3.91;
    birth = "12/12/12";
    matriculation = "12/31/20";
  }
  Student (string last, string first, int cred, double gradepoint,
	   string bday, string mat)
  {
    firstname = first;
    lastname = last;
    credits = cred;
    gpa = gradepoint;
    birth = bday;
    matriculation = mat;
    if (credits >= 0 && credits < 15)
      {
	standing = "Lower Freshman";
      }
    else if (credits >= 15 && credits < 30)
      {
	standing = "Upper Freshman";
      }
    else if (credits >= 30 && credits < 45)
      {
	standing = "Lower Sophomore";
      }
    else if (credits >= 45 && credits < 60)
      {
	standing = "Upper Sophomore";
      }
    else if (credits >= 60 && credits < 75)
      {
	standing = "Lower Junior";
      }
    else if (credits >= 75 && credits < 90)
      {
	standing = "Upper Junior";
      }
    else if (credits >= 90 && credits < 105)
      {
	standing = "Lower Senior";
      }
    else if (credits >= 105)
      {
	standing = "Upper Senior";
      }
    else if (credits < 0)
      {
	standing = "invalid credits entered";
      }


  }
  string getfirstname ()
  {
    return firstname;
  }
  string getlastname ()
  {
    return lastname;
  }
  string getstanding ()
  {
    return standing;
  }
  string getbirth ()
  {
    return birth;
  }
  string getmatriculation ()
  {
    return matriculation;
  }
  int getcredits ()
  {
    return credits;
  }
  double getgpa ()
  {
    return gpa;
  }
  void setfirstname (string first)
  {
    firstname = first;
  }
  void setlastname (string last)
  {
    lastname = last;
  }
  void setbirth (string bday)
  {
    birth = bday;
  }
  void setmatriculation (string mat)
  {
    matriculation = mat;
  }
  void setgpa (double gradepoint)
  {
    gpa = gradepoint;
  }
  void setcredits (int cred)
  {
    credits = cred;
    if (credits >= 0 && credits < 15)
      {
	standing = "Lower Freshman";
      }
    else if (credits >= 15 && credits < 30)
      {
	standing = "Upper Freshman";
      }
    else if (credits >= 30 && credits < 45)
      {
	standing = "Lower Sophomore";
      }
    else if (credits >= 45 && credits < 60)
      {
	standing = "Upper Sophomore";
      }
    else if (credits >= 60 && credits < 75)
      {
	standing = "Lower Junior";
      }
    else if (credits >= 75 && credits < 90)
      {
	standing = "Upper Junior";
      }
    else if (credits >= 90 && credits < 105)
      {
	standing = "Lower Senior";
      }
    else if (credits >= 105)
      {
	standing = "Upper Senior";
      }
    else if (credits < 0)
      {
	standing = "invalid credits entered";
      }
  }
  void inputStudent ()
  {
    cout << endl << "Please input the following information for a student" <<
      endl;
    cout << "First Name ";
    cin >> firstname;
    cout << endl << "Last Name ";
    cin >> lastname;
    cout << endl << "Credits ";
    cin >> credits;
    cout << endl << "GPA ";
    cin >> gpa;
    cout << endl << "Birth Date ";
    cin >> birth;
    cout << endl << "Matriculation ";
    cin >> matriculation;
    if (credits >= 0 && credits < 15)
      {
	standing = "Lower Freshman";
      }
    else if (credits >= 15 && credits < 30)
      {
	standing = "Upper Freshman";
      }
    else if (credits >= 30 && credits < 45)
      {
	standing = "Lower Sophomore";
      }
    else if (credits >= 45 && credits < 60)
      {
	standing = "Upper Sophomore";
      }
    else if (credits >= 60 && credits < 75)
      {
	standing = "Lower Junior";
      }
    else if (credits >= 75 && credits < 90)
      {
	standing = "Upper Junior";
      }
    else if (credits >= 90 && credits < 105)
      {
	standing = "Lower Senior";
      }
    else if (credits >= 105)
      {
	standing = "Upper Senior";
      }
    else if (credits < 0)
      {
	standing = "invalid credits entered";
      }
  }
  void outputStudent ()
  {
    cout << endl << "the students information is the following";
    cout << endl << "First Name " << firstname;
    cout << endl << "Last Name " << lastname;
    cout << endl << "Credits " << credits;
    cout << endl << "Standing " << standing;
    cout << endl << "GPA " << gpa;
    cout << endl << "Date of Birth " << birth;
    cout << endl << "Matruculation Date " << matriculation;
  }


}

;
int
main ()
{
  int tnf;
  Student student1;
  Student student2;
  Student student3;
  student1.outputStudent ();
  student2.setlastname ("Mercury");
  student2.setfirstname ("Freddie");
  student2.setgpa (2.55);
  student2.setbirth ("11/11/11");
  student2.setcredits (101);
  student2.setmatriculation ("11/07/29");
  cout << endl <<
    "would you like to see the setter and getter functions type 1(Yes) or 0 to terminate the function";
  cin >> tnf;
  if (tnf <= 0)
    {
      return 0;
    }
  else if (tnf >= 0)
    {
      cout << endl <<"Last Name "<< student2.getlastname () << endl;
      cout << "First Name "<< student2.getfirstname () << endl;
      cout << "Credits "<< student2.getcredits () << endl;
      cout << "standings "<<student2.getstanding () << endl;
      cout << "GPA "<<student2.getgpa () << endl;
      cout << "Birthday "<<student2.getbirth () << endl;
      cout << "Matriculation date "<< student2.getmatriculation () << endl;
    }

  cout << endl <<
    "would you like to see the input function type 1(Yes) or 0 to terminate the function";
  cin >> tnf;
  if (tnf <= 0)
    {
      return 0;
    }
  else if (tnf >= 0)
    {
      student3.inputStudent ();
      student3.outputStudent ();
    }
  return 0;
}


