#include "Controller.h"
#include "CardEliteGroup.h"
#include "CunningCard.h"
#include "BattleCard.h"
#include <ctime>
#include <random>
#ifdef __unix__
# include <unistd.h>
#elif defined _WIN32
# include <windows.h>
#define sleep(x) Sleep(1000 * (x))
#endif
#include <sstream>


int generateRandomNumber() {
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> distribution(1, 100);
    return distribution(rng);
}


Controller::Controller(bool tactique): m_tec(tactique), m_winner(0), m_clan_game(ClanGame::getClanGame()), m_tec_game(TecGame::getTecGame()), m_unplayed_cards(m_clan_game.getNbCards())
{
    m_clan_deck = new Rest(m_clan_game);
    if(tactique){
        m_tec_deck = new Rest(m_tec_game);
        printf("战术\n");
        m_table = new Table(7, false, false);
    }
    else{
        m_table = new Table(6, false, false);
        printf("经典\n");
    }

    size_t i=0;
    ClanGame::Iterator it=m_clan_game.getIterator();
    while (!it.isDone()){
        m_unplayed_cards[i]= new ClanCard(static_cast<const ClanCard&>(it.currentItem()));
        it.next();
        i++;
    }
}

Controller::~Controller()
{
    delete m_clan_deck;
    delete m_tec_deck;
    delete m_table;
    for(int i=0; i<m_unplayed_cards.size(); i++){
        delete m_unplayed_cards[i];
    }
}

Controller& Controller::getController(bool tactique)
{
    if (processor.controller == nullptr)
        processor.controller = new Controller(tactique);
    return *processor.controller;
}

void Controller::releaseController()
{
    delete processor.controller;
    processor.controller =nullptr;
}

Controller::Processor Controller::processor = Processor();


void clean(void)
{
    int c= 0;
    while ( (getchar()) != '\n' && c != EOF);
}

void Controller::Display_Gate1(){
    for(auto i =0; i<9;i++){
        cout << "|B" << i<<":";
        Show_Vector_ClanCard(m_table->getStones(i)->getcardp1()->getCards());
        cout <<"|"<< endl;
    }
    cout << endl;

}
void Controller::Display_Gate2(){
    for(auto i =0; i<9;i++){
        cout << "|B" << i <<":";
        Show_Vector_ClanCard(m_table->getStones(i)->getcardp2()->getCards());
        cout <<"|"<< endl;
    }
    cout << endl;
}

void Controller::displayUnplayedCards() const
{
    std::cout << "未发出的卡牌 : " << std::endl;
    for (int i = 0; i < m_unplayed_cards.size(); ++i)
    {
        std::cout << "卡片 " << i + 1 << ": ";
        if (m_unplayed_cards[i] != nullptr)
            std::cout << m_unplayed_cards[i]->getColor() << " "<< m_unplayed_cards[i]->getNumber()<< std::endl;
        else
            std::cout << "没有卡片" << std::endl;
    }
}
int Joker1 = 0;
int Joker2=0;
int cardtacJoue1 =0;
int cardtacJoue2 =0;
int testclan = 1;
int testclan2 = 1;
void Controller::PlayTurn1(){
    int attente_valide = 0;
    int print = 0;
    int cartClan = 0;
   // cout <<"taille Rest clan : "<<getClanRest()->getNbCards()<<"\n";
    //cout <<"taille Rest tactique : "<<getTecRest()->getNbCards()<<"\n";
    //CunningCard::Play_Recruiter();
    //cout <<"taille Rest clan : "<<getClanRest()->getNbCards()<<"\n";
    //cout <<"taille Rest tactique : "<<getTecRest()->getNbCards()<<"\n";
    //cout << "Voici votre Hand :" << endl;
    //m_table->showPlayerHand(1);

    system ("CLS");
    m_table->showTable(1);
    vector<Card*> cardsHand = m_table->player1->getHand()->getCards();

    testclan = 0;
    if (cardsHand.size()!=0) {


        while (attente_valide != 1) {
            cout << "请您选择您想要打出的卡片（其ID） :" << endl;
            int choix_card, nb_tac = 0, nb_clan = 0, nb_total = 0;
            cin >> choix_card;
            clean();
            while (choix_card >= cardsHand.size() || choix_card < 0) {
                cout << "您没有这张卡，请输入您拥有的一张卡 :" << endl;
                cin >> choix_card;
            }
            vector<Card *> cards = m_table->player1->getHand()->getCards();
            Card *card = cards[choix_card];

            if (CardEliteGroup *cardEliteGroupChoisie = dynamic_cast<CardEliteGroup *>(card)) {
                if (cardtacJoue1 < cardtacJoue2 + 1) {
                    if (cardEliteGroupChoisie->getName() == "Joker") {
                        Joker1++;
                    }
                    if (Joker1 > 1 && cardEliteGroupChoisie->getName() == "Joker") {
                        cout << "您不能在同一局游戏中使用两张小丑牌，请选择另一张牌"
                             << endl;
                    } else {
                        cout << "你选择了卡片：名字:" << cardEliteGroupChoisie->getName() << endl;
                        cout << "您想在哪个终端使用这张卡片 ? :" << endl;
                        int choix_stone;
                        cin >> choix_stone;
                        m_table->getStones(choix_stone)->getcardp1()->getMudFight() == 0;
                        while ((choix_stone > 8 || choix_stone < 0) ||
                               (m_table->getStones(choix_stone)->getcardp1()->getMudFight() == 0 &&
                                m_table->getStones(choix_stone)->getcardp1()->getCards().size() == 3) ||
                               (m_table->getStones(choix_stone)->getcardp1()->getMudFight() == 1 &&
                                m_table->getStones(choix_stone)->getcardp1()->getCards().size() == 4)) {
                            cout << "您不能将您的卡片放在这个终端上:" << endl;
                            cin >> choix_stone;
                        }
                        testclan++;
                        cout << "将选择的卡片放在终端上 " << choix_stone << " :" << endl;
                        m_table->put(*m_table->getStones(choix_stone), cardEliteGroupChoisie);
                        cout << "终端 " << choix_stone << " :" << endl;
                        Show_Vector_ClanCard(m_table->getStones(choix_stone)->getcardp1()->getCards());
                        cout << endl;
                        cardtacJoue1++;
                        attente_valide = 1;
                        cartClan = 1;
                        m_table->getPlayer1()->getHand()->remove(choix_card);
                    }

                } else if (testclan == 0) {
                    cout
                            << "您不能使用这张牌，您比对手多出一张战术卡"
                            << endl;
                    print++;

                }
            } else if (ClanCard *ClanCardChoisie = dynamic_cast<ClanCard *>(card)) {
                cout << "您选择了卡片：力量 :" << ClanCardChoisie->getNumber() << " 颜色 : "
                     << ClanCardChoisie->getColor() << endl;
                system("CLS");
                m_table->showTable(1);
                cout << "请选择一个终点 :" << endl;
                int choix_stone;
                cin >> choix_stone;
                while ((choix_stone > 8 || choix_stone < 0) ||
                       (m_table->getStones(choix_stone)->getcardp1()->getMudFight() == 0 &&
                        m_table->getStones(choix_stone)->getcardp1()->getCards().size() == 3) ||
                       (m_table->getStones(choix_stone)->getcardp1()->getMudFight() == 1 &&
                        m_table->getStones(choix_stone)->getcardp1()->getCards().size() == 4)) {
                    cout << "您不能在此终点上放置卡片 :" << endl;
                    cin >> choix_stone;
                }
                system("CLS");
                cout << "我们将选择的地图放在这个终点上 " << choix_stone << " :" << endl;
                m_table->put(*m_table->getStones(choix_stone), ClanCardChoisie);
                m_table->showTable(1);
                m_table->getPlayer1()->getHand()->remove(choix_card);
                attente_valide = 1;
                cartClan = 1;
            }
            if (cartClan == 0) {
                if (cardtacJoue1 < cardtacJoue2 + 1) {

                    if (TecCard *TecCardChoisie = dynamic_cast<TecCard *>(card)) {

                        cout << "您选择的地图是：名称 :" << TecCardChoisie->getName() << endl;

                        if (TecCardChoisie->getName() == "Colin Maillard") {
                            cout << "您想在哪个终端使用这张地图 ? :" << endl;
                            int choix_stone;
                            cin >> choix_stone;
                            while (choix_stone > 8 || choix_stone < 0) {
                                cout << "您没有该终端，请输入正确的终端 :" << endl;
                                cin >> choix_stone;
                            }
                            cout << "将选择的卡放在终端上 " << choix_stone << " :" << endl;
                            BattleCard::play_BlindBluff(m_table->getStones(choix_stone));
                            m_table->getPlayer1()->getHand()->remove(choix_card);
                            attente_valide = 1;
                            cardtacJoue1++;
                        } else if (TecCardChoisie->getName() == "Combat de Boue") {
                            int choix_stone;
                            cin >> choix_stone;
                            while (choix_stone > 8 || choix_stone < 0) {
                                cout << "您没有这个终端，请输入一个终端 :" << endl;
                                cin >> choix_stone;
                            }
                            cout << "我们把选定的卡片放在终端上 " << choix_stone << " :" << endl;
                            BattleCard::play_MudFight(m_table->getStones(choix_stone));
                            m_table->getPlayer1()->getHand()->remove(choix_card);
                            attente_valide = 1;
                        } else if (TecCardChoisie->getName() == "Chasseur de Tete") {
                            CunningCard::Play_Recruiter();
                            attente_valide = 1;
                            m_table->getPlayer1()->getHand()->remove(choix_card);
                        } else if (TecCardChoisie->getName() == "Stratege") {
                            for (int i = 0; i < 9; i++) {
                                if (m_table->getStones(i)->getcardp1()->getCards().size() != 0) {
                                    nb_clan++;
                                }

                            }
                            if (nb_clan != 0) {
                                CunningCard::Play_Strategis();
                                attente_valide = 1;
                                m_table->getPlayer1()->getHand()->remove(choix_card);
                            } else {
                                cout << "您在桌子上没有卡片." << endl;
                                attente_valide = 0;
                            }
                            attente_valide = 0;

                        } else if (TecCardChoisie->getName() == "Banshee") {
                            for (int i = 0; i < 9; i++) {
                                if (m_table->getStones(i)->getcardp2()->getCards().size() != 0) {
                                    nb_clan++;
                                }

                            }
                            if (nb_clan != 0) {
                                CunningCard::Play_Banshee();
                                attente_valide = 1;
                                m_table->getPlayer1()->getHand()->remove(choix_card);
                            } else {
                                cout << "您在桌子上没有卡片." << endl;
                                attente_valide = 0;

                            }

                        } else if (TecCardChoisie->getName() == "Traitre") {
                            for (int i = 0; i < 9; i++) {
                                if (m_table->getStones(i)->getcardp2()->getCards().size() != 0) {
                                    nb_clan++;
                                }

                            }
                            if (nb_clan != 0) {
                                CunningCard::Play_Traiter();
                                attente_valide = 1;
                                m_table->getPlayer1()->getHand()->remove(choix_card);
                            } else {
                                cout << "对手在桌子上没有纸牌." << endl;
                                attente_valide = 0;
                            }


                        }
                        //TODO ne sert a rien car une card EliteGroup est une ClanCard
                        cardtacJoue1++;
                    }
                } else if (testclan == 0 && print == 0) {
                    cout
                            << " 你已经打出比对手多一张战术牌，所以你不能打出战术牌."
                            << endl;
                }
            }
        }
    }
    else {
        cout << "你跳过了回合，因为你没有手牌了" << endl;
    }
    cout << "您想要领取一个设施吗？1代表是，0代表否:" << endl;
    int choix_revendication;
    cin >> choix_revendication;

    if(choix_revendication==1){
        cout << "请您选择您想要领取的设施 :" << endl;
        int choix_stone;
        cin >> choix_stone;
        while (m_table->m_stones[choix_stone]->getrevendique()==2 || m_table->m_stones[choix_stone]->getrevendique()==1 && (choix_stone > 8 || choix_stone < 0)) {
            cout << "该设施已经被认领，请选择其他设施 :" << endl;
            cin>> choix_stone;
            return;
        }
        auto msg =claim_gate(choix_stone,true);
        cout << msg << endl;
        sleep(3);
        auto cardsstones = m_table->getStones(choix_stone)->getcardp1()->getCards();
        int i =0;

    }
    system ("CLS");
    m_table->showTable(1);
    cout << "请选择您要选择的战术地图或普通地图：0代表普通，1代表战术" << endl;
    int choix_style;
    cin >> choix_style;
    while(choix_style!=0 && choix_style!=1){
        cout << "请选择您要选择的战术地图或普通地图：0代表普通，1代表战术" << endl;
        cin >> choix_style;
    }
    if (choix_style == 0) {
        if( !getClanRest()->isEmpty()) {

            ClanCard *ci = new ClanCard(getClanRest()->drawClanCard());
            m_table->getPlayer1()->getHand()->add(ci);
            cout << "抽取的卡片 : " << ci->getNumber() << " " << ci->getColor() << endl;

        }
    }
    else if ( !getTecRest()->isEmpty() && choix_style==1){
        switch (getTecRest()->whendrawpayattention() ) {
            case 1: {
                cout << "你抽到了战术卡 :" << endl;
                TecCard * a = new TecCard(getTecRest()->drawTecCard());
                m_table->getPlayer1()->getHand()->add(a);
                cout << a->getName() << endl;
                break;
            }
            case 2: {
                cout << "你抽到了精英部队卡 :" << endl;
                CardEliteGroup * b = new CardEliteGroup( getTecRest()->drawCardEliteGroup());
                m_table->getPlayer1()->getHand()->add(b);
                cout << b->getName() << endl;
                break;
            }
        }

    }
    else {
        cout << "你的牌堆里没有剩余的牌了" << endl;
    }
    //Affichage de la Hand du joueur 1
    system ("CLS");
    cout << "你现在的手牌由以下卡牌组成 : " << endl;
    m_table->showTable(1);

    //cout <<"taille Rest tactique : "<<getTecRest()->getNbCards()<<"\n";
    //Display_Gate1();
    cout << "\n回合结束" << endl;
}


void Controller::PlayAI(){
    int print = 0;
    int cartClan = 0;
    m_table->showStones(2);
    m_table->showPlayerHand(2);
    vector<Card*> cardsHand = m_table->player2->getHand()->getCards();
    int attente_valide=0;
    if (cardsHand.size()!=0) {
        while (attente_valide != 1) {

            int choix_card, nb_tac = 0, nb_clan = 0, nb_total = 0;
            choix_card = generateRandomNumber() % cardsHand.size();
            clean();
            while (choix_card >= cardsHand.size() || choix_card < 0) {

                choix_card = generateRandomNumber() % cardsHand.size();
            }
            vector<Card *> cards = m_table->player2->getHand()->getCards();
            Card *card = cards[choix_card];
            if (CardEliteGroup *cardEliteGroupChoisie = dynamic_cast<CardEliteGroup *>(card)) {
                if (cardtacJoue2 < cardtacJoue1 + 1) {
                    if (cardEliteGroupChoisie->getName() == "Joker") {
                        Joker2++;
                    }
                    if (Joker2 > 1 && cardEliteGroupChoisie->getName() == "Joker") {
                        cout << "在同一局游戏中，您不能拥有两张百搭牌，请选择另一张牌"
                             << endl;
                    } else {
                        int choix_stone;
                        choix_stone = generateRandomNumber() % 8 + 1;
                        while ((choix_stone > 8 || choix_stone < 0) ||
                               (m_table->getStones(choix_stone)->getcardp2()->getMudFight() == 0 &&
                                m_table->getStones(choix_stone)->getcardp2()->getCards().size() == 3) ||
                               (m_table->getStones(choix_stone)->getcardp2()->getMudFight() == 1 &&
                                m_table->getStones(choix_stone)->getcardp2()->getCards().size() == 4)) {
                            choix_stone = generateRandomNumber() % 8 + 1;
                        }
                        cout << "人工智能把选择的牌放在终端上 " << choix_stone << " :" << endl;
                        m_table->put(*m_table->getStones(choix_stone), cardEliteGroupChoisie);
                        cout << "终端设备 " << choix_stone << " :" << endl;
                        cartClan = 1;
                        cout << endl;
                        attente_valide = 1;
                        cardtacJoue2++;
                        m_table->getPlayer2()->getHand()->remove(choix_card);
                    }
                } else if (testclan2 == 0) {
                    cout
                            << "您不能打出这张牌，您已经比对手打出一张战术牌多."
                            << endl;
                    print++;
                }
            } else if (ClanCard *ClanCardChoisie = dynamic_cast<ClanCard *>(card)) {
                cout << "AI选择了一张牌：力量 :" << ClanCardChoisie->getNumber() << " 颜色 : "
                     << ClanCardChoisie->getColor() << endl;
                m_table->showTable(2);

                int choix_stone;
                choix_stone = generateRandomNumber() % 8 + 1;
                while ((choix_stone > 8 || choix_stone < 0) ||
                       (m_table->getStones(choix_stone)->getcardp2()->getMudFight() == 0 &&
                        m_table->getStones(choix_stone)->getcardp2()->getCards().size() == 3) ||
                       (m_table->getStones(choix_stone)->getcardp2()->getMudFight() == 1 &&
                        m_table->getStones(choix_stone)->getcardp2()->getCards().size() == 4)) {
                    choix_stone = generateRandomNumber() % 8 + 1;
                }
                cout << "AI将选择的卡放在终端上 " << choix_stone << " :" << endl;
                m_table->put(*m_table->getStones(choix_stone), ClanCardChoisie);
                m_table->showTable(2);
                m_table->getPlayer2()->getHand()->remove(choix_card);
                attente_valide = 1;
                cartClan = 1;
            }
            if (cartClan == 0) {
                if (cardtacJoue2 < cardtacJoue1 + 1) {


                    if (TecCard *TecCardChoisie = dynamic_cast<TecCard *>(card)) {
                        cout << "AI选择了卡片：名称:" << TecCardChoisie->getName() << endl;

                        if (TecCardChoisie->getName() == "Colin Maillard") {
                            int choix_stone;
                            choix_stone = generateRandomNumber() % 8 + 1;
                            while ((choix_stone > 8 || choix_stone < 0) ||
                                   (m_table->getStones(choix_stone)->getcardp2()->getMudFight() == 0 &&
                                    m_table->getStones(choix_stone)->getcardp2()->getCards().size() == 3) ||
                                   (m_table->getStones(choix_stone)->getcardp2()->getMudFight() == 1 &&
                                    m_table->getStones(choix_stone)->getcardp2()->getCards().size() == 4)) {
                                choix_stone = generateRandomNumber() % 8 + 1;
                            }
                            cout << "AI将选择的卡片放在终端上 " << choix_stone << " :" << endl;
                            BattleCard::play_BlindBluff(m_table->getStones(choix_stone));
                            m_table->getPlayer2()->getHand()->remove(choix_card);
                            attente_valide = 1;
                        } else if (TecCardChoisie->getName() == "Combat de Boue") {
                            int choix_stone;
                            choix_stone = generateRandomNumber() % 8 + 1;
                            while ((choix_stone > 8 || choix_stone < 0) ||
                                   (m_table->getStones(choix_stone)->getcardp2()->getMudFight() == 0 &&
                                    m_table->getStones(choix_stone)->getcardp2()->getCards().size() == 3) ||
                                   (m_table->getStones(choix_stone)->getcardp2()->getMudFight() == 1 &&
                                    m_table->getStones(choix_stone)->getcardp2()->getCards().size() == 4)) {
                                choix_stone = generateRandomNumber() % 8 + 1;
                            }
                            BattleCard::play_MudFight(m_table->getStones(choix_stone));
                            m_table->getPlayer2()->getHand()->remove(choix_card);
                            attente_valide = 1;
                        } else if (TecCardChoisie->getName() == "Chasseur de Tete") {
                            CunningCard::Play_RecruiterAI();
                            attente_valide = 1;
                            m_table->getPlayer2()->getHand()->remove(choix_card);
                        } else if (TecCardChoisie->getName() == "Stratege") {
                            for (int i = 0; i < 9; i++) {
                                if (m_table->getStones(i)->getcardp2()->getCards().size() != 0) {
                                    nb_clan++;
                                }

                            }
                            if (nb_clan != 0) {
                                CunningCard::Play_StrategisAI();
                                attente_valide = 1;
                                m_table->getPlayer2()->getHand()->remove(choix_card);
                            } else {

                                attente_valide = 0;
                            }


                        } else if (TecCardChoisie->getName() == "Banshee") {
                            for (int i = 0; i < 9; i++) {
                                if (m_table->getStones(i)->getcardp1()->getCards().size() != 0) {
                                    nb_clan++;
                                }

                            }
                            if (nb_clan != 0) {
                                CunningCard::Play_BansheeAI();
                                attente_valide = 1;
                                m_table->getPlayer2()->getHand()->remove(choix_card);
                            } else {
                                attente_valide = 0;
                            }

                        } else if (TecCardChoisie->getName() == "Traitre") {
                            for (int i = 0; i < 9; i++) {
                                if (m_table->getStones(i)->getcardp1()->getCards().size() != 0) {
                                    nb_clan++;
                                }

                            }
                            if (nb_clan != 0) {
                                CunningCard::Play_TraiterAI();
                                attente_valide = 1;
                                m_table->getPlayer2()->getHand()->remove(choix_card);
                            } else {
                                attente_valide = 0;
                            }

                        }
                        cardtacJoue2++;
                    }
                } else if (testclan == 0 && print == 0) {
                    cout
                            << "你比对手多打出了一张战术牌，所以不能再打出战术牌"
                            << endl;

                }
            }
        }
    }
    else {
        cout << "因为你没有手牌了，所以你要跳过回合。" << endl;
    }
    //AI试图在宣称有三张卡的站点上投注。
    int count_cards = 0;
    for (int i=0 ;i <9;i++) {
        count_cards=0;
        auto cardsstones = m_table->getStones(i)->getcardp2()->getCards();
        if (m_table->m_stones[i]->getrevendique()==2 || m_table->m_stones[i]->getrevendique()==1 ) {
            return;
        }
        else if (cardsstones.size() ==3 ||cardsstones.size()==4 ) {
            cout << "AI将尝试主张这个站点的权利 " << i << endl;
            auto msg =claim_gate(i,false);
            cout << msg << endl;

        }
    }
    int choix_style = generateRandomNumber()%4;
    if (choix_style==3){
     if ( !getTecRest()->isEmpty()){
        switch (getTecRest()->whendrawpayattention() ) {
            case 1: {
                cout << "你拿到了战术地图卡 :" << endl;
                TecCard * a = new TecCard(getTecRest()->drawTecCard());
                m_table->getPlayer2()->getHand()->add(a);
                cout << a->getName() << endl;
                break;
            }
            case 2: {
                cout << "你抽到了精英部队卡片:" << endl;
                CardEliteGroup * b = new CardEliteGroup( getTecRest()->drawCardEliteGroup());
                m_table->getPlayer2()->getHand()->add(b);
                cout << b->getName() << endl;
                break;
            }
        }

    }
    }

    else if (choix_style != 3) {
        if( !getClanRest()->isEmpty()) {
            ClanCard *ci = new ClanCard(getClanRest()->drawClanCard());
            m_table->getPlayer2()->getHand()->add(ci);
            cout << "抽到的卡片 : " << ci->getNumber() << " " << ci->getColor() << endl;

        }
    }


    else {
        cout << "你的牌堆没有剩余的牌了" << endl;
    }
    //显示玩家1的手牌

    cout << "\n回合结束" << endl;

}

void Controller::PlayTurn2(){
    int attente_valide = 0;
    int print = 0;
    int cartClan = 0;


    system ("CLS");
    m_table->showTable(2);
    vector<Card*> cardsHand = m_table->player2->getHand()->getCards();

    testclan = 0;
    if (cardsHand.size()!=0) {


        while (attente_valide != 1) {
            cout << "请选择您想要打出的卡牌（其ID） :" << endl;
            int choix_card, nb_tac = 0, nb_clan = 0, nb_total = 0;
            cin >> choix_card;
            clean();
            while (choix_card >= cardsHand.size() || choix_card < 0) {
                cout << "您没有这张牌，请输入您所拥有的一张牌 :" << endl;
                cin >> choix_card;
            }
            vector<Card *> cards = m_table->player2->getHand()->getCards();
            Card *card = cards[choix_card];

            if (CardEliteGroup *cardEliteGroupChoisie = dynamic_cast<CardEliteGroup *>(card)) {
                if (cardtacJoue2 < cardtacJoue1 + 1) {
                    if (cardEliteGroupChoisie->getName() == "Joker") {
                        Joker2++;
                    }
                    if (Joker1 > 1 && cardEliteGroupChoisie->getName() == "Joker") {
                        cout << "在同一场游戏中不能选择两张百搭牌，请选择其他一张牌"
                             << endl;
                    } else {
                        cout << "您选择了卡片：名称 :" << cardEliteGroupChoisie->getName() << endl;
                        cout << "您想在哪个终端使用这张卡片? :" << endl;
                        int choix_stone;
                        cin >> choix_stone;
                        m_table->getStones(choix_stone)->getcardp1()->getMudFight() == 0;
                        while ((choix_stone > 8 || choix_stone < 0) ||
                               (m_table->getStones(choix_stone)->getcardp2()->getMudFight() == 0 &&
                                m_table->getStones(choix_stone)->getcardp2()->getCards().size() == 3) ||
                               (m_table->getStones(choix_stone)->getcardp2()->getMudFight() == 1 &&
                                m_table->getStones(choix_stone)->getcardp2()->getCards().size() == 4)) {
                            cout << "您不能将您的卡放在这个终端上:" << endl;
                            cin >> choix_stone;
                        }
                        testclan2++;
                        cout << "将选择的卡放在终端上 " << choix_stone << " :" << endl;
                        m_table->put(*m_table->getStones(choix_stone), cardEliteGroupChoisie);
                        cout << "终端 " << choix_stone << " :" << endl;
                        Show_Vector_ClanCard(m_table->getStones(choix_stone)->getcardp2()->getCards());
                        cout << endl;
                        cardtacJoue1++;
                        attente_valide = 1;
                        cartClan = 1;
                        m_table->getPlayer2()->getHand()->remove(choix_card);
                    }

                } else if (testclan2 == 0) {
                    cout
                            << "您不能打出这张牌，您手上的战术牌比对手多一张"
                            << endl;
                    print++;

                }
            } else if (ClanCard *ClanCardChoisie = dynamic_cast<ClanCard *>(card)) {
                cout << "您选择了卡片：力量 :" << ClanCardChoisie->getNumber() << " 颜色 : "
                     << ClanCardChoisie->getColor() << endl;
                system("CLS");
                m_table->showTable(2);
                cout << "请选择一个终点 :" << endl;
                int choix_stone;
                cin >> choix_stone;
                while ((choix_stone > 8 || choix_stone < 0) ||
                       (m_table->getStones(choix_stone)->getcardp2()->getMudFight() == 0 &&
                        m_table->getStones(choix_stone)->getcardp2()->getCards().size() == 3) ||
                       (m_table->getStones(choix_stone)->getcardp2()->getMudFight() == 1 &&
                        m_table->getStones(choix_stone)->getcardp2()->getCards().size() == 4)) {
                    cout << "您不能在此终点放置地图 :" << endl;
                    cin >> choix_stone;
                }
                system("CLS");
                cout << "将选择的地图放在终点上 " << choix_stone << " :" << endl;
                m_table->put(*m_table->getStones(choix_stone), ClanCardChoisie);
                m_table->showTable(2);
                m_table->getPlayer2()->getHand()->remove(choix_card);
                attente_valide = 1;
                cartClan = 1;
            }
            if (cartClan == 0) {
                if (cardtacJoue1 < cardtacJoue2 + 1) {

                    if (TecCard *TecCardChoisie = dynamic_cast<TecCard *>(card)) {

                        cout << "您选择了地图：名称 :" << TecCardChoisie->getName() << endl;

                        if (TecCardChoisie->getName() == "Colin Maillard") {
                            cout << "您想在哪个终端使用这张卡 ? :" << endl;
                            int choix_stone;
                            cin >> choix_stone;
                            while (choix_stone > 8 || choix_stone < 0) {
                                cout << "您没有该终端，请输入一个终端 :" << endl;
                                cin >> choix_stone;
                            }
                            cout << "将所选的卡放在终端上 " << choix_stone << " :" << endl;
                            BattleCard::play_BlindBluff(m_table->getStones(choix_stone));
                            m_table->getPlayer2()->getHand()->remove(choix_card);
                            attente_valide = 1;
                            cardtacJoue2++;
                        } else if (TecCardChoisie->getName() == "Combat de Boue") {
                            int choix_stone;
                            cin >> choix_stone;
                            while (choix_stone > 8 || choix_stone < 0) {
                                cout << "您没有该终端，请输入一个终端 :" << endl;
                                cin >> choix_stone;
                            }
                            cout << "On pose la card choisie sur la stone " << choix_stone << " :" << endl;
                            BattleCard::play_MudFight(m_table->getStones(choix_stone));
                            m_table->getPlayer2()->getHand()->remove(choix_card);
                            attente_valide = 1;
                        } else if (TecCardChoisie->getName() == "Chasseur de Tete") {
                            CunningCard::Play_Recruiter2();
                            attente_valide = 1;
                            m_table->getPlayer1()->getHand()->remove(choix_card);
                        } else if (TecCardChoisie->getName() == "Stratege") {
                            for (int i = 0; i < 9; i++) {
                                if (m_table->getStones(i)->getcardp2()->getCards().size() != 0) {
                                    nb_clan++;
                                }

                            }
                            if (nb_clan != 0) {
                                CunningCard::Play_Strategis2();
                                attente_valide = 1;
                                m_table->getPlayer2()->getHand()->remove(choix_card);
                            } else {
                                cout << "您在桌面上没有卡片." << endl;
                                attente_valide = 0;
                            }
                            attente_valide = 0;

                        } else if (TecCardChoisie->getName() == "Banshee") {
                            for (int i = 0; i < 9; i++) {
                                if (m_table->getStones(i)->getcardp1()->getCards().size() != 0) {
                                    nb_clan++;
                                }

                            }
                            if (nb_clan != 0) {
                                CunningCard::Play_Banshee2();
                                attente_valide = 1;
                                m_table->getPlayer2()->getHand()->remove(choix_card);
                            } else {
                                cout << "您在桌面上没有卡片." << endl;
                                attente_valide = 0;

                            }

                        } else if (TecCardChoisie->getName() == "Traitre") {
                            for (int i = 0; i < 9; i++) {
                                if (m_table->getStones(i)->getcardp1()->getCards().size() != 0) {
                                    nb_clan++;
                                }

                            }
                            if (nb_clan != 0) {
                                CunningCard::Play_Traiter2();
                                attente_valide = 1;
                                m_table->getPlayer2()->getHand()->remove(choix_card);
                            } else {
                                cout << "对手在战场上没有卡牌." << endl;
                                attente_valide = 0;
                            }


                        }
                        //TODO无用，因为精英部队卡是一个部落卡
                        cardtacJoue2++;
                    }
                } else if (testclan2 == 0 && print == 0) {
                    cout
                            << " 您比对手多出了一张战术牌，因此您无法再玩战术牌."
                            << endl;
                }
            }
        }
    }
    else {
        cout << "你跳过了回合，因为你没有剩余的牌了" << endl;
    }
    cout << "您想要认领一个站点吗？输入1表示是，输入0表示否 :" << endl;
    int choix_revendication;
    cin >> choix_revendication;

    if(choix_revendication==1){
        cout << "请选择您想要认领的站点 :" << endl;
        int choix_stone;
        cin >> choix_stone;
        while (m_table->m_stones[choix_stone]->getrevendique()==2 || m_table->m_stones[choix_stone]->getrevendique()==1 && (choix_stone > 8 || choix_stone < 0)) {
            cout << "该站点已经被认领了，请选择另一个站点 :" << endl;
            cin>> choix_stone;
            return;
        }
        auto msg =claim_gate(choix_stone,true);
        cout << msg << endl;
        sleep(3);
        auto cardsstones = m_table->getStones(choix_stone)->getcardp2()->getCards();
        int i =0;

    }
    system ("CLS");
    m_table->showTable(2);
    cout << "请选择您想要的游戏地图：0代表普通地图，1代表战术地图" << endl;
    int choix_style;
    cin >> choix_style;
    while(choix_style!=0 && choix_style!=1){
        cout << "请选择您想要的游戏地图：0代表普通地图，1代表战术地图" << endl;
        cin >> choix_style;
    }
    if (choix_style == 0) {
        if( !getClanRest()->isEmpty()) {

            ClanCard *ci = new ClanCard(getClanRest()->drawClanCard());
            m_table->getPlayer2()->getHand()->add(ci);
            cout << "抽到的卡片 : " << ci->getNumber() << " " << ci->getColor() << endl;

        }
    }
    else if ( !getTecRest()->isEmpty() && choix_style==1){
        switch (getTecRest()->whendrawpayattention() ) {
            case 1: {
                cout << "您抽到了战术卡 :" << endl;
                TecCard * a = new TecCard(getTecRest()->drawTecCard());
                m_table->getPlayer2()->getHand()->add(a);
                cout << a->getName() << endl;
                break;
            }
            case 2: {
                cout << "您抽到了精英部队卡 :" << endl;
                CardEliteGroup * b = new CardEliteGroup( getTecRest()->drawCardEliteGroup());
                m_table->getPlayer2()->getHand()->add(b);
                cout << b->getName() << endl;
                break;
            }
        }

    }
    else {
        cout << "您的牌堆中没有卡牌了" << endl;
    }
    system ("CLS");
    cout << "您的手牌现在由以下牌组成 : " << endl;
    m_table->showTable(2);
 
    cout << "\n回合结束" << endl;
}

void Controller::PlayClassicAI(){

    m_table->showStones(2);
    m_table->showPlayerHand(2);
    vector<Card*> cardsHand = m_table->player1->getHand()->getCards();
    srand(time(0));
    int choix_card, nb_tac=0,nb_clan=0,nb_total=0;
    choix_card = generateRandomNumber()%cardsHand.size();
    while(choix_card>cardsHand.size() || choix_card<0){

        choix_card = generateRandomNumber()%cardsHand.size()+1;
    }
    vector<Card*> cards = m_table->player2->getHand()->getCards();
    Card* card = cards[choix_card];
    if (card = dynamic_cast<ClanCard *>(card)) {
        Card* cardChoisie = m_table->getPlayer2()->getHand()->getCard(choix_card);
        ClanCard* ClanCardChoisie = dynamic_cast<ClanCard*>(cardChoisie);
            cout << "AI选择打出了一张牌：力量 :" << ClanCardChoisie->getNumber() << " 颜色 : " << ClanCardChoisie->getColor() << endl;
        //affichage stone
        //Choix de la stone
        int choix_stone = generateRandomNumber()%8+1;
        if (choix_stone > 8|| choix_stone < 0) {
            choix_stone = generateRandomNumber()%8+1;
        }

        while (m_table->getStones(choix_stone)->getcardp2()->getCards().size()==3){
            cout << "充电桩已满，请选择另一个充电桩 :" << endl;
            choix_stone = generateRandomNumber()%8+1;
        }


        Show_Vector_ClanCard(m_table->getStones(choix_stone)->getcardp2()->getCards());cout <<endl;
        cout << "将抽到的卡片放在充电桩上 "<< choix_stone << " :"<<endl;
        m_table->put(*m_table->getStones(choix_stone),ClanCardChoisie );
        cout << "终端 " << choix_stone << " :" << endl;
        Show_Vector_ClanCard(m_table->getStones(choix_stone)->getcardp2()->getCards());cout <<endl;
        m_table->getPlayer2()->getHand()->remove(choix_card);
    }
    m_table->showStones(2);
    int count_cards = 0;
    for (int i=0 ;i <9;i++) {
        count_cards=0;
        auto cardsstones = m_table->getStones(i)->getcardp2()->getCards();
            if (cardsstones.size() ==3) {
                count_cards = 3;
                auto msg =claim_gate(i,false);
                cout << msg << endl;
                cout << "AI占领了这个充电桩 " << i << endl;
        }
    }

    cout <<"公会镐等级 : "<<getClanRest()->getNbCards()<<"\n";
        ClanCard* ci = new ClanCard(getClanRest()->drawClanCard());
        m_table->getPlayer2()->getHand()->add(ci);
        cout <<"AI抽了一张卡片  : "<< ci->getNumber() <<" "<< ci->getColor() << endl;
        m_table->showPlayerHand(1);
    //jouer card espion
    //Affichage de la Hand du joueur 1
    cout << "AI的手牌组成 :" << endl;
    m_table->showPlayerHand(2);
    cout << "\n回合结束" << endl;
}


void Controller::PlayClassicTurn1(){
    system ("CLS");
    vector<Card*> cardsHand = m_table->player1->getHand()->getCards();
    m_table->showTable(1);
    cout<<"请选择您要打出的卡牌（按其ID选择） :"<<endl;
    int choix_card, nb_tac=0,nb_clan=0,nb_total=0;
    cin>>choix_card; clean();
    while(choix_card>cardsHand.size() || choix_card<0){
        cout<<"您没有这张卡牌，请重新输入您拥有的一张卡牌 :"<<endl;
        cin>>choix_card;
    }
    vector<Card*> cards = m_table->player1->getHand()->getCards();
    Card* card = cards[choix_card];
    if (auto card_choisie = dynamic_cast<ClanCard *>(card)) {
        for (auto card: cards) {
            nb_clan++;
            nb_total++;
        }
        if (nb_clan==0){
            cout << "您已经没有任何王卡了 !" << endl;
            return;
        }
        if (nb_total ==0 ){
            cout << "您没有卡片了 !" << endl;
            return; exit(0);
        }

        system ("CLS");
        cout << "选择的卡片 : " << card_choisie->getColor() << " " << card_choisie->getNumber() << endl;
        m_table->showTable(1);
        cout << "请选取一个终端 :" << endl;
        int choix_stone;
        cin >> choix_stone;
        while (choix_stone > 8 || choix_stone < 0) {
            cout << "您没有这个终端，请输入一个终端 :" << endl;
            cin >> choix_stone;
        }
        while (m_table->getStones(choix_stone)->getcardp1()->getCards().size()==3){
            cout << "该终端已满，请选择另一个终端 :" << endl;
            cin >> choix_stone;
        }

        m_table->put(*m_table->getStones(choix_stone),card_choisie);
        m_table->getPlayer1()->getHand()->remove(choix_card);
        system ("CLS");
        m_table->showTable(1);

    }


    cout << "您想认领一个终端吗？1表示是，0表示否 :" << endl;
    int choix_revendication;
    cin >> choix_revendication;

    if(choix_revendication==1) {
        cout << "请您选择想要认领的终端 :" << endl;
        int choix_stone;
        cin >> choix_stone;
        while (m_table->m_stones[choix_stone]->getrevendique() == 2 ||
               m_table->m_stones[choix_stone]->getrevendique() == 1 && (choix_stone > 9 || choix_stone < 1)) {
            cout << "该终端已被认领，请选择另一个终端 :" << endl;
            cin >> choix_stone;
            return;
        }
        auto msg =claim_gate(choix_stone,true);
        cout << msg << endl;
        sleep(3);
    }
    ClanCard* ci = new ClanCard(getClanRest()->drawClanCard());

    m_table->getPlayer1()->getHand()->add(ci);
    system ("CLS");
    m_table->showTable(1);
    cout <<"抽到的卡片 : "<< ci->getNumber() <<" "<< ci->getColor() << endl;
    cout << "\n回合结束" << endl;

}

void Controller::PlayClassicTurn2(){
    system ("CLS");
    vector<Card*> cardsHand = m_table->player2->getHand()->getCards();
    m_table->showTable(2);
    cout<<"请选择您想要打出的卡片（通过其ID） :"<<endl;
    int choix_card, nb_tac=0,nb_clan=0,nb_total=0;
    cin>>choix_card; clean();
    while(choix_card>cardsHand.size() || choix_card<0){
        cout<<"您没有这张卡片，请重新输入您拥有的一张卡片 :"<<endl;
        cin>>choix_card;
    }
    vector<Card*> cards = m_table->player2->getHand()->getCards();
    Card* card = cards[choix_card];
    if (auto card_choisie = dynamic_cast<ClanCard *>(card)) {
        for (auto card: cards) {
            nb_clan++;
            nb_total++;
        }
        if (nb_clan==0){
            cout << "你已经没有任何氏族卡了 !" << endl;
            return;
        }
        if (nb_total ==0 ){
            cout << "你没有卡牌了 !" << endl;
            return; exit(0);
        }

        system ("CLS");
        cout << "选择的卡片 : " << card_choisie->getColor() << " " << card_choisie->getNumber() << endl;
        m_table->showTable(2);
        cout << "请选择一个终端 :" << endl;
        int choix_stone;
        cin >> choix_stone;
        while (choix_stone > 8 || choix_stone < 0) {
            cout << "您没有这个终端，请输入一个终端 :" << endl;
            cin >> choix_stone;
        }
        while (m_table->getStones(choix_stone)->getcardp2()->getCards().size()==3){
            cout << "终端已满，请选择另一个终端 :" << endl;
            cin >> choix_stone;
        }

        m_table->put(*m_table->getStones(choix_stone),card_choisie);
        m_table->getPlayer2()->getHand()->remove(choix_card);
        system ("CLS");
        m_table->showTable(2);

    }


    cout << "您是否想认领一个终端？ 输入1表示是，输入0表示否 :" << endl;
    int choix_revendication;
    cin >> choix_revendication;

    if(choix_revendication==1) {
        cout << "请选择您想要认领的终端 :" << endl;
        int choix_stone;
        cin >> choix_stone;
        while (m_table->m_stones[choix_stone]->getrevendique() == 2 ||
               m_table->m_stones[choix_stone]->getrevendique() == 1 && (choix_stone > 9 || choix_stone < 1)) {
            cout << "该终端已被认领，请选择另一个终端 :" << endl;
            cin >> choix_stone;
            return;
        }
        auto msg =claim_gate(choix_stone,true);
        cout << msg << endl;
        cout << "点击" ;
        string oui;
        cin >>  oui;
    }
    ClanCard* ci = new ClanCard(getClanRest()->drawClanCard());

    m_table->getPlayer2()->getHand()->add(ci);
    system ("CLS");
    m_table->showTable(2);
    cout <<"抽到的牌 : "<< ci->getNumber() <<" "<< ci->getColor() << endl;
    cout << "\n回合结束" << endl;

}



bool Controller::checkEndGame() {
    int sum1=0;
    int serie1=0;
    int sum2=0;
    int serie2=0;
    for(auto i=0; i<9; i++){
        int j = m_table->m_stones[i]->getrevendique();
        //printf("test");
        if(j==1){
            sum1++;
            serie1++;
            //printf("test1");
            if(serie1==3){
                m_winner=1;
                //printf("test3");
                return true;
            }
            serie2=0;
        }
        else if(j==2){
            sum2++;
            serie2++;
            //printf("test2");
            if(serie2==3){
                m_winner=2;
                return true;
            }
            serie1=0;
        }
        if (sum1 == 5){
            m_winner=1;
            return true;
        }
        else if (sum2 == 5){
            m_winner=2;
            return true;
        }
    }
    return false;
}

std::string Controller::claim_gate(int num_stone, bool huHand) {

    Stone *stone = m_table->getStones(num_stone);
    Combination *combi_j1 = stone->getcardp1();
    Combination *combi_j2 = stone->getcardp2();
    vector<ClanCard *> cards_pose_j1 = combi_j1->getCards();
    vector<ClanCard *> cards_pose_j2 = combi_j2->getCards();

    //临时待办事项:
    cout << "卡牌是\nJ1:  "<< endl;
    Show_Vector_ClanCard(cards_pose_j1);
    cout << "\nJ2:" << endl;
    Show_Vector_ClanCard(cards_pose_j2);
    cout <<"\n"<<endl;
    // 我们检查该终端尚未被认领
    if (stone->getrevendique() != 0){
        return "该标志已经被认领了";
    }

    int joueur_qui_revendique = getTable()->getCurrentPlayer();
    // 我们检查玩家是否放置了 3 或 4 张牌
    if (joueur_qui_revendique == 1){
        if(combi_j1->getMudFight() == 0){
            if (cards_pose_j1.size() !=3){
                return "J1没有打出3张牌，他不能认领该标志";
            }
        }
        else{
            if (cards_pose_j1.size() !=4){
                return "J1没有打出4张牌，他不能认领该标志";
            }
        }
    }
    else{
        if(combi_j2->getMudFight() == 0){
            if (cards_pose_j2.size() !=3){
                return "J2没有打出3张牌，他不能认领该标志";
            }
        }
        else{
            if (cards_pose_j2.size() !=4){
                return "J2没有打出4张牌，他不能认领该标志";
            }
        }
    }


    if (joueur_qui_revendique == 1) {
        cout << "J1要求认领该标志 "<< num_stone << endl;
        if (huHand) {
            //如果我们有精锐部队卡，那么 J1 选择它们的值
            if (contains_joker(cards_pose_j1) || contains_shieldbeare(cards_pose_j1) || contains_spy(cards_pose_j1)) {
                for (auto c: cards_pose_j1) {
                    if (auto t = dynamic_cast<CardEliteGroup *>(c)) {
                        auto NamegetName = t->getName();
                        if (NamegetName == "Joker") {
                            t->player_Joker();
                            combi_j1->calculateForceCombi();
                            combi_j1->setTotalNumber(
                                    combi_j1->getTotalNumber() + static_cast<int>(t->getNumber()));
                        } else if (NamegetName == "Espion") {
                            t->player_Spy();
                            combi_j1->calculateForceCombi();
                            combi_j1->setTotalNumber(
                                    combi_j1->getTotalNumber() + static_cast<int>(t->getNumber()));

                        } else if (NamegetName == "Porte_Bouclier") {
                            t->player_ShieldBeare();
                            combi_j1->calculateForceCombi();
                            combi_j1->setTotalNumber(
                                    combi_j1->getTotalNumber() + static_cast<int>(t->getNumber()));

                        }
                    }
                }
            }
        }
        else{
            if (huHand) {
                if (contains_joker(cards_pose_j1) || contains_shieldbeare(cards_pose_j1) || contains_spy(cards_pose_j1)) {
                    //如果我们有精锐部队卡，那么 J1 选择它们的值
                    for (auto c: cards_pose_j1) {
                        if (auto t = dynamic_cast<CardEliteGroup *>(c)) {
                            auto NamegetName = t->getName();
                            if (NamegetName == "Joker") {
                                t->player_JokerAI();
                                combi_j1->calculateForceCombi();
                                combi_j1->setTotalNumber(
                                        combi_j1->getTotalNumber() + static_cast<int>(t->getNumber()));
                            } else if (NamegetName == "Espion") {
                                t->player_SpyAI();
                                combi_j1->calculateForceCombi();
                                combi_j1->setTotalNumber(
                                        combi_j1->getTotalNumber() + static_cast<int>(t->getNumber()));

                            } else if (NamegetName == "Porte_Bouclier") {
                                t->player_ShieldBeareAI();
                                combi_j1->calculateForceCombi();
                                combi_j1->setTotalNumber(
                                        combi_j1->getTotalNumber() + static_cast<int>(t->getNumber()));

                            }
                        }
                    }
                }
            }
        }

        int tab_troupe_tac[4] = {0, 0, 0, 0};
        if (contains_joker(cards_pose_j2) || contains_shieldbeare(cards_pose_j2) || contains_spy(cards_pose_j2)) {
            // J2已经放置了精英部队卡，但J1声称：我们测试J2的卡可以取的可能值
            size_t i = 0;
            for (auto c: cards_pose_j2) {
                if (auto t = dynamic_cast<CardEliteGroup *>(c)) {
                    auto NamegetName = t->getName();
                    if (NamegetName == "Joker") {
                        tab_troupe_tac[i] = 1;
                    } else if (NamegetName == "Espion") {
                        tab_troupe_tac[i] = 2;
                    } else if (NamegetName == "Porte_Bouclier") {
                        tab_troupe_tac[i] = 3;
                    }
                }
                i++;
            }
        }
        if (combi_j1->getMudFight() == 0) {
            // 创建 J2 卡将在其上变化的向量
            vector<ClanCard *> cards_a1 = m_unplayed_cards;
            vector<ClanCard *> cards_a2 = m_unplayed_cards;
            vector<ClanCard *> cards_a3 = m_unplayed_cards;
            if (cards_pose_j2.size()) {
                for (auto i = 0; i < cards_pose_j2.size() ; i++)
                    switch (i) {
                        case (0): {
                            switch (tab_troupe_tac[i]) {
                                case (0): {
                                    cards_a1.clear();
                                    cards_a1.push_back(cards_pose_j2[i]);
                                    break;
                                }
                                case (1): {
                                    cards_a1.clear();
                                    cards_a1 = gen_vect_joker();
                                    break;
                                }
                                case (2): {
                                    cards_a1.clear();
                                    cards_a1 = gen_vect_espion();
                                    break;
                                }
                                case (3): {
                                    cards_a1.clear();
                                    cards_a1 = gen_vect_portebou();
                                    break;
                                }
                            }
                            break;
                        }
                        case (1): {
                            switch (tab_troupe_tac[i]) {
                                case (0): {
                                    cards_a2.clear();
                                    cards_a2.push_back(cards_pose_j2[i]);
                                    break;
                                }
                                case (1): {
                                    cards_a2.clear();
                                    cards_a2 = gen_vect_joker();
                                    break;
                                }
                                case (2): {
                                    cards_a2.clear();
                                    cards_a2 = gen_vect_espion();
                                    break;
                                }
                                case (3): {
                                    cards_a2.clear();
                                    cards_a2 = gen_vect_portebou();
                                    break;
                                }
                            }
                            break;
                        }
                        case (2): {
                            switch (tab_troupe_tac[i]) {
                                case (0): {
                                    cards_a3.clear();
                                    cards_a3.push_back(cards_pose_j2[i]);
                                    break;
                                }
                                case (1): {
                                    cards_a3.clear();
                                    cards_a3 = gen_vect_joker();
                                    break;
                                }
                                case (2): {
                                    cards_a3.clear();
                                    cards_a3 = gen_vect_espion();
                                    break;
                                }
                                case (3): {
                                    cards_a3.clear();
                                    cards_a3 = gen_vect_portebou();
                                    break;
                                }
                            }
                            break;
                        }
                    }
            }


            for (auto a1: cards_a1) {
                for (auto a2: cards_a2) {
                    for (auto a3: cards_a3) {
                        if (ClanCard_egales(a1, a2) || ClanCard_egales(a1, a3) ||
                            ClanCard_egales(a2, a3)  )
                            continue;

                        Combination *combi_temp = new Combination();
                        combi_temp->addCard(a1);
                        combi_temp->addCard(a2);
                        combi_temp->addCard(a3);
                        if (who_wins(combi_j1, combi_temp) == 2) {
                            // J2 gagne
                            std::ostringstream oss;
                            oss << "\n失败，J2可能会赢: " << endl;
                            oss << a1->getNumber() <<" "<< a1->getColor() << " "<< a2->getNumber() <<" "<< a2->getColor() << " "<< a3->getNumber() <<" "<< a3->getColor() << endl;
                            delete combi_temp;
                            return oss.str();
                        }

                    }
                }
            }
            std::ostringstream oss;
            oss << "成功：J2无法赢得胜利（J1获胜）" << endl;
            stone->setrevendique(1);
            return oss.str();
        }
        else {
            vector<ClanCard *> cards_a1 = m_unplayed_cards;
            vector<ClanCard *> cards_a2 = m_unplayed_cards;
            vector<ClanCard *> cards_a3 = m_unplayed_cards;
            vector<ClanCard *> cards_a4 = m_unplayed_cards;
            if (cards_pose_j2.size()) {
                for (auto i = 0; i < cards_pose_j2.size() ; i++)
                    switch (i) {
                        case (0): {
                            switch (tab_troupe_tac[i]) {
                                case (0): {
                                    cards_a1.clear();
                                    cards_a1.push_back(cards_pose_j2[i]);
                                    break;
                                }
                                case (1): {
                                    cards_a1.clear();
                                    cards_a1 = gen_vect_joker();
                                    break;
                                }
                                case (2): {
                                    cards_a1.clear();
                                    cards_a1 = gen_vect_espion();
                                    break;
                                }
                                case (3): {
                                    cards_a1.clear();
                                    cards_a1 = gen_vect_portebou();
                                    break;
                                }
                            }
                            break;
                        }
                        case (1): {
                            switch (tab_troupe_tac[i]) {
                                case (0): {
                                    cards_a2.clear();
                                    cards_a2.push_back(cards_pose_j2[i]);
                                    break;
                                }
                                case (1): {
                                    cards_a2.clear();
                                    cards_a2 = gen_vect_joker();
                                    break;
                                }
                                case (2): {
                                    cards_a2.clear();
                                    cards_a2 = gen_vect_espion();
                                    break;
                                }
                                case (3): {
                                    cards_a2.clear();
                                    cards_a2 = gen_vect_portebou();
                                    break;
                                }
                            }
                            break;
                        }
                        case (2): {
                            switch (tab_troupe_tac[i]) {
                                case (0): {
                                    cards_a3.clear();
                                    cards_a3.push_back(cards_pose_j2[i]);
                                    break;
                                }
                                case (1): {
                                    cards_a3.clear();
                                    cards_a3 = gen_vect_joker();
                                    break;
                                }
                                case (2): {
                                    cards_a3.clear();
                                    cards_a3 = gen_vect_espion();
                                    break;
                                }
                                case (3): {
                                    cards_a3.clear();
                                    cards_a3 = gen_vect_portebou();
                                    break;
                                }
                            }
                            break;
                        }
                        case (3): {
                            switch (tab_troupe_tac[i]) {
                                case (0): {
                                    cards_a4.clear();
                                    cards_a4.push_back(cards_pose_j2[i]);
                                    break;
                                }
                                case (1): {
                                    cards_a4.clear();
                                    cards_a4 = gen_vect_joker();
                                    break;
                                }
                                case (2): {
                                    cards_a4.clear();
                                    cards_a4 = gen_vect_espion();
                                    break;
                                }
                                case (3): {
                                    cards_a4.clear();
                                    cards_a4 = gen_vect_portebou();
                                    break;
                                }
                            }
                            break;
                        }
                    }
            }

            for (auto a1: cards_a1) {
                for (auto a2: cards_a2) {
                    for (auto a3: cards_a3) {
                        for (auto a4: cards_a4) {
                            if (ClanCard_egales(a1, a2) || ClanCard_egales(a1, a3) || ClanCard_egales(a1, a4) ||
                                ClanCard_egales(a2, a3) || ClanCard_egales(a2, a4) || ClanCard_egales(a3, a4))
                                continue;
                            Combination *combi_temp = new Combination();
                            combi_temp->setMudFight(true);
                            combi_temp->addCard(a1);
                            combi_temp->addCard(a2);
                            combi_temp->addCard(a3);
                            combi_temp->addCard(a4);
                            if (who_wins(combi_j1, combi_temp) == 2) {
                                // J2 gagne
                                std::ostringstream oss;
                                oss << "失败，J2可以获胜" << endl;
                                oss << a1->getNumber() <<" "<< a1->getColor() << " "<< a2->getNumber() <<" "<< a2->getColor() << " "<< a3->getNumber() <<" "<< a3->getColor() << " "<< a4->getNumber() <<" "<< a4->getColor() << endl;
                                delete combi_temp;
                                return oss.str();

                            }
                        }
                    }
                }
            }
            std::ostringstream oss;
            oss << "成功 J2 无法获胜（J1 获胜 2）" << endl;
            stone->setrevendique(1);
            return oss.str();
        }
    }
    else {
        // J2 revendique
        cout << "J2 认领终端 "<< num_stone << endl;
        if (huHand) {
            if(contains_joker(cards_pose_j2) || contains_spy(cards_pose_j2) || contains_shieldbeare(cards_pose_j2)){
                for (auto c: cards_pose_j2) {
                    if (auto t = dynamic_cast<CardEliteGroup *>(c)) {
                        auto NamegetName = t->getName();
                        if (NamegetName == "Joker") {
                            t->player_Joker();
                            combi_j2->calculateForceCombi();
                            combi_j2->setTotalNumber(combi_j2->getTotalNumber() + static_cast<int>(t->getNumber()));

                        } else if (NamegetName == "Espion") {
                            t->player_Spy();
                            combi_j2->calculateForceCombi();
                            combi_j2->setTotalNumber(combi_j2->getTotalNumber() + static_cast<int>(t->getNumber()));

                        } else if (NamegetName == "Porte_Bouclier") {
                            t->player_ShieldBeare();
                            combi_j2->calculateForceCombi();
                            combi_j2->setTotalNumber(combi_j2->getTotalNumber() + static_cast<int>(t->getNumber()));

                        }
                    }
                }

            }
        }
        else {
            if(contains_joker(cards_pose_j2) || contains_spy(cards_pose_j2) || contains_shieldbeare(cards_pose_j2)){
                for (auto c: cards_pose_j2) {
                    if (auto t = dynamic_cast<CardEliteGroup *>(c)) {
                        auto NamegetName = t->getName();
                        if (NamegetName == "Joker") {
                            t->player_JokerAI();
                            combi_j2->calculateForceCombi();
                            combi_j2->setTotalNumber(combi_j2->getTotalNumber() + static_cast<int>(t->getNumber()));

                        } else if (NamegetName == "Espion") {
                            t->player_SpyAI();
                            combi_j2->calculateForceCombi();
                            combi_j2->setTotalNumber(combi_j2->getTotalNumber() + static_cast<int>(t->getNumber()));

                        } else if (NamegetName == "Porte_Bouclier") {
                            t->player_ShieldBeareAI();
                            combi_j2->calculateForceCombi();
                            combi_j2->setTotalNumber(combi_j2->getTotalNumber() + static_cast<int>(t->getNumber()));

                        }
                    }
                }

            }

        }
        int tab_troupe_tac[4] = {0, 0, 0, 0};
        if (contains_joker(cards_pose_j1) || contains_shieldbeare(cards_pose_j1) || contains_spy(cards_pose_j1)) {
            size_t i = 0;
            for (auto c: cards_pose_j1) {
                if (auto t = dynamic_cast<CardEliteGroup *>(c)) {
                    auto NamegetName = t->getName();
                    if (NamegetName == "Joker") {
                        tab_troupe_tac[i] = 1;
                    } else if (NamegetName == "Espion") {
                        tab_troupe_tac[i] = 2;
                    } else if (NamegetName == "Porte_Bouclier") {
                        tab_troupe_tac[i] = 3;
                    }
                }
                i++;
            }
        }
        if (combi_j2->getMudFight() == 0) {
            vector<ClanCard *> cards_a1 = m_unplayed_cards;
            vector<ClanCard *> cards_a2 = m_unplayed_cards;
            vector<ClanCard *> cards_a3 = m_unplayed_cards;
            if (cards_pose_j1.size()) {
                for (auto i = 0; i < cards_pose_j1.size(); i++)
                    switch (i) {
                        case (0): {
                            switch (tab_troupe_tac[i]) {
                                case (0): {
                                    cards_a1.clear();
                                    cards_a1.push_back(cards_pose_j1[i]);
                                    break;
                                }
                                case (1): {
                                    cards_a1.clear();
                                    cards_a1 = gen_vect_joker();
                                    break;
                                }
                                case (2): {
                                    cards_a1.clear();
                                    cards_a1 = gen_vect_espion();
                                    break;
                                }
                                case (3): {
                                    cards_a1.clear();
                                    cards_a1 = gen_vect_portebou();
                                    break;
                                }
                            }
                            break;
                        }
                        case (1): {
                            switch (tab_troupe_tac[i]) {
                                case (0): {
                                    cards_a2.clear();
                                    cards_a2.push_back(cards_pose_j1[i]);
                                    break;
                                }
                                case (1): {
                                    cards_a2.clear();
                                    cards_a2 = gen_vect_joker();
                                    break;
                                }
                                case (2): {
                                    cards_a2.clear();
                                    cards_a2 = gen_vect_espion();
                                    break;
                                }
                                case (3): {
                                    cards_a2.clear();
                                    cards_a2 = gen_vect_portebou();
                                    break;
                                }
                            }
                            break;
                        }
                        case (2): {
                            switch (tab_troupe_tac[i]) {
                                case (0): {
                                    cards_a3.clear();
                                    cards_a3.push_back(cards_pose_j1[i]);
                                    break;
                                }
                                case (1): {
                                    cards_a3.clear();
                                    cards_a3 = gen_vect_joker();
                                    break;
                                }
                                case (2): {
                                    cards_a3.clear();
                                    cards_a3 = gen_vect_espion();
                                    break;
                                }
                                case (3): {
                                    cards_a3.clear();
                                    cards_a3 = gen_vect_portebou();
                                    break;
                                }
                            }
                            break;
                        }
                    }
            }
            // TODO temporaire
            /*cout << "cards_a1" << endl;
            Show_Vector_ClanCard(cards_a1);
            cout << "cards_a2" << endl;
            Show_Vector_ClanCard(cards_a2);
            cout << "cards_a3" << endl;
            Show_Vector_ClanCard(cards_a3);*/

            for (auto a1: cards_a1) {
                for (auto a2: cards_a2) {
                    for (auto a3: cards_a3) {
                        if (ClanCard_egales(a1, a2) || ClanCard_egales(a1, a3) ||
                            ClanCard_egales(a2, a3) )
                            continue;
                        Combination *combi_temp = new Combination();
                        combi_temp->addCard(a1);
                        combi_temp->addCard(a2);
                        combi_temp->addCard(a3);
                        if (who_wins(combi_j2, combi_temp) == 2) {
                            // J1 gagne
                            std::ostringstream oss;
                            oss << "\n失败 J1 也能获胜: " << endl;
                            oss << a1->getNumber() <<" "<< a1->getColor() << " "<< a2->getNumber() <<" "<< a2->getColor() << " "<< a3->getNumber() <<" "<< a3->getColor() << endl;
                            delete combi_temp;
                            return oss.str();
                        }
                    }
                }
            }
            std::ostringstream oss;
            oss << "成功 J1 无法获胜（J2 获胜 1）" << endl;
            stone->setrevendique(2);
            return oss.str();
        }
        else {
            vector<ClanCard *> cards_a1 = m_unplayed_cards;
            vector<ClanCard *> cards_a2 = m_unplayed_cards;
            vector<ClanCard *> cards_a3 = m_unplayed_cards;
            vector<ClanCard *> cards_a4 = m_unplayed_cards;
            if (cards_pose_j1.size()) {
                for (auto i = 0; i < cards_pose_j1.size() ; i++)
                    switch (i) {
                        case (0): {
                            switch (tab_troupe_tac[i]) {
                                case (0): {
                                    cards_a1.clear();
                                    cards_a1.push_back(cards_pose_j1[i]);
                                    break;
                                }
                                case (1): {
                                    cards_a1.clear();
                                    cards_a1 = gen_vect_joker();
                                    break;
                                }
                                case (2): {
                                    cards_a1.clear();
                                    cards_a1 = gen_vect_espion();
                                    break;
                                }
                                case (3): {
                                    cards_a1.clear();
                                    cards_a1 = gen_vect_portebou();
                                    break;
                                }
                            }
                            break;
                        }
                        case (1): {
                            switch (tab_troupe_tac[i]) {
                                case (0): {
                                    cards_a2.clear();
                                    cards_a2.push_back(cards_pose_j1[i]);
                                    break;
                                }
                                case (1): {
                                    cards_a2.clear();
                                    cards_a2 = gen_vect_joker();
                                    break;
                                }
                                case (2): {
                                    cards_a2.clear();
                                    cards_a2 = gen_vect_espion();
                                    break;
                                }
                                case (3): {
                                    cards_a2.clear();
                                    cards_a2 = gen_vect_portebou();
                                    break;
                                }
                            }
                            break;
                        }
                        case (2): {
                            switch (tab_troupe_tac[i]) {
                                case (0): {
                                    cards_a3.clear();
                                    cards_a3.push_back(cards_pose_j1[i]);
                                    break;
                                }
                                case (1): {
                                    cards_a3.clear();
                                    cards_a3 = gen_vect_joker();
                                    break;
                                }
                                case (2): {
                                    cards_a3.clear();
                                    cards_a3 = gen_vect_espion();
                                    break;
                                }
                                case (3): {
                                    cards_a3.clear();
                                    cards_a3 = gen_vect_portebou();
                                    break;
                                }
                            }
                            break;
                        }
                        case (3): {
                            switch (tab_troupe_tac[i]) {
                                case (0): {
                                    cards_a4.clear();
                                    cards_a4.push_back(cards_pose_j1[i]);
                                    break;
                                }
                                case (1): {
                                    cards_a4.clear();
                                    cards_a4 = gen_vect_joker();
                                    break;
                                }
                                case (2): {
                                    cards_a4.clear();
                                    cards_a4 = gen_vect_espion();
                                    break;
                                }
                                case (3): {
                                    cards_a4.clear();
                                    cards_a4 = gen_vect_portebou();
                                    break;
                                }
                            }
                            break;
                        }
                    }
            }
            // TODO temporaire
            /*cout << "cards_a1" << endl;
            Show_Vector_ClanCard(cards_a1);
            cout << "cards_a2" << endl;
            Show_Vector_ClanCard(cards_a2);
            cout << "cards_a3" << endl;
            Show_Vector_ClanCard(cards_a3);
            cout << "cards_a4" << endl;
            Show_Vector_ClanCard(cards_a4);*/

            for (auto a1: cards_a1) {
                for (auto a2: cards_a2) {
                    for (auto a3: cards_a3) {
                        for (auto a4: cards_a4) {
                            if (ClanCard_egales(a1, a2) || ClanCard_egales(a1, a3) || ClanCard_egales(a1, a4) ||
                                ClanCard_egales(a2, a3) || ClanCard_egales(a2, a4) || ClanCard_egales(a3, a4))
                                continue;
                            Combination *combi_temp = new Combination();
                            combi_temp->setMudFight(true);
                            combi_temp->addCard(a1);
                            combi_temp->addCard(a2);
                            combi_temp->addCard(a3);
                            combi_temp->addCard(a4);
                            if (who_wins(combi_j2, combi_temp) == 2) {
                                // J1 gagne
                                std::ostringstream oss;
                                oss << "失败 J1 也能获胜" << endl;
                                oss << a1->getNumber() <<" "<< a1->getColor() << " "<< a2->getNumber() <<" "<< a2->getColor()  << " "<< a3->getNumber() <<" "<< a3->getColor() << " "<< a4->getNumber() <<" "<< a4->getColor() << endl;
                                delete combi_temp;
                                return oss.str();
                            }
                        }
                    }
                }
            }
            std::ostringstream oss;
            oss << "成功 J1 无法获胜（J2 获胜 2）" << endl;
            stone->setrevendique(2);
            return oss.str();
        }
    }
}

void Controller::endGame(){

    delete m_table->player1;
    delete m_table->player2;


    // 释放不同类的成员对象的内存

    // 清空并删除指针容器
    vector<Card*> cardsHand1 = m_table->player1->getHand()->getCards();
    for (int i = 0; i < cardsHand1.size(); i++) {
        delete cardsHand1[i];
    }
    cardsHand1.clear();


    vector<Card*> cardsHand2 = m_table->player2->getHand()->getCards();
    for (int i = 0; i < cardsHand2.size(); i++) {
        delete cardsHand2[i];
    }
    cardsHand2.clear();
    delete[] m_table->player1->getHand();
    delete[] m_table->player2->getHand();
    for (int i=0;i<9;i++){
        delete m_table->m_stones[i];
    }
    delete m_table;
}

void Controller::startClassicGame() {
    // 将 6 张牌添加到玩家 1 的手上
    for (int i = 0; i < 6; i++) {
        ClanCard *ci = new ClanCard(getClanRest()->drawClanCard());
        m_table->player1->getHand()->add(ci);
    }

    // 将 6 张牌添加到玩家 2 的手上
    for (int i = 0; i < 6; i++) {
        ClanCard *ci = new ClanCard(getClanRest()->drawClanCard());
        m_table->player2->getHand()->add(ci);
    }

    // 显示玩家手牌
    m_table->showPlayerHand(1);
    m_table->showPlayerHand(2);
    cout << "抽签阶段结束" << endl<<endl;
}

void Controller::starttecGame() {
    // 将 7 张牌添加到玩家 1 的手上
    for (int i = 0; i < 7; i++) {
        ClanCard *ci = new ClanCard(getClanRest()->drawClanCard());
        m_table->player1->getHand()->add(ci);
    }

    // 将 6 张牌添加到玩家 2 的手上
    for (int i = 0; i < 7; i++) {
        ClanCard *ci = new ClanCard(getClanRest()->drawClanCard());
        m_table->player2->getHand()->add(ci);
    }

    // 显示玩家手牌
    cout << "玩家 1 的手牌:" << endl;
    show_vector_card(m_table->player1->getHand()->getCards());
    cout << "玩家 2 的手牌 :" << endl;
    show_vector_card(m_table->player2->getHand()->getCards());
    cout << "抽签阶段结束" << endl<<endl;
}

void Controller::remove_card_played_v1(ClanCard *card) {
    for (int i = 0; i < m_unplayed_cards.size(); i++) {
        if (m_unplayed_cards[i] == card) {
            m_unplayed_cards.erase(m_unplayed_cards.begin() + i);
        }
    }
}
void Controller::remove_card_played_v2(ClanCard *card) {
    auto p = card->getNumber();
    auto c = card->getColor();
    for (int i = 0; i < m_unplayed_cards.size(); i++) {
        if (m_unplayed_cards[i]->getNumber() == p && m_unplayed_cards[i]->getColor() == c) {
            m_unplayed_cards.erase(m_unplayed_cards.begin() + i);
        }
    }
}


// 小丑所有卡牌
vector<ClanCard *> gen_vect_joker(){
    vector<ClanCard *> res;
    for (auto c : Colors)
        for (auto p : Numbers)
            res.push_back( new ClanCard(p, c));
    return res;

}

//任何颜色的间谍7
vector<ClanCard *> gen_vect_espion(){
    vector<ClanCard *> res;
    for (auto c : Colors)
        res.push_back( new ClanCard(Number::nine, c));
    return res;

}
// 布门
vector<ClanCard *> gen_vect_portebou(){
    vector<ClanCard *> res;
    for (auto c : Colors){
        res.push_back( new ClanCard(Number::one, c));
        res.push_back( new ClanCard(Number::two, c));
        res.push_back( new ClanCard(Number::three, c));
    }
    return res;

}

bool contains_joker(vector<ClanCard *> v){
    for (auto c:v){
        if(auto card =  dynamic_cast<CardEliteGroup *>(c)){
            if (card->getName()=="Joker")
                return true;
        }
    }
    return false;
}

bool contains_spy(vector<ClanCard *> v){
    for (auto c:v){
        if(auto card =  dynamic_cast<CardEliteGroup *>(c)){
            if (card->getName()=="Espion")
                return true;
        }
    }
    return false;
}
bool contains_shieldbeare(vector<ClanCard *> v){
    for (auto c:v){
        if(auto card =  dynamic_cast<CardEliteGroup *>(c)){
            if (card->getName()=="Porte_Bouclier")
                return true;
        }
    }
    return false;
}

int who_wins(Combination * combi1, Combination * combi2){
    if (combi1->getForceCombi()>combi2->getForceCombi()) {
        //cout << "combi1 gagne car force combi" << endl;
        return 1;
    }
    else if (combi1->getForceCombi()<combi2->getForceCombi()) {
        //cout << "combi2 gagne car force combi" << endl;
        return 2;
    }
    else if (combi1->getTotalNumber()>combi2->getTotalNumber()) {
        //cout << "combi1 gagne car total Number" << endl;
        return 1;
    }
    else if (combi1->getTotalNumber()<combi2->getTotalNumber()) {
        //cout << "combi2 gagne car total Number" << endl;
        return 2;
    }
    else {
        //cout << "combi gagne car dernier a put" << endl;
        return combi1->getFirstCompleted();
    }

}

int ClanCard_egales(ClanCard* c1, ClanCard* c2){
    if (c1->getNumber()==c2->getNumber() && c1->getColor()==c2->getColor())
        return 1;
    else
        return 0;
}



