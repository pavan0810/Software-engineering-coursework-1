#include "person.h"
#include <string>
void Person::setName(std::string name) {
  this->name = name;
}
void Person::setAddress(std::string address) {
  this->address = address;
}
void Person::setEmail(std::string email) {
  this->email = email;
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
