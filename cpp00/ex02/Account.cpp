#include "Account.hpp"
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
	: _accountIndex(_nbAccounts),
	  _amount(initial_deposit),
	  _nbDeposits(0),
	  _nbWithdrawals(0)
{
	_nbAccounts++;
	_totalAmount += initial_deposit;

}

Account::~Account()
{
	_nbAccounts--;
	_totalAmount -= _amount;
	_totalNbDeposits -= _nbDeposits;
	_totalNbWithdrawals -= _nbWithdrawals;
}

int Account::getNbAccounts()
{
	return _nbAccounts;
}

int Account::getTotalAmount()
{
	return _totalAmount;
}

int Account::getNbDeposits()
{
	return _totalNbDeposits;
}

int Account::getNbWithdrawals()
{
	return _totalNbWithdrawals;
}
int	Account::checkAmount() const
{
	return _amount;
}

void Account::makeDeposit(int deposit)
{
	_totalNbDeposits++;
	_nbDeposits++;
	_amount += deposit;
	_totalAmount += deposit;
}
bool Account::makeWithdrawal(int withdrawal)
{
	if (withdrawal <= _amount)
	{
		_totalNbWithdrawals++;
		_nbWithdrawals++;
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		return (true);
	}
	else
		return (false);
}

void	Account::displayStatus() const
{
	std::cout << "Account number " << _accountIndex << ": amount" << _amount << ", deposits: " << _nbDeposits << ", withdrawals: " << _nbWithdrawals << std::endl;
}

void	Account::displayAccountsInfos()
{
	std::cout << "Total accounts: " << _nbAccounts << ", total amount: " << _totalAmount << ", total deposits: " << _totalNbDeposits << ", total withdrawals: " << _totalNbWithdrawals << std::endl;
}