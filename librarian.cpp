#include "librarian.h"
#include <string>
Librarian::Librarian(int staffID, std::string name, std::string address, std::string email, int salary) {
  setStaffID(staffID);
  setSalary(salary);
  setName(name);
  setAddress(address);
  setEmail(email);
}

void Librarian::addMember() {
}

void Librarian::issueBook(int memberID, int bookID) {
}

void Librarian::returnBook(int memberID, int bookID){
}

void Librarian::displayBorrowedBooks(int memberID){
}

void Librarian::calcFine(int memberID) {
}

int Librarian::getStaffID() const {
  return staffid;
}

void Librarian::setStaffID(int staffID){
  staffid = staffID;
}

int Librarian::getSalary() const {
  return salary;
}

void Librarian::setSalary(int librarian_salary){
  salary = librarian_salary;
}
