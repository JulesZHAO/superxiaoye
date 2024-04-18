#include <iostream>
#include "Controller.h"
#include <iostream>
#include "ClanCard.h"
#include "BattleCard.h"
#include "CardEliteGroup.h"
#include "Stone.h"
#include "Combination.h"
#include "SetException.h"
#include "Controller.h"
#include "CunningCard.h"
#include "Table.h"
#include "Hand.h"
#include "Player.h"
#include "Rest.h"

#include <typeinfo>
#include <stdlib.h>
#ifdef __unix__
# include <unistd.h>
#elif defined _WIN32
# include <windows.h>
#define sleep(x) Sleep(1000 * (x))
#endif


using namespace std;


void launchClassicGame(bool againstAI) {
    std::cout << "Launching Classic Game " << againstAI << std::endl;
    Controller& c = Controller::getController(false);
    c.startClassicGame();
    if (againstAI) {
        while (!c.checkEndGame()) {
            c.PlayClassicTurn1();
            if (c.checkEndGame()) {
                break;
            }
            c.getTable()->setCurrentPlayer(2);
            c.PlayClassicAI();
            c.getTable()->setCurrentPlayer(1);
        }
        std::cout << "Game Over" << std::endl;
        std::cout << "Player " << c.getWinner() << " wins" << std::endl;
        c.endGame();
    }
    else {
        while (!c.checkEndGame()) {
            c.PlayClassicTurn1();
            if (c.checkEndGame()) {
                break;
            }
            c.getTable()->setCurrentPlayer(2);
            c.PlayClassicTurn2();
            c.getTable()->setCurrentPlayer(1);
        }
        std::cout << "Game Over" << std::endl;
        std::cout << "Player " << c.getWinner() << " wins" << std::endl;
        c.endGame();
    }
}

void launchTacticalGame(bool againstAI) {
    std::cout << "Launching Tactical Game " << againstAI << std::endl;
    Controller& c = Controller::getController(true);
    c.starttecGame();
    if (againstAI) {
        while (!c.checkEndGame()) {
            c.PlayTurn1();
            if (c.checkEndGame()) {
                break;
            }
            c.getTable()->setCurrentPlayer(2);
            c.PlayClassicAI();
            c.getTable()->setCurrentPlayer(1);
        }
        std::cout << "Game Over" << std::endl;
        std::cout << "Player " << c.getWinner() << " wins" << std::endl;
        c.endGame();
    }
    else {
        while (!c.checkEndGame()) {
            c.PlayTurn1();
            if (c.checkEndGame()) {
                break;
            }
            c.getTable()->setCurrentPlayer(2);
            c.PlayTurn2();
            c.getTable()->setCurrentPlayer(1);
        }
        std::cout << "Game Over" << std::endl;
        std::cout << "Player " << c.getWinner() << " wins" << std::endl;
        c.endGame();
    }
}



int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;

    while (true) {
        system("CLS");
        std::cout << "=== Menu ===" << std::endl;
        std::cout << "1. classic game with human" << std::endl;
        std::cout << "2. classic game with AI" << std::endl;
        std::cout << "3. tactical game with human" << std::endl;
        std::cout << "4. tactical game with AI" << std::endl;
        std::cout << "5. exit" << std::endl;

        int choice;
        std::cout << "input your choice : ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            launchClassicGame(false);
            break;
        case 2:
            launchClassicGame(true);
            break;
        case 3:
            launchTacticalGame(false);
            break;
        case 4:
            launchTacticalGame(true);
            break;
        case 5:
            std::cout << "�ټ� !" << std::endl;
            std::exit(0);
        default:
            std::cout << "ѡ����Ч�������³���" << std::endl;
        }
    }
    return 0;
}


