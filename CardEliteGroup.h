#pragma once
#include "TecCard.h"
#include "ClanCard.h"
#include<string>
#include<ostream>
//��Ӣ���������忨�������� 
using namespace std;
class CardEliteGroup : public ClanCard {
    string name;

public:

    CardEliteGroup(const string& name, Number number, Color color) : name(name), ClanCard( number, color)  {};

    string getName() const {
        return name;
    }

    CardEliteGroup player_Joker() {
        std::cout << "ѡ��С�� : " << endl;//����ѡ��С�󿨵Ľ׶� 
        for (int i = 0; i < 6; i++) {
            std::cout << i << ": " << static_cast<Color>(i) << endl;//������iת��Ϊ��Ӧ����ɫ 
        }
        int choose_Color = -1;
        while (choose_Color < 0 || choose_Color > 7) {
            std::cout << "��ѡ����ɫ :" << endl;
            std::cin >> choose_Color;//��֤�û�Ҫ����һ����Ч����ɫ��0~7֮��)��Ȼ��һֱ����whileѭ��
        }
        setColor(static_cast<Color>(choose_Color));//���û�ѡ�����ɫת��ΪColor������Ϊ�������ݲ����� 

        int choose_number = -1;
        while (choose_number < 0 || choose_number > 10) {
            std::cout << "��ѡ�� 1 �� 9 ֮���һ����:" << endl;
            std::cin >> choose_number;
        }
        setNumber(static_cast<Number>(choose_number));
    return *this;
    }//�û�ѡ��Ƭ����ɫ��ǿ�� 

    CardEliteGroup player_JokerAI(){
        setColor(static_cast<Color>(rand()%6));
        setNumber(static_cast<Number>(rand()%10));
        return *this;
    }//�������ѡ��Ƭ����ɫ��ǿ�� 



    CardEliteGroup player_ShieldBeare()  {
        std::cout << "�ֿ��˶������� : " << endl;
        for (int i = 0; i < 6; i++) {
            std::cout << i << ": " << static_cast<Color>(i) << endl;
        }
        int choose_Color = -1;
        while (choose_Color < 0 || choose_Color > 7) {
            std::cout << "��ѡ����ɫ :" << endl;
            std::cin >> choose_Color;
        }
        setColor(static_cast<Color>(choose_Color));

        int choose_number = -1;
        while (choose_number < 0 || choose_number > 4) {
            std::cout << "��ѡ�� 1 �� 3 ֮�� :" << endl;
            std::cin >> choose_number;
        }
        setNumber(static_cast<Number>(choose_number));
        return *this;
    }//�û�ѡ��Ƭ����ɫ��ǿ�� 
    
    CardEliteGroup player_ShieldBeareAI(){
        setColor(static_cast<Color>(rand()%6));
        setNumber(static_cast<Number>(rand()%4));
        return *this;
    }//�������ѡ��Ƭ����ɫ��ǿ�� 

    CardEliteGroup player_Spy() {
        std::cout << "������ƿ� : " << endl;
        for (int i = 0; i < 6; i++) {
            std::cout << i << ": " << static_cast<Color>(i) << endl;
        }
        int choose_Color = -1;
        while (choose_Color < 0 || choose_Color > 7) {
            std::cout << "��ѡ����ɫ :" << endl;
            std::cin >> choose_Color;
        }
        setColor(static_cast<Color>(choose_Color));//�û�ѡ��Ƭ����ɫ 
        setNumber(Number::seven);//���������Ϊ7 
        return *this;
    }
    CardEliteGroup player_SpyAI(){
        setColor(static_cast<Color>(rand()%6));//�������ѡ��Ƭ����ɫ 
        setNumber(Number::seven);//���������Ϊ7 
        return *this;
    }

    void ShowCard() const{
        if(getName()=="Joker"){
            std::cout << "| С�� |";
        }
        else if(getName()=="ShieldBeare"){
            std::cout << "| ���ܿ� |";
        }
        else if(getName()=="Spy"){
            std::cout << "| ����� |";
        }
        else{
            std::cout << "|    " << getName() << "    |";
        }
    }

    void ShowDisCard() const {
        std::cout << "| ���Ա��� |";
    }
};

