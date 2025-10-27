/*
Student List
Aparajita Baidya
10.26.2025
Structs and pointers!
Type ADD --> create new studant: ask for 1st name, 2nd name, student id, gpa
Type PRINT --> print out all studants: format (1st name 2nd name, id, gpa)
Type DELETE --> ask for id, remove struct from vector (delete that data, dude)
Type QUIT --> program should end
*/
#include <iostream>
#include <cstring>
using namespace std;

//declare functions
int ADD();
int PRINT();
int DELETE();

//student struct
struct Student
{
  char name1[20];
  char name2[20];
  int id;
  float gpa;
}
  
int main()
{
  char input[7];//user input
  cout << "Hello there!" << endl;
  while(input != "QUIT")//the main while loop
  {
    cout << "Please enter an input: [ADD], [PRINT], [DELETE]" << endl;
    cin.get(input, 7);
    cin.ignore(50, '\n');
    if(input == "ADD")
    {
      ADD();
    }
    else if(input == "PRINT")
    {
      PRINT();
    }
    else if(input == "DELETE")
    {
      DELETE();
    }
  }
  return 0;
}

//add
int ADD()
{
  return 0;
}

//print
int PRINT()
{
  return 0;
}

//delete
int DELETE()
{
  return 0;
}
