#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "person.h"
#include "book.h"
#include "member.h"

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
}

TEST_CASE("Testing member class", "[Member]"){

  Member member1(1, "yash","La Rosa", "yash@mail.com");

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
}
