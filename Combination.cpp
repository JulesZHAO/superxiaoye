#include "Combination.h"
#include "Controller.h"

int Combination::calculateForceCombi()
{
    auto size_card = m_cards.size();//�Ȼ�ȡ�����ϵĿ�������
    Color tab_color[4];
    int tab_number[4];
    for (auto i = 0; i < size_card; i++) {
        tab_color[i] = m_cards[i]->getColor();
        tab_number[i] = static_cast<int>(m_cards[i]->getNumber());
    }
    for (auto i = 0; i < size_card; i++) {
        for (auto j = 0; j < size_card; j++) {
            if (tab_number[i] < tab_number[j]) {
                auto temp = tab_number[i];
                tab_number[i] = tab_number[j];
                tab_number[j] = temp;
            }//���ڽ�number���򣬴Ӵ�С������Ϊ�˺���ñȽ
        }
    }


    if (size_card == 3) {//������ϼ����ƣ������ཬս���Ļ�����3�ţ�
        if (tab_color[0] == tab_color[1] && tab_color[1] == tab_color[2] 
            && tab_number[0] + 1 == tab_number[1] && tab_number[1] + 1 == tab_number[2]) {
            m_force_combi = 4;
            return 4;
        }//�����ͬ��˳����������ϣ����԰������ϵ�force����Ϊ4������force
        if (tab_number[0] == tab_number[1] && tab_number[1] == tab_number[2]) {
            m_force_combi = 3;
            return 3;//��������ǻ�ɫֻ���ǵ�����ͬ���ǵڶ������ϣ���force����Ϊ3������
        }
        if (tab_color[0] == tab_color[1] && tab_color[1] == tab_color[2]) {
            m_force_combi = 2;
            return 2;
        }//��������ǵ���ֻ���ǻ�ɫ��ͬ���ǵ��������ϣ���force����Ϊ2������
        if (tab_number[0] + 1 == tab_number[1] && tab_number[1] + 1 == tab_number[2]) {
            m_force_combi = 1;
            return 1;
        }//���ֻ���ǵ����������������ǻ�ɫ������С����ϣ���force����Ϊ1������

    }
    else if (size_card == 4) {
        if (tab_color[0] == tab_color[1] && tab_color[1] == tab_color[2] 
            && tab_color[2] == tab_color[3] && tab_number[0] + 1 == tab_number[1] 
            && tab_number[1] + 1 == tab_number[2] && tab_number[2] + 1 == tab_number[3]){
            m_force_combi = 4;
            return 4;
        }
        if (tab_number[0] == tab_number[1] && tab_number[1] == tab_number[2] && tab_number[2] == tab_number[3])
        {
            m_force_combi = 3;
            return 3;
        }
        if (tab_color[0] == tab_color[1] && tab_color[1] == tab_color[2] && tab_color[2] == tab_color[3]){
            m_force_combi = 2;
            return 2;
        }
        if (tab_number[0] + 1 == tab_number[1] && tab_number[1] + 1 == tab_number[2] && tab_number[2] + 1 == tab_number[3]){
            m_force_combi = 1;
            return 1;
        }


    }
    m_force_combi = 0;//�����ϵ����޷�ƥ�������κ�һ��������Ǿͷ���forceΪ0�����أ���������С�����
    return 0;
}
