#pragma once
#include"TecCard.h"
#include"Stone.h"

using namespace std;
class BattleCard : public TecCard {
    public:
        BattleCard(const string& name): TecCard(name) {};
        
        static void play_BlindBluff(Stone* b) {b->setBlindBluff(true);}
        static void play_MudFight(Stone* b) {b->setMudFight(true);}

        void showCard() const {
            if(getName() == "盲人牌局") cout<<"| Blind Bluff |";
            else if(getName() == "泥浆搏斗") cout<<"| Mud Fight |";
        }
        void showDisCard() const {
            cout<<"| 战术 |";
        }
};