#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
#include <ctime>

using namespace std;

string adminUsername;
string adminPassword;
string employeeUsername;
string employeePassword;
int employeeAge;
string customerUsername;
string customerPassword;
int customerAge;
double customerDeposit;
double customerWithdrawal;
double customerAccountBalance;
double dollarRate;
double yenRate;
double poundRate;
double euroRate;
int customerAccountNumber;
int senderAccountNumber;
int receiverAccountNumber;
double receiverAccountBalance;
bool isTransactionSuccessful;
bool isDepositSuccessful;
bool isWidthrawalSuccessful;
bool isLoanApplicationSuccessful;
bool isInvestmentSuccessful;
int loanId;
int loanAmount;
int loanDuration;
string loanStatus;
int interestRate;

class Admin {
    

};

class Employee {

};

class Customer {

};

void adminlogin() {

}

void adminSignUp() {

}

void adminForgotPassword() {

}
//horizontal dashes are 62 in number
void adminMenu () {
    int adminMenuChoice;
    cout <<"--------------------------------------------------------------"<< endl;
    cout <<"|                WELCOME TO MTU SITA BANK SYSTEM             |"<< endl;
    cout <<"|                                                            |"<< endl;
    cout <<"|                  --------------------------                |"<< endl;
    cout <<"|                  ********Admin Menu********                |"<< endl;
    cout <<"|                  *------------------------*                |"<< endl;
    cout <<"|                  * 1. Login               *                |"<< endl;
    cout <<"|                  * 2. Sign up             *                |"<< endl;
    cout <<"|                  * 3. Forgot password     *                |"<< endl;
    cout <<"|                  * 4. Exit                *                |"<< endl;
    cout <<"|                  *------------------------*                |"<< endl;
    cout <<"|                  * Enter your choice: "; cin >> adminMenuChoice;

    cout <<"|                  *------------------------*                |"<< endl;
    cout <<"|                                                            |"<< endl;
    cout <<"--------------------------------------------------------------"<< endl;

    switch (adminMenuChoice) {
        case 1:
            adminlogin();
        case 2:
            adminSignUp();
        case 3:
            adminForgotPassword();
        case 4:
            break;
        default:
            cout << "Enter a valid choice";
            adminMenu();
    }

}

void employeeMenu() {

}

void customerMenu() {

}

int main() {
    adminMenu();
    
    return 0;
}
