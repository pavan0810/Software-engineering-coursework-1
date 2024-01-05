#include <iostream>

int main(){
  int exit = 0;
  int option;
  while (exit != 1){
    std::cout << "Welcome to the main menu." << std::endl;
    std::cout << "1. Add Member" << std::endl;
    std::cout << "2. Borrow Book" << std::endl;
    std::cout << "3. Return Book" << std::endl;
    std::cout << "4. View all borrowed books" << std::endl;
    std::cout << "5. Exit" << std::endl;
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
    }
  }
  return 0;
}
