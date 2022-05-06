// Copyright by Jenn Pham & Nhut Do
// May 6, 2022
// Main file

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
        std::cout << "1/ Querry using 1 criteria." << std::endl;
        menu1(myDB);
        break;
      case 2:
        std::cout << "2/ Querry using 2 criterias." << std::endl;
        menu2(myDB);
        break;
      case 3:
        std::cout << "3/ Querry using COUNT function." << std::endl;
        menu3(myDB);
        break;
      case 4:
        std::cout << "4/ Querry using GROUP BY function." << std::endl;
        menu4(myDB);
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
