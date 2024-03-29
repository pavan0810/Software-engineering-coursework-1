#include "book.h"
#include "member.h"
#include <string>
Book::Book(int bookID, std::string bookName, std::string authorFirstName, std::string authorLastName):dueDate(new Date(0,0,0)){
  this->bookID = bookID;
  this->bookName = bookName;
  this->authorFirstName = authorFirstName;
  this->authorLastName = authorLastName;
}

std::string Book::getbookID() const{
  return std::to_string(bookID);
}

std::string Book::getbookName() const{
  return bookName;
}

std::string Book::getAuthorFirstName() const{
  return authorFirstName;
}

std::string Book::getAuthorLastName() const{
  return authorLastName;
}

Date* Book::getDueDate() const{
  return dueDate;
}

void Book::setDueDate(Date* dueDate){
  this->dueDate = dueDate;
}

/**
   sets the dueDate and borrower to null when member returns the book
   
 */
void Book::returnBook(){
  dueDate = nullptr;
  borrower = nullptr;
}

/**
   Sets the borrower and due date for the book when a member is borrowing the book
 */
void Book::borrowBook(Member* borrower, Date* dueDate){
  this->borrower = borrower;
  setDueDate(dueDate);
}
