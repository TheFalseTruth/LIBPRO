#pragma once
#include "iostream"
#include "string"

using namespace std;

typedef struct {
	unsigned int year;
	short day, month;
} Date;

typedef struct {
	string account_name;
	string password;
	char status;
	short role;
} Account;
 
