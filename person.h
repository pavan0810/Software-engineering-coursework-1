#ifndef PERSON_H
#define PERSON_H
#include <string>
class Person {
 public:
  std::string getName() const;
  void setName(std::string person_name);
  std::string getAddress() const;
  void setAddress(std::string person_address);
  std::string getEmail() const;
  void setEmail(std::string person_email);
  
 private:
  std::string name;
  std::string address;
  std::string email;
};
#endif
