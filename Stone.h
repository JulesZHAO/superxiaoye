#pragma once
#include "Combination.h"

class Stone{
        int m_num;
        int m_revendique;//Ŀǰ��֪�������ʲô����û�ĳ�Ӣ��?
        Combination *m_cardp1;
        Combination *m_cardp2;

    public:
        friend class Table;
        explicit Stone(int num,bool BlindBluff=false,bool MudFight=false):m_num(num),m_revendique(0){
            m_cardp1=new Combination();
            m_cardp2=new Combination();
        }
        int getnum() const{
            return m_num;
        }
        void setnum(int num) {
            m_num = num;
        } 
        int getrevendique() const{
            return m_revendique;
        }
        int setrevendique(int revendique){
            m_revendique = revendique;
        }
        Combination* getcardp1() const {
            return m_cardp1;
        }
        Combination* getcardp2() const {
            return m_cardp2;
        }
        void setBlindBluff(bool BlindBluff){
            m_cardp1[0].setBlindBluff(BlindBluff);
            m_cardp2[0].setBlindBluff(BlindBluff);
        }
        void setMudFight(bool MudFight){
            m_cardp1[0].setMudFight(MudFight);
            m_cardp2[0].setMudFight(MudFight);
        }
        void add_Card(ClanCard* card);
};
