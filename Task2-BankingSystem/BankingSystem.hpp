

#ifndef BANKINGSYSTEM_HPP
#define BANKINGSYSTEM_HPP
#include<iostream>
using namespace std;

class BankAccount {

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


class SavingsBankAccount : public BankAccount {
private:
    double minimumBalance = 1000;

public:
    SavingsBankAccount();

    SavingsBankAccount(double balance);

    int withdraw(double amount);

    int deposit(double amount);
};


class Client {

private:
	string name;
	string address;
	string phoneNum;
	BankAccount Account;
	bool createAccount();

public:
	Client();
	
	string getName();

	string getAddress();

	string getPhoneNum();

	BankAccount getBankAccount();
};

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