#include <iostream>
#include <string>
#include <algorithm>

class Chef {
protected:
    std::string chefName;

public:
    Chef(const std::string& name) : chefName(name) {
        std::cout << "Chef " << chefName << " konstruktor!" << std::endl;
    }

    virtual ~Chef() {
        std::cout << "Chef " << chefName << " destruktori!" << std::endl;
    }

    std::string getName() const {
        return chefName;
    }

    int makeSalad(int ingredients) {
        std::cout << "Chef " << chefName << " can make salad ";
        int portions = ingredients / 5;
        std::cout << portions << " portions" << std::endl;
        return portions;
    }

    int makeSoup(int ingredients) {
        std::cout << "Chef " << chefName << " can make soup ";
        int portions = ingredients / 3;
        std::cout << portions << " portions" << std::endl;
        return portions;
    }
};

class ItalianChef : public Chef {
private:
    std::string password = "pizza";
    int flour = 0;
    int water = 0;

    int makePizza(int flour, int water) {
        return std::min(flour / 5, water / 5);
    }

public:
    ItalianChef(const std::string& name) : Chef(name) {
        std::cout << "ItalianChef " << chefName << " konstruktor!" << std::endl;
    }

    ~ItalianChef() override {
        std::cout << "ItalianChef " << chefName << " destruktori!" << std::endl;
    }

    bool askSecret(const std::string& inputPassword, int flourAmount, int waterAmount) {
        if (inputPassword == password) {
            int pizzas = makePizza(flourAmount, waterAmount);
            std::cout << "ItalianChef " << chefName << " with " << flourAmount
                      << " flour and " << waterAmount << " water can make " << pizzas << " pizzas!" << std::endl;
            return true;
        } else {
            std::cout << "Wrong password!" << std::endl;
            return false;
        }
    }
};

int main() {
    Chef gordon("Gordon");
    gordon.makeSalad(11);
    gordon.makeSoup(14);

    ItalianChef mario("Mario");
    mario.makeSalad(10);
    mario.makeSoup(9);

    mario.askSecret("pizza", 17, 12);
    mario.askSecret("wrongpassword", 10, 10);

    return 0;
}
