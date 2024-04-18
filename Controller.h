#pragma once
#include "Rest.h"
#include "Table.h"
#include "ClanGame.h"
#include "ClanCard.h"
#include "stdlib.h"
#include"Combination.h"

class Controller {
    int m_winner;
    bool m_tec; // or const bool?
    Rest* m_clan_deck; //bord == hand  ,  pioche == rest
    Rest* m_tec_deck;
    Table* m_table; // or Board
    ClanGame& m_clan_game;
    TecGame& m_tec_game;

    vector<ClanCard*> m_unplayed_cards;

    explicit Controller(bool tec);
    ~Controller();

    struct Processor
    {
        Controller* controller;
        Processor() : controller(nullptr) {}
        ~Processor() { delete controller; }
    };

    static Processor processor;

public:
    Controller(const Controller& j) = delete;
    Controller& operator=(const Controller& j) = delete;

    static Controller& getController(bool tec);
    static void releaseController();

    int getWinner() const { return m_winner; }
    bool getTec() const { return m_tec; }
    void endGame();

    vector<ClanCard*> getUnplayedCards() const { return m_unplayed_cards; }
    void displayUnplayedCards() const;

    void Display_Gate1();
    void Display_Gate2();
    Table* getTable() const { return m_table; }
    void setWinner(int winner) { m_winner = winner; }
    void PlayTurn1();
    void PlayTurn2();
    void PlayClassicAI();
    void PlayAI();

    Rest* getClanRest() const { return m_clan_deck; }
    Rest* getTecRest() const { return m_tec_deck; }
    std::string claim_gate(int gate_num, bool human);

    void startClassicGame();
    void starttecGame();

    void test();

    bool checkEndGame();
    void remove_card_played_v1(ClanCard* card);
    void remove_card_played_v2(ClanCard* card);
    void PlayClassicTurn1();
    void PlayClassicTurn2();

};
int who_wins(Combination* combo1, Combination* combo2);
int ClanCard_equals(ClanCard* c1, ClanCard* c2);
vector<ClanCard*> generate_joker_vector();
vector<ClanCard*> generate_espion_vector();
vector<ClanCard*> generate_gatebearer_vector();

bool contains_joker(vector<ClanCard*> v);
bool contains_spy(vector<ClanCard*> v);
bool contains_shieldbeare(vector<ClanCard*> v);

