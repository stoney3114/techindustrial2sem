#include <iostream>
#include <vector>
#include <string>

class Vehicle {
protected:
    std::string brand;
    int year;
    double maxSpeed;
public:
    Vehicle(std::string b, int y, double s) : brand(b), year(y), maxSpeed(s) {}
    virtual void start() = 0;
    virtual void stop() = 0;
    virtual double getMaxSpeed() const { return maxSpeed; }
    virtual void displayInfo() const {
        std::cout << brand << " (" << year << "), макс. скорость: " << maxSpeed << " км/ч";
    }
    virtual ~Vehicle() {}
};

class Car : public Vehicle {
private:
    int doors;
public:
    Car(std::string b, int y, double s, int d) : Vehicle(b, y, s), doors(d) {}
    void start() override { std::cout << "Автомобиль завелся\n"; }
    void stop() override { std::cout << "Автомобиль остановился\n"; }
    void displayInfo() const override {
        Vehicle::displayInfo();
        std::cout << ", дверей: " << doors << "\n";
    }
};

class Motorcycle : public Vehicle {
private:
    bool hasSidecar;
public:
    Motorcycle(std::string b, int y, double s, bool sidecar) : Vehicle(b, y, s), hasSidecar(sidecar) {}
    void start() override { std::cout << "Мотоцикл завелся\n"; }
    void stop() override { std::cout << "Мотоцикл остановился\n"; }
    void displayInfo() const override {
        Vehicle::displayInfo();
        std::cout << ", коляска: " << (hasSidecar ? "есть" : "нет") << "\n";
    }
};

class Truck : public Vehicle {
private:
    double loadCapacity;
public:
    Truck(std::string b, int y, double s, double cap) : Vehicle(b, y, s), loadCapacity(cap) {}
    void start() override { std::cout << "Грузовик завелся\n"; }
    void stop() override { std::cout << "Грузовик остановился\n"; }
    void displayInfo() const override {
        Vehicle::displayInfo();
        std::cout << ", грузоподъемность: " << loadCapacity << " т\n";
    }
};

class FleetManager {
private:
    std::vector<Vehicle*> fleet;
public:
    void addVehicle(Vehicle* v) { fleet.push_back(v); }
    
    void startAll() {
        std::cout << "\nЗапуск всего парка:\n";
        for(auto v : fleet) v->start();
    }
    
    void stopAll() {
        std::cout << "\nОстановка всего парка:\n";
        for(auto v : fleet) v->stop();
    }
    
    void showAll() {
        std::cout << "\nПарк техники:\n";
        for(auto v : fleet) v->displayInfo();
    }
    
    ~FleetManager() { for(auto v : fleet) delete v; }
};

int main() {
    FleetManager manager;
    
    manager.addVehicle(new Car("Toyota", 2020, 180, 4));
    manager.addVehicle(new Motorcycle("Harley", 2019, 220, false));
    manager.addVehicle(new Truck("Volvo", 2018, 140, 20));
    
    manager.showAll();
    manager.startAll();
    manager.stopAll();
    
    return 0;
}
