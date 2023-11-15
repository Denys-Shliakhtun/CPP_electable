#include "mainwindow.h"
#include <QLabel>
#include <QMessageBox>
#include <QFileDialog>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("Insurance Policies");
    setGeometry(100, 100, 540, 680);
    setMinimumSize(340, 610);

    int i = 0;

    QLabel *policyNumberLabel = new QLabel(this);
    policyNumberLabel->setText("Number of policy");
    policyNumberLabel->setGeometry(12, 10 + i*60, 200, 20);

    policyNumberField = new QLineEdit(this);
    policyNumberField->setGeometry(10, 30 + i*60, 200, 20);
    i++;

    QLabel *startDateLabel = new QLabel(this);
    startDateLabel->setText("Start date");
    startDateLabel->setGeometry(12, 10 + i*60, 200, 20);

    startDateField = new QLineEdit(this);
    startDateField->setGeometry(10, 30 + i * 60, 200, 20);
    i++;

    QLabel *endDateLabel = new QLabel(this);
    endDateLabel->setText("End date");
    endDateLabel->setGeometry(12, 10 + i*60, 200, 20);

    endDateField = new QLineEdit(this);
    endDateField->setGeometry(10, 30 + i * 60, 200, 20);
    i++;

    QLabel *costLabel = new QLabel(this);
    costLabel->setText("Cost");
    costLabel->setGeometry(12, 10 + i*60, 200, 20);

    costField = new QLineEdit(this);
    costField->setGeometry(10, 30 + i * 60, 200, 20);
    i++;

    QLabel *payoutAmountLabel = new QLabel(this);
    payoutAmountLabel->setText("Payout");
    payoutAmountLabel->setGeometry(12, 10 + i*60, 200, 20);

    payoutAmountField = new QLineEdit(this);
    payoutAmountField->setGeometry(10, 30 + i * 60, 200, 20);
    i++;

    QLabel *policyTypeCodeLabel = new QLabel(this);
    policyTypeCodeLabel->setText("Type code");
    policyTypeCodeLabel->setGeometry(12, 10 + i*60, 200, 20);

    policyTypeCodeField = new QLineEdit(this);
    policyTypeCodeField->setGeometry(10, 30 + i * 60, 200, 20);
    i++;

    QLabel *paymentStatusLabel = new QLabel(this);
    paymentStatusLabel->setText("Payment status");
    paymentStatusLabel->setGeometry(12, 10 + i*60, 200, 20);

    paymentStatusField = new QLineEdit(this);
    paymentStatusField->setGeometry(10, 30 + i * 60, 200, 20);
    i++;

    QLabel *clientCodeLabel = new QLabel(this);
    clientCodeLabel->setText("Client code");
    clientCodeLabel->setGeometry(12, 10 + i*60, 200, 20);

    clientCodeField = new QLineEdit(this);
    clientCodeField->setGeometry(10, 30 + i * 60, 200, 20);
    i++;

    QLabel *employeeCodeLabel = new QLabel(this);
    employeeCodeLabel->setText("Employee code");
    employeeCodeLabel->setGeometry(12, 10 + i*60, 200, 20);

    employeeCodeField = new QLineEdit(this);
    employeeCodeField->setGeometry(10, 30 + i * 60, 200, 20);
    i++;

    QLabel *chooseCommandLabel = new QLabel(this);
    chooseCommandLabel->setText("Choose command to execute");
    chooseCommandLabel->setGeometry(12, 30 + i*60, 200, 20);

    commandChoice = new QComboBox(this);
    commandChoice->setGeometry(10, 50 + i*60, 200, 20);
    commandChoice->addItems(*new QList<QString>(
        {"Print all policies",
         "Add new insurance",
         "Print insurance by number",
         "Print insurance by client",
         "Add default values",
         "Print days left by number",
         "Disable insurance",
         "Add insurance cost",
         "Save file",
         "Open file"}));

    outputField = new QTextEdit(this);
    outputField->setGeometry(230, 10, 300, 610);
    outputField->setReadOnly(true);

    QPushButton *executeButton = new QPushButton(this);
    executeButton->setGeometry(430, 635, 70, 30);
    executeButton->setText("Execute");
    connect(executeButton, SIGNAL(released()), this, SLOT (handleButton()));

}

MainWindow::~MainWindow()
{
}

void MainWindow::handleButton()
{
    int select = commandChoice->currentIndex();
    try {
        switch (select)
        {
        case 0:
            printAllPolicies();
            break;
        case 1:
            addNewInsurance();
            break;
        case 2:
            printInsuranceByNumber();
            break;
        case 3:
            printInsuranceByClient();
            break;
        case 4:
            setDefaultValues();
            break;
        case 5:
            printDaysLeftByNumber();
            break;
        case 6:
            disableInsurance();
            break;
        case 7:
            addInsuranceCost();
            break;
        case 8:
            saveFile();
            break;
        case 9:
            openFile();
            break;
        }
        QMessageBox messageBox;
        messageBox.information(0,"Information","Task completed successfully");
        messageBox.setFixedSize(500,200);
    }
    catch (const std::string& str)
    {
        QMessageBox messageBox;
        messageBox.critical(0,"Error",QString::fromStdString(str));
        messageBox.setFixedSize(500,200);
    }

}

std::tuple<int, int, int>getDateFromString(QString str)
{
    int a, b, c;
    std::istringstream dateStream(str.toStdString());
    char dot;
    dateStream >> a >> dot >> b >> dot >> c;
    return std::tuple(a, b, c);
}

void MainWindow::printAllPolicies()
{
    outputField->setText(QString::fromStdString(database.toString()));
}

void MainWindow::addNewInsurance()
{
    database.addNewPolicy(
        getDateFromString(startDateField->text()),
        getDateFromString(endDateField->text()),
        costField->text().toDouble(),
        payoutAmountField->text().toDouble(),
        policyTypeCodeField->text().toInt(),
        paymentStatusField->text() == "True" ? true : false,
        clientCodeField->text().toInt(),
        employeeCodeField->text().toInt());
    printAllPolicies();
}

void MainWindow::printInsuranceByNumber()
{
    outputField->setText(QString::fromStdString(database.getPolicyByNumber(policyNumberField->text().toInt()).toString()));
}

void MainWindow::printInsuranceByClient()
{
    outputField->setText(QString::fromStdString(database.getPolicyByClient(clientCodeField->text().toInt())[0]->toString()));
}

void MainWindow::setDefaultValues()
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

    printAllPolicies();
}

void MainWindow::printDaysLeftByNumber()
{
    outputField->setText(
        QString::fromStdString(
            database.getPolicyByNumber(policyNumberField->text().toInt()).toString()
            + "Days left: "
            + std::to_string(
                database.getPolicyByNumber(policyNumberField->text().toInt()).getDaysLeft()
                )
            )
        );
}

void MainWindow::disableInsurance()
{
    database.getPolicyByNumber(policyNumberField->text().toInt()).setIsExpired();
    printInsuranceByNumber();
}

void MainWindow::addInsuranceCost()
{
    double currentCost = database.getPolicyByNumber(policyNumberField->text().toInt()).getCost();
    database.getPolicyByNumber(policyNumberField->text().toInt()).setCost(currentCost+costField->text().toDouble());
    printInsuranceByNumber();
}

void MainWindow::saveFile()
{
    QString path = QFileDialog::getSaveFileName(this, "Save Text File", "f:\\university\\V semester\\cpp\\Lab3\\temp", "Text files(*.txt);;All files (*.*)");
    if(!path.isEmpty())
        database.saveInFile(path.toStdString());
}

void MainWindow::openFile()
{
    QString path = QFileDialog::getOpenFileName(this, "Open Text File", "f:\\university\\V semester\\cpp\\Lab3\\temp", "Text files(*.txt);;All files (*.*)");
    if(!path.isEmpty())
        database.readFromFile(path.toStdString());
    printAllPolicies();
}

