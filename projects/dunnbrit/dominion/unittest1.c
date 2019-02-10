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
	int otherPlayer = 1;

	//Track overall pass or fail
	int overall = 1;

	//Intialize a game
	initializeGame(numPlayers,kingdomCards,randomSeed,&G);

	printf("\n>>>Testing Function: shuffle(player,gameState)<<<\n");

	printf("Updating Test and Other Players' deck to include cards 1-5... \n");
	//Updating the deck so shuffle can be shown better using different cards
	//Instead of intial hand of sever Coppers (4) and three estates (1)
	for (int i = 0; i < G.deckCount[0]; ++i)
	{
		G.deck[testPlayer][i] = i+1;
	}
	//Updating other players too to make sure there's is unchanged
	for (int i = 0; i < G.deckCount[0]; ++i)
	{
		G.deck[otherPlayer][i] = i+1;
	}

	printf("Test Player's Current Deck: ");
	for (int i = 0; i < G.deckCount[testPlayer]; ++i)
	{
		printf("%d  ", G.deck[testPlayer][i]);
	}
	
	//Run shuffle on test player
	shuffle(testPlayer,&G);

	//Show the shuffled deck
	printf("\nTest Player's Shuffled Deck: ");
	for (int i = 0; i < G.deckCount[testPlayer]; ++i)
	{
		printf("%d  ", G.deck[testPlayer][i]);
	}
	printf("\n");

	printf("\n......Running Tests......\n");
	
	//Test that other player's deck remains unchanged
	printf("Other Player Deck is Not Changed: " );
	//Check deck size
	if(G.deckCount[testPlayer] != 5){
		printf("FAILED \n");
		overall = 0;
	}
	else{
		//Check same cards
		for (int i = 0; i < 5; ++i){
			if(G.deck[otherPlayer][i] != i+1){
				printf("FAILED \n");
				overall = 0;
			}
			else if (i == 4){
				printf("PASSED \n");
			}
		}
	}
	
	//Test for the correct number of cards in the deck of test player
	printf("Number of Cards in Test Player's Deck Correct: ");
	if(G.deckCount[testPlayer] == 5){
		printf("PASSED \n");
	}
	else{
		printf("FAILED \n");
		overall = 0;
	}

	//Test for all the same cards in the deck of the test player
	printf("Test Player's Deck has Same Cards as Before Shuffle: " );

	//Varible to track if card was found
	int found = 0;
	
	for (int i = 0; i < G.deckCount[testPlayer]; ++i){
				
		int j = 0;
		while(found == 0 && j < 5){
			//Search for each card 1-5
			if(G.deck[testPlayer][j] == i+1){
				//if found, set found to true
				found = 1;
			}
		}

		//If card was not found then test failed
		if (found == 0)
		{
			printf("FAILED \n");
			overall = 0;
		}
	}

	//If all cards where found then test passed
	if (found == 1)
	{
		printf("PASSED \n");
	}

	//Test the deck was shuffled (not in same order)
	printf("Test Player's Deck Has Been Shuffled (in new order): " );

	//Variable for if test passed
	int status = 0;
	//Check that at least one card has moved
	for (int i = 0; i < G.deckCount[testPlayer]; ++i){
		if(G.deck[testPlayer][i] != i+1){
			printf("PASSED \n\n");
			//Set status to passed so failed message does not print
			status = 1;
			//Exit loop
			i = G.deckCount[testPlayer];
		}
	}

	//If test failed
	if(status == 0){
		printf("FAILED \n\n");
		overall = 0;
	}

	//Finished Result
	if(overall == 0){
		printf(">>>Testing of shuffle FAILED <<<\n");
	}

	else{
		printf(">>>Testing of shuffle PASSED <<<\n");
	}
	

	return 0;
}