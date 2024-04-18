#include "ClanCard.h"
#include<ostream>

 using namespace std;
ostream& operator<<(ostream& os, const ClanCard& ClanCard) {
    os << "部落卡片 :\n\t力量 : " << ClanCard.getNumber() << "\n\t颜色 : " << ClanCard.getColor();
    return os;
}
void Show_Vector_ClanCard(vector<ClanCard*> v){
    for (auto card: v) {
        cout << " " << card->getNumber()<< " "<< card->getColor();
    }

}					