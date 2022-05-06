#define MYSQLPP_MYSQL_HEADERS_BURIED
#include <mysql++/mysql++.h>
#include "functions.h"
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
        menu1(myDB);
        std::cout << "1/ Querry using 1 criteria." << std::endl;
        break;
      case 2:
        menu2(myDB);
        std::cout << "2/ Querry using 2 criterias." << std::endl;
        break;
      case 3:
        menu3(myDB);
        std::cout << "3/ Querry using COUNT function." << std::endl;
        break;
      case 4:
        menu4(myDB);
        std::cout << "4/ Querry using GROUP BY function." << std::endl;
        break;
      default:
        break;
    }
    std::cout << "-------------------------------------------\n";
    printMenu();
    std::cin >> choice;
  }

  std::cout << "EXIT. End of program." << std::endl;

  return 0;
}
