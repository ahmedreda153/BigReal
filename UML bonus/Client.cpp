#include "Client.h"

Client::Client() {
	// TODO - implement Client::Client
	throw "Not yet implemented";
}

string Client::getName() {
	return this->name;
}

void Client::setName(string n) {
	this->name = n;
}

string Client::getAddress() {
	return this->address;
}

void Client::setAddress(string a) {
	this->address = a;
}

string Client::getPhone() {
	return this->phone;
}

void Client::setPhone(string p) {
	this->phone = p;
}

BankAcc Client::getBankAccount() {
	return this->bankAccount;
}

void Client::setBankAccount(BankAcc acc) {
	this->bankAccount = acc;
}
