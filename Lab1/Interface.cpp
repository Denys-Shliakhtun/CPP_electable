#include "Interface.h"

void Interface(Database& database)
{
	bool done = false;
	while (!done)
	{
		int select = selection();
		try
		{
			switch (select) {
			case 1:
				addNewInsurance(database);
				break;
			case 2:
				printInsuranceByNumber(database);
				break;
			case 3:
				printInsuranceByClient(database);
				break;
			case 4:
				std::cout << std::endl;
				database.displayData();
				break;
			case 5:
				setDefaultValues(database);
				break;
			case 6:
				printDaysLeft(database);
				break;
			case 0:
				done = true;
				break;
			default:
				throw std::string("Interface: invalid code");
				break;
			}
		}
		catch (const std::string& str)
		{
			std::cout << std::endl << "Error:" << std::endl << str << std::endl;
		}
	}
}

int selection()
{
	std::cout << "\nInsurance Policy Database\n"
		<< "-------------------------\n"
		<< "1) Add a new insurance policy\n"
		<< "2) Find an insurance policy by number\n"
		<< "3) Find insurance policies by client\n"
		<< "4) Display the database\n"
		<< "5) Set default values to database\n"
		<< "6) Get days left for insurance\n"
		<< "0) Exit the programme\n"
		<< "Enter code: ";
	int a;
	std::cin >> a;
	return a;
}

void addNewInsurance(Database& database)
{
	int startDay, startMonth, startYear, endDay, endMonth, endYear, type, client, employee;
	double cost, payout;
	bool status;
	std::cout << "\nAdding new policy\n"
		<< "Start date, day: ";
	std::cin >> startDay;
	
	std::cout << "Start date, month: ";
	std::cin >> startMonth;
	
	std::cout << "Start date, year: ";
	std::cin >> startYear;

	std::cout << "End date, day: ";
	std::cin >> endDay;

	std::cout << "End date, month: ";
	std::cin >> endMonth;

	std::cout << "End date, year: ";
	std::cin >> endYear;

	std::cout << "Cost: ";
	std::cin >> cost;
	
	std::cout << "Payout: ";
	std::cin >> payout;

	std::cout << "Type: ";
	std::cin >> type;

	std::cout << "Status: ";
	std::cin >> status;
	std::cin.clear();

	std::cout << "Client: ";
	std::cin >> client;

	std::cout << "Employee: ";
	std::cin >> employee;
	
	database.addNewPolicy(
		std::tuple(startDay, startMonth, startYear),
		std::tuple(endDay, endMonth, endYear), 
		cost, payout, type, status, client, employee);
}

void printTableHeader()
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
}

void printInsuranceByNumber(Database& database)
{
	int num;
	
	std::cout << "\nEnter the number of insurance: ";
	std::cin >> num;

	InsurancePolicy ins = database.getPolicyByNumber(num);
	
	printTableHeader();
	ins.consoleOutput();
}

void printInsuranceByClient(Database& database)
{
	int num;

	std::cout << "\nEnter the code of client: ";
	std::cin >> num;

	std::vector<InsurancePolicy*> ins = database.getPolicyByClient(num);

	printTableHeader();
	for (int i = 0; i < ins.size(); i++)
	{
		ins[i]->consoleOutput();
		std::cout << std::endl;
	}
		
	std::cout << std::endl;
}

void printDaysLeft(Database& database)
{
	int num;

	std::cout << "\nEnter the number of insurance: ";
	std::cin >> num;

	InsurancePolicy ins = database.getPolicyByNumber(num);

	std::cout << "Days left: " << ins.getDaysLeft() << std::endl;
}

void setDefaultValues(Database& database)
{
	database.addNewPolicy(
		std::tuple(10, 2, 2004),
		std::tuple(12, 8, 2006),
		100, 300, 23, true, 34, 45);

	database.addNewPolicy(
		std::tuple(5, 11, 2008),
		std::tuple(3, 4, 2010),
		150, 250, 15, false, 21, 55);

	database.addNewPolicy(
		std::tuple(7, 6, 2012),
		std::tuple(9, 1, 2014),
		200, 400, 30, true, 67, 12);

	database.addNewPolicy(
		std::tuple(1, 9, 2016),
		std::tuple(4, 12, 2017),
		120, 280, 18, false, 89, 34);

	database.addNewPolicy(
		std::tuple(3, 5, 2019),
		std::tuple(8, 10, 2020),
		180, 350, 25, true, 45, 77);

	database.addNewPolicy(
		std::tuple(11, 7, 2022),
		std::tuple(6, 3, 2023),
		250, 450, 40, false, 21, 55);

	database.addNewPolicy(
		std::tuple(2, 4, 2007),
		std::tuple(15, 9, 2009),
		300, 500, 35, true, 67, 12);

	database.addNewPolicy(
		std::tuple(8, 12, 2011),
		std::tuple(10, 6, 2013),
		170, 320, 20, false, 89, 34);

	database.addNewPolicy(
		std::tuple(6, 8, 2015),
		std::tuple(13, 11, 2018),
		220, 380, 28, true, 45, 77);
	/*
	database.addNewPolicy(
		std::tuple(startDay, startMonth, startYear),
		std::tuple(endDay, endMonth, endYear),
		cost, payout, type, status, client, employee);
	*/
}