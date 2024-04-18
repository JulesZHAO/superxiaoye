#pragma once
#include "Player.h"
#include "Card.h"
#include "TecCard.h"
#include "Stone.h"

class Table {
public:
	Player* player1 = nullptr;
	Player* player2 = nullptr;
	Stone** m_stones  = nullptr;	
private:	
	int m_current_player;
	
	vector<Card*> discards;
public:
	Table(size_t nb, bool is_ai1, bool is_ai2) : m_current_player(1), m_stones ( new Stone* [9] )
 {
		player1 = new Player(nb, is_ai1);
		player2 = new Player(nb, is_ai2);
		for (int i = 0; i < 9; ++i) 
			m_stones[i] = new Stone (i + 1);
	}
	Table(const Table&) = delete;
	Table& operator=(const Table&) = delete;

	Player* getPlayer1() const { return player1; }
	Player* getPlayer2() const { return player2; }
	int getCurrentPlayer() const { return m_current_player; }
	vector<Card*> getDiscards() const { return discards; }
	Stone* getStones(int i) const { return m_stones[i]; }
	void setCurrentPlayer(int current_player) {
		m_current_player = current_player;
	}
	void put(Stone stone, ClanCard* card);

	void showPlayerHand(int player);
	void showHandBack(int player);
	void showStones(int player);
	void showTable(int someone);															
};