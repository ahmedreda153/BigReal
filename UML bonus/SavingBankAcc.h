#ifndef SAVINGBANKACC_H
#define SAVINGBANKACC_H

class SavingBankAcc : public BankAcc {

public:
	double minimumBalance;

	SavingBankAcc();

	double getMinimumBalance();

	void setMinimumBalance(double min);

	bool setBalance(double bal);

	bool withdraw(double amount);

	bool deposit(double amount);
};

#endif
