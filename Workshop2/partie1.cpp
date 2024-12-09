#include <iostream>

class BankAccount {

private:
    double balance;

public:
    explicit BankAccount(const double balance) : balance(balance) {}

    double obtenirBalance() const {
        return balance;
    }

    void deposer(const double quantite) {
        balance += quantite;
    }

    void retirer(const double quantite) {
        balance -= quantite;
    }
};

class Transaction {
private:
    BankAccount* from;
    BankAccount* to;
    double amount;
public:
    Transaction(BankAccount* from, BankAccount* to, const double amount)
    : from(from), to(to), amount(amount) {}
    
    bool execute() const {
        if (from->obtenirBalance() >= amount) {
            from->retirer(amount);
            to->deposer(amount);
            return true;
        }

        return false;
    }
};


int main() {
    BankAccount* account1 = new BankAccount(1000.0);
    BankAccount* account2 = new BankAccount(500.0);
    const Transaction* transaction = new Transaction(account1, account2, 80.0);
    bool res = transaction->execute();
    if (res) {
        std::cout << "Transaction successful" << std::endl;
    } else {
        std::cout << "Transaction failed" << std::endl;
    }
    std::cout << account1->obtenirBalance() << std::endl;
    std::cout << account2->obtenirBalance() << std::endl;

    delete account1;
    delete account2;
    delete transaction;
    
    account1 = new BankAccount(1000.0);
    account2 = new BankAccount(500.0);
    transaction = new Transaction(account1, account2, 5000.0);

    res = transaction->execute();
    if (res) {
        std::cout << "Transaction successful" << std::endl;
    } else {
        std::cout << "Transaction failed" << std::endl;
    }
    
    std::cout << account1->obtenirBalance() << std::endl;
    std::cout << account2->obtenirBalance() << std::endl;

    delete account1;
    delete account2;
    delete transaction;
   
    return 0;
}