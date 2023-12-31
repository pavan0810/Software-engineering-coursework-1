#include "books.h"
#include <string>
Book:Book(int bookId, std::string book_name, std::string author_first_name, std::string author_last_name){
  bookID = bookId;
  bookName = book_name;
  authorFirstName = author_first_name;
  authorLastName = author_last_name;
}

std::string Book:getbookID() const{
  return bookID;
}

std::string Book:getbookName() const{
  return bookName;
}

std::string Book:getAuthorFirstName const{
  return authorFirstName;
}

std::string Book:getAuthorLastName const{
  return authorLastName;
}

Date Book:getDueDate() const{
  return dueDate;
}

void Book:setDueDate(Date due_date){
  dueDate = due_date;
}

void Book:returnBook(){
}

void Book:borrowBook(Member borrower, Date dueDate){
}
