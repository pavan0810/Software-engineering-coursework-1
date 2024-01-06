#include "date.h"
Date::Date(int day, int month, int year){
  this->day = day;
  this->month = month;
  this->year = year;
}

void Date::setDay(int day){
  this->day = day;
}

void Date::setMonth(int month){
  this->month = month;
}

void Date::setYear(int year){
  this->year = year;
}

int Date::getDay(){
  return day;
}

int Date::getMonth(){
  return month;
}

int Date::getYear(){
  return year;
}
