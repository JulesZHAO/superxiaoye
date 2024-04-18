#include "Rest.h"
#include "SetException.h"
#include <random>
#include <algorithm>


int getRandomInt(int min, int max){
    static std::random_device rd;
    static std::mt19937 generate(rd());
    std::uniform_int_distribution<int> distribution(min,max);
    return distribution(generate);
}

Rest::Rest(const ClanGame& ClanGame) : m_cards(new const Card* [ClanGame.getNbCards()]),m_nb(ClanGame.getNbCards()){
    size_t i = 0;
    for(auto it = ClanGame.getIterator(); !it.isDone(); it.next())
        m_cards[i++] = &it.currentItem();


    for(size_t it = 0; it < 2*m_nb; ++it){
        size_t a = getRandomInt(0, m_nb - 1);
        size_t b = getRandomInt(0, m_nb - 1);

        std::swap(m_cards[a],m_cards[b]);
    }
}

Rest::Rest(const TecGame& TecGame) : m_cards(new const Card* [TecGame.getNbCards()]),m_nb(TecGame.getNbCards()){
    size_t i = 0;
    for(auto it = TecGame.getIterator(); !it.isDone(); it.next())
        m_cards[i++] = &it.currentItem();


    for(size_t it = 0; it < 2*m_nb; ++it){
        size_t a = getRandomInt(0, m_nb - 1);
        size_t b = getRandomInt(0, m_nb - 1);

        std::swap(m_cards[a],m_cards[b]);
    }
}

const Card& Rest::draw(){
    if (isEmpty()){
        throw SetException("it is empty");
    }
    m_nb--;
    const Card* card = m_cards[getNbCards()];
    if(dynamic_cast<const TecCard*>(card)){
        const TecCard* tecCard = dynamic_cast<const TecCard*>(card);
        return *new TecCard(*tecCard);
    }
    else if (dynamic_cast<const ClanCard*>(card)){
        const ClanCard* clanCard = dynamic_cast<const ClanCard*>(card);
        return *new ClanCard(*clanCard);
    }
    throw SetException("");
}

const ClanCard& Rest::drawClanCard(){
    if (isEmpty()){
        throw SetException("it is empty");
    }
    m_nb--;
    const Card* card = m_cards[getNbCards()];

    const ClanCard* clancard = dynamic_cast<const ClanCard*>(card);
    if(!clancard){
        throw SetException("");
    }
    return *clancard;
}

const TecCard& Rest::drawTecCard(){
    if (isEmpty()){
        throw SetException("it is empty");
    }
    m_nb--;
    const Card* card = m_cards[getNbCards()];

    const TecCard* teccard = dynamic_cast<const TecCard*>(card);
    if(!teccard){
        throw SetException("");
    }
    return *teccard;
}

const CardEliteGroup& Rest::drawCardEliteGroup(){
    if (isEmpty()){
        throw SetException("it is empty");
    }
    m_nb--;
    const Card* card = m_cards[getNbCards()];
    const CardEliteGroup* c = dynamic_cast<const CardEliteGroup*>(card);
    if(!c){
        throw SetException("");
    }
    return *c;
}

Rest::~Rest(){
    delete [] m_cards;
}

int Rest::whendrawpayattention(){
    auto card = m_cards[m_nb-1];
    if(auto c1 = dynamic_cast<const TecCard*>(card)) return 1;
    else if (auto c2 = dynamic_cast<const CardEliteGroup*>(card)) return 2;
    else if (auto c3 = dynamic_cast<const ClanCard*>(card)) return 3;
    return 0;
}