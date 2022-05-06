// Copyright by Jenn Pham and Nhut Do
// May 5, 2022
// Functions file for reading and writing databases.

#define MYSQLPP_MYSQL_HEADERS_BURIED
#include <mysql++/mysql++.h>
#include "functions.h"
#include <iostream>
#include <string>

/**
 * @brief Querying airports data based on one selection criteria.
 * The selection criterion (a table column- more columns) should be determined by the programmer in the program.
 *
 * @param myDB
 */
void menu1(mysqlpp::Connection myDB) {
    // Create a query
    mysqlpp::Query query = myDB.query();

    // Print the examples of cities.
    std::cout << "Here are sample city names in Germany.  "
    << "<---- possible input list (used limit 10)" << std::endl;
    std::cout << "- Bautzen" << std::endl;
    std::cout << "- Altenburg" << std::endl;
    std::cout << "- Dessau" << std::endl;
    std::cout << "- Eisenhuettenstadt" << std::endl;
    std::cout << "- Suhl" << std::endl;

    // Ask for user input
    std::string city;
    std::cout << "Enter the city name in Germany >>" << std::endl;
    std::cin >> city;

    query << "SELECT ID, Name, Code, City, Country FROM Airports WHERE City = '"
    << city << "' LIMIT 10;";

    query.parse();  // check to ensure query is correct
    // Run the query and get stored results
    mysqlpp::StoreQueryResult result = query.store();

    std::cout << "Here are the airports in " << city << std::endl;
    // Results is a 2D vector of mysqlpp::String objects.
    // Print the results.
    std::cout << "ID\tName\tCode\tCity\tCountry" << std::endl;
    for (const auto& row : result) {
        for (const auto& col : row) {
            std::cout << col << "\t";
        }
        std::cout << std::endl;
    }
}

/**
 * @brief Querying airports data based on two selection criteria.
 * The selection criteria (two table columns) should be determined by the programmer in the program.
 *
 * @param myDB
 */
void menu2(mysqlpp::Connection myDB) {
    // Create a query
    mysqlpp::Query query = myDB.query();

    // Print the examples of cities.
    std::cout << "Here are sample city names in Germany.  "
    << "<---- possible input list (used limit 10)" << std::endl;
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
    std::cout << "Enter the maximum ID you want >>" << std::endl;
    std::cin >> ID;
    query << "SELECT ID, Name, Code, City, Country FROM Airports WHERE City = '"
    << city << "' AND ID <= " << ID << " LIMIT 10;";

    query.parse();  // check to ensure query is correct
    // Run the query and get stored results
    mysqlpp::StoreQueryResult result = query.store();

    std::cout << "Here are the airports in " << city << std::endl;
    // Results is a 2D vector of mysqlpp::String objects.
    // Print the results.
    std::cout << "ID\tName\tCode\tCity\tCountry" << std::endl;
    for (const auto& row : result) {
        for (const auto& col : row) {
            std::cout << col << "\t";
        }
        std::cout << std::endl;
    }
}

/**
 * @brief Summarizing of airports data using (an) aggregate function(s) with a selection criterion.
 *
 * @param myDB
 */
void menu3(mysqlpp::Connection myDB) {
    mysqlpp::Query query = myDB.query();
    std::cout << "This code will output the number of airports to in each "
    << "city in the country you input\n";
    std::cout << "(Maximum 10 lines)\n";
    std::cout << "------\n";
    std::cout << "Example:\nVietnam\nGermany\nUkraine\nSpain\n";
    std::cout << "------\n";

    std::cout << "Enter the country you want >>" << std::endl;
    std::string country;
    std::cin >> country;
    query << "SELECT Country, City, COUNT(*) FROM Airports GROUP BY "
    << "City HAVING Country = '" << country << "' LIMIT 10;";

    query.parse();
    mysqlpp::StoreQueryResult result = query.store();

    // Results is a 2D vector of mysqlpp::String objects.
    // Print the results.
    std::cout << "Country\tCity\tCount" << std::endl;
    for (const auto& row : result) {
        for (const auto& col : row) {
            std::cout << col << "\t";
        }
        std::cout << std::endl;
    }
}

/**
 * @brief Summarizing airport data using grouping.
 *
 * @param myDB
 */
void menu4(mysqlpp::Connection myDB) {
  mysqlpp::Query query = myDB.query();
  std::cout << "This code will output the number of airports to group by "
  << "the category you input\n";
  std::cout << "(Maximum 10 lines)\n";
  std::cout << "Please choose from one of these options. "
   << "Please type correctly\n";
  std::cout << "------\n";
  std::cout << "Options:\nCountry\nCode\nLongtitude\nLatitude\nAltitude\n";
  std::cout << "Timezone\nDST\nTz\n";
  std::cout << "------\n";
  std::cout << "Enter the category you want: >>" << std::endl;
  std::string category;
  std::cin >> category;
  query << "SELECT " << category << ", COUNT(*) FROM Airports GROUP BY "
  << category << " ORDER BY " << category << " LIMIT 15;";

  query.parse();
  mysqlpp::StoreQueryResult result = query.store();

  // Results is a 2D vector of mysqlpp::String objects.
  // Print the results.
  std::cout << category << "\tCOUNT(*)\t" << std::endl;
  for (const auto& row : result) {
      for (const auto& col : row) {
          std::cout << col << "\t";
      }
      std::cout << std::endl;
  }
}

/**
 * @brief Print the Option Menu.
 *
 */
void printMenu() {
    // Function to print the option menu
    std::cout << "Option. Enter the appropriate number to choose the option:\n";
    std::cout << "1/ Querry using 1 criteria.\n";
    std::cout << "2/ Querry using 2 criteria.\n";
    std::cout << "3/ Querry using COUNT function.\n";
    std::cout << "4/ Querry using GROUP BY function.\n";
    std::cout << "5/ Exit.\n";
}
