#pragma once

#include <vector>

namespace OKey {

static const int MAX_N = 13;
static const int MAX_M = 4;
static const int MAX_LEN = MAX_N*MAX_M;

typedef std::pair<int,int> Card;
typedef std::vector<Card> Cards;
typedef Cards Deck;
struct Play
{
	int count;
	int min;
	int max;
	int interval;
	int suit;
	int suits[MAX_M+1];

	inline bool operator == (const Play &other) const
	{
		if ( this->count != other.count )
			return false;
		if ( this->count <= 0 )
			return true;

		if ( this->interval != other.interval )
			return false;
		if ( this->min != other.min )
			return false;
		if ( this->max != other.max )
			return false;

		if ( this->interval )
			return (this->suit == other.suit);

		return true;
	};
};
struct Solution
{
	std::vector<Play> plays;
	int okey;
};

inline int CARD_OFFSET(const Card &card) { return (card.first-1)*MAX_M + (card.second-1); }
inline int CARD_OFFSET(int first, int second) { return (first-1)*MAX_M + (second-1); }

class OKeySolver
{
public:
	Solution Solve(const Deck &cards, int okey = 2);
	int Score(const Solution &solution);
	int Score(const Play& play);

protected:
	void Search();

	int CheckPlay(const Play &play, const Card &card);
	void AddPlay(Play &play, const Card &card);
	void RemovePlay(Play &play, const Card &card);

	void Evaluate(const Solution &solution);
	bool AddBest(const Solution &solution);
	int MakeBestPlay(Play &play, int okey);

	struct WasteMark
	{
		bool triplets[MAX_N+1];
		bool sequence_upper_bounds[MAX_LEN];
	};
	bool IsNextWasteOnSinglePlay(const Play &play, const Card& card, int okey_cost);
	bool IsNextWasteOnMultiplePlays(const Play &play, const Card& card, WasteMark &mark);

private:
	Deck hand_cards;
	std::vector<int> card_suit_upper_bounds;

	int card_index;

	Solution solution;
	std::vector<int> last_play_indexes;

	Solution best_solution;
	int best_score;
};

Deck Play2Deck(const Play &play);
std::vector<Deck> Solution2Decks(const Solution &solution, const Deck &cards);

void dump(const Deck &cards);
void dump(const Play &play);
void dump(const Solution &solution);
void dump(const std::vector<Deck> &decks);

};