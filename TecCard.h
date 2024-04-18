#pragma once
#include "Card.h"

class TecCard : public Card{
private:
    const string m_name;
public:
    TecCard(const string& name): m_name(name){};
    
    const string& getName() const { return m_name;}
    void showCard() const {
        if(getName() == "Recruiter") std::cout<< "| Recruiter |";
        if(getName() == "Strategis") std::cout<< "| Strategis |";
        if(getName() == "Banshee") std::cout<< "| Banshee |";
        if(getName() == "Traiter") std::cout<< "| Traiter |";
        if(getName() == "Blind Bluff") std::cout<< "| Blind Bluff |";
        if(getName() == "Mud Fight") std::cout<< "| Mud Fight |";
    }
    void showDisCard() const {
        std::cout<<"| Discard |";
    }
};