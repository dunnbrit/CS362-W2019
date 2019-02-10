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

	//Track overall pass or fail
	int overall = 1;

	//Variable to track the hand countreturned from the function
	int count;

	//Intialize a game
	initializeGame(numPlayers,kingdomCards,randomSeed,&G);

	printf("\n>>>Testing Function: numHandCards(gameState)<<<\n");

	printf("\n......Running Tests......\n");

	//Test intial hand count is 5 for both players
	printf("Hand Card Count for Player One Correct: ");

	//Run function
	count = numHandCards(&G);

	if(count == 5){
		printf("PASSED \n");
	}
	else{
		printf("FAILED - Expected: 5 , Actual: %d \n", count);
		overall = 0;
	}

	//Change turn to player two and test hand count
	G.whoseTurn = 1;
	printf("Hand Card Count for Player Two Correct: ");

	//Run function
	count = numHandCards(&G);

	//Player two won't draw their hand cards until their first turn in the game
	//(Based on game intialization function)
	if(count == 0){
		printf("PASSED \n\n");
	}
	else{
		printf("FAILED - Expected: 5 , Actual: %d \n\n", count);
		overall = 0;
	}

	//Finished Result
	if(overall == 0){
		printf(">>>Testing of numHandCards FAILED <<<\n");
	}

	else{
		printf(">>>Testing of numHandCards PASSED <<<\n");
	}

	return 0;
}