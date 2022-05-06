#define MYSQLPP_MYSQL_HEADERS_BURIED
#include <mysql++/mysql++.h>

void printMenu() {
  // Function to print the option menu
  std::cout << "Option. Enter the appropriate number to choose the option: \n";
  std::cout << "1/ Querry using 1 criteria.\n";
  std::cout << "2/ Querry using 2 criteria.\n";
  std::cout << "3/ Querry using COUNT function.\n";
  std::cout << "4/ Querry using GROUP BY function.\n";
}

void menu3(mysqlpp::Connection myDB) {
  mysqlpp::Query query = myDB.query();
  std::cout << "This code will output the number of airports to
  in each city in the country you input \(Maximum 10 lines)\n";
  std::cout << "Example:\nVietnam\nGermany\nUkraine\nSpain\n";
  String country;
  std::cin >> country;
  query << "SELECT Country, City, COUNT(*) FROM Airports GROUP BY City HAVING Country =
  '" << country << "' LIMIT 10";

  query.parse();
  mysqlpp::StoreQueryResult result = query.store();

  // Results is a 2D vector of mysqlpp::String objects.
  // Print the results.
  for (const auto& row : result) {
      for (const auto& col : row) {
          std::cout << col << "\t";
      }
      std::cout << std::endl;
  }
  // All done
  return 0;

}
