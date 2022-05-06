// Copyright by Jenn Pham & Nhut Do
// May 5, 2022
// Header file for functions.cpp

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#define MYSQLPP_MYSQL_HEADERS_BURIED
#include <mysql++/mysql++.h>

#include <iostream>

void printMenu();
void menu1(mysqlpp::Connection myDB);
void menu2(mysqlpp::Connection myDB);
void menu3(mysqlpp::Connection myDB);
void menu4(mysqlpp::Connection myDB);

#endif  // FUNCTIONS_H_
