#include <iostream>
#include <string>
#include <vector>
#include <memory>

class Product {
protected:
    std::string name;
    double price;
public:
    Product(std::string n, double p) : name(n), price(p) {}
    virtual void displayInfo() const {
        std::cout << "Товар: " << name << ", Цена: " << price << " руб.";
    }
    virtual double getPrice() const { return price; }
    virtual ~Product() {}
};

class Electronics : public Product {
private:
    int warranty;
    std::string brand;
public:
    Electronics(std::string n, double p, int w, std::string b) 
        : Product(n, p), warranty(w), brand(b) {}
    
    void displayInfo() const override {
        std::cout << "Электроника: " << name << ", Бренд: " << brand 
                  << ", Цена: " << price << " руб., Гарантия: " << warranty << " мес.";
    }
    
    double getPrice() const override { 
        return price * 0.95; //скидка 5%
    }
};

class Clothing : public Product {
private:
    std::string size;
    std::string material;
public:
    Clothing(std::string n, double p, std::string s, std::string m) 
        : Product(n, p), size(s), material(m) {}
    
    void displayInfo() const override {
        std::cout << "Одежда: " << name << ", Размер: " << size 
                  << ", Материал: " << material << ", Цена: " << price << " руб.";
    }
    
    double getPrice() const override { 
        return price * 0.90; //скидка 10%
    }
};

class Food : public Product {
private:
    std::string expiration;
    double weight;
public:
    Food(std::string n, double p, std::string e, double w) 
        : Product(n, p), expiration(e), weight(w) {}
    
    void displayInfo() const override {
        std::cout << "Продукты: " << name << ", Вес: " << weight 
                  << "кг, Годен до: " << expiration << ", Цена: " << price << " руб.";
    }
    
    double getPrice() const override { 
        return price * 0.97; //скидка 3%
    }
};

int main() {
    std::vector<Product*> cart;
    
    cart.push_back(new Electronics("Ноутбук", 50000, 24, "HP"));
    cart.push_back(new Clothing("Футболка", 1500, "L", "Хлопок"));
    cart.push_back(new Food("Молоко", 80, "15.03.2026", 1));
    
    std::cout << "=== Корзина товаров ===\n\n";
    
    double total = 0;
    double totalWithoutDiscount = 0;
    
    for(const auto& item : cart) {
        item->displayInfo();
        std::cout << "\n  Цена со скидкой: " << item->getPrice() << " руб.\n\n";
        total += item->getPrice();
        totalWithoutDiscount += item->Product::getPrice();
    }
    
    std::cout << "=== ИТОГО ===\n";
    std::cout << "Сумма без скидок: " << totalWithoutDiscount << " руб.\n";
    std::cout << "Сумма со скидками: " << total << " руб.\n";
    std::cout << "Вы сэкономили: " << totalWithoutDiscount - total << " руб.\n";
    
    for(auto& item : cart) delete item;
    
    return 0;
}
