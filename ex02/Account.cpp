
#include "Account.hpp"

#include <iostream>
#include <chrono>
#include <iomanip>

using namespace std;

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// ===========GETTERS=================
int  Account::getNbAccounts(void)
{
    return  Account::_nbAccounts;
}
int	Account::getTotalAmount( void )
{
    return Account::_totalAmount;
}
int	Account::getNbDeposits( void )
{
    return Account::_totalNbDeposits;
}
int	Account::getNbWithdrawals( void )
{
    return Account::_totalNbWithdrawals;
}
// =========END OF GETTERS============

void	Account::makeDeposit( int deposit )
{
    _displayTimestamp();
    _nbDeposits++;
    _totalNbDeposits++;
    cout << "index:"<<_accountIndex <<";p_amount:"<<_amount << ";deposit:"<<deposit 
    <<";amount:"<<_amount + deposit <<";nb_deposits:"<< _nbDeposits << endl;
    _amount += deposit;
    // cout << "makeDeposit" << deposit << endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
    _displayTimestamp();
    if(withdrawal > _amount)
    {
        cout << "index:"<< _accountIndex <<";p_amount:"<< _amount <<";withdrawal:refused"<< endl;
        return false;
    }
    _nbWithdrawals++;
    _totalNbWithdrawals++;

    cout << "index:"<< _accountIndex <<";p_amount:"<< _amount<<";withdrawal:"<< withdrawal
    <<";amount:"<< _amount - withdrawal <<";nb_withdrawals:"<< _nbWithdrawals<< endl;
    _amount -= withdrawal;
    return true;
}

void	Account::displayAccountsInfos( void )
{
    Account::_displayTimestamp();
    cout <<"accounts:"<< getNbAccounts()<<";total:" << getTotalAmount()<<";deposits:" 
    << getNbDeposits()<< "withdrawals:"<< getNbWithdrawals()<< endl;
}

void Account::displayStatus(void) const
{
    Account::_displayTimestamp();
    cout << "index:"<<_accountIndex <<";amount:"<<_amount << ";deposits:"<<_nbDeposits 
    <<";withdrawals:"<< _nbWithdrawals<< endl;
}

int		Account::checkAmount( void ) const{
    return _amount;
}

void	Account::_displayTimestamp( void )
{
    chrono::time_point<chrono::system_clock> now = chrono::system_clock::now();
    time_t current_time = chrono::system_clock::to_time_t(now);
    cout << put_time(localtime(&current_time), "[%Y%m%d_%H%M%S] ") ;
}

Account::Account(int ss)
{
    _displayTimestamp();
    _accountIndex =_nbAccounts;
    _amount = ss;
    _totalAmount += ss;
    _nbAccounts++;
    cout << "index:" << _accountIndex<< ";amount:"<< ss << ";created"<< endl;
}
