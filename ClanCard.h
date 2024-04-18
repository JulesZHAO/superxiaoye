#pragma once
#include"Card.h"
#include<iostream>


//氏族卡： ClanCard 由card派生而来 
 
class ClanCard : public Card {
    Number m_number;//这里是扑克牌的数字（1~9）,表示不同的强度级别 
    Color m_color;

public:
    ClanCard(Number number, Color color): m_number(number), m_color(color) {};
    Number getNumber() const { return m_number; }
    Color getColor() const { return m_color; }
    void setColor(Color color) { m_color = color; }
    void setNumber(Number number) { m_number = number; }

    void ShowCard()const {
        switch (getColor())
    
        { 
            case Color::yellow:
                std::cout << "| " << getNumber() << "   " << getColor() << " |";
                break;
            case Color::green:
                std::cout << "| " << getNumber() << "   " << getColor() << " |";
                break;
            case Color::purple:
                std::cout << "| " << getNumber() << "   " << getColor() << " |";
                break;
            case Color::red:
                std::cout << "| " << getNumber() << "   " << getColor() << " |";
                break;
            case Color::blue:
                std::cout << "| " << getNumber() << "   " << getColor() << " |";
                break;
            case Color::black:
                std::cout << "| " << getNumber() << "   " << getColor() << " |";
                break;
        }
    }

    void ShowDisCard()const {
        std::cout << "| 部落地图 |";
    }
};

ostream &operator<<(ostream &os, const ClanCard &ClanCard);
void Show_Vector_ClanCard(vector<ClanCard*> v);

