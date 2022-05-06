#define MYSQLPP_MYSQL_HEADERS_BURIED
#include <mysql++/mysql++.h>
#include <functions.h>
#include <iostream>

int main() {

  int choice;
  mysqlpp::Connection myDB("cse278", "localhost", "cse278",
          "wVQABsJFQhwNdNbr");

  printMenu();
  std::cin >> choice;

  while (choice < 5 && choice > 0) {
    switch (choice) {
      case 1:
        // menu1(myDB);
        std::cout << "1";
        break;
      case 2:
        // menu2(myDB);
        std::cout << "2";
        break;
      case 3:
        // menu3(myDB);
        std::cout << "3";
        break;
      case 4:
        // menu4(myDB);
        std::cout << "4";
        break;
    }
    printMenu();
    std::cin >> choice;
  }

  std::cout << "End of program." << std::endl;

  return 0;
}
