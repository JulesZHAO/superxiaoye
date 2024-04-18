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
            if(getName() == "ä���ƾ�") cout<<"| Blind Bluff |";
            else if(getName() == "�ཬ����") cout<<"| Mud Fight |";
        }
        void showDisCard() const {
            cout<<"| ս�� |";
        }
};