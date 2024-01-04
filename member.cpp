#include "member.h"
#include <string>
#include <vector>

Member::Member(int ID, std::string name, std::string address, std:: string email){
  setName(name);
  setAddress(address);
  setEmail(email);
  memberId = ID;
}

std::string Member::getMemberID() const{
  return std::to_string(memberId);
}

std::vector<Book> Member::getBooksBorrowed() const{
  return booksLoaned;
}

void Member::setBooksBorrowed(Book book){
  book = book;
}
