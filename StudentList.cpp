/*
Student List
Aparajita Baidya
10.27.2025

Structs and pointers!
Type ADD --> create new studant: ask for 1st name, 2nd name, student id, gpa
Type PRINT --> print out all studants: format (1st name 2nd name, id, gpa)
Type DELETE --> ask for id, remove struct from vector (delete that data, dude)
Type QUIT --> program should end
*/

#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

//student struct
struct Student
{
  char name1[20];
  char name2[20];
  int id;
  float gpa;
};

//declare functions
void ADD(vector<Student*>*, int& c);
void PRINT(vector<Student*>*);
void DELETE(vector<Student*>*, int& i);
  
int main()
{
  //make vector for student struct pointer of type...student pointer
  //vector<Student*>* stud = new vector<Student*>(); pass pointer, use arrows
  //vector<Student*> stud; pass by reference, use & when sending it to functions
  vector<Student*>* stud = new vector<Student*>();
  int idnum; //gonna use this for checking if two ID numbers are the same
  int idCheck;//same reason as idnum, but used differently
  char input[7];//user input
  
  cout << "Hello there!" << endl;

  while(strcmp(input, "QUIT") != 0)//the main while loop
  {
    cout << "Please enter an input: [ADD], [PRINT], [DELETE]" << endl;
    cin.get(input, 7);
    cin.ignore(50, '\n');
    cout << "Your input was: " << input << endl;
    if(strcmp(input, "ADD") == 0)
    {
      ADD(stud, idCheck);
      cout << "added" << endl;
    }
    else if(strcmp(input, "PRINT") == 0)
    {	
      PRINT(stud);
      cout << "printed" << endl;
    }
    else if(strcmp(input, "DELETE") == 0)
    {
      cout << "Alrighty then, please give me an ID number" << endl;
      cin >> idnum;//in this case, I'll be looking for idnum in the student* vector
      cout << "Oookay, " << idnum << ", lets see if that student even exists...";
      //DELETE(stud, idnum);
      cout << "deleted" << endl;
    }
    else if(strcmp(input, "QUIT") != 0)
    {
      cout << "what.";
    }
  }
  return 0;
}

//add
void ADD(vector<Student*>* stud, int& idCheck)
{
  //get ready for the cout-cin wall
  Student* s = new Student();
  cout << "Please enter the students first name:" << endl;
  cin >> s -> name1;
  cin.ignore(50,'\n');
  cout << endl;

  cout << "last name:" << endl;
  cin >> s -> name2;
  cin.ignore(50,'\n');
  cout << endl;
  
  cout << "ID:" << endl;
  cin >> s -> id;
  cin.ignore(50,'\n');
  cout << endl;
  //heh made a do while to check if ID is already taken
  do
  {
    for(vector<Student*>::iterator it = stud -> begin(); it != stud -> end(); ++it)
    {
      if((*it) -> id == s -> id) //if IDs are the same, as again, and set idnum to 0 so it loops to check again
      {
	idCheck = 0;
	cout << "oops, someone has that id! Set it to a different one!" << endl;
	cin >> s -> id;
      }
      else//if there are no matches, exit the loop!
      {
	idCheck = 1;
      }
    }
  }while(idCheck==0);
  
  cout << "GPA:" << endl;
  cin >> s -> gpa;
  cin.ignore(50,'\n');
  cout << endl;
  //round GPA to 2 digits
  
  
  //finally, push that student into stud
  stud -> push_back(s);
}

//print

void PRINT(vector<Student*>* stud)
{
  for(vector<Student*>::iterator it = stud -> begin(); it != stud -> end(); ++it)
  {
    //yup. A long long line of dereferencing and cout-ing
    cout << (*it) -> name1 << ' ' << (*it) -> name2 << ", " << (*it) -> id << ", " << (*it) -> gpa << endl;
  }
}

//delete
void DELETE(vector<Student*>* stud, int& idnum) //the inputed id
{
  //delete based on id, so iterate through vector and find student with correct id
  for(vector<Student*>::iterator it = stud -> begin(); it != stud -> end(); ++it)
  {
    //yup. A long long line of dereferencing and cout-ing
    if((*it -> id == idnum)
    {
      cout << "Yup yup, I guess it exists.";
    }
  }
}
