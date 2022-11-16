

#ifndef BANKAPPLICATION_H
#define BANKAPPLICATION_H

class BankApplication {

protected:
	Client clients;
protected:
	BankAccount accounts;

public:
	BankApplication();

	void addClient();

	void printClients();
};

#endif

#include "BankApplication.h"

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

#ifndef CLIENT_H
#define CLIENT_H

class Client {

private:
	String name;
	String address;
	String phoneNum;
	BankAccount BankAccount;

public:
	Client();
private:

	bool createAccount();

public:
	String getName();

	String getAddress();

	String getPhoneNum();

	BankAccount getBankAccount();
};

#endif

#include "Client.h"

Client::Client() {
	// TODO - implement Client::Client
	throw "Not yet implemented";
}

bool Client::createAccount() {
	// TODO - implement Client::createAccount
	throw "Not yet implemented";
}

String Client::getName() {
	return this->name;
}

String Client::getAddress() {
	return this->address;
}

String Client::getPhoneNum() {
	return this->phoneNum;
}

BankAccount Client::getBankAccount() {
	// TODO - implement Client::getBankAccount
	throw "Not yet implemented";
}


#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

class BankAccount {

private:
	String accountID;
	Double balance;

public:
	int withdraw(double amount);

	int deposit(double amount);

	Double getBalance();

	void setBalance(Double balance);

	String getAccountID();

	void generateID(String accountID);
};

#endif
#include "BankAccount.h"

int BankAccount::withdraw(double amount) {
	// TODO - implement BankAccount::withdraw
	throw "Not yet implemented";
}

int BankAccount::deposit(double amount) {
	// TODO - implement BankAccount::deposit
	throw "Not yet implemented";
}

Double BankAccount::getBalance() {
	return this->balance;
}

void BankAccount::setBalance(Double balance) {
	this->balance = balance;
}

String BankAccount::getAccountID() {
	return this->accountID;
}

void BankAccount::generateID(String accountID) {
	// TODO - implement BankAccount::generateID
	throw "Not yet implemented";
}

#ifndef SAVINGSBANKACCOUNT_H
#define SAVINGSBANKACCOUNT_H

class SavingsBankAccount : BankAccount {

public:
	double minimumBalance;

	int withdraw(double amount);

	int deposit(double amount);
};

#endif

#include "SavingsBankAccount.h"

int SavingsBankAccount::withdraw(double amount) {
	// TODO - implement SavingsBankAccount::withdraw
	throw "Not yet implemented";
}

int SavingsBankAccount::deposit(double amount) {
	// TODO - implement SavingsBankAccount::deposit
	throw "Not yet implemented";
}
