#include "librarian.h"
#include "member.h"
#include <iostream>
#include <string>
#include <vector>
#include <iostream>

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
  std::cout << "------------------------------------------------------------------------" << std::endl;
  std::cout << "Registration completed! Book can be issued to Member." << std::endl;
  std::cout << "Member ID: " << memberID << std::endl;
  std::cout << "Book ID: " << bookID << std::endl;
  std::cout << "------------------------------------------------------------------------" << std::endl;
}

void Librarian::returnBook(int memberID, int bookID){
}

void Librarian::displayBorrowedBooks(int memberID){
}

void Librarian::calcFine(int memberID) {
}

int Librarian::getStaffID() const {
  return staffId;
}

void Librarian::setStaffID(int staffID){
  staffId = staffID;
}

int Librarian::getSalary() const {
  return salary;
}

void Librarian::setSalary(int salary){
  this->salary = salary;
}
