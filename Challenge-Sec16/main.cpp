// Section 16 
// Challenge 
#include <vector>
#include "Account.h"
#include "Savings_Account.h"
#include "Checking_Account.h"
#include "Trust_Account.h"
#include "Account_Util.h"


int main() {
   
    
    // Savings 

    Account *p1 = new Savings_Account {};
    Account *p2 = new Savings_Account {"Superman"};
    Account *p3 = new Savings_Account {"Batman", 2000};
    Account *p4 = new Savings_Account {"Wonderwoman", 5000, 5.0};

    std::vector<Account *> sav_accounts {p1, p2, p3, p4};

    display(sav_accounts);
    deposit(sav_accounts, 1000);
    withdraw(sav_accounts,2000);
   
   // Checking
   
    p1 = new Checking_Account {};
    p2 = new Checking_Account {"Kirk"};
    p3 = new Checking_Account {"Spock", 2000};
    p4 = new Checking_Account {"Bones", 5000};

    std::vector<Account*> check_accounts {p1, p2, p3, p4};

    display(check_accounts);
    deposit(check_accounts, 1000);
    withdraw(check_accounts, 2000);

    // Trust
  
    p1 = new Trust_Account {};
    p2 = new Trust_Account {"Athos", 10000, 5.0};
    p3 = new Trust_Account {"Porthos", 20000, 4.0};
    p4 = new Trust_Account {"Aramis", 30000};

    std::vector<Account *> trust_accounts {p1, p2, p3, p4};
    display(trust_accounts);
    deposit(trust_accounts, 1000);
    withdraw(trust_accounts, 3000);
    
    // Withdraw 5 times from each trust account
    // All withdrawals should fail if there are too many withdrawals or if the withdrawl is > 20% of the balance
    for (int i=1; i<=5; i++)
        withdraw(trust_accounts, 1000);
    

    
    return 0;
}

