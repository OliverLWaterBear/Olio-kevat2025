#include <iostream>
#include <cstdlib>
#include <ctime>

int game(int maxnum) {
    std::srand(std::time(0));
    int satunnainenLuku = std::rand() % maxnum + 1;
    int arvaus = 0;
    int arvausLaskuri = 0;

    std::cout << "Arvaa luku valilla 1-" << maxnum << "." << std::endl;

    while (true) {
        std::cout << "Anna arvauksesi: ";
        std::cin >> arvaus;
        arvausLaskuri++;

        if (arvaus < satunnainenLuku) {
            std::cout << "Luku on suurempi kuin arvauksesi." << std::endl;
        } else if (arvaus > satunnainenLuku) {
            std::cout << "Luku on pienempi kuin arvauksesi." << std::endl;
        } else {
            std::cout << "Oikein! Arvasit luvun " << satunnainenLuku
                      << " " << arvausLaskuri << " arvauksella." << std::endl;
            break;
        }
    }

    return arvausLaskuri;
}

int main() {
    int maxnum;
    std::cout << "Anna suurin mahdollinen etsittava luku: ";
    std::cin >> maxnum;

    int arvauksia = game(maxnum);

    std::cout << "Peli paattyi. Kaytit " << arvauksia << " arvausta." << std::endl;
    return 0;
}
