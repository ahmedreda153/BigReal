#ifndef CLIENT_H
#define CLIENT_H

class Client {

private:
	string name;
	string address;
	string phone;
	BankAcc bankAccount;

public:
	Client();

	string getName();

	void setName(string n);

	string getAddress();

	void setAddress(string a);

	string getPhone();

	void setPhone(string p);

	BankAcc getBankAccount();

	void setBankAccount(BankAcc acc);
};

#endif
