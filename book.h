#ifndef BOOK_H
#define BOOK_H
#include "date.h"
#include <string>
#include <vector>
class Member;
class Book {
 public:
  Book(int bookID, std::string bookName, std::string authorFirstName, std::string authorLastName);
  std::string getbookID() const;
  std::string getbookName() const;
  std::string getAuthorFirstName() const;
  std::string getAuthorLastName() const;
  Date* getDueDate() const;
  void setDueDate(Date* dueDate);
  void returnBook();
  void borrowBook(Member* borrower, Date* dueDate);
 private:
  int bookID;
  std::string bookName;
  std::string authorFirstName;
  std::string authorLastName;
  std::string bookType;
  Date* dueDate;
  Member* borrower;
};
#endif
