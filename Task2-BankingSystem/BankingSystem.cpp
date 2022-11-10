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



class Client {

private:
	string name;
	string address;
	string phoneNum;
	BankAccount BankAccount;

public:
	Client();
private:

	bool createAccount();

public:
	string getName();

	string getAddress();

	string getPhoneNum();

	BankAccount getBankAccount();
};





Client::Client() {
	// TODO - implement Client::Client
	throw "Not yet implemented";
}

bool Client::createAccount() {
	// TODO - implement Client::createAccount
	throw "Not yet implemented";
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
	// TODO - implement Client::getBankAccount
	throw "Not yet implemented";
}



class BankAccount {

private:
	string accountID;
	double balance;

public:
	int withdraw(double amount);

	int deposit(double amount);

	double getBalance();

	void setBalance(double balance);

	string getAccountID();

	void generateID(string accountID);
};



int BankAccount::withdraw(double amount) {
	// TODO - implement BankAccount::withdraw
	throw "Not yet implemented";
}

int BankAccount::deposit(double amount) {
	// TODO - implement BankAccount::deposit
	throw "Not yet implemented";
}

double BankAccount::getBalance() {
	return this->balance;
}

void BankAccount::setBalance(double balance) {
	this->balance = balance;
}

string BankAccount::getAccountID() {
	return this->accountID;
}

void BankAccount::generateID(string accountID) {
	// TODO - implement BankAccount::generateID
	throw "Not yet implemented";
}








int SavingsBankAccount::withdraw(double amount) {
	// TODO - implement SavingsBankAccount::withdraw
	throw "Not yet implemented";
}

int SavingsBankAccount::deposit(double amount) {
	// TODO - implement SavingsBankAccount::deposit
	throw "Not yet implemented";
}
