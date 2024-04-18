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
        printf("ս��\n");
        m_table = new Table(7, false, false);
    }
    else{
        m_table = new Table(6, false, false);
        printf("����\n");
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
    std::cout << "δ�����Ŀ��� : " << std::endl;
    for (int i = 0; i < m_unplayed_cards.size(); ++i)
    {
        std::cout << "��Ƭ " << i + 1 << ": ";
        if (m_unplayed_cards[i] != nullptr)
            std::cout << m_unplayed_cards[i]->getColor() << " "<< m_unplayed_cards[i]->getNumber()<< std::endl;
        else
            std::cout << "û�п�Ƭ" << std::endl;
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
            cout << "����ѡ������Ҫ����Ŀ�Ƭ����ID�� :" << endl;
            int choix_card, nb_tac = 0, nb_clan = 0, nb_total = 0;
            cin >> choix_card;
            clean();
            while (choix_card >= cardsHand.size() || choix_card < 0) {
                cout << "��û�����ſ�����������ӵ�е�һ�ſ� :" << endl;
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
                        cout << "��������ͬһ����Ϸ��ʹ������С���ƣ���ѡ����һ����"
                             << endl;
                    } else {
                        cout << "��ѡ���˿�Ƭ������:" << cardEliteGroupChoisie->getName() << endl;
                        cout << "�������ĸ��ն�ʹ�����ſ�Ƭ ? :" << endl;
                        int choix_stone;
                        cin >> choix_stone;
                        m_table->getStones(choix_stone)->getcardp1()->getMudFight() == 0;
                        while ((choix_stone > 8 || choix_stone < 0) ||
                               (m_table->getStones(choix_stone)->getcardp1()->getMudFight() == 0 &&
                                m_table->getStones(choix_stone)->getcardp1()->getCards().size() == 3) ||
                               (m_table->getStones(choix_stone)->getcardp1()->getMudFight() == 1 &&
                                m_table->getStones(choix_stone)->getcardp1()->getCards().size() == 4)) {
                            cout << "�����ܽ����Ŀ�Ƭ��������ն���:" << endl;
                            cin >> choix_stone;
                        }
                        testclan++;
                        cout << "��ѡ��Ŀ�Ƭ�����ն��� " << choix_stone << " :" << endl;
                        m_table->put(*m_table->getStones(choix_stone), cardEliteGroupChoisie);
                        cout << "�ն� " << choix_stone << " :" << endl;
                        Show_Vector_ClanCard(m_table->getStones(choix_stone)->getcardp1()->getCards());
                        cout << endl;
                        cardtacJoue1++;
                        attente_valide = 1;
                        cartClan = 1;
                        m_table->getPlayer1()->getHand()->remove(choix_card);
                    }

                } else if (testclan == 0) {
                    cout
                            << "������ʹ�������ƣ����ȶ��ֶ��һ��ս����"
                            << endl;
                    print++;

                }
            } else if (ClanCard *ClanCardChoisie = dynamic_cast<ClanCard *>(card)) {
                cout << "��ѡ���˿�Ƭ������ :" << ClanCardChoisie->getNumber() << " ��ɫ : "
                     << ClanCardChoisie->getColor() << endl;
                system("CLS");
                m_table->showTable(1);
                cout << "��ѡ��һ���յ� :" << endl;
                int choix_stone;
                cin >> choix_stone;
                while ((choix_stone > 8 || choix_stone < 0) ||
                       (m_table->getStones(choix_stone)->getcardp1()->getMudFight() == 0 &&
                        m_table->getStones(choix_stone)->getcardp1()->getCards().size() == 3) ||
                       (m_table->getStones(choix_stone)->getcardp1()->getMudFight() == 1 &&
                        m_table->getStones(choix_stone)->getcardp1()->getCards().size() == 4)) {
                    cout << "�������ڴ��յ��Ϸ��ÿ�Ƭ :" << endl;
                    cin >> choix_stone;
                }
                system("CLS");
                cout << "���ǽ�ѡ��ĵ�ͼ��������յ��� " << choix_stone << " :" << endl;
                m_table->put(*m_table->getStones(choix_stone), ClanCardChoisie);
                m_table->showTable(1);
                m_table->getPlayer1()->getHand()->remove(choix_card);
                attente_valide = 1;
                cartClan = 1;
            }
            if (cartClan == 0) {
                if (cardtacJoue1 < cardtacJoue2 + 1) {

                    if (TecCard *TecCardChoisie = dynamic_cast<TecCard *>(card)) {

                        cout << "��ѡ��ĵ�ͼ�ǣ����� :" << TecCardChoisie->getName() << endl;

                        if (TecCardChoisie->getName() == "Colin Maillard") {
                            cout << "�������ĸ��ն�ʹ�����ŵ�ͼ ? :" << endl;
                            int choix_stone;
                            cin >> choix_stone;
                            while (choix_stone > 8 || choix_stone < 0) {
                                cout << "��û�и��նˣ���������ȷ���ն� :" << endl;
                                cin >> choix_stone;
                            }
                            cout << "��ѡ��Ŀ������ն��� " << choix_stone << " :" << endl;
                            BattleCard::play_BlindBluff(m_table->getStones(choix_stone));
                            m_table->getPlayer1()->getHand()->remove(choix_card);
                            attente_valide = 1;
                            cardtacJoue1++;
                        } else if (TecCardChoisie->getName() == "Combat de Boue") {
                            int choix_stone;
                            cin >> choix_stone;
                            while (choix_stone > 8 || choix_stone < 0) {
                                cout << "��û������նˣ�������һ���ն� :" << endl;
                                cin >> choix_stone;
                            }
                            cout << "���ǰ�ѡ���Ŀ�Ƭ�����ն��� " << choix_stone << " :" << endl;
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
                                cout << "����������û�п�Ƭ." << endl;
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
                                cout << "����������û�п�Ƭ." << endl;
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
                                cout << "������������û��ֽ��." << endl;
                                attente_valide = 0;
                            }


                        }
                        //TODO ne sert a rien car une card EliteGroup est une ClanCard
                        cardtacJoue1++;
                    }
                } else if (testclan == 0 && print == 0) {
                    cout
                            << " ���Ѿ�����ȶ��ֶ�һ��ս���ƣ������㲻�ܴ��ս����."
                            << endl;
                }
            }
        }
    }
    else {
        cout << "�������˻غϣ���Ϊ��û��������" << endl;
    }
    cout << "����Ҫ��ȡһ����ʩ��1�����ǣ�0�����:" << endl;
    int choix_revendication;
    cin >> choix_revendication;

    if(choix_revendication==1){
        cout << "����ѡ������Ҫ��ȡ����ʩ :" << endl;
        int choix_stone;
        cin >> choix_stone;
        while (m_table->m_stones[choix_stone]->getrevendique()==2 || m_table->m_stones[choix_stone]->getrevendique()==1 && (choix_stone > 8 || choix_stone < 0)) {
            cout << "����ʩ�Ѿ������죬��ѡ��������ʩ :" << endl;
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
    cout << "��ѡ����Ҫѡ���ս����ͼ����ͨ��ͼ��0������ͨ��1����ս��" << endl;
    int choix_style;
    cin >> choix_style;
    while(choix_style!=0 && choix_style!=1){
        cout << "��ѡ����Ҫѡ���ս����ͼ����ͨ��ͼ��0������ͨ��1����ս��" << endl;
        cin >> choix_style;
    }
    if (choix_style == 0) {
        if( !getClanRest()->isEmpty()) {

            ClanCard *ci = new ClanCard(getClanRest()->drawClanCard());
            m_table->getPlayer1()->getHand()->add(ci);
            cout << "��ȡ�Ŀ�Ƭ : " << ci->getNumber() << " " << ci->getColor() << endl;

        }
    }
    else if ( !getTecRest()->isEmpty() && choix_style==1){
        switch (getTecRest()->whendrawpayattention() ) {
            case 1: {
                cout << "��鵽��ս���� :" << endl;
                TecCard * a = new TecCard(getTecRest()->drawTecCard());
                m_table->getPlayer1()->getHand()->add(a);
                cout << a->getName() << endl;
                break;
            }
            case 2: {
                cout << "��鵽�˾�Ӣ���ӿ� :" << endl;
                CardEliteGroup * b = new CardEliteGroup( getTecRest()->drawCardEliteGroup());
                m_table->getPlayer1()->getHand()->add(b);
                cout << b->getName() << endl;
                break;
            }
        }

    }
    else {
        cout << "����ƶ���û��ʣ�������" << endl;
    }
    //Affichage de la Hand du joueur 1
    system ("CLS");
    cout << "�����ڵ����������¿������ : " << endl;
    m_table->showTable(1);

    //cout <<"taille Rest tactique : "<<getTecRest()->getNbCards()<<"\n";
    //Display_Gate1();
    cout << "\n�غϽ���" << endl;
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
                        cout << "��ͬһ����Ϸ�У�������ӵ�����Űٴ��ƣ���ѡ����һ����"
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
                        cout << "�˹����ܰ�ѡ����Ʒ����ն��� " << choix_stone << " :" << endl;
                        m_table->put(*m_table->getStones(choix_stone), cardEliteGroupChoisie);
                        cout << "�ն��豸 " << choix_stone << " :" << endl;
                        cartClan = 1;
                        cout << endl;
                        attente_valide = 1;
                        cardtacJoue2++;
                        m_table->getPlayer2()->getHand()->remove(choix_card);
                    }
                } else if (testclan2 == 0) {
                    cout
                            << "�����ܴ�������ƣ����Ѿ��ȶ��ִ��һ��ս���ƶ�."
                            << endl;
                    print++;
                }
            } else if (ClanCard *ClanCardChoisie = dynamic_cast<ClanCard *>(card)) {
                cout << "AIѡ����һ���ƣ����� :" << ClanCardChoisie->getNumber() << " ��ɫ : "
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
                cout << "AI��ѡ��Ŀ������ն��� " << choix_stone << " :" << endl;
                m_table->put(*m_table->getStones(choix_stone), ClanCardChoisie);
                m_table->showTable(2);
                m_table->getPlayer2()->getHand()->remove(choix_card);
                attente_valide = 1;
                cartClan = 1;
            }
            if (cartClan == 0) {
                if (cardtacJoue2 < cardtacJoue1 + 1) {


                    if (TecCard *TecCardChoisie = dynamic_cast<TecCard *>(card)) {
                        cout << "AIѡ���˿�Ƭ������:" << TecCardChoisie->getName() << endl;

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
                            cout << "AI��ѡ��Ŀ�Ƭ�����ն��� " << choix_stone << " :" << endl;
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
                            << "��ȶ��ֶ�����һ��ս���ƣ����Բ����ٴ��ս����"
                            << endl;

                }
            }
        }
    }
    else {
        cout << "��Ϊ��û�������ˣ�������Ҫ�����غϡ�" << endl;
    }
    //AI��ͼ�����������ſ���վ����Ͷע��
    int count_cards = 0;
    for (int i=0 ;i <9;i++) {
        count_cards=0;
        auto cardsstones = m_table->getStones(i)->getcardp2()->getCards();
        if (m_table->m_stones[i]->getrevendique()==2 || m_table->m_stones[i]->getrevendique()==1 ) {
            return;
        }
        else if (cardsstones.size() ==3 ||cardsstones.size()==4 ) {
            cout << "AI�������������վ���Ȩ�� " << i << endl;
            auto msg =claim_gate(i,false);
            cout << msg << endl;

        }
    }
    int choix_style = generateRandomNumber()%4;
    if (choix_style==3){
     if ( !getTecRest()->isEmpty()){
        switch (getTecRest()->whendrawpayattention() ) {
            case 1: {
                cout << "���õ���ս����ͼ�� :" << endl;
                TecCard * a = new TecCard(getTecRest()->drawTecCard());
                m_table->getPlayer2()->getHand()->add(a);
                cout << a->getName() << endl;
                break;
            }
            case 2: {
                cout << "��鵽�˾�Ӣ���ӿ�Ƭ:" << endl;
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
            cout << "�鵽�Ŀ�Ƭ : " << ci->getNumber() << " " << ci->getColor() << endl;

        }
    }


    else {
        cout << "����ƶ�û��ʣ�������" << endl;
    }
    //��ʾ���1������

    cout << "\n�غϽ���" << endl;

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
            cout << "��ѡ������Ҫ����Ŀ��ƣ���ID�� :" << endl;
            int choix_card, nb_tac = 0, nb_clan = 0, nb_total = 0;
            cin >> choix_card;
            clean();
            while (choix_card >= cardsHand.size() || choix_card < 0) {
                cout << "��û�������ƣ�����������ӵ�е�һ���� :" << endl;
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
                        cout << "��ͬһ����Ϸ�в���ѡ�����Űٴ��ƣ���ѡ������һ����"
                             << endl;
                    } else {
                        cout << "��ѡ���˿�Ƭ������ :" << cardEliteGroupChoisie->getName() << endl;
                        cout << "�������ĸ��ն�ʹ�����ſ�Ƭ? :" << endl;
                        int choix_stone;
                        cin >> choix_stone;
                        m_table->getStones(choix_stone)->getcardp1()->getMudFight() == 0;
                        while ((choix_stone > 8 || choix_stone < 0) ||
                               (m_table->getStones(choix_stone)->getcardp2()->getMudFight() == 0 &&
                                m_table->getStones(choix_stone)->getcardp2()->getCards().size() == 3) ||
                               (m_table->getStones(choix_stone)->getcardp2()->getMudFight() == 1 &&
                                m_table->getStones(choix_stone)->getcardp2()->getCards().size() == 4)) {
                            cout << "�����ܽ����Ŀ���������ն���:" << endl;
                            cin >> choix_stone;
                        }
                        testclan2++;
                        cout << "��ѡ��Ŀ������ն��� " << choix_stone << " :" << endl;
                        m_table->put(*m_table->getStones(choix_stone), cardEliteGroupChoisie);
                        cout << "�ն� " << choix_stone << " :" << endl;
                        Show_Vector_ClanCard(m_table->getStones(choix_stone)->getcardp2()->getCards());
                        cout << endl;
                        cardtacJoue1++;
                        attente_valide = 1;
                        cartClan = 1;
                        m_table->getPlayer2()->getHand()->remove(choix_card);
                    }

                } else if (testclan2 == 0) {
                    cout
                            << "�����ܴ�������ƣ������ϵ�ս���Ʊȶ��ֶ�һ��"
                            << endl;
                    print++;

                }
            } else if (ClanCard *ClanCardChoisie = dynamic_cast<ClanCard *>(card)) {
                cout << "��ѡ���˿�Ƭ������ :" << ClanCardChoisie->getNumber() << " ��ɫ : "
                     << ClanCardChoisie->getColor() << endl;
                system("CLS");
                m_table->showTable(2);
                cout << "��ѡ��һ���յ� :" << endl;
                int choix_stone;
                cin >> choix_stone;
                while ((choix_stone > 8 || choix_stone < 0) ||
                       (m_table->getStones(choix_stone)->getcardp2()->getMudFight() == 0 &&
                        m_table->getStones(choix_stone)->getcardp2()->getCards().size() == 3) ||
                       (m_table->getStones(choix_stone)->getcardp2()->getMudFight() == 1 &&
                        m_table->getStones(choix_stone)->getcardp2()->getCards().size() == 4)) {
                    cout << "�������ڴ��յ���õ�ͼ :" << endl;
                    cin >> choix_stone;
                }
                system("CLS");
                cout << "��ѡ��ĵ�ͼ�����յ��� " << choix_stone << " :" << endl;
                m_table->put(*m_table->getStones(choix_stone), ClanCardChoisie);
                m_table->showTable(2);
                m_table->getPlayer2()->getHand()->remove(choix_card);
                attente_valide = 1;
                cartClan = 1;
            }
            if (cartClan == 0) {
                if (cardtacJoue1 < cardtacJoue2 + 1) {

                    if (TecCard *TecCardChoisie = dynamic_cast<TecCard *>(card)) {

                        cout << "��ѡ���˵�ͼ������ :" << TecCardChoisie->getName() << endl;

                        if (TecCardChoisie->getName() == "Colin Maillard") {
                            cout << "�������ĸ��ն�ʹ�����ſ� ? :" << endl;
                            int choix_stone;
                            cin >> choix_stone;
                            while (choix_stone > 8 || choix_stone < 0) {
                                cout << "��û�и��նˣ�������һ���ն� :" << endl;
                                cin >> choix_stone;
                            }
                            cout << "����ѡ�Ŀ������ն��� " << choix_stone << " :" << endl;
                            BattleCard::play_BlindBluff(m_table->getStones(choix_stone));
                            m_table->getPlayer2()->getHand()->remove(choix_card);
                            attente_valide = 1;
                            cardtacJoue2++;
                        } else if (TecCardChoisie->getName() == "Combat de Boue") {
                            int choix_stone;
                            cin >> choix_stone;
                            while (choix_stone > 8 || choix_stone < 0) {
                                cout << "��û�и��նˣ�������һ���ն� :" << endl;
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
                                cout << "����������û�п�Ƭ." << endl;
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
                                cout << "����������û�п�Ƭ." << endl;
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
                                cout << "������ս����û�п���." << endl;
                                attente_valide = 0;
                            }


                        }
                        //TODO���ã���Ϊ��Ӣ���ӿ���һ�����俨
                        cardtacJoue2++;
                    }
                } else if (testclan2 == 0 && print == 0) {
                    cout
                            << " ���ȶ��ֶ����һ��ս���ƣ�������޷�����ս����."
                            << endl;
                }
            }
        }
    }
    else {
        cout << "�������˻غϣ���Ϊ��û��ʣ�������" << endl;
    }
    cout << "����Ҫ����һ��վ��������1��ʾ�ǣ�����0��ʾ�� :" << endl;
    int choix_revendication;
    cin >> choix_revendication;

    if(choix_revendication==1){
        cout << "��ѡ������Ҫ�����վ�� :" << endl;
        int choix_stone;
        cin >> choix_stone;
        while (m_table->m_stones[choix_stone]->getrevendique()==2 || m_table->m_stones[choix_stone]->getrevendique()==1 && (choix_stone > 8 || choix_stone < 0)) {
            cout << "��վ���Ѿ��������ˣ���ѡ����һ��վ�� :" << endl;
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
    cout << "��ѡ������Ҫ����Ϸ��ͼ��0������ͨ��ͼ��1����ս����ͼ" << endl;
    int choix_style;
    cin >> choix_style;
    while(choix_style!=0 && choix_style!=1){
        cout << "��ѡ������Ҫ����Ϸ��ͼ��0������ͨ��ͼ��1����ս����ͼ" << endl;
        cin >> choix_style;
    }
    if (choix_style == 0) {
        if( !getClanRest()->isEmpty()) {

            ClanCard *ci = new ClanCard(getClanRest()->drawClanCard());
            m_table->getPlayer2()->getHand()->add(ci);
            cout << "�鵽�Ŀ�Ƭ : " << ci->getNumber() << " " << ci->getColor() << endl;

        }
    }
    else if ( !getTecRest()->isEmpty() && choix_style==1){
        switch (getTecRest()->whendrawpayattention() ) {
            case 1: {
                cout << "���鵽��ս���� :" << endl;
                TecCard * a = new TecCard(getTecRest()->drawTecCard());
                m_table->getPlayer2()->getHand()->add(a);
                cout << a->getName() << endl;
                break;
            }
            case 2: {
                cout << "���鵽�˾�Ӣ���ӿ� :" << endl;
                CardEliteGroup * b = new CardEliteGroup( getTecRest()->drawCardEliteGroup());
                m_table->getPlayer2()->getHand()->add(b);
                cout << b->getName() << endl;
                break;
            }
        }

    }
    else {
        cout << "�����ƶ���û�п�����" << endl;
    }
    system ("CLS");
    cout << "����������������������� : " << endl;
    m_table->showTable(2);
 
    cout << "\n�غϽ���" << endl;
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
            cout << "AIѡ������һ���ƣ����� :" << ClanCardChoisie->getNumber() << " ��ɫ : " << ClanCardChoisie->getColor() << endl;
        //affichage stone
        //Choix de la stone
        int choix_stone = generateRandomNumber()%8+1;
        if (choix_stone > 8|| choix_stone < 0) {
            choix_stone = generateRandomNumber()%8+1;
        }

        while (m_table->getStones(choix_stone)->getcardp2()->getCards().size()==3){
            cout << "���׮��������ѡ����һ�����׮ :" << endl;
            choix_stone = generateRandomNumber()%8+1;
        }


        Show_Vector_ClanCard(m_table->getStones(choix_stone)->getcardp2()->getCards());cout <<endl;
        cout << "���鵽�Ŀ�Ƭ���ڳ��׮�� "<< choix_stone << " :"<<endl;
        m_table->put(*m_table->getStones(choix_stone),ClanCardChoisie );
        cout << "�ն� " << choix_stone << " :" << endl;
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
                cout << "AIռ����������׮ " << i << endl;
        }
    }

    cout <<"�����ȼ� : "<<getClanRest()->getNbCards()<<"\n";
        ClanCard* ci = new ClanCard(getClanRest()->drawClanCard());
        m_table->getPlayer2()->getHand()->add(ci);
        cout <<"AI����һ�ſ�Ƭ  : "<< ci->getNumber() <<" "<< ci->getColor() << endl;
        m_table->showPlayerHand(1);
    //jouer card espion
    //Affichage de la Hand du joueur 1
    cout << "AI��������� :" << endl;
    m_table->showPlayerHand(2);
    cout << "\n�غϽ���" << endl;
}


void Controller::PlayClassicTurn1(){
    system ("CLS");
    vector<Card*> cardsHand = m_table->player1->getHand()->getCards();
    m_table->showTable(1);
    cout<<"��ѡ����Ҫ����Ŀ��ƣ�����IDѡ�� :"<<endl;
    int choix_card, nb_tac=0,nb_clan=0,nb_total=0;
    cin>>choix_card; clean();
    while(choix_card>cardsHand.size() || choix_card<0){
        cout<<"��û�����ſ��ƣ�������������ӵ�е�һ�ſ��� :"<<endl;
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
            cout << "���Ѿ�û���κ������� !" << endl;
            return;
        }
        if (nb_total ==0 ){
            cout << "��û�п�Ƭ�� !" << endl;
            return; exit(0);
        }

        system ("CLS");
        cout << "ѡ��Ŀ�Ƭ : " << card_choisie->getColor() << " " << card_choisie->getNumber() << endl;
        m_table->showTable(1);
        cout << "��ѡȡһ���ն� :" << endl;
        int choix_stone;
        cin >> choix_stone;
        while (choix_stone > 8 || choix_stone < 0) {
            cout << "��û������նˣ�������һ���ն� :" << endl;
            cin >> choix_stone;
        }
        while (m_table->getStones(choix_stone)->getcardp1()->getCards().size()==3){
            cout << "���ն���������ѡ����һ���ն� :" << endl;
            cin >> choix_stone;
        }

        m_table->put(*m_table->getStones(choix_stone),card_choisie);
        m_table->getPlayer1()->getHand()->remove(choix_card);
        system ("CLS");
        m_table->showTable(1);

    }


    cout << "��������һ���ն���1��ʾ�ǣ�0��ʾ�� :" << endl;
    int choix_revendication;
    cin >> choix_revendication;

    if(choix_revendication==1) {
        cout << "����ѡ����Ҫ������ն� :" << endl;
        int choix_stone;
        cin >> choix_stone;
        while (m_table->m_stones[choix_stone]->getrevendique() == 2 ||
               m_table->m_stones[choix_stone]->getrevendique() == 1 && (choix_stone > 9 || choix_stone < 1)) {
            cout << "���ն��ѱ����죬��ѡ����һ���ն� :" << endl;
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
    cout <<"�鵽�Ŀ�Ƭ : "<< ci->getNumber() <<" "<< ci->getColor() << endl;
    cout << "\n�غϽ���" << endl;

}

void Controller::PlayClassicTurn2(){
    system ("CLS");
    vector<Card*> cardsHand = m_table->player2->getHand()->getCards();
    m_table->showTable(2);
    cout<<"��ѡ������Ҫ����Ŀ�Ƭ��ͨ����ID�� :"<<endl;
    int choix_card, nb_tac=0,nb_clan=0,nb_total=0;
    cin>>choix_card; clean();
    while(choix_card>cardsHand.size() || choix_card<0){
        cout<<"��û�����ſ�Ƭ��������������ӵ�е�һ�ſ�Ƭ :"<<endl;
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
            cout << "���Ѿ�û���κ����忨�� !" << endl;
            return;
        }
        if (nb_total ==0 ){
            cout << "��û�п����� !" << endl;
            return; exit(0);
        }

        system ("CLS");
        cout << "ѡ��Ŀ�Ƭ : " << card_choisie->getColor() << " " << card_choisie->getNumber() << endl;
        m_table->showTable(2);
        cout << "��ѡ��һ���ն� :" << endl;
        int choix_stone;
        cin >> choix_stone;
        while (choix_stone > 8 || choix_stone < 0) {
            cout << "��û������նˣ�������һ���ն� :" << endl;
            cin >> choix_stone;
        }
        while (m_table->getStones(choix_stone)->getcardp2()->getCards().size()==3){
            cout << "�ն���������ѡ����һ���ն� :" << endl;
            cin >> choix_stone;
        }

        m_table->put(*m_table->getStones(choix_stone),card_choisie);
        m_table->getPlayer2()->getHand()->remove(choix_card);
        system ("CLS");
        m_table->showTable(2);

    }


    cout << "���Ƿ�������һ���նˣ� ����1��ʾ�ǣ�����0��ʾ�� :" << endl;
    int choix_revendication;
    cin >> choix_revendication;

    if(choix_revendication==1) {
        cout << "��ѡ������Ҫ������ն� :" << endl;
        int choix_stone;
        cin >> choix_stone;
        while (m_table->m_stones[choix_stone]->getrevendique() == 2 ||
               m_table->m_stones[choix_stone]->getrevendique() == 1 && (choix_stone > 9 || choix_stone < 1)) {
            cout << "���ն��ѱ����죬��ѡ����һ���ն� :" << endl;
            cin >> choix_stone;
            return;
        }
        auto msg =claim_gate(choix_stone,true);
        cout << msg << endl;
        cout << "���" ;
        string oui;
        cin >>  oui;
    }
    ClanCard* ci = new ClanCard(getClanRest()->drawClanCard());

    m_table->getPlayer2()->getHand()->add(ci);
    system ("CLS");
    m_table->showTable(2);
    cout <<"�鵽���� : "<< ci->getNumber() <<" "<< ci->getColor() << endl;
    cout << "\n�غϽ���" << endl;

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

    //��ʱ��������:
    cout << "������\nJ1:  "<< endl;
    Show_Vector_ClanCard(cards_pose_j1);
    cout << "\nJ2:" << endl;
    Show_Vector_ClanCard(cards_pose_j2);
    cout <<"\n"<<endl;
    // ���Ǽ����ն���δ������
    if (stone->getrevendique() != 0){
        return "�ñ�־�Ѿ���������";
    }

    int joueur_qui_revendique = getTable()->getCurrentPlayer();
    // ���Ǽ������Ƿ������ 3 �� 4 ����
    if (joueur_qui_revendique == 1){
        if(combi_j1->getMudFight() == 0){
            if (cards_pose_j1.size() !=3){
                return "J1û�д��3���ƣ�����������ñ�־";
            }
        }
        else{
            if (cards_pose_j1.size() !=4){
                return "J1û�д��4���ƣ�����������ñ�־";
            }
        }
    }
    else{
        if(combi_j2->getMudFight() == 0){
            if (cards_pose_j2.size() !=3){
                return "J2û�д��3���ƣ�����������ñ�־";
            }
        }
        else{
            if (cards_pose_j2.size() !=4){
                return "J2û�д��4���ƣ�����������ñ�־";
            }
        }
    }


    if (joueur_qui_revendique == 1) {
        cout << "J1Ҫ������ñ�־ "<< num_stone << endl;
        if (huHand) {
            //��������о��񲿶ӿ�����ô J1 ѡ�����ǵ�ֵ
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
                    //��������о��񲿶ӿ�����ô J1 ѡ�����ǵ�ֵ
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
            // J2�Ѿ������˾�Ӣ���ӿ�����J1���ƣ����ǲ���J2�Ŀ�����ȡ�Ŀ���ֵ
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
            // ���� J2 ���������ϱ仯������
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
                            oss << "\nʧ�ܣ�J2���ܻ�Ӯ: " << endl;
                            oss << a1->getNumber() <<" "<< a1->getColor() << " "<< a2->getNumber() <<" "<< a2->getColor() << " "<< a3->getNumber() <<" "<< a3->getColor() << endl;
                            delete combi_temp;
                            return oss.str();
                        }

                    }
                }
            }
            std::ostringstream oss;
            oss << "�ɹ���J2�޷�Ӯ��ʤ����J1��ʤ��" << endl;
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
                                oss << "ʧ�ܣ�J2���Ի�ʤ" << endl;
                                oss << a1->getNumber() <<" "<< a1->getColor() << " "<< a2->getNumber() <<" "<< a2->getColor() << " "<< a3->getNumber() <<" "<< a3->getColor() << " "<< a4->getNumber() <<" "<< a4->getColor() << endl;
                                delete combi_temp;
                                return oss.str();

                            }
                        }
                    }
                }
            }
            std::ostringstream oss;
            oss << "�ɹ� J2 �޷���ʤ��J1 ��ʤ 2��" << endl;
            stone->setrevendique(1);
            return oss.str();
        }
    }
    else {
        // J2 revendique
        cout << "J2 �����ն� "<< num_stone << endl;
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
                            oss << "\nʧ�� J1 Ҳ�ܻ�ʤ: " << endl;
                            oss << a1->getNumber() <<" "<< a1->getColor() << " "<< a2->getNumber() <<" "<< a2->getColor() << " "<< a3->getNumber() <<" "<< a3->getColor() << endl;
                            delete combi_temp;
                            return oss.str();
                        }
                    }
                }
            }
            std::ostringstream oss;
            oss << "�ɹ� J1 �޷���ʤ��J2 ��ʤ 1��" << endl;
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
                                oss << "ʧ�� J1 Ҳ�ܻ�ʤ" << endl;
                                oss << a1->getNumber() <<" "<< a1->getColor() << " "<< a2->getNumber() <<" "<< a2->getColor()  << " "<< a3->getNumber() <<" "<< a3->getColor() << " "<< a4->getNumber() <<" "<< a4->getColor() << endl;
                                delete combi_temp;
                                return oss.str();
                            }
                        }
                    }
                }
            }
            std::ostringstream oss;
            oss << "�ɹ� J1 �޷���ʤ��J2 ��ʤ 2��" << endl;
            stone->setrevendique(2);
            return oss.str();
        }
    }
}

void Controller::endGame(){

    delete m_table->player1;
    delete m_table->player2;


    // �ͷŲ�ͬ��ĳ�Ա������ڴ�

    // ��ղ�ɾ��ָ������
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
    // �� 6 ������ӵ���� 1 ������
    for (int i = 0; i < 6; i++) {
        ClanCard *ci = new ClanCard(getClanRest()->drawClanCard());
        m_table->player1->getHand()->add(ci);
    }

    // �� 6 ������ӵ���� 2 ������
    for (int i = 0; i < 6; i++) {
        ClanCard *ci = new ClanCard(getClanRest()->drawClanCard());
        m_table->player2->getHand()->add(ci);
    }

    // ��ʾ�������
    m_table->showPlayerHand(1);
    m_table->showPlayerHand(2);
    cout << "��ǩ�׶ν���" << endl<<endl;
}

void Controller::starttecGame() {
    // �� 7 ������ӵ���� 1 ������
    for (int i = 0; i < 7; i++) {
        ClanCard *ci = new ClanCard(getClanRest()->drawClanCard());
        m_table->player1->getHand()->add(ci);
    }

    // �� 6 ������ӵ���� 2 ������
    for (int i = 0; i < 7; i++) {
        ClanCard *ci = new ClanCard(getClanRest()->drawClanCard());
        m_table->player2->getHand()->add(ci);
    }

    // ��ʾ�������
    cout << "��� 1 ������:" << endl;
    show_vector_card(m_table->player1->getHand()->getCards());
    cout << "��� 2 ������ :" << endl;
    show_vector_card(m_table->player2->getHand()->getCards());
    cout << "��ǩ�׶ν���" << endl<<endl;
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


// С�����п���
vector<ClanCard *> gen_vect_joker(){
    vector<ClanCard *> res;
    for (auto c : Colors)
        for (auto p : Numbers)
            res.push_back( new ClanCard(p, c));
    return res;

}

//�κ���ɫ�ļ��7
vector<ClanCard *> gen_vect_espion(){
    vector<ClanCard *> res;
    for (auto c : Colors)
        res.push_back( new ClanCard(Number::nine, c));
    return res;

}
// ����
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



