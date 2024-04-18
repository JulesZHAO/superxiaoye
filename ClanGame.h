#pragma once
#include"Card.h"
#include"SetException.h"
#include <cstddef>
#include "SetCard.h"

class ClanGame{
private:
	const Card* cards[54];

	struct Processor {
		ClanGame* game = nullptr;
		Processor();
		~Processor() { delete game; }
	};
	static Processor processor;
	const Card& getCard(size_t i) const {
		if (i >= 81) throw SetException("not exist");
		return*cards[i];
	}

public:
	friend class Controller;

	ClanGame();
	~ClanGame();
	ClanGame(const ClanGame&) = delete;
	ClanGame& operator=(const ClanGame&) = delete;

	static ClanGame& getClanGame();
	static void freeClanGame();
	size_t getNbCards() const { return 54; }

	class Iterator {
	private:
		size_t i = 0;
	public:
		friend class ClanGame;
		Iterator() = default;
		~Iterator() = default;

		bool isDone() const { return i == ClanGame::getClanGame().getNbCards(); }
		void next() {
			if (isDone())
				throw SetException("it is over");
			i++;
		}
		const Card& currentItem() const {
			if (isDone()) throw SetException("it is over");
			return ClanGame::getClanGame().getCard(i);
		}
	};
	Iterator getIterator() const {
		return Iterator();
	}
};
