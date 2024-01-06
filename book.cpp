#include "book.h"
#include <string>
Book::Book(int bookID, std::string bookName, std::string authorFirstName, std::string authorLastName){
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

Date Book::getDueDate() const{
  return dueDate;
}

void Book::setDueDate(Date dueDate){
  dueDate = due_date;
}

void Book::returnBook(){
}

void Book::borrowBook(Member borrower, Date dueDate){
}
