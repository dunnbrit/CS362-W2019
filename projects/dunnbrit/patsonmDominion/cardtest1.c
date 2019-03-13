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
	struct gameState copyG;
	int testPlayer = 0;
	int otherPlayer = 1;
	int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
	int newCards = 3;
	int discarded = 1;

	//Track overall pass or fail
	int overall = 1;

	//Intialize a game
	initializeGame(numPlayers,kingdomCards,randomSeed,&G);

	//Copy current game state to use later to make sure parts of game state changes correctly
	memcpy(&copyG, &G, sizeof(struct gameState));

	printf("\n>>>Testing Card: Smithy <<<\n");

	printf("\n......Running Tests......\n");

	//Run function cardEffect using smithy
	cardEffect(smithy,choice1,choice2,choice3,&G,handpos,&bonus);

	printf("Draw 3 Cards Added to Hand (Test Player's Hand Increased Correctly) : ");
	//Hand should have 3 more cards than before smithy was used
	if(G.handCount[testPlayer] == (copyG.handCount[testPlayer] + newCards)){
		printf("PASSED \n");
	}
	else{
		printf("FAILED - Expected Hand Count: %d , Actual: %d \n",(copyG.handCount[testPlayer] + newCards), G.handCount[testPlayer] );
		overall = 0;
	}


	printf("3 Cards Drawn from Player's Deck (Test Player's Deck Decreased Correctly): ");
	//Deck should have 3 less cards
	if(G.deckCount[testPlayer] == (copyG.deckCount[testPlayer] - newCards)){
		printf("PASSED \n");
	}
	else{
		printf("FAILED - Expected Deck Count: %d , Actual: %d \n",(copyG.deckCount[testPlayer] - newCards), G.deckCount[testPlayer] );
		overall = 0;
	}


	printf("3 Cards Drawn from Player's Deck (Test Player's Hand Includes Copper or Estate Only): ");
	//Varible for the correct cards
	int playerCards = 1;

	//Loop through player hand and check for cards other than copper and estates
	for(int i = 0; i < G.handCount[testPlayer]; i++){
		if(G.hand[testPlayer][i] != 1 && G.hand[testPlayer][i] != 4){
			//Card is not from player's deck set to false
			playerCards = 0;
		}
	}

	//If card is not from player's deck then failed test
	if(playerCards == 0){
		printf("FAILED \n");
		overall = 0;
	}
	else{
		printf("PASSED \n");
	}


	printf("Test Player Discarded Smithy (Discard Count is Increased Correctly): ");
	//Discard count should be 1
	if(G.discardCount[testPlayer] == discarded){
		printf("PASSED \n");
	}
	else{
		printf("FAILED - Expected Discard Count: %d , Actual: %d \n", discarded, G.discardCount[testPlayer]) ;
		overall = 0;
	}


	printf("Test Player Discarded Smithy (Discard Pile Contains Smithy): ");
	//Varible for the containing smithy
	int contains = 0;

	//Loop through player discard pile and check for smithy
	for(int i = 0; i < G.discardCount[testPlayer]; i++){
		if(G.discard[testPlayer][i] == 13){
			//Card is in discard, set true
			contains = 1;
		}
	}
	
	if(contains == 0){
		printf("FAILED \n");
		overall = 0;
	}
	else{
		printf("PASSED \n");
	}


	//Check the game state is unaffected by smithy by compare previous game state to current game state
	
	printf("Game State Remains Unchanged (Other Player's Hand Count is Unchanged): ");
	//check other player's hand count is the same as before smithy was used
	if(copyG.handCount[otherPlayer] == G.handCount[otherPlayer]){
		printf("PASSED \n");
	}
	else{
		printf("FAILED - Expected Hand Count: %d , Actual: %d \n", copyG.handCount[otherPlayer], G.handCount[otherPlayer]) ;
		overall = 0;
	}


	printf("Game State Remains Unchanged (Other Player's Deck Count is Unchanged): ");
	//check other player's deck count is the same as before smithy was used
	if(copyG.deckCount[otherPlayer] == G.deckCount[otherPlayer]){
		printf("PASSED \n");
	}
	else{
		printf("FAILED - Expected Deck Count: %d , Actual: %d \n", copyG.deckCount[otherPlayer], G.deckCount[otherPlayer]) ;
		overall = 0;
	}


	printf("Game State Remains Unchanged (Other Player's Discard Count is Unchanged): ");
	//check other player's discard count is the same as before smithy was used
	if(copyG.discardCount[otherPlayer] == G.discardCount[otherPlayer]){
		printf("PASSED \n");
	}
	else{
		printf("FAILED - Expected Discard Count: %d , Actual: %d \n", copyG.discardCount[otherPlayer], G.discardCount[otherPlayer]) ;
		overall = 0;
	}


	printf("Game State Remains Unchanged (Supply Count for Victory Cards is Unchanged): ");
	//varible to track supply is unchanged
	int supplyUnchanged = 1;

	//Check count of all victory cards
	if(supplyCount(estate, &copyG) != supplyCount(estate, &G)){
		supplyUnchanged = 0;
		printf("FAILED For Estate Count: Expected: %d Actual:%d \n",supplyCount(estate,&copyG), supplyCount(estate, &G) );
	}
	if(supplyCount(duchy, &copyG) != supplyCount(duchy, &G)){
		supplyUnchanged = 0;
		printf("FAILED For Duchy Count: Expected: %d Actual:%d \n",supplyCount(duchy,&copyG), supplyCount(duchy, &G) );
	}	
	if(supplyCount(province, &copyG) != supplyCount(province, &G)){
		supplyUnchanged = 0;
		printf("FAILED For Province Count: Expected: %d Actual:%d \n",supplyCount(province,&copyG), supplyCount(province, &G) );
	}
	

	if(supplyUnchanged == 1){
		printf("PASSED\n");
	}


	printf("Game State Remains Unchanged (Supply Count for Coin Cards is Unchanged): ");
	//varible to track supply is unchanged
	supplyUnchanged = 1;

	//Check count of all coins
	if(supplyCount(copper, &copyG) != supplyCount(copper, &G)){
		supplyUnchanged = 0;
		printf("FAILED For copper Count: Expected: %d Actual:%d \n",supplyCount(copper,&copyG), supplyCount(copper, &G) );
	}
	if(supplyCount(silver, &copyG) != supplyCount(silver, &G)){
		supplyUnchanged = 0;
		printf("FAILED For silver Count: Expected: %d Actual:%d \n",supplyCount(silver,&copyG), supplyCount(silver, &G) );
	}
	if(supplyCount(gold, &copyG) != supplyCount(gold, &G)){
		supplyUnchanged = 0;
		printf("FAILED For gold Count: Expected: %d Actual:%d \n",supplyCount(gold,&copyG), supplyCount(gold, &G) );
	}

	if(supplyUnchanged == 1){
		printf("PASSED\n");
	}

	printf("Game State Remains Unchanged (Supply Count for All Kingdom Cards is Unchanged): ");
	//varible to track supply is unchanged
	supplyUnchanged = 1;

	//Check each kingdom card
	for(int i = 0; i < 10; i++){
		if(supplyCount(kingdomCards[i], &copyG) != supplyCount(kingdomCards[i], &G)){
			supplyUnchanged = 0;
			printf("FAILED For kingdom Card %d Count: Expected: %d Actual:%d \n",i ,supplyCount(kingdomCards[i],&copyG), supplyCount(kingdomCards[i], &G) );
		}
	}

	if(supplyUnchanged == 1){
		printf("PASSED\n\n");
	}	

	//Finished Result
	if(overall == 0){
		printf(">>>Testing of Smithy FAILED <<<\n");
	}

	else{
		printf(">>>Testing of Smithy PASSED <<<\n");
	}

	return 0;
}