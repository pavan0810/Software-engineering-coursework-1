#include <iostream>
#include <fstream>
#include <string>
#include <vector>

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
      std::cout << bookID << std::endl << bookName << std::endl <<
	  authorFirstName << std::endl << authorLastName << std::endl;
      std::cout << line[i] << std::endl;
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
      std::cout << "option1" << std::endl;
    } else if (option == 2){
      clear();
      std::cout << "option2" << std::endl;
    } else if (option == 3) {
      clear();
      std::cout << "option3" << std::endl;
    } else if (option == 4) {
      clear();
      std::cout << "option4" << std::endl;
    } else if (option == 5) {
      exit = 1;
    } else {
      clear();
      std::cout << "Invalid option. Please try again!\n" << std::endl;
    }
  }
  return 0;
}
