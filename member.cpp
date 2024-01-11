#include "member.h"
#include "book.h"
#include <string>
#include <vector>

Member::Member(int memberID, std::string name, std::string address, std:: string email){
  setName(name);
  setAddress(address);
  setEmail(email);
  this->memberId = memberID;
}

std::string Member::getMemberID() const{
  return std::to_string(memberId);
}

/**
   gets all the books borrowed by a member
   @return vector<Book*>
 */
std::vector<Book*> Member::getBooksBorrowed() const{
  return booksLoaned;
}


/**
   adds a book to the books loaned for the member
   @param The pointer of the book object to add to the list
 */
void Member::setBooksBorrowed(Book* book){
  if(book->getbookName() == "remove"){
    booksLoaned.clear();
  } else {
    booksLoaned.push_back(book);
  }
}
