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
  std::cout << "New member added successfully!" << std::endl;
}

/**
   Displays a message to allow librarian to issue a book to a member
   @param memberID stores the ID of the member
   @param bookID stores the ID of the book
   
 */
void Librarian::issueBook(int memberID, int bookID) {
  std::cout << "----------------------------------------------------------------------" << std::endl;
  std::cout << "Registration completed! Book can be issued to Member." << std::endl;
  std::cout << "Member ID: " << memberID << std::endl;
  std::cout << "Book ID: " << bookID << std::endl;
}

/**
   Displays a message to show that a member has returned a book
   @param memberID stores the ID of the member
   @param bookID stores the ID of the book
   
 */
void Librarian::returnBook(int memberID, int bookID){
  std::cout << "The member with ID " << memberID << " has returned the book with ID " << bookID << std::endl;
  std::cout << "----------------------------------------------------------------------" << std::endl;
}

/**
   Displays a message to display whose member's books are being displayed
   @param memberID stores the ID of the member
   
 */
void Librarian::displayBorrowedBooks(int memberID){
  std::cout << "The books borrowed by member " << memberID << " are:" << std::endl;
}

/**
   Displays a message to show which member has to pay a fine
   @param memberID stores the ID of the member
   
 */
void Librarian::calcFine(int memberID) {
  std::cout << "----------------------------------------------------------------------" << std::endl;
  std::cout << "The member with memberID " << memberID << " has exceeded the due date." << std::endl;
  std::cout << "The fine to be paid is: " << std::endl; 
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
