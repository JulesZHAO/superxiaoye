#pragma once
#include"Card.h"
#include<iostream>


//���忨�� ClanCard ��card�������� 
 
class ClanCard : public Card {
    Number m_number;//�������˿��Ƶ����֣�1~9��,��ʾ��ͬ��ǿ�ȼ��� 
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
        std::cout << "| �����ͼ |";
    }
};

ostream &operator<<(ostream &os, const ClanCard &ClanCard);
void Show_Vector_ClanCard(vector<ClanCard*> v);

