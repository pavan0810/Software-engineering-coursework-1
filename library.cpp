#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "person.h"
#include "member.h"
#include "librarian.h"
#include "book.h"

/**
   Function to add a member to the library system
   @param librarian is a pointer to the librarian object
   @param vector<Member*> stores all the members for the library
   
 */
void addMember(Librarian* librarian, std::vector<Member*>& members){
  int memberID;
  std::string name;
  std::string address;
  std::string email;
  std::cout << "Input name of member: " << std::endl;
  std::cin >> name;
  std::cout << "Input address of member: " << std::endl;
  std::cin >> address;
  std::cout << "Input email of member: " << std::endl;
  std::cin >> email;
  memberID = members.size() + 1;
  Member* newMember = new Member(memberID,name, address, email);
  members.push_back(newMember);
  std::cout << "----------------------------------------------------------------------" << std::endl;
  std::cout << "MemberID: " <<  newMember->getMemberID() << std::endl <<
    "Name: " << newMember->getName() << std::endl <<
    "Email: " << newMember->getEmail()<< std::endl <<
    "Address: " << newMember->getAddress() << std::endl;
  std::cout << "----------------------------------------------------------------------" << std::endl;
}

/**
   Function to borrow a book from the library
   @param librarian is a pointer to the librarian object
   @param vector<Member*> stores all the members for the library
   @param vector<Book*> stores all the books in the library
   @param vector<Date*> stores all the dates for the books
   
 */
void borrowBook(Librarian* librarian, std::vector<Member*>& members, std::vector<Book*>& books, std::vector<Date*>& dates){
  Book* book;
  Member* member;
  int exit = 0;
  int memberID;
  int bookID;
  bool foundMember = false;
  bool foundBook = false;
  int day;
  int month;
  int year;
  std::string choice;
  std::cout << "Please input MemberID: " << std::endl;
  std::cin >> memberID;
  std::cout << "Please input BookID: " << std::endl;
  std::cin >> bookID;
  if(members.size() != 0 && books.size() != 0){
    for(int i=0;i<members.size();i++){
      if(std::to_string(memberID) == members[i]->getMemberID()){
	foundMember = true;
	member = members[i];
      }
    }
    for(int j=0;j<books.size();j++){
      if(std::to_string(bookID) == books[j]->getbookID()){
	foundBook = true;
	book = books[j];
      }
    }
    
    while(foundMember == false || foundBook == false){
      std::cout << "BookID or MemberID does not exist, please input again!" << std::endl;
      std::cout << "Do you want to continue input?[y/n]" << std::endl;
      std::cin >> choice;
      if (choice == "y" || choice == "Y"){
	std::cout << "Please input MemberID: " << std::endl;
	std::cin >> memberID;
	std::cout << "Please input BookID: " << std::endl;
	std::cin >> bookID;
	for(int i=0;i<members.size();i++){
	  if(std::to_string(memberID) == members[i]->getMemberID()){
	    foundMember = true;
	    member = members[i];
	  }
	}
	for(int j=0;j<books.size();j++){
	  if(std::to_string(bookID) == books[j]->getbookID()){
	    foundBook = true;
	    book = books[j];
	  }
	}
      } else {
	exit = 1;
	break;
      }    
    }
    if(exit != 1) {
      std::cout << "Please input today's date in the form day month year: " << std::endl;
      std::cin >> day >> month >> year;
      // calculating the due date
      if (day > 28 && month == 12){
	day = day + 3 - 31;
	month = 1;
	year = year + 1;
      } else if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 12) {
	if (day > 28) {
	  day = day + 3 - 31;
	  month = month + 1;
	} else {
	  day = day + 3;
	}
      } else {
	if(month == 2){
	  if(day > 25) {
	    day = day + 3 - 28;
	    month = month + 1;
	  } else {
	    day = day + 3;
	  }
	} else {
	  if(day > 27){
	    day = day + 3 - 30;
	    month = month + 1;
	  } else {
	    day = day + 3;
	  }
	}
      }
      Date* dueDate = new Date(day, month, year);
      dates.push_back(dueDate);
      book->setDueDate(dueDate);
      book->borrowBook(member, dueDate);
      member->setBooksBorrowed(book);
      librarian->issueBook(memberID, bookID);
    }
  } else {
    std::cout << "No member has been registered" << std::endl;
  }
  
}

/**
   Function to calculate after how many days the member is returning a book
   @param day stores the day when the book was returned
   @param month stores the month the book was returned
   @param year stores the year the book was returned
   @param returnDay stores the day of the due date
   @param returnMonth stores the month of the due date
   @param returnYear stores the year of the due date
   @return the difference between the return date and due date for the book
   
 */
int dateDifference(int day, int month, int year, int returnDay, int returnMonth, int returnYear){
  int totalDaysReturn = 0;
  int totalDays = 0;
  int difference = 0;
  if(year == returnYear){
    for(int i=1;i<month;i++){
      if (i==1 || i==3 || i==5 || i==7 || i==8 || i==10 || i==12 ) {
        totalDays = totalDays + 31;
      } else if(i==2) {
	totalDays = totalDays + 28;
      } else {
	totalDays = totalDays + 30;
      }
    }
    totalDays = totalDays + day;
    for(int j=1;j<returnMonth;j++){
      if (j==1 || j==3 || j==5 || j==7 || j==8 || j==10 || j==12 ) {
	totalDaysReturn = totalDaysReturn + 31;
      } else if(j==2) {
	totalDaysReturn = totalDaysReturn + 28;
      } else {
	totalDaysReturn = totalDaysReturn + 30;
      }
    }
    totalDaysReturn = totalDaysReturn + returnDay;
  } else {
    for(int i=1;i<month;i++){
      if (i==1 || i==3 || i==5 || i==7 || i==8 || i==10 || i==12 ) {
	totalDays = totalDays + 31;
      } else if(i==2) {
	totalDays = totalDays + 28;
      } else {
	totalDays = totalDays + 30;
      }
    }
    totalDays = totalDays + day + 365;
    for(int j=1;j<returnMonth;j++){
      if (j==1 || j==3 || j==5 || j==7 || j==8 || j==10 || j==12 ) {
	totalDaysReturn = totalDaysReturn + 31;
      } else if(j==2) {
	totalDaysReturn = totalDaysReturn + 28;
      } else {
	totalDaysReturn = totalDaysReturn + 30;
      }
    }
    totalDaysReturn = totalDaysReturn + returnDay;
  }
  difference = totalDays - totalDaysReturn;
  return difference;
}

/**
   Function to return a book to the library
   @param librarian is a pointer to the librarian object
   @param vector<Member*> stores all the members for the library
   @param vector<Book*> stores all the books in the library
   
 */
void returnBook(Librarian* librarian, std::vector<Member*>& members, std::vector<Book*>& books){
  Book* book;
  Member* member;
  int exit = 0;
  int memberID;
  int bookID;
  bool foundMember = false;
  bool foundBook = false;
  bool memberBook = false;
  std::string choice;
  Date* dueDate;
  int day;
  int month;
  int year;
  int returnDay;
  int returnMonth;
  int returnYear;
  int diffDate;
  std::vector<Book*> booksLoaned;
  if(members.size() != 0 && books.size() != 0){
    std::cout << "Please input MemberID: " << std::endl;
    std::cin >> memberID;
    std::cout << "Please input BookID: " << std::endl;
    std::cin >> bookID;
    for(int i=0;i<members.size();i++){
      if(std::to_string(memberID) == members[i]->getMemberID()){
	foundMember = true;
	member = members[i];
      }
    }
    for(int j=0;j<books.size();j++){
      if(std::to_string(bookID) == books[j]->getbookID()){
	foundBook = true;
	book = books[j];
      }
    }
    
    while(foundMember == false || foundBook == false){
      std::cout << "BookID or MemberID does not exist, please input again!" << std::endl;
      std::cout << "Do you want to continue input?[y/n]" << std::endl;
      std::cin >> choice;
      if (choice == "y" || choice == "Y"){
	std::cout << "Please input MemberID: " << std::endl;
	std::cin >> memberID;
	std::cout << "Please input BookID: " << std::endl;
	std::cin >> bookID;
	for(int i=0;i<members.size();i++){
	  if(std::to_string(memberID) == members[i]->getMemberID()){
	    foundMember = true;
	    member = members[i];
	  }
	}
	for(int j=0;j<books.size();j++){
	  if(std::to_string(bookID) == books[j]->getbookID()){
	    foundBook = true;
	    book = books[j];
	  }
	}
      } else {
	exit = 1;
	break;
      }    
    }
    if(exit != 1) {
      booksLoaned = member->getBooksBorrowed();
      if (booksLoaned.size() == 0){
	std::cout << "Member with memberID " << memberID << " has not borrowed this book!" << std::endl; 
      } else {
	for(int i=0;i<booksLoaned.size();i++) {
	  if (booksLoaned[i]->getbookID() == std::to_string(bookID)){
	    std::cout << "Input today's date in the form day month year: " << std::endl;
	    std::cin >> day >> month >> year;
	    memberBook = true;
	    dueDate = book->getDueDate();
            returnDay = dueDate->getDay();
	    returnMonth = dueDate->getMonth();
	    returnYear = dueDate->getYear();
	    member->setBooksBorrowed(new Book(0, "remove", "remove", "remove"));
	    break;
	  }
	}
	if (memberBook == true){
	  diffDate = dateDifference(day, month, year, returnDay, returnMonth, returnYear);
	  if (diffDate > 3) {
	    librarian->calcFine(memberID);
	    std::cout << "£ " << diffDate << std::endl;
	  }
	  book->returnBook();
	  librarian->returnBook(memberID, bookID);

	  // adding books borrowed except return book to booksLoaned for member
	  for(int i=0;i<booksLoaned.size();i++){
	    if (!(booksLoaned[i]->getbookID() == std::to_string(bookID))){
	      member->setBooksBorrowed(booksLoaned[i]);
	    }
	  }
	} else {
	  std::cout << "This book has not been borrowed by member!" << std::endl;
	}
      }
    }
  } else {
    std::cout << "No member has been registered" << std::endl;
  }
}

/**
   Function to display all borrowe dbooks by a member
   @param librarian is a pointer to the librarian object
   @param vector<Member*> stores all the members for the library
   
 */
void displayBorrowedBooks(std::vector<Member*>& members, Librarian* librarian){
  int memberID;
  bool foundMember = false;
  bool display = false;
  std::string choice;
  Member* member;
  std::vector<Book*> booksBorrowed;
  std::cout << "Please enter member ID of member to view all books borrowed by member: " << std::endl;
  std::cin >> memberID;
  if(members.size() != 0) {
    for(int i=0;i<members.size();i++){
      if(std::to_string(memberID) == members[i]->getMemberID()){
	foundMember = true;
	display = true;
	member = members[i];
      }
    }
    while(foundMember != true){
      std::cout << "MemberID entered is not valid, please input again or exit!" << std::endl;
      std::cout << "Do you want to continue input?[y/n]" << std::endl;
      std::cin >> choice;
      if (choice == "y" || choice == "Y"){
	std::cout << "Please enter member ID of member to view all books borrowed by member: " << std::endl;
	std::cin >> memberID;
	for(int i=0;i<members.size();i++){
	  if(std::to_string(memberID) == members[i]->getMemberID()){
	    foundMember = true;
	    display = true;
	    member = members[i];
	  }
	}
      } else {
	break;
      }
    }
    if(display == true){
      booksBorrowed = member->getBooksBorrowed();
      if (booksBorrowed.size() == 0){
	std::cout << "Member has not borrowed any books!" << std::endl;
      } else {
	librarian->displayBorrowedBooks(memberID);
	for(int j=0;j<booksBorrowed.size();j++) {
	  std::cout << booksBorrowed[j]->getbookName() << std::endl;
	}
      }
    }
    
  } else {
    std::cout << "No member has been created. Create a member first.";
  }
}

// function to clear the screen
void clear(){
  std::cout << "\033c";
}

// main function
int main(int argc, char *argv[]){
  // check if filename argument has been passed
  if (argc != 2) {
    std::cout << "Usage: " << argv[0] << " input-filename" << std::endl;
    exit(1);
  }

  std::ifstream file;
  file.open(argv[1]);
  // check if there an error in opening the file
  if(file.fail()){
    std::cout << "Error to read file\n" << std::endl;
    exit(1);
  }

  // creating a librarian object
  Librarian* librarian = new Librarian(1, "Shana", "New Grove", "s@gamil.com", 25000);
  std::vector<Date*> dates;
  std::vector<Member*> members;
  std::vector<Book*> books;
  std::string line;
  std::string::size_type i;
  std::string temp="";
  int count;
  int bookID;
  std::string authorFirstName;
  std::string authorLastName;
  std::string bookName;
  int fileLine = 0;
  // read the file line by line until end of file
  while(getline(file, line)){
    if (fileLine != 0){
      count = 1;
      for(i=0;i < line.length();i++){
	if(line[i] == ',' || i == (line.length() - 1)){
	  if (i == line.length() - 1) {
	    temp = temp + line[i];
	  }
	  if (count == 1){
	    bookID = std::stoi(temp);
	  } else if(count == 2){
	    bookName = temp;
	  } else if(count == 4){
	    authorFirstName = temp;
	  } else if(count == 5){
	    authorLastName = temp;
	  }
	  count = count + 1;
	  temp = "";
	} else {
	  temp = temp + line[i];
	}
      }
      books.push_back(new Book(bookID, bookName, authorFirstName, authorLastName));
    }
    fileLine = fileLine + 1;
  }
  file.close();
  
  int exit = 0;
  int option;
  while (exit != 1){
    std::cout << "Welcome to the main menu.\n" << std::endl;
    std::cout << "----------------------------------------------" << std::endl;
    std::cout << "1. Add Member" << std::endl;
    std::cout << "2. Borrow Book" << std::endl;
    std::cout << "3. Return Book" << std::endl;
    std::cout << "4. View all borrowed books" << std::endl;
    std::cout << "5. Exit\n" << std::endl;
    std::cout << "----------------------------------------------" << std::endl;
    std::cout << "Enter the number for the option: " << std::endl;
    std::cin >> option;
    if (option == 1){
      clear();
      addMember(librarian, members);
    } else if (option == 2){
      clear();
      borrowBook(librarian, members, books, dates);
    } else if (option == 3) {
      clear();
      returnBook(librarian, members, books);
    } else if (option == 4) {
      clear();
      displayBorrowedBooks(members, librarian);
    } else if (option == 5) {
      exit = 1;
    } else {
      clear();
      std::cout << "Invalid option. Please try again!\n" << std::endl;
    }
  }
  for(std::vector<Book*>::size_type j = 0;j<books.size();j++){
    delete books[j];
  }
  books.clear();
  
  for(std::vector<Member*>::size_type k = 0;k<members.size();k++){
    delete members[k];
  }

  for(std::vector<Date*>::size_type l = 0;l<dates.size();l++){
    delete dates[l];
  }
  delete librarian;
  members.clear();
  return 0;
}
