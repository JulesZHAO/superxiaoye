#include "TecGame.h"

TecGame::TecGame(){
    size_t i = 0;

    //盲人牌局：将其置于石头上时，该石头的争夺只比较三张牌的大�?
    cards[i++] = new BattleCard("Blind Bluff");
    //Mud Fight泥斗 ：将其置于石头上时，该石头的争夺将变为两侧放置四张牌�?
    cards[i++] = new BattleCard("Mud Fight");
    //Recruiter招募者：从氏族或者战术排堆中总共选择三张牌加入手牌，并选择你手牌中的两张牌放入对应的牌堆底（诸葛亮观星）；
    cards[i++] = new CunningCard("Recruiter");
    //Strategis战略家：在还未被夺取的石头的两侧或上方选择一张牌，将其放在另一个还未被夺取的石头两侧或者上方，也可以将该牌丢弃
    cards[i++] = new CunningCard("Strategis");
    //Banshee女妖：在还未被夺取的石头的对手侧选择一张牌，将其丢弃；
    cards[i++] = new CunningCard("Banshee");
    //Traiter 叛徒：在还未被夺取的石头的对手侧选择一张牌，将其放在自己的一�?
    cards[i++] = new CunningCard("Traiter");

    //Joker小丑卡：有两张。可以在结算石头时任意选择颜色和大小，
    //每局游戏每个玩家只能出一次小丑，若已出过一张小丑并有另一张，则只能将小丑留在手牌内�?
    cards[i++] = new CardEliteGroup("Joker", Number::zero, Color::black);
    cards[i++] = new CardEliteGroup("Joker", Number::zero, Color::black);
    //Spy间谍：大小为7，可以在结算石头时任意选择颜色�?
    cards[i++] = new CardEliteGroup("Spy", Number::zero, Color::black);
    //Shield-Beare持盾者：在结算石头时选择颜色和大小，大小只能�?1�?2�?3�?
    cards[i++] = new CardEliteGroup("Shield-Beare", Number::zero, Color::black);
    
}

TecGame::~TecGame(){
    for (size_t i = 0; i < getNbCards(); i++)
        delete cards[i];
}

TecGame& TecGame::getTecGame(){
    if (processor.game == nullptr)
        processor.game = new TecGame;
    return *processor.game;
}

//释放先前创建的TecGame实例的内存，并将实例指针设置为nullptr�?
void TecGame::freeTecGame(){
    delete processor.game;
    processor.game = nullptr;
}

TecGame::Processor TecGame::processor = Processor();