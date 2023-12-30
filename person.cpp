#include "person.h"
#include <string>
void Person::setName(std::string person_name) {
  name = person_name;
}
void Person::setAddress(std::string person_address) {
  address = person_address;
}
void Person::setEmail(std::string person_email) {
  email = person_email;
}

std::string Person::getName() const {
  return name;
}
std::string Person::getAddress() const {
  return address;
}

std::string Person::getEmail() const {
  return email;
}
