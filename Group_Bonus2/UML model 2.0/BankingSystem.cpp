#include "BankingSystem.hpp"

// Default Constructor
BankApplication::BankApplication() {}

// Start the application and display the menu
void BankApplication::start()
{
	cout << "Welcome to FCAI Banking Application!\n";
	// Loop until the user exits
	while (true)
	{
		cout << "1. Create a New Account\n"
				"2. List Clients and Accounts\n"
				"3. Withdraw Money\n"
				"4. Deposit Money\n"
				"5. Exit\n";
		cout << "Please Enter Choice =====> ";
		int choice;
		cin >> choice;
		if (choice == 1)
			this->addClient();
		else if (choice == 2)
			this->printClients();
		else if (choice == 3)
			this->withdrawMoney();
		else if (choice == 4)
			this->depositMoney();
		else if (choice == 5)
		{
			cout << "Thank You For Using FCAI Banking Application!\n";
			return;
		}
		else
			cerr << "INVALID INPUT!!\n";
	}
}

// Add new client to the system
bool BankApplication::addClient()
{
	string name = "", address = "", phoneNumber = "";
	// Get Account Data from the user
	cout << "Please Enter Client Name =====> ";
	cin.ignore();
	getline(cin, name);
	cout << "Please Enter Client Address =====> ";
	getline(cin, address);
	cout << "Please Enter Client Phone Number =====> ";
	getline(cin, phoneNumber);
	// Create object from Client and pass the values entered by the user
	// to the constructor of Client class
	Client newClient(name, address, phoneNumber);
	// Complete the creation of the account and if created successfully
	// print a message confirming the status of creating the account
	if (newClient.createAccount())
	{
		cout << "An Account was created with ID " << newClient.getBankAccount().getAccountID();
		cout << " and Starting Balance " << newClient.getBankAccount().getBalance() << " L.E.\n";
		// Add the client to the vector of clients
		clients.push_back(newClient);
		cout << setw(60) << setfill('-') << "" << endl;
		return true;
	}
	else
	{
		cerr << "FAILED Creating Account!!\n";
		cout << setw(60) << setfill('-') << "" << endl;
		return false;
	}
}

// List all accounts in the vector of clients
void BankApplication::printClients()
{
	// Check if the vector is empty, means that there are no clients added
	if (this->clients.empty())
	{
		cout << "There are NO clients on the system yet!\n";
		cout << setw(60) << setfill('-') << "" << endl;
		return;
	}
	else
	{
		// Loop over all clients in the vector and print their information
		for (int i = 0; i < this->clients.size(); ++i)
		{
			cout << setw(30) << setfill('-') << " " << clients[i].getName() << " ";
			cout << setw(30) << setfill('-') << "" << endl;
			cout << "Address: " << clients[i].getAddress() << ", ";
			cout << "Phone: " << clients[i].getPhoneNum() << endl;
			cout << "Account ID: " << clients[i].getBankAccount().getAccountID() << endl;
			cout << "Balance: " << clients[i].getBankAccount().getBalance() << endl;
			cout << setw(60) << setfill('-') << "" << endl;
		}
	}
}

// Withdraw certain amount from current account
void BankApplication::withdrawMoney()
{
	string id = "";
	double moneyToWithdraw = 0.0;
	cout << "Please Enter Account ID (e.g., FCAI-015) =====> ";
	cin >> id;
	// Search for the client with the entered id
	for (int i = 0; i < this->clients.size(); ++i)
	{
		// If the account is found perform the desired action
		if (clients[i].getBankAccount().getAccountID() == id)
		{
			cout << "Account ID: " << clients[i].getBankAccount().getAccountID() << endl;
			cout << "Balance: " << clients[i].getBankAccount().getBalance() << endl;
			cout << "Please Enter The Amount to Withdraw =====> ";
			cin >> moneyToWithdraw;
			// If the amount entered is valid call the desired function
			if (clients[i].getBankAccount().withdraw(moneyToWithdraw))
			{
				cout << "Account ID: " << clients[i].getBankAccount().getAccountID() << endl;
				cout << "New Balance: " << clients[i].getBankAccount().getBalance() << endl;
				cout << setw(60) << setfill('-') << "" << endl;
				return;
			}
			else
			{
				cerr << "Sorry. This is more than what you can withdraw.\n";
				return;
			}
		}
		// If the account is NOT found in the vector of clients
		cerr << "Sorry. This Account is NOT found on the system!\n";
		cout << setw(60) << setfill('-') << "" << endl;
	}
}

// Deposit certain amount in current account
void BankApplication::depositMoney()
{
	string id = "";
	double moneyToDeposit = 0.0;
	cout << "Please Enter Account ID (e.g., FCAI-015) =====> ";
	cin >> id;
	// Search for the client with the entered id
	for (int i = 0; i < this->clients.size(); ++i)
	{
		// If the account is found perform the desired action
		if (clients[i].getBankAccount().getAccountID() == id)
		{
			cout << "Account ID: " << clients[i].getBankAccount().getAccountID() << endl;
			cout << "Balance: " << clients[i].getBankAccount().getBalance() << endl;
			cout << "Please Enter The Amount to Deposit =====> ";
			cin >> moneyToDeposit;
			// If the amount entered is valid call the desired function
			if (clients[i].getBankAccount().deposit(moneyToDeposit))
			{
				cout << "Account ID: " << clients[i].getBankAccount().getAccountID() << endl;
				cout << "New Balance: " << clients[i].getBankAccount().getBalance() << endl;
				cout << setw(60) << setfill('-') << "" << endl;
				return;
			}
			else
			{
				cout << "Sorry. You should deposit more than this.\n";
				return;
			}
		}
		// If the account is NOT found in the vector of clients
		cerr << "Sorry. This Account is NOT found on the system!\n";
	}
}

Client::Client(string name, string address, string phoneNum)
{
	this->name = name;
	this->address = address;
	this->phoneNum = phoneNum;
}

bool Client::createAccount()
{
	cout << "Do you want the account to be a savings account? (y/n) ";
	char choice;
	double amount;
	cin >> choice;
	cout << "Enter the initial amount to be deposited: ";
	cin >> amount;
	if (choice == 'y')
	{
		BankAccount account = SavingsBankAccount(amount);
		this->Account = account;
		return true;
	}
	else if (choice == 'n')
	{
		BankAccount account(amount);
		this->Account = account;
		return true;
	}
	else
	{
		cout << "Invalid Choice\n";
		return false;
	}
}

string Client::getName()
{
	return this->name;
}

string Client::getAddress()
{
	return this->address;
}

string Client::getPhoneNum()
{
	return this->phoneNum;
}

BankAccount Client::getBankAccount()
{
	return this->Account;
}

int BankAccount::order = 1;

BankAccount::BankAccount()
{
	balance = 0.0;
}

BankAccount::BankAccount(double balance)
{
	this->accountID = generateID();
	this->balance = balance;
}

int BankAccount::withdraw(double amount)
{
	if (amount <= getBalance() && amount > 0)
	{
		balance -= amount;
		return 1;
	}
	else
		return 0;
}

int BankAccount::deposit(double amount)
{
	if (amount > 0)
	{
		balance += amount;
		return 1;
	}
	else
	{
		return 0;
	}
}

double BankAccount::getBalance()
{
	return this->balance;
}

void BankAccount::setBalance(double balance)
{
	if (balance > 0)
	{
		this->balance = balance;
	}
}

string BankAccount::getAccountID()
{
	return this->accountID;
}

string BankAccount::generateID()
{
	return "FCAI-" + to_string(order++);
}

SavingsBankAccount::SavingsBankAccount() : BankAccount() {}

SavingsBankAccount::SavingsBankAccount(double balance) : BankAccount(balance) {}

int SavingsBankAccount::withdraw(double amount)
{
	if (amount <= getBalance() - minimumBalance)
	{
		setBalance(getBalance() - amount);
		return 1;
	}
	else
	{
		return 0;
	}
}

int SavingsBankAccount::deposit(double amount)
{
	if (amount >= 100)
	{
		setBalance(getBalance() + amount);
		return 1;
	}
	else
	{
		return 0;
	}
}
