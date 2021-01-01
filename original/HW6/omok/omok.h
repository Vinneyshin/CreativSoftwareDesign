#ifndef _OMOK_H_
#define _OMOK_H_

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Omok {
	public:
		Omok();

		bool Put(int x, int y);
		bool IsOmok(bool* is_winner_black) const;
		bool IsBlacksTurn() const { return blacks_turn_; }

		friend std::ostream& operator<<(std::ostream& os, const Omok& omok);

	private:

		vector<string> inputs;
		int width_, height_;
		int recentX_, recentY_;
		bool blacks_turn_;  // 흑돌 차례면 true.
		int stage_[19][19];
};

std::ostream& operator<<(std::ostream& os, const Omok& omok);

#endif
