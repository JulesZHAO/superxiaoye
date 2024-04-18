#include "Stone.h"
#include "Controller.h"

void Stone::add_Card(ClanCard* Card){
    Controller& c = Controller::getController(true);
    if (c.getTable()->getCurrentPlayer() == 1) {//���д����鵱ǰ����Ϸ״̬�������ǰ��Ծ����������?1��ͨ��getJoueurACtif()������ã�����ִ�����²�����?
        m_cardp1->addCard(Card);
        if (m_cardp1->getMudFight() == true)
            if (m_cardp1->getCards().size() == 4) {
                m_cardp1->setFirstCompleted(1);
                m_cardp2->setFirstCompleted(1);
            }//�ཬս�Ĺ�����ǿ��Է���������? 
            else {
                if (m_cardp1->getCards().size() == 3) {
                    m_cardp1->setFirstCompleted(1);
                    m_cardp2->setFirstCompleted(1);
                }//���ཬսֻ�ܷ��������� 
            }
    }
    else {//����������1�������?2
        m_cardp2->addCard(Card);
        if (m_cardp1->getMudFight())
            if (m_cardp1->getFirstCompleted() == 0)
                if (m_cardp1->getCards().size() == 4) {
                    m_cardp1->setFirstCompleted(2);
                    m_cardp2->setFirstCompleted(2);
                }
                else {
                    if (m_cardp1->getFirstCompleted() == 0)
                        if (m_cardp1->getCards().size() == 3) {
                            m_cardp1->setFirstCompleted(2);
                            m_cardp2->setFirstCompleted(2);
                        }
                }
    }

}