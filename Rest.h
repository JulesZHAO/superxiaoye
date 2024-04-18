#pragma once
#include"Card.h"
#include"ClanGame.h"
#include"TecGame.h"
#include"CardEliteGroup.h"
#include "TecCard.h"

class Rest {
private:
    const Card** m_cards = nullptr;
    size_t m_nb;
public:
    Rest(const ClanGame& clangame);
    Rest(const TecGame& tecgame);
    ~Rest();
    Rest(const Rest& r) = delete;
    Rest& operator=(const Rest& r) = delete;
    
    void setM_nb(size_t mNb){m_nb = mNb;}
    bool isEmpty() const { return m_nb == 0; }
    size_t getNbCards() const { return m_nb; }
    const Card**& getCards() {return m_cards;}
    const Card& draw(); 
    const ClanCard& drawClanCard();
    const TecCard& drawTecCard();
    const CardEliteGroup& drawCardEliteGroup();
    int whendrawpayattention();
    void push_back(const Card* card) {
        const Card** newtab = new const Card * [m_nb + 1];
        for (size_t i = 0; i < m_nb; i++) newtab[i] = m_cards[i];
        newtab[m_nb] = card;
        delete[] m_cards;
        m_cards = newtab;
        ++m_nb;
    }
    void push_back2(const Card* card){
        m_cards[++m_nb] = card;
    }

};
int getRandomInt(int min, int max);