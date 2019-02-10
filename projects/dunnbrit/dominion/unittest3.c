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
	int playerOne = 0;
	int playerTwo = 1;

	//Track overall pass or fail
	int overall = 1;

	//Variable to track the turn returned from the function
	int turn;

	//Intialize a game
	initializeGame(numPlayers,kingdomCards,randomSeed,&G);

	printf("\n>>>Testing Function: whooseTurn(gameState)<<<\n");

	printf("\n......Running Tests......\n");

	//Test first turn is player one
	printf("First Turn is Player One: ");

	//Run function
	turn = whoseTurn(&G);

	if(turn == playerOne){
		printf("PASSED \n");
	}
	else{
		printf("FAILED - Expected: 0 , Actual: %d \n", turn);
		overall = 0;
	}

	//Change turn to player two and test
	printf("Player Two Turn Correct: ");
	G.whoseTurn = playerTwo;

	//Run function
	turn = whoseTurn(&G);

	if(turn == playerTwo){
		printf("PASSED \n");
	}
	else{
		printf("FAILED - Expected: 1 , Actual: %d \n", turn);
		overall = 0;
	}

	//Change turn back to player one and test
	printf("Player One Turn Correct: ");
	G.whoseTurn = playerOne;

	//Run function
	turn = whoseTurn(&G);

	if(turn == playerOne){
		printf("PASSED \n\n");
	}
	else{
		printf("FAILED - Expected: 0 , Actual: %d \n\n", turn);
		overall = 0;
	}

	//Finished Result
	if(overall == 0){
		printf(">>>Testing of whoseTurn FAILED <<<\n");
	}

	else{
		printf(">>>Testing of whoseTurn PASSED <<<\n");
	}

	return 0;
}