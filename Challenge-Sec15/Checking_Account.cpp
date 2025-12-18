#include "Checking_Account.h"
#include <iostream>

Checking_Account::Checking_Account(std::string name, double balance, double withdrawal_fee)
    : Account{name, balance}, withdrawal_fee{withdrawal_fee} {
}

bool Checking_Account::withdraw(double amount) {
    return Account::withdraw(amount + withdrawal_fee);
}

std::ostream &operator<<(std::ostream &os, const Checking_Account &account) {
    os << "[Checking_Account: " << account.name << ": " << account.balance << ", " << account.withdrawal_fee << " fee]";
    return os;
}
