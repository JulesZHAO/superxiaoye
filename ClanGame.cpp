#include "ClanGame.h"
#include "ClanCard.h"

ClanGame::ClanGame(){
    size_t i = 0;
    for (auto c : Colors)
        for (auto n : Numbers)
            cards[i++] = new ClanCard(n,c);
}

ClanGame::~ClanGame(){
    for (size_t i = 0; i < getNbCards(); i++)
        delete cards[i];
}

ClanGame& ClanGame::getClanGame(){
    if (processor.game == nullptr)
        processor.game = new ClanGame;
    return *processor.game;
}

//释放先前创建的TecGame实例的内存，并将实例指针设置为nullptr。
void ClanGame::freeClanGame(){
    delete processor.game;
    processor.game = nullptr;
}

ClanGame::Processor ClanGame::processor = Processor();