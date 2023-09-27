#pragma once

#include "Database.h"

void Interface(Database& database);
int selection();
void addNewInsurance(Database& database);
void printInsuranceByNumber(Database& database);
void printInsuranceByClient(Database& database);
void setDefaultValues(Database& database);
void printDaysLeft(Database& database);
