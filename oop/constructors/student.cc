#include <cstring>
#include <iostream>
#include "student.h"

using namespace std;


//////////////////////////////////////////////////////////

void Student::set_name(const char* nam)
{
  delete[] name;
  name = new char[strlen(nam)+1];
  strcpy(name,nam);
}



void Student::set_no(int n)
{
        no = n;
}

void Student::set_year_of_studies(int y)
{
        year_of_studies = y;
}



//////////////////////////////////////////////////////////

char* Student::get_name() const
{
        return name;
}

int Student::get_no() const
{
        return no;
}

int Student::get_year_of_studies() const
{
        return year_of_studies;
}


//////////////////////////////////////////////////////////
// Destructor

Student::~Student()
{
   cout << "Deleting student with name " << name << endl ;
   delete[] name;
}


//////////////////////////////////////////////////////////
// Constructors

Student::Student(const char* nam)
{
   name = new char[strlen(nam)+1];
   strcpy(name,nam);
   cout << "I just constructed a student " << endl;
}

Student::Student()
{
   cout << "I just constructed a student " << endl;
}





#ifdef COPY
//////////////////////////////////////////////////////////
// Copy-Constructors


Student::Student(const Student& s)
{ name = new char[strlen(s.name)+1];
  strcpy(name,s.name);
  // name = s.name; Careful: this is the result of default copy
  no = s.no;
  year_of_studies = s.year_of_studies;
  cout << "I just created a student by copying ... " << endl;
}

#endif


#ifdef ASSIGN
//////////////////////////////////////////////////////////
// Function-symbol '=' overload

Student& Student::operator=(const Student& s)
{
  // name = s.name; Careful: this is the result of default assignment
  if (this != &s) { // Careful not to assign to itself, especially
  // if some storage reclaim was made within the body
     
    if (name != NULL) delete[] name;
    name = new char[strlen(s.name)+1];
    strcpy(name,s.name);
    no = s.no;
    year_of_studies = s.year_of_studies;
    cout << "I just performed a student ASSIGNMENT ... " << endl;
  }
  return *this;
}


#endif
