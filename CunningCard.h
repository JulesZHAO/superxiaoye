#pragma once
#include"TecCard.h"
//CunningCard：诡计卡，由战术牌派生而来 
class CunningCard : public TecCard {
public:
    CunningCard(const string& nom) : TecCard(nom)  {};


    static void Play_Recruiter() ;
    static void Play_Strategis() ;
    static void Play_Banshee() ;
    static void Play_Traiter() ;
    static void Play_Recruiter2() ;
    static void Play_Strategis2() ;                                                               
    static void Play_Banshee2() ;
    static void Play_Traiter2() ;
    static void Play_RecruiterAI() ;
    static void Play_StrategisAI() ;
    static void Play_BansheeAI() ;
    static void Play_TraiterAI() ;

    void ShowCard()const {
        if(getName()=="Recruiter"){
            std::cout << "| 招募者 |";
        }
        else if(getName()=="Strategis"){
            std::cout << "| 战略家 |";
        }
        else if(getName()=="Banshee"){
            std::cout << "| 女妖 |";
        }
        else if(getName()=="Traiter"){
            std::cout << "| 背叛者 |";
        }

    }

    void ShowDisCard()const{
        std::cout  << "| 战术卡 |";
    }
};

