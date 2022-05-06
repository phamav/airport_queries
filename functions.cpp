// Copyright by Jenn Pham and Nhut Do
// May 5, 2022
// Functions file for reading and writing databases.

#define MYSQLPP_MYSQL_HEADERS_BURIED
#include <mysql++/mysql++.h>
#include "functions.h"
#include <iostream>
#include <string>

/**
 * @brief
 *
 */
void menu1(mysqlpp::Connection myDB) {
    // Create a query
    mysqlpp::Query query = myDB.query();

    // Print the examples of cities.
    std::cout << "Here are sample city names in Germany.  <---- possible input list (used limit 5)" << std::endl;
    std::cout << "- Bautzen" << std::endl;
    std::cout << "- Altenburg" << std::endl;
    std::cout << "- Dessau" << std::endl;
    std::cout << "- Eisenhuettenstadt" << std::endl;
    std::cout << "- Suhl" << std::endl;

    // Ask for user input
    std::string city;
    std::cout << "Enter the city name in Germany >>" << std::endl;
    std::cin >> city;

    query << "SELECT * FROM Airports WHERE City = '" << city << "' LIMIT 5;";

    query.parse();  // check to ensure query is correct
    // Run the query and get stored results
    mysqlpp::StoreQueryResult result = query.store();

    std::cout << "Here are the airports in " << city << std::endl;
    // Results is a 2D vector of mysqlpp::String objects.
    // Print the results.
    std::cout << "ID\tName\tCity\tCountry\tCode\tICAO\tLatitude\tLongtitude\tAltitude\tTimezone\tDST\tTz" << std::endl;
    for (const auto& row : result) {
        for (const auto& col : row) {
            std::cout << col << "\t";
        }
        std::cout << std::endl;
    }
}

/**
 * @brief
 *
 */
void menu2(mysqlpp::Connection myDB) {
    // Create a query
    mysqlpp::Query query = myDB.query();

    // Print the examples of cities.
    std::cout << "Here are sample city names in Germany.  <---- possible input list (used limit 5)" << std::endl;
    std::cout << "- Bautzen" << std::endl;
    std::cout << "- Altenburg" << std::endl;
    std::cout << "- Dessau" << std::endl;
    std::cout << "- Eisenhuettenstadt" << std::endl;
    std::cout << "- Suhl" << std::endl;

    // Ask for user input (2 entries)
    std::string city;
    std::cout << "Enter the city name in Germany >>" << std::endl;
    std::cin >> city;

    int ID;
    std::cout << "Enter the ID range >>" << std::endl;
    std::cin >> ID;
    query << "SELECT * FROM Airports WHERE City = "
    << city << " & ID <= " << ID << " LIMIT 5;";

    query.parse();  // check to ensure query is correct
    // Run the query and get stored results
    mysqlpp::StoreQueryResult result = query.store();

    std::cout << "Here are the airports in " << city << std::endl;
    // Results is a 2D vector of mysqlpp::String objects.
    // Print the results.
    std::cout << "ID\tName\tCity\tCountry\tCode\tICAO\tLatitude\tLongtitude\tAltitude\tTimezone\tDST\tTz" << std::endl;
    for (const auto& row : result) {
        for (const auto& col : row) {
            std::cout << col << "\t";
        }
        std::cout << std::endl;
    }
}

void menu3(mysqlpp::Connection myDB) {
    mysqlpp::Query query = myDB.query();
    std::cout << "This code will output the number of airports to in each city in the country you input\n";
    std::cout << "(Maximum 10 lines)\n";
    std::cout << "Example:\nVietnam\nGermany\nUkraine\nSpain\n";
    std::string country;
    std::cin >> country;
    query << "SELECT Country, City, COUNT(*) FROM Airports GROUP BY City HAVING Country = "
    << country << " LIMIT 10;";

    query.parse();
    mysqlpp::StoreQueryResult result = query.store();

    // Results is a 2D vector of mysqlpp::String objects.
    // Print the results.
    std::cout << "Country\tCity\tCOUNT(*)" << std::endl;
    for (const auto& row : result) {
        for (const auto& col : row) {
            std::cout << col << "\t";
        }
        std::cout << std::endl;
    }
}

void menu4(mysqlpp::Connection myDB) {
  mysqlpp::Query query = myDB.query();
  std::cout << "This code will output the number of airports to group by the category you input\n";
  std::cout << "(Maximum 10 lines)\n";
  std::cout << "Options:\nCountry\nCode\nLongtitude\nLatitude\nAltitude\n";
  std::cout << "Timezone\nDST\nTz\n";
  std::string category;
  std::cin >> category;
  query << "SELECT " << category << ", COUNT(*) FROM Airports GROUP BY "
  << category << " ORDER BY " << category << " LIMIT 15;";

  query.parse();
  mysqlpp::StoreQueryResult result = query.store();

  // Results is a 2D vector of mysqlpp::String objects.
  // Print the results.
  std::cout << category << "\tCOUNT(*)\t" << category << std::endl;
  for (const auto& row : result) {
      for (const auto& col : row) {
          std::cout << col << "\t";
      }
      std::cout << std::endl;
  }
}

void printMenu() {
    // Function to print the option menu
    std::cout << "Option. Enter the appropriate number to choose the option: \n";
    std::cout << "1/ Querry using 1 criteria.\n";
    std::cout << "2/ Querry using 2 criteria.\n";
    std::cout << "3/ Querry using COUNT function.\n";
    std::cout << "4/ Querry using GROUP BY function.\n";
}
