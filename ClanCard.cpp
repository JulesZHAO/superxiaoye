#include "ClanCard.h"
#include<ostream>

 using namespace std;
ostream& operator<<(ostream& os, const ClanCard& ClanCard) {
    os << "���俨Ƭ :\n\t���� : " << ClanCard.getNumber() << "\n\t��ɫ : " << ClanCard.getColor();
    return os;
}
void Show_Vector_ClanCard(vector<ClanCard*> v){
    for (auto card: v) {
        cout << " " << card->getNumber()<< " "<< card->getColor();
    }

}					