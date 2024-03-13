
#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
#include <ctime>
#include <fstream>
#include <sstream>
#include <algorithm>
<<<<<<< HEAD
#include <conio.h> // for _getch() function
=======
#include <vector>
#include <conio.h>
>>>>>>> ca9f06abf92faaed38e710b43154ba1bfb64f7a3


using namespace std;

string adminUsername;
string adminPassword;
string employeeUsername;
string employeePassword;
int employeeAge;
string newCustomer;
int age;
int accountNumber;
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
    int age;
    int initialDeposit;
    int pin;
    string accountNumber;
    string newPassWord;
    string fulluserName;
<<<<<<< HEAD
};
bool checkIfUserExists(const Credentials& creds);
=======
    string firstName;
    string secondName;
    int balance;
    string createdBy;
    string creatorName;
};

bool checkIfUserExists(const Credentials& creds);

>>>>>>> ca9f06abf92faaed38e710b43154ba1bfb64f7a3
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

    if (checkIfUserExists(newUser)) {
        cout << "\t\tError: Username already exists!" << endl;
        return;
    }

    ofstream credentialsFile("customerCredentials.txt", ios::app);
    if (credentialsFile.is_open()) {
        credentialsFile << newUser.userName << "," << newUser.passWord << endl;
        credentialsFile.close();
        cout << "\t\t\tSign up successful!" << endl;
    } else {
        cout << "\t\t\tError: could not open credentials file" << endl;
    }
}

bool checkIfUserExists(const Credentials& creds) {
    ifstream inputFile("customerCredentials.txt");
    if (!inputFile) {
        cout << "Failed to open file 'customerCredentials.txt'" << endl;
        return false;
    }

    string line;
    while (getline(inputFile, line)) {
        size_t pos = line.find(",");
        if (pos == string::npos) continue;

        string username = line.substr(0, pos);
        string password = line.substr(pos + 1);

        if (username == creds.userName && password == creds.passWord) {
            inputFile.close();
            return true;
        }
    }

    inputFile.close();
    return false;
}

string generateAccountNumber() {
    ifstream file("account_numbers.txt");

    // Read the last account number from the file
    string lastAccountNumber;
    while (file >> lastAccountNumber) {
        // continue reading until the last account number is obtained
    }

    // Increment the last account number by 1 to generate the new one
    int newAccountNumber = atoi(lastAccountNumber.c_str()) + 1;

    // Close the file
    file.close();

    // Append the new account number to the file
    ofstream outFile("account_numbers.txt", ios::app);
    outFile << newAccountNumber << endl;
    outFile.close();

    return "AC" + to_string(newAccountNumber);
}

int pinVerification() {
    int pin1 = 0, pin2 = 0; // Initialize pin1 and pin2 to zero
    char ch;
    bool pinVerification = false;
    do
    {
    cout << "\t\t\tEnter your PIN: ";
    for (int i = 0; i < 4; i++) {
        ch = _getch(); // reads a character from the keyboard without displaying it
        if (ch >= '0' && ch <= '9') {
            pin1 = (pin1 * 10) + (ch - '0'); // converts the character to an integer and stores it in pin1
            cout << "*"; // displays an asterisk for privacy
        }
        else {
            cout << "Invalid input. Please enter a 4-digit numeric PIN." << endl;
            return 1; // exits the program if the input is invalid
        }
    }

    cout << "\n\t\t\tConfirm your PIN: ";
    for (int i = 0; i < 4; i++) {
        ch = _getch(); // reads a character from the keyboard without displaying it
        if (ch >= '0' && ch <= '9') {
            pin2 = (pin2 * 10) + (ch - '0'); // converts the character to an integer and stores it in pin2
            cout << "*"; // displays an asterisk for privacy
        }
        else {
            cout << "Invalid input. Please enter a 4-digit numeric PIN." << endl;
              return 1; // exits the program if the input is invalid
        }
    }

    if (pin1 == pin2) {
        cout << "\n\t\t\tPIN verified successfully!" << endl;
        pinVerification = true;
        return pin2;
    }
    else {
        cout << "\n\t\t\tPINs do not match. Please try again." << endl;
    }
    } while (!pinVerification);
    return 0, pin2;
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
private:
    string userName;
public:
    Customer(string userName) : userName(userName) {}
    void displayMenu() override {
        //Brad
        cout <<"|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
        cout <<"|                       CUSTOMER MENU                        |\n";
        cout <<"|   Welcome, " << userName << "!                             |\n";
        cout <<"|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
        cout <<"|   1. Check balance                                         |\n";
        cout <<"|   2. Create a bank account                                 |\n";
        cout <<"|   3. Delete account                                        |\n";
        cout <<"|   4. Deposit money                                         |\n";
        cout <<"|   5. Withdraw money                                        |\n";
        cout <<"|   6. Transfer money                                        |\n";
        cout <<"|   7. Change password                                       |\n";
        cout <<"|   8. Change currency                                       |\n";
        cout <<"|   9. Log out                                               |\n";
        cout <<"|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
        cout <<"|   Please enter an option: ";
    }

    void executeAction(int actionNumber) override {
        switch (actionNumber) {
            case 1:
            //Brad
                // int checkBalance();
                checkBalance(userName);
                break;
            case 2:
            //Crissy
<<<<<<< HEAD
                createCustomerBankAccount();
=======
                createCustomerBankAccount(userName);
>>>>>>> ca9f06abf92faaed38e710b43154ba1bfb64f7a3
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
                transferMoney(userName);
                break;
            case 7:
            //Kelvin
                changePassword();
                break;
            case 9:
                logOut();
                break;
            default:
                cout << "\t\tInvalid option!\n";
                break;
        }
    }

private:
    void checkBalance(string username) {
        // Display current balance
        // cout << "\t\tCurrent balance:\n";
        ifstream file("customerAccounts.txt");
        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                istringstream iss(line);
                string accountNumber, pin, firstName,secondName, age, balance, createdBy, creatorName;
                iss >> accountNumber >> pin >> firstName >>secondName >> age >> balance >> createdBy >> creatorName;
                if (creatorName == username) {
                    cout << "Your account Number: " << accountNumber << endl;
                    cout << "Your balance: " <<  balance << endl;
                }
            }
            file.close();
        } else {
            cout << "Unable to open file";
        }
    }
    void createCustomerBankAccount(const string& username){
        Credentials newCustomer;
        system("cls"); 
        cout <<"\t\t\t============ MTU SITA BANK SYSTEM ==============\n";
        cout <<"\t\t\t************************************************\n";
        cout <<"\t\t\t------------ CREATE BANK ACCOUNT --------------\n";

        cout << "\t\t\tEnter your full name: ";
        getline(cin.ignore(), newCustomer.fulluserName);

        cout << "\t\t\tEnter your age: ";
        cin >> newCustomer.age;
        newCustomer.accountNumber = generateAccountNumber();
        cout << "\t\t\tYour account number is: " << newCustomer.accountNumber << endl;  
        int zero; // for the zero that was retuned in pin verification
        zero,newCustomer.pin = pinVerification();
<<<<<<< HEAD
        cout << "\t\t\tEnter initial deposit amount: $";
=======
        cout << "\t\t\tEnter initial deposit amount: ksh";
>>>>>>> ca9f06abf92faaed38e710b43154ba1bfb64f7a3
        cin >> newCustomer.initialDeposit;

        // Store the customer information in a file
        ofstream customerFile("customerAccounts.txt", ios::app);
        if (customerFile.is_open()) {
            customerFile << newCustomer.accountNumber << "\t"<<newCustomer.pin <<"\t"<< newCustomer.fulluserName << "\t" << newCustomer.age << "\t"
<<<<<<< HEAD
                          << newCustomer.initialDeposit <<"\tcreated by\t"<<newCustomer.userName<<endl;
=======
                          << newCustomer.initialDeposit <<"\tcreatedBy\t"<<userName<<endl;
>>>>>>> ca9f06abf92faaed38e710b43154ba1bfb64f7a3
            customerFile.close();
            cout << "\t\t\tBank account created successfully!\n";
            cout << "\t\t\tYour account number is: " << newCustomer.accountNumber << endl;
            cout << "\t\t\tYour balance is: " << newCustomer.initialDeposit <<endl;
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

    void transferMoney(string username) {   
        string recipientAccount;
        ifstream file("customerAccounts.txt");
        ofstream tempFileOut("tempCredentials.txt");

        if (file.is_open() && tempFileOut.is_open()) {
            vector<Credentials> accounts;
            string line;
            while (getline(file, line)) {
                istringstream iss(line);
                Credentials account;
                iss >> account.accountNumber >> account.pin >> account.firstName >> account.secondName >> account.age >> account.balance >> account.createdBy >> account.creatorName;
                accounts.push_back(account);
            }

            for (size_t i = 0; i < accounts.size(); i++) {
                if (accounts[i].creatorName == username) {
                    cout << "Your account Number: " << accounts[i].accountNumber << endl;
                    cout << "Your balance: " <<  accounts[i].balance << endl;
                    cout << "Enter the recipient's account number: ";
                    cin >> recipientAccount;

                    for (size_t j = 0; j < accounts.size(); j++) {
                        if (recipientAccount == accounts[j].accountNumber) {
                            cout << "Enter the amount to transfer: ";
                            int transferAmount;
                            cin >> transferAmount;
                            if (accounts[i].balance < transferAmount) {
                                cout << "Insufficient funds.\n";
                                return;
                            }
                            accounts[i].balance -= transferAmount;
                            accounts[j].balance += transferAmount;
                            cout << "Transfer successful.\n";
                            break;
                        }
                    }
                    break;
                }
            }

            for (const auto& account : accounts) {
                tempFileOut << account.accountNumber << "\t" << account.pin << "\t" << account.firstName << "\t" << account.secondName << "\t" << account.age << "\t" << account.balance << "\t" << account.createdBy << "\t" << account.creatorName << "\t" << endl;
            }

            file.close();
            tempFileOut.close();

            remove("customerAccounts.txt");
            rename("tempCredentials.txt", "customerAccounts.txt");
        } else {
            cout << "Unable to open file";
        }
    }

    void changePassword() {
        Credentials loginUser;
        bool validCredentials = false;

        cout << "\nChanging password...\n";
        cout << "Enter your username: ";
        cin >> loginUser.userName;

        // Prompt user to enter current password
        cout << "Enter your current password: ";
        cin >> loginUser.passWord;

        ifstream credentialsFileIn("customerCredentials.txt");
        if (credentialsFileIn.is_open()) {
            ofstream tempFileOut("tempCredentials.txt");
            if (tempFileOut.is_open()) {
                string line;
                while (getline(credentialsFileIn, line)) {
                    size_t commaPos = line.find(',');
                    string username = line.substr(0, commaPos);
                    string password = line.substr(commaPos + 1);

                    if (loginUser.userName == username && loginUser.passWord == password) {
                        validCredentials = true;
                        // Prompt user to enter new password
                        string newPassword;
                        cout << "Enter your new password: ";
                        cin >> newPassword;
                        tempFileOut << loginUser.userName << "," << newPassword << endl;
                    } else {
                        tempFileOut << line << endl;
                    }
                }
                tempFileOut.close();
                credentialsFileIn.close();

                if (validCredentials) {
                    remove("customerCredentials.txt");
                    // Rename the temporary file to the original file
                    if (rename("tempCredentials.txt", "customerCredentials.txt") == 0) {
                        cout << "Password changed successfully!\n";
                    } else {
                        cout << "Error: Could not rename temporary file\n";
                    }
                } else {
                    cout << "Incorrect username or password. Password change failed.\n";
                    // Remove the temporary file if the password change failed
                    remove("tempCredentials.txt");
                }
            } else {
                cout << "Error: Could not open temporary file\n";
            }
        } else {
            cout << "Error: Could not open credentials file\n";
        }
    }

    void deleteCustomerBankAccount(){

    }
};
//Mark
double changeCurrency() {
    return 0;
};
Account *currentAccount;
void logOut() {
    currentAccount = nullptr;
    cout << "\tYou have successfully logged out." << endl;
    main();
}

int main() {
    int choice;
    bool validCredentials = false;
    Credentials inputCredentials;
    Account *currentAccount = nullptr; 

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
            case 3://added this code to handle exit when loged in
                cout <<"|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
                cout <<"|           Thank You For Using Mtu Sita Bank System         |\n";
                cout <<"|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
                exit(0);
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
                            currentAccount = new Customer(inputCredentials.userName);
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
