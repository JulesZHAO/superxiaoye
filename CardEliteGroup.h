#pragma once
#include "TecCard.h"
#include "ClanCard.h"
#include<string>
#include<ostream>
//精英卡，由氏族卡派生而来 
using namespace std;
class CardEliteGroup : public ClanCard {
    string name;

public:

    CardEliteGroup(const string& name, Number number, Color color) : name(name), ClanCard( number, color)  {};

    string getName() const {
        return name;
    }

    CardEliteGroup player_Joker() {
        std::cout << "选择小丑卡 : " << endl;//进入选择小丑卡的阶段 
        for (int i = 0; i < 6; i++) {
            std::cout << i << ": " << static_cast<Color>(i) << endl;//将整数i转换为对应的颜色 
        }
        int choose_Color = -1;
        while (choose_Color < 0 || choose_Color > 7) {
            std::cout << "请选择颜色 :" << endl;
            std::cin >> choose_Color;//保证用户要输入一个有效的颜色（0~7之间)不然会一直进入while循环
        }
        setColor(static_cast<Color>(choose_Color));//将用户选择的颜色转换为Color类型作为参数传递并保存 

        int choose_number = -1;
        while (choose_number < 0 || choose_number > 10) {
            std::cout << "请选择 1 到 9 之间的一个数:" << endl;
            std::cin >> choose_number;
        }
        setNumber(static_cast<Number>(choose_number));
    return *this;
    }//用户选择卡片的颜色与强度 

    CardEliteGroup player_JokerAI(){
        setColor(static_cast<Color>(rand()%6));
        setNumber(static_cast<Number>(rand()%10));
        return *this;
    }//电脑随机选择卡片的颜色与强度 



    CardEliteGroup player_ShieldBeare()  {
        std::cout << "持卡人盾牌姿势 : " << endl;
        for (int i = 0; i < 6; i++) {
            std::cout << i << ": " << static_cast<Color>(i) << endl;
        }
        int choose_Color = -1;
        while (choose_Color < 0 || choose_Color > 7) {
            std::cout << "请选择颜色 :" << endl;
            std::cin >> choose_Color;
        }
        setColor(static_cast<Color>(choose_Color));

        int choose_number = -1;
        while (choose_number < 0 || choose_number > 4) {
            std::cout << "请选择 1 到 3 之间 :" << endl;
            std::cin >> choose_number;
        }
        setNumber(static_cast<Number>(choose_number));
        return *this;
    }//用户选择卡片的颜色与强度 
    
    CardEliteGroup player_ShieldBeareAI(){
        setColor(static_cast<Color>(rand()%6));
        setNumber(static_cast<Number>(rand()%4));
        return *this;
    }//电脑随机选择卡片的颜色和强度 

    CardEliteGroup player_Spy() {
        std::cout << "间谍姿势卡 : " << endl;
        for (int i = 0; i < 6; i++) {
            std::cout << i << ": " << static_cast<Color>(i) << endl;
        }
        int choose_Color = -1;
        while (choose_Color < 0 || choose_Color > 7) {
            std::cout << "请选择颜色 :" << endl;
            std::cin >> choose_Color;
        }
        setColor(static_cast<Color>(choose_Color));//用户选择卡片的颜色 
        setNumber(Number::seven);//间谍卡能力为7 
        return *this;
    }
    CardEliteGroup player_SpyAI(){
        setColor(static_cast<Color>(rand()%6));//电脑随机选择卡片的颜色 
        setNumber(Number::seven);//间谍卡能力为7 
        return *this;
    }

    void ShowCard() const{
        if(getName()=="Joker"){
            std::cout << "| 小丑卡 |";
        }
        else if(getName()=="ShieldBeare"){
            std::cout << "| 护盾卡 |";
        }
        else if(getName()=="Spy"){
            std::cout << "| 间谍卡 |";
        }
        else{
            std::cout << "|    " << getName() << "    |";
        }
    }

    void ShowDisCard() const {
        std::cout << "| 策略背面 |";
    }
};

