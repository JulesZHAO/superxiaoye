#include"Table.h"
#include"Controller.h"


void Table::put(Stone stone, ClanCard* card){
    stone.add_Card(card);
    Controller::getController(true).remove_card_played_v2(card);
}

void Table::showPlayerHand(int player){
    Player* currentplayer = (player==2) ? player1 : player2;
    
}