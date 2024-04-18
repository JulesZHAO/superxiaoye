#include "CunningCard.h"
#include "Controller.h"
#include "Hand.h"
#include <random>
#include "Card.h"

int generateRandomNumber2() {
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> distribution(1, 100);
    return distribution(rng);
}

void Supp_PushClanCardTactique(){
    vector<Card*> cardsHgetHand = Controller::getController(true).getTable()->getPlayer1()->getHand()->getCards();
    std::cout << "请选择您要删除的卡牌 (输入其ID)：" << endl;
    int choix_card, nb_tac = 0, nb_clan = 0, nb_total = 0;
    std::cin >> choix_card;
    while (choix_card >= cardsHgetHand.size() || choix_card < 0) {
        std::cout << "您没有这张卡牌，请选择您拥有的卡牌：" << endl;
        std::cin >> choix_card;
    }
    vector<Card*> cards =  Controller::getController(true).getTable()->getPlayer1()->getHand()->getCards();
     Card*  card = cards[choix_card];
    auto a =Controller::getController(true).getTecRest()->getCards();
     if (CardEliteGroup * CardEliteGroupChoisie = dynamic_cast<CardEliteGroup*>(card)){

         Controller::getController(true).getTecRest()->setM_nb(Controller::getController(true).getTecRest()->getNbCards() + 1);
         std::cout << "牌堆中有 " << Controller::getController(true).getTecRest()->getNbCards() << " 张牌。" << endl;
         // 我们将它放回到牌堆中
         a[Controller::getController(true).getTecRest()->getNbCards()]= reinterpret_cast<const Card*>(&card);
         Controller::getController(true).getTable()->getPlayer1()->getHand()->remove(choix_card);
     }

    else if (ClanCard* ClanCardChoisie = dynamic_cast<ClanCard*>(card)) {
        Controller::getController(false).getClanRest()->push_back(card);
        Controller::getController(true).getTable()->getPlayer1()->getHand()->remove(choix_card);
}
    else {


        Controller::getController(true).getTecRest()->setM_nb(Controller::getController(true).getTecRest()->getNbCards() + 1);
        std::cout << "牌堆中有 " << Controller::getController(true).getTecRest()->getNbCards() << " 张牌。" << endl;
        // 我们将它放回到牌堆中
        a[Controller::getController(true).getTecRest()->getNbCards()]= reinterpret_cast<const Card*>(&card);
        Controller::getController(true).getTable()->getPlayer1()->getHand()->remove(choix_card);
    }
}
void Supp_PushClanCardTactique2(){
    vector<Card*> cardsHgetHand = Controller::getController(true).getTable()->getPlayer2()->getHand()->getCards();
    std::cout << "您没有这张卡牌，请选择您拥有的卡牌：" << endl;
    int choix_card, nb_tac = 0, nb_clan = 0, nb_total = 0;
    std::cin >> choix_card;
    while (choix_card >= cardsHgetHand.size() || choix_card < 0) {
        std::cout << "您没有这张卡牌，请选择您拥有的卡牌：" << endl;
        std::cin >> choix_card;
    }
    vector<Card*> cards =  Controller::getController(true).getTable()->getPlayer2()->getHand()->getCards();
    Card*  card = cards[choix_card];
    auto a =Controller::getController(true).getTecRest()->getCards();
    if (CardEliteGroup * CardEliteGroupChoisie = dynamic_cast<CardEliteGroup*>(card)){

        Controller::getController(true).getTecRest()->setM_nb(Controller::getController(true).getTecRest()->getNbCards() + 1);
        std::cout << "牌堆中有 " << Controller::getController(true).getTecRest()->getNbCards() << " 张牌。" << endl;
        // 我们将它放回到牌堆中
        a[Controller::getController(true).getTecRest()->getNbCards()]= reinterpret_cast<const Card*>(&card);
        Controller::getController(true).getTable()->getPlayer2()->getHand()->remove(choix_card);
    }

    else if (ClanCard* ClanCardChoisie = dynamic_cast<ClanCard*>(card)) {
        Controller::getController(false).getClanRest()->push_back(card);
        Controller::getController(true).getTable()->getPlayer2()->getHand()->remove(choix_card);
    }
    else {


        Controller::getController(true).getTecRest()->setM_nb(Controller::getController(true).getTecRest()->getNbCards() + 1);
        std::cout << "牌堆中有 " << Controller::getController(true).getTecRest()->getNbCards() << "  张牌。" << endl;
        // 我们将它放回到牌堆中
        a[Controller::getController(true).getTecRest()->getNbCards()]= reinterpret_cast<const Card*>(&card);
        Controller::getController(true).getTable()->getPlayer2()->getHand()->remove(choix_card);
    }
}

void Supp_PushClanCardTactiqueIA(){
    vector<Card*> cardsHgetHand = Controller::getController(true).getTable()->getPlayer2()->getHand()->getCards();

    int choix_card, nb_tac = 0, nb_clan = 0, nb_total = 0;
    choix_card = generateRandomNumber2()%cardsHgetHand.size()+1;
    while (choix_card >= cardsHgetHand.size() || choix_card < 0) {
        choix_card = generateRandomNumber2()%cardsHgetHand.size()+1;
    }
    vector<Card*> cards =  Controller::getController(true).getTable()->getPlayer2()->getHand()->getCards();
    Card* card = cards[choix_card];
    auto a =Controller::getController(true).getTecRest()->getCards();
    if (CardEliteGroup * CardEliteGroupChoisie = dynamic_cast<CardEliteGroup*>(card)){

        Controller::getController(true).getTecRest()->setM_nb(Controller::getController(true).getTecRest()->getNbCards() + 1);
        std::cout << "牌堆中有 " << Controller::getController(true).getTecRest()->getNbCards() << "  张牌。" << endl;
        // 我们将它放回到牌堆中
        a[Controller::getController(true).getTecRest()->getNbCards()]= reinterpret_cast<const Card*>(&card);
        Controller::getController(true).getTable()->getPlayer2()->getHand()->remove(choix_card);
    }

    else if (ClanCard* ClanCardChoisie = dynamic_cast<ClanCard*>(card)) {
        Controller::getController(false).getClanRest()->push_back(card);
        Controller::getController(true).getTable()->getPlayer2()->getHand()->remove(choix_card);
    }
    else {


        Controller::getController(true).getTecRest()->setM_nb(Controller::getController(true).getTecRest()->getNbCards() + 1);
        std::cout << "Il y a " << Controller::getController(true).getTecRest()->getNbCards() << " cards dans le paquet" << endl;
        // 我们将它放回到牌堆中
        a[Controller::getController(true).getTecRest()->getNbCards()]= reinterpret_cast<const Card*>(&card);
        Controller::getController(true).getTable()->getPlayer2()->getHand()->remove(choix_card);
    }
}

void CunningCard::Play_ChasseurdeTeteIA(){
    std::cout << "AI通牌了“猎头”卡片。" << endl;
    int nbClanCard = generateRandomNumber2()%3+1;
    while (nbClanCard>3 || nbClanCard<0){
        nbClanCard = generateRandomNumber2()%3+1;
    }
    int nbTac = 3 - nbClanCard;
    int NagetNamebreTecCard =  Controller::getController(true).getTecRest()->getNbCards();

    while (NagetNamebreTecCard -nbTac <0){
        std::cout << "你不能抽取比牌堆中剩余牌数量更多的牌" << endl;
        std::cout  << "请先选择你想要抽取的克兰牌数量：" << endl;
        nbClanCard = generateRandomNumber2()%3+1;
        nbTac = 3 - nbClanCard;
    }
    switch(nbClanCard){
        case 0 : {
            for (int i = 0 ; i<3;i++){
                switch (Controller::getController(true).getTecRest()->whendrawpayattention()) {
                    case 1: {
                        std::cout << "AI抽取了战术牌：" << endl;
                        TecCard * a = new TecCard(Controller::getController(true).getTecRest()->drawTecCard());
                        Controller::getController(true).getTable()->getPlayer2()->getHand()->add(a);
                        std::cout << a->getName() << endl;
                        break;
                    }
                    case 2: {
                        std::cout << "AI抽取了精英部队牌：" << endl;
                        CardEliteGroup * b = new CardEliteGroup(Controller::getController(true).getTecRest()->drawCardEliteGroup());
                        Controller::getController(true).getTable()->getPlayer2()->getHand()->add(b);
                        std::cout << b->getName() << endl;
                        break;
                    }
                }
            }
            break;}
        case 1:{
            ClanCard* c11 = new ClanCard(Controller::getController(false).getClanRest()->drawClanCard());
            std::cout <<"卡牌抽取成功： "<< c11->getNumber() <<" "<< c11->getColor() << endl;
            Controller::getController(false).getTable()->getPlayer2()->getHand()->add(c11);

            for (int i = 0 ; i<2;i++){
                switch (Controller::getController(true).getTecRest()->whendrawpayattention()) {
                    case 1: {
                        std::cout << "AI抽到了战术卡牌 :" << endl;
                        TecCard * a = new TecCard(Controller::getController(true).getTecRest()->drawTecCard());
                        Controller::getController(true).getTable()->getPlayer2()->getHand()->add(a);
                        std::cout << a->getName() << endl;
                        break;
                    }
                    case 2: {
                        std::cout << "AI抽到了精英部队卡牌 :" << endl;
                        CardEliteGroup * b = new CardEliteGroup(Controller::getController(true).getTecRest()->drawCardEliteGroup());
                        Controller::getController(true).getTable()->getPlayer2()->getHand()->add(b);
                        std::cout << b->getName() << endl;
                        break;
                    }
                }
            }
            break;}
        case 2: {
            ClanCard *c21 = new ClanCard(Controller::getController(false).getClanRest()->drawClanCard());
            Controller::getController(false).getTable()->getPlayer2()->getHand()->add(c21);
            std::cout << "抽到的卡牌 : " << c21->getNumber() << " " << c21->getColor() << endl;
            ClanCard *c22 = new ClanCard(Controller::getController(false).getClanRest()->drawClanCard());
            Controller::getController(false).getTable()->getPlayer2()->getHand()->add(c22);
            std::cout << "抽到的卡牌 : " << c22->getNumber() << " " << c22->getColor() << endl;
            switch (Controller::getController(true).getTecRest()->whendrawpayattention()) {
                case 1: {
                    std::cout << "AI抽到了战术牌 :" << endl;
                    TecCard * a = new TecCard(Controller::getController(true).getTecRest()->drawTecCard());
                    Controller::getController(true).getTable()->getPlayer2()->getHand()->add(a);
                    std::cout << a->getName() << endl;
                    break;
                }
                case 2: {
                    std::cout << "AI抽到了精英部队牌 :" << endl;
                    CardEliteGroup * b = new CardEliteGroup(Controller::getController(true).getTecRest()->drawCardEliteGroup());
                    Controller::getController(true).getTable()->getPlayer2()->getHand()->add(b);
                    std::cout << b->getName() << endl;
                    break;
                }
            }
            break;
        }
        case 3: {
            ClanCard* c31 = new ClanCard(Controller::getController(false).getClanRest()->drawClanCard());
            Controller::getController(false).getTable()->getPlayer2()->getHand()->add(c31);
            std::cout <<"抽到的牌 : "<< c31->getNumber() <<" "<< c31->getColor() << endl;
            ClanCard* c32 = new ClanCard(Controller::getController(false).getClanRest()->drawClanCard());
            Controller::getController(false).getTable()->getPlayer2()->getHand()->add(c32);
            std::cout <<"抽到的牌 : "<< c32->getNumber() <<" "<< c32->getColor() << endl;
            ClanCard* c33 = new ClanCard(Controller::getController(false).getClanRest()->drawClanCard());
            Controller::getController(false).getTable()->getPlayer2()->getHand()->add(c33);
            std::cout <<"抽到的牌 : "<< c33->getNumber() <<" "<< c33->getColor() << endl;
        }
    }
    Supp_PushClanCardTactiqueIA();
    Supp_PushClanCardTactiqueIA();
}

void CunningCard::Play_StrategeIA() {
     std::cout << "AI决定打出了战略卡" << endl;

     int choix_stone, choix_card;
     choix_stone = rand() % 8 + 1;
    while ((choix_stone>8 || choix_stone<0) ||Controller::getController(true).getTable()->getStones(
            choix_stone)->getcardp2()->getCards().empty()) {
            choix_stone = generateRandomNumber2() % 8 + 1;
     }

     auto cardsgetStones = Controller::getController(true).getTable()->getStones(
             choix_stone)->getcardp2()->getCards();
     choix_card = generateRandomNumber2() % cardsgetStones.size();

     while (choix_card > cardsgetStones.size() - 1 || choix_card < 0) {
         choix_card = generateRandomNumber2() % cardsgetStones.size();
     }
     auto card_choisie = Controller::getController(true).getTable()->getStones(
             choix_stone)->getcardp2()->getCards()[choix_card];
    std::cout << "AI选择了这张卡片 : " << card_choisie->getColor() << " " << card_choisie->getNumber() << endl;

     Controller::getController(true).getTable()->getStones(choix_stone)->getcardp2()->DeleteCard_Stone(
             choix_card);
     int choix;
     choix =generateRandomNumber2() % 2 + 1;

     //我们将卡片放在另一个终端上
     if (choix == 2) {

         choix_stone = rand() % 8 + 1;
         while(Controller::getController(true).getTable()->getStones(choix_stone)->getrevendique()!=0 && (choix_stone<0 && choix_stone>8)){
             choix_stone = generateRandomNumber2() % 8 + 1;
         }
         Controller::getController(true).getTable()->getStones(choix_stone)->getcardp2()->addCard(card_choisie);
            std::cout << "AI选择把卡片放在终端上 " << choix_stone << endl;
     }
         //我们弃掉该张牌
     else{

         delete card_choisie;
            std::cout << "AI选择弃掉这张卡片" << endl;

     }
        std::cout << "这是对手的生命值 : " << endl;
        Controller::getController(true).getTable()->showStones(2);
}
void CunningCard::Play_BansheeIA() {
    std::cout << "AI打出了幽灵卡" << endl;
    int choix_stone, choix_card;
    choix_stone = generateRandomNumber2() % 9 ;

    while (Controller::getController(true).getTable()->getStones(
            choix_stone)->getcardp1()->getCards().empty() || Controller::getController(true).getTable()->getStones(choix_stone)->getrevendique()!=0) {
        choix_stone = generateRandomNumber2() % 9;
    }
    while (choix_stone > 8 || choix_stone < 0) {
        choix_stone = generateRandomNumber2() % 9;

    }

    auto cardsgetStones = Controller::getController(true).getTable()->getStones(choix_stone)->getcardp1()->getCards();
    int taille_stone = cardsgetStones.size();
    choix_card = generateRandomNumber2() % taille_stone;

    while (choix_card >= cardsgetStones.size() || choix_card < 0) {
        choix_card = generateRandomNumber2() % taille_stone;
    }


    auto card_choisie = Controller::getController(true).getTable()->getStones(
            choix_stone)->getcardp1()->getCards()[choix_card];
    std::cout << "AI选择移除该卡片 : " << card_choisie->getColor() << " " << card_choisie->getNumber() << " 从终端/自助设备 "<< choix_stone<< endl;
    Controller::getController(true).getTable()->getStones(choix_stone)->getcardp1()->DeleteCard_Stone(choix_card);
}
 void CunningCard::Play_TraitreIA() {
     std::cout << "人工智能出卖了自己的牌" << endl;
     int choix_stone, choix_card;
     choix_stone = generateRandomNumber2() % 9;

     while ((choix_stone > 8 || choix_stone < 0) || Controller::getController(true).getTable()->getStones(
             choix_stone)->getcardp1()->getCards().empty() || Controller::getController(true).getTable()->getStones(choix_stone)->getrevendique()!=0 ) {
         choix_stone = generateRandomNumber2() % 9;
     }

     auto cardsgetStones = Controller::getController(true).getTable()->getStones(choix_stone)->getcardp1()->getCards();

     int taille_stone = cardsgetStones.size();
     choix_card = generateRandomNumber2() % taille_stone;

     while (choix_card >= cardsgetStones.size()|| choix_card < 0) {
         choix_card = generateRandomNumber2() % taille_stone;
     }

     vector<Card*> cardsHgetHand = Controller::getController(true).getTable()->getPlayer2()->getHand()->getCards();
     vector<Card*> cards = Controller::getController(true).getTable()->getPlayer2()->getHand()->getCards();
     Card* card = cards[choix_card];
     int a =0;
     while(a==0) {
         if (ClanCard *ClanCardChoisie = dynamic_cast<ClanCard *>(card)) {
             a=1;
             auto card_choisie = Controller::getController(false).getTable()->getStones(
                     choix_stone)->getcardp1()->getCards()[choix_card];
             Controller::getController(true).getTable()->getStones(choix_stone)->getcardp1()->DeleteCard_Stone(
                     choix_card);
             std::cout << "你想把你的卡放在哪个未声明的终点上 ? " << endl;
             choix_stone = generateRandomNumber2() % 9;
             while ((Controller::getController(true).getTable()->getStones(choix_stone)->getcardp2()->getCards().size()==3) || (choix_stone > 8 || choix_stone < 0) || Controller::getController(true).getTable()->getStones(choix_stone)->getrevendique() != 0) {
                 std::cout << "您不能把卡放在这个终点上，请选择另一个 : " << endl;
                 choix_stone = generateRandomNumber2() % 9;
             }

             Controller::getController(true).getTable()->getStones(choix_stone)->getcardp2()->addCard(
                     card_choisie);
         } else {
             std::cout << "您不能选择这张卡，请选择另一张 : " << endl;
             choix_card = generateRandomNumber2() % taille_stone;

         }
     }
}


void CunningCard::Play_ChasseurdeTete() {
    std::cout << "您打出了猎头卡牌" << endl;
    std::cout  << "请选择您想要抽取的氏族卡牌数量 :" << endl;
    int nbClanCard;
    std::cin >> nbClanCard;
    while (nbClanCard>3 || nbClanCard<0){
        std::cout << "您不能抽取超过或少于3张卡牌" << endl;
        std::cout  << "请先选择您想要抽取的氏族卡牌数量 :" << endl;
        std::cin >> nbClanCard;}

    int nbTac = 3 - nbClanCard;
    int NagetNamebreTecCard =  Controller::getController(true).getTecRest()->getNbCards();
    std::cout << "剩余 " << NagetNamebreTecCard << " 张战术牌 " << endl;
    while (NagetNamebreTecCard -nbTac <0){
            std::cout << "您不能抽取超过牌堆中已有的数量" << endl;
            std::cout  << "请先选择您想要抽取的氏族卡牌数量 :" << endl;
            std::cin >> nbClanCard;
            nbTac = 3 - nbClanCard;
        }

    switch(nbClanCard){
        case 0 : {
            for (int i = 0 ; i<3;i++){
            switch (Controller::getController(true).getTecRest()->whendrawpayattention()) {
                case 1: {
                    std::cout << "您已经抽取了战术牌 :" << endl;
                    TecCard * a = new TecCard(Controller::getController(true).getTecRest()->drawTecCard());
                    Controller::getController(true).getTable()->getPlayer1()->getHand()->add(a);
                    std::cout << a->getName() << endl;
                    break;
                }
                case 2: {
                    std::cout << "您已经抽取了精英部队卡 :" << endl;
                    CardEliteGroup * b = new CardEliteGroup(Controller::getController(true).getTecRest()->drawCardEliteGroup());
                    Controller::getController(true).getTable()->getPlayer1()->getHand()->add(b);
                    std::cout << b->getName() << endl;
                    break;
                }
             }
            }
            break;}
        case 1:{
            ClanCard* c11 = new ClanCard(Controller::getController(false).getClanRest()->drawClanCard());
            std::cout <<"抽取的卡牌 : "<< c11->getNumber() <<" "<< c11->getColor() << endl;
            Controller::getController(false).getTable()->getPlayer1()->getHand()->add(c11);
            for (int i = 0 ; i<2;i++){
                switch (Controller::getController(true).getTecRest()->whendrawpayattention()) {
                    case 1: {
                        std::cout << "您抽到了战术卡 :" << endl;
                        TecCard * a = new TecCard(Controller::getController(true).getTecRest()->drawTecCard());
                        Controller::getController(true).getTable()->getPlayer1()->getHand()->add(a);
                        std::cout << a->getName() << endl;
                        break;
                    }
                    case 2: {
                        std::cout << "您抽到了精英部队卡 :" << endl;
                        CardEliteGroup * b = new CardEliteGroup(Controller::getController(true).getTecRest()->drawCardEliteGroup());
                        Controller::getController(true).getTable()->getPlayer1()->getHand()->add(b);
                        std::cout << b->getName() << endl;
                        break;
                    }
                }
            }

            break;}
        case 2: {
            ClanCard *c21 = new ClanCard(Controller::getController(false).getClanRest()->drawClanCard());
            Controller::getController(false).getTable()->getPlayer1()->getHand()->add(c21);
            std::cout << "抽到的卡牌 : " << c21->getNumber() << " " << c21->getColor() << endl;
            ClanCard *c22 = new ClanCard(Controller::getController(false).getClanRest()->drawClanCard());
            Controller::getController(false).getTable()->getPlayer1()->getHand()->add(c22);
            std::cout << "抽到的卡牌 : " << c22->getNumber() << " " << c22->getColor() << endl;
            switch (Controller::getController(true).getTecRest()->whendrawpayattention()) {
                case 1: {
                    std::cout << "你抽到了战术牌 :" << endl;
                    TecCard * a = new TecCard(Controller::getController(true).getTecRest()->drawTecCard());
                    Controller::getController(true).getTable()->getPlayer1()->getHand()->add(a);
                    std::cout << a->getName() << endl;
                    break;
                }
                case 2: {
                    std::cout << "你抽到了精英部队牌 :" << endl;
                    CardEliteGroup * b = new CardEliteGroup(Controller::getController(true).getTecRest()->drawCardEliteGroup());
                    Controller::getController(true).getTable()->getPlayer1()->getHand()->add(b);
                    std::cout << b->getName() << endl;
                    break;
                }
            }
            break;
        }
        case 3: {
            ClanCard* c31 = new ClanCard(Controller::getController(false).getClanRest()->drawClanCard());
            Controller::getController(false).getTable()->getPlayer1()->getHand()->add(c31);
            std::cout <<"抽到的卡牌 : "<< c31->getNumber() <<" "<< c31->getColor() << endl;
            ClanCard* c32 = new ClanCard(Controller::getController(false).getClanRest()->drawClanCard());
            Controller::getController(false).getTable()->getPlayer1()->getHand()->add(c32);
            std::cout <<"抽到的卡牌 : "<< c32->getNumber() <<" "<< c32->getColor() << endl;
            ClanCard* c33 = new ClanCard(Controller::getController(false).getClanRest()->drawClanCard());
            Controller::getController(false).getTable()->getPlayer1()->getHand()->add(c33);
            std::cout <<"抽到的卡牌 : "<< c33->getNumber() <<" "<< c33->getColor() << endl;

        }

    }
    std::cout << "您现在需要选择两张要从手牌中删除的卡牌" << endl;
    std::cout << "这是你当前手上的牌 :" << endl;
    Controller::getController(true).getTable()->showPlayerHand(1);
    Supp_PushClanCardTactique();
    std::cout << "这是你当前手上的牌 :" << endl;
    Controller::getController(true).getTable()->showPlayerHand(1);
    Supp_PushClanCardTactique();
}

void CunningCard::Play_ChasseurdeTete2() {
    std::cout << "您已经使用了猎头卡片" << endl;
    std::cout  << "请选择您想抽取的氏族牌数量 :" << endl;
    int nbClanCard;
    std::cin >> nbClanCard;
    while (nbClanCard>3 || nbClanCard<0){
        std::cout << "您不能抽取超过或少于 3 张牌" << endl;
        std::cout  << "请先选择您想抽取的氏族牌数量 :" << endl;
        std::cin >> nbClanCard;}

    int nbTac = 3 - nbClanCard;
    int NagetNamebreTecCard =  Controller::getController(true).getTecRest()->getNbCards();
    std::cout << "还剩下 " << NagetNamebreTecCard << " 张战术牌 " << endl;
    while (NagetNamebreTecCard -nbTac <0){
        std::cout << "您不能抽取超过牌堆中剩余数量的牌" << endl;
        std::cout  << "请先选择您想抽取的氏族牌数量 :" << endl;
        std::cin >> nbClanCard;
        nbTac = 3 - nbClanCard;
    }

    switch(nbClanCard){
        case 0 : {
            for (int i = 0 ; i<3;i++){
                switch (Controller::getController(true).getTecRest()->whendrawpayattention()) {
                    case 1: {
                        std::cout << "您抽取了战术卡 :" << endl;
                        TecCard * a = new TecCard(Controller::getController(true).getTecRest()->drawTecCard());
                        Controller::getController(true).getTable()->getPlayer2()->getHand()->add(a);
                        std::cout << a->getName() << endl;
                        break;
                    }
                    case 2: {
                        std::cout << "您抽取了精英部队卡 :" << endl;
                        CardEliteGroup * b = new CardEliteGroup(Controller::getController(true).getTecRest()->drawCardEliteGroup());
                        Controller::getController(true).getTable()->getPlayer2()->getHand()->add(b);
                        std::cout << b->getName() << endl;
                        break;
                    }
                }
            }
            break;}
        case 1:{
            ClanCard* c11 = new ClanCard(Controller::getController(false).getClanRest()->drawClanCard());
            std::cout <<"抽到的卡牌 : "<< c11->getNumber() <<" "<< c11->getColor() << endl;
            Controller::getController(false).getTable()->getPlayer2()->getHand()->add(c11);
            for (int i = 0 ; i<2;i++){
                switch (Controller::getController(true).getTecRest()->whendrawpayattention()) {
                    case 1: {
                        std::cout << "你抽到了战术牌 :" << endl;
                        TecCard * a = new TecCard(Controller::getController(true).getTecRest()->drawTecCard());
                        Controller::getController(true).getTable()->getPlayer2()->getHand()->add(a);
                        std::cout << a->getName() << endl;
                        break;
                    }
                    case 2: {
                        std::cout << "你抽到了精英部队牌 :" << endl;
                        CardEliteGroup * b = new CardEliteGroup(Controller::getController(true).getTecRest()->drawCardEliteGroup());
                        Controller::getController(true).getTable()->getPlayer2()->getHand()->add(b);
                        std::cout << b->getName() << endl;
                        break;
                    }
                }
            }

            break;}
        case 2: {
            ClanCard *c21 = new ClanCard(Controller::getController(false).getClanRest()->drawClanCard());
            Controller::getController(false).getTable()->getPlayer2()->getHand()->add(c21);
            std::cout << "抽到的卡牌 : " << c21->getNumber() << " " << c21->getColor() << endl;
            ClanCard *c22 = new ClanCard(Controller::getController(false).getClanRest()->drawClanCard());
            Controller::getController(false).getTable()->getPlayer2()->getHand()->add(c22);
            std::cout << "抽到的卡牌 : " << c22->getNumber() << " " << c22->getColor() << endl;
            switch (Controller::getController(true).getTecRest()->whendrawpayattention()) {
                case 1: {
                    std::cout << "你抽到了战术牌 :" << endl;
                    TecCard * a = new TecCard(Controller::getController(true).getTecRest()->drawTecCard());
                    Controller::getController(true).getTable()->getPlayer2()->getHand()->add(a);
                    std::cout << a->getName() << endl;
                    break;
                }
                case 2: {
                    std::cout << "你抽到了精英部队牌 :" << endl;
                    CardEliteGroup * b = new CardEliteGroup(Controller::getController(true).getTecRest()->drawCardEliteGroup());
                    Controller::getController(true).getTable()->getPlayer2()->getHand()->add(b);
                    std::cout << b->getName() << endl;
                    break;
                }
            }
            break;
        }
        case 3: {
            ClanCard* c31 = new ClanCard(Controller::getController(false).getClanRest()->drawClanCard());
            Controller::getController(false).getTable()->getPlayer2()->getHand()->add(c31);
            std::cout <<"抽到的卡牌 : "<< c31->getNumber() <<" "<< c31->getColor() << endl;
            ClanCard* c32 = new ClanCard(Controller::getController(false).getClanRest()->drawClanCard());
            Controller::getController(false).getTable()->getPlayer2()->getHand()->add(c32);
            std::cout <<"抽到的卡牌 : "<< c32->getNumber() <<" "<< c32->getColor() << endl;
            ClanCard* c33 = new ClanCard(Controller::getController(false).getClanRest()->drawClanCard());
            Controller::getController(false).getTable()->getPlayer2()->getHand()->add(c33);
            std::cout <<"抽到的卡牌 : "<< c33->getNumber() <<" "<< c33->getColor() << endl;

        }

    }
    std::cout << "你现在需要选择两张手牌并将其丢弃" << endl;
    std::cout << "这是您当前的手牌 :" << endl;
    Controller::getController(true).getTable()->showPlayerHand(2);
    Supp_PushClanCardTactique2();
    std::cout << "这是您当前的手牌 :" << endl;
    Controller::getController(true).getTable()->showPlayerHand(2);
    Supp_PushClanCardTactique2();
}
void CunningCard::Play_Stratege() {
    std::cout << "你打出了战略家卡片" << endl;
    std::cout << "这是您的所有终点 : " << endl;
    Controller::getController(true).getTable()->showStones(1);
    std::cout << "请选择一处未被认领的属于您的终点 " << endl;
    int choix_stone, choix_card;
    std::cin >> choix_stone;
    while ((choix_stone>8 || choix_stone<0) ||Controller::getController(true).getTable()->getStones(
            choix_stone)->getcardp1()->getCards().empty()) {
        std::cout << "您在这个终点上没有地图，请选择另一个终点 : " << endl;
        std::cin >> choix_stone;
    }

    auto cardsgetStones = Controller::getController(true).getTable()->getStones(
            choix_stone)->getcardp1()->getCards();
    for (int i = 0; i < cardsgetStones.size(); i++) {
        std::cout << "id :" << i << " " << cardsgetStones[i]->getColor() << " " << cardsgetStones[i]->getNumber()
             << endl;
    }
    std::cout << "您想从终点机器上取走哪张地图 "<< choix_stone << "?" << endl;
    std::cin >> choix_card;
    while (choix_card > cardsgetStones.size() - 1 || choix_card < 0) {
        std::cout << "该终端上没有地图可供选择，请选择另一个终端 : " << endl;
        std::cin >> choix_card;
    }
    auto card_choisie = Controller::getController(true).getTable()->getStones(
            choix_stone)->getcardp1()->getCards()[choix_card];
    std::cout << "您已选择地图 : " << card_choisie->getColor() << " " << card_choisie->getNumber()
         << endl;
    Controller::getController(true).getTable()->getStones(choix_stone)->getcardp1()->DeleteCard_Stone(
            choix_card);
    std::cout << "您想弃掉这张卡片还是放到另一个位置？ " << endl;
    std::cout << "1 : 弃掉卡片" << endl;
    std::cout << "2 : 将卡片放到另一个位置上" << endl;
    int choix;
    std::cin >> choix;
    if (choix == 2) {
            std::cout << "您想把卡片放在哪个未被认领的载体上？ " << endl;
            std::cin >> choix_stone;
            while(Controller::getController(true).getTable()->getStones(choix_stone)->getrevendique()!=0 && choix_stone<0 && choix_stone>8){
                std::cout << "您不能将卡片放在这个载体上，请选择另一个 : " << endl;
                std::cin >> choix_stone;
        }
            Controller::getController(true).getTable()->getStones(choix_stone)->getcardp1()->addCard(card_choisie);
    }
    else{
        std::cout << "您已弃牌 "<< card_choisie->getColor() << " " << card_choisie->getNumber()<< endl;
        delete card_choisie;
    }
}


void CunningCard::Play_Stratege2() {
    std::cout << "您打出了策略卡牌" << endl;
    std::cout << "这是您的所有边界 : " << endl;
    Controller::getController(true).getTable()->showStones(2);
    std::cout << "请选择一个未被认领的边界，属于您自己的 " << endl;
    int choix_stone, choix_card;
    std::cin >> choix_stone;
    while ((choix_stone>8 || choix_stone<0) ||Controller::getController(true).getTable()->getStones(
            choix_stone)->getcardp2()->getCards().empty()) {
        std::cout << "您在该边界没有卡牌，请选择另一个 : " << endl;
        std::cin >> choix_stone;
    }

    auto cardsgetStones = Controller::getController(true).getTable()->getStones(
            choix_stone)->getcardp2()->getCards();
    for (int i = 0; i < cardsgetStones.size(); i++) {
        std::cout << "id :" << i << " " << cardsgetStones[i]->getColor() << " " << cardsgetStones[i]->getNumber()
             << endl;
    }
    std::cout << "您想从边界上移除哪张卡牌 "<< choix_stone << "?" << endl;
    std::cin >> choix_card;
    while (choix_card > cardsgetStones.size() - 1 || choix_card < 0) {
        std::cout << "您在该边界没有卡牌，请选择另一个 : " << endl;
        std::cin >> choix_card;
    }
    auto card_choisie = Controller::getController(true).getTable()->getStones(
            choix_stone)->getcardp2()->getCards()[choix_card];
    std::cout << "您选择了卡牌 : " << card_choisie->getColor() << " " << card_choisie->getNumber()
         << endl;
    Controller::getController(true).getTable()->getStones(choix_stone)->getcardp2()->DeleteCard_Stone(
            choix_card);
    std::cout << "您想要将该卡牌弃掉还是放在其他边界上？ " << endl;
    std::cout << "1 : 弃掉该卡牌" << endl;
    std::cout << "2 : 放在其他边界上" << endl;
    int choix;
    std::cin >> choix;
    if (choix == 2) {
        std::cout << "您想要将卡牌放在哪个未被认领的边界上？ " << endl;
        std::cin >> choix_stone;
        while(Controller::getController(true).getTable()->getStones(choix_stone)->getrevendique()!=0 && choix_stone<0 && choix_stone>8){
            std::cout << "您不能将卡牌放在该边界上，请选择另一个： " << endl;
            std::cin >> choix_stone;
        }
        Controller::getController(true).getTable()->getStones(choix_stone)->getcardp2()->addCard(card_choisie);
    }
    else{
        std::cout << "您已经弃掉了卡牌 "<< card_choisie->getColor() << " " << card_choisie->getNumber()<< endl;
        delete card_choisie;
    }
}
void CunningCard::Play_Traitre() {
    std::cout << "您使用了卡牌叛徒" << endl;
    std::cout << "对手的边界如下 : " << endl;
    Controller::getController(true).getTable()->showStones(1);
    std::cout << "请选择一个对手未被认领的边界 " << endl;
    int choix_stone, choix_card;
    std::cin >> choix_stone;

    while ((choix_stone > 8 || choix_stone < 0) || Controller::getController(true).getTable()->getStones(
            choix_stone)->getcardp2()->getCards().empty() || Controller::getController(true).getTable()->getStones(choix_stone)->getrevendique()!=0 ) {
        std::cout << "对手在该边界没有卡牌，请选择其他边界 : " << endl;
        std::cin >> choix_stone;
    }
    auto cardsgetStones = Controller::getController(true).getTable()->getStones(
            choix_stone)->getcardp2()->getCards();
    for (int i = 0; i < cardsgetStones.size(); i++) {
        std::cout << "id :" << i << " " << cardsgetStones[i]->getColor() << " " << cardsgetStones[i]->getNumber()
             << endl;
    }
    std::cout << "请选择要从边界上移除的卡牌： "<< choix_stone << "?" << endl;
    std::cin >> choix_card;

    while (choix_card > cardsgetStones.size() - 1 || choix_card < 0 ) {
        std::cout << "您不能选择该卡牌，请选择其他卡牌： " << endl;
        std::cin >> choix_card;
    }
    vector<Card*> cardsHgetHand = Controller::getController(true).getTable()->getPlayer1()->getHand()->getCards();
    vector<Card*> cards = Controller::getController(true).getTable()->getPlayer1()->getHand()->getCards();
    Card* card = cards[choix_card];
    int a =0;
    while(a==0) {
        if (ClanCard *ClanCardChoisie = dynamic_cast<ClanCard *>(card)) {
            a=1;
            auto card_choisie = Controller::getController(false).getTable()->getStones(
                    choix_stone)->getcardp2()->getCards()[choix_card];
            std::cout << "您选择了卡牌: " << card_choisie->getColor() << " "
                 << card_choisie->getNumber()
                 << endl;
            Controller::getController(true).getTable()->getStones(choix_stone)->getcardp2()->DeleteCard_Stone(
                    choix_card);
            std::cout << "您想把卡牌放在哪个未声明的纽扣上？" << endl;
            std::cin >> choix_stone;
            while ((Controller::getController(true).getTable()->getStones(choix_stone)->getcardp1()->getCards().size()==3) || (choix_stone > 8 || choix_stone < 0) || Controller::getController(true).getTable()->getStones(choix_stone)->getrevendique() != 0) {
                std::cout << "您无法在此纽扣上放置卡片，请选择其他纽扣：" << endl;
                std::cin >> choix_stone;
            }

            Controller::getController(true).getTable()->getStones(choix_stone)->getcardp1()->addCard(
                    card_choisie);
        } else {
            std::cout << "您不能选择此卡牌，请选择其他卡牌：" << endl;
            std::cin >> choix_card;

        }
    }



}
void CunningCard::Play_Traitre2() {
    std::cout << "您已经使用了诡计卡片" << endl;
    std::cout << "对手的出生点是指对手的可接受范围或极限 : " << endl;
    Controller::getController(true).getTable()->showStones(2);
    std::cout << "请为对手选择一个未被索要的边界点 " << endl;
    int choix_stone, choix_card;
    std::cin >> choix_stone;

    while ((choix_stone > 8 || choix_stone < 0) || Controller::getController(true).getTable()->getStones(
            choix_stone)->getcardp1()->getCards().empty() || Controller::getController(true).getTable()->getStones(choix_stone)->getrevendique()!=0 ) {
        std::cout << "对手在这个边界点上没有卡片，请选择另一个 : " << endl;
        std::cin >> choix_stone;
    }
    auto cardsgetStones = Controller::getController(true).getTable()->getStones(
            choix_stone)->getcardp1()->getCards();
    for (int i = 0; i < cardsgetStones.size(); i++) {
        std::cout << "id :" << i << " " << cardsgetStones[i]->getColor() << " " << cardsgetStones[i]->getNumber()
             << endl;
    }
    std::cout << "您希望从边界点中移除哪张卡片 "<< choix_stone << "?" << endl;
    std::cin >> choix_card;

    while (choix_card > cardsgetStones.size() - 1 || choix_card < 0 ) {
        std::cout << "很抱歉，您无法选择该卡片，请选择另一张 : " << endl;
        std::cin >> choix_card;
    }
    vector<Card*> cardsHgetHand = Controller::getController(true).getTable()->getPlayer2()->getHand()->getCards();
    vector<Card*> cards = Controller::getController(true).getTable()->getPlayer2()->getHand()->getCards();
    Card* card = cards[choix_card];
    int a =0;
    while(a==0) {
        if (ClanCard *ClanCardChoisie = dynamic_cast<ClanCard *>(card)) {
            a=1;
            auto card_choisie = Controller::getController(false).getTable()->getStones(
                    choix_stone)->getcardp1()->getCards()[choix_card];
            std::cout << "您选择了该卡片 : " << card_choisie->getColor() << " "
                 << card_choisie->getNumber()
                 << endl;
            Controller::getController(true).getTable()->getStones(choix_stone)->getcardp1()->DeleteCard_Stone(
                    choix_card);
            std::cout << "你想把你的卡片放在哪个未占有的插槽上 ? " << endl;
            std::cin >> choix_stone;
            while ((Controller::getController(true).getTable()->getStones(choix_stone)->getcardp2()->getCards().size()==3) || (choix_stone > 8 || choix_stone < 0) || Controller::getController(true).getTable()->getStones(choix_stone)->getrevendique() != 0) {
                std::cout << "你不能在这个插槽上放置卡片，请选择另一个插槽 : " << endl;
                std::cin >> choix_stone;
            }

            Controller::getController(true).getTable()->getStones(choix_stone)->getcardp2()->addCard(
                    card_choisie);
        } else {
            std::cout << "你不能选择这张卡片，请选择另一张 : " << endl;
            std::cin >> choix_card;

        }
    }



}
void CunningCard::Play_Banshee() {
    std::cout << "你打出了女妖卡" << endl;
    std::cout << "这是对手的边界 : " << endl;
    Controller::getController(true).getTable()->showStones(1);
    std::cout << "请选择对手拥有但未被要求的边界 " << endl;
    int choix_stone, choix_card;
    std::cin >> choix_stone;

    while (Controller::getController(true).getTable()->getStones(
            choix_stone)->getcardp2()->getCards().empty() || Controller::getController(true).getTable()->getStones(choix_stone)->getrevendique()!=0) {
        std::cout << "对手在这个边界上没有卡片，请选择另一个边界 : " << endl;
        std::cin >> choix_stone;
    }
    while (choix_stone > 8 || choix_stone < 0) {
        std::cout << "你没有这个边界，请选择一个边界 :" << endl;
        std::cin >> choix_stone;
    }

    auto cardsgetStones = Controller::getController(true).getTable()->getStones(
            choix_stone)->getcardp2()->getCards();
    for (int i = 0; i < cardsgetStones.size(); i++) {
        std::cout << "id :" << i << " " << cardsgetStones[i]->getColor() << " " << cardsgetStones[i]->getNumber()
             << endl;
    }
    std::cout << "您想从边界机上取走哪张卡片 "<< choix_stone << "?" << endl;
    std::cin >> choix_card;
    while (choix_card > cardsgetStones.size() - 1 || choix_card < 0) {
        std::cout << "您不能选择该卡片，请选择另一张卡片 : " << endl;
        std::cin >> choix_card;
    }
    auto card_choisie = Controller::getController(true).getTable()->getStones(
            choix_stone)->getcardp2()->getCards()[choix_card];
    std::cout << "您已选择该卡片 : " << card_choisie->getColor() << " " << card_choisie->getNumber()
         << endl;
    Controller::getController(true).getTable()->getStones(choix_stone)->getcardp2()->DeleteCard_Stone(
            choix_card);

}
void CunningCard::Play_Banshee2() {
    std::cout << "您使用了女妖卡片" << endl;
    std::cout << "这是对手的控制点 : " << endl;
    Controller::getController(true).getTable()->showStones(2);
    std::cout << "请从对手的未被认领的控制点中选择一个 " << endl;
    int choix_stone, choix_card;
    std::cin >> choix_stone;

    while (Controller::getController(true).getTable()->getStones(
            choix_stone)->getcardp1()->getCards().empty() || Controller::getController(true).getTable()->getStones(choix_stone)->getrevendique()!=0) {
        std::cout << "对手在这个控制点上没有卡牌，请选择另一个控制点 : " << endl;
        std::cin >> choix_stone;
    }
    while (choix_stone > 8 || choix_stone < 0) {
        std::cout << "您没有该控制点，请输入另一个控制点 :" << endl;
        std::cin >> choix_stone;
    }

    auto cardsgetStones = Controller::getController(true).getTable()->getStones(
            choix_stone)->getcardp1()->getCards();
    for (int i = 0; i < cardsgetStones.size(); i++) {
        std::cout << "id :" << i << " " << cardsgetStones[i]->getColor() << " " << cardsgetStones[i]->getNumber()
             << endl;
    }
    std::cout << "您想从控制点取走哪张卡片 "<< choix_stone << "?" << endl;
    std::cin >> choix_card;
    while (choix_card > cardsgetStones.size() - 1 || choix_card < 0) {
        std::cout << "您无法选择该卡片，请选择另一张 : " << endl;
        std::cin >> choix_card;
    }
    auto card_choisie = Controller::getController(true).getTable()->getStones(
            choix_stone)->getcardp1()->getCards()[choix_card];
    std::cout << "你选择了这张卡片 : " << card_choisie->getColor() << " " << card_choisie->getNumber()
         << endl;
    Controller::getController(true).getTable()->getStones(choix_stone)->getcardp1()->DeleteCard_Stone(
            choix_card);

}