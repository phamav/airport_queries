// Copyright by Jenn Pham and Nhut Do
// May 5, 2022
// Functions file for reading and writing databases.

#include <iostream>

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

    query << "select * from Airports where City = " << city << " LIMIT 5;";

    query.parse();  // check to ensure query is correct
    // Run the query and get stored results
    mysqlpp::StoreQueryResult result = query.store();

    std::cout << "Here are the airports in " << city << std::endl;
    // Results is a 2D vector of mysqlpp::String objects.
    // Print the results.
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

}
