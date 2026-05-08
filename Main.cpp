#include "chess.h"
#include <iostream>
using namespace std;
int main() {
    Menu::loadingScreen();
    int choice;

    while (true) {
        Console::clearScreen();
        Menu::menuScreen();

        cout << Style::GREEN << "\nEnter Choice: " << Style::RESET;
        cin >> choice;

        switch (choice) {
        case 1: {
            ChessGame game;
            game.play();
            break;
        }

        case 2: {
            Console::clearScreen();

            cout << Style::CYAN;
            cout << "\n=========== INSTRUCTIONS ===========\n";
            cout << "\n1. Enter moves like e2 e4";
            cout << "\n2. White moves first";
            cout << "\n3. Protect your king";
            cout << "\n4. Type quit to exit";
            cout << Style::RESET;

            cin.ignore();
            cin.get();

            break;
        }

        case 3: {
            Console::clearScreen();

            cout << Style::MAGENTA;
            cout << "\n=========== ABOUT PROJECT ===========\n";
            cout << "\nC++ Chess Game";
            cout << "\nPure OOP Concepts";
            cout << "\nUnicode Console UI";
            cout << Style::RESET;

            cin.ignore();
            cin.get();

            break;
        }

        case 4: {
            Console::clearScreen();

            cout << Style::RED;
            cout << "\nThanks For Playing Chess!\n";
            cout << Style::RESET;

            return 0;
        }

        default:
            cout << Style::RED << "\nInvalid Choice!\n" << Style::RESET;
            Console::sleepMs(1000);
        }
    }

    return 0;
}