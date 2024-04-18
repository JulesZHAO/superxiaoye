#pragma once
#include"ClanCard.h"
#include<iostream>
#include<string>
#include<vector>
//Combination���ʾ����Ϸ�е�һ����Ƭ��� 
class Combination{
private:
    int m_force_combi;
    int m_total_number;
    bool m_mudfight, m_blindbluff;
    int m_first_completed; 
    vector <ClanCard*> m_cards;
public:
    Combination() : m_cards({}), m_force_combi(0), m_total_number(0),
             m_blindbluff(false), m_mudfight(false), m_first_completed(0){}

    Combination(vector<ClanCard*> cards):m_cards({}), m_force_combi(0),
             m_total_number(0), m_blindbluff(false), m_mudfight(false), m_first_completed(0) {
        for (auto card : cards) {
			addCard(card);
		}
    }
    void DeleteCard_Stone(int pos){m_cards.erase(m_cards.begin() + pos);}//�Ƴ���������λ�õĿ�Ƭ 
    vector<ClanCard*> getCards(){return m_cards;}//���ؿ�Ƭ����е����п��? 
    int getForceCombi() const{return m_force_combi;}//���ؿ�Ƭ��ϵ�������������������ʾ���Ƕ���һ�������ǿ�ȵ��жϣ����ǿ��Ƶĵ����������ж���cpp�ļ���
    int getTotalNumber() const{return m_total_number;} //���ؿ�Ƭ��ϵ��ܵ���?,������Ǳ�ʾÿ��card�ĵ�����С
    
/*
    void setForceCombi(int force_combi) {
		m_force_combi = force_combi;
*/  //����ԭ����ע�͵��ˣ����Ҿ��ÿ��Բ���ע�͵���
 
    void setTotalNumber(int total_number){m_total_number = total_number;}
    bool getMudFight() const {return m_mudfight;}//����Ƭ�Ƿ��ܵ�mudfight��Ӱ�� 
    void setMudFight(bool mudfight) {
		m_mudfight = mudfight;
        setFirstCompleted(0);
	}//���ÿ����Ƿ��ܵ�mudfight��Ӱ�� 

    bool getBlindBluff(){return m_blindbluff;}
    void setBlindBluff(bool blindbluff) {m_blindbluff = blindbluff;}
    int getFirstCompleted() const {return m_first_completed;}//��ȡ��һ����ɵ���ϱ�־ 
    void setFirstCompleted(int premier_complet) {m_first_completed = premier_complet;}//���õ�һ����ɵ���ϱ�־ 
    int calculateForceCombi();//���ڼ��㿨�������� 

//�ú���������Ƭ��������ӿ�Ƭ��? 
    void addCard(ClanCard* card) {
        if (m_mudfight) {
            if (m_cards.size() == 4)//�Ѿ��������ƾͲ����������� 
                throw std::invalid_argument("���޷���һ����������ӳ���?4�ſ�Ƭ");
            else{
                m_cards.push_back(card);//���ӿ�Ƭ 
                setTotalNumber(getTotalNumber() + static_cast<int>(card->getNumber()));
                //���¿�Ƭ��ϵ��ܵ���? 
            }
        }//���ϵ����ܵ�mudfight��Ӱ�� �Ͳ�ȡ��Щ���� ��Ȼ������ 
        else{
            if (m_cards.size() == 3)throw std::invalid_argument("��������û���ཬս�����������������ӳ���3�ſ�Ƭ");
            else{
                m_cards.push_back(card);
                //cout << getTotalPuissance() + static_cast<int>(card->getPuissance()) << endl;��һ��Ҳ��ԭ������ע�͵���
                setTotalNumber(getTotalNumber() + static_cast<int>(card->getNumber()));   
            }
        }
        if (m_blindbluff) m_force_combi = 0;
        //����ܵ�BlindBluffս����Ӱ��,�����Ҳ�֪��ΪʲôҪ������������Ϊ0��ä���ƾֵ���
        //����ֻ�Ƚ������ƵĴ�С������Ϊʲô����Ϊ0     
        else m_force_combi = calculateForceCombi();
    }


};

