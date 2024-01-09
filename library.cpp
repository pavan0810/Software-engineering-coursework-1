#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main(int argc, char *argv[]){
  if (argc != 2) {
    std::cout << "Usage: " << argv[0] << " input-filename" << std::endl;
    exit(1);
  }
  
  std::ifstream file;
  file.open(argv[1]);
  if(file.fail()){
    std::cout << "Error to read file\n" << std::endl;
    exit(1);
  }

  std::string line;
  while(getline(file, line)){
    std::cout << line << std::endl;
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
      std::cout << "option1" << std::endl;
    } else if (option == 2){
      std::cout << "option2" << std::endl;
    } else if (option == 3) {
      std::cout << "option3" << std::endl;
    } else if (option == 4) {
      std::cout << "option4" << std::endl;
    } else if (option == 5) {
      exit = 1;
    } else {
      std::cout << "Invalid option. Please try again!\n" << std::endl;
    }
  }
  return 0;
}
