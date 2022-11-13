#include "BankAcc.h"

static int BankAcc::accountCount() {
	// TODO - implement BankAcc::accountCount
	throw "Not yet implemented";
}

BankAcc::BankAcc() {
	// TODO - implement BankAcc::BankAcc
	throw "Not yet implemented";
}

BankAcc::BankAcc(double bal) {
	// TODO - implement BankAcc::BankAcc
	throw "Not yet implemented";
}

string BankAcc::getAccountID() {
	return this->accountID;
}

void BankAcc::setAccountID(string ID) {
	this->accountID = ID;
}

double BankAcc::getBalance() {
	return this->balance;
}

virtual bool BankAcc::setBalance(double balance) {
	// TODO - implement BankAcc::setBalance
	throw "Not yet implemented";
}

string BankAcc::getType() {
	return this->type;
}

void BankAcc::setType(string type) {
	this->type = type;
}

Client BankAcc::getClient() {
	// TODO - implement BankAcc::getClient
	throw "Not yet implemented";
}

void BankAcc::setClient(Client bankClient) {
	// TODO - implement BankAcc::setClient
	throw "Not yet implemented";
}

virtual bool BankAcc::withdraw(double amount) {
	// TODO - implement BankAcc::withdraw
	throw "Not yet implemented";
}

virtual bool BankAcc::deposit(double amount) {
	// TODO - implement BankAcc::deposit
	throw "Not yet implemented";
}
