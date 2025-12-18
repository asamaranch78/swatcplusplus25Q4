#include "Trust_Account.h"
#include "Savings_Account.h"

Trust_Account::Trust_Account(std::string name,
                             double balance,
                             double int_rate,
                             double bonus,
                             double bonus_threshold,
                             int remaining_withdrawall) :
    Savings_Account{name, balance, int_rate},
    bonus{bonus},
    bonus_threshold{bonus_threshold},
    remaining_withdrawall{remaining_withdrawall}{
}

bool Trust_Account::deposit(double amount) {
    if (amount > bonus_threshold) { amount += bonus;}
    return Savings_Account::deposit(amount);

}

bool Trust_Account::withdraw(double amount) {
    double max_limit = balance * 0.2;
    if (amount > max_limit) { return false; }
    if (remaining_withdrawall > 0) {
        remaining_withdrawall--;
        return Savings_Account::withdraw(amount);
    }
    return false;
}

std::ostream &operator<<(std::ostream &os, const Trust_Account &account) {
    os << "[Trust_Account: " << account.name << ": " 
        << account.balance << ", " 
        << account.int_rate << "%, "
        << account.remaining_withdrawall << " withdrawals remaining]";
    return os;
}
