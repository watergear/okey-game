#include "best_solution.h"

#include <iostream>
using namespace std;

namespace OKey {

void dump(const Deck &cards)
{
	cout<<"{";
	bool first = true;
	for ( const auto &card : cards )
	{
		cout<<(first?"":","); first = false;
		cout<<"{"<<card.first<<","<<card.second<<"}";
	}
	cout<<"}";
}

void dump(const Play &play)
{
	dump(Play2Deck(play));
}

void dump(const Solution &solution)
{
	bool first = true;
	for ( const auto &play : solution.plays )
	{
		cout<<(first?"":","); first = false;
		dump(play);
	}
	cout<<", "<<solution.okey<<" okey"<<endl;
}

void dump(const vector<Deck> &decks)
{
	cout<<"{";
	bool first = true;
	for ( const auto &deck : decks )
	{
		cout<<(first?"":","); first = false;
		dump(deck);
	}
	cout<<"}";
	cout<<endl;
}


int OKeySolver::MakeBestPlay(Play &play, int okey)
{
	int score = Score(play);
	if ( play.count > 1 )
	{
		if ( play.interval ) // Sequence
		{
			int add_to_max = min(okey, MAX_N - play.max);
			int add_to_min = min(okey - add_to_max, play.min - 1);
			play.min -= add_to_min;
			play.max += add_to_max;
			okey = add_to_min + add_to_max;
		}
		else // Triplet
		{
		}
		play.count += okey;
		play.suits[0] += okey;
	}
	else
	if ( play.count == 1 && okey >= 2 )
	{
		int add_to_max = min(okey, MAX_N - play.max);
		int add_to_min = min(okey - add_to_max, play.min - 1);
		if (add_to_max > add_to_min) // to Sequence
		{
			play.min -= add_to_min;
			play.max += add_to_max;
			okey = add_to_min + add_to_max;
		}
		else // to Triplet
		{
			play.interval = 0;
		}
		play.count += okey;
		play.suits[0] += okey;
	}
	return Score(play) - score;
}
void OKeySolver::Evaluate(const Solution &solution)
{
	// dump(solution);

	if ( 2 <= solution.okey )
	{
		// 2 okey
		{
			int best_i = -1;
			int best_score_up = 0;
			Play best_play;
			for ( size_t i = 0; i < solution.plays.size(); ++i )
			{
				Play play = solution.plays[i];
				int score_up = MakeBestPlay(play, 2);
				if ( score_up > best_score_up )
				{
					best_i = i;
					best_score_up = score_up;
					best_play = play;
				}
			}
			Solution okey_solution(solution);
			if (best_score_up > 0)
			{
				okey_solution.plays[best_i] = best_play;
				okey_solution.okey -= 2;
			}
			AddBest(okey_solution);
		}

		// 1 okey and 1 okey
		{
			int best_i1 = -1, best_i2 = -1;
			int best_score_up1 = 0, best_score_up2 = 0;
			Play best_play1, best_play2;
			for ( size_t i = 0; i < solution.plays.size(); ++i )
			{
				Play play = solution.plays[i];
				int score_up = MakeBestPlay(play, 1);
				if ( score_up > best_score_up1 )
				{
					best_i2 = best_i1;
					best_score_up2 = best_score_up1;
					best_play2 = best_play1;
					best_i1 = i;
					best_score_up1 = score_up;
					best_play1 = play;
				}
				else
				if ( score_up > best_score_up2 )
				{
					best_i2 = i;
					best_score_up2 = score_up;
					best_play2 = play;
				}
			}

			Solution okey_solution(solution);
			if (best_score_up1 > 0)
			{
				okey_solution.plays[best_i1] = best_play1;
				okey_solution.okey -= 1;
			}
			if (best_score_up2 > 0)
			{
				okey_solution.plays[best_i2] = best_play2;
				okey_solution.okey -= 1;
			}
			AddBest(okey_solution);
		}
	}
	else
	if ( 1 == solution.okey )
	{
		// 1 okey
		{
			int best_i1 = -1;
			int best_score_up1 = 0;
			Play best_play1;
			for ( size_t i = 0; i < solution.plays.size(); ++i )
			{
				Play play = solution.plays[i];
				int score_up = MakeBestPlay(play, 1);
				if ( score_up > best_score_up1 )
				{
					best_i1 = i;
					best_score_up1 = score_up;
					best_play1 = play;
				}
			}

			Solution okey_solution(solution);
			if (best_score_up1 > 0)
			{
				okey_solution.plays[best_i1] = best_play1;
				okey_solution.okey -= 1;
			}
			AddBest(okey_solution);
		}
	}
	else
	{
		AddBest(solution);
	}
}

int OKeySolver::Score(const Play& play)
{
	int score = 0;
	if (play.count >= 3)
	{
		if ( play.interval )
			score = (play.min + play.max) * play.count / 2;
		else
			score = play.max * play.count;
	}
	return score;
}
int OKeySolver::Score(const Solution &solution)
{
	int score = 0;
	for ( const auto &play : solution.plays )
		score += Score(play);
	return score;
}

bool OKeySolver::AddBest(const Solution &solution)
{
	int score = Score(solution);
	if ( score > best_score )
	{
		best_score = score;
		best_solution = solution;
		return true;
	}
	return false;	
}

int OKeySolver::CheckPlay(const Play &play, const Card &card)
{
	if ( play.count > 1 )
	{
		if ( play.interval ) // Sequence
		{
			if ( play.suit == card.second )
				return card.first - play.max - 1;
		}
		else // Triplet
		{
			if ( play.max == card.first )
				return 0;
		}
		return -1;
	}
	else
	if ( 1 == play.count )
	{
		if ( play.max == card.first ) // Triplet
			return 0;
		if ( play.suit == card.second ) // Sequence
			return card.first - play.max - 1;
		return -1;
	}
	return 0;
}
void OKeySolver::AddPlay(Play &play, const Card &card)
{
	if ( play.count <= 0 )
	{
		play.count = 1;
		play.min = play.max = card.first;
		play.interval = 1;
		play.suit = card.second;
		++play.suits[play.suit];
	}
	else
	{
		if ( play.max == card.first ) // Triplet
		{
			assert(1 == play.count || !play.interval);
			play.interval = 0;
		}
		else  // Sequence
		{
			assert(play.max+1 == card.first);
			assert(0 == card.second || play.suit == card.second);
			assert(1 == play.count || play.interval);
			++play.max;
		}
		++play.suits[card.second];
		++play.count;
	}
}
void OKeySolver::RemovePlay(Play &play, const Card &card)
{
	assert(play.count > 0);
	assert(play.max == card.first);
	if ( play.interval ) // Sequence
	{
		assert(0 == card.second || play.suit == card.second);
		--play.max;
	}
	else // Triplet
	{
		if ( 2 == play.count )
			play.interval = 1;
	}
	--play.suits[card.second];
	--play.count;
}

// it is not easy, but it is able to proof for this method.
/*
	(a,b,c,...),... => any (a,b),...,(...,c,...),... is waste

		case: 1,2,3
		proof:
		(1,2,3,...),...,(),... is better than (1,2),...,(3),...

		case: 1,2,2,3,4
		proof:
		(1,2,3,4,...),...,(2),... is better than (1,2),...,(2,3,4,...),...

		case: 1,2,2,3,4,5
		proof:
		(1,2,3,4,5,...),...,(2),... is better than (1,2),...,(2,3,4,5,...),...

		case: 1,2,3,3
		proof:
		(1,2,3,...),...,(3),... is better than (1,2),...,(3,3),...

		case: 1,2,3,3,3
		proof:
		(1,2,3,...),...,(3,3),... is bad than (1,2),...,(3,3,3),...
		(1),(2),...,(3,3,3),... is same as (1,2),...,(3,3,3),...

	(a,a,a,...),... => any (a,a),...,(...,a,...),... is waste

		case: 1,1,1
		proof:
		(1,1,1,...),...,(),... is better than (1,1),...,(1),...

		case: 1,1,1,1
		proof:
		(1,1,1,1,...),...,(),... is better than (1,1),...,(1,1,...),...

		case: 1,1,1,1,1
		proof:
		(1,1,1,1,1,...),...,(),... is better than (1,1),...,(1,1,1,...),...

		case: 1,1,1,2
		proof:
		(1,1,1),...,(2),... is better than (1,1),...,(1,2),...

		case: 1,1,1,2,3
		proof:
		(1,1,1),...,(2,3),... is bad than (1,1),...,(1,2,3),...
		(1),(1),...,(1,2,3),... is same as (1,1),...,(1,2,3),...

		case: 1,1,1,2,3,4
		proof:
		(1,1,1),...,(2,3,4),... is better than (1,1),...,(1,2,3,4),...
*/
bool OKeySolver::IsNextWasteOnSinglePlay(const Play &play, const Card& card, int okey_cost)
{
	if ( 0 == okey_cost && 2 == play.count ) // play.count can't be less than 2 and more than 2.
	{
		if ( play.interval ) // Sequence
		{
			/*
				play can be any sequence.
			*/
			assert(play.max + 1 == card.first && play.suit == card.second);
			return true;
		}
		else // Triplet
		{
			assert(play.max == card.first);
			/*
				play can't be any triplet.

				the following examples need to cared.
					case: {{1,3},{1,3},{1,3},{2,3},{3,3}} with 0 okey
					the best solution is {(1,3),(2,3),(3,3)},{(1,3)},{(1,3)}, score is 6.

					case: {{1,3},{1,3},{1,3},{2,3},{3,3}} with 1 okey
					the best solution is {(1,3),(1,3),(1,3)},{(2,3),(3,3),okey}, score is 12.

					case: {{11,3},{11,3},{11,3},{12,3},{13,3}} with 1 okey
					the best solution is {(11,3),(11,3),(11,3)},{okey,(12,3),(13,3)}, score is 69.

					case: {{1,2},{1,3},{1,3},{1,3},{2,3},{3,3}} with 0 okey
					the best solution is {(1,2),(1,3),(1,3)},{(1,3),(2,3),(3,3)}, score is 9.

				the following examples need to not cared.
					case: {{1,1},{1,2},{1,3},{1,4},{2,3},{3,3}} with 0 okey
					the best solution is {(1,1),(1,2),(1,4)},{(1,3),(2,3),(3,3)}, score is 9.

					case: {{1,2},{1,2},{1,2},{1,4},{2,2},{3,2}} with 0 okey
					the best solution is {(1,2),(1,2),(1,4)},{(1,2),(2,2),(3,2)}, score is 9.
			*/
			if ( card_suit_upper_bounds[card.first] == card.second ) // no more other else will be triplet
				return true;
		}
	}
	return false;
}

// it is not easy, but it is able to proof for this method.
/*
	(a,b),(c,d),...,(...,e,...),... is waste
	
		case: 1,2,3,3,3
		proof:
		(1,2,3),...,(3),... is better than (1,2),...,(3),...,(3),...

		case: 1,2,3,4,4
		proof:
		(1,2,3,4),...,(4),... is better than (1,2),...,(3,4),...,(4),...
		
	(a),(a),...,(...,b,...),... is waste
		
		case: 1,1,2,2,2
		proof:
		(1,1),...,(2,2,2),... is same as (1),(1),...,(2,2,2),...
		
		case: 1,1,1,2,2,2
		proof:
		(1,1,1),...,(2,2,2),... is better than (1,1),(1),...,(2,2,2),...
		(1,1,1),...,(2,2,2),... is better than (1),(1,1),...,(2,2,2),...
		(1,1,1),...,(2,2,2),... is better than (1),(1),(1),...,(2,2,2),...
		
		case: 1,1,2,3,4
		proof:
		(1,1),...,(2,3,4),... is same as (1),(1),...,(2,3,4),...
		(1,2,3,4),(1),...,(),... is better than (1),(1),...,(2,3,4),...
		
		case: 1,1,1,2,3,4
		proof:
		(1,1,1),...,(2,3,4),... is better than (1,1),(1),...,(2,3,4),...
		(1,1,1),...,(2,3,4),... is better than (1),(1,1),...,(2,3,4),...
		(1,1,1),...,(2,3,4),... is better than (1),(1),(1),...,(2,3,4),...
*/
bool OKeySolver::IsNextWasteOnMultiplePlays(const Play &play, const Card& card, WasteMark &mark)
{
	#define MUST_TO_BE_SEQ(__play__, __card__) ( ( __play__.count > 1 && __play__.interval ) || \
		( 1 == __play__.count && __play__.max == __card__.first && card_suit_upper_bounds[card.first] == card.second ) )
	#define MUST_TO_BE_TRI(__play__, __card__) ( !__play__.interval || \
		( 1 == __play__.count && __play__.max < __card__.first && __play__.suit == __card__.second ) )
	
	if ( MUST_TO_BE_SEQ(play, card) )
	{
		/*
			play can't be any sequence.

			the following examples need to cared.
				case: {{1,1},{2,1},{3,1},{4,1},{5,1},{6,1},{7,1},{8,1},{9,1},{10,1},{11,1},{12,1},{13,1}} with 0 okey
				the best solution is {(1,1),(2,1),(3,1),(4,1),(5,1),(6,1),(7,1),(8,1),(9,1),(10,1),(11,1),(12,1),(13,1)}, score is 91.

				case: {{9,1},{10,1},{11,1},{12,1},{13,1},{11,3},{12,3},{13,3}} with 0 okey
				the best solution is {(9,1),(10,1),(11,1),(12,1),(13,1)},{(11,3),(12,3),(13,3)}, score is 91.

			the following examples need to not cared.
				case: {{9,1},{10,1},{11,1},{12,1},{13,1},{11,3},{12,3},{13,3}} with 1 okey
				the best solution is {(9,1),(10,1),(11,1)},{(11,3),(12,3),(13,3)},{okey,(12,1),(13,1)}, score is 102.

				case: {{9,1},{10,1},{11,1},{12,1},{13,1},{11,3},{12,3},{13,3}} with 2 okey
				the best solution is {(9,1),(10,1),(11,1),(12,1)},{(11,3),(12,3),(13,3)},{okey,okey,(13,1)}, score is 117.

				case: {{1,1},{2,1},{3,1},{4,1},{5,1},{6,1},{7,1},{8,1},{9,1},{10,1},{11,1},{12,1}} with 2 okey
				the best solution is {(1,1),(2,1),(3,1),(4,1),(5,1),(6,1),(7,1),(8,1),(9,1),(10,1),(11,1)},{okey,okey,(12,1)}, score is 102.

				case: {{7,1},{8,1},{9,1},{10,1},{11,1},{12,1},{13,1},{7,1},{8,1},{9,1},{10,1},{11,1},{12,1},{13,1}} with 1 okey
				the best solution is {(7,1),(8,1),(9,1),(10,1),(11,1),(12,1)},{(7,1),(8,1),(9,1),(10,1),(11,1),(12,1)},{okey,(13,1),(13,1)}, score is 153.

				case: {{7,1},{8,1},{9,1},{10,1},{11,1},{12,1},{13,1},{7,1},{8,1},{9,1},{10,1},{11,1},{12,1},{13,1}} with 2 okey
				the best solution is {(7,1),(8,1),(9,1),(10,1),(11,1),(12,1),(13,1)},{(7,1),(8,1),(9,1),(10,1),(11,1),(12,1)},{okey,okey,(13,1)}, score is 166.

				case: {{7,1},{8,1},{9,1},{10,1},{11,1},{12,1},{13,1},{7,3},{8,3},{9,3},{10,3},{11,3},{12,3},{13,3}} with 1 okey
				the best solution is {(7,1),(8,1),(9,1),(10,1),(11,1),(12,1)},{(7,3),(8,3),(9,3),(10,3),(11,3),(12,3)},{okey,(13,1),(13,3)}, score is 153.

				case: {{7,1},{8,1},{9,1},{10,1},{11,1},{12,1},{13,1},{7,3},{8,3},{9,3},{10,3},{11,3},{12,3},{13,3}} with 2 okey
				the best solution is {(7,1),(8,1),(9,1),(10,1),(11,1),(12,1),(13,1)},{(7,3),(8,3),(9,3),(10,3),(11,3),(12,3)},{okey,okey,(13,3)}, score is 166.
		*/
		if ( 1 < play.min && mark.sequence_upper_bounds[CARD_OFFSET(play.min-1, play.suit)] ) // combinable sequence
		{
			// seems play.min can be any number (just a guess), and none of case is able to show it is incorrect.
			if ( play.min <= MAX_N - 2 ) // make sure play.count >= 3 when play.max is enlarged to MAX_N
				return true;
		}
		mark.sequence_upper_bounds[CARD_OFFSET(play.max, play.suit)] = true;
	}
	else
	if ( MUST_TO_BE_TRI(play, card) )
	{
		/*
			play can't be any triplet.

			the following examples need to cared.
				case: {{9,1},{9,1},{11,1},{10,1},{10,2},{10,3}} with 1 okey
				the best solution is {(9,1),(10,1),(11,1)},{(9,1)},{okey,(10,2),(10,3)}, score is 60.

				case: {{9,2},{9,2},{11,2},{10,1},{10,2},{10,3}} with 1 okey
				the best solution is {(9,2),(10,2),(11,2)},{(9,2)},{okey,(10,1),(10,3)}, score is 60.

				case: {{9,2},{9,2},{9,2},{11,2},{10,1},{10,2},{10,3}} with 1 okey
				the best solution is {(9,2),(9,2),(9,2)},{okey,(10,1),(10,2),(10,3)},{(11,2)}, score is 67.

				case: {{9,2},{9,2},{9,2},{9,2},{11,2},{10,1},{10,2},{10,3}} with 1 okey
				the best solution is {(9,2),(9,2),(9,2)},{(9,2),(10,2),(11,2)},{okey,(10,1),(10,3)}, score is 87.

				case: {{9,2},{9,2},{9,2},{9,2},{9,2},{11,2},{10,1},{10,2},{10,3}} with 1 okey
				the best solution is {(9,2),(9,2),(9,2),(9,2)},{(9,2),(10,2),(11,2)},{okey,(10,1),(10,3)}, score is 96.

				case: {{10,1},{10,1},{12,1},{12,1},{13,1},{11,1}} with 2 okey
				the best solution is {(10,1),(11,1),(12,1),(13,1)},{(10,1),okey,(12,1),okey}, score is 92.

				case: {{10,1},{10,2},{12,1},{12,2},{13,2},{11,1}} with 1 okey
				the best solution is {(10,1),(11,1),(12,1)},{(10,2),okey,(12,2),(13,2)}, score is 79.

				case: {{10,1},{10,2},{10,1},{10,2},{12,1},{12,2},{13,2},{11,1}} with 1 okey
				the best solution is {(10,1),(10,2),(10,2)},{(10,1),(11,1),(12,1)},{okey,(12,2),(13,2)}, score is 99.

				case: {{10,1},{10,2},{10,2},{10,2},{11,1},{12,1}} with 0 okey
				the best solution is {(10,1),(11,1),(12,1)},{(10,2),(10,2),(10,2)}, score is 63.

				case: {{10,2},{10,3},{10,3},{10,3},{11,2},{12,2},{11,2}} with 0 okey
				the best solution is {(10,2),(11,2),(12,2)},{(10,3),(10,3),(10,3)},{(11,2)}, score is 63.

			the following examples need to not cared.
				case: {{10,1},{10,1},{12,1},{12,1},{13,1},{11,2}} with 2 okey
				the best solution is {(10,1),okey,(12,1),(13,1)},{(10,1),okey,(12,1)},{(11,2)}, score is 79.

				case: {{10,2},{10,3},{10,3},{10,3},{11,2},{12,2},{11,1}} with 0 okey
				the best solution is {(10,2),(11,2),(12,2)},{(10,3),(10,3),(10,3)},{(11,1)}, score is 63.

				case: {{10,2},{10,3},{10,3},{10,3},{11,3},{12,3},{11,2}} with 0 okey
				the best solution is {(10,2),(10,3),(10,3)},{(10,3),(11,3),(12,3)},{(11,2)}, score is 63.

				case: {{9,2},{9,4},{11,4},{10,1},{10,2},{10,3}} with 1 okey
				the best solution is {(9,2)},{(9,4),okey,(11,4)},{(10,1),(10,2),(10,3)}, score is 60.
		*/
		if ( mark.triplets[play.max] ) // combinable triplet
			return true;
		mark.triplets[play.max] = true;
	}

	return false;
}

void OKeySolver::Search()
{
	if ( card_index >= (int)hand_cards.size() )
	{
		Evaluate(solution);
		return;
	}

	const Card &card = hand_cards[card_index];
	int card_offset = CARD_OFFSET(card);
	int last_play_index = last_play_indexes[card_offset];
	WasteMark waste_mark = {{0},{0}};
	bool is_next_waste = false;
	if ( 0 < last_play_index )
		is_next_waste = IsNextWasteOnMultiplePlays(solution.plays[last_play_index-1], card, waste_mark);
	++card_index;
	int solution_size = solution.plays.size();
	for ( int play_index = last_play_index; play_index < solution_size; ++play_index )
	{
		if ( !(0 < play_index && solution.plays[play_index-1] == solution.plays[play_index]) ) // not same plays
		{
			bool okey_check_pass = true;
			int okey = CheckPlay(solution.plays[play_index], card);
			if ( okey < 0 || solution.okey < okey )
			{
				okey_check_pass = false;
			}
			else
			if ( 0 < okey )
			{
				for ( int okey_i = okey; okey_i >= 1; --okey_i )
				{
					Card okey_card = {card.first-okey_i, card.second};
					if ( play_index < last_play_indexes[CARD_OFFSET(okey_card)] )
					{
						okey_check_pass = false;
						break;
					}
				}
			}

			if ( okey_check_pass )
			{
				for ( int okey_i = okey; okey_i >= 1; --okey_i )
					AddPlay(solution.plays[play_index], Card{card.first-okey_i, 0});
				solution.okey -= okey;
				AddPlay(solution.plays[play_index], card);
				last_play_indexes[card_offset] = play_index;
				Search();
				RemovePlay(solution.plays[play_index], card);
				for ( int okey_i = 1; okey_i <= okey; ++okey_i )
					RemovePlay(solution.plays[play_index], Card{card.first-okey_i, 0});
				solution.okey += okey;

				is_next_waste = IsNextWasteOnSinglePlay(solution.plays[play_index], card, okey);
				if ( is_next_waste )
					break;
			}
		}

		is_next_waste = IsNextWasteOnMultiplePlays(solution.plays[play_index], card, waste_mark);
		if ( is_next_waste )
			break;
	}
	if ( !is_next_waste )
	{
		Play play_new = {0,0,0,0,0,{0}};
		AddPlay(play_new, card);
		solution.plays.push_back(play_new);
		last_play_indexes[card_offset] = solution_size;
		Search();
		solution.plays.pop_back();
	}
	--card_index;
	last_play_indexes[card_offset] = last_play_index;
}

Solution OKeySolver::Solve(const Deck &cards, int okey)
{
	hand_cards = cards;
	sort(hand_cards.begin(), hand_cards.end());
	card_suit_upper_bounds.resize(MAX_N+1, 0);
	for ( const auto &card : hand_cards )
		card_suit_upper_bounds[card.first] = max(card_suit_upper_bounds[card.first], card.second);
	last_play_indexes.resize(MAX_LEN, 0);
	solution.plays.clear();
	solution.okey = okey;
	best_solution.plays.clear();
	best_solution.okey = 0;
	best_score = 0;
	card_index = 0;
	Search();
	return best_solution;
}

Deck Play2Deck(const Play &play)
{
	Deck deck;
	Play _play = play;
	if ( !_play.interval )
	{
		_play.suit = 0;
		while ( !_play.suits[_play.suit] )
			++_play.suit;
	}
	while ( _play.count-- )
	{
		deck.push_back({_play.min, _play.suit});
		_play.min += _play.interval;
		if ( !_play.interval )
		{
			--_play.suits[_play.suit];
			while ( !_play.suits[_play.suit] )
				++_play.suit;
		}
	}
	return deck;
}

vector<Deck> Solution2Decks(const Solution &solution, const Deck &cards)
{
	vector<Deck> decks;
	vector<int> card_counts(MAX_LEN, 0);
	for ( const auto &card : cards )
		++card_counts[CARD_OFFSET(card)];
	for ( const Play& play : solution.plays )
	{
		Deck deck = Play2Deck(play);
		for ( auto &card : deck )
		{
			if ( card.second )
			{
				int card_offset = CARD_OFFSET(card);
				if ( card_counts[card_offset] )
					--card_counts[card_offset];
				else
					card.second = 0;
			}
		}
		decks.push_back(move(deck));
	}
	return decks;
}

};