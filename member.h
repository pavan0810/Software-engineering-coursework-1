#ifndef MEMBER_H
#define MEMBER_H
#include "person.h"
#include <string>
#include <vector>
class Book;
class Member : public Person {
 public:
  Member(int memberID, std::string name, std::string address, std:: string email);
  std::string getMemberID() const;
  std::vector<Book> getBooksBorrowed() const;
  void setBooksBorrowed(Book book);
  
 private:
  int memberId;
  std::vector<Book> booksLoaned;
};
#endif
