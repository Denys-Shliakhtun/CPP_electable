#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Database.h"

#include <QMainWindow>

#include <QLineEdit>
#include <QPushButton>
#include <QTextEdit>
#include <QComboBox>

class MainWindow : public QMainWindow
{
    Q_OBJECT
    Database database;


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



private slots:
    void handleButton();

private:
    void printAllPolicies();
    void addNewInsurance();
    void printInsuranceByNumber();
    void printInsuranceByClient();
    void setDefaultValues();
    void printDaysLeftByNumber();
    void disableInsurance();
    void addInsuranceCost();
    void saveFile();
    void openFile();

    QComboBox *commandChoice;
    QTextEdit *outputField;

    QLineEdit *policyNumberField;
    QLineEdit *startDateField;
    QLineEdit *endDateField;
    QLineEdit *costField;
    QLineEdit *payoutAmountField;
    QLineEdit *policyTypeCodeField;
    QLineEdit *paymentStatusField;
    QLineEdit *clientCodeField;
    QLineEdit *employeeCodeField;
};
#endif // MAINWINDOW_H
