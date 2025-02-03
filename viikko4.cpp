#include <iostream>
#include <string>
using namespace std;

// Pankkitili-luokka
class Pankkitili {
protected:
    string omistaja;
    double saldo = 0;

public:
    Pankkitili(string nimi) : omistaja(nimi) {
        cout << "Pankkitili luotu " << omistaja << ":lle" << endl;
    }

    virtual ~Pankkitili() {}

    virtual bool deposit(double amount) {
        if (amount <= 0) {
            return false;
        }
        saldo += amount;
        cout << "Pankkitilille talletus " << amount << " tehty" << endl;
        return true;
    }

    virtual bool withdraw(double amount) {
        if (amount <= 0 || saldo < amount) {
            return false;
        }
        saldo -= amount;
        cout << "Pankkitililtä nosto " << amount << " tehty" << endl;
        return true;
    }

    double getBalance() const {
        return saldo;
    }
};

// Luottotili-luokka
class Luottotili : public Pankkitili {
private:
    double luottoRaja;

public:
    Luottotili(string nimi, double luotto) : Pankkitili(nimi), luottoRaja(luotto) {
        cout << "Luottotili luotu " << omistaja << ":lle, luottoraja " << luottoRaja << endl;
    }

    bool withdraw(double amount) override {
        if (amount <= 0 || saldo - amount < -luottoRaja) {
            return false;
        }
        saldo -= amount;
        cout << "Luottotililtä nosto " << amount << " tehty" << endl;
        return true;
    }

    bool deposit(double amount) override {
        if (amount <= 0) {
            return false;
        }
        saldo += amount;
        cout << "Luottotilille talletus " << amount << " tehty" << endl;
        return true;
    }
};

// Asiakas-luokka
class Asiakas {
private:
    string nimi;
    Pankkitili kayttotili;
    Luottotili luottotili;

public:
    Asiakas(string nimi, double luottoRaja)
        : nimi(nimi), kayttotili(nimi), luottotili(nimi, luottoRaja) {
        cout << "Asiakas luotu: " << nimi << endl;
    }

    void showSaldo() {
        cout << nimi << " Käyttötilin saldo: " << kayttotili.getBalance() << endl;
        cout << nimi << " Luottotilin saldo: " << luottotili.getBalance() << endl;
    }

    bool talletus(double amount) {
        return kayttotili.deposit(amount);
    }

    bool nosto(double amount) {
        return kayttotili.withdraw(amount);
    }

    bool luotonNosto(double amount) {
        return luottotili.withdraw(amount);
    }

    bool luotonMaksu(double amount) {
        return luottotili.deposit(amount);
    }

    bool tiliSiirto(double amount, Asiakas& toinenAsiakas) {
        if (!kayttotili.withdraw(amount)) {
            return false;
        }
        if (!toinenAsiakas.kayttotili.deposit(amount)) {
            kayttotili.deposit(amount); // Palautetaan rahat, jos siirto epäonnistuu
            return false;
        }
        cout << "Tilisiirto " << amount << " tehty " << nimi << " -> " << toinenAsiakas.nimi << endl;
        return true;
    }
};

// Testataan ohjelma
int main() {
    // Luodaan kaksi asiakasta
    Asiakas asiakas1("Aapeli", 1000);
    Asiakas asiakas2("Bertha", 500);

    // Käyttötilin talletus ja nosto
    asiakas1.talletus(250);
    asiakas1.nosto(150);

    // Luottotilin nosto ja maksu
    asiakas2.luotonNosto(50);
    asiakas2.luotonMaksu(100);

    // Näytetään saldot
    asiakas1.showSaldo();
    asiakas2.showSaldo();

    // Tilisiirto
    asiakas1.tiliSiirto(50, asiakas2);

    // Näytetään saldot uudelleen
    asiakas1.showSaldo();
    asiakas2.showSaldo();

    return 0;
}
