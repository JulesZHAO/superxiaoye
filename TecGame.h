#pragma once
#include"Card.h"
#include"SetException.h"
#include"CunningCard.h"
#include"BattleCard.h"
#include"CardEliteGroup.h"
#include <cstddef>
#include "SetCard.h"

class TecGame {
private:
	const Card* cards[10];

	struct Processor {
		TecGame* game = nullptr;
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

	TecGame();
	~TecGame();
	TecGame(const TecGame&) = delete;
	TecGame& operator=(const TecGame&) = delete;

	static TecGame& getTecGame();
	static void freeTecGame();
	size_t getNbCards() const { return 54; }

	class Iterator {
	private:
		size_t i = 0;
	public:
		friend class TecGame;
		Iterator() = default;
		~Iterator() = default;

		bool isDone() const { return i == TecGame::getTecGame().getNbCards(); }
		void next() {
			if (isDone())
				throw SetException("it is over");
			i++;
		}
		const Card& currentItem() const {
			if (isDone()) throw SetException("it is over");
			return TecGame::getTecGame().getCard(i);
		}
	};
	Iterator getIterator() const {
		return Iterator();
	}
};
