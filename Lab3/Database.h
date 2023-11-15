#pragma once

#include <vector>
#include "InsurancePolicy.h"

class Database {
public:
	Database();
	
	//operations
	InsurancePolicy& addNewPolicy(std::tuple<int, int, int> startDate, std::tuple<int, int, int> endDate, double cost, double payout, int type, bool status, int client, int employee);
	InsurancePolicy& getPolicyByNumber(int);
	std::vector<InsurancePolicy*> getPolicyByClient(int);
    bool saveInFile(std::string);
    bool readFromFile(std::string);
    std::string toString();


private:
	//variables
	static const int minPolicy = 100;
	int currentPolicy;
	std::vector<InsurancePolicy*> data;
};
