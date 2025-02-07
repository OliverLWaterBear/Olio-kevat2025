#include <iostream>
#include <string>
using namespace std;

class Seuraaja {
public:
    Seuraaja(string n) : nimi(n), next(nullptr) {}
    string getNimi() { return nimi; }
    void paivitys(string viesti) {
        cout << "Seuraaja " << nimi << " sai viestin: " << viesti << endl;
    }
    Seuraaja* next;

private:
    string nimi;
};

class Notifikaattori {
public:
    Notifikaattori() : seuraajat(nullptr) {}

    void lisaa(Seuraaja* uusiSeuraaja) {
        uusiSeuraaja->next = seuraajat;
        seuraajat = uusiSeuraaja;
    }

    void poista(Seuraaja* poistettava) {
        if (seuraajat == nullptr) return;
        if (seuraajat == poistettava) {
            seuraajat = seuraajat->next;
            delete poistettava;
            return;
        }
        Seuraaja* nykyinen = seuraajat;
        while (nykyinen->next != nullptr) {
            if (nykyinen->next == poistettava) {
                nykyinen->next = poistettava->next;
                delete poistettava;
                return;
            }
            nykyinen = nykyinen->next;
        }
    }

    void tulosta() {
        Seuraaja* nykyinen = seuraajat;
        while (nykyinen != nullptr) {
            cout << "Seuraaja: " << nykyinen->getNimi() << endl;
            nykyinen = nykyinen->next;
        }
    }

    void postita(string viesti) {
        Seuraaja* nykyinen = seuraajat;
        while (nykyinen != nullptr) {
            nykyinen->paivitys(viesti);
            nykyinen = nykyinen->next;
        }
    }

private:
    Seuraaja* seuraajat;
};

int main() {
    Notifikaattori n;

    Seuraaja* s1 = new Seuraaja("A");
    Seuraaja* s2 = new Seuraaja("B");
    Seuraaja* s3 = new Seuraaja("C");

    n.lisaa(s1);
    n.lisaa(s2);
    n.lisaa(s3);

    cout << "Kaikki seuraajat:" << endl;
    n.tulosta();

    cout << "\nLähetetään viesti kaikille seuraajille:" << endl;
    n.postita("Tervetuloa!");

    cout << "\nPoistetaan seuraaja B:" << endl;
    n.poista(s2);

    cout << "\nKaikki seuraajat poistamisen jälkeen:" << endl;
    n.tulosta();

    return 0;
}
