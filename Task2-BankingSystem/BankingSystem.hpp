

#ifndef BANKINGSYSTEM_HPP
#define BANKINGSYSTEM_HPP
#include<iostream>
using namespace std;

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






class Client {

private:
	string name;
	string address;
	string phoneNum;
	BankAccount BankAccount;
	bool createAccount();

public:
	Client();
	
	string getName();

	string getAddress();

	string getPhoneNum();

	BankAccount getBankAccount();
};



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



class SavingsBankAccount : BankAccount {

public:
	double minimumBalance;

	int withdraw(double amount);

	int deposit(double amount);
};

#endif