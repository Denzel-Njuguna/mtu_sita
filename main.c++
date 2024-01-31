
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

void logOut();
int main();


struct Credentials {
    string userName;
    string passWord;
};

/*
Hi guys I've created this backbone based on what I remember we were supposed to implement, I might have excluded other features but will just add on this foundation
Don't get scared of the code everything is just simple.
WHAT I HAVE ADDED
    -adminsCredentials.txt file - this will be storing admins passwords and username in this format "adminusername,adminpassword"
    -customerCredentials.txt file- """"
    -employeesCredentials.txr file - """"

N/B:/-
    the major throwback of this code now is that when a customer share common username and password as admins or employees it might give them previleges that they dont deserve
    this can be adressed by storing the files in separate folders

This code only serves as a foundation code and we should be building on top of it,
We can start by working on the functions on the admin account side/ then add something that I(Nerd) might have forgoten to add on the menu (add function of admin to add other admins and employees,freeze accounts etc)
We can also improve the user interface, I had limited time so I could not enhance it
*/
void signup() {
    Credentials newUser;
    system("cls");
    cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout <<"|                   MTU SITA BANK SYSTEM                     |\n";
    cout <<"|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
    cout <<"|   SIGN UP                                                  |\n";
    cout <<"|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
    cout <<"|   Enter a username: ";
    cin >> newUser.userName;
    cout <<"|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
    cout <<"|   Enter a password: ";
    cin >> newUser.passWord;
    cout <<"|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";

    ofstream credentialsFile("customerCredentials.txt", ios::app);
    if (credentialsFile.is_open()) {
        credentialsFile << newUser.userName << "," << newUser.passWord << endl;
        credentialsFile.close();
        cout << "\t\t\tSign up successful!" << endl;
    } else {
        cout << "\t\t\tError: could not open credentials file" << endl;
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
        cout <<"|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
        cout <<"|                        ADMIN MENU                          |\n";
        cout <<"|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
        cout <<"|   1. View all users                                        |\n";
        cout <<"|   2. Delete a user                                         |\n";
        cout <<"|   3. Add funds to account                                  |\n";
        cout <<"|   4. Withdraw funds from account                           |\n";
        cout <<"|   5. Transfer funds between accounts                       |\n";
        cout <<"|   6. Log out                                               |\n";
        cout <<"|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
        cout <<"|   Please enter an option: ";
        cout <<"|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
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
                logOut();
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
};

class Employee : public Account {
public:
    void displayMenu() override {
        cout <<"|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
        cout <<"|                       EMPLOYEE MENU                        |\n";
        cout <<"|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
        cout <<"|   1. Change Account                                        |\n";
        cout <<"|   2. Manage transaction                                    |\n";
        cout <<"|   3. Deposit                                               |\n";
        cout <<"|   4. Withdrow                                              |\n";
        cout <<"|   5. Offer Loan                                            |\n";
        cout <<"|   6. Log out                                               |\n";
        cout <<"|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
        cout <<"|   Please enter an option: \n";
        cout <<"|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
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
                logOut();
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
};

class Customer : public Account {
public:
    void displayMenu() override {
        //Brad
        cout <<"|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
        cout <<"|                       CUSTOMER MENU                        |\n";
        cout <<"|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
        cout <<"|   1. Check balance                                         |\n";
        cout <<"|   2. Create a bank account                                 |\n";
        cout <<"|   3. Delete account                                        |\n";
        cout <<"|   4. Deposit money                                         |\n";
        cout <<"|   5. Withdraw money                                        |\n";
        cout <<"|   6. Transfer money                                        |\n";
        cout <<"|   7. Change password                                       |\n";
        cout <<"|   8. Change currency                                       |\n";
        //Sam
        cout <<"|   9. Log out                                               |\n";
        cout <<"|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
        cout <<"|   Please enter an option: ";
    }

    void executeAction(int actionNumber) override {
        switch (actionNumber) {
            case 1:
            //Brad
                int checkBalance();
                break;
            case 2:
            //Crissy
                int createCustomerBankAccount();
                break;
            case 3:
            //Crissy
                int deleteCustomerBankAccount();
                break;
            case 4:
            //lazy Denzel
                int depositMoney();
                break;
            //lazy Denzel
            case 5:
                int withdrawMoney();
                break;
            case 6:
            //Samson
                int transferMoney();
                break;
            case 7:
            //Kelvin
                changePassword();
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
    void createCustomerBankAccount(){
      system("cls"); 
        cout <<"\t\t\t============ MTU SITA BANK SYSTEM ==============\n";
        cout <<"\t\t\t************************************************\n";
        cout <<"\t\t\t------------ CREATE BANK ACCOUNT --------------\n";

        cout << "\t\t\tEnter your full name: ";
        getline(cin.ignore(), newCustomer.name);

        cout << "\t\t\tEnter your age: ";
        cin >> newCustomer.age;

        cout << "\t\t\tEnter initial deposit amount: $";
        cin >> newCustomer.initialDeposit;
         static int accountCounter = 1001;
        newCustomer.accountNumber = accountCounter++;

        // Store the customer information in a file
        ofstream customerFile("customerAccounts.txt", ios::app);
        if (customerFile.is_open()) {
            customerFile << newCustomer.accountNumber << "," << newCustomer.name << "," << newCustomer.age << ","
                          << newCustomer.initialDeposit << endl;
            customerFile.close();
            cout << "\t\t\tBank account created successfully!\n";
            cout << "\t\t\tYour account number is: " << newCustomer.accountNumber << endl;
        } else {
            cout << "\t\t\tError: could not open customer accounts file\n";
        }
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
    void createCustomerBankAccount(){

    }

    void deleteCustomerBankAccount(){

    }
};
//Mark
double changeCurrency() {
    return 0;
};

int main() {
    int choice;
    bool validCredentials = false;
    Credentials inputCredentials;
    Account* currentAccount;

    do {
        system("cls");
        cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout <<"|                      MTU SITA BANK SYSTEM                  |\n";
        cout <<"|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
        cout <<"|   1. Sign Up                                               |\n";
        cout <<"|   2. Log In                                                |\n";
        cout <<"|   3. Exit                                                  |\n";
        cout <<"|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
        cout <<"|   Select an option: ";
        cin >> choice;
        cout <<"|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
        switch (choice) {
            case 1:
                signup();
                break;
            case 2:
                system("cls");
                cout <<"|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
                cout <<"|                      MTU SITA BANK SYSTEM                  |\n";
                cout <<"|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
                cout <<"|   LOGIN                                                    |\n";
                cout <<"|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
                cout <<"|   Enter your username: ";
                cin >> inputCredentials.userName;
                cout <<"|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
                cout <<"|   Enter your password: ";
                cin >> inputCredentials.passWord;
                cout <<"|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";

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

    cout <<"|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
    cout <<"|           Thank You For Using Mtu Sita Bank System         |\n";
    cout <<"|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";


    return 0;
}
