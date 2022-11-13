#ifndef BANKAPP_H
#define BANKAPP_H

class BankApp {

private:
	std::vector<Client> vecClients;
	std::vector<BankAcc> vecAccounts;

public:
	bool addClient();

	void listClients();

	void withdraw();

	void deposit();

	void run();
};

#endif
