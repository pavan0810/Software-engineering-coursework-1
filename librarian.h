#ifndef LIBRARIAN_H
#define LIBRARIAN_H
#include "person.h"
#include "book.h"
#include <string>
class Librarian : public Person {
 public:
  Librarian(int staffID, std::string name, std::string address, std::string email, int salary);
  void addMember();
  void issueBook(int memberID, int bookID);
  void returnBook(int memberID, int bookID);
  void displayBorrowedBooks(int memberID);
  void calcFine(int memberID);
  int getStaffID() const;
  void setStaffID(int staffID);
  int getSalary() const;
  void setSalary(int librarian_salary);
  
 private:
  int staffid;
  int salary;
};
#endif
