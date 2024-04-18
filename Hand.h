#pragma once
#include "Card.h"
#include<iostream>
#include<string>
#include <vector>

using namespace std;
class Hand {
private:
    vector<Card*> m_cards;
    size_t m_nb_tec_card_played;
    int m_nb;
    bool m_joker;
public:
    friend class Player;
    explicit Hand(int nb) :m_nb(0), m_cards(0), m_nb_tec_card_played(0), m_joker(false){};
    ~Hand() = default;
    Hand(const Hand& h) = delete;
    Hand& operator=(const Hand& h) = delete;

    size_t getNbCards() const { return m_nb; }
    size_t getNbTecCardPlayed() const { return m_nb_tec_card_played; }
    void add(Card* c) { m_cards.push_back(c); }
    void remove(size_t index) {
        m_cards.erase(m_cards.begin() + index);
        m_nb = m_cards.size();
    }
    vector<Card*>getCards() { return m_cards; }
    Card* getCard(size_t i) const { return m_cards[i]; }
    bool getJoker() const {return m_joker ;}
};
