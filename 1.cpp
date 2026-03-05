#include <iostream>
#include <string>

class BankAccount {
private:
    double balance;
    std::string accountNumber;

    bool isValidAccountNumber(const std::string& accNum) const {
        if (accNum.length() != 10) return false;
        for (char c : accNum) {
            if (!isdigit(c)) return false;
        }
        return true;
    }

public:
    BankAccount(std::string accNum, double initBalance) {
        if (!isValidAccountNumber(accNum)) {
            throw std::invalid_argument("Ошибка: неверный формат номера счета. Должно быть 10 цифр.");
        }
        if (initBalance < 0) {
            throw std::invalid_argument("Ошибка: начальный баланс не может быть отрицательным.");
        }
        accountNumber = accNum;
        balance = initBalance;
    }

    void deposit(double amount) {
        if (amount <= 0) {
            std::cout << "Ошибка: сумма пополнения должна быть положительной.\n";
            return;
        }
        balance += amount;
    }

    bool withdraw(double amount) {
        if (amount <= 0) {
            std::cout << "Ошибка: сумма снятия должна быть положительной.\n";
            return false;
        }
        if (amount > balance) {
            std::cout << "Ошибка: недостаточно средств.\n";
            return false;
        }
        balance -= amount;
        return true;
    }

    double getBalance() const {
        return balance;
    }
};

//пример использования
int main() {
    try {
        BankAccount myAccount("1234567890", 1000.0);
        
        std::cout << "Начальный баланс: " << myAccount.getBalance() << std::endl;
        
        myAccount.deposit(500.0);
        std::cout << "После пополнения: " << myAccount.getBalance() << std::endl;
        
        myAccount.withdraw(200.0);
        std::cout << "После снятия: " << myAccount.getBalance() << std::endl;
        
    } catch (const std::exception& e) {
        std::cout << "Ошибка: " << e.what() << std::endl;
    }
    
    return 0;
}
