#include "InsurancePolicy.h"

InsurancePolicy::InsurancePolicy() {
    startDate = tm();
    endDate = tm();
}

int InsurancePolicy::getDaysLeft() {
    return !isPolicyExpired() ? difftime(mktime(&endDate), time(NULL))/60/60/24 : 0;
}

void InsurancePolicy::consoleOutput() {
    std::cout << std::right
        << std::setw(5) << policyNumber << ' '
        << std::setfill('0')
        << std::setw(2) << startDate.tm_mday << '.' << std::setw(2) << startDate.tm_mon << '.' << startDate.tm_year + 1900 << ' '
        << std::setw(2) << endDate.tm_mday << '.' << std::setw(2) << endDate.tm_mon << '.' << endDate.tm_year + 1900 << ' '
        << std::setfill(' ')
        << std::setw(7) << cost << "$ "
        << std::setw(7) << payoutAmount << "$ "
        << std::setw(5) << policyTypeCode << ' '
        << std::setw(7) << (paymentStatus ? "Yes" : "No") << ' '
        << std::setw(7) << (isPolicyExpired() ? "Yes" : "No") << ' '
        << std::setw(6) << clientCode << ' '
        << std::setw(8) << employeeCode;
}

bool InsurancePolicy::isPolicyExpired()
{
    if (isExpired)
        return isExpired;

    if (mktime(&endDate) < time(NULL))
        isExpired = true;
    
    return isExpired;
}

void InsurancePolicy::setPolicyNumber(int number) {
    policyNumber = number;
}

int InsurancePolicy::getPolicyNumber() {
    return policyNumber;
}

void InsurancePolicy::setStartDate(int day, int month, int year) {
    startDate = tm();
    startDate.tm_year = year - 1900;
    startDate.tm_mon = month;
    startDate.tm_mday = day;
}

tm InsurancePolicy::getStartDate() {
    return startDate;
}

void InsurancePolicy::setEndDate(int day, int month, int year) {
    endDate = tm();
    endDate.tm_year = year - 1900;
    endDate.tm_mon = month;
    endDate.tm_mday = day;
}

tm InsurancePolicy::getEndDate() {
    return endDate;
}

void InsurancePolicy::setCost(double value) {
    cost = value;
}

double InsurancePolicy::getCost() {
    return cost;
}

void InsurancePolicy::setPayoutAmount(double value) {
    payoutAmount = value;
}

double InsurancePolicy::getPayoutAmount() {
    return payoutAmount;
}

void InsurancePolicy::setPolicyTypeCode(int code) {
    policyTypeCode = code;
}

int InsurancePolicy::getPolicyTypeCode() {
    return policyTypeCode;
}

void InsurancePolicy::setPaymentStatus(bool status) {
    paymentStatus = status;
}

bool InsurancePolicy::getPaymentStatus() {
    return paymentStatus;
}

void InsurancePolicy::setClientCode(int code) {
    clientCode = code;
}

int InsurancePolicy::getClientCode() {
    return clientCode;
}

void InsurancePolicy::setEmployeeCode(int code) {
    employeeCode = code;
}

int InsurancePolicy::getEmployeeCode() {
    return employeeCode;
}

void InsurancePolicy::setIsExpired() {
    isExpired = true;
}