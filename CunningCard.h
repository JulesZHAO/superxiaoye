#pragma once
#include"TecCard.h"
//CunningCard����ƿ�����ս������������ 
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
            std::cout << "| ��ļ�� |";
        }
        else if(getName()=="Strategis"){
            std::cout << "| ս�Լ� |";
        }
        else if(getName()=="Banshee"){
            std::cout << "| Ů�� |";
        }
        else if(getName()=="Traiter"){
            std::cout << "| ������ |";
        }

    }

    void ShowDisCard()const{
        std::cout  << "| ս���� |";
    }
};

