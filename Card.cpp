#include "Card.h"
#include "ClanCard.h"
#include "TecCard.h"
#include "vector"
#include "CardEliteGroup.h"

void show_vector_card(vector<Card*> v) {
    auto it = 0;
    for (auto card: v){
        if (CardEliteGroup* card_elite_group = dynamic_cast<CardEliteGroup*>(card)){
            cout<< it << " ÍõÅÆ£º " << card_elite_group->getNumber()<<card_elite_group->getColor()<<endl;
        }
        else if (ClanCard* clan_card = dynamic_cast<ClanCard*>(card)){
            cout<< it << " ²¿Âä¿¨Æ¬ " <<clan_card->getNumber()<<clan_card->getColor()<<endl;
        }
        else if (TecCard* tec_card = dynamic_cast<TecCard*>(card)){
            cout<< it << " Õ½Êõ¿¨Æ¬ " <<tec_card->getName()<<endl;
    }
    it++;
    }
}

void show_vector_card(vector<Card*> v){
    for (auto card: v){
        if (ClanCard* clan_card = dynamic_cast<ClanCard*>(card)){
            cout<< " ÊÏ×å¿¨ " <<clan_card->getNumber()<<clan_card->getColor()<<endl;
        }
    }
} 