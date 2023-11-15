#include "InsurancePolicy.h"

InsurancePolicy::InsurancePolicy() {
    startDate = tm();
    endDate = tm();
}

int InsurancePolicy::getDaysLeft() {
    return !isPolicyExpired() ? difftime(mktime(&endDate), time(NULL))/60/60/24 : 0;
}

std::string InsurancePolicy::toString() {
    return
        "Policy number: " + std::to_string(policyNumber) + '\n'
        + "Start date: " + std::string((startDate.tm_mday>9?0:1), '0').append(std::to_string(startDate.tm_mday)) + '.'
        + std::string((startDate.tm_mon>9?0:1), '0').append(std::to_string(startDate.tm_mon))  + '.'
        + std::to_string(startDate.tm_year + 1900) + '\n'
        + "End date: " + std::string((endDate.tm_mday>9?0:1), '0').append(std::to_string(endDate.tm_mday)) + '.'
        + std::string((endDate.tm_mon>9?0:1), '0').append(std::to_string(endDate.tm_mon))  + '.'
        + std::to_string(endDate.tm_year + 1900) + '\n'
        + "Cost: " + std::to_string(cost) + "$\n"
        + "Payout amount: " + std::to_string(payoutAmount) + "$\n"
        + "Type: " + std::to_string(policyTypeCode) + '\n'
        + "Status: " + (paymentStatus ? "Yes" : "No") + '\n'
        + "Expired: " + (isPolicyExpired() ? "Yes" : "No") + '\n'
        + "Client: " + std::to_string(clientCode) + '\n'
        + "Employee: " + std::to_string(employeeCode) + '\n';
}

void InsurancePolicy::fromString(std::string str)
{
    size_t startPos = 0;
    size_t endPos = str.find('\n');
    int year;

    std::string line = str.substr(startPos, endPos - startPos);

    policyNumber = std::stoi(line.substr(line.find(": ") + 2));

    startPos = endPos + 1;
    endPos = str.find('\n', startPos);
    line = str.substr(startPos, endPos - startPos);

    std::istringstream dateStream(line.substr(line.find(": ") + 2));
    char dot;
    dateStream >> startDate.tm_mday >> dot >> startDate.tm_mon >> dot >> year;
    startDate.tm_year = year - 1900;

    startPos = endPos + 1;
    endPos = str.find('\n', startPos);
    line = str.substr(startPos, endPos - startPos);

    std::istringstream dateStream2(line.substr(line.find(": ") + 2));
    dateStream2 >> endDate.tm_mday >> dot >> endDate.tm_mon >> dot >> year;
    endDate.tm_year = year - 1900;

    startPos = endPos + 1;
    endPos = str.find('\n', startPos);
    line = str.substr(startPos, endPos - startPos);

    cost = std::stod(line.substr(line.find(": ") + 2));

    startPos = endPos + 1;
    endPos = str.find('\n', startPos);
    line = str.substr(startPos, endPos - startPos);

    payoutAmount = std::stod(line.substr(line.find(": ") + 2));

    startPos = endPos + 1;
    endPos = str.find('\n', startPos);
    line = str.substr(startPos, endPos - startPos);

    policyTypeCode = std::stoi(line.substr(line.find(": ") + 2));

    startPos = endPos + 1;
    endPos = str.find('\n', startPos);
    line = str.substr(startPos, endPos - startPos);

    paymentStatus = (line.substr(line.find(": ") + 2) == "Yes");

    startPos = endPos + 1;
    endPos = str.find('\n', startPos);
    line = str.substr(startPos, endPos - startPos);

    isExpired = (line.substr(line.find(": ") + 2) == "Yes");

    startPos = endPos + 1;
    endPos = str.find('\n', startPos);
    line = str.substr(startPos, endPos - startPos);

    clientCode = std::stoi(line.substr(line.find(": ") + 2));

    startPos = endPos + 1;
    endPos = str.find('\n', startPos);
    line = str.substr(startPos, endPos - startPos);

    employeeCode = std::stoi(line.substr(line.find(": ") + 2));

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
