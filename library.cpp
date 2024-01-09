#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "person.h"
#include "member.h"
#include "librarian.h"
#include "book.h"

// function to add a Member
std::vector<Member*> addMember(Librarian* librarian, std::vector<Member*> members){
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
  members.push_back(new Member(memberID,name, address, email));
  std::cout << "Member added successfully!" << std::endl;
  return members;
}

void borrowBook(){
}

void returnBook(){
}

void displayBorrowedBooks(){
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
    std::cout << "1. Add Member" << std::endl;
    std::cout << "2. Borrow Book" << std::endl;
    std::cout << "3. Return Book" << std::endl;
    std::cout << "4. View all borrowed books" << std::endl;
    std::cout << "5. Exit\n" << std::endl;
    std::cout << "Enter the number for the option: " << std::endl;
    std::cin >> option;
    if (option == 1){
      clear();
      members = addMember(librarian, members);
    } else if (option == 2){
      clear();
      borrowBook();
    } else if (option == 3) {
      clear();
      returnBook();
    } else if (option == 4) {
      clear();
      displayBorrowedBooks();
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
  members.clear();
  return 0;
}
