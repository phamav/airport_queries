// Copyright by Jenn Pham & Nhut Do
// May 5, 2022
// Header file for functions.cpp

#define MYSQLPP_MYSQL_HEADERS_BURIED
#include <mysql++/mysql++.h>
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>

void printMenu();
void menu1(mysqlpp::Connection myDB);
void menu2(mysqlpp::Connection myDB);
void menu3(mysqlpp::Connection myDB);
void menu4(mysqlpp::Connection myDB);

#endif
