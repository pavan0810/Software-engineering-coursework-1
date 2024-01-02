#ifndef BOOK_H
#define BOOK_H
#include "member.h"
#include <string>
#include <vector>
class Book {
 public:
  Book(int bookId, std::string book_name, std::string author_first_name, std::string author_last_name);
  std::string getbookID() const;
  std::string getbookName() const;
  std::string getAuthorFirstName const;
  std::string getAuthorLastName const;
  Date getDueDate() const;
  void setDueDate(Date due_date);
  void returnBook();
  void borrowBook(Member borrower, Date dueDate);
 private:
  int bookID;
  std::string bookName;
  std::string authorFirstName;
  std::string authorLastName;
  std::string bookType;
  Date dueDate;
  Member borrower;
};
#endif
