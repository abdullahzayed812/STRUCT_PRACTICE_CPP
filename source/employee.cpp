#include <algorithm>
#include <iostream>

using namespace std;

struct Employee {
  std::string name;
  short int age;
  double salary;
  std::string gender;
  void readEmployee();
  void printEmployee();
};

int added = 0;
const int MAX = 100;
Employee employeeArr[MAX];

void printEmployees();
bool compareName(const Employee& a, const Employee& b);
bool compareSalary(const Employee& a, const Employee& b);
bool compareNameSalary(const Employee& a, const Employee& b);

void Employee::readEmployee() {
  cout << "*** Read Employee ***"
       << "\n";
  cout << "\tEnter name: ";
  cin >> name;
  cout << "\tEnter age: ";
  cin >> age;
  cout << "\tEnter salary: ";
  cin >> salary;
  cout << "\tEnter gender: ";
  cin >> gender;
  cout << "\n";
}

void Employee::printEmployee() {
  cout << "\tName: " << name << "\t ";
  cout << "Age: " << age << "\t ";
  cout << "Salary: " << salary << "\t ";
  cout << "Gender: " << gender << "\t ";
  cout << "\n";
}

void printEmployees() {
  cout << "*** Print employees ***\n";
  for (int i = 0; i < added; i++) employeeArr[i].printEmployee();
}

bool compareName(const Employee& a, const Employee& b) {
  return a.name < b.name;
}

bool compareSalary(const Employee& a, const Employee& b) {
  return a.salary > b.salary;
}

bool compareNameSalary(const Employee& a, const Employee& b) {
  if (a.name != b.name) return a.name < b.name;
  return a.salary > b.salary;
}

int main() {
  employeeArr[added++].readEmployee();
  employeeArr[added++].readEmployee();
  printEmployees();

  cout << "Sorted by name: ";
  sort(employeeArr, employeeArr + added, compareName);
  printEmployees();

  cout << "Sorted by salary: ";
  sort(employeeArr, employeeArr + added, compareSalary);
  printEmployees();

  // Employee emp1 = {"Hamza", 2, 20000, "Male"};
  // Employee emp = {"Abdullah", 26, 6000, "Male"};
  // emp.ptr = &emp1;

  // cout << "Name: " << emp.name << "\n";
  // cout << "Age: " << emp.age << "\n";
  // cout << "Salary: " << emp.salary << "\n";
  // cout << "Gender: " << emp.gender << "\n";
  // cout << "Name again: " << emp.ptr->name << "\n";
}