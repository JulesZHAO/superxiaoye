#pragma once
#include <iostream>
#include<string>
#include "SetException.h"
#include<vector>
#include"SetCard.h"

using namespace std;

class Card {
public:
    virtual ~Card() {};
    virtual void showCard() const {
        std::cout<<"showCard";
    }
    virtual void showDisCard() const {
        std::cout<<"showDisCard";
    }
};

void show_vector_card(vector<Card*> v); //接受一个Card对象的指针向量，并对每个对象调用showCard打印
void show_vector_card2(vector<struct ClanCard*> v);//接受一个ClanCard结构体对象的指针向量，并对每个对象调用showCard打印

