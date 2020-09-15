#include "best_solution.h"
#include "gtest/gtest.h"

#include "sys/time.h"

#include <algorithm>

using namespace std;
using namespace OKey;

TEST(OKeyGame, BaseUpperSequenceTwoOKey)
{
	Deck cards =
		{{5,1},{6,1}};
	int okey = 2;
	vector<Deck> play_decks_to_check =
		{{{5,1},{6,1},{7,0},{8,0}}};
	int score = 26;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, BaseUpperSequenceTwoOKey_2)
{
	Deck cards =
		{{1,1},{2,1},{3,1},{4,1}};
	int okey = 2;
	vector<Deck> play_decks_to_check =
		{{{1,1},{2,1},{3,1},{4,1},{5,0},{6,0}}};
	int score = 21;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, BaseUpperLongSequenceTwoOKey)
{
	Deck cards =
		{{6,1},{7,1},{8,1},{9,1},{9,1},{10,1},{11,1}};
	int okey = 2;
	vector<Deck> play_decks_to_check =
		{{{6,1},{7,1},{8,1},{9,1}},{{9,1},{10,1},{11,1},{12,0},{13,0}}};
	int score = 85;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, BaseUpperLongSequenceTwoOKey_2)
{
	Deck cards =
		{{9,1},{10,1},{11,1},{11,1},{12,1},{13,1}};
	int okey = 2;
	vector<Deck> play_decks_to_check =
		{{{9,1},{10,1},{11,1},{12,1},{13,1}},{{11,1},{12,0},{13,0}}};
	int score = 91;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, BaseUpperLongSequenceOneOKey)
{
	Deck cards =
		{{7,1},{8,1},{9,1},{10,1},{10,1},{11,1},{12,1}};
	int okey = 1;
	vector<Deck> play_decks_to_check =
		{{{7,1},{8,1},{9,1},{10,1}},{{10,1},{11,1},{12,1},{13,0}}};
	int score = 80;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, BaseUpperLongSequenceOneOKey_2)
{
	Deck cards =
		{{9,1},{10,1},{11,1},{11,1},{12,1}};
	int okey = 1;
	vector<Deck> play_decks_to_check =
		{{{9,1},{10,1},{11,1}},{{11,1},{12,1},{13,0}}};
	int score = 66;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, BaseUpperLongSequenceOneOKey_3)
{
	Deck cards =
		{{9,1},{10,1},{11,1},{11,1},{12,1},{13,1}};
	int okey = 1;
	vector<Deck> play_decks_to_check =
		{{{9,1},{10,1},{11,1},{12,1}},{{11,1},{12,0},{13,1}}};
	int score = 78;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, BaseUpperTwoSequenceTwoOKey)
{
	Deck cards =
		{{2,1},{3,1},{2,2},{3,2}};
	int okey = 2;
	vector<Deck> play_decks_to_check =
		{{{2,1},{3,1},{4,0}},{{2,2},{3,2},{4,0}}};
	int score = 18;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, BaseUpperTwoSequenceTwoOKey_2)
{
	Deck cards =
		{{11,1},{12,1},{11,2},{12,2}};
	int okey = 2;
	vector<Deck> play_decks_to_check =
		{{{11,1},{12,1},{13,0}},{{11,2},{12,2},{13,0}}};
	int score = 72;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, BaseUpperLongTwoSequenceTwoOKey)
{
	Deck cards =
		{{7,1},{8,1},{9,1},{10,1},{10,1},{11,1},{12,1}};
	int okey = 2;
	vector<Deck> play_decks_to_check =
		{{{7,1},{8,1},{9,1},{10,1},{11,1}},{{10,1},{11,0},{12,1},{13,0}}};
	int score = 91;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, BaseUpperLongTwoSequenceTwoOKey_2)
{
	Deck cards =
		{{9,1},{10,1},{11,1},{11,1},{12,1}};
	int okey = 2;
	vector<Deck> play_decks_to_check =
		{{{9,1},{10,1},{11,1},{12,1}},{{11,1},{12,0},{13,0}}};
	int score = 78;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, BaseUpperTripletTwoOKey)
{
	Deck cards =
		{{9,1},{10,1},{11,1},{12,1}};
	int okey = 2;
	vector<Deck> play_decks_to_check =
		{{{9,1},{10,1},{11,1}},{{12,0},{12,0},{12,1}}};
	int score = 66;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, BaseUpperTripletTwoOKey_2)
{
	Deck cards =
		{{10,1},{11,1},{12,1},{13,1}};
	int okey = 2;
	vector<Deck> play_decks_to_check =
		{{{10,1},{11,1},{12,1}},{{13,0},{13,0},{13,1}}};
	int score = 72;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, BaseUpperTripletTwoOKey_3)
{
	Deck cards =
		{{4,1},{5,1},{6,1},{11,1},{11,2}};
	int okey = 2;
	vector<Deck> play_decks_to_check =
		{{{4,1},{5,1},{6,1}},{{11,0},{11,0},{11,1},{11,2}}};
	int score = 59;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, BaseMiddleTripletTwoOKey)
{
	Deck cards =
		{{11,1},{12,1},{12,2},{13,1}};
	int okey = 2;
	vector<Deck> play_decks_to_check =
		{{{11,1},{12,1},{13,1}},{{12,0},{12,0},{12,2}}};
	int score = 72;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, BaseTwoTripletTwoOKey)
{
	Deck cards =
		{{12,1},{13,1},{12,2},{13,2}};
	int okey = 2;
	vector<Deck> play_decks_to_check =
		{{{12,0},{12,1},{12,2}},{{13,0},{13,1},{13,2}}};
	int score = 75;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, BaseLowerSequenceTwoOKey)
{
	Deck cards =
		{{11,1},{12,1},{13,1}};
	int okey = 2;
	vector<Deck> play_decks_to_check =
		{{{9,0},{10,0},{11,1},{12,1},{13,1}}};
	int score = 55;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, BaseLowerSequenceOneOKey)
{
	Deck cards =
		{{11,1},{12,1},{13,1}};
	int okey = 1;
	vector<Deck> play_decks_to_check =
		{{{10,0},{11,1},{12,1},{13,1}}};
	int score = 46;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, BaseLowerShortSequenceTwoOKey)
{
	Deck cards =
		{{12,1},{13,1}};
	int okey = 2;
	vector<Deck> play_decks_to_check =
		{{{10,0},{11,0},{12,1},{13,1}}};
	int score = 46;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, BaseLowerShortSequenceOneOKey)
{
	Deck cards =
		{{12,1},{13,1}};
	int okey = 1;
	vector<Deck> play_decks_to_check =
		{{{11,0},{12,1},{13,1}}};
	int score = 36;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, BaseLowerLongSequenceOneOKey)
{
	Deck cards =
		{{10,1},{11,1},{12,1},{12,1},{13,1}};
	int okey = 1;
	vector<Deck> play_decks_to_check =
		{{{10,1},{11,1},{12,1}},{{11,0},{12,1},{13,1}}};
	int score = 69;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, BaseLowerUpperSequenceTwoOKey)
{
	Deck cards =
		{{11,1},{12,1}};
	int okey = 2;
	vector<Deck> play_decks_to_check =
		{{{10,0},{11,1},{12,1},{13,0}}};
	int score = 46;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, BaseLowerUpperSequenceTwoOKey_2)
{
	Deck cards =
		{{10,1},{11,1},{12,1}};
	int okey = 2;
	vector<Deck> play_decks_to_check =
		{{{9,0},{10,1},{11,1},{12,1},{13,0}}};
	int score = 55;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, BaseLowerUpperSequenceTwoOKey_3)
{
	Deck cards =
		{{4,1},{5,1},{6,1},{11,1},{12,1}};
	int okey = 2;
	vector<Deck> play_decks_to_check =
		{{{4,1},{5,1},{6,1}},{{10,0},{11,1},{12,1},{13,0}}};
	int score = 61;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, BaseLowerUpperLongSequenceTwoOKey)
{
	Deck cards =
		{{10,1},{11,1},{12,1},{12,1},{13,1}};
	int okey = 2;
	vector<Deck> play_decks_to_check =
		{{{10,1},{11,1},{12,1},{13,1}},{{12,0},{12,0},{12,1}}};
	int score = 82;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, BaseMiddleSequenceTwoOKey)
{
	Deck cards =
		{{8,1},{11,1}};
	int okey = 2;
	vector<Deck> play_decks_to_check =
		{{{8,1},{9,0},{10,0},{11,1}}};
	int score = 38;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, BaseMiddleSequenceOneOKey)
{
	Deck cards =
		{{6,1},{8,1}};
	int okey = 1;
	vector<Deck> play_decks_to_check =
		{{{6,1},{7,0},{8,1}}};
	int score = 21;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, BaseMiddleSequenceOneOKey_2)
{
	Deck cards =
		{{5,1},{6,1},{8,1},{9,1}};
	int okey = 1;
	vector<Deck> play_decks_to_check =
		{{{5,1},{6,1},{7,0},{8,1},{9,1}}};
	int score = 35;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, BaseMiddleSequenceOneOKey_3)
{
	Deck cards =
		{{3,1},{5,1},{7,1}};
	int okey = 1;
	vector<Deck> play_decks_to_check =
		{{{3,1}},{{5,1},{6,0},{7,1}}};
	int score = 18;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, BaseMiddleSequenceOneOKey_4)
{
	Deck cards =
		{{8,1},{9,1},{11,1},{13,1}};
	int okey = 1;
	vector<Deck> play_decks_to_check =
		{{{8,1},{9,1},{10,0},{11,1}},{{13,1}}};
	int score = 38;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, BaseMiddleAndUpperSequenceTwoOKey)
{
	Deck cards =
		{{6,1},{8,1},{11,1},{12,1}};
	int okey = 2;
	vector<Deck> play_decks_to_check =
		{{{6,1},{7,0},{8,1}},{{11,1},{12,1},{13,0}}};
	int score = 57;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, BaseMiddleAndLowerSequenceTwoOKey)
{
	Deck cards =
		{{6,1},{8,1},{12,1},{13,1}};
	int okey = 2;
	vector<Deck> play_decks_to_check =
		{{{6,1},{7,0},{8,1}},{{11,0},{12,1},{13,1}}};
	int score = 57;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, BaseUpperAndLowerSequenceTwoOKey)
{
	Deck cards =
		{{3,1},{4,1},{12,1},{13,1}};
	int okey = 2;
	vector<Deck> play_decks_to_check =
		{{{3,1},{4,1},{5,0}},{{11,0},{12,1},{13,1}}};
	int score = 48;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, BaseMiddleSequenceAndTripletTwoOKey)
{
	Deck cards =
		{{6,1},{8,1},{11,1},{11,2}};
	int okey = 2;
	vector<Deck> play_decks_to_check =
		{{{6,1},{7,0},{8,1}},{{11,0},{11,1},{11,2}}};
	int score = 54;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, BaseTwoMiddleSequenceTwoOKey)
{
	Deck cards =
		{{3,1},{5,1},{7,1},{9,1}};
	int okey = 2;
	vector<Deck> play_decks_to_check =
		{{{3,1},{4,0},{5,1}},{{7,1},{8,0},{9,1}}};
	int score = 36;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, BaseTwoMiddleSequenceTwoOKey_2)
{
	Deck cards =
		{{5,1},{7,1},{10,1},{12,1}};
	int okey = 2;
	vector<Deck> play_decks_to_check =
		{{{5,1},{6,0},{7,1}},{{10,1},{11,0},{12,1}}};
	int score = 51;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, BaseTwoMiddleSequenceTwoOKey_3)
{
	Deck cards =
		{{6,1},{8,1},{10,1},{12,1}};
	int okey = 2;
	vector<Deck> play_decks_to_check =
		{{{6,1},{7,0},{8,1}},{{10,1},{11,0},{12,1}}};
	int score = 54;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, BaseMiddleUpperSequenceTwoOKey)
{
	Deck cards =
		{{9,1},{11,1}};
	int okey = 2;
	vector<Deck> play_decks_to_check =
		{{{9,1},{10,0},{11,1},{12,0}}};
	int score = 42;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, BaseMiddleUpperSequenceTwoOKey_2)
{
	Deck cards =
		{{1,1},{3,1},{5,1},{7,1}};
	int okey = 2;
	vector<Deck> play_decks_to_check =
		{{{1,1}},{{3,1}},{{5,1},{6,0},{7,1},{8,0}}};
	int score = 26;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, BaseMiddleUpperSequenceTwoOKey_3)
{
	Deck cards =
		{{5,1},{6,1},{8,1},{9,1}};
	int okey = 2;
	vector<Deck> play_decks_to_check =
		{{{5,1},{6,1},{7,0},{8,1},{9,1},{10,0}}};
	int score = 45;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, NormalUpperSequenceTwoOKey)
{
	Deck cards =
		{{1,1},{2,1},{3,1},{2,2},{3,2},{2,3}};
	int okey = 2;
	vector<Deck> play_decks_to_check =
		{{{1,1},{2,1},{3,1}},{{2,2},{3,2},{4,0},{5,0}},{{2,3}}};
	int score = 20;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, NormalUpperSequenceTwoOKey_2)
{
	Deck cards =
		{{1,1},{2,1},{3,1},{2,2},{3,2},{3,3}};
	int okey = 2;
	vector<Deck> play_decks_to_check =
		{{{1,1},{2,1},{3,1}},{{2,2},{3,2},{4,0},{5,0}},{{3,3}}};
	int score = 20;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, NormalUpperTripletTwoOKey)
{
	Deck cards =
		{{11,1},{12,1},{13,1},{12,2},{13,2},{13,3}};
	int okey = 2;
	vector<Deck> play_decks_to_check =
		{{{11,1},{12,1},{13,1}},{{12,2}},{{13,0},{13,0},{13,2},{13,3}}};
	int score = 88;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, NormalUpperTripletTwoOKey_2)
{
	Deck cards =
		{{11,1},{12,1},{13,1},{13,2}};
	int okey = 2;
	vector<Deck> play_decks_to_check =
		{{{11,1},{12,1},{13,1}},{{13,0},{13,0},{13,2}}};
	int score = 75;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, NormalUpperTripletTwoOKey_3)
{
	Deck cards =
		{{2,1},{3,1},{4,1},{5,1},{6,1},{7,1},{8,1},{9,1},{10,1},{11,1},{12,1}};
	int okey = 2;
	vector<Deck> play_decks_to_check =
		{{{2,1},{3,1},{4,1},{5,1},{6,1},{7,1},{8,1},{9,1},{10,1},{11,1}},{{12,0},{12,0},{12,1}}};
	int score = 101;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, NormalLowerSequenceTwoOKey)
{
	Deck cards =
		{{11,1},{12,1},{13,1},{12,2},{13,2}};
	int okey = 2;
	vector<Deck> play_decks_to_check =
		{{{11,1},{12,1},{13,1}},{{10,0},{11,0},{12,2},{13,2}}};
	int score = 82;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, NormalLowerSequenceAndTripletTwoOKey)
{
	Deck cards =
		{{11,1},{12,1},{13,1},{12,2},{13,2},{13,3},{13,4}};
	int okey = 2;
	vector<Deck> play_decks_to_check =
		{{{11,1},{12,1},{13,1}},{{11,0},{12,2},{13,2}},{{13,0},{13,3},{13,4}}};
	int score = 111;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, NormalTwoMiddleSequenceTwoOKey)
{
	Deck cards =
		{{3,1},{4,1},{5,1},{6,1},{3,2},{4,2},{6,2},{4,3},{6,3}};
	int okey = 2;
	vector<Deck> play_decks_to_check =
		{{{3,1},{4,1},{5,1},{6,1}},{{3,2},{4,2},{5,0},{6,2}},{{4,3},{5,0},{6,3}}};
	int score = 51;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, NormalTwoMiddleSequenceTwoOKey_2)
{
	Deck cards =
		{{3,1},{4,1},{5,1},{6,1},{3,2},{4,2},{6,2},{4,3},{6,3},{7,3}};
	int okey = 2;
	vector<Deck> play_decks_to_check =
		{{{3,1},{4,1},{5,1},{6,1}},{{3,2},{4,2},{5,0},{6,2}},{{4,3},{5,0},{6,3},{7,3}}};
	int score = 58;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, NormalMiddleSequenceUpperTripletFirstOneOKey)
{
	Deck cards =
		{{10,1},{12,1},{5,1},{6,1},{7,1},{7,2},{7,3}};
	int okey = 1;
	vector<Deck> play_decks_to_check =
		{{{5,1}},{{6,1}},{{7,1},{7,2},{7,3}},{{10,1},{11,0},{12,1}}};
	int score = 54;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	// EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, NormalLongMiddleSequenceUpperTripletFirstOneOKey)
{
	Deck cards =
		{{7,1},{8,1},{8,3},{9,1},{9,2},{9,3},{9,4},{11,1}};
	int okey = 1;
	vector<Deck> play_decks_to_check =
		{{{7,1},{8,1},{9,1},{10,0},{11,1}},{{8,3}},{{9,2},{9,3},{9,4}}};
	int score = 72;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, NormalUpperSequenceOnTwoSequenceAndOneTripletTwoOKey)
{
	Deck cards =
		{{1,1},{1,2},{1,3},{1,4},{2,1},{2,3},{3,1},{3,3},{4,1}};
	int okey = 2;
	vector<Deck> play_decks_to_check =
		{{{1,1},{1,2},{1,4}},{{1,3},{2,3},{3,3}},{{2,1},{3,1},{4,1},{5,0},{6,0}}};
	int score = 29;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, NormalUpperSequenceOnLongSequenceTwoOKey)
{
	Deck cards =
		{{1,1},{2,1},{3,1},{4,1},{2,2},{4,2}};
	int okey = 2;
	vector<Deck> play_decks_to_check =
		{{{1,1},{2,1},{3,1},{4,1}},{{2,2}},{{4,2},{5,0},{6,0}}};
	int score = 25;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, AntiGreedySequenceFirstZeroOKey)
{
	Deck cards =
		{{5,1},{6,1},{7,1},{8,1},{9,1},{9,2},{9,1},{10,1},{11,1}};
	int okey = 0;
	vector<Deck> play_decks_to_check =
		{{{5,1},{6,1},{7,1},{8,1},{9,1}},{{9,1},{10,1},{11,1}},{{9,2}}};
	int score = 65;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, AntiGreedyTripletFirstOneOKey)
{
	Deck cards =
		{{5,1},{6,1},{7,1},{7,2},{7,3},{9,3}};
	int okey = 1;
	vector<Deck> play_decks_to_check =
		{{{5,1},{6,1},{7,1}},{{7,2}},{{7,3},{8,0},{9,3}}};
	int score = 42;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, AntiGreedyThreeCardsFirstZeroOKey)
{
	Deck cards =
		{{4,1},{6,1},{1,2},{2,2},{3,2},{4,2},{5,2},{6,2},{4,3},{5,3},{6,3},{7,3},{8,3},{9,3},{4,4},{6,4}};
	int okey = 0;
	vector<Deck> play_decks_to_check =
		{{{1,2},{2,2},{3,2},{4,2},{5,2}},{{4,1},{4,3},{4,4}},{{5,3},{6,3},{7,3},{8,3},{9,3}},{{6,1},{6,2},{6,4}}};
	int score = 80;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestOKeyCheckPassLogic)
{
	Deck cards =
		{{1,1},{2,1},{3,1},{2,1},{5,1},{4,1},{5,1}};
	int okey = 2;
	vector<Deck> play_decks_to_check =
		{{{1,1},{2,1},{3,1},{4,1},{5,1}},{{2,1}},{{5,1},{6,0},{7,0}}};
	int score = 33;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnSinglePlayShortSequenceLogic)
{
	Deck cards =
		{{2,1},{3,1},{3,2},{3,3}};
	int okey = 0;
	vector<Deck> play_decks_to_check =
		{{{2,1}},{{3,1},{3,2},{3,3}}};
	int score = 9;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnSinglePlayShortSequenceLogic_2)
{
	Deck cards =
		{{2,2},{3,1},{3,2},{3,3}};
	int okey = 0;
	vector<Deck> play_decks_to_check =
		{{{2,2}},{{3,1},{3,2},{3,3}}};
	int score = 9;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnSinglePlayShortSequenceLogic_3)
{
	Deck cards =
		{{2,3},{3,1},{3,2},{3,3}};
	int okey = 0;
	vector<Deck> play_decks_to_check =
		{{{2,3}},{{3,1},{3,2},{3,3}}};
	int score = 9;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnSinglePlayLowerSequenceLogic)
{
	Deck cards =
		{{1,1},{2,1},{3,1},{3,2},{3,3}};
	int okey = 0;
	vector<Deck> play_decks_to_check =
		{{{1,1}},{{2,1}},{{3,1},{3,2},{3,3}}};
	int score = 9;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	// EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnSinglePlayLowerSequenceLogic_2)
{
	Deck cards =
		{{1,2},{2,2},{3,1},{3,2},{3,3}};
	int okey = 0;
	vector<Deck> play_decks_to_check =
		{{{1,2}},{{2,2}},{{3,1},{3,2},{3,3}}};
	int score = 9;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	// EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnSinglePlayLowerSequenceLogic_3)
{
	Deck cards =
		{{1,3},{2,3},{3,1},{3,2},{3,3}};
	int okey = 0;
	vector<Deck> play_decks_to_check =
		{{{1,3}},{{2,3}},{{3,1},{3,2},{3,3}}};
	int score = 9;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	// EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnSinglePlayMiddleSequenceLogic)
{
	Deck cards =
		{{2,1},{3,1},{3,2},{3,3},{4,1}};
	int okey = 0;
	vector<Deck> play_decks_to_check =
		{{{2,1},{3,1},{4,1}},{{3,2},{3,3}}};
	int score = 9;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnSinglePlayMiddleSequenceLogic_2)
{
	Deck cards =
		{{2,2},{3,1},{3,2},{3,3},{4,2}};
	int okey = 0;
	vector<Deck> play_decks_to_check =
		{{{2,2},{3,2},{4,2}},{{3,1},{3,3}}};
	int score = 9;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnSinglePlayMiddleSequenceLogic_3)
{
	Deck cards =
		{{2,3},{3,1},{3,2},{3,3},{4,3}};
	int okey = 0;
	vector<Deck> play_decks_to_check =
		{{{2,3},{3,3},{4,3}},{{3,1},{3,2}}};
	int score = 9;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnSinglePlayUpperSequenceLogic)
{
	Deck cards =
		{{3,1},{3,2},{3,3},{4,1},{5,1}};
	int okey = 0;
	vector<Deck> play_decks_to_check =
		{{{3,1},{4,1},{5,1}},{{3,2},{3,3}}};
	int score = 12;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnSinglePlayUpperSequenceLogic_2)
{
	Deck cards =
		{{3,1},{3,2},{3,3},{4,2},{5,2}};
	int okey = 0;
	vector<Deck> play_decks_to_check =
		{{{3,1},{3,3}},{{3,2},{4,2},{5,2}}};
	int score = 12;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnSinglePlayUpperSequenceLogic_3)
{
	Deck cards =
		{{3,1},{3,2},{3,3},{4,3},{5,3}};
	int okey = 0;
	vector<Deck> play_decks_to_check =
		{{{3,1}},{{3,2}},{{3,3},{4,3},{5,3}}};
	int score = 12;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	// EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnSinglePlayLongSequenceLogic)
{
	Deck cards =
		{{1,1},{2,1},{3,1},{4,1},{4,2},{4,3}};
	int okey = 0;
	vector<Deck> play_decks_to_check =
		{{{1,1},{2,1},{3,1}},{{4,1},{4,2},{4,3}}};
	int score = 18;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnSinglePlayLongSequenceLogic_2)
{
	Deck cards =
		{{1,2},{2,2},{3,2},{4,1},{4,2},{4,3}};
	int okey = 0;
	vector<Deck> play_decks_to_check =
		{{{1,2},{2,2},{3,2}},{{4,1},{4,2},{4,3}}};
	int score = 18;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnSinglePlayLongSequenceLogic_3)
{
	Deck cards =
		{{1,3},{2,3},{3,3},{4,1},{4,2},{4,3}};
	int okey = 0;
	vector<Deck> play_decks_to_check =
		{{{1,3},{2,3},{3,3}},{{4,1},{4,2},{4,3}}};
	int score = 18;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

// testing ( play.count > 1 )
TEST(OKeyGame, TestNextWasteOnSinglePlaySequenceNeedCheckingPlayCountLogic)
{
	Deck cards =
		{{12,1},{13,1},{13,2},{13,3}};
	int okey = 0;
	vector<Deck> play_decks_to_check =
		{{{12,1}},{{13,1},{13,2},{13,3}}};
	int score = 39;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

// testing ( play.count > 1 )
TEST(OKeyGame, TestNextWasteOnSinglePlaySequenceNeedCheckingPlayCountLogic_2)
{
	Deck cards =
		{{11,1},{12,1},{13,1},{13,2},{13,3}};
	int okey = 0;
	vector<Deck> play_decks_to_check =
		{{{11,1}},{{12,1}},{{13,1},{13,2},{13,3}}};
	int score = 39;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	// EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

// testing ( play.count < 3 )
TEST(OKeyGame, TestNextWasteOnSinglePlaySequenceNeedCheckingPlayCountLogic_3)
{
	Deck cards =
		{{5,1},{6,1},{7,1},{6,1},{7,1},{8,1},{6,1},{7,1},{8,1}};
	int okey = 2;
	vector<Deck> play_decks_to_check =
		{{{5,1},{6,1},{7,1}},{{6,1},{7,1},{8,1},{9,0},{10,0}},{{6,1},{7,1},{8,1}}};
	int score = 79;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnSinglePlayLowerTripletLogic)
{
	Deck cards =
		{{1,3},{1,3},{1,3},{2,3},{3,3}};
	int okey = 0;
	vector<Deck> play_decks_to_check =
		{{{1,3},{2,3},{3,3}},{{1,3}},{{1,3}}};
	int score = 6;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnSinglePlayLowerTripletLogic_2)
{
	Deck cards =
		{{1,3},{1,3},{1,3},{2,3},{3,3}};
	int okey = 1;
	vector<Deck> play_decks_to_check =
		{{{1,3},{2,3},{3,3},{4,0}},{{1,3}},{{1,3}}};
	int score = 10;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnSinglePlayLowerTripletLogic_3)
{
	Deck cards =
		{{11,3},{11,3},{11,3},{12,3},{13,3}};
	int okey = 1;
	vector<Deck> play_decks_to_check =
		{{{10,0},{11,3},{12,3},{13,3}},{{11,3}},{{11,3}}};
	int score = 46;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnSinglePlayMiddleTripletLogic)
{
	Deck cards =
		{{1,3},{2,3},{2,3},{2,3},{3,3}};
	int okey = 0;
	vector<Deck> play_decks_to_check =
		{{{1,3},{2,3},{3,3}},{{2,3}},{{2,3}}};
	int score = 6;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnSinglePlayMiddleTripletLogic_2)
{
	Deck cards =
		{{1,3},{2,3},{2,3},{2,3},{3,3}};
	int okey = 1;
	vector<Deck> play_decks_to_check =
		{{{1,3},{2,3},{3,3},{4,0}},{{2,3}},{{2,3}}};
	int score = 10;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnSinglePlayUpperTripletLogic)
{
	Deck cards =
		{{1,3},{2,3},{3,3},{3,3},{3,3}};
	int okey = 0;
	vector<Deck> play_decks_to_check =
		{{{1,3},{2,3},{3,3}},{{3,3}},{{3,3}}};
	int score = 6;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnSinglePlayUpperTripletLogic_2)
{
	Deck cards =
		{{1,3},{2,3},{3,3},{3,3},{3,3}};
	int okey = 1;
	vector<Deck> play_decks_to_check =
		{{{1,3},{2,3},{3,3},{4,0}},{{3,3}},{{3,3}}};
	int score = 10;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnSinglePlayShortTripletLogic)
{
	Deck cards =
		{{1,1},{1,1},{2,1},{3,1}};
	int okey = 0;
	vector<Deck> play_decks_to_check =
		{{{1,1},{2,1},{3,1}},{{1,1}}};
	int score = 6;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnSinglePlayShortDiffTripletLogic)
{
	Deck cards =
		{{1,1},{1,2},{2,1},{3,1}};
	int okey = 0;
	vector<Deck> play_decks_to_check =
		{{{1,1},{2,1},{3,1}},{{1,2}}};
	int score = 6;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnSinglePlayShortDiffTripletLogic_2)
{
	Deck cards =
		{{1,1},{1,2},{2,2},{3,2}};
	int okey = 0;
	vector<Deck> play_decks_to_check =
		{{{1,1}},{{1,2},{2,2},{3,2}}};
	int score = 6;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnSinglePlayLowerDiffTripletLogic)
{
	Deck cards =
		{{1,1},{1,2},{1,3},{2,1},{3,1}};
	int okey = 0;
	vector<Deck> play_decks_to_check =
		{{{1,1},{2,1},{3,1}},{{1,2},{1,3}}};
	int score = 6;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnSinglePlayLowerDiffTripletLogic_2)
{
	Deck cards =
		{{1,1},{1,2},{1,3},{2,2},{3,2}};
	int okey = 0;
	vector<Deck> play_decks_to_check =
		{{{1,1},{1,3}},{{1,2},{2,2},{3,2}}};
	int score = 6;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnSinglePlayLowerDiffTripletLogic_3)
{
	Deck cards =
		{{1,1},{1,2},{1,3},{2,3},{3,3}};
	int okey = 0;
	vector<Deck> play_decks_to_check =
		{{{1,1}},{{1,2}},{{1,3},{2,3},{3,3}}};
	int score = 6;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	// EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnSinglePlayLowerDiffTripletLogic_4)
{
	Deck cards =
		{{1,1},{1,2},{1,3},{2,3},{3,3}};
	int okey = 1;
	vector<Deck> play_decks_to_check =
		{{{1,1},{1,2},{1,3}},{{2,3},{3,3},{4,0}}};
	int score = 12;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}


TEST(OKeyGame, TestNextWasteOnSinglePlayLowerDiffTripletLogic_5)
{
	Deck cards =
		{{11,1},{11,2},{11,3},{12,3},{13,3}};
	int okey = 1;
	vector<Deck> play_decks_to_check =
		{{{11,1},{11,2},{11,3}},{{11,0},{12,3},{13,3}}};
	int score = 69;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnSinglePlayMiddleDiffTripletLogic)
{
	Deck cards =
		{{1,1},{2,1},{2,2},{2,3},{3,1}};
	int okey = 0;
	vector<Deck> play_decks_to_check =
		{{{1,1},{2,1},{3,1}},{{2,2},{2,3}}};
	int score = 6;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnSinglePlayMiddleDiffTripletLogic_2)
{
	Deck cards =
		{{1,2},{2,1},{2,2},{2,3},{3,2}};
	int okey = 0;
	vector<Deck> play_decks_to_check =
		{{{1,2},{2,2},{3,2}},{{2,1},{2,3}}};
	int score = 6;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnSinglePlayMiddleDiffTripletLogic_3)
{
	Deck cards =
		{{1,3},{2,1},{2,2},{2,3},{3,3}};
	int okey = 0;
	vector<Deck> play_decks_to_check =
		{{{1,3},{2,3},{3,3}},{{2,1},{2,2}}};
	int score = 6;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnSinglePlayMiddleDiffTripletLogic_4)
{
	Deck cards =
		{{1,3},{2,1},{2,2},{2,3},{3,3}};
	int okey = 1;
	vector<Deck> play_decks_to_check =
		{{{1,3},{2,3},{3,3}},{{2,0},{2,1},{2,2}}};
	int score = 12;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnSinglePlayUpperDiffTripletLogic)
{
	Deck cards =
		{{1,1},{2,1},{3,1},{3,2},{3,3}};
	int okey = 0;
	vector<Deck> play_decks_to_check =
		{{{1,1}},{{2,1}},{{3,1},{3,2},{3,3}}};
	int score = 9;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	// EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnSinglePlayUpperDiffTripletLogic_2)
{
	Deck cards =
		{{1,2},{2,2},{3,1},{3,2},{3,3}};
	int okey = 0;
	vector<Deck> play_decks_to_check =
		{{{1,2}},{{2,2}},{{3,1},{3,2},{3,3}}};
	int score = 9;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	// EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnSinglePlayUpperDiffTripletLogic_3)
{
	Deck cards =
		{{1,3},{2,3},{3,1},{3,2},{3,3}};
	int okey = 0;
	vector<Deck> play_decks_to_check =
		{{{1,3}},{{2,3}},{{3,1},{3,2},{3,3}}};
	int score = 9;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	// EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnSinglePlayUpperDiffTripletLogic_4)
{
	Deck cards =
		{{1,3},{2,3},{3,1},{3,2},{3,3}};
	int okey = 1;
	vector<Deck> play_decks_to_check =
		{{{1,3},{2,3},{3,3}},{{3,0},{3,1},{3,2}}};
	int score = 15;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnSinglePlayDiffTripletLogic)
{
	Deck cards =
		{{1,2},{1,2},{1,3},{2,3},{3,3}};
	int okey = 0;
	vector<Deck> play_decks_to_check =
		{{{1,2}},{{1,2}},{{1,3},{2,3},{3,3}}};
	int score = 6;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnSinglePlayDiffTripletLogic_2)
{
	Deck cards =
		{{1,2},{1,3},{1,3},{2,3},{3,3}};
	int okey = 0;
	vector<Deck> play_decks_to_check =
		{{{1,2},{1,3}},{{1,3},{2,3},{3,3}}};
	int score = 6;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnSinglePlayLongTripletLogic)
{
	Deck cards =
		{{1,3},{1,3},{1,3},{1,3},{2,3},{3,3}};
	int okey = 0;
	vector<Deck> play_decks_to_check =
		{{{1,3},{2,3},{3,3}},{{1,3}},{{1,3}},{{1,3}}};
	int score = 6;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnSinglePlayLongDiffTripletLogic)
{
	Deck cards =
		{{1,1},{1,2},{1,3},{1,4},{2,1},{3,1}};
	int okey = 0;
	vector<Deck> play_decks_to_check =
		{{{1,1},{2,1},{3,1}},{{1,2},{1,3},{1,4}}};
	int score = 9;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnSinglePlayLongDiffTripletLogic_2)
{
	Deck cards =
		{{1,1},{1,2},{1,3},{1,4},{2,2},{3,2}};
	int okey = 0;
	vector<Deck> play_decks_to_check =
		{{{1,1},{1,3},{1,4}},{{1,2},{2,2},{3,2}}};
	int score = 9;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnSinglePlayLongDiffTripletLogic_3)
{
	Deck cards =
		{{1,1},{1,2},{1,3},{1,4},{2,3},{3,3}};
	int okey = 0;
	vector<Deck> play_decks_to_check =
		{{{1,1},{1,2},{1,4}},{{1,3},{2,3},{3,3}}};
	int score = 9;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnSinglePlayLongDiffTripletLogic_4)
{
	Deck cards =
		{{1,1},{1,2},{1,3},{1,4},{2,4},{3,4}};
	int okey = 0;
	vector<Deck> play_decks_to_check =
		{{{1,1},{1,2},{1,3}},{{1,4},{2,4},{3,4}}};
	int score = 9;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnSinglePlayLongDiffTripletLogic_5)
{
	Deck cards =
		{{1,1},{1,2},{1,3},{1,3},{2,3},{3,3}};
	int okey = 0;
	vector<Deck> play_decks_to_check =
		{{{1,1},{1,2},{1,3}},{{1,3},{2,3},{3,3}}};
	int score = 9;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnSinglePlayLongDiffTripletLogic_6)
{
	Deck cards =
		{{1,2},{1,2},{1,3},{1,3},{2,3},{3,3}};
	int okey = 0;
	vector<Deck> play_decks_to_check =
		{{{1,2},{1,3}},{{1,2}},{{1,3},{2,3},{3,3}}};
	int score = 6;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnSinglePlayLongDiffTripletLogic_7)
{
	Deck cards =
		{{1,2},{1,3},{1,3},{1,3},{2,3},{3,3}};
	int okey = 0;
	vector<Deck> play_decks_to_check =
		{{{1,2},{1,3}},{{1,3},{2,3},{3,3}},{{1,3}}};
	int score = 6;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

// testing ( play.count > 1 )
TEST(OKeyGame, TestNextWasteOnSinglePlayTripletNeedCheckingPlayCountLogic)
{
	Deck cards =
		{{1,1},{1,2},{2,2},{3,2}};
	int okey = 0;
	vector<Deck> play_decks_to_check =
		{{{1,1}},{{1,2},{2,2},{3,2}}};
	int score = 6;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

// testing ( play.count > 1 )
TEST(OKeyGame, TestNextWasteOnSinglePlayTripletNeedCheckingPlayCountLogic_2)
{
	Deck cards =
		{{1,1},{1,2},{1,3},{2,3},{3,3}};
	int okey = 0;
	vector<Deck> play_decks_to_check =
		{{{1,1}},{{1,2}},{{1,3},{2,3},{3,3}}};
	int score = 6;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	// EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

// testing ( play.count < 3 )
TEST(OKeyGame, TestNextWasteOnSinglePlayTripletNeedCheckingPlayCountLogic_3)
{
	Deck cards =
		{{1,1},{1,2},{1,3},{1,4},{2,4},{3,4}};
	int okey = 0;
	vector<Deck> play_decks_to_check =
		{{{1,1},{1,2},{1,3}},{{1,4},{2,4},{3,4}}};
	int score = 9;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

// testing ( card_suit_upper_bounds[card.first] == card.second ) // no more other else will be triplet
TEST(OKeyGame, TestNextWasteOnSinglePlayTripletNeedCheckingCardSuitUpperBoundsLogic)
{
	Deck cards =
		{{1,1},{1,2},{1,3},{1,4},{2,3},{3,3}};
	int okey = 0;
	vector<Deck> play_decks_to_check =
		{{{1,1},{1,2},{1,4}},{{1,3},{2,3},{3,3}}};
	int score = 9;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysSequenceLogic)
{
	Deck cards =
		{{1,1},{2,1},{3,1},{4,1},{5,1},{6,1},{7,1},{8,1},{9,1},{10,1},{11,1},{12,1},{13,1}};
	int okey = 0;
	vector<Deck> play_decks_to_check =
		{{{1,1},{2,1},{3,1},{4,1},{5,1},{6,1},{7,1},{8,1},{9,1},{10,1},{11,1},{12,1},{13,1}}};
	int score = 91;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysSequenceLogic_1)
{
	Deck cards =
		{{1,1},{2,1},{3,1},{4,1},{5,1},{6,1},{7,1},{8,1},{9,1},{10,1},{11,1},{12,1},{13,1}};
	int okey = 1;
	vector<Deck> play_decks_to_check =
		{{{1,1},{2,1},{3,1},{4,1},{5,1},{6,1},{7,1},{8,1},{9,1},{10,1},{11,1}},{{11,0},{12,1},{13,1}}};
	int score = 102;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysSequenceLogic_2)
{
	Deck cards =
		{{1,1},{2,1},{3,1},{4,1},{5,1},{6,1},{7,1},{8,1},{9,1},{10,1},{11,1},{12,1},{13,1}};
	int okey = 2;
	vector<Deck> play_decks_to_check =
		{{{1,1},{2,1},{3,1},{4,1},{5,1},{6,1},{7,1},{8,1},{9,1},{10,1},{11,1},{12,1}},{{13,0},{13,0},{13,1}}};
	int score = 117;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysSequenceLogic_3)
{
	Deck cards =
		{{1,1},{2,1},{3,1},{4,1},{5,1},{6,1},{7,1},{8,1},{9,1},{10,1},{11,1},{12,1}};
	int okey = 1;
	vector<Deck> play_decks_to_check =
		{{{1,1},{2,1},{3,1},{4,1},{5,1},{6,1},{7,1},{8,1},{9,1},{10,1},{11,1},{12,1},{13,0}}};
	int score = 91;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysSequenceLogic_4)
{
	Deck cards =
		{{1,1},{2,1},{3,1},{4,1},{5,1},{6,1},{7,1},{8,1},{9,1},{10,1},{11,1},{12,1}};
	int okey = 2;
	vector<Deck> play_decks_to_check =
		{{{1,1},{2,1},{3,1},{4,1},{5,1},{6,1},{7,1},{8,1},{9,1},{10,1},{11,1}},{{12,0},{12,0},{12,1}}};
	int score = 102;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysTwoSequenceLogic)
{
	Deck cards =
		{{7,1},{8,1},{9,1},{10,1},{11,1},{12,1},{13,1},{7,1},{8,1},{9,1},{10,1},{11,1},{12,1},{13,1}};
	int okey = 1;
	vector<Deck> play_decks_to_check =
		{{{7,1},{8,1},{9,1},{10,1},{11,1},{12,1},{13,1}},{{7,1},{8,1},{9,1},{10,1},{11,1}},{{11,0},{12,1},{13,1}}};
	int score = 151;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysTwoSequenceLogic_2)
{
	Deck cards =
		{{7,1},{8,1},{9,1},{10,1},{11,1},{12,1},{13,1},{7,1},{8,1},{9,1},{10,1},{11,1},{12,1},{13,1}};
	int okey = 2;
	vector<Deck> play_decks_to_check =
		{{{7,1},{8,1},{9,1},{10,1},{11,1},{12,1},{13,1}},{{7,1},{8,1},{9,1},{10,1},{11,1},{12,1}},{{13,0},{13,0},{13,1}}};
	int score = 166;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysTwoDiffSequenceLogic)
{
	Deck cards =
		{{7,1},{8,1},{9,1},{10,1},{11,1},{12,1},{13,1},{7,3},{8,3},{9,3},{10,3},{11,3},{12,3},{13,3}};
	int okey = 1;
	vector<Deck> play_decks_to_check =
		{{{7,1},{8,1},{9,1},{10,1},{11,1},{12,1}},{{7,3},{8,3},{9,3},{10,3},{11,3},{12,3}},{{13,0},{13,1},{13,3}}};
	int score = 153;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysTwoDiffSequenceLogic_2)
{
	Deck cards =
		{{7,1},{8,1},{9,1},{10,1},{11,1},{12,1},{13,1},{7,3},{8,3},{9,3},{10,3},{11,3},{12,3},{13,3}};
	int okey = 2;
	vector<Deck> play_decks_to_check =
		{{{7,1},{8,1},{9,1},{10,1},{11,1},{12,1},{13,1}},{{7,3},{8,3},{9,3},{10,3},{11,3},{12,3}},{{13,0},{13,0},{13,3}}};
	int score = 166;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysLongUpperSequenceLogic)
{
	Deck cards =
		{{8,1},{9,1},{10,1},{11,1},{12,1},{13,1},{11,3},{12,3},{13,3}};
	int okey = 0;
	vector<Deck> play_decks_to_check =
		{{{8,1},{9,1},{10,1},{11,1},{12,1},{13,1}},{{11,3},{12,3},{13,3}}};
	int score = 99;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysLongUpperSequenceLogic_1)
{
	Deck cards =
		{{8,1},{9,1},{10,1},{11,1},{12,1},{13,1},{11,3},{12,3},{13,3}};
	int okey = 1;
	vector<Deck> play_decks_to_check =
		{{{8,1},{9,1},{10,1},{11,1}},{{11,3},{12,3},{13,3}},{{11,0},{12,1},{13,1}}};
	int score = 110;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysLongUpperSequenceLogic_2)
{
	Deck cards =
		{{8,1},{9,1},{10,1},{11,1},{12,1},{13,1},{11,3},{12,3},{13,3}};
	int okey = 2;
	vector<Deck> play_decks_to_check =
		{{{8,1},{9,1},{10,1},{11,1},{12,1}},{{11,3},{12,3},{13,3}},{{13,0},{13,0},{13,1}}};
	int score = 125;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

// testing ( play.max == card.first && card_suit_upper_bounds[card.first] == card.second )
TEST(OKeyGame, TestNextWasteOnMultiplePlaysSequenceNeedCheckingCardSuitUpperBoundsLogic)
{
	Deck cards =
		{{5,1},{6,1},{7,1},{8,1},{8,2},{8,3},{8,4},{9,2},{10,2}};
	int okey = 0;
	vector<Deck> play_decks_to_check =
		{{{5,1},{6,1},{7,1}},{{8,1},{8,3},{8,4}},{{8,2},{9,2},{10,2}}};
	int score = 69;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

// testing ( play.min <= MAX_N - 2 )
TEST(OKeyGame, TestNextWasteOnMultiplePlaysSequenceNeedCheckingMaxPlayCountLogic)
{
	Deck cards =
		{{8,1},{9,1},{10,1},{11,1},{12,1},{13,1},{13,1}};
	int okey = 1;
	vector<Deck> play_decks_to_check =
		{{{8,1},{9,1},{10,1},{11,1}},{{11,0},{12,1},{13,1}},{{13,1}}};
	int score = 74;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysTripletsLogic)
{
	Deck cards =
		{{9,1},{9,1},{11,1},{11,1},{10,1}};
	int okey = 2;
	vector<Deck> play_decks_to_check =
		{{{9,1},{10,1},{11,1},{12,0}},{{9,1},{10,0},{11,1}}};
	int score = 72;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysFarTripletLogic)
{
	Deck cards =
		{{9,1},{9,1},{11,1},{10,1},{10,2},{10,3}};
	int okey = 1;
	vector<Deck> play_decks_to_check =
		{{{9,1},{10,1},{11,1}},{{9,1}},{{10,0},{10,2},{10,3}}};
	int score = 60;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysFarTripletLogic_2)
{
	Deck cards =
		{{9,2},{9,2},{11,2},{10,1},{10,2},{10,3}};
	int okey = 1;
	vector<Deck> play_decks_to_check =
		{{{9,2},{10,2},{11,2}},{{9,2}},{{10,0},{10,1},{10,3}}};
	int score = 60;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysFarTripletLogic_3)
{
	Deck cards =
		{{9,3},{9,3},{11,3},{10,1},{10,2},{10,3}};
	int okey = 1;
	vector<Deck> play_decks_to_check =
		{{{9,3},{10,3},{11,3}},{{9,3}},{{10,0},{10,1},{10,2}}};
	int score = 60;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysDiffTripletLogic)
{
	Deck cards =
		{{10,2},{10,3},{11,3},{12,3},{11,2}};
	int okey = 0;
	vector<Deck> play_decks_to_check =
		{{{10,2},{11,2}},{{10,3},{11,3},{12,3}}};
	int score = 33;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysDiffTripletLogic_2)
{
	Deck cards =
		{{10,2},{10,3},{11,2},{12,2},{11,3}};
	int okey = 0;
	vector<Deck> play_decks_to_check =
		{{{10,2},{11,2},{12,2}},{{10,3},{11,3}}};
	int score = 33;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysLongTripletLogic)
{
	Deck cards =
		{{9,1},{9,2},{9,3},{11,2},{10,1},{10,2},{10,3}};
	int okey = 1;
	vector<Deck> play_decks_to_check =
		{{{9,1},{9,2},{9,3}},{{10,0},{10,1},{10,2},{10,3}},{{11,2}}};
	int score = 67;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysLongTripletLogic_2)
{
	Deck cards =
		{{9,1},{9,2},{9,3},{9,4},{11,2},{10,1},{10,2},{10,3}};
	int okey = 1;
	vector<Deck> play_decks_to_check =
		{{{9,1},{9,3},{9,4}},{{9,2},{10,2},{11,2}},{{10,0},{10,1},{10,3}}};
	int score = 87;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysLongTripletLogic_3)
{
	Deck cards =
		{{9,1},{9,2},{9,3},{9,4},{9,2},{11,2},{10,1},{10,2},{10,3}};
	int okey = 1;
	vector<Deck> play_decks_to_check =
		{{{9,1},{9,2},{9,3},{9,4}},{{9,2},{10,2},{11,2}},{{10,0},{10,1},{10,3}}};
	int score = 96;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysLongDiffTripletLogic)
{
	Deck cards =
		{{10,1},{10,2},{10,3},{10,4},{11,1},{12,1}};
	int okey = 0;
	vector<Deck> play_decks_to_check =
		{{{10,1},{11,1},{12,1}},{{10,2},{10,3},{10,4}}};
	int score = 63;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysLongDiffTripletLogic_2)
{
	Deck cards =
		{{10,1},{10,2},{10,3},{10,4},{11,2},{12,2}};
	int okey = 0;
	vector<Deck> play_decks_to_check =
		{{{10,1},{10,3},{10,4}},{{10,2},{11,2},{12,2}}};
	int score = 63;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysLongDiffTripletLogic_3)
{
	Deck cards =
		{{10,1},{10,2},{10,3},{10,4},{11,3},{12,3}};
	int okey = 0;
	vector<Deck> play_decks_to_check =
		{{{10,1},{10,2},{10,4}},{{10,3},{11,3},{12,3}}};
	int score = 63;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysLongDiffTripletLogic_4)
{
	Deck cards =
		{{10,1},{10,2},{10,3},{10,4},{11,4},{12,4}};
	int okey = 0;
	vector<Deck> play_decks_to_check =
		{{{10,1},{10,2},{10,3}},{{10,4},{11,4},{12,4}}};
	int score = 63;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysLongDiffTripletLogic_5)
{
	Deck cards =
		{{10,1},{10,2},{10,3},{10,4},{11,1}};
	int okey = 0;
	vector<Deck> play_decks_to_check =
		{{{10,1},{10,2},{10,3},{10,4}},{{11,1}}};
	int score = 40;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysLongDiffTripletLogic_6)
{
	Deck cards =
		{{10,1},{10,2},{10,3},{10,4},{11,3}};
	int okey = 0;
	vector<Deck> play_decks_to_check =
		{{{10,1},{10,2},{10,3},{10,4}},{{11,3}}};
	int score = 40;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysLongDiffTripletLogic_7)
{
	Deck cards =
		{{10,2},{10,3},{10,4},{10,3},{11,1}};
	int okey = 0;
	vector<Deck> play_decks_to_check =
		{{{10,2},{10,3},{10,4}},{{10,3}},{{11,1}}};
	int score = 30;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysLongDiffTripletLogic_8)
{
	Deck cards =
		{{10,2},{10,3},{10,4},{10,3},{11,3}};
	int okey = 0;
	vector<Deck> play_decks_to_check =
		{{{10,2},{10,3},{10,4}},{{10,3},{11,3}}};
	int score = 30;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysLongDiffTripletWithSequenceLogic)
{
	Deck cards =
		{{10,2},{10,2},{10,3},{10,4},{11,2},{12,2},{11,1}};
	int okey = 0;
	vector<Deck> play_decks_to_check =
		{{{10,2},{10,3},{10,4}},{{10,2},{11,2},{12,2}},{{11,1}}};
	int score = 63;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysLongDiffTripletWithSequenceLogic_2)
{
	Deck cards =
		{{10,2},{10,2},{10,3},{10,4},{11,2},{12,2},{11,2}};
	int okey = 0;
	vector<Deck> play_decks_to_check =
		{{{10,2},{10,3},{10,4}},{{10,2},{11,2},{12,2}},{{11,2}}};
	int score = 63;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysLongDiffTripletWithSequenceLogic_3)
{
	Deck cards =
		{{10,2},{10,2},{10,3},{10,4},{11,2},{12,2},{11,3}};
	int okey = 0;
	vector<Deck> play_decks_to_check =
		{{{10,2},{10,3},{10,4}},{{10,2},{11,2},{12,2}},{{11,3}}};
	int score = 63;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysLongDiffTripletWithSequenceLogic_4)
{
	Deck cards =
		{{10,2},{10,2},{10,3},{10,4},{11,2},{12,2},{11,4}};
	int okey = 0;
	vector<Deck> play_decks_to_check =
		{{{10,2},{10,3},{10,4}},{{10,2},{11,2},{12,2}},{{11,4}}};
	int score = 63;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysLongDiffTripletWithUpperSequenceLogic)
{
	Deck cards =
		{{10,1},{10,2},{10,3},{11,3},{12,3},{11,2}};
	int okey = 0;
	vector<Deck> play_decks_to_check =
		{{{10,1}},{{10,2},{11,2}},{{10,3},{11,3},{12,3}}};
	int score = 33;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	// EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysLongDiffTripletWithUpperSequenceLogic_2)
{
	Deck cards =
		{{10,1},{10,2},{10,3},{10,4},{11,3},{12,3},{11,2}};
	int okey = 0;
	vector<Deck> play_decks_to_check =
		{{{10,1},{10,2},{10,4}},{{10,3},{11,3},{12,3}},{{11,2}}};
	int score = 63;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysTwoTripletsLogic)
{
	Deck cards =
		{{10,1},{10,1},{12,1},{12,1},{13,1},{11,1}};
	int okey = 2;
	vector<Deck> play_decks_to_check =
		{{{10,1},{11,1},{12,1},{13,1}},{{10,1},{11,0},{12,1},{13,0}}};
	int score = 92;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysTwoDiffTripletsLogic)
{
	Deck cards =
		{{10,1},{10,2},{12,1},{12,2},{13,2},{11,1}};
	int okey = 1;
	vector<Deck> play_decks_to_check =
		{{{10,1},{11,1},{12,1}},{{10,2},{11,0},{12,2},{13,2}}};
	int score = 79;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysTwoDiffTripletsLogic_2)
{
	Deck cards =
		{{10,1},{10,2},{12,1},{12,2},{13,2},{11,2}};
	int okey = 1;
	vector<Deck> play_decks_to_check =
		{{{10,1},{11,0},{12,1}},{{10,2},{11,2},{12,2},{13,2}}};
	int score = 79;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysTwoDiffTripletsLogic_3)
{
	Deck cards =
		{{10,1},{10,2},{12,1},{12,2},{13,2},{11,3}};
	int okey = 2;
	vector<Deck> play_decks_to_check =
		{{{10,1},{11,0},{12,1}},{{10,2},{11,0},{12,2},{13,2}},{{11,3}}};
	int score = 79;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysTwoLongDiffTripletsLogic)
{
	Deck cards =
		{{10,1},{10,2},{10,3},{10,4},{12,1},{12,2},{13,2},{11,1}};
	int okey = 1;
	vector<Deck> play_decks_to_check =
		{{{10,1},{11,1},{12,1}},{{10,2},{10,3},{10,4}},{{11,0},{12,2},{13,2}}};
	int score = 99;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysTwoLongDiffTripletsLogic_2)
{
	Deck cards =
		{{10,1},{10,2},{10,3},{10,4},{12,1},{12,2},{13,2},{11,2}};
	int okey = 1;
	vector<Deck> play_decks_to_check =
		{{{10,1},{11,0},{12,1}},{{10,2},{10,3},{10,4}},{{11,2},{12,2},{13,2}}};
	int score = 99;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

// proof for code's logic
//	if ( 1 == play.count && play.max < card.first && play.suit == card.second )
//				preference = PlayPreferToTriplet
//
//		for case:
//		i,i,i+3,...
//
//		suppose to:
//		i
//		i (i+1) (i+2)
//		i+3 ...
//		score = i + (i+1) + (i+2) = 3i + 3
//
//		be possible to:
//		1)
//		i i
//		(i+3) (i+3) i+3 x 1
//		score = (i+3) + (i+3) + i+3 = 3i + 9
//
//		2)
//		i i
//		(i+3) (i+3) i+3 x 2
//		score = (i+3) + (i+3) + i+3 + i+3 = 4i + 12
//
//		or
//		i i (i)
//		(i+3) i+3 x 2
//		score = i + i + (i) + (i+3) + i+3 + i+3 = 6i + 9
//
//		3)
//		i i (i)
//		(i+3) i+3 x 3
//		= i + i + (i) + (i+3) = 4i + 3
//
//		4)
//		i i (i) (i)
//		i+3 x 4
//		= i + i + (i) + (i) = 4i
//
//		or
//		i i
//		i+3 x 3
//		(i+3) (i+3) i+3
//		= i+3 i+3 = 2i + 6
//
//		5)
//		i i (i)
//		(i+2) i+3 i+4 ...
//		= i + i + (i) + (i+2) = 4i + 2
//
//		for 1)
//		3i + 3 > 3i + 9  ==>  0 > 6
//
//		for 2)
//		3i + 3 > 4i + 12 and 3i + 3 > 6i + 9  ==>  i < -9 and i < -2
//
//		for 3)
//		3i + 3 > 4i + 3  ==>  i < 0
//
//		for 4)
//		3i + 3 > 4i and 3i + 3 > 2i + 6  ==> i < 3 and i > 3
//
//		for 5)
//		3i + 3 > 4i + 2  ==>  i < 1
//
//		conclusion:
//		for case i,i,i+3,..., then {i,i,...},{i+3,...} is better than {i},{i,i+1,i+2},{i+3,...}
//
// testing preference = PlayPreferToTriplet, as triplet solution is better than sequence solution
TEST(OKeyGame, TestNextWasteOnMultiplePlaysPreferToTripletLogic)
{
	Deck cards =
		{{2,1},{2,2},{5,1},{5,2},{5,3},{5,4}};
	int okey = 2;
	vector<Deck> play_decks_to_check =
		{{{2,1},{2,2}},{{5,1},{5,2},{5,3}},{{5,4},{6,0},{7,0}}};
	int score = 33;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

// testing preference = PlayPreferToTriplet, as triplet solution is better than sequence solution
TEST(OKeyGame, TestNextWasteOnMultiplePlaysPreferToTripletLogic_2)
{
	Deck cards =
		{{4,1},{4,2},{7,1},{7,2},{7,3},{7,4}};
	int okey = 2;
	vector<Deck> play_decks_to_check =
		{{{4,1},{4,2}},{{7,1},{7,2},{7,3}},{{7,4},{8,0},{9,0}}};
	int score = 45;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

// testing ( play.max < card.first && play.suit == card.second )
// testing ( play.count < 3 && play.max < card.first )
TEST(OKeyGame, TestNextWasteOnMultiplePlaysTripletNeedCheckingCardPointLogic)
{
	Deck cards =
		{{3,1},{3,2},{3,4},{3,3},{3,3},{4,3},{4,3},{5,3},{5,3}};
	int okey = 0;
	vector<Deck> play_decks_to_check =
		{{{3,1},{3,2},{3,4}},{{3,3},{4,3},{5,3}},{{3,3},{4,3},{5,3}}};
	int score = 33;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

// // testing ( play.max < card.first && play.suit == card.second )
// TEST(OKeyGame, TestNextWasteOnMultiplePlaysTripletNeedCheckingCardPointLogic_2)
// {	// this is unable to catch the error from logic of codes
// 	Deck cards =
// 		{{9,1},{9,2},{9,3},{9,4},{11,4},{12,4},{13,4}};
// 	int okey = 2;
// 	vector<Deck> play_decks_to_check =
// 		{{{9,1},{9,2},{9,3}},{{9,4},{10,0},{11,4}},{{11,0},{12,4},{13,4}}};
// 	int score = 93;
// 	OKeySolver solver;
// 	Solution solution = solver.Solve(cards, okey);
// 	EXPECT_EQ(solver.Score(solution), score);
// 	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
// }

// // testing ( play.max < card.first && play.suit == card.second )
// TEST(OKeyGame, TestNextWasteOnMultiplePlaysTripletNeedCheckingCardPointLogic_3)
// {	// this is unable to catch the error from logic of codes
// 	Deck cards =
// 		{{8,1},{8,2},{8,3},{8,4},{11,4},{12,4},{13,4}};
// 	int okey = 2;
// 	vector<Deck> play_decks_to_check =
// 		{{{8,1},{8,2},{8,3},{8,4}},{{9,0},{10,0},{11,4},{12,4},{13,4}}};
// 	int score = 87;
// 	OKeySolver solver;
// 	Solution solution = solver.Solve(cards, okey);
// 	EXPECT_EQ(solver.Score(solution), score);
// 	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
// }

// testing ( play.max < card.first && play.suit == card.second )
TEST(OKeyGame, TestNextWasteOnMultiplePlaysTripletNeedCheckingCardSuitLogic)
{
	Deck cards =
		{{9,2},{9,4},{11,4},{10,1},{10,2},{10,3}};
	int okey = 1;
	vector<Deck> play_decks_to_check =
		{{{9,2}},{{9,4},{10,0},{11,4}},{{10,1},{10,2},{10,3}}};
	int score = 60;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

// testing ( play.max < card.first && play.suit == card.second )
TEST(OKeyGame, TestNextWasteOnMultiplePlaysTripletNeedCheckingCardSuitLogic_2)
{
	Deck cards =
		{{9,3},{9,4},{11,4},{10,1},{10,2},{10,3}};
	int okey = 1;
	vector<Deck> play_decks_to_check =
		{{{9,3}},{{9,4},{10,0},{11,4}},{{10,1},{10,2},{10,3}}};
	int score = 60;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

// testing ( play.count < 3 && play.max < card.first )
TEST(OKeyGame, TestNextWasteOnMultiplePlaysTripletNeedCheckingPlayCountLogic)
{
	Deck cards =
		{{4,1},{4,2},{4,3},{4,4},{4,4},{7,1}};
	int okey = 1;
	vector<Deck> play_decks_to_check =
		{{{4,1},{4,2},{4,4}},{{4,0},{4,3},{4,4}},{{7,1}}};
	int score = 24;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

// testing ( play.count < 3 && play.max < card.first )
TEST(OKeyGame, TestNextWasteOnMultiplePlaysTripletNeedCheckingPlayCountAndCardPointLogic)
{
	Deck cards =
		{{4,1},{4,2},{4,4},{4,2},{4,3},{4,4},{4,3},{5,3},{6,3}};
	int okey = 0;
	vector<Deck> play_decks_to_check =
		{{{4,1},{4,2},{4,4}},{{4,2},{4,3},{4,4}},{{4,3},{5,3},{6,3}}};
	int score = 39;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

// testing ( suit_available ) // combinable triplet
TEST(OKeyGame, TestNextWasteOnMultiplePlaysTripletNeedCheckingPlaySuitAvailableLogic)
{
	Deck cards =
		{{7,1},{7,2},{7,1},{7,2},{12,3}};
	int okey = 2;
	vector<Deck> play_decks_to_check =
		{{{7,0},{7,1},{7,2}},{{7,0},{7,1},{7,2}},{{12,3}}};
	int score = 42;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

// testing play_preferences = play_preferences_bak; // prevent play preferences from become dirt
TEST(OKeyGame, TestNextWasteOnMultiplePlaysTripletNeedRestorePlayPreferencesLogic)
{
	Deck cards =
		{{9,2},{9,4},{11,4},{10,1},{10,2},{10,3}};
	int okey = 1;
	vector<Deck> play_decks_to_check =
		{{{9,2}},{{9,4},{10,0},{11,4}},{{10,1},{10,2},{10,3}}};
	int score = 60;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysDiscontinuousTripletsLogic)
{
	Deck cards =
		{{10,1},{10,2},{10,3},{10,4},{11,3},{12,3},{11,2}};
	int okey = 0;
	vector<Deck> play_decks_to_check =
		{{{10,1},{10,2},{10,4}},{{10,3},{11,3},{12,3}},{{11,2}}};
	int score = 63;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysTwoSingleTripletsLogic)
{
	Deck cards =
		{{5,1},{5,2},{5,2},{5,3},{5,3},{5,4},{9,1},{9,2},{9,3}};
	int okey = 0;
	vector<Deck> play_decks_to_check =
		{{{5,1},{5,2},{5,3}},{{5,2},{5,3},{5,4}},{{9,1},{9,2},{9,3}}};
	int score = 57;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysTypeSameThreeThreeTripletLogic)
{
	Deck cards =
		{{5,1},{5,2},{5,3},{5,1},{5,2},{5,3},{9,1},{9,2},{9,3}};
	int okey = 0;
	vector<Deck> play_decks_to_check =
		{{{5,1},{5,2},{5,3}},{{5,1},{5,2},{5,3}},{{9,1},{9,2},{9,3}}};
	int score = 57;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysTypeSameThreeThreeTripletLogic_2)
{
	Deck cards =
		{{5,1},{5,2},{5,3},{5,1},{5,2},{5,3},{9,1},{9,2},{9,3}};
	int okey = 1;
	vector<Deck> play_decks_to_check =
		{{{5,1},{5,2},{5,3}},{{5,1},{5,2},{5,3}},{{9,0},{9,1},{9,2},{9,3}}};
	int score = 66;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysTypeSameThreeThreeTripletLogic_3)
{
	Deck cards =
		{{5,1},{5,2},{5,3},{5,1},{5,2},{5,3},{9,1},{9,2},{9,3}};
	int okey = 2;
	vector<Deck> play_decks_to_check =
		{{{5,0},{5,1},{5,2},{5,3}},{{5,1},{5,2},{5,3}},{{9,0},{9,1},{9,2},{9,3}}};
	int score = 71;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysTypeSameThreeThreeTripletLogic_4)
{
	Deck cards =
		{{5,1},{5,2},{5,3},{5,1},{5,2},{5,3},{9,2}};
	int okey = 0;
	vector<Deck> play_decks_to_check =
		{{{5,1},{5,2},{5,3}},{{5,1},{5,2},{5,3}},{{9,2}}};
	int score = 30;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysTypeSameThreeThreeTripletLogic_5)
{
	Deck cards =
		{{5,1},{5,2},{5,3},{5,1},{5,2},{5,3},{9,2}};
	int okey = 1;
	vector<Deck> play_decks_to_check =
		{{{5,0},{5,1},{5,2},{5,3}},{{5,1},{5,2},{5,3}},{{9,2}}};
	int score = 35;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysTypeSameThreeThreeTripletLogic_6)
{
	Deck cards =
		{{5,1},{5,2},{5,3},{5,1},{5,2},{5,3},{9,4}};
	int okey = 0;
	vector<Deck> play_decks_to_check =
		{{{5,1},{5,2},{5,3}},{{5,1},{5,2},{5,3}},{{9,4}}};
	int score = 30;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysTypeSameThreeThreeTripletLogic_7)
{
	Deck cards =
		{{5,1},{5,2},{5,3},{5,1},{5,2},{5,3},{9,4}};
	int okey = 1;
	vector<Deck> play_decks_to_check =
		{{{5,0},{5,1},{5,2},{5,3}},{{5,1},{5,2},{5,3}},{{9,4}}};
	int score = 35;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysTypeSameThreeThreeFourTripletLogic)
{
	Deck cards =
		{{5,1},{5,2},{5,3},{5,1},{5,2},{5,3},{9,1},{9,2},{9,3},{9,4}};
	int okey = 2;
	vector<Deck> play_decks_to_check =
		{{{5,1},{5,2},{5,3}},{{5,1},{5,2},{5,3}},{{9,1},{9,2},{9,3}},{{9,4},{10,0},{11,0}}};
	int score = 87;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysTypeSameThreeThreeFourTripletLogic_2)
{
	Deck cards =
		{{5,1},{5,2},{5,3},{5,1},{5,2},{5,3},{13,1},{13,2},{13,3},{13,4}};
	int okey = 2;
	vector<Deck> play_decks_to_check =
		{{{5,1},{5,2},{5,3}},{{5,1},{5,2},{5,3}},{{13,1},{13,2},{13,3}},{{13,0},{13,0},{13,4}}};
	int score = 108;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysTypeDiffThreeThreeTripletLogic)
{
	Deck cards =
		{{5,1},{5,2},{5,3},{5,2},{5,3},{5,4},{9,1},{9,2},{9,3}};
	int okey = 0;
	vector<Deck> play_decks_to_check =
		{{{5,1},{5,2},{5,3}},{{5,2},{5,3},{5,4}},{{9,1},{9,2},{9,3}}};
	int score = 57;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysTypeDiffThreeThreeTripletLogic_2)
{
	Deck cards =
		{{5,1},{5,2},{5,3},{5,2},{5,3},{5,4},{9,2}};
	int okey = 0;
	vector<Deck> play_decks_to_check =
		{{{5,1},{5,2},{5,3}},{{5,2},{5,3},{5,4}},{{9,2}}};
	int score = 30;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysTypeDiffThreeThreeTripletLogic_3)
{
	Deck cards =
		{{5,1},{5,2},{5,3},{5,2},{5,3},{5,4},{9,2}};
	int okey = 1;
	vector<Deck> play_decks_to_check =
		{{{5,1},{5,2},{5,3},{5,4}},{{5,0},{5,2},{5,3}},{{9,2}}};
	int score = 35;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysTypeDiffThreeThreeTripletLogic_4)
{
	Deck cards =
		{{5,1},{5,2},{5,3},{5,2},{5,3},{5,4},{9,4}};
	int okey = 0;
	vector<Deck> play_decks_to_check =
		{{{5,1},{5,2},{5,3}},{{5,2},{5,3},{5,4}},{{9,4}}};
	int score = 30;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysTypeDiffThreeThreeTripletLogic_5)
{
	Deck cards =
		{{5,1},{5,2},{5,3},{5,2},{5,3},{5,4},{9,4}};
	int okey = 1;
	vector<Deck> play_decks_to_check =
		{{{5,1},{5,2},{5,3},{5,4}},{{5,0},{5,2},{5,3}},{{9,4}}};
	int score = 35;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysTypeSameThreeTwoTripletLogic)
{
	Deck cards =
		{{5,1},{5,2},{5,3},{5,2},{5,3},{9,1},{9,2},{9,3}};
	int okey = 1;
	vector<Deck> play_decks_to_check =
		{{{5,1},{5,2},{5,3}},{{5,0},{5,2},{5,3}},{{9,1},{9,2},{9,3}}};
	int score = 57;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysTypeSameThreeTwoTripletLogic_2)
{
	Deck cards =
		{{5,1},{5,2},{5,3},{5,2},{5,3},{9,1},{9,2},{9,3}};
	int okey = 2;
	vector<Deck> play_decks_to_check =
		{{{5,1},{5,2},{5,3}},{{5,0},{5,2},{5,3}},{{9,0},{9,1},{9,2},{9,3}}};
	int score = 66;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysTypeSameThreeTwoTripletLogic_3)
{
	Deck cards =
		{{5,1},{5,2},{5,3},{5,2},{5,3},{9,2}};
	int okey = 1;
	vector<Deck> play_decks_to_check =
		{{{5,1},{5,2},{5,3}},{{5,0},{5,2},{5,3}},{{9,2}}};
	int score = 30;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysTypeSameThreeTwoTripletLogic_4)
{
	Deck cards =
		{{5,1},{5,2},{5,3},{5,2},{5,3},{9,2}};
	int okey = 2;
	vector<Deck> play_decks_to_check =
		{{{5,1},{5,2},{5,3}},{{5,2},{5,3}},{{9,2},{10,0},{11,0}}};
	int score = 45;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysTypeSameThreeTwoTripletLogic_5)
{
	Deck cards =
		{{5,1},{5,2},{5,3},{5,2},{5,3},{9,4}};
	int okey = 1;
	vector<Deck> play_decks_to_check =
		{{{5,1},{5,2},{5,3}},{{5,0},{5,2},{5,3}},{{9,4}}};
	int score = 30;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysTypeSameThreeTwoTripletLogic_6)
{
	Deck cards =
		{{5,1},{5,2},{5,3},{5,2},{5,3},{9,4}};
	int okey = 2;
	vector<Deck> play_decks_to_check =
		{{{5,1},{5,2},{5,3}},{{5,2},{5,3}},{{9,4},{10,0},{11,0}}};
	int score = 45;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysTypeDiffThreeTwoTripletLogic)
{
	Deck cards =
		{{5,1},{5,2},{5,3},{5,3},{5,4},{9,1},{9,2},{9,3},{9,4}};
	int okey = 1;
	vector<Deck> play_decks_to_check =
		{{{5,1},{5,2},{5,3}},{{5,0},{5,3},{5,4}},{{9,1},{9,2},{9,3},{9,4}}};
	int score = 66;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysTypeDiffThreeTwoTripletLogic_2)
{
	Deck cards =
		{{5,1},{5,2},{5,3},{5,3},{5,4},{9,1},{9,2},{9,3},{9,4}};
	int okey = 2;
	vector<Deck> play_decks_to_check =
		{{{5,1},{5,2},{5,3},{5,4}},{{5,3}},{{9,1},{9,2},{9,3}},{{9,4},{10,0},{11,0}}};
	int score = 77;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysTypeDiffThreeTwoTripletLogic_3)
{
	Deck cards =
		{{5,1},{5,2},{5,3},{5,3},{5,4},{9,1},{9,3},{9,4}};
	int okey = 1;
	vector<Deck> play_decks_to_check =
		{{{5,1},{5,2},{5,3}},{{5,0},{5,3},{5,4}},{{9,1},{9,3},{9,4}}};
	int score = 57;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysTypeDiffThreeTwoTripletLogic_4)
{
	Deck cards =
		{{5,1},{5,2},{5,3},{5,3},{5,4},{9,1},{9,3},{9,4}};
	int okey = 2;
	vector<Deck> play_decks_to_check =
		{{{5,1},{5,2},{5,3}},{{5,0},{5,3},{5,4}},{{9,0},{9,1},{9,3},{9,4}}};
	int score = 66;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysTypeDiffThreeTwoTripletLogic_5)
{
	Deck cards =
		{{5,1},{5,2},{5,3},{5,3},{5,4},{9,3}};
	int okey = 1;
	vector<Deck> play_decks_to_check =
		{{{5,1},{5,2},{5,3}},{{5,0},{5,3},{5,4}},{{9,3}}};
	int score = 30;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysTypeDiffThreeTwoTripletLogic_6)
{
	Deck cards =
		{{5,1},{5,2},{5,3},{5,3},{5,4},{9,3}};
	int okey = 2;
	vector<Deck> play_decks_to_check =
		{{{5,1},{5,2},{5,3},{5,4}},{{5,3}},{{9,3},{10,0},{11,0}}};
	int score = 50;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysTypeDiffThreeTwoTripletLogic_7)
{
	Deck cards =
		{{5,1},{5,2},{5,3},{5,3},{5,4},{9,4}};
	int okey = 1;
	vector<Deck> play_decks_to_check =
		{{{5,1},{5,2},{5,3}},{{5,0},{5,3},{5,4}},{{9,4}}};
	int score = 30;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysTypeDiffThreeTwoTripletLogic_8)
{
	Deck cards =
		{{5,1},{5,2},{5,3},{5,3},{5,4},{9,4}};
	int okey = 2;
	vector<Deck> play_decks_to_check =
		{{{5,1},{5,2},{5,3},{5,4}},{{5,3}},{{9,4},{10,0},{11,0}}};
	int score = 50;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysTypeSameThreeOneTripletLogic)
{
	Deck cards =
		{{5,1},{5,2},{5,3},{5,3},{9,1},{9,2},{9,3}};
	int okey = 2;
	vector<Deck> play_decks_to_check =
		{{{5,1},{5,2},{5,3}},{{5,3},{6,0},{7,0}},{{9,1},{9,2},{9,3}}};
	int score = 60;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysTypeSameThreeOneTripletLogic_2)
{
	Deck cards =
		{{5,1},{5,2},{5,3},{5,3},{9,2}};
	int okey = 2;
	vector<Deck> play_decks_to_check =
		{{{5,1},{5,2},{5,3}},{{5,3}},{{9,2},{10,0},{11,0}}};
	int score = 45;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysTypeSameThreeOneTripletLogic_3)
{
	Deck cards =
		{{5,1},{5,2},{5,3},{5,3},{9,3}};
	int okey = 2;
	vector<Deck> play_decks_to_check =
		{{{5,1},{5,2},{5,3}},{{5,3}},{{9,3},{10,0},{11,0}}};
	int score = 45;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysTypeSameThreeOneTripletLogic_4)
{
	Deck cards =
		{{5,1},{5,2},{5,3},{5,3},{9,4}};
	int okey = 2;
	vector<Deck> play_decks_to_check =
		{{{5,1},{5,2},{5,3}},{{5,3}},{{9,4},{10,0},{11,0}}};
	int score = 45;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysTypeSameThreeOneTripletLogic_5)
{
	Deck cards =
		{{5,1},{5,2},{5,3},{5,3},{9,4}};
	int okey = 1;
	vector<Deck> play_decks_to_check =
		{{{5,0},{5,1},{5,2},{5,3}},{{5,3}},{{9,4}}};
	int score = 20;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysTypeDiffThreeOneTripletLogic)
{
	Deck cards =
		{{5,1},{5,2},{5,3},{5,4},{9,1},{9,3},{9,4}};
	int okey = 1;
	vector<Deck> play_decks_to_check =
		{{{5,1},{5,2},{5,3},{5,4}},{{9,0},{9,1},{9,3},{9,4}}};
	int score = 56;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysTypeDiffThreeOneTripletLogic_2)
{
	Deck cards =
		{{5,1},{5,2},{5,3},{5,4},{9,1},{9,3},{9,4}};
	int okey = 2;
	vector<Deck> play_decks_to_check =
		{{{5,1},{5,2},{5,3}},{{5,4},{6,0},{7,0}},{{9,1},{9,3},{9,4}}};
	int score = 60;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysTypeDiffThreeOneTripletLogic_3)
{
	Deck cards =
		{{5,1},{5,2},{5,3},{5,4},{9,2}};
	int okey = 1;
	vector<Deck> play_decks_to_check =
		{{{5,1},{5,2},{5,3},{5,4}},{{9,2}}};
	int score = 20;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysTypeDiffThreeOneTripletLogic_4)
{
	Deck cards =
		{{5,1},{5,2},{5,3},{5,4},{9,2}};
	int okey = 2;
	vector<Deck> play_decks_to_check =
		{{{5,1},{5,2},{5,3},{5,4}},{{9,2},{10,0},{11,0}}};
	int score = 50;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysTypeDiffThreeOneTripletLogic_5)
{
	Deck cards =
		{{5,1},{5,2},{5,3},{5,4},{13,4}};
	int okey = 1;
	vector<Deck> play_decks_to_check =
		{{{5,1},{5,2},{5,3},{5,4}},{{13,4}}};
	int score = 20;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}
TEST(OKeyGame, TestNextWasteOnMultiplePlaysTypeDiffThreeOneTripletLogic_6)
{
	Deck cards =
		{{5,1},{5,2},{5,3},{5,4},{13,4}};
	int okey = 2;
	vector<Deck> play_decks_to_check =
		{{{5,1},{5,2},{5,3},{5,4}},{{13,0},{13,0},{13,4}}};
	int score = 59;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysTypeSameTwoTwoTripletLogic)
{
	Deck cards =
		{{5,1},{5,2},{5,1},{5,2},{9,1},{9,2},{9,3}};
	int okey = 1;
	vector<Deck> play_decks_to_check =
		{{{5,0},{5,1},{5,2}},{{5,1},{5,2}},{{9,1},{9,2},{9,3}}};
	int score = 42;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysTypeSameTwoTwoTripletLogic_2)
{
	Deck cards =
		{{5,1},{5,2},{5,1},{5,2},{9,1},{9,2},{9,3}};
	int okey = 2;
	vector<Deck> play_decks_to_check =
		{{{5,0},{5,1},{5,2}},{{5,0},{5,1},{5,2}},{{9,1},{9,2},{9,3}}};
	int score = 57;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysTypeSameTwoTwoTripletLogic_3)
{
	Deck cards =
		{{5,1},{5,2},{5,1},{5,2},{9,2}};
	int okey = 1;
	vector<Deck> play_decks_to_check =
		{{{5,0},{5,1},{5,2}},{{5,1},{5,2}},{{9,2}}};
	int score = 15;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysTypeSameTwoTwoTripletLogic_4)
{
	Deck cards =
		{{5,1},{5,2},{5,1},{5,2},{9,4}};
	int okey = 1;
	vector<Deck> play_decks_to_check =
		{{{5,0},{5,1},{5,2}},{{5,1},{5,2}},{{9,4}}};
	int score = 15;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysTypeSameTwoTwoTripletLogic_5)
{
	Deck cards =
		{{5,1},{5,2},{5,1},{5,2},{10,2}};
	int okey = 2;
	vector<Deck> play_decks_to_check =
		{{{5,1},{5,2}},{{5,1},{5,2}},{{10,2},{11,0},{12,0}}};
	int score = 33;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysTypeDiffTwoTwoTripletLogic)
{
	Deck cards =
		{{5,1},{5,2},{5,2},{5,3},{9,1},{9,2},{9,3}};
	int okey = 1;
	vector<Deck> play_decks_to_check =
		{{{5,1},{5,2},{5,3}},{{5,2}},{{9,0},{9,1},{9,2},{9,3}}};
	int score = 51;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysTypeDiffTwoTwoTripletLogic_2)
{
	Deck cards =
		{{5,1},{5,2},{5,2},{5,3},{9,1},{9,2},{9,3}};
	int okey = 2;
	vector<Deck> play_decks_to_check =
		{{{5,1},{5,2},{5,3}},{{5,2},{6,0},{7,0}},{{9,1},{9,2},{9,3}}};
	int score = 60;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysTypeDiffTwoTwoTripletLogic_3)
{
	Deck cards =
		{{5,1},{5,2},{5,2},{5,3},{9,2}};
	int okey = 1;
	vector<Deck> play_decks_to_check =
		{{{5,0},{5,1},{5,2},{5,3}},{{5,2}},{{9,2}}};
	int score = 20;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysTypeDiffTwoTwoTripletLogic_4)
{
	Deck cards =
		{{5,1},{5,2},{5,2},{5,3},{9,4}};
	int okey = 1;
	vector<Deck> play_decks_to_check =
		{{{5,0},{5,1},{5,2},{5,3}},{{5,2}},{{9,4}}};
	int score = 20;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysTypeDiffTwoTwoTripletLogic_5)
{
	Deck cards =
		{{5,1},{5,2},{5,2},{5,3},{9,4}};
	int okey = 2;
	vector<Deck> play_decks_to_check =
		{{{5,1},{5,2},{5,3}},{{5,2}},{{9,4},{10,0},{11,0}}};
	int score = 45;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysTypeSameTwoOneTripletLogic)
{
	Deck cards =
		{{5,1},{5,2},{5,2},{9,1},{9,2},{9,3}};
	int okey = 1;
	vector<Deck> play_decks_to_check =
		{{{5,0},{5,1},{5,2}},{{5,2}},{{9,1},{9,2},{9,3}}};
	int score = 42;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysTypeSameTwoOneTripletLogic_2)
{
	Deck cards =
		{{5,1},{5,2},{5,2},{9,1},{9,2},{9,3}};
	int okey = 2;
	vector<Deck> play_decks_to_check =
		{{{5,0},{5,1},{5,2}},{{5,2}},{{9,0},{9,1},{9,2},{9,3}}};
	int score = 51;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysTypeSameTwoOneTripletLogic_3)
{
	Deck cards =
		{{5,1},{5,2},{5,2},{9,2}};
	int okey = 1;
	vector<Deck> play_decks_to_check =
		{{{5,0},{5,1},{5,2}},{{5,2}},{{9,2}}};
	int score = 15;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysTypeSameTwoOneTripletLogic_4)
{
	Deck cards =
		{{5,1},{5,2},{5,2},{9,4}};
	int okey = 1;
	vector<Deck> play_decks_to_check =
		{{{5,0},{5,1},{5,2}},{{5,2}},{{9,4}}};
	int score = 15;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysTypeSameTwoOneTripletLogic_5)
{
	Deck cards =
		{{5,1},{5,2},{5,2},{9,4}};
	int okey = 2;
	vector<Deck> play_decks_to_check =
		{{{5,1},{5,2}},{{5,2}},{{9,4},{10,0},{11,0}}};
	int score = 30;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysTypeDiffTwoOneTripletLogic)
{
	Deck cards =
		{{5,1},{5,2},{5,3},{9,1},{9,2},{9,3}};
	int okey = 1;
	vector<Deck> play_decks_to_check =
		{{{5,1},{5,2},{5,3}},{{9,0},{9,1},{9,2},{9,3}}};
	int score = 51;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysTypeDiffTwoOneTripletLogic_2)
{
	Deck cards =
		{{5,1},{5,2},{5,3},{9,1},{9,2},{9,3}};
	int okey = 2;
	vector<Deck> play_decks_to_check =
		{{{5,0},{5,1},{5,2},{5,3}},{{9,0},{9,1},{9,2},{9,3}}};
	int score = 56;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysTypeDiffTwoOneTripletLogic_3)
{
	Deck cards =
		{{5,1},{5,2},{5,3},{9,2}};
	int okey = 1;
	vector<Deck> play_decks_to_check =
		{{{5,0},{5,1},{5,2},{5,3}},{{9,2}}};
	int score = 20;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysTypeDiffTwoOneTripletLogic_4)
{
	Deck cards =
		{{5,1},{5,2},{5,3},{9,4}};
	int okey = 1;
	vector<Deck> play_decks_to_check =
		{{{5,0},{5,1},{5,2},{5,3}},{{9,4}}};
	int score = 20;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysTypeDiffTwoOneTripletLogic_5)
{
	Deck cards =
		{{5,1},{5,2},{5,3},{9,4}};
	int okey = 2;
	vector<Deck> play_decks_to_check =
		{{{5,1},{5,2},{5,3}},{{9,4},{10,0},{11,0}}};
	int score = 45;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysTypeSameOneOneTripletLogic)
{
	Deck cards =
		{{5,1},{5,1},{9,1},{9,2},{9,3},{9,4}};
	int okey = 2;
	vector<Deck> play_decks_to_check =
		{{{5,1}},{{5,1}},{{9,1},{9,2},{9,3}},{{9,4},{10,0},{11,0}}};
	int score = 57;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysTypeSameOneOneTripletLogic_2)
{
	Deck cards =
		{{5,1},{5,1},{9,1},{9,2},{9,3}};
	int okey = 2;
	vector<Deck> play_decks_to_check =
		{{{5,1},{6,0},{7,0}},{{5,1}},{{9,1},{9,2},{9,3}}};
	int score = 45;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysTypeSameOneOneTripletLogic_3)
{
	Deck cards =
		{{5,1},{5,1},{9,1}};
	int okey = 2;
	vector<Deck> play_decks_to_check =
		{{{5,1}},{{5,1}},{{9,1},{10,0},{11,0}}};
	int score = 30;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysTypeSameOneOneTripletLogic_4)
{
	Deck cards =
		{{5,1},{5,1},{9,2}};
	int okey = 2;
	vector<Deck> play_decks_to_check =
		{{{5,1}},{{5,1}},{{9,2},{10,0},{11,0}}};
	int score = 30;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysTypeSameOneOneTripletLogic_5)
{
	Deck cards =
		{{5,1},{5,1}};
	int okey = 1;
	vector<Deck> play_decks_to_check =
		{};
	int score = 0;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysTypeSameOneOneTripletLogic_6)
{
	Deck cards =
		{{5,1},{5,1}};
	int okey = 2;
	vector<Deck> play_decks_to_check =
		{{{5,1},{6,0},{7,0}},{{5,1}}};
	int score = 18;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysTypeDiffOneOneTripletLogic)
{
	Deck cards =
		{{5,1},{5,2},{9,1},{9,2},{9,3},{9,4}};
	int okey = 1;
	vector<Deck> play_decks_to_check =
		{{{5,0},{5,1},{5,2}},{{9,1},{9,2},{9,3},{9,4}}};
	int score = 51;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysTypeDiffOneOneTripletLogic_2)
{
	Deck cards =
		{{5,1},{5,2},{9,1},{9,2},{9,3}};
	int okey = 1;
	vector<Deck> play_decks_to_check =
		{{{5,0},{5,1},{5,2}},{{9,1},{9,2},{9,3}}};
	int score = 42;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysTypeDiffOneOneTripletLogic_3)
{
	Deck cards =
		{{5,1},{5,2},{9,1},{9,2},{9,3}};
	int okey = 2;
	vector<Deck> play_decks_to_check =
		{{{5,0},{5,1},{5,2}},{{9,0},{9,1},{9,2},{9,3}}};
	int score = 51;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysTypeDiffOneOneTripletLogic_4)
{
	Deck cards =
		{{5,1},{5,2},{9,2}};
	int okey = 1;
	vector<Deck> play_decks_to_check =
		{{{5,0},{5,1},{5,2}},{{9,2}}};
	int score = 15;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysTypeDiffOneOneTripletLogic_5)
{
	Deck cards =
		{{5,1},{5,2},{9,3}};
	int okey = 1;
	vector<Deck> play_decks_to_check =
		{{{5,0},{5,1},{5,2}},{{9,3}}};
	int score = 15;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysTypeDiffOneOneTripletLogic_6)
{
	Deck cards =
		{{5,1},{5,2},{9,3}};
	int okey = 2;
	vector<Deck> play_decks_to_check =
		{{{5,1},{5,2}},{{9,3},{10,0},{11,0}}};
	int score = 30;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysTypeDiffOneOneTripletLogic_7)
{
	Deck cards =
		{{5,1},{5,2}};
	int okey = 1;
	vector<Deck> play_decks_to_check =
		{{{5,0},{5,1},{5,2}}};
	int score = 15;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TestNextWasteOnMultiplePlaysTypeDiffOneOneTripletLogic_8)
{
	Deck cards =
		{{5,1},{5,2}};
	int okey = 2;
	vector<Deck> play_decks_to_check =
		{{{5,0},{5,0},{5,1},{5,2}}};
	int score = 20;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TimeCostTwoLongSequence)
{
	Deck cards =
		{{2,1},{3,1},{4,1},{5,1},{6,1},{7,1},{8,1},{9,1},{10,1},{11,1},{2,1},{3,1},{4,1},{5,1},{6,1},{7,1},{8,1},{9,1},{10,1},{11,1}};
	int okey = 2;
	vector<Deck> play_decks_to_check =
		{{{2,1},{3,1},{4,1},{5,1},{6,1},{7,1},{8,1},{9,1},{10,1},{11,1},{12,0},{13,0}},{{2,1},{3,1},{4,1},{5,1},{6,1},{7,1},{8,1},{9,1},{10,1},{11,1}}};
	int score = 155;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TimeCostTwoLongSequence_2)
{
	Deck cards =
		{{3,1},{4,1},{5,1},{6,1},{7,1},{8,1},{9,1},{10,1},{11,1},{12,1},{3,1},{4,1},{5,1},{6,1},{7,1},{8,1},{9,1},{10,1},{11,1},{12,1}};
	int okey = 2;
	vector<Deck> play_decks_to_check =
		{{{3,1},{4,1},{5,1},{6,1},{7,1},{8,1},{9,1},{10,1},{11,1},{12,1},{13,0}},{{3,1},{4,1},{5,1},{6,1},{7,1},{8,1},{9,1},{10,1},{11,1},{12,1},{13,0}}};
	int score = 176;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TimeCostTwoDiffLongSequence)
{
	Deck cards =
		{{2,1},{3,1},{4,1},{5,1},{6,1},{7,1},{8,1},{9,1},{10,1},{11,1},{3,1},{4,1},{5,1},{6,1},{7,1},{8,1},{9,1},{10,1},{11,1},{12,1}};
	int okey = 2;
	vector<Deck> play_decks_to_check =
		{{{2,1},{3,1},{4,1},{5,1},{6,1},{7,1},{8,1},{9,1},{10,1},{11,1},{12,1}},{{3,1},{4,1},{5,1},{6,1},{7,1},{8,1},{9,1},{10,1},{11,1},{12,0},{13,0}}};
	int score = 165;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TimeCostTwoDiffLongSequence_2)
{
	Deck cards =
		{{2,1},{3,1},{4,1},{5,1},{6,1},{7,1},{8,1},{9,1},{10,1},{11,1},{2,2},{3,2},{4,2},{5,2},{6,2},{7,2},{8,2},{9,2},{10,2},{11,2}};
	int okey = 2;
	vector<Deck> play_decks_to_check =
		{{{2,1},{3,1},{4,1},{5,1},{6,1},{7,1},{8,1},{9,1},{10,1},{11,1},{12,0},{13,0}},{{2,2},{3,2},{4,2},{5,2},{6,2},{7,2},{8,2},{9,2},{10,2},{11,2}}};
	int score = 155;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TimeCostThreeLongSequence)
{
	Deck cards =
		{{4,1},{5,1},{6,1},{7,1},{8,1},{9,1},{10,1},{4,1},{5,1},{6,1},{7,1},{8,1},{9,1},{10,1},{4,1},{5,1},{6,1},{7,1},{8,1},{9,1},{10,1}};
	int okey = 2;
	vector<Deck> play_decks_to_check =
		{{{4,1},{5,1},{6,1},{7,1},{8,1},{9,1},{10,1},{11,0},{12,0}},{{4,1},{5,1},{6,1},{7,1},{8,1},{9,1},{10,1}},{{4,1},{5,1},{6,1},{7,1},{8,1},{9,1},{10,1}}};
	int score = 170;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TimeCostThreeDiffLongSequence)
{
	Deck cards =
		{{4,1},{5,1},{6,1},{7,1},{8,1},{9,1},{10,1},{4,1},{5,1},{6,1},{7,1},{8,1},{9,1},{10,1},{4,2},{5,2},{6,2},{7,2},{8,2},{9,2},{10,2}};
	int okey = 2;
	vector<Deck> play_decks_to_check =
		{{{4,1},{5,1},{6,1},{7,1},{8,1},{9,1},{10,1},{11,0},{12,0}},{{4,1},{5,1},{6,1},{7,1},{8,1},{9,1},{10,1}},{{4,2},{5,2},{6,2},{7,2},{8,2},{9,2},{10,2}}};
	int score = 170;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TimeCostThreeDiffLongSequence_2)
{
	Deck cards =
		{{4,1},{5,1},{6,1},{7,1},{8,1},{9,1},{10,1},{4,2},{5,2},{6,2},{7,2},{8,2},{9,2},{10,2},{4,3},{5,3},{6,3},{7,3},{8,3},{9,3},{10,3}};
	int okey = 2;
	vector<Deck> play_decks_to_check =
		{{{4,1},{4,2},{4,3}},{{5,1},{5,2},{5,3}},{{6,1},{6,2},{6,3}},{{7,1},{7,2},{7,3}},{{8,1},{9,1},{10,1},{11,0},{12,0}},{{8,2},{9,2},{10,2}},{{8,3},{9,3},{10,3}}};
	int score = 170;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TimeCostThreeTotallyDiffLongSequence)
{
	Deck cards =
		{{3,1},{4,1},{5,1},{6,1},{7,1},{8,1},{9,1},{4,2},{5,2},{6,2},{7,2},{8,2},{9,2},{10,2},{5,3},{6,3},{7,3},{8,3},{9,3},{10,3},{11,3}};
	int okey = 2;
	vector<Deck> play_decks_to_check =
		{{{3,1},{4,1},{5,1},{6,1},{7,1},{8,1},{9,1}},{{4,2},{5,2},{6,2},{7,2},{8,2},{9,2},{10,2}},{{5,3},{6,3},{7,3},{8,3},{9,3},{10,3},{11,3},{12,0},{13,0}}};
	int score = 172;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TimeCostFourDiffLongSequence)
{
	Deck cards =
		{{5,1},{6,1},{7,1},{8,1},{9,1},{5,2},{6,2},{7,2},{8,2},{9,2},{5,3},{6,3},{7,3},{8,3},{9,3},{5,4},{6,4},{7,4},{8,4},{9,4}};
	int okey = 2;
	vector<Deck> play_decks_to_check =
		{{{5,1},{5,2},{5,3},{5,4}},{{6,1},{6,2},{6,3},{6,4}},{{7,1},{7,2},{7,3},{7,4}},{{8,1},{8,2},{8,3},{8,4}},{{9,1},{9,2},{9,3}},{{9,4},{10,0},{11,0}}};
	int score = 161;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TimeCostFourDiffLongSequence_2)
{
	Deck cards =
		{{4,1},{5,1},{6,1},{7,1},{8,1},{4,2},{5,2},{6,2},{7,2},{8,2},{5,3},{6,3},{7,3},{8,3},{9,3},{5,4},{6,4},{7,4},{8,4},{9,4}};
	int okey = 2;
	vector<Deck> play_decks_to_check =
		{{{4,1},{5,1},{6,1},{7,1},{8,1}},{{4,2},{5,2},{6,2},{7,2},{8,2}},{{5,3},{6,3},{7,3},{8,3},{9,3},{10,0},{11,0}},{{5,4},{6,4},{7,4},{8,4},{9,4}}};
	int score = 151;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

TEST(OKeyGame, TimeCostFourTotallyDiffLongSequence)
{
	Deck cards =
		{{3,1},{4,1},{5,1},{6,1},{7,1},{4,2},{5,2},{6,2},{7,2},{8,2},{5,3},{6,3},{7,3},{8,3},{9,3},{6,4},{7,4},{8,4},{9,4},{10,4}};
	int okey = 2;
	vector<Deck> play_decks_to_check =
		{{{3,1},{4,1},{5,1},{6,1},{7,1}},{{4,2},{5,2},{6,2},{7,2},{8,2}},{{5,3},{6,3},{7,3},{8,3},{9,3}},{{6,4},{7,4},{8,4},{9,4},{10,4},{11,0},{12,0}}};
	int score = 153;
	OKeySolver solver;
	Solution solution = solver.Solve(cards, okey);
	EXPECT_EQ(solver.Score(solution), score);
	EXPECT_EQ(Solution2Decks(solution, cards), play_decks_to_check);
}

int dump_test()
{
	Deck cards = {{5,1},{6,1},{7,1},{8,1},{9,1},{5,2},{6,2},{7,2},{8,2},{9,2},{5,3},{6,3},{7,3},{8,3},{9,3},{5,4},{6,4},{7,4},{8,4},{9,4}};
	sort(cards.begin(), cards.end());
	cout<<"hand:"<<endl;
	dump(cards); cout<<endl;
	cout<<"solutions:"<<endl;
	OKeySolver solver;
	clock_t  begin, end;
	begin=clock();
	Solution solution = solver.Solve(cards, 2);
	end=clock();
	cout<<"best solution:"<<endl;
	dump(Solution2Decks(solution, cards));
	cout<<"best score: "<<solver.Score(solution)<<endl;
	cout<<"Time cost: "<< (double)(end - begin) / CLOCKS_PER_SEC <<" secs."<< endl;
	return 0;
}

int main(int argc, char **argv)
{
	// return dump_test();
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
