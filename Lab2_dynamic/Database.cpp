#include "Database.h"

Database::Database()
{
	currentPolicy = minPolicy;
}

InsurancePolicy& Database::addNewPolicy(std::tuple<int, int, int> startDate, std::tuple<int, int, int> endDate, double cost, double payout, int type, bool status, int client, int employee)
{
	std::string errors = "";
	InsurancePolicy* policy = new InsurancePolicy();
	
	policy->setPolicyNumber(currentPolicy);	

	if (std::get<0>(startDate) > 31 || std::get<0>(startDate) < 1 || std::get<1>(startDate) > 12 || std::get<1>(startDate) < 1 || std::get<2>(startDate) < 1970 || std::get<2>(startDate) > 2050)
		errors += "startDate: invalid value\n";
	if (std::get<0>(endDate) > 31 || std::get<0>(endDate) < 1 || std::get<1>(endDate) > 12 || std::get<1>(endDate) < 1 || std::get<2>(endDate) < 1970 || std::get<2>(endDate) > 2050)
		errors += "endDate: invalid value\n";
	if (cost<0)
		errors += "cost: invalid value\n";
	if (payout<0)
		errors += "payout: invalid value\n";

	if (errors != "")
	{
		delete policy;
		throw errors;
	}		

	policy->setStartDate(std::get<0>(startDate), std::get<1>(startDate), std::get<2>(startDate));
	policy->setEndDate(std::get<0>(endDate), std::get<1>(endDate), std::get<2>(endDate));
	policy->setCost(cost);
	policy->setPayoutAmount(payout);
	policy->setPolicyTypeCode(type);
	policy->setPaymentStatus(status);
	policy->setClientCode(client);
	policy->setEmployeeCode(employee);

	data.push_back(policy);
	currentPolicy++;
	return *policy;
}

InsurancePolicy& Database::getPolicyByNumber(int number)
{
	for (int i = 0; i < data.size(); i++)
		if (data[i]->getPolicyNumber() == number)
			return *(data[i]);
	throw std::string("The policy cannot be found");
}

std::vector<InsurancePolicy*> Database::getPolicyByClient(int code)
{
	std::vector<InsurancePolicy*> vec;
	for (int i = 0; i < data.size(); i++)
		if (data[i]->getClientCode() == code)
			vec.push_back(data[i]);
	if (vec.size() < 1)
		throw std::string("The policy cannot be found");

	return vec;
}

void Database::displayData()
{
	std::cout << std::right
		<< std::setw(5) << "Num" << ' '
		<< std::setw(10) << "Start" << ' '
		<< std::setw(10) << "End" << ' '
		<< std::setw(8) << "Cost" << ' '
		<< std::setw(8) << "Payout" << " "
		<< std::setw(5) << "Type" << ' '
		<< std::setw(7) << "Status" << ' '
		<< std::setw(7) << "Expired" << ' '
		<< std::setw(6) << "Client" << ' '
		<< std::setw(8) << "Employee" << std::endl;
	for (int i = 0; i < data.size(); i++)
	{
		data[i]->consoleOutput();
		std::cout << std::endl;
	}
}

