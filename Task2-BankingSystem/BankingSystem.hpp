#ifndef BANKINGSYSTEM_HPP
#define BANKINGSYSTEM_HPP

#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

class BankAccount
{
private:
	string accountID;
	double balance;
	static int order;

public:
	BankAccount();

	BankAccount(double balance);

	virtual int withdraw(double amount);

	virtual int deposit(double amount);

	double getBalance();

	void setBalance(double balance);

	string getAccountID();

	string generateID();
};

class SavingsBankAccount : public BankAccount
{
private:
	double minimumBalance = 1000;

public:
	SavingsBankAccount();

	SavingsBankAccount(double balance);

	int withdraw(double amount);

	int deposit(double amount);
};

class Client
{

private:
	string name;
	string address;
	string phoneNum;
	BankAccount * account;


public:
	bool createAccount();

	Client(string name, string address, string phoneNum);

	string getName();

	string getAddress();

	string getPhoneNum();

	BankAccount* getBankAccount();
};

// Main class that runs the application
class BankApplication
{
private:
	// Vector of Clients to store the data into
	vector<Client> clients;

public:
	// Default constructor
	BankApplication();
	// Start the application
	void start();
	// Add new client to the system
	bool addClient();
	// List all current clients and accounts
	void printClients();
	// Withdraw money from certain account
	void withdrawMoney();
	// Deposit money into ceratin account
	void depositMoney();
};

#endif