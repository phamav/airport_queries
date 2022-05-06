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

  while (choice < 5 && choice <= 0) {
    switch (choice) {
      case 1:
        menu1(myDB);
        break;
      case 2:
        menu2(myDB);
        break;
      case 3:
        menu3(myDB);
        break;
      case 4:
        menu4(myDB);
        break;
    }
    printMenu();
    std::cin >> choice;
  }

  std::cout << "End of program." << std::endl;

  return 0;
}
