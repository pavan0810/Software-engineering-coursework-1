#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "person.h"
#include "book.h"
#include "member.h"
#include "librarian.h"
#include "date.h"

// test for person class
TEST_CASE("Testing Person class", "[Person]"){
  Person person1;
  person1.setName("yash");
  person1.setAddress("La Rosa");
  person1.setEmail("y@example.com");
  
  SECTION("Testing getName() function"){
    REQUIRE(person1.getName() == "yash");
  }
  
  SECTION("Testing getAddress() function"){
    REQUIRE(person1.getAddress() == "La Rosa");
  }
  
  SECTION("Testing getEmail() function"){
    REQUIRE(person1.getEmail() == "y@example.com");
  }
}

// test for book class
TEST_CASE("Testing Book class", "[Book]"){
  Book book1(1,"Harry Potter", "JK", "Rowling");
  Date* dueDate = new Date(10,10,2024);
  book1.setDueDate(dueDate);
    
  SECTION("testing getbookID() function"){
    REQUIRE(book1.getbookID() == "1");
    
  }
  
  SECTION("testing getbookName() function"){
    REQUIRE(book1.getbookName() == "Harry Potter");
  }
  
  SECTION("testing getAuthorFirstName() function"){
    REQUIRE(book1.getAuthorFirstName() == "JK");
  }
  
  SECTION("testing getookID() function"){
    REQUIRE(book1.getAuthorLastName() == "Rowling");
  }

  SECTION("testing getDueDate() function"){
    REQUIRE(book1.getDueDate() == dueDate);
  }

  SECTION("testing returnBook() function"){
    book1.returnBook();
    REQUIRE(book1.getDueDate() == nullptr);
  }
  delete dueDate;
}


// Test for Member class
TEST_CASE("Testing member class", "[Member]"){
  Member member1(1, "yash","La Rosa", "yash@mail.com");
  Book* book1 = new Book(1,"Harry Potter", "JK", "Rowling");
  Book* book2 = new Book(2,"Harry Potter and The Goblet of Fire", "JK", "Rowling");
  Book* book3 = new Book(3,"remove", "remove", "remove");
  member1.setBooksBorrowed(book1);
  member1.setBooksBorrowed(book2);
  
  SECTION("Testing getName() function"){
    REQUIRE(member1.getName() == "yash");
  }
  
  SECTION("Testing getAddress() function"){
    REQUIRE(member1.getAddress() == "La Rosa");
  }
  
  SECTION("Testing getEmail() function"){
    REQUIRE(member1.getEmail() == "yash@mail.com");
  }
  
  SECTION("Testing getMemberID() function"){
    REQUIRE(member1.getMemberID() == "1");
  }

  SECTION("Testing setBooksBorrowed(Book* book) function"){
    std::vector<Book*> expectedBooks;
    expectedBooks = {book1, book2};
    REQUIRE((member1.getBooksBorrowed()).size() == expectedBooks.size());
    member1.setBooksBorrowed(book3);
    expectedBooks = {};
    REQUIRE((member1.getBooksBorrowed().size()) == expectedBooks.size());
  }
}


// Testing Librarian class
TEST_CASE("Testing Librarian class", "[Librarian]"){
  Librarian librarian1(1, "yash", "La Rosa", "yash@example.com", 40000);
  
  SECTION("Testing getStaffID() function"){
    REQUIRE(librarian1.getStaffID() == 1);
  }
  SECTION("Testing getSalary() function"){
    REQUIRE(librarian1.getSalary() == 40000);
  }
  SECTION("Testing getName() function"){
    REQUIRE(librarian1.getName() == "yash");
  }
  
  SECTION("Testing getAddress() function"){
    REQUIRE(librarian1.getAddress() == "La Rosa");
  }
  
  SECTION("Testing getEmail() function"){
    REQUIRE(librarian1.getEmail() == "yash@example.com");
  }
}

// Test for date ADT
TEST_CASE("Testing date ADT", "[Date]"){
  Date birthdate(8,10,2002);

  SECTION("Testing getDay() function"){
    REQUIRE(birthdate.getDay() == 8);
  }

  SECTION("Testing getMonth() function"){
    REQUIRE(birthdate.getMonth() == 10);
  }

  SECTION("Testing getYear() function"){
    REQUIRE(birthdate.getYear() == 2002);
  }
}
