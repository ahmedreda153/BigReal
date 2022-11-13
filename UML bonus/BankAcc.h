#ifndef BANKACC_H
#define BANKACC_H

class BankAcc {

protected:
	string accountID;
	double balance;
	string type;
	Client bankClient;

public:
	static int accountCount();

	BankAcc();

	BankAcc(double bal);

	string getAccountID();

	void setAccountID(string ID);

	double getBalance();

	virtual bool setBalance(double balance);

	string getType();

	void setType(string type);

	Client getClient();

	void setClient(Client bankClient);

	virtual bool withdraw(double amount);

	virtual bool deposit(double amount);
};

#endif
