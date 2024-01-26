#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
#include <ctime>
#include <fstream>
#include <sstream>


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
int actionNumber;
int choice;
bool validCredentials = false;


struct Credentials {
    string userName;
    string passWord;
};

/*
Hi guys I've created this backbone based on what i rember that we were to implement, i might have excluded other features but will just add on this foundation
Don't get scared of the code everything is just simple.
WHAT I HAVE ADDED
    -adminsCredentials.txt file - this will be storing admins passwords and username in this format "adminusername,adminpassword"
    -customerCredentials.txt file- """"
    -employeesCredentials.txr file - """"

N/B:/-
    the major throwback of this code now is that when a customer share common username and password as admins or employees it might give them previleges that they dont deserve
    this can be adressed by storing the files in separate folders

This code only serves as a foundation code and we should be building on top of it,
We can start by working on the functions on the admin accout side/ then add something that i might have forgoten to add on the menu (add function of admin to add other admins and employees,freeze acouts etc)
We can also improve the user interface, i had limited time so i could not enhance it
*/
void signup() {
    Credentials newUser;
    system("cls");
    cout <<"\t\t\t============ MTU SITA BANK SYSTEM ==============\n";
    cout <<"\t\t\t************************************************\n";
    cout <<"\t\t\t------------------SIGN UP-----------------------\n";
    cout << "\t\t\t\tEnter a username: ";
    cin >> newUser.userName;
    cout << "\t\t\t\tEnter a password: ";
    cin >> newUser.passWord;

    ofstream credentialsFile("customerCredentials.txt", ios::app);
    if (credentialsFile.is_open()) {
        credentialsFile << newUser.userName << "," << newUser.passWord << endl;
        credentialsFile.close();
        cout << "\t\t\tSign up successful!" << endl;
    } else {
        cout << "\t\t\tError: could not open credentials file" << endl;
    }
}

bool login() {
    Credentials loginUser;
    system("cls");
    cout <<"\t\t\t============ MTU SITA BANK SYSTEM ==============\n";
    cout <<"\t\t\t************************************************\n";
    cout <<"\t\t\t-------------------LOGIN------------------------\n";
    cout << "\t\t\t\tEnter your username: ";
    cin >> loginUser.userName;
    cout << "\t\t\t\tEnter your password: ";
    cin >> loginUser.passWord;

    ifstream credentialsFile("customerCredentials.txt");
    if (credentialsFile.is_open()) {
        string line;
        while (getline(credentialsFile, line)) {
            // The line should be in the format "username,password"
            // so we can use the comma as a delimiter to extract the
            // username and password
            size_t commaPos = line.find(',');
            string username = line.substr(0, commaPos);
            string password = line.substr(commaPos + 1);

            if (loginUser.userName == username && loginUser.passWord == password) {
                // If we found a match, return true
                credentialsFile.close();
                return true;
            }
        }
        // If we didn't find a match, return false
        credentialsFile.close();
        return false;
    } else {
        cout << "\t\t\t\t\tError: could not open credentials file" << endl;
        return false;
    }
}


class Account {
public:
    virtual void displayMenu() = 0;
    virtual void executeAction(int actionNumber) = 0;
};

class Admin : public Account {
public:
    void displayMenu() override {
        cout << "\t\t\t------------ ADMIN MENU --------------\n";
        cout << "\t\t\t1. View all users\n";
        cout << "\t\t\t2. Delete a user\n";
        cout << "\t\t\t3. Add funds to account\n";
        cout << "\t\t\t4. Withdraw funds from account\n";
        cout << "\t\t\t5. Transfer funds between accounts\n";
        cout << "\t\t\t6. Log out\n";
        cout << "\t\t\tPlease enter an option: ";
    }

    void executeAction(int actionNumber) override {
        switch (actionNumber) {
            case 1:
                viewAllUsers();
                break;
            case 2:
                deleteUser();
                break;
            case 3:
                addFundsToAccount();
                break;
            case 4:
                withdrawFundsFromAccount();
                break;
            case 5:
                transferFundsBetweenAccounts();
                break;
            case 6:
                logOutLogic();
                break;
            default:
                cout << "\t\tInvalid option!\n";
                break;
        }
    }

private:
    void viewAllUsers() {
        // Display all registered users
        cout << "\t\tList of all users:\n";
    }

    void deleteUser() {
        // Implement logic for deleting a user
        cout << "\t\tDeleting a user...\n";
    }

    void addFundsToAccount() {
        // Implement logic for adding funds to an account
        cout << "\t\tAdding funds to an account...\n";
    }

    void withdrawFundsFromAccount() {
        // Implement logic for withdrawing funds from an account
        cout << "\t\tWithdrawing funds from an account...\n";
    }

    void transferFundsBetweenAccounts() {
        // Implement logic for transferring funds between two accounts
        cout << "\t\tTransferring funds...\n";
    }
    void logOutLogic() {
        // add the loging out logic here
        cout << "\t\tLogin out...\n";
    }
};

class Employee : public Account {
public:
    void displayMenu() override {
        cout << "\t\t\t------------- EMPLOYEE MENU ---------------\n";
        cout << "\t\t\t1. Change Account\n";
        cout << "\t\t\t2. Manage transaction\n";
        cout << "\t\t\t3. Deposit\n";
        cout << "\t\t\t4. Withdrow\n";
        cout << "\t\t\t5. Offer Loan\n";
        cout << "\t\t\t6. Log out\n";
        cout << "\t\t\tPlease enter an option: ";
    }

    void executeAction(int actionNumber) override {
        switch (actionNumber) {
            case 1:
                changeAcount();
                break;
            case 2:
                manageTransaction();
                break;
            case 3:
                withdraw();
                break;
            case 4:
                transferMoney();
                break;
            case 5:
                offerLoan();
                break;
            case 6:
                logOutLogic();
                break;
            default:
                cout << "\t\tInvalid option!\n";
                break;
        }
    }

private:
    void changeAcount() {
        // Display current balance
        cout << "\t\tChange account:\n";
    }

    void manageTransaction() {
        // Implement logic for depositing money into account
        cout << "\t\tManage Transactions...\n";
    }

    void withdraw() {
        // Implement logic for withdrawing money from account
        cout << "\t\tWithdrawing money...\n";
    }

    void transferMoney() {
        // Implement logic for transferring money between accounts
        cout << "\t\tTransferring money...\n";
    }

    void offerLoan() {
        // Implement logic for changing password
        cout << "\t\tChanging password...\n";
    }
    void logOutLogic() {
        // add the loging out logic here
        cout << "\t\tLogin out...\n";
    }
};

class Customer : public Account {
public:
    void displayMenu() override {
        cout << "\t\t\t------------- USER MENU ---------------\n";
        cout << "\t\t\t1. Check balance\n";
        cout << "\t\t\t2. Deposit money\n";
        cout << "\t\t\t3. Withdraw money\n";
        cout << "\t\t\t4. Transfer money\n";
        cout << "\t\t\t5. Change password\n";
        cout << "\t\t\t6. Log out\n";
        cout << "\t\t\tPlease enter an option: ";
    }

    void executeAction(int actionNumber) override {
        switch (actionNumber) {
            case 1:
                checkBalance();
                break;
            case 2:
                depositMoney();
                break;
            case 3:
                withdrawMoney();
                break;
            case 4:
                transferMoney();
                break;
            case 5:
                changePassword();
                break;
            case 6:
                logOutLogic();
                break;
            default:
                cout << "\t\tInvalid option!\n";
                break;
        }
    }

private:
    void checkBalance() {
        // Display current balance
        cout << "\t\tCurrent balance:\n";
    }

    void depositMoney() {
        // Implement logic for depositing money into account
        cout << "\t\tDepositing money...\n";
    }

    void withdrawMoney() {
        // Implement logic for withdrawing money from account
        cout << "\t\tWithdrawing money...\n";
    }

    void transferMoney() {
        // Implement logic for transferring money between accounts
        cout << "\t\tTransferring money...\n";
    }

    void changePassword() {
        // Implement logic for changing password
        cout << "\t\tChanging password...\n";
    }
    void logOutLogic() {
        // add the loging out logic here
        cout << "\t\tLogin out...\n";
    }
};

int main() {
    int choice;
    bool validCredentials = false;
    Credentials inputCredentials;
    Account* currentAccount;

    do {
        system("cls");
        cout <<"\t\t\t============ MTU SITA BANK SYSTEM ==============\n";
        cout <<"\t\t\t************************************************\n";
        cout <<"\t\t\t----------------LOGIN / SIGNUP------------------\n";
        cout <<"\t\t\t\t1. Sign Up\n";
        cout <<"\t\t\t\t2. Log In\n";
        cout <<"\t\t\t\t3. Exit\n";
        // add more option here
        cout <<"\t\t\tChose one of the options: ";
        cin >> choice;

        switch (choice) {
            case 1:
                signup();
                break;
            case 2:
                system("cls");
                cout <<"\t\t\t============ MTU SITA BANK SYSTEM ==============\n";
                cout <<"\t\t\t************************************************\n";
                cout <<"\t\t\t-------------------LOGIN------------------------\n";
                cout << "\t\t\t\tEnter your username: ";
                cin >> inputCredentials.userName;
                cout << "\t\t\t\tEnter your password: ";
                cin >> inputCredentials.passWord;

                ifstream credentialsFile("customerCredentials.txt");
                if (credentialsFile.is_open()) {
                    string line;
                    while (getline(credentialsFile, line)) {
                        // The line should be in the format "username,password"
                        // so we can use the comma as a delimiter to extract the
                        // username and password
                        size_t commaPos = line.find(',');
                        string username = line.substr(0, commaPos);
                        string password = line.substr(commaPos + 1);

                        if (inputCredentials.userName == username && inputCredentials.passWord == password) {
                            validCredentials = true;
                            currentAccount = new Customer();
                            break;
                        }
                    }
                    credentialsFile.close();

                    if (!validCredentials) {
                        ifstream adminsFile("adminsCredentials.txt");
                        if (adminsFile.is_open()) {
                            while (getline(adminsFile, line)) {
                                // The line should be in the format "username,password"
                                // so we can use the comma as a delimiter to extract the
                                // username and password
                                size_t commaPos = line.find(',');
                                string username = line.substr(0, commaPos);
                                string password = line.substr(commaPos + 1);

                                if (inputCredentials.userName == username && inputCredentials.passWord == password) {
                                    validCredentials = true;
                                    currentAccount = new Admin();
                                    break;
                                }
                            }
                            adminsFile.close();
                        }
                    }

                    if (!validCredentials) {
                        ifstream employeeFile("employeesCredentials.txt");
                        if (employeeFile.is_open()) {
                            while (getline(employeeFile, line)) {
                                size_t commaPos = line.find(',');
                                string username = line.substr(0, commaPos);
                                string password = line.substr(commaPos + 1);

                                if (inputCredentials.userName == username && inputCredentials.passWord == password) {
                                    validCredentials = true;
                                    currentAccount = new Employee();
                                    break;
                                }
                            }
                            employeeFile.close();
                        }
                    }

                    if (!validCredentials) {
                        cout << "\t\tInvalid username or password.\n";
                    }
                } else {
                    cout << "\t\tCould not open credentials file.\n";
                }
                break;
            //more cases here like about the bank etc

        }

        if (validCredentials) {
            int selectedOption;
            do {
                currentAccount->displayMenu();
                cin >> selectedOption;
                currentAccount->executeAction(selectedOption);
            } while (true);
        }

    } while (choice != 3);//make sure you change this when adding cases in the main menu

    cout << "\t----------------------------------------------------------------------------------------------------------\n";
    cout << "\t\t\t\t\tThank You For Using This System\t\t\t\t\t\t\n";
    cout << "\t----------------------------------------------------------------------------------------------------------\n";

    return 0;
}
