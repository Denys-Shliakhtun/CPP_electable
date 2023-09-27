#pragma once

#include <iostream>
#include <iomanip>
#include <ctime>
#include <iostream>

class InsurancePolicy {
    // operations
public:
    InsurancePolicy();
    int getDaysLeft();
    bool isPolicyExpired();
    void consoleOutput();

    // variables
private:
    int policyNumber;
    tm startDate;
    tm endDate;
    double cost;
    double payoutAmount;
    int policyTypeCode;
    bool paymentStatus;
    bool isExpired = false;
    int clientCode;
    int employeeCode;

    // getters and setters
public:
    void setPolicyNumber(int);
    int getPolicyNumber();
    void setStartDate(int day, int month, int year);
    tm getStartDate();
    void setEndDate(int day, int month, int year);
    tm getEndDate();
    void setCost(double);
    double getCost();
    void setPayoutAmount(double);
    double getPayoutAmount();
    void setPolicyTypeCode(int);
    int getPolicyTypeCode();
    void setPaymentStatus(bool);
    bool getPaymentStatus();
    void setClientCode(int);
    int getClientCode();
    void setEmployeeCode(int);
    int getEmployeeCode();
};
