#include "BankingSystem.hpp"

BankApplication::BankApplication() {
	// TODO - implement BankApplication::BankApplication
	throw "Not yet implemented";
}

void BankApplication::addClient() {
	// TODO - implement BankApplication::addClient
	throw "Not yet implemented";
}

void BankApplication::printClients() {
	// TODO - implement BankApplication::printClients
	throw "Not yet implemented";
}

Client::Client(string name,string address,string phoneNum) {
	this->name = name;
    this->address = address;
    this->phoneNum = phoneNum;
    if(!createAccount()){
        // TODO - Destruct client and abort creation
    }
}

bool Client::createAccount() {
	cout << "Do you want the account to be a savings account? (y/n)" << endl;
    char choice;
    double amount;
    cin >> choice;
    cout << "Enter the initial amount to be deposited: " << endl;
    cin >> amount;
    if (choice == 'y') {
        BankAccount account = SavingsBankAccount(amount);
        this->Account = account;
        return true;
    } else if (choice == 'n') {
        BankAccount account = BankAccount(amount);
        this->Account = account;
        return true;
    } else {
        cout << "Invalid choice" << endl;
        return false;
    }
}

string Client::getName() {
	return this->name;
}

string Client::getAddress() {
	return this->address;
}

string Client::getPhoneNum() {
	return this->phoneNum;
}

BankAccount Client::getBankAccount() {
	return this->Account;
}
int BankAccount::order = 1;

BankAccount::BankAccount(){
    balance = 0;
}

BankAccount::BankAccount(double balance) {
    this->accountID = generateID();
    this->balance = balance;
}


int BankAccount::withdraw(double amount) {
    if(amount <= getBalance() && amount > 0 ) {
        balance -= amount;
        return 1;
    }
    else
        return 0;
}

int BankAccount::deposit(double amount) {
    if(amount > 0){
        balance += amount;
        return 1;
    }
    else{
        return 0;
    }
}

double BankAccount::getBalance() {
	return this->balance;
}

void BankAccount::setBalance(double balance) {
    if(balance > 0){
        this->balance = balance;
    }
}

string BankAccount::getAccountID() {
	return this->accountID;
}

string BankAccount::generateID() {
    return "FCAI " + to_string(order++);
}

SavingsBankAccount::SavingsBankAccount() : BankAccount(){}

SavingsBankAccount::SavingsBankAccount(double balance) : BankAccount(balance){}

int SavingsBankAccount::withdraw(double amount) {
    if(amount <= getBalance() - minimumBalance){
        setBalance(getBalance() - amount);
        return 1;
    }
    else{
        return 0;
    }
}

int SavingsBankAccount::deposit(double amount) {
    if(amount >= 100){
        setBalance(getBalance() + amount);
        return 1;
    }
    else{
        return 0;
    }
}
