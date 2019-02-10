#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>

int main()
{
	//Set variables to intialize game
	//Referenced provided code samples
	int numPlayers = 2 ;
	int kingdomCards[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
	int randomSeed = 1000 ;
	struct gameState G;
	int testPlayer = 0;

	//Track overall pass or fail
	int overall = 1;

	//varible to hold deck count as tested
	int count;

	//Intialize a game
	initializeGame(numPlayers,kingdomCards,randomSeed,&G);

	printf("\n>>>Testing Function: fullDeckCount(player, card, gameState)<<<\n");

	printf("\n......Running Tests......\n");

	//Test the intial deck count is correct at 10
	printf("Intial Deck Count Correct: ");

	//Run function
	count = fullDeckCount(testPlayer, 0, &G);

	//New game should start with 10 cards total
	if(count == 10){
		printf("PASSED \n");
	}
	else{
		printf("FAILED - Expected: 10 , Actual: %d \n", count);
		overall = 0;
	}

	//Test for decrease count of hand, discard, and deck each by 1

	//Decrease hand by 1
	G.handCount[testPlayer] -= 1;

	//Run function
	count = fullDeckCount(testPlayer, 0, &G);

	printf("Decrease in Hand Count Reflected Correctly in Full Deck Count: ");

	if(count == 9){
		printf("PASSED \n");
	}
	else{
		printf("FAILED - Expected: 9 , Actual: %d \n", count);
		overall = 0;
	}

	//Decrease discard by 1
	G.discardCount[testPlayer] -= 1;

	//Run function
	count = fullDeckCount(testPlayer, 0, &G);

	printf("Decrease in Discard Count Reflected Correctly in Full Deck Count: ");

	if(count == 8){
		printf("PASSED \n");
	}
	else{
		printf("FAILED - Expected: 8 , Actual: %d \n", count);
		overall = 0;
	}

	//Decrease deck by 1
	G.deckCount[testPlayer] -= 1;

	//Run function
	count = fullDeckCount(testPlayer, 0, &G);

	printf("Decrease in Deck Count Reflected Correctly in Full Deck Count: ");

	if(count == 7){
		printf("PASSED \n\n");
	}
	else{
		printf("FAILED - Expected: 7 , Actual: %d \n\n", count);
		overall = 0;
	}

	//Finished Result
	if(overall == 0){
		printf(">>>Testing of fullDeckCount FAILED <<<\n");
	}

	else{
		printf(">>>Testing of fullDeckCount PASSED <<<\n");
	}

	return 0;
}
