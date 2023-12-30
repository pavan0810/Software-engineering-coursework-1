#ifndef MEMBER_H
#define MEMBER_H
#include <string>
#include <vector>
class Member : public Person {
  
 public:
  Member(int ID, std::string name, std::string address, std:: string email);
  std::string getMemberID() const;
  std::vector<Book> getBooksBorrowed() const;
  void setBooksBorrowed(Book book);
  
 private:
  int memberId;
  std::vector<Book> booksLoaned;
};
#endif
