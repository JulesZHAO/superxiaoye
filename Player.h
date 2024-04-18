#pragma once
#include "Hand.h"

class Player {
public:
	Player(const Player&) = default;
	Player& operator=(const Player&) = delete;
	Player(size_t nb, bool is_ai) : m_is_ai(is_ai) { m_hand = new Hand(nb); }

	Hand* getHand() { return m_hand; }
	bool getIsAI() { return m_is_ai; }
	
private:
	Hand* m_hand = nullptr;
	bool m_is_ai;
	bool Joker;
};