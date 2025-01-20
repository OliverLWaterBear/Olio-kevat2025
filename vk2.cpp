#include <iostream>
#include <cstdlib>
#include <ctime>

class Game {
private:
    int maxNumber;
    int randomNumber;
    int playerGuess;
    int numOfGuesses;

public:
    Game(int maxNumber) : maxNumber(maxNumber), playerGuess(0), numOfGuesses(0) {
        std::srand(std::time(0));
        randomNumber = std::rand() % maxNumber + 1;
        std::cout << "PELIALOITUS: Objekti alustettu maksimiluvulla " << maxNumber << "\n";
    }

    ~Game() {
        std::cout << "PELIN LOPETUS: Objekti poistettu muistista\n";
    }

    void play() {
        std::cout << "Arvaa luku välillä 1 ja " << maxNumber << ":\n";
        while (true) {
            std::cout << "Anna arvauksesi: ";
            std::cin >> playerGuess;
            numOfGuesses++;

            if (playerGuess < randomNumber) {
                std::cout << "Arvauksesi on liian pieni\n";
            } else if (playerGuess > randomNumber) {
                std::cout << "Arvauksesi on liian suuri\n";
            } else {
                std::cout << "Oikein! Arvasit luvun oikein.\n";
                break;
            }
        }
    }

    void printGameResult() {
        std::cout << "Arvasit oikean luvun = " << randomNumber
                  << " " << numOfGuesses << " arvauksella\n";
    }
};

int main() {
    int maxNumber;

    std::cout << "Anna pelin maksimiluku: ";
    std::cin >> maxNumber;

    Game game(maxNumber);
    game.play();
    game.printGameResult();

    return 0;
}
