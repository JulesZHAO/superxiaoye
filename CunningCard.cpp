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
    std::cout << "��ѡ����Ҫɾ���Ŀ��� (������ID)��" << endl;
    int choix_card, nb_tac = 0, nb_clan = 0, nb_total = 0;
    std::cin >> choix_card;
    while (choix_card >= cardsHgetHand.size() || choix_card < 0) {
        std::cout << "��û�����ſ��ƣ���ѡ����ӵ�еĿ��ƣ�" << endl;
        std::cin >> choix_card;
    }
    vector<Card*> cards =  Controller::getController(true).getTable()->getPlayer1()->getHand()->getCards();
     Card*  card = cards[choix_card];
    auto a =Controller::getController(true).getTecRest()->getCards();
     if (CardEliteGroup * CardEliteGroupChoisie = dynamic_cast<CardEliteGroup*>(card)){

         Controller::getController(true).getTecRest()->setM_nb(Controller::getController(true).getTecRest()->getNbCards() + 1);
         std::cout << "�ƶ����� " << Controller::getController(true).getTecRest()->getNbCards() << " ���ơ�" << endl;
         // ���ǽ����Żص��ƶ���
         a[Controller::getController(true).getTecRest()->getNbCards()]= reinterpret_cast<const Card*>(&card);
         Controller::getController(true).getTable()->getPlayer1()->getHand()->remove(choix_card);
     }

    else if (ClanCard* ClanCardChoisie = dynamic_cast<ClanCard*>(card)) {
        Controller::getController(false).getClanRest()->push_back(card);
        Controller::getController(true).getTable()->getPlayer1()->getHand()->remove(choix_card);
}
    else {


        Controller::getController(true).getTecRest()->setM_nb(Controller::getController(true).getTecRest()->getNbCards() + 1);
        std::cout << "�ƶ����� " << Controller::getController(true).getTecRest()->getNbCards() << " ���ơ�" << endl;
        // ���ǽ����Żص��ƶ���
        a[Controller::getController(true).getTecRest()->getNbCards()]= reinterpret_cast<const Card*>(&card);
        Controller::getController(true).getTable()->getPlayer1()->getHand()->remove(choix_card);
    }
}
void Supp_PushClanCardTactique2(){
    vector<Card*> cardsHgetHand = Controller::getController(true).getTable()->getPlayer2()->getHand()->getCards();
    std::cout << "��û�����ſ��ƣ���ѡ����ӵ�еĿ��ƣ�" << endl;
    int choix_card, nb_tac = 0, nb_clan = 0, nb_total = 0;
    std::cin >> choix_card;
    while (choix_card >= cardsHgetHand.size() || choix_card < 0) {
        std::cout << "��û�����ſ��ƣ���ѡ����ӵ�еĿ��ƣ�" << endl;
        std::cin >> choix_card;
    }
    vector<Card*> cards =  Controller::getController(true).getTable()->getPlayer2()->getHand()->getCards();
    Card*  card = cards[choix_card];
    auto a =Controller::getController(true).getTecRest()->getCards();
    if (CardEliteGroup * CardEliteGroupChoisie = dynamic_cast<CardEliteGroup*>(card)){

        Controller::getController(true).getTecRest()->setM_nb(Controller::getController(true).getTecRest()->getNbCards() + 1);
        std::cout << "�ƶ����� " << Controller::getController(true).getTecRest()->getNbCards() << " ���ơ�" << endl;
        // ���ǽ����Żص��ƶ���
        a[Controller::getController(true).getTecRest()->getNbCards()]= reinterpret_cast<const Card*>(&card);
        Controller::getController(true).getTable()->getPlayer2()->getHand()->remove(choix_card);
    }

    else if (ClanCard* ClanCardChoisie = dynamic_cast<ClanCard*>(card)) {
        Controller::getController(false).getClanRest()->push_back(card);
        Controller::getController(true).getTable()->getPlayer2()->getHand()->remove(choix_card);
    }
    else {


        Controller::getController(true).getTecRest()->setM_nb(Controller::getController(true).getTecRest()->getNbCards() + 1);
        std::cout << "�ƶ����� " << Controller::getController(true).getTecRest()->getNbCards() << "  ���ơ�" << endl;
        // ���ǽ����Żص��ƶ���
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
        std::cout << "�ƶ����� " << Controller::getController(true).getTecRest()->getNbCards() << "  ���ơ�" << endl;
        // ���ǽ����Żص��ƶ���
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
        // ���ǽ����Żص��ƶ���
        a[Controller::getController(true).getTecRest()->getNbCards()]= reinterpret_cast<const Card*>(&card);
        Controller::getController(true).getTable()->getPlayer2()->getHand()->remove(choix_card);
    }
}

void CunningCard::Play_ChasseurdeTeteIA(){
    std::cout << "AIͨ���ˡ���ͷ����Ƭ��" << endl;
    int nbClanCard = generateRandomNumber2()%3+1;
    while (nbClanCard>3 || nbClanCard<0){
        nbClanCard = generateRandomNumber2()%3+1;
    }
    int nbTac = 3 - nbClanCard;
    int NagetNamebreTecCard =  Controller::getController(true).getTecRest()->getNbCards();

    while (NagetNamebreTecCard -nbTac <0){
        std::cout << "�㲻�ܳ�ȡ���ƶ���ʣ���������������" << endl;
        std::cout  << "����ѡ������Ҫ��ȡ�Ŀ�����������" << endl;
        nbClanCard = generateRandomNumber2()%3+1;
        nbTac = 3 - nbClanCard;
    }
    switch(nbClanCard){
        case 0 : {
            for (int i = 0 ; i<3;i++){
                switch (Controller::getController(true).getTecRest()->whendrawpayattention()) {
                    case 1: {
                        std::cout << "AI��ȡ��ս���ƣ�" << endl;
                        TecCard * a = new TecCard(Controller::getController(true).getTecRest()->drawTecCard());
                        Controller::getController(true).getTable()->getPlayer2()->getHand()->add(a);
                        std::cout << a->getName() << endl;
                        break;
                    }
                    case 2: {
                        std::cout << "AI��ȡ�˾�Ӣ�����ƣ�" << endl;
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
            std::cout <<"���Ƴ�ȡ�ɹ��� "<< c11->getNumber() <<" "<< c11->getColor() << endl;
            Controller::getController(false).getTable()->getPlayer2()->getHand()->add(c11);

            for (int i = 0 ; i<2;i++){
                switch (Controller::getController(true).getTecRest()->whendrawpayattention()) {
                    case 1: {
                        std::cout << "AI�鵽��ս������ :" << endl;
                        TecCard * a = new TecCard(Controller::getController(true).getTecRest()->drawTecCard());
                        Controller::getController(true).getTable()->getPlayer2()->getHand()->add(a);
                        std::cout << a->getName() << endl;
                        break;
                    }
                    case 2: {
                        std::cout << "AI�鵽�˾�Ӣ���ӿ��� :" << endl;
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
            std::cout << "�鵽�Ŀ��� : " << c21->getNumber() << " " << c21->getColor() << endl;
            ClanCard *c22 = new ClanCard(Controller::getController(false).getClanRest()->drawClanCard());
            Controller::getController(false).getTable()->getPlayer2()->getHand()->add(c22);
            std::cout << "�鵽�Ŀ��� : " << c22->getNumber() << " " << c22->getColor() << endl;
            switch (Controller::getController(true).getTecRest()->whendrawpayattention()) {
                case 1: {
                    std::cout << "AI�鵽��ս���� :" << endl;
                    TecCard * a = new TecCard(Controller::getController(true).getTecRest()->drawTecCard());
                    Controller::getController(true).getTable()->getPlayer2()->getHand()->add(a);
                    std::cout << a->getName() << endl;
                    break;
                }
                case 2: {
                    std::cout << "AI�鵽�˾�Ӣ������ :" << endl;
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
            std::cout <<"�鵽���� : "<< c31->getNumber() <<" "<< c31->getColor() << endl;
            ClanCard* c32 = new ClanCard(Controller::getController(false).getClanRest()->drawClanCard());
            Controller::getController(false).getTable()->getPlayer2()->getHand()->add(c32);
            std::cout <<"�鵽���� : "<< c32->getNumber() <<" "<< c32->getColor() << endl;
            ClanCard* c33 = new ClanCard(Controller::getController(false).getClanRest()->drawClanCard());
            Controller::getController(false).getTable()->getPlayer2()->getHand()->add(c33);
            std::cout <<"�鵽���� : "<< c33->getNumber() <<" "<< c33->getColor() << endl;
        }
    }
    Supp_PushClanCardTactiqueIA();
    Supp_PushClanCardTactiqueIA();
}

void CunningCard::Play_StrategeIA() {
     std::cout << "AI���������ս�Կ�" << endl;

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
    std::cout << "AIѡ�������ſ�Ƭ : " << card_choisie->getColor() << " " << card_choisie->getNumber() << endl;

     Controller::getController(true).getTable()->getStones(choix_stone)->getcardp2()->DeleteCard_Stone(
             choix_card);
     int choix;
     choix =generateRandomNumber2() % 2 + 1;

     //���ǽ���Ƭ������һ���ն���
     if (choix == 2) {

         choix_stone = rand() % 8 + 1;
         while(Controller::getController(true).getTable()->getStones(choix_stone)->getrevendique()!=0 && (choix_stone<0 && choix_stone>8)){
             choix_stone = generateRandomNumber2() % 8 + 1;
         }
         Controller::getController(true).getTable()->getStones(choix_stone)->getcardp2()->addCard(card_choisie);
            std::cout << "AIѡ��ѿ�Ƭ�����ն��� " << choix_stone << endl;
     }
         //��������������
     else{

         delete card_choisie;
            std::cout << "AIѡ���������ſ�Ƭ" << endl;

     }
        std::cout << "���Ƕ��ֵ�����ֵ : " << endl;
        Controller::getController(true).getTable()->showStones(2);
}
void CunningCard::Play_BansheeIA() {
    std::cout << "AI��������鿨" << endl;
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
    std::cout << "AIѡ���Ƴ��ÿ�Ƭ : " << card_choisie->getColor() << " " << card_choisie->getNumber() << " ���ն�/�����豸 "<< choix_stone<< endl;
    Controller::getController(true).getTable()->getStones(choix_stone)->getcardp1()->DeleteCard_Stone(choix_card);
}
 void CunningCard::Play_TraitreIA() {
     std::cout << "�˹����ܳ������Լ�����" << endl;
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
             std::cout << "�������Ŀ������ĸ�δ�������յ��� ? " << endl;
             choix_stone = generateRandomNumber2() % 9;
             while ((Controller::getController(true).getTable()->getStones(choix_stone)->getcardp2()->getCards().size()==3) || (choix_stone > 8 || choix_stone < 0) || Controller::getController(true).getTable()->getStones(choix_stone)->getrevendique() != 0) {
                 std::cout << "�����ܰѿ���������յ��ϣ���ѡ����һ�� : " << endl;
                 choix_stone = generateRandomNumber2() % 9;
             }

             Controller::getController(true).getTable()->getStones(choix_stone)->getcardp2()->addCard(
                     card_choisie);
         } else {
             std::cout << "������ѡ�����ſ�����ѡ����һ�� : " << endl;
             choix_card = generateRandomNumber2() % taille_stone;

         }
     }
}


void CunningCard::Play_ChasseurdeTete() {
    std::cout << "���������ͷ����" << endl;
    std::cout  << "��ѡ������Ҫ��ȡ�����忨������ :" << endl;
    int nbClanCard;
    std::cin >> nbClanCard;
    while (nbClanCard>3 || nbClanCard<0){
        std::cout << "�����ܳ�ȡ����������3�ſ���" << endl;
        std::cout  << "����ѡ������Ҫ��ȡ�����忨������ :" << endl;
        std::cin >> nbClanCard;}

    int nbTac = 3 - nbClanCard;
    int NagetNamebreTecCard =  Controller::getController(true).getTecRest()->getNbCards();
    std::cout << "ʣ�� " << NagetNamebreTecCard << " ��ս���� " << endl;
    while (NagetNamebreTecCard -nbTac <0){
            std::cout << "�����ܳ�ȡ�����ƶ������е�����" << endl;
            std::cout  << "����ѡ������Ҫ��ȡ�����忨������ :" << endl;
            std::cin >> nbClanCard;
            nbTac = 3 - nbClanCard;
        }

    switch(nbClanCard){
        case 0 : {
            for (int i = 0 ; i<3;i++){
            switch (Controller::getController(true).getTecRest()->whendrawpayattention()) {
                case 1: {
                    std::cout << "���Ѿ���ȡ��ս���� :" << endl;
                    TecCard * a = new TecCard(Controller::getController(true).getTecRest()->drawTecCard());
                    Controller::getController(true).getTable()->getPlayer1()->getHand()->add(a);
                    std::cout << a->getName() << endl;
                    break;
                }
                case 2: {
                    std::cout << "���Ѿ���ȡ�˾�Ӣ���ӿ� :" << endl;
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
            std::cout <<"��ȡ�Ŀ��� : "<< c11->getNumber() <<" "<< c11->getColor() << endl;
            Controller::getController(false).getTable()->getPlayer1()->getHand()->add(c11);
            for (int i = 0 ; i<2;i++){
                switch (Controller::getController(true).getTecRest()->whendrawpayattention()) {
                    case 1: {
                        std::cout << "���鵽��ս���� :" << endl;
                        TecCard * a = new TecCard(Controller::getController(true).getTecRest()->drawTecCard());
                        Controller::getController(true).getTable()->getPlayer1()->getHand()->add(a);
                        std::cout << a->getName() << endl;
                        break;
                    }
                    case 2: {
                        std::cout << "���鵽�˾�Ӣ���ӿ� :" << endl;
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
            std::cout << "�鵽�Ŀ��� : " << c21->getNumber() << " " << c21->getColor() << endl;
            ClanCard *c22 = new ClanCard(Controller::getController(false).getClanRest()->drawClanCard());
            Controller::getController(false).getTable()->getPlayer1()->getHand()->add(c22);
            std::cout << "�鵽�Ŀ��� : " << c22->getNumber() << " " << c22->getColor() << endl;
            switch (Controller::getController(true).getTecRest()->whendrawpayattention()) {
                case 1: {
                    std::cout << "��鵽��ս���� :" << endl;
                    TecCard * a = new TecCard(Controller::getController(true).getTecRest()->drawTecCard());
                    Controller::getController(true).getTable()->getPlayer1()->getHand()->add(a);
                    std::cout << a->getName() << endl;
                    break;
                }
                case 2: {
                    std::cout << "��鵽�˾�Ӣ������ :" << endl;
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
            std::cout <<"�鵽�Ŀ��� : "<< c31->getNumber() <<" "<< c31->getColor() << endl;
            ClanCard* c32 = new ClanCard(Controller::getController(false).getClanRest()->drawClanCard());
            Controller::getController(false).getTable()->getPlayer1()->getHand()->add(c32);
            std::cout <<"�鵽�Ŀ��� : "<< c32->getNumber() <<" "<< c32->getColor() << endl;
            ClanCard* c33 = new ClanCard(Controller::getController(false).getClanRest()->drawClanCard());
            Controller::getController(false).getTable()->getPlayer1()->getHand()->add(c33);
            std::cout <<"�鵽�Ŀ��� : "<< c33->getNumber() <<" "<< c33->getColor() << endl;

        }

    }
    std::cout << "��������Ҫѡ������Ҫ��������ɾ���Ŀ���" << endl;
    std::cout << "�����㵱ǰ���ϵ��� :" << endl;
    Controller::getController(true).getTable()->showPlayerHand(1);
    Supp_PushClanCardTactique();
    std::cout << "�����㵱ǰ���ϵ��� :" << endl;
    Controller::getController(true).getTable()->showPlayerHand(1);
    Supp_PushClanCardTactique();
}

void CunningCard::Play_ChasseurdeTete2() {
    std::cout << "���Ѿ�ʹ������ͷ��Ƭ" << endl;
    std::cout  << "��ѡ�������ȡ������������ :" << endl;
    int nbClanCard;
    std::cin >> nbClanCard;
    while (nbClanCard>3 || nbClanCard<0){
        std::cout << "�����ܳ�ȡ���������� 3 ����" << endl;
        std::cout  << "����ѡ�������ȡ������������ :" << endl;
        std::cin >> nbClanCard;}

    int nbTac = 3 - nbClanCard;
    int NagetNamebreTecCard =  Controller::getController(true).getTecRest()->getNbCards();
    std::cout << "��ʣ�� " << NagetNamebreTecCard << " ��ս���� " << endl;
    while (NagetNamebreTecCard -nbTac <0){
        std::cout << "�����ܳ�ȡ�����ƶ���ʣ����������" << endl;
        std::cout  << "����ѡ�������ȡ������������ :" << endl;
        std::cin >> nbClanCard;
        nbTac = 3 - nbClanCard;
    }

    switch(nbClanCard){
        case 0 : {
            for (int i = 0 ; i<3;i++){
                switch (Controller::getController(true).getTecRest()->whendrawpayattention()) {
                    case 1: {
                        std::cout << "����ȡ��ս���� :" << endl;
                        TecCard * a = new TecCard(Controller::getController(true).getTecRest()->drawTecCard());
                        Controller::getController(true).getTable()->getPlayer2()->getHand()->add(a);
                        std::cout << a->getName() << endl;
                        break;
                    }
                    case 2: {
                        std::cout << "����ȡ�˾�Ӣ���ӿ� :" << endl;
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
            std::cout <<"�鵽�Ŀ��� : "<< c11->getNumber() <<" "<< c11->getColor() << endl;
            Controller::getController(false).getTable()->getPlayer2()->getHand()->add(c11);
            for (int i = 0 ; i<2;i++){
                switch (Controller::getController(true).getTecRest()->whendrawpayattention()) {
                    case 1: {
                        std::cout << "��鵽��ս���� :" << endl;
                        TecCard * a = new TecCard(Controller::getController(true).getTecRest()->drawTecCard());
                        Controller::getController(true).getTable()->getPlayer2()->getHand()->add(a);
                        std::cout << a->getName() << endl;
                        break;
                    }
                    case 2: {
                        std::cout << "��鵽�˾�Ӣ������ :" << endl;
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
            std::cout << "�鵽�Ŀ��� : " << c21->getNumber() << " " << c21->getColor() << endl;
            ClanCard *c22 = new ClanCard(Controller::getController(false).getClanRest()->drawClanCard());
            Controller::getController(false).getTable()->getPlayer2()->getHand()->add(c22);
            std::cout << "�鵽�Ŀ��� : " << c22->getNumber() << " " << c22->getColor() << endl;
            switch (Controller::getController(true).getTecRest()->whendrawpayattention()) {
                case 1: {
                    std::cout << "��鵽��ս���� :" << endl;
                    TecCard * a = new TecCard(Controller::getController(true).getTecRest()->drawTecCard());
                    Controller::getController(true).getTable()->getPlayer2()->getHand()->add(a);
                    std::cout << a->getName() << endl;
                    break;
                }
                case 2: {
                    std::cout << "��鵽�˾�Ӣ������ :" << endl;
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
            std::cout <<"�鵽�Ŀ��� : "<< c31->getNumber() <<" "<< c31->getColor() << endl;
            ClanCard* c32 = new ClanCard(Controller::getController(false).getClanRest()->drawClanCard());
            Controller::getController(false).getTable()->getPlayer2()->getHand()->add(c32);
            std::cout <<"�鵽�Ŀ��� : "<< c32->getNumber() <<" "<< c32->getColor() << endl;
            ClanCard* c33 = new ClanCard(Controller::getController(false).getClanRest()->drawClanCard());
            Controller::getController(false).getTable()->getPlayer2()->getHand()->add(c33);
            std::cout <<"�鵽�Ŀ��� : "<< c33->getNumber() <<" "<< c33->getColor() << endl;

        }

    }
    std::cout << "��������Ҫѡ���������Ʋ����䶪��" << endl;
    std::cout << "��������ǰ������ :" << endl;
    Controller::getController(true).getTable()->showPlayerHand(2);
    Supp_PushClanCardTactique2();
    std::cout << "��������ǰ������ :" << endl;
    Controller::getController(true).getTable()->showPlayerHand(2);
    Supp_PushClanCardTactique2();
}
void CunningCard::Play_Stratege() {
    std::cout << "������ս�Լҿ�Ƭ" << endl;
    std::cout << "�������������յ� : " << endl;
    Controller::getController(true).getTable()->showStones(1);
    std::cout << "��ѡ��һ��δ����������������յ� " << endl;
    int choix_stone, choix_card;
    std::cin >> choix_stone;
    while ((choix_stone>8 || choix_stone<0) ||Controller::getController(true).getTable()->getStones(
            choix_stone)->getcardp1()->getCards().empty()) {
        std::cout << "��������յ���û�е�ͼ����ѡ����һ���յ� : " << endl;
        std::cin >> choix_stone;
    }

    auto cardsgetStones = Controller::getController(true).getTable()->getStones(
            choix_stone)->getcardp1()->getCards();
    for (int i = 0; i < cardsgetStones.size(); i++) {
        std::cout << "id :" << i << " " << cardsgetStones[i]->getColor() << " " << cardsgetStones[i]->getNumber()
             << endl;
    }
    std::cout << "������յ������ȡ�����ŵ�ͼ "<< choix_stone << "?" << endl;
    std::cin >> choix_card;
    while (choix_card > cardsgetStones.size() - 1 || choix_card < 0) {
        std::cout << "���ն���û�е�ͼ�ɹ�ѡ����ѡ����һ���ն� : " << endl;
        std::cin >> choix_card;
    }
    auto card_choisie = Controller::getController(true).getTable()->getStones(
            choix_stone)->getcardp1()->getCards()[choix_card];
    std::cout << "����ѡ���ͼ : " << card_choisie->getColor() << " " << card_choisie->getNumber()
         << endl;
    Controller::getController(true).getTable()->getStones(choix_stone)->getcardp1()->DeleteCard_Stone(
            choix_card);
    std::cout << "�����������ſ�Ƭ���Ƿŵ���һ��λ�ã� " << endl;
    std::cout << "1 : ������Ƭ" << endl;
    std::cout << "2 : ����Ƭ�ŵ���һ��λ����" << endl;
    int choix;
    std::cin >> choix;
    if (choix == 2) {
            std::cout << "����ѿ�Ƭ�����ĸ�δ������������ϣ� " << endl;
            std::cin >> choix_stone;
            while(Controller::getController(true).getTable()->getStones(choix_stone)->getrevendique()!=0 && choix_stone<0 && choix_stone>8){
                std::cout << "�����ܽ���Ƭ������������ϣ���ѡ����һ�� : " << endl;
                std::cin >> choix_stone;
        }
            Controller::getController(true).getTable()->getStones(choix_stone)->getcardp1()->addCard(card_choisie);
    }
    else{
        std::cout << "�������� "<< card_choisie->getColor() << " " << card_choisie->getNumber()<< endl;
        delete card_choisie;
    }
}


void CunningCard::Play_Stratege2() {
    std::cout << "������˲��Կ���" << endl;
    std::cout << "�����������б߽� : " << endl;
    Controller::getController(true).getTable()->showStones(2);
    std::cout << "��ѡ��һ��δ������ı߽磬�������Լ��� " << endl;
    int choix_stone, choix_card;
    std::cin >> choix_stone;
    while ((choix_stone>8 || choix_stone<0) ||Controller::getController(true).getTable()->getStones(
            choix_stone)->getcardp2()->getCards().empty()) {
        std::cout << "���ڸñ߽�û�п��ƣ���ѡ����һ�� : " << endl;
        std::cin >> choix_stone;
    }

    auto cardsgetStones = Controller::getController(true).getTable()->getStones(
            choix_stone)->getcardp2()->getCards();
    for (int i = 0; i < cardsgetStones.size(); i++) {
        std::cout << "id :" << i << " " << cardsgetStones[i]->getColor() << " " << cardsgetStones[i]->getNumber()
             << endl;
    }
    std::cout << "����ӱ߽����Ƴ����ſ��� "<< choix_stone << "?" << endl;
    std::cin >> choix_card;
    while (choix_card > cardsgetStones.size() - 1 || choix_card < 0) {
        std::cout << "���ڸñ߽�û�п��ƣ���ѡ����һ�� : " << endl;
        std::cin >> choix_card;
    }
    auto card_choisie = Controller::getController(true).getTable()->getStones(
            choix_stone)->getcardp2()->getCards()[choix_card];
    std::cout << "��ѡ���˿��� : " << card_choisie->getColor() << " " << card_choisie->getNumber()
         << endl;
    Controller::getController(true).getTable()->getStones(choix_stone)->getcardp2()->DeleteCard_Stone(
            choix_card);
    std::cout << "����Ҫ���ÿ����������Ƿ��������߽��ϣ� " << endl;
    std::cout << "1 : �����ÿ���" << endl;
    std::cout << "2 : ���������߽���" << endl;
    int choix;
    std::cin >> choix;
    if (choix == 2) {
        std::cout << "����Ҫ�����Ʒ����ĸ�δ������ı߽��ϣ� " << endl;
        std::cin >> choix_stone;
        while(Controller::getController(true).getTable()->getStones(choix_stone)->getrevendique()!=0 && choix_stone<0 && choix_stone>8){
            std::cout << "�����ܽ����Ʒ��ڸñ߽��ϣ���ѡ����һ���� " << endl;
            std::cin >> choix_stone;
        }
        Controller::getController(true).getTable()->getStones(choix_stone)->getcardp2()->addCard(card_choisie);
    }
    else{
        std::cout << "���Ѿ������˿��� "<< card_choisie->getColor() << " " << card_choisie->getNumber()<< endl;
        delete card_choisie;
    }
}
void CunningCard::Play_Traitre() {
    std::cout << "��ʹ���˿�����ͽ" << endl;
    std::cout << "���ֵı߽����� : " << endl;
    Controller::getController(true).getTable()->showStones(1);
    std::cout << "��ѡ��һ������δ������ı߽� " << endl;
    int choix_stone, choix_card;
    std::cin >> choix_stone;

    while ((choix_stone > 8 || choix_stone < 0) || Controller::getController(true).getTable()->getStones(
            choix_stone)->getcardp2()->getCards().empty() || Controller::getController(true).getTable()->getStones(choix_stone)->getrevendique()!=0 ) {
        std::cout << "�����ڸñ߽�û�п��ƣ���ѡ�������߽� : " << endl;
        std::cin >> choix_stone;
    }
    auto cardsgetStones = Controller::getController(true).getTable()->getStones(
            choix_stone)->getcardp2()->getCards();
    for (int i = 0; i < cardsgetStones.size(); i++) {
        std::cout << "id :" << i << " " << cardsgetStones[i]->getColor() << " " << cardsgetStones[i]->getNumber()
             << endl;
    }
    std::cout << "��ѡ��Ҫ�ӱ߽����Ƴ��Ŀ��ƣ� "<< choix_stone << "?" << endl;
    std::cin >> choix_card;

    while (choix_card > cardsgetStones.size() - 1 || choix_card < 0 ) {
        std::cout << "������ѡ��ÿ��ƣ���ѡ���������ƣ� " << endl;
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
            std::cout << "��ѡ���˿���: " << card_choisie->getColor() << " "
                 << card_choisie->getNumber()
                 << endl;
            Controller::getController(true).getTable()->getStones(choix_stone)->getcardp2()->DeleteCard_Stone(
                    choix_card);
            std::cout << "����ѿ��Ʒ����ĸ�δ������Ŧ���ϣ�" << endl;
            std::cin >> choix_stone;
            while ((Controller::getController(true).getTable()->getStones(choix_stone)->getcardp1()->getCards().size()==3) || (choix_stone > 8 || choix_stone < 0) || Controller::getController(true).getTable()->getStones(choix_stone)->getrevendique() != 0) {
                std::cout << "���޷��ڴ�Ŧ���Ϸ��ÿ�Ƭ����ѡ������Ŧ�ۣ�" << endl;
                std::cin >> choix_stone;
            }

            Controller::getController(true).getTable()->getStones(choix_stone)->getcardp1()->addCard(
                    card_choisie);
        } else {
            std::cout << "������ѡ��˿��ƣ���ѡ���������ƣ�" << endl;
            std::cin >> choix_card;

        }
    }



}
void CunningCard::Play_Traitre2() {
    std::cout << "���Ѿ�ʹ���˹�ƿ�Ƭ" << endl;
    std::cout << "���ֵĳ�������ָ���ֵĿɽ��ܷ�Χ���� : " << endl;
    Controller::getController(true).getTable()->showStones(2);
    std::cout << "��Ϊ����ѡ��һ��δ����Ҫ�ı߽�� " << endl;
    int choix_stone, choix_card;
    std::cin >> choix_stone;

    while ((choix_stone > 8 || choix_stone < 0) || Controller::getController(true).getTable()->getStones(
            choix_stone)->getcardp1()->getCards().empty() || Controller::getController(true).getTable()->getStones(choix_stone)->getrevendique()!=0 ) {
        std::cout << "����������߽����û�п�Ƭ����ѡ����һ�� : " << endl;
        std::cin >> choix_stone;
    }
    auto cardsgetStones = Controller::getController(true).getTable()->getStones(
            choix_stone)->getcardp1()->getCards();
    for (int i = 0; i < cardsgetStones.size(); i++) {
        std::cout << "id :" << i << " " << cardsgetStones[i]->getColor() << " " << cardsgetStones[i]->getNumber()
             << endl;
    }
    std::cout << "��ϣ���ӱ߽�����Ƴ����ſ�Ƭ "<< choix_stone << "?" << endl;
    std::cin >> choix_card;

    while (choix_card > cardsgetStones.size() - 1 || choix_card < 0 ) {
        std::cout << "�ܱ�Ǹ�����޷�ѡ��ÿ�Ƭ����ѡ����һ�� : " << endl;
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
            std::cout << "��ѡ���˸ÿ�Ƭ : " << card_choisie->getColor() << " "
                 << card_choisie->getNumber()
                 << endl;
            Controller::getController(true).getTable()->getStones(choix_stone)->getcardp1()->DeleteCard_Stone(
                    choix_card);
            std::cout << "�������Ŀ�Ƭ�����ĸ�δռ�еĲ���� ? " << endl;
            std::cin >> choix_stone;
            while ((Controller::getController(true).getTable()->getStones(choix_stone)->getcardp2()->getCards().size()==3) || (choix_stone > 8 || choix_stone < 0) || Controller::getController(true).getTable()->getStones(choix_stone)->getrevendique() != 0) {
                std::cout << "�㲻�����������Ϸ��ÿ�Ƭ����ѡ����һ����� : " << endl;
                std::cin >> choix_stone;
            }

            Controller::getController(true).getTable()->getStones(choix_stone)->getcardp2()->addCard(
                    card_choisie);
        } else {
            std::cout << "�㲻��ѡ�����ſ�Ƭ����ѡ����һ�� : " << endl;
            std::cin >> choix_card;

        }
    }



}
void CunningCard::Play_Banshee() {
    std::cout << "������Ů����" << endl;
    std::cout << "���Ƕ��ֵı߽� : " << endl;
    Controller::getController(true).getTable()->showStones(1);
    std::cout << "��ѡ�����ӵ�е�δ��Ҫ��ı߽� " << endl;
    int choix_stone, choix_card;
    std::cin >> choix_stone;

    while (Controller::getController(true).getTable()->getStones(
            choix_stone)->getcardp2()->getCards().empty() || Controller::getController(true).getTable()->getStones(choix_stone)->getrevendique()!=0) {
        std::cout << "����������߽���û�п�Ƭ����ѡ����һ���߽� : " << endl;
        std::cin >> choix_stone;
    }
    while (choix_stone > 8 || choix_stone < 0) {
        std::cout << "��û������߽磬��ѡ��һ���߽� :" << endl;
        std::cin >> choix_stone;
    }

    auto cardsgetStones = Controller::getController(true).getTable()->getStones(
            choix_stone)->getcardp2()->getCards();
    for (int i = 0; i < cardsgetStones.size(); i++) {
        std::cout << "id :" << i << " " << cardsgetStones[i]->getColor() << " " << cardsgetStones[i]->getNumber()
             << endl;
    }
    std::cout << "����ӱ߽����ȡ�����ſ�Ƭ "<< choix_stone << "?" << endl;
    std::cin >> choix_card;
    while (choix_card > cardsgetStones.size() - 1 || choix_card < 0) {
        std::cout << "������ѡ��ÿ�Ƭ����ѡ����һ�ſ�Ƭ : " << endl;
        std::cin >> choix_card;
    }
    auto card_choisie = Controller::getController(true).getTable()->getStones(
            choix_stone)->getcardp2()->getCards()[choix_card];
    std::cout << "����ѡ��ÿ�Ƭ : " << card_choisie->getColor() << " " << card_choisie->getNumber()
         << endl;
    Controller::getController(true).getTable()->getStones(choix_stone)->getcardp2()->DeleteCard_Stone(
            choix_card);

}
void CunningCard::Play_Banshee2() {
    std::cout << "��ʹ����Ů����Ƭ" << endl;
    std::cout << "���Ƕ��ֵĿ��Ƶ� : " << endl;
    Controller::getController(true).getTable()->showStones(2);
    std::cout << "��Ӷ��ֵ�δ������Ŀ��Ƶ���ѡ��һ�� " << endl;
    int choix_stone, choix_card;
    std::cin >> choix_stone;

    while (Controller::getController(true).getTable()->getStones(
            choix_stone)->getcardp1()->getCards().empty() || Controller::getController(true).getTable()->getStones(choix_stone)->getrevendique()!=0) {
        std::cout << "������������Ƶ���û�п��ƣ���ѡ����һ�����Ƶ� : " << endl;
        std::cin >> choix_stone;
    }
    while (choix_stone > 8 || choix_stone < 0) {
        std::cout << "��û�иÿ��Ƶ㣬��������һ�����Ƶ� :" << endl;
        std::cin >> choix_stone;
    }

    auto cardsgetStones = Controller::getController(true).getTable()->getStones(
            choix_stone)->getcardp1()->getCards();
    for (int i = 0; i < cardsgetStones.size(); i++) {
        std::cout << "id :" << i << " " << cardsgetStones[i]->getColor() << " " << cardsgetStones[i]->getNumber()
             << endl;
    }
    std::cout << "����ӿ��Ƶ�ȡ�����ſ�Ƭ "<< choix_stone << "?" << endl;
    std::cin >> choix_card;
    while (choix_card > cardsgetStones.size() - 1 || choix_card < 0) {
        std::cout << "���޷�ѡ��ÿ�Ƭ����ѡ����һ�� : " << endl;
        std::cin >> choix_card;
    }
    auto card_choisie = Controller::getController(true).getTable()->getStones(
            choix_stone)->getcardp1()->getCards()[choix_card];
    std::cout << "��ѡ�������ſ�Ƭ : " << card_choisie->getColor() << " " << card_choisie->getNumber()
         << endl;
    Controller::getController(true).getTable()->getStones(choix_stone)->getcardp1()->DeleteCard_Stone(
            choix_card);

}